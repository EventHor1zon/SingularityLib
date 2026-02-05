cmake_minimum_required(CMAKE_VERSION 3.10)

add_library(singularity STATIC)
add_subdirectory(include)

set(SINGULARITY_ABS_PATH ${CMAKE_SOURCE_DIR}/Drivers/singularity_lib)

set(SINGULARITY_SRC_FILES 
    ${SINGULARITY_ABS_PATH}/source/singularity.c
)

target_sources(singularity PRIVATE SINGULARITY_SRC_FILES)
