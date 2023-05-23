cmake_minimum_required(VERSION 3.5)
project(my_project)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})
## set(CMAKE_MODULE_PATH "/home/sayak/corrade/modules/" ${CMAKE_MODULE_PATH})
## set(CMAKE_PREFIX_PATH "/usr/share/cmake/Corrade" ${CMAKE_PREFIX_PATH})
# Add Magnum package
find_package(Corrade REQUIRED)
find_package(Magnum REQUIRED GL Shaders Primitives Sdl2Application)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Emscripten-specific settings
set(CMAKE_TOOLCHAIN_FILE "/home/sayak/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake")
#set(CMAKE_EXECUTABLE_SUFFIX ".html")

# Enable Emscripten-specific settings
set(EMSCRIPTEN True)

# Set the output directory for the generated JavaScript and HTML files
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/web)

# Add source files
add_executable(my_project
    src/main.cpp
    src/MyApplication.cpp
)

# Link libraries
target_link_libraries(my_project PRIVATE
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::Shaders
    Magnum::Primitives
)

# Configure the JavaScript file
configure_file(index.html ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/index.html COPYONLY)
