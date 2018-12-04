file(GLOB HEADERS "include/CreateCoin/plugins/raw_block/*.hpp")

add_library( CreateCoin_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( CreateCoin_raw_block CreateCoin_app CreateCoin_chain CreateCoin_protocol fc )
target_include_directories( CreateCoin_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
