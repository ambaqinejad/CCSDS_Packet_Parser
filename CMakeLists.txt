cmake_minimum_required(VERSION 3.30)
project(CCSDS_PARSER)

set(CMAKE_CXX_STANDARD 20)

# Ensure we are building a shared library
set(BUILD_SHARED_LIBS ON)

# Add the shared library
add_library(CCSDS SHARED CCSDS/CCSDS_Packet.cpp)

# Ensure correct output names
set_target_properties(CCSDS PROPERTIES
        OUTPUT_NAME "CCSDS"
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# Ensure include directories
target_include_directories(CCSDS PUBLIC ${CMAKE_SOURCE_DIR})

# Create executable and link the shared library
add_executable(CCSDS_PARSER main.cpp)
target_link_libraries(CCSDS_PARSER PRIVATE CCSDS)
