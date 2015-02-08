Switching from integrated to discrete should work.

  $ $GPUCTL --force-integrated
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: false

  $ $GPUCTL --force-discrete
  $ sleep 1 && $GPUCTL --stat
  GPU: discrete
  Dynamic: false

Switching from integrated to dynamic should work.

  $ $GPUCTL --force-integrated
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: false

  $ $GPUCTL --dynamic
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: true

Switching from discrete to integrated should work.

  $ $GPUCTL --force-discrete
  $ sleep 1 && $GPUCTL --stat
  GPU: discrete
  Dynamic: false

  $ $GPUCTL --force-integrated
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: false

Switching from discrete to dynamic should work.

  $ $GPUCTL --force-discrete
  $ sleep 1 && $GPUCTL --stat
  GPU: discrete
  Dynamic: false

  $ $GPUCTL --dynamic
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: true

Switching from dynamic to integrated should work.

  $ $GPUCTL --dynamic
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: true

  $ $GPUCTL --force-integrated
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: false

Switching from dynamic to discrete should work.

  $ $GPUCTL --dynamic
  $ sleep 1 && $GPUCTL --stat
  GPU: integrated
  Dynamic: true

  $ $GPUCTL --force-discrete
  $ sleep 1 && $GPUCTL --stat
  GPU: discrete
  Dynamic: false
