cmake_minimum_required(VERSION 3.17)
project(Test_Cpp_Standards CXX)

find_package(Torch 1.6 REQUIRED)
find_package(OpenCV 4.4 EXACT REQUIRED)
find_package(Boost 1.67 EXACT REQUIRED)
#find_package(Boost 1.67 QUIET REQUIRED COMPONENTS program_options)

# This is for matplotlib
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
find_package(Eigen3)

if (${EIGEN3_FOUND})
    include_directories(${EIGEN3_INCLUDE_DIR})
else()
    message(STATUS "Eigen3 not found")
endif()

find_package(Python3 COMPONENTS Interpreter Development)
if (${Python3_FOUND})
    include_directories(${Python3_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Python3 not found, please install it.")
endif()

find_package(NumPy)
if (${PYTHON_NUMPY_FOUND})
    include_directories(${PYTHON_NUMPY_INCLUDE_DIR})
else()
    message(WARNING "Python3 NumPy not found, proceeding with -DWITHOUT_NUMPY."
            " Some functions might not work.")
    add_definitions(-DWITHOUT_NUMPY)
endif()

 get_cmake_property(_variableNames VARIABLES)
 list(SORT _variableNames)
 foreach (_variableName ${_variableNames})
     message(STATUS "${_variableName}=${${_variableName}}")
 endforeach ()

add_subdirectory(copy)
add_subdirectory(pointers)
add_subdirectory(string)
#add_subdirectory(with_cpp11)
#add_subdirectory(with_cpp14)
#add_subdirectory(with_cpp17)
#add_subdirectory(with_cpp20)
add_subdirectory(with_python)
