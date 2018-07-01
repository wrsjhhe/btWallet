aux_source_directory(. DIR_LOG_SRCS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DBOOST_LOG_DYN_LINK")

add_library(log ${DIR_LOG_SRCS})
target_link_libraries(log -lboost_log)