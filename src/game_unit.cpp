//
// Created by james on 4/30/2022.
//

#include "game_unit.h"
#include "unit_types.h"


#include "catch2/catch.hpp"

struct test_pos{
    int x, y;
};

TEST_CASE("Simple Construction", "game_unit"){
    //template <class Name_T, class Position_T, class Size_T, class Pathfinding_T, Pathfinding_T pathfinding_id, class Movement_Speed_T>
    rts::game_unit<const char*, test_pos, test_pos, rts::path_finding_type, rts::path_finding_type::None, float> obj;
    REQUIRE(true);
    REQUIRE(obj.pathfinding_id == rts::path_finding_type::None);
}