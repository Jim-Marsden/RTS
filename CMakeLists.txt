cmake_minimum_required(VERSION 3.16)
project(RTS)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        smk
        GIT_REPOSITORY https://github.com/ArthurSonzogni/smk.git
        GIT_TAG        master
)

FetchContent_MakeAvailable(smk)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)
#
#FetchContent_Declare(
#        imgui
#        GIT_REPOSITORY https://github.com/ocornut/imgui
#        GIT_TAG 35b1148efb839381b84de9290d9caf0b66ad7d03
#)
#
#FetchContent_MakeAvailable(imgui)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

add_executable(RTS src/main.cpp src/test_runner.cpp src/test_runner.h src/game_entity.cpp src/game_entity.h src/game_unit.cpp src/game_unit.h src/unit_types.h src/drawable.cpp src/drawable.h)

target_link_libraries(RTS Catch2::Catch2 smk)
include(CTest)
include(Catch)
#catch_discover_tests()


file(COPY data DESTINATION . )
#configure_file(/data/* /data/* COPYONLY)



