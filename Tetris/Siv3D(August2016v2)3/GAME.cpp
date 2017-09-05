#include <Siv3D.hpp>
#include "GAME.h"
#include "Map.h"
#include "Piece.h"

Game::Game() {
	state = GAME;
}
void Game::update() {
	static Font fontS(30);

	switch (state) {
	case State::START:
		fontS(L"てとりす").drawCenter(100 - fontS.ascent);
		fontS(L"すたーと").drawCenter(300, Palette::Yellow);
		break;
	case State::GAME:
		game();
		break;
	case State::CLEAR:
		fontS(L"げーむくりあー").drawCenter(200, Palette::Yellow);
		break;
	case State::END:
		fontS(L"げーむおーばー").drawCenter(200, Palette::Yellow);
		break;
	}
}

void Game::game() {
	piece.update(screen, mino);
	//ライン消滅処理
	line_num = map.check_line(screen);
	map.erase_line(screen, line_num);
	map.map_down(screen, line_num);
	//マップ状況表示
	map.draw_map(screen, mino);
	piece.draw_block(mino);
}

