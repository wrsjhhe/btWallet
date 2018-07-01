aux_source_directory(. DIR_CHAIN_SRCS)
add_library(chain ${DIR_CHAIN_SRCS})
target_link_libraries(chain
        -lboost_thread)