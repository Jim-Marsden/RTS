//
// Created by james on 4/30/2022.
//

#ifndef RTS_UNIT_TYPES_H
#define RTS_UNIT_TYPES_H
namespace rts{
    namespace enum_constants{
        constexpr auto unknown{-0xff};
    }
    enum struct path_finding_type{
        None = enum_constants::unknown,
        Land = 0,
        Sea,
        Air,
    };
}
#endif //RTS_UNIT_TYPES_H
