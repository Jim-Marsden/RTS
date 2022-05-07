//
// Created by james on 4/30/2022.
//

#include "test_runner.h"
#define CATCH_CONFIG_RUNNER
#include "catch2/catch.hpp"

TEST_CASE("catch2 is working"){
    REQUIRE(true);
}

int rts::test_runner(int argc, char **argv) noexcept {
    return Catch::Session().run(argc, argv);
}
