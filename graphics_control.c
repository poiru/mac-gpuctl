// Copyright 2015 Birunthan Mohanathas
//
// Licensed under the MIT license <http://opensource.org/licenses/MIT>. This
// file may not be copied, modified, or distributed except according to those
// terms.

// This is largely based on gfxCardStatus by Cody Krieger.

#include "graphics_control.h"

enum
{
  graphics_control_method_open = 0,
  graphics_control_method_close = 1,
  graphics_control_method_set_mux_state = 2,
  graphics_control_method_get_mux_state = 3
};

enum
{
  // Param: 0
  mux_force_gpu_switch = 2,

  // Param: 0 to disable, 1 to enable.
  mux_set_dynamic_switching = 4,

  // Param: 0
  mux_get_graphics_card = 7
};

io_connect_t connect_graphics_control()
{
  kern_return_t kr = KERN_SUCCESS;
  io_iterator_t iterator = IO_OBJECT_NULL;
  kr = IOServiceGetMatchingServices(kIOMasterPortDefault,
                                    IOServiceMatching("AppleGraphicsControl"),
                                    &iterator);
  if (kr != KERN_SUCCESS) {
    return IO_OBJECT_NULL;
  }

  // Assume that there is only one service.
  io_service_t service = IOIteratorNext(iterator);
  IOObjectRelease(iterator);
  if (service == IO_OBJECT_NULL) {
    return IO_OBJECT_NULL;
  }

  io_connect_t connect;
  kr = IOServiceOpen(service, mach_task_self(), 0, &connect);
  if (kr != KERN_SUCCESS) {
    return IO_OBJECT_NULL;
  }

  kr = IOConnectCallScalarMethod(connect,
                                 graphics_control_method_open,
                                 NULL, 0, NULL, NULL);
  if (kr != KERN_SUCCESS) {
    IOServiceClose(connect);
    return IO_OBJECT_NULL;
  }

  return connect;
}

void close_graphics_control(io_connect_t io_connect)
{
  kern_return_t kr = KERN_SUCCESS;
  kr = IOConnectCallScalarMethod(io_connect,
                                 graphics_control_method_close,
                                 NULL, 0, NULL, NULL);
  if (kr == KERN_SUCCESS) {
    IOServiceClose(io_connect);
  }
}

static bool set_graphics_mux_state(io_connect_t connect, uint32_t action,
                                   uint64_t arg)
{
    kern_return_t kr = KERN_SUCCESS;
    uint64_t scalarI_64[3] = { 1, (uint64_t)action, arg };
    kr = IOConnectCallScalarMethod(connect,
                                   graphics_control_method_set_mux_state,
                                   scalarI_64, 3, NULL, 0);
    return kr == KERN_SUCCESS;
}

static bool get_graphics_mux_state(io_connect_t connect, uint32_t input,
                                   uint64_t* output)
{
  kern_return_t kr = KERN_SUCCESS;
  uint32_t outputCount = 1;
  uint64_t scalarI_64[2] = { 1, input };
  kr = IOConnectCallScalarMethod(connect,
                                 graphics_control_method_get_mux_state,
                                 scalarI_64, 2, output, &outputCount);
  return kr == KERN_SUCCESS;
}

bool force_graphics_switch(io_connect_t connect)
{
    return set_graphics_mux_state(connect, mux_force_gpu_switch, 0);
}

bool set_dynamic_graphics_switching(io_connect_t connect, bool enable)
{
    return set_graphics_mux_state(connect, mux_set_dynamic_switching,
                                  (uint64_t)enable);
}

bool is_using_integrated_graphics(io_connect_t connect)
{
    uint64_t output = 0;
    get_graphics_mux_state(connect, mux_get_graphics_card, &output);
    return output != 0;
}
