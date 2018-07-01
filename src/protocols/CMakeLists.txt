aux_source_directory(. DIR_ZMQ_SRCS)
add_library(protocols ${DIR_ZMQ_SRCS})
target_link_libraries(protocols -lzmq config formats)