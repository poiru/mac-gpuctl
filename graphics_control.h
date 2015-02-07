// Copyright 2015 Birunthan Mohanathas
//
// Licensed under the MIT license <http://opensource.org/licenses/MIT>. This
// file may not be copied, modified, or distributed except according to those
// terms.

#ifndef MAC_GPU_CONTROL_GRAPHICS_CONTROL_H
#define MAC_GPU_CONTROL_GRAPHICS_CONTROL_H

#include <IOKit/IOKitLib.h>

// This is largely based on gfxCardStatus by Cody Krieger.

enum
{
  // Param: 0
  mux_force_gpu_switch = 2,

  // Param: 0 to disable, 1 to enable.
  mux_set_dynamic_switching = 4,

  // Param: 0
  mux_get_graphics_card = 7
};

io_connect_t connect_graphics_control();
void close_graphics_control(io_connect_t io_connect);

bool set_graphics_mux_state(io_connect_t connect, uint32_t action, uint64_t arg);
bool get_graphics_mux_state(io_connect_t connect, uint32_t input, uint64_t* output);

bool is_using_integrated_graphics(io_connect_t connect);

#endif
