#!/bin/sh
clang main.c graphics_control.c \
  -o gpuctl \
  -DNDEBUG -O2 \
  -std=c11 -Wall -framework IOKit
