{
  "targets": [
    {
      "target_name": "xoroshirojs",
      "sources": [ "xoroshirojs.cc", "splitmix64.cc", "xoroshiro128plus.cc" ],
      "cflags": ["-fno-move-loop-invariants", "-fno-unroll-loops"],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
