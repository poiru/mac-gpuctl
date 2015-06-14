**gpuctl** allows forcing Macs to use only the integrated or discrete GPU.

Run `build.sh` to build and then run `./gpuctl` for help.

To run tests, install [cram](https://pypi.python.org/pypi/cram) and run
`GPUCTL=$PWD/gpuctl cram test.t`.

Tested only with Early 2013 and Late 2014 MacBook Pros. Use with caution on
older Macs.

### Run on boot

To run gpuctl on boot, create `~/Library/LaunchAgents/com.user.gpuctl.plist` with the following contents:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
  <key>Label</key>
  <string>com.user.gpuctl</string>
  <key>ProgramArguments</key>
  <array>
    <string>/usr/local/bin/gpuctl</string>
    <string>--force-integrated</string>
  </array>
  <key>RunAtLoad</key>
  <true/>
</dict>
</plist>
```

--

Licensed under the MIT license. See LICENSE.txt for details.
