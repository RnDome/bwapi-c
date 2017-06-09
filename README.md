bwapi-c
=======

[![Build Status](https://travis-ci.org/RnDome/bwapi-c.svg?branch=master)](https://travis-ci.org/RnDome/bwapi-c/branches) [![Build status](https://ci.appveyor.com/api/projects/status/3l3mngo6cf33hdrw/branch/master?svg=true)](https://ci.appveyor.com/project/kpp/bwapi-c/branch/master) [![release](https://img.shields.io/github/release/RnDome/bwapi-c/all.svg)](https://github.com/RnDome/bwapi-c/releases/latest)

C language bindings to the BWAPI library 

# BWAPI again? Why?

The original `BWAPI.dll` is written in C++. Due to mangling etc... you can't link against `BWAPI.dll` with other compilers but only with `cl.exe` and `link.exe`. The goal of this library is to provide a minimalistic C API which can be used to create bindings for high-level languages.

# Build on Linux

```
bwapi-c/ $ mkdir build && cd build
bwapi-c/build $ cmake .. -DBWAPI_PATH=~/Downloads/BWAPI
bwapi-c/build $ make
```

`BWAPI_PATH` must point to directory with BWAPI release.

# Usage on Linux
You should get `BWAPIC.lib`, `BWAPIC.dll` and `BWAPI.dll` that was build on Windows with MSVC. See [Releases](https://github.com/RnDome/bwapi-c/releases).

### Module

```
~/bwapi-c/example $ ls
BWAPIC.lib Dll.c
~/bwapi-c/example $ i686-w64-mingw32-gcc -mabi=ms -shared -o Dll.dll Dll.c -I../include -L. -lBWAPIC
~/bwapi-c/example $ ls
BWAPIC.lib  Dll.cpp  Dll.dll
```

Put `BWAPIC.dll` inside `StarCraft` directory and `Dll.dll` inside `StarCraft/bwapi-data`.
Set up `bwapi.ini` (`ai=bwapi-data/Dll.dll`) and run:
```
$ wine bwheadless.exe -e StarCraft.exe -l bwapi-data/BWAPI.dll --headful
```

### Client
```
~/bwapi-c/example $ ls
BWAPIC.lib Client.c
~/bwapi-c/example $ i686-w64-mingw32-gcc -mabi=ms -o Client.exe Client.c -I../include -L. -lBWAPIC
~/bwapi-c/example $ ls
BWAPIC.lib Client.c Client.exe
```

Put `Client.exe` into a directory with `BWAPIC.dll` and `BWAPI.dll`. Run in the first terminal:
```
~/bwapi-c/example $ ls
Client.exe BWAPIC.dll BWAPI.dll
~/bwapi-c/example $ wine Client.exe 
fixme:module:load_library unsupported flag(s) used (flags: 0x00000800)
...
fixme:ntdll:EtwEventRegister ({5eec90ab-c022-44b2-a5dd-fd716a222a15}, 0x2a27f0, 0x2b0030, 0x2b0048) stub.
fixme:ntdll:EtwEventSetInformation (deadbeef, 2, 0x2a2560, 43) stub
Reconnecting...
Game table mapping not found.
...
```

Set up `bwapi.ini` (comment out `ai=...` and `ai_dbg=...`) and run in the second terminal:
```
$ wine bwheadless.exe -e StarCraft.exe -l bwapi-data/BWAPI.dll --headful
```

Switch to the first terminal, you shall see:
```
...
Game table mapping not found.
0 | 62 | 0 | 36406654
1 | 0 | 0 | 0
2 | 0 | 0 | 0
3 | 0 | 0 | 0
4 | 0 | 0 | 0
5 | 0 | 0 | 0
6 | 0 | 0 | 0
7 | 0 | 0 | 0
Connected
Connection successful
```

Open Starcraft gui window, start a game or replay, the client in the first terminal will report you:
```
Connected
Connection successful
Starting match
```
