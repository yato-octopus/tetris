#include "Game.h"



Game::Game()
{
	map = std::make_shared<Map>();
	piece = std::make_shared<Piece>();
}


Game::~Game()
{
}

void Game::update() {
	map->update();
	piece->update(map->map);
}

void Game::draw() {
	map->draw();
	piece->draw();
}