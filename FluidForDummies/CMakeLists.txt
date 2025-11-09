cmake_minimum_required(VERSION 3.20)

project(FluidForDummies)
add_executable(app) # WIN32 - hide the console like this add_executable(app WIN32)

target_sources(app
PRIVATE
    main.cpp
    FluidCell.cpp
)

find_package(SDL3)
target_link_libraries(app PRIVATE SDL3::SDL3)
target_compile_definitions(app PRIVATE SDL_MAIN_USE_CALLBACKS)
target_link_options(app PRIVATE -static)