cmake_minimum_required(VERSION 3.10)


set(SINGULARITY_SRC_FILES 
    ${CMAKE_SOURCE_DIR}/source/singularity.c
)

add_library(singularity STATIC)

target_sources(singularity PRIVATE ${SINGULARITY_SRC_FILES})
