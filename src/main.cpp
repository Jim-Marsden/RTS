#include "test_runner.h"

#include <iostream>
#include "smk/Shape.hpp"
#include "smk/Color.hpp"
#include <smk/Window.hpp>
#include <smk/Input.hpp>
#include <smk/Sprite.hpp>
#include <smk/RenderTarget.hpp>
smk::Sprite make_sprite(smk::Texture const & texture){

    smk::Sprite result(texture);
    result.SetCenter(16,16);
    result.SetPosition(128, 128);

    return result;
}

auto make_shape(){
    auto result = smk::Shape::RoundedRectangle(32, 32, 1);

//    result.SetScale(32, 32);
    result.SetCenter(16,16);
    result.SetPosition(128, 128);


    return result;
}

int main(int argc, char** argv) {
    auto window = smk::Window(640, 640, "smk/example/text");


    std::vector<smk::Transformable> recs;
    recs.resize(10000);

    smk::Texture const texture("./data/test1.png");


    for(auto & e : recs){ e = make_shape();}

    window.ExecuteMainLoop([&] {
        window.PoolEvents();
        window.Clear(smk::Color::Black);



        for(auto const & e : recs) window.Draw(e);
        if(window.input().IsKeyPressed(GLFW_KEY_F1)) {
            recs.emplace_back(make_sprite(texture));
            recs.back().SetPosition(window.input().mouse());
            std::cout << recs.size() << '\n';
        }

        if(window.input().IsKeyPressed(GLFW_KEY_F2)){

            if(!recs.empty()) recs.pop_back();
            std::cout << recs.size() << '\n';
        }
        window.Display();

        smk::View v;
        window.SetView(window.view());
    });
    // return result;
}
