// Patched by Will0 (https://willow.systems) - 18/04/2020
// Pebble is dead. Long live Rebble!

Pebble.addEventListener('showConfiguration', function(e) {

  var url = 'https://willow.systems/pebble/configs/teatime/#'
  

  // Show config page
  var config = {}
  //config.ready = localStorage.getItem("ready");
  if (config.ready != null) {
	  config.temp_unit = localStorage.getItem("temp_unit");
	  config.black = localStorage.getItem("black");
	  config.black_hide = localStorage.getItem("black_hide");
	  config.green = localStorage.getItem("green");
	  config.green_hide = localStorage.getItem("green_hide");
	  config.herbal = localStorage.getItem("herbal");
	  config.herbal_hide = localStorage.getItem("herbal_hide");
	  config.mate = localStorage.getItem("mate");
	  config.mate_hide = localStorage.getItem("mate_hide");
	  config.oolong = localStorage.getItem("oolong");
	  config.oolong_hide = localStorage.getItem("oolong_hide");
	  config.puerh = localStorage.getItem("puerh");
	  config.puerh_hide = localStorage.getItem("puerh_hide");
	  config.rooibos = localStorage.getItem("rooibos");
  	  config.rooibos_hide = localStorage.getItem("rooibos_hide");
	  config.white = localStorage.getItem("white");
	  config.white_hide = localStorage.getItem("white_hide");
	  config.matcha = localStorage.getItem("matcha");
	  config.matcha_hide = localStorage.getItem("matcha_hide");
	  console.log("Previous config: " + JSON.stringify(config));
	  url += btoa(JSON.stringify(config));
   } else {
	  console.log("No previous config stored");
   }

   console.log("Open settings url: " + url);
   Pebble.openURL(url);
});

Pebble.addEventListener('webviewclosed', function(e) {
  // Decode and parse config data as JSON
  var config_data = JSON.parse(decodeURIComponent(e.response));
	

  for(var key in config_data) {
  	localStorage.setItem(key, config_data[key]);
  }
  
  // Prepare AppMessage payload
  var dict = {
    'PERSIST_READY': config_data.ready,
    'PERSIST_TEMP_UNIT': config_data.temp_unit,
    'PERSIST_TEA_BLACK': config_data.black * 60 * config_data.black_hide,
    'PERSIST_TEA_GREEN': config_data.green * 60 * config_data.green_hide,
    'PERSIST_TEA_HERBAL': config_data.herbal * 60 * config_data.herbal_hide,
    'PERSIST_TEA_MATE': config_data.mate * 60 * config_data.mate_hide,
    'PERSIST_TEA_OOLONG': config_data.oolong * 60 * config_data.oolong_hide,
    'PERSIST_TEA_PUERH': config_data.puerh * 60 * config_data.puerh_hide,
    'PERSIST_TEA_ROOIBOS': config_data.rooibos * 60 * config_data.rooibos_hide,
    'PERSIST_TEA_WHITE': config_data.white * 60 * config_data.white_hide,
    'PERSIST_TEA_MATCHA': config_data.matcha * 60 * config_data.matcha_hide
  };
  
  // Send settings to Pebble watchapp
  console.log('Sending configuration: ' + JSON.stringify(dict));
  Pebble.sendAppMessage(dict,
    function(){
      console.log('Configuration sent to Pebble');  
    },
    function() {
      console.log('Failed to send configuration to Pebble');
    });
});
