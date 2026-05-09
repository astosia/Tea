// Tea's Ready - Pebble JS
// Config powered by Clay (local, no external dependency)

var Clay = require('@rebble/clay');
var clayConfig = require('./config.json');
var clay = new Clay(clayConfig);

Pebble.addEventListener('webviewclosed', function(e) {
  if (!e.response || e.response === 'CANCELLED') {
    return;
  }

  var config_data = clay.getSettings(e.response);
  //console.log('Raw config_data: ' + JSON.stringify(config_data));

  // Clay returns settings keyed by numeric message key (as defined in package.json messageKeys),
  // not by name. Key numbers must match messageKeys in package.json exactly.
  // Radiogroup and select values are returned as strings so parseInt() is needed.
  // Sliders with step 0.5 are returned scaled by 10 (e.g. 4 mins -> 40), so divide by 10 first.

  var dict = {
    'PERSIST_READY':        parseInt(config_data['8'], 10),
    'PERSIST_TEMP_UNIT':    parseInt(config_data['9'], 10),

    'PERSIST_TEA_BLACK':    (config_data['10'] / 10) * 60,
    'PERSIST_TEA_GREEN':    (config_data['11'] / 10) * 60,
    'PERSIST_TEA_HERBAL':   (config_data['12'] / 10) * 60,
    'PERSIST_TEA_MATE':     (config_data['13'] / 10) * 60,
    'PERSIST_TEA_OOLONG':   (config_data['14'] / 10) * 60,
    'PERSIST_TEA_PUERH':    (config_data['15'] / 10) * 60,
    'PERSIST_TEA_ROOIBOS':  (config_data['16'] / 10) * 60,
    'PERSIST_TEA_WHITE':    (config_data['17'] / 10) * 60,
    'PERSIST_TEA_MATCHA':   (config_data['18'] / 10) * 60,

    'black_hide':           config_data['28'] ? 1 : 0,
    'green_hide':           config_data['29'] ? 1 : 0,
    'herbal_hide':          config_data['30'] ? 1 : 0,
    'mate_hide':            config_data['31'] ? 1 : 0,
    'oolong_hide':          config_data['32'] ? 1 : 0,
    'puerh_hide':           config_data['33'] ? 1 : 0,
    'rooibos_hide':         config_data['34'] ? 1 : 0,
    'white_hide':           config_data['35'] ? 1 : 0,
    'matcha_hide':          config_data['36'] ? 1 : 0,

    // Custom cooldown sent as seconds (step 1, no scaling needed)
    'PERSIST_READY_CUSTOM': config_data['37'] * 60,

    // Custom tea — steep time scaled by 10 (step 0.5), temp is integer (step 1)
    'PERSIST_CUSTOM_TIME':  (config_data['39'] / 10) * 60,
    'PERSIST_CUSTOM_TEMP':  config_data['40']
  };

  // Custom tea name sent as cstring under key 38
  var customName = config_data['38'] || '';
  if (customName.length > 15) {
    customName = customName.substring(0, 15);
  }
  dict['custom_name'] = customName;

  console.log('Sending configuration: ' + JSON.stringify(dict));

  Pebble.sendAppMessage(dict,
    function() { console.log('Configuration sent to Pebble'); },
    function() { console.log('Failed to send configuration to Pebble'); }
  );
});