# ---[ Project and semantic versioning.
project(foo CXX C)

option(BUILD_SHARED_LIBS "" ON)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include_directories(${PROJECT_SOURCE_DIR})


# Set 1: it passes, but gives you warning about inconsistent dll linkage
# because we are using dllimport in foo.dll. This is C4273 error.
# add_library(foo foo.cc)
# add_executable(main main.cc)
# target_link_libraries(main foo)


# Set 2: explicitly add definition of MY_EXPORTS across the board. Passes.
# add_definitions("-DMY_EXPORTS")
# add_library(foo foo.cc)
# add_executable(main main.cc)
# target_link_libraries(main foo)


# Set 3: do exports and imports properly. This should be the right way. Passes.
add_library(foo foo.cc)
target_compile_definitions(foo PRIVATE "-DMY_EXPORTS")
add_executable(main main.cc)
target_link_libraries(main foo)
