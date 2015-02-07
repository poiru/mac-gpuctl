#!/bin/sh
clang main.c graphics_control.c -o gpuctl -std=c11 -Wall -framework IOKit
