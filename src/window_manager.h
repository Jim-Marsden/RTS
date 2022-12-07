//
// Created by Jim on 11/20/22.
//

#ifndef RTS_WINDOW_MANAGER_H
#define RTS_WINDOW_MANAGER_H


#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/String.hpp"

class window_manager {
public:
    window_manager() = default;
    ~window_manager() = default;
    window_manager(unsigned int x, unsigned int y, sf::String const &name = "default");
    bool do_events();
    void clear();
    void display();
    void draw(sf::RenderTexture & rt);
    void draw(sf::Drawable const & d, sf::RenderStates const & renderStates = sf::RenderStates::Default);

    explicit operator sf::RenderWindow&();

    sf::Vector2u get_size();



private:
    sf::RenderWindow window;
};


#endif //RTS_WINDOW_MANAGER_H
