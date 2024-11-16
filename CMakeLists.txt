cmake_minimum_required(VERSION 3.5.0)
project(sfml-project VERSION 0.1.0)

# As std::auto_ptr was removed in C++17, sfml-audio fails to compile
# with following CXX standards. So instead of setting a global standard
# this template sets CXX_STANDARD to 17 using set_property.
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED True)

# Copy all the required SFML libs and main executable to bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)

# Build SFML
add_subdirectory(vendors/sfml/)

# Collect all the source and header files (use GLOB in place of GLOB_RECURSE if you only want to collect the files from root dir)
file(GLOB_RECURSE ALL_SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE ALL_HEADER_FILES "${CMAKE_SOURCE_DIR}/include/*.hpp")

# Add the main target.
add_executable(${PROJECT_NAME} ${ALL_SOURCE_FILES} ${ALL_HEADER_FILES})

# Use C++17 standards
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Include directories for main target
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${PROJECT_SOURCE_DIR}/include/
    PRIVATE ${PROJECT_SOURCE_DIR}/vendors/sfml/include/
)

# Link required libraries (add sfml-audio and sfml-network if needed)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Copy resources folder to the binary output directory (to handle resource dependency for the executable)
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR}/bin)