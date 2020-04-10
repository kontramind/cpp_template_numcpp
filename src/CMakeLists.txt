# option(CPP_STARTER_USE_QT "Enable compilation of QT sample" OFF)
# option(CPP_STARTER_USE_FLTK "Enable compilation of FLTK sample" OFF)
# option(CPP_STARTER_USE_IMGUI "Enable compilation of ImGui sample" OFF)
# option(CPP_STARTER_USE_SDL "Enable compilation of SDL sample" OFF)

# # sdl
# if(CPP_STARTER_USE_SDL)
#   message("Using SDL2")
#   add_subdirectory(sdl)
# endif()

# # qt
# if(CPP_STARTER_USE_QT)
#   message("Using Qt")
#   add_subdirectory(qt)
# endif()

# # fltk test
# if(CPP_STARTER_USE_FLTK)
#   message("Using FLTK")
#   add_subdirectory(fltk)
# endif()

# # imgui example
# if(CPP_STARTER_USE_IMGUI)
#   message("Using Dear ImGui")
#   add_subdirectory(imgui)
# endif()

# Generic test that uses conan libs
add_executable(intro main.cpp)
target_link_libraries(intro
                      PRIVATE
                      project_options
                      project_warnings
                      ${Boost_LIBRARIES}
)
