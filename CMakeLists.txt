cmake_minimum_required(VERSION 3.5.0)
project(PalleteSwap VERSION 0.1.0 LANGUAGES C CXX)

# Find SDL2
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Add the executable using the gathered files
add_executable(PalleteSwap ${SRC_FILES})

target_include_directories(PalleteSwap PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(PalleteSwap PRIVATE ${SDL2_LIBRARIES})


include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
