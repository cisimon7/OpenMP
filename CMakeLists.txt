cmake_minimum_required(VERSION 3.21)
project(OpenMP)

set(CMAKE_CXX_STANDARD 23)
set(OPEN_MP_DIR ${PROJECT_SOURCE_DIR}/dependencies/openMP)

# To tell the compiler that you want to use OpenMP
SET(OPENMP_COMPILE_FLAGS "-Xpreprocessor -fopenmp")
#SET(OPENMP_LINK_FLAGS    "-fopenmp=libomp")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${OPENMP_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${OPENMP_LINK_FLAGS}")

add_executable(OpenMP main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${OPEN_MP_DIR}/include)

set(OPEN_MP_LIB "${OPEN_MP_DIR}/lib/libomp.dylib") # Make sure to use the omp library for your computer architecture
target_link_libraries(${PROJECT_NAME} ${OPEN_MP_LIB})

#set(OMP_FLAG_GNU "-fopenmp")
#set(OMP_FLAG_Clang "-fopenmp=libomp")
#set(OMP_FLAG_HP "+Openmp")

#include_directories("/opt/homebrew/include" "/opt/homebrew/opt/llvm/include")
#link_directories("/opt/homebrew/lib" "/opt/homebrew/opt/llvm/lib")

#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -fopenmp=libiomp5")

#-DCMAKE_C_COMPILER="-L/opt/homebrew/opt/llvm/bin/clang" -DCMAKE_CXX_COMPILER="-L/opt/homebrew/opt/llvm/bin/clang++"

#message(STATUS "${OpenMP_CXX_FLAGS}")

#target_compile_options(first-test PRIVATE -fopenmp)

#[[
export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"
export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"
]]

#[[
-DCMAKE_C_COMPILER="/opt/homebrew/opt/llvm/bin/clang"
-DCMAKE_CXX_COMPILER="/opt/homebrew/opt/llvm/bin/clang++"
]]
