//
// Created by james on 4/30/2022.
//

#ifndef RTS_GAME_ENTITY_H
#define RTS_GAME_ENTITY_H

namespace rts {
    template <class Name_T, class Position_T, class Size_T>
    struct game_entity {
        Name_T name;
        signed short health; // should define a max in bits?
        Position_T position;
        Size_T size;
    };
}

#endif //RTS_GAME_ENTITY_H
