// Copyright 2015 Birunthan Mohanathas
//
// Licensed under the MIT license <http://opensource.org/licenses/MIT>. This
// file may not be copied, modified, or distributed except according to those
// terms.

#include <stdio.h>
#include <string.h>

#include "graphics_control.h"

int main(int argc, char* argv[])
{
  io_connect_t connect = connect_graphics_control();
  if (connect == IO_OBJECT_NULL) {
    return 1;
  }

  if (argc == 1) {
    puts("gpuctl: usage: [--force-integrated | --force-discrete]");
    return 1;
  } else if (argc > 2) {
    puts("gpuctl: Too many option");
    return 1;
  }

  const char* opt = argv[1];
  if (strcmp(opt, "--force-integrated") == 0) {
    if (!is_using_integrated_graphics(connect)) {
      force_graphics_switch(connect);

      // The GPU switch typically takes ~150ms. When switching to integrated,
      // dynamic switching is enabled shortly after the GPU switch occurs. So
      // we wait 300ms here before disabling dynamic switching.
      usleep(1000 * 300);
    }

    set_dynamic_graphics_switching(connect, false);
  } else if (strcmp(opt, "--force-discrete") == 0) {
    set_dynamic_graphics_switching(connect, false);
    if (is_using_integrated_graphics(connect)) {
      force_graphics_switch(connect);
    }
  } else {
    puts("gpuctl: Invalid option");
  }

  close_graphics_control(connect);
  return 0;
}
