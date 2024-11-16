#include "classes/game.hpp"
#include <iostream>

namespace game
{
Game::Game(): step(0) {}
Game::~Game(){}
bool Game::isActive(){ return step < 5; }
void Game::doStep(){ std::cout<< "Step: " << ++step << std::endl; }
}