#include <pebble.h>

Window *window;
TextLayer *text_layer;

static void window_load(Window *window) {
  
}

static void window_unload(Window *window) {
  
}

void deinit(void) {
  text_layer_destroy(text_layer);
  window_destroy(window);
}

void init(void) {
  window = window_create();

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
