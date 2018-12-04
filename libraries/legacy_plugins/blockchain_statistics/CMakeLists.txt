file(GLOB HEADERS "include/CreateCoin/blockchain_statistics/*.hpp")

add_library( CreateCoin_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( CreateCoin_blockchain_statistics CreateCoin_chain CreateCoin_protocol CreateCoin_app )
target_include_directories( CreateCoin_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   CreateCoin_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)