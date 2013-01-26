#include_directories(${X11_INCLUDE_DIR})
add_executable(project1 project1.cc)
target_link_libraries(project1 ${X11_LIBRARIES})
install(TARGETS
   project1
   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
