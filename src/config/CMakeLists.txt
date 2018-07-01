aux_source_directory(. DIR_CONFIG_SRCS)
add_library(config ${DIR_CONFIG_SRCS})
target_link_libraries(config
            -lboost_program_options
            -lboost_regex)