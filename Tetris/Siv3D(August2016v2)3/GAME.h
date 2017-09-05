#pragma once
#include <Siv3D.hpp>
#include "GAME.h"
#include "Map.h"
#include "Piece.h"

class Map;
class Piece;
class Game {
public:
	Game();
	void update();
	void game();
private:
	enum State {
		START,
		GAME,
		CLEAR,
		END,
	}state;
	Map map;
	Piece piece;
	int mino[4][4];
	int screen[20][10] = {0};
	int line_num;
};

void Main()
{
	Window::Resize(300, 600);
	Game games;
	while (System::Update()){
		games.update();
	}
}