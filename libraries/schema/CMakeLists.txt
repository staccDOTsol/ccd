file(GLOB HEADERS "include/CreateCoin/schema/*.hpp")
add_library( CreateCoin_schema schema.cpp ${HEADERS} )
target_link_libraries( CreateCoin_schema fc )
target_include_directories( CreateCoin_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   CreateCoin_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/CreateCoin/schema" )
