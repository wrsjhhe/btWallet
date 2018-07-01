aux_source_directory(. DIR_MATH_SRCS)

add_subdirectory(./external)

add_library(math ${DIR_MATH_SRCS})
target_link_libraries(math
        secp256k1
        external)