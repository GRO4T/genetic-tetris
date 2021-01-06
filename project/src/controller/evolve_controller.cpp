#include "controller/evolve_controller.hpp"

#include <AI/evolutionary_strategy.hpp>
#include <tetris/tetris.hpp>

namespace gentetris {

EvolveController::EvolveController(Tetris& tetris_ai, EvolutionaryStrategy& ai, GUI& gui) : Controller(gui), tetris_ai_(tetris_ai), ai_(ai) {}

void EvolveController::update() {
    if (state_ == State::STOP) return;
    if (tetris_ai_.isFinished()) {
        tetris_ai_ = Tetris();
    }
    auto move = EvolutionaryStrategy::generateBestMove(ai_.getBest(), tetris_ai_);
    move.apply(tetris_ai_);
}

void EvolveController::handleCustomEvent(EventType e) {
    if (e == EventType::START_EVOLVE_BUTTON_CLICKED) {
        reset();
        start();
    } else if (e == EventType::SAVE_BUTTON_CLICKED) {
        ai_.save();
    }
}

void EvolveController::start() {
    ai_thread_ = std::thread([this]() { ai_(EvolutionaryStrategy::Mode::EVOLVE); });
    state_ = State::START;
}

void EvolveController::reset() {
    finish();
    tetris_ai_ = Tetris(true);
    state_ = State::STOP;
}

void EvolveController::finish() {
    ai_.finish();
    if (ai_thread_.joinable()) {
        ai_thread_.join();
    }
}

}  // namespace gentetris