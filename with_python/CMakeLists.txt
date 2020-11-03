set(CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-g -O0")
set(PYBIND11_PYTHON_VERSION 3.8 CACHE STRING "")
add_subdirectory(extensions/pybind11)

include_directories(extensions/utils)

add_subdirectory(extensions/stl)