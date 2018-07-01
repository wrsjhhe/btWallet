aux_source_directory(. DIR_CLIENT_SRCS)
add_library(client ${DIR_CLIENT_SRCS})
target_link_libraries(client protocols)