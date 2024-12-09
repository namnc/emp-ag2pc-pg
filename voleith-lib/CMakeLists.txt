cmake_minimum_required(VERSION 3.22)
project(voleith-lib)

# Get SHA3 implementation type from environment variable, default to 'plain32'
if(DEFINED ENV{SHA3})
    set(SHA3_IMPL $ENV{SHA3})
else()
    set(SHA3_IMPL "plain32")
endif()

# Define source files based on SHA3 implementation
if(SHA3_IMPL STREQUAL "opt64")
    set(SHA3_SOURCES
        sha3/opt64/KeccakP-1600-opt64.c
        sha3/opt64/KeccakP-1600-times4-on1.c
    )
    set(SHA3_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/sha3/opt64
    )
elseif(SHA3_IMPL STREQUAL "plain32")
    set(SHA3_SOURCES
        sha3/plain32/KeccakP-1600-inplace32BI.c
        sha3/plain32/KeccakP-1600-times4-on1.c
    )
    set(SHA3_INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/sha3/plain32
    )
else()
    message(FATAL_ERROR "Unknown SHA3 implementation: ${SHA3_IMPL}")
endif()


# # Create library with all the files
file(GLOB SOURCES 
    "./*.c"
    "./*.h"
)
file(GLOB SHA3 "./sha3/*.c" "./sha3/*.h")


add_library(voleith-lib
    STATIC
    ${SOURCES}
    ${SHA3}
    ${SHA3_SOURCES}    
)

message(SHA3_INCLUDE_DIRS=${SHA3_INCLUDE_DIRS})

# Set include directories
target_include_directories(voleith-lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/sha3
    ${SHA3_INCLUDE_DIRS}
)
