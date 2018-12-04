file(GLOB HEADERS "include/CreateCoin/plugins/auth_util/*.hpp")

add_library( CreateCoin_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( CreateCoin_auth_util CreateCoin_app CreateCoin_chain CreateCoin_protocol fc )
target_include_directories( CreateCoin_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
