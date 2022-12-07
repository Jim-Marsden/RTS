cmake_minimum_required(VERSION 3.23)
project("swifty and divi's rts")
add_subdirectory(third_party)
add_executable(RTS src/window_manager.cpp src/window_manager.h src/main2.cpp)
target_compile_features(RTS PRIVATE cxx_std_23)
set_target_properties(RTS PROPERTIES CXX_EXTENSIONS ON)
target_link_libraries(RTS Catch2::Catch2 SFML::Graphics ImGui-SFML::ImGui-SFML)
file(COPY data DESTINATION . )


