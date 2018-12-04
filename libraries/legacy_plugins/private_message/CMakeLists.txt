file(GLOB HEADERS "include/CreateCoin/private_message/*.hpp")

add_library( CreateCoin_private_message
             private_message_plugin.cpp
           )

target_link_libraries( CreateCoin_private_message CreateCoin_chain CreateCoin_protocol CreateCoin_app )
target_include_directories( CreateCoin_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   CreateCoin_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
