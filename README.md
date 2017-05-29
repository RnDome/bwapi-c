bwapi-c
=======

[![Build Status](https://travis-ci.org/RnDome/bwapi-c.svg?branch=master)](https://travis-ci.org/RnDome/bwapi-c/branches) [![Build status](https://ci.appveyor.com/api/projects/status/3l3mngo6cf33hdrw/branch/master?svg=true)](https://ci.appveyor.com/project/kpp/bwapi-c/branch/master)

C language bindings to the BWAPI library 

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
You should get `BWAPIC.lib` and `BWAPIC.dll` that was build on Windows with MSVC. See [Releases](https://github.com/RnDome/bwapi-c/releases).

```
~/bwapi-c/example $ ls
BWAPIC.lib  Dll.c
~/bwapi-c/example $ i686-w64-mingw32-gcc -mabi=ms -shared -o Dll.dll Dll.c -I../include -L. -lBWAPIC
~/bwapi-c/example $ ls
BWAPIC.lib  Dll.cpp  Dll.dll
```

Put `BWAPIC.dll` inside `StarCraft` directory and `Dll.dll` inside `StarCraft/bwapi-data`.
Set up `bwapi.ini` (`ai=bwapi-data/Dll.dll`) and run:
```
wine bwheadless.exe -e StarCraft.exe -l bwapi-data/BWAPI.dll --headful
```
