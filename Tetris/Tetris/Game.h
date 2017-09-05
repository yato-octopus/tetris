#pragma once
# include <memory>
# include <Siv3D.hpp>

# include "Map.h"
# include "Piece.h"

class Game
{
public:
	Game();
	~Game();
	void update();
	void draw();
private:
	std::shared_ptr<Map> map;
	std::shared_ptr<Piece> piece;
};

