aux_source_directory(. DIR_NETWORK_SRCS)

add_subdirectory(./protocols net_protocols)
add_subdirectory(./sessions net_sessions)

add_library(network ${DIR_NETWORK_SRCS})
target_link_libraries(network net_protocols net_sessions)