#include <SFML/Graphics.hpp>

#include "SceneWindow.hpp"
#include "../../../../game/src/storage/Variables.h"

SceneWindow::SceneWindow(cv::Size resolution_projector, const bool &fullscreen_projector) {
    this->window_scene = new sf::RenderWindow(
            sf::VideoMode(
                    resolution_projector.width,
                    resolution_projector.height
            ),
            "Projector",
            fullscreen_projector
            ? sf::Style::Fullscreen
            : sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close
    );
    this->window_scene->clear(sf::Color::White);
    this->window_scene->display();
    this->window_scene->setFramerateLimit(Variables::FRAMERATE_LIMIT);
}

void SceneWindow::drawScene(Scene *scene) {
    this->window_scene->clear(sf::Color::White);
    scene->draw(*this->window_scene);

    this->window_scene->display();
}

bool SceneWindow::shouldKeepOpen() {
    bool open = true;
    sf::Event event;
    while (this->window_scene->pollEvent(event)) {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)) {
            open = false;
        }
    }
    if (!open) {
        //window_scene->close();
    }
    return open;
}
