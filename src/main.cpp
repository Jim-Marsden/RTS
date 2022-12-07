//
// Created by Jim on 11/20/22.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <memory>
#include "window_manager.h"
#include "imgui.h" // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h

#include "imgui-SFML.h" // for ImGui::SFML::* functions and SFML-specific overloads

auto generate_random_number(float range){
    static std::random_device rd;
    sf::RenderTexture rt;
    std::uniform_int_distribution<float> dist({}, range);
    return dist(rd);
}

int main() try {
    auto up = std::make_unique<int>();
    std::random_device rd;
    sf::RenderTexture rt;

    sf::Vector3 target_color{1.0f,0.0f,1.0f};
    window_manager window(120, 120, "text");


    sf::Texture texture;
    sf::Shader test;
    if(not test.loadFromFile("data/shaders/outline_test.frag", sf::Shader::Type::Fragment))
        std::cerr << "inavlid shader :c\n";


    if(not rt.create(window.get_size()))
        throw std::runtime_error("rt.create failed to create");
    if(not texture.loadFromFile("data/test1.png"))
        throw std::runtime_error("texture.loadFromFile failed to load from file"); // lol
    sf::Sprite sprite(texture);

    sf::Sprite sprite2(texture);
    sprite.setOrigin({sprite.getScale().x / 2, sprite.getScale().y / 2});
    sprite2.move({64, 64});
    sprite2.setOrigin({sprite2.getScale().x / 2, sprite2.getScale().y / 2});
    test.setUniform("selected_color", target_color);
    test.setUniform("outline_scale", 0.01f);

    sf::Clock deltaClock{};

    bool bool_thing{};


    while(window.do_events()){



        window.clear();
        ImGui::SFML::Update(static_cast<sf::RenderWindow&>(window), deltaClock.restart());


        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();
        rt.clear(sf::Color::Yellow);
        window.draw(sprite, sf::RenderStates(&test));

        sprite2.setPosition({generate_random_number(window.get_size().x),
                             generate_random_number(window.get_size().y)});
        sprite2.getGlobalBounds();
        ImGui::Render();
        window.draw(sprite2, sf::RenderStates(&test));
        window.display();
    }
    return 0;
}
catch (std::exception &e) {
    std::cout << "an exception\n";
}