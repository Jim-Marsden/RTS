//
// Created by Jim on 11/20/22.
//
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include "window_manager.h"
namespace sf{
    using Uint8 = unsigned char;
}
#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads

#include "imgui.h" // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h


#include <iostream>
window_manager::window_manager(unsigned int x, unsigned int y, sf::String const &name) :
window{sf::VideoMode({x, y}), name} {
    if (!ImGui::SFML::Init(window))
        throw std::runtime_error("Unable to initialise ImGui SFML");
}

bool window_manager::do_events() {
    auto result = window.isOpen();
    if (result){
        sf::Event event{};
        while(window.pollEvent(event)){
            ImGui::SFML::ProcessEvent(window, event);
            if(event.type == sf::Event::Closed){
                result = false;
                window.close();
            }
        }
        if (event.type == sf::Event::Resized)
        {
            const sf::View v{sf::Vector2f{static_cast<float>(event.size.width) / 2.0f,
                                          static_cast<float>(event.size.height) / 2.0f},
                             sf::Vector2f{static_cast<float>(event.size.width),
                                          static_cast<float>(event.size.height)}};
            window.setView(v);
        }
    }
    return result;
}

void window_manager::draw(sf::RenderTexture & rt) {
//    window.clear(sf::Color::Green);

    window.draw(sf::Sprite{rt.getTexture()});

//    window.display();
}

void window_manager::draw(sf::Drawable const & d,  sf::RenderStates const & renderStates ){
    window.draw(d, renderStates);
}

void window_manager::clear() {
    window.clear(sf::Color(0xff / 4, 0xff / 4, 0xff / 2));
}

void window_manager::display() {
    window.display();
}

sf::Vector2u window_manager::get_size() {
    return window.getSize();
}

window_manager::operator sf::RenderWindow&() {
    return window;
}
