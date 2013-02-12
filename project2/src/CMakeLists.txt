#include_directories(${X11_INCLUDE_DIR})

add_library(button button.cc)

add_executable(project2 main.cc)

target_link_libraries(project2 ${X11_LIBRARIES} button)

install(TARGETS
   project2
   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
