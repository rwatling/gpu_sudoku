cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(EEGraph LANGUAGES CXX CUDA)

##### Variables and flags
set(GPU_LIB "_cuda")
set(CPU_LIB "_cpp")
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O2")
set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS}")
set(MAIN_PROJECT "main")

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES "72;75")
endif()

##### FILES
file(GLOB main "${CMAKE_SOURCE_DIR}/src/main.cu")

file(GLOB cpp_source_files
  "${CMAKE_SOURCE_DIR}/src/argument_parsing.cpp"
  "${CMAKE_SOURCE_DIR}/src/utilities.cpp"
  "${CMAKE_SOURCE_DIR}/src/timer.cpp")

file(GLOB gpu_source_files)

##### Include directories
include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${GPU_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CPU_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

##### GPU Library
add_library(${GPU_LIB} STATIC ${gpu_source_files}
            "${CMAKE_SOURCE_DIR}/src/sudoku.cu")

# Target compile feautes
target_compile_features(${GPU_LIB} PUBLIC cxx_std_11)

# We need to explicitly state that we need all CUDA files in ${GPU_LIB}
# to be built with -dc
set_target_properties(${GPU_LIB} PROPERTIES CUDA_SEPARABLE_COMPILATION ON)

##### CPU Library
add_library(${CPU_LIB} STATIC ${cpp_source_files})

##### Executables - MAIN
add_executable(${MAIN_PROJECT} ${main})

##### Link libraries - MAIN PROJECT
target_link_libraries(${MAIN_PROJECT} PRIVATE ${GPU_LIB})
target_link_libraries(${MAIN_PROJECT} PRIVATE ${CPU_LIB})
target_link_libraries(${MAIN_PROJECT} PUBLIC)
set_property(TARGET ${MAIN_PROJECT} PROPERTY CXX_STANDARD 14)