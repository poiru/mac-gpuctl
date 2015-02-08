// Copyright 2015 Birunthan Mohanathas
//
// Licensed under the MIT license <http://opensource.org/licenses/MIT>. This
// file may not be copied, modified, or distributed except according to those
// terms.

#ifndef MAC_GPU_CONTROL_GRAPHICS_CONTROL_H
#define MAC_GPU_CONTROL_GRAPHICS_CONTROL_H

#include <IOKit/IOKitLib.h>

io_connect_t connect_graphics_control();
void close_graphics_control(io_connect_t io_connect);

void force_graphics_switch(io_connect_t connect);
bool is_dynamic_graphics_switching(io_connect_t connect);
void set_dynamic_graphics_switching(io_connect_t connect, bool enable);
bool is_using_integrated_graphics(io_connect_t connect);

#endif
