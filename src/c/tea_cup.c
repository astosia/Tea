// #include "tea_cup.h"

// /********************/
// /*    VARIABLES     */
// /********************/

// // Display variable
// static GPath *s_tea_cup;
// static GPath *s_tea_cup_fill;
// static GPath *s_plate;
// static GPath *s_handle;
// static GPath *s_vapor_left;
// static GPath *s_vapor_right;

// // Path
// static GPathInfo s_path_tea_cup = {
//   .num_points = 6,
//   .points = (GPoint []) {
//     {0, 0}, // Cup - top left
//     {0, 25}, // Cup - centre left
//     {15, 40}, // Cup - bottom left
//     {35, 40}, // Cup - bottom right
//     {50, 25}, // Cup - centre right
//     {50, 0} // Cup - top right
//   }
// };
// static GPathInfo s_path_tea_cup_fill = {
//   .num_points = 6,
//   .points = (GPoint []) {
//     {0, 0}, // Cup - top left
//     {0, 25}, // Cup - centre left
//     {15, 40}, // Cup - bottom left
//     {35, 40}, // Cup - bottom right
//     {50, 25}, // Cup - centre right
//     {50, 0} // Cup - top right
//   }
// };
// static GPathInfo s_path_plate = {
//   .num_points = 4,
//   .points = (GPoint []) {
//     {0, 0}, // Plate - top left
//     {6, 6}, // Plate - bottom left
//     {44, 6}, // Plate - bottom right
//     {50, 0} // Plate - top right
//   }
// };
// static GPathInfo s_path_handle = {
//   .num_points = 6,
//   .points = (GPoint []) {
//     {12, 0}, // Handle - top right
//     {4, 0}, // Handle - top top left
//     {0, 4}, // Handle - center top left
//     {0, 14}, // Handle - center bottom left
//     {4, 18}, // Plate - bottom bottom left
//     {12, 18} // Plate - bottom right
//   }
// };
// static GPathInfo s_path_vapor = {
//   .num_points = 4,
//   .points = (GPoint []) {
//     {10, 0}, // Handle - top right
//     {3, 7}, // Handle - center left
//     {7, 7}, // Handle - center right
//     {0, 14}, // Handle - bottom left
//   }
// };

// // Other variables
// static uint8_t s_tea_cup_loaded;

// /********************/
// /*     DISPLAY      */
// /********************/

// // Draw tea cup on context
// void tea_cup_draw(Layer *layer, GContext *ctx, uint8_t fill_percentage, bool vapor) {
//   GRect bounds = layer_get_bounds(layer);
//   if(fill_percentage < 100)
//     fill_percentage = fill_percentage / 100.0 * 38 + 1;
//   else
//     fill_percentage = 40;
  
//   // Initialize the tea cup
//   if(!s_tea_cup_loaded) {
//     s_tea_cup_loaded = 1;
    
//     // Create path
//     s_tea_cup = gpath_create(&s_path_tea_cup);
//     s_tea_cup_fill = gpath_create(&s_path_tea_cup_fill);
//     s_plate = gpath_create(&s_path_plate);
//     s_handle = gpath_create(&s_path_handle);
  
//     // Translate to centre
//     gpath_move_to(s_tea_cup, GPoint(bounds.size.w / 2 - 25, bounds.size.h / 2 - 23));
//     gpath_move_to(s_tea_cup_fill, GPoint(bounds.size.w / 2 - 25, bounds.size.h / 2 - 23));
//     gpath_move_to(s_plate, GPoint(bounds.size.w / 2 - 25, bounds.size.h / 2 + 17));
//     gpath_move_to(s_handle, GPoint(bounds.size.w / 2 - 37, bounds.size.h / 2 - 20));
    
//     // Add vapor
//     if(vapor) {
//       s_vapor_left = gpath_create(&s_path_vapor);
//       s_vapor_right = gpath_create(&s_path_vapor);
//       gpath_move_to(s_vapor_left, GPoint(bounds.size.w / 2 - 10, bounds.size.h / 2 - 45));
//       gpath_move_to(s_vapor_right, GPoint(bounds.size.w / 2 + 6, bounds.size.h / 2 - 45));
//       s_tea_cup_loaded = 2;
//     }
//   }
  
//   // Setup fill path
//   if(fill_percentage <= 15) {
//     // Remove top points
//     s_path_tea_cup_fill.points[0] = GPoint(15 - fill_percentage, 40 - fill_percentage);
//     s_path_tea_cup_fill.points[5] = GPoint(35 + fill_percentage, 40 - fill_percentage);
    
//     // Set centre points correctly
//     s_path_tea_cup_fill.points[1] = GPoint(15 - fill_percentage, 40 - fill_percentage);
//     s_path_tea_cup_fill.points[4] = GPoint(35 + fill_percentage, 40 - fill_percentage);
//   }
//   else {
//     // Set top points correctly
//     s_path_tea_cup_fill.points[0] = GPoint(0, 40 - fill_percentage);
//     s_path_tea_cup_fill.points[5] = GPoint(50, 40 - fill_percentage);
    
//     // Set centre points to default
//     s_path_tea_cup_fill.points[1] = GPoint(0, 25);
//     s_path_tea_cup_fill.points[4] = GPoint(50, 25);
//   }
  
//   // Fill
//   graphics_context_set_fill_color(ctx, GColorBlack);
//   gpath_draw_filled(ctx, s_tea_cup);
//   graphics_context_set_fill_color(ctx, GColorWhite);
//   gpath_draw_filled(ctx, s_plate);
//   gpath_draw_filled(ctx, s_tea_cup_fill);
  
//   // Outline
//   graphics_context_set_stroke_color(ctx, GColorBlack);
//   graphics_context_set_stroke_width(ctx, 2);
//   gpath_draw_outline(ctx, s_plate);
//   gpath_draw_outline(ctx, s_tea_cup);
//   gpath_draw_outline(ctx, s_handle);
//   if(vapor) {
//     gpath_draw_outline(ctx, s_vapor_left);
//     gpath_draw_outline(ctx, s_vapor_right);
//   }
// }

// // Destroy the tea cup
// void tea_cup_destroy() {
//   if(s_tea_cup_loaded > 0) {
//     gpath_destroy(s_tea_cup);
//     gpath_destroy(s_tea_cup_fill);
//     gpath_destroy(s_plate);
//     gpath_destroy(s_handle);
//     if(s_tea_cup_loaded > 1) {
//       gpath_destroy(s_vapor_left);
//       gpath_destroy(s_vapor_right);
//     }
    
//     s_tea_cup_loaded = false;
//   }
// }


#include "tea_cup.h"

/********************/
/* MACROS           */
/********************/

// Manual scaling logic for Emery (1.4x)
#if defined(PBL_PLATFORM_EMERY)
  #define SC(coord) ((coord) * 14 / 10) 
  #define STROKE_WIDTH 3
  // Shift the cup up an extra 3 pixels on Emery to avoid saucer overlap
  #define CUP_Y_ADJUST 2
#elif defined(PBL_PLATFORM_GABBRO)
  #define SC(coord) ((coord) * 14 / 10) 
  #define STROKE_WIDTH 3
  // Shift the cup up an extra 3 pixels on Gabbro too to avoid saucer overlap
  #define CUP_Y_ADJUST 2
#else
  #define SC(coord) (coord)
  #define STROKE_WIDTH 2
  #define CUP_Y_ADJUST 0
#endif

/********************/
/* PATH INFO        */
/********************/

static GPathInfo s_path_tea_cup = {
  .num_points = 6,
  .points = (GPoint []) {
    {SC(0), SC(0)}, {SC(0), SC(25)}, {SC(15), SC(40)}, 
    {SC(35), SC(40)}, {SC(50), SC(25)}, {SC(50), SC(0)}
  }
};

static GPathInfo s_path_tea_cup_fill = {
  .num_points = 6,
  .points = (GPoint []) {
    {SC(0), SC(0)}, {SC(0), SC(25)}, {SC(15), SC(40)}, 
    {SC(35), SC(40)}, {SC(50), SC(25)}, {SC(50), SC(0)}
  }
};

static GPathInfo s_path_plate = {
  .num_points = 4,
  .points = (GPoint []) {
    {SC(0), SC(0)}, {SC(6), SC(6)}, {SC(44), SC(6)}, {SC(50), SC(0)}
  }
};

static GPathInfo s_path_handle = {
  .num_points = 6,
  .points = (GPoint []) {
    {SC(12), SC(0)}, {SC(4), SC(0)}, {SC(0), SC(4)}, 
    {SC(0), SC(14)}, {SC(4), SC(18)}, {SC(12), SC(18)}
  }
};

static GPathInfo s_path_vapor = {
  .num_points = 4,
  .points = (GPoint []) {
    {SC(10), SC(0)}, {SC(3), SC(7)}, {SC(7), SC(7)}, {SC(0), SC(14)}
  }
};

static GPath *s_tea_cup;
static GPath *s_tea_cup_fill;
static GPath *s_plate;
static GPath *s_handle;
static GPath *s_vapor_left;
static GPath *s_vapor_right;

static uint8_t s_tea_cup_loaded;

/********************/
/* DISPLAY          */
/********************/

void tea_cup_draw(Layer *layer, GContext *ctx, uint8_t fill_percentage, bool vapor) {
  GRect bounds = layer_get_bounds(layer);
  
  // Constants for fill logic (scaled)
  const int cup_h = SC(40);
  const int cup_mid_y = SC(25);
  const int cup_w = SC(50);
  const int cup_side_offset = SC(15);

  // Calculate fill height
  uint8_t current_fill_h;
  if(fill_percentage < 100)
    current_fill_h = (uint8_t)(fill_percentage / 100.0 * (cup_h - 2) + 1);
  else
    current_fill_h = cup_h;
  
  if(!s_tea_cup_loaded) {
    s_tea_cup_loaded = 1;
    
    s_tea_cup = gpath_create(&s_path_tea_cup);
    s_tea_cup_fill = gpath_create(&s_path_tea_cup_fill);
    //s_plate = gpath_create(&s_plate_info); // Fixed from previous snippet
    s_plate = gpath_create(&s_path_plate);
    s_handle = gpath_create(&s_path_handle);
    
    // Position using scaled offsets and the vertical adjustment
    int cup_origin_y = bounds.size.h / 2 - (SC(23) + CUP_Y_ADJUST);
    
    gpath_move_to(s_tea_cup, GPoint(bounds.size.w / 2 - SC(25), cup_origin_y));
    gpath_move_to(s_tea_cup_fill, GPoint(bounds.size.w / 2 - SC(25), cup_origin_y));
    
    // Saucer (Plate) stays at standard center + offset
    gpath_move_to(s_plate, GPoint(bounds.size.w / 2 - SC(25), bounds.size.h / 2 + SC(17)));
    
    // Handle moved up to match the cup
    gpath_move_to(s_handle, GPoint(bounds.size.w / 2 - SC(37), bounds.size.h / 2 - (SC(20) + CUP_Y_ADJUST)));
    
    if(vapor) {
      s_vapor_left = gpath_create(&s_path_vapor);
      s_vapor_right = gpath_create(&s_path_vapor);
      // Vapor also shifts up to stay above the cup
      gpath_move_to(s_vapor_left, GPoint(bounds.size.w / 2 - SC(10), bounds.size.h / 2 - (SC(45) + CUP_Y_ADJUST)));
      gpath_move_to(s_vapor_right, GPoint(bounds.size.w / 2 + SC(6), bounds.size.h / 2 - (SC(45) + CUP_Y_ADJUST)));
      s_tea_cup_loaded = 2;
    }
  }
  
  // Update the points of the fill path dynamically
  if(current_fill_h <= SC(15)) {
    s_path_tea_cup_fill.points[0] = GPoint(cup_side_offset - current_fill_h, cup_h - current_fill_h);
    s_path_tea_cup_fill.points[5] = GPoint((cup_w - cup_side_offset) + current_fill_h, cup_h - current_fill_h);
    s_path_tea_cup_fill.points[1] = s_path_tea_cup_fill.points[0];
    s_path_tea_cup_fill.points[4] = s_path_tea_cup_fill.points[5];
  } else {
    s_path_tea_cup_fill.points[0] = GPoint(0, cup_h - current_fill_h);
    s_path_tea_cup_fill.points[5] = GPoint(cup_w, cup_h - current_fill_h);
    s_path_tea_cup_fill.points[1] = GPoint(0, cup_mid_y);
    s_path_tea_cup_fill.points[4] = GPoint(cup_w, cup_mid_y);
  }
  
  // Fill drawing
  graphics_context_set_fill_color(ctx, GColorBlack);
  gpath_draw_filled(ctx, s_tea_cup);
  
  graphics_context_set_fill_color(ctx, GColorWhite);
  gpath_draw_filled(ctx, s_plate);
  gpath_draw_filled(ctx, s_tea_cup_fill);
  
  // Outline drawing
  graphics_context_set_stroke_color(ctx, GColorBlack);
  graphics_context_set_stroke_width(ctx, STROKE_WIDTH);
  gpath_draw_outline(ctx, s_plate);
  gpath_draw_outline(ctx, s_tea_cup);
  gpath_draw_outline(ctx, s_handle);
  
  if(vapor && s_tea_cup_loaded > 1) {
    gpath_draw_outline(ctx, s_vapor_left);
    gpath_draw_outline(ctx, s_vapor_right);
  }
}

void tea_cup_destroy() {
  if(s_tea_cup_loaded > 0) {
    gpath_destroy(s_tea_cup);
    gpath_destroy(s_tea_cup_fill);
    gpath_destroy(s_plate);
    gpath_destroy(s_handle);
    if(s_tea_cup_loaded > 1) {
      gpath_destroy(s_vapor_left);
      gpath_destroy(s_vapor_right);
    }
    s_tea_cup_loaded = 0;
  }
}