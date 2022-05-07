//
// Created by james on 4/30/2022.
//

#ifndef RTS_GAME_UNIT_H
#define RTS_GAME_UNIT_H

#include "game_entity.h"
#include <vector>
namespace rts {
    template <class Name_T, class Position_T, class Size_T, class Pathfinding_T, Pathfinding_T Pathfinding_id, class Movement_Speed_T>
    struct game_unit : public rts::game_entity<Name_T, Position_T, Size_T> {
        Movement_Speed_T speed;
        std::vector<Position_T> Waypoints;
        const Pathfinding_T pathfinding_id{Pathfinding_id};
    };
}

#endif //RTS_GAME_UNIT_H
