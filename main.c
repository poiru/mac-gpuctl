// Copyright 2015 Birunthan Mohanathas
//
// Licensed under the MIT license <http://opensource.org/licenses/MIT>. This
// file may not be copied, modified, or distributed except according to those
// terms.

#include "graphics_control.h"

int main(int argc, char* argv[])
{
  io_connect_t connect = connect_graphics_control();
  if (connect == IO_OBJECT_NULL) {
    return 1;
  }

  // TODO: Right now, this just forces the integrated GPU and disables GPU
  // switching. An option to force the discrete GPU would be nice.

  if (!is_using_integrated_graphics(connect)) {
    set_graphics_mux_state(connect, mux_force_gpu_switch, 0);

    // Wait 100ms and then try to disable GPU switching every 10ms.
    usleep(1000 * 100);
    for (int i = 0; i < 50; ++i) {
      if (is_using_integrated_graphics(connect)) {
        set_graphics_mux_state(connect, mux_set_dynamic_switching, 0);
        break;
      }
      usleep(1000 * 10);
    }
  }

  close_graphics_control(connect);
  return 0;
}
