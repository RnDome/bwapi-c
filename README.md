# bwapi-c [![Build Status](https://travis-ci.org/RnDome/bwapi-c.svg?branch=master)](https://travis-ci.org/RnDome/bwapi-c)
C bindings to the BWAPI library 

# BWAPI again? Why?

The original `BWAPId.lib` is written in C++. Due to mangling etc... you can't link against `BWAPId.lib` with other compilers but only with `cl.exe` and `link.exe`. The goal of this library is to provide a minimalistic C API which can be used to create bindings for high-level languages.

# Build on Linux

```
bwapi-c/ $ mkdir build && cd build
bwapi-c/build $ cmake .. -DBWAPI_PATH=~/Downloads/BWAPI
bwapi-c/build $ make
```

`BWAPI_PATH` must point to directory with BWAPI release.

# Usage on Linux
You should get `BWAPIC.lib` that was build on Windows with MSVC.

```
~/bwapi-c/example $ ls
BWAPIC.lib  Dll.cpp
~/bwapi-c/example $ i686-w64-mingw32-g++ -std=c++11 -mabi=ms -shared -o Dll.dll Dll.cpp -I../include -L. -lBWAPIC
~/bwapi-c/example $ ls
BWAPIC.lib  Dll.cpp  Dll.dll
```
