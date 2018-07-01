cmake_minimum_required(VERSION 3.10)
project(btWallet)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(./src DIRSRCS)
aux_source_directory(./src/chain chain)
aux_source_directory(./src/wallet wallet)
aux_source_directory(./src/wallet/parse_encrypted_keys parse_encrypted_keys)

include_directories(./include)

add_subdirectory(./src/config)
add_subdirectory(./src/formats)
add_subdirectory(./src/log)
add_subdirectory(./src/machine)
add_subdirectory(./src/math)
add_subdirectory(./src/message)
add_subdirectory(./src/unicode)
add_subdirectory(./src/utility)
add_subdirectory(./src/network)
add_subdirectory(./src/protocols)
add_subdirectory(./src/client)

add_executable(btWallet
        ${DIRSRCS}
        ${chain}
        ${wallet}
        ${parse_encrypted_keys}
        )

target_link_libraries(btWallet
        boost_system
        boost_thread
        pthread
        math
        config
        formats
        log
        machine
        message
        unicode
        utility
        network
        protocols
        client
        )