#include "inbox.h"
#include "keys.h"
#include "menu.h"

/********************/
/*     MESSAGES     */
/********************/

void inbox_received_handler(DictionaryIterator *iter, void *context) {
  Tuple *t;

  // Steep times and general settings
  t = dict_find(iter, MESSAGE_KEY_PERSIST_READY);
  if (t) persist_write_int(PERSIST_READY, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_READY_CUSTOM);
  if (t) persist_write_int(PERSIST_READY_CUSTOM, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEMP_UNIT);
  if (t) persist_write_int(PERSIST_TEMP_UNIT, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_BLACK);
  if (t) persist_write_int(PERSIST_TEA_BLACK, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_GREEN);
  if (t) persist_write_int(PERSIST_TEA_GREEN, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_HERBAL);
  if (t) persist_write_int(PERSIST_TEA_HERBAL, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_MATE);
  if (t) persist_write_int(PERSIST_TEA_MATE, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_OOLONG);
  if (t) persist_write_int(PERSIST_TEA_OOLONG, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_PUERH);
  if (t) persist_write_int(PERSIST_TEA_PUERH, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_ROOIBOS);
  if (t) persist_write_int(PERSIST_TEA_ROOIBOS, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_WHITE);
  if (t) persist_write_int(PERSIST_TEA_WHITE, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_TEA_MATCHA);
  if (t) persist_write_int(PERSIST_TEA_MATCHA, t->value->int32);

  // Hide flags (1 = show, 0 = hidden)
  t = dict_find(iter, MESSAGE_KEY_black_hide);
  if (t) persist_write_int(PERSIST_HIDE_BLACK, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_green_hide);
  if (t) persist_write_int(PERSIST_HIDE_GREEN, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_herbal_hide);
  if (t) persist_write_int(PERSIST_HIDE_HERBAL, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_mate_hide);
  if (t) persist_write_int(PERSIST_HIDE_MATE, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_oolong_hide);
  if (t) persist_write_int(PERSIST_HIDE_OOLONG, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_puerh_hide);
  if (t) persist_write_int(PERSIST_HIDE_PUERH, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_rooibos_hide);
  if (t) persist_write_int(PERSIST_HIDE_ROOIBOS, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_white_hide);
  if (t) persist_write_int(PERSIST_HIDE_WHITE, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_matcha_hide);
  if (t) persist_write_int(PERSIST_HIDE_MATCHA, t->value->int32);

  // Custom tea — name sent as cstring under MESSAGE_KEY_custom_name (key 38)
  t = dict_find(iter, MESSAGE_KEY_custom_name);
  if (t) persist_write_string(PERSIST_CUSTOM_NAME, t->value->cstring);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_CUSTOM_TIME);
  if (t) persist_write_int(PERSIST_CUSTOM_TIME, t->value->int32);

  t = dict_find(iter, MESSAGE_KEY_PERSIST_CUSTOM_TEMP);
  if (t) persist_write_int(PERSIST_CUSTOM_TEMP, t->value->int32);

  // Refresh menu with new settings
  menu_mark_dirty();
}