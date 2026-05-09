// #define PERSIST_WAKEUP      0
// #define PERSIST_DURATION    1
// #define PERSIST_COUNT_MODE  2
// #define PERSIST_TEA         3

// #define PERSIST_READY       8
// #define PERSIST_TEMP_UNIT   9
// #define PERSIST_TEA_BLACK   10
// #define PERSIST_TEA_GREEN   11
// #define PERSIST_TEA_HERBAL  12
// #define PERSIST_TEA_MATE    13
// #define PERSIST_TEA_OOLONG  14
// #define PERSIST_TEA_PUERH   15
// #define PERSIST_TEA_ROOIBOS 16
// #define PERSIST_TEA_WHITE   17
// #define PERSIST_TEA_MATCHA  18

#pragma once

// Internal persist keys (never sent over AppMessage)
#define PERSIST_WAKEUP      0
#define PERSIST_DURATION    1
#define PERSIST_COUNT_MODE  2
#define PERSIST_TEA         3

// AppMessage keys — must match messageKeys in package.json
// SDK also generates MESSAGE_KEY_* constants from package.json;
// those are used in inbox.c for dict_find() to guarantee they stay in sync.
#define PERSIST_READY       8
#define PERSIST_TEMP_UNIT   9
#define PERSIST_TEA_BLACK   10
#define PERSIST_TEA_GREEN   11
#define PERSIST_TEA_HERBAL  12
#define PERSIST_TEA_MATE    13
#define PERSIST_TEA_OOLONG  14
#define PERSIST_TEA_PUERH   15
#define PERSIST_TEA_ROOIBOS 16
#define PERSIST_TEA_WHITE   17
#define PERSIST_TEA_MATCHA  18

// Hide flags — must match messageKeys in package.json
// 1 = show in menu, 0 = hidden
#define PERSIST_HIDE_BLACK   28
#define PERSIST_HIDE_GREEN   29
#define PERSIST_HIDE_HERBAL  30
#define PERSIST_HIDE_MATE    31
#define PERSIST_HIDE_OOLONG  32
#define PERSIST_HIDE_PUERH   33
#define PERSIST_HIDE_ROOIBOS 34
#define PERSIST_HIDE_WHITE   35
#define PERSIST_HIDE_MATCHA  36

// Custom cooldown duration in minutes (only used when PERSIST_READY == 5)
#define PERSIST_READY_CUSTOM  37

// Custom tea - name sent as cstring under raw key 38, time and temp as integers
#define PERSIST_CUSTOM_NAME  38
#define PERSIST_CUSTOM_TIME  39
#define PERSIST_CUSTOM_TEMP  40

