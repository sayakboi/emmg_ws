-- Magnum on Web

Please note the directories

cmake commands for building corrade 

```
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE="/home/sayak/emmg_ws/toolchains/generic/Emscripten.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX=/home/sayak/emsdk/upstream/emscripten/cache/sysroot \
    -DCORRADE_RC_EXECUTABLE=/home/sayak/corrade/build/bin/corrade-rc
cmake --build . --target install
```
cmake commands for building corrade 
```
cmake .. \
    -DCMAKE_TOOLCHAIN_FILE="../toolchains/generic/Emscripten.cmake" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH=/home/sayak/emsdk/upstream/emscripten/cache/sysroot \
    -DCMAKE_INSTALL_PREFIX=/home/sayak/emsdk/upstream/emscripten/cache/sysroot \
    -DCORRADE_RC_EXECUTABLE=/home/sayak/corrade/build/bin/corrade-rc \
    -DMAGNUM_DEPLOY_PREFIX=/srv/http/magnum \
    -DMAGNUM_WITH_SDL2APPLICATION=ON
cmake --build . --target install
```

in magnum do a git submodule init to get the toolchains submodule. In that go to toolchains/generic/Emscripten.cmake
Change set(EMSCRIPTEN_PREFIX "/usr/lib/emscripten")  to  set(EMSCRIPTEN_PREFIX "/home/sayak/emsdk/upstream/emscripten")

also 
change set(EMSCRIPTEN_TOOLCHAIN_PATH "${EMSCRIPTEN_PREFIX}/system")  to  set(EMSCRIPTEN_TOOLCHAIN_PATH "${EMSCRIPTEN_PREFIX}/cache/sysroot")

In this project add the same toolchain as submodule. use the modules directory in magnum to find all required packages (as done in this project's CMakeLists.txt file) 

to build this project follow commands:

```
cmake -DCMAKE_TOOLCHAIN_FILE="/home/sayak/emmg_ws/toolchains/generic/Emscripten-wasm.cmake" ..
make
```