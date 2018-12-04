add_executable( CreateCoind main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling CreateCoind with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( CreateCoin_STATIC_BUILD )
   target_link_libraries( CreateCoind PRIVATE
      "-static-libstdc++ -static-libgcc"
      appbase
      CreateCoin_utilities
      CreateCoin_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( CreateCoin_STATIC_BUILD )
   target_link_libraries( CreateCoind PRIVATE
      appbase
      CreateCoin_utilities
      CreateCoin_plugins
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( CreateCoin_STATIC_BUILD )

if( CLANG_TIDY_EXE )
   set_target_properties(
      CreateCoind PROPERTIES
      CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
   )
endif( CLANG_TIDY_EXE )

install( TARGETS
   CreateCoind

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
