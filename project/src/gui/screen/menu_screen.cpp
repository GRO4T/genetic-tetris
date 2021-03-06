/*
 * Author: Damian Kolaska
 */

#include "gui/screen/menu_screen.hpp"

#include <event_manager.hpp>

namespace genetic_tetris {

genetic_tetris::MenuScreen::MenuScreen(sf::RenderWindow& window) : Screen(window) {
    createPlayButton();
    createEvolveButton();
    createExitButton();
}

void genetic_tetris::MenuScreen::update() {
    play_button_.update();
    evolve_button_.update();
    exit_button_.update();
}

void genetic_tetris::MenuScreen::draw() {
    window_.clear(BG_COLOR);
    window_.draw(play_button_);
    window_.draw(evolve_button_);
    window_.draw(exit_button_);
    window_.display();
}

void genetic_tetris::MenuScreen::handleSfmlEvent(const sf::Event& event) {
    play_button_.handleEvent(event, window_);
    evolve_button_.handleEvent(event, window_);
    exit_button_.handleEvent(event, window_);
}

void genetic_tetris::MenuScreen::createPlayButton() {
    play_button_.setPosition(sf::Vector2f(300, 600));
    play_button_.setSize(sf::Vector2f(200, 50));
    play_button_.setText("PLAY", font_);
    play_button_.setOnClick(
        []() { EventManager::getInstance().addEvent(EventType::PLAY_BUTTON_CLICKED); });
}

void genetic_tetris::MenuScreen::createEvolveButton() {
    evolve_button_.setPosition(sf::Vector2f(300, 660));
    evolve_button_.setSize(sf::Vector2f(200, 50));
    evolve_button_.setText("EVOLVE", font_);
    evolve_button_.setOnClick(
        []() { EventManager::getInstance().addEvent(EventType::EVOLVE_BUTTON_CLICKED); });
}

void genetic_tetris::MenuScreen::createExitButton() {
    exit_button_.setPosition(sf::Vector2f(300, 720));
    exit_button_.setSize(sf::Vector2f(200, 50));
    exit_button_.setText("EXIT", font_);
    exit_button_.setOnClick(
        []() { EventManager::getInstance().addEvent(EventType::EXIT_BUTTON_CLICKED); });
}

}  // namespace genetic_tetris