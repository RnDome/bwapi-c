# bwapi-c [![Build Status](https://travis-ci.org/RnDome/bwapi-c.svg?branch=master)](https://travis-ci.org/RnDome/bwapi-c)
C bindings to the BWAPI library 

# BWAPI again? Why?

The original `BWAPId.lib` is written in C++. Due to mangling etc... you can't link against `BWAPId.lib` with other compilers but only with `cl.exe` and `link.exe`. The goal of this library is to provide a minimalistic C API which can be used to create bindings for high-level languages.

# Build

```
bwapi-c/ $ mkdir build && cd build
bwapi-c/build $ cmake ..
bwapi-c/build $ make
```

# Usage
All you need is to link this library with `BWAPId.lib` >< TODO
