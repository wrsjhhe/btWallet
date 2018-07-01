aux_source_directory(. DIR_WALLET_SRCS)
add_library(wallet ${DIR_WALLET_SRCS})
target_link_libraries(wallet)