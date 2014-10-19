#include <pebble.h>

Window *window;
TextLayer *text_layer;

static void window_load(Window *window) {
  
}

static void window_unload(Window *window) {
  
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "select clicked");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "up clicked");
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "down clicked");
}

static void handle_minute_tick(struct tm *tick_time, TimeUnits units_changed) {
  APP_LOG(APP_LOG_LEVEL_INFO, "minute changed");
}

static void handle_second_tick(struct tm *tick_time, TimeUnits units_changed) {
  APP_LOG(APP_LOG_LEVEL_INFO, "second changed");
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  tick_timer_service_subscribe(SECOND_UNIT, handle_second_tick);
  tick_timer_service_subscribe(MINUTE_UNIT, handle_minute_tick);
}

void deinit(void) {
  text_layer_destroy(text_layer);
  window_destroy(window);
}

void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  
  text_layer = text_layer_create(GRect(0, 0, 144, 20));
  window_stack_push(window, true);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
