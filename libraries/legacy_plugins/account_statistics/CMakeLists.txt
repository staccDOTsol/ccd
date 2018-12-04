file(GLOB HEADERS "include/CreateCoin/account_statistics/*.hpp")

add_library( CreateCoin_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( CreateCoin_account_statistics CreateCoin_chain CreateCoin_protocol CreateCoin_app )
target_include_directories( CreateCoin_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   CreateCoin_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)