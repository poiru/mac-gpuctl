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

  bool force_integrated = false;
  const char* opt = argv[1];
  if (strcmp(opt, "--force-integrated") == 0) {
    force_integrated = true;
  } else if (strcmp(opt, "--force-discrete") == 0) {
    force_integrated = false;
  } else {
    puts("gpuctl: Invalid option");
    return 1;
  }

  set_dynamic_graphics_switching(connect, false);

  if (is_using_integrated_graphics(connect) != force_integrated) {
    force_graphics_switch(connect);
  }

  close_graphics_control(connect);
  return 0;
}
