file(GLOB HEADERS "include/CreateCoin/plugins/block_info/*.hpp")

add_library( CreateCoin_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( CreateCoin_block_info CreateCoin_app CreateCoin_chain CreateCoin_protocol fc )
target_include_directories( CreateCoin_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
