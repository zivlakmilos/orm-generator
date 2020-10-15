cmake_minimum_required(VERSION 2.8.11)
project(ormgenerator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(include/)
include_directories(${CMAKE_BINARY_DIR})

# JSON Library
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(lib/json)

set(project_SRC
    src/main.cpp
)

set(project_LIB
    nlohmann_json::nlohmann_json
)

# Tell CMake to create the rrf executable
add_executable(${PROJECT_NAME} ${project_SRC})

# Tell CMake to link the rrf executable
target_link_libraries(${PROJECT_NAME} ${project_LIB})

# Install the executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
