#include_directories(${X11_INCLUDE_DIR})
add_executable(projectTransparent main.cc)
target_link_libraries(projectTransparent ${X11_LIBRARIES})
install(TARGETS
   projectTransparent
   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
