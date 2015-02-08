**gpuctl** allows forcing Macs to use only the integrated or discrete GPU.

Run `build.sh` to build and then run `./gpuctl` for help.

To run tests, install [cram](https://pypi.python.org/pypi/cram) and run
`GPUCTL=$PWD/gpuctl cram test.t`.

Tested only with Early 2013 and Late 2014 MacBook Pros. Use with caution on
older Macs.

--

Licensed under the MIT license. See LICENSE.txt for details.
