//
// Created by james on 4/30/2022.
//

#ifndef RTS_DRAWABLE_H
#define RTS_DRAWABLE_H


template <class Drawable_T, class Entity_T>
class drawable {
    Drawable_T drawable_;
    Entity_T & active_Entity;

public:
    drawable(Drawable_T const & drawable, Entity_T & entity) : drawable_{drawable}, active_Entity{entity}{}
    explicit operator Drawable_T(){return drawable_;}
    explicit operator Drawable_T&(){return drawable_;}
};


#endif //RTS_DRAWABLE_H
