#include "Piece.h"



Piece::Piece()
{
	init();
}


Piece::~Piece()
{
}

void Piece::update(std::vector<std::vector<bool> > &map) {
	//↑が押されたらピースを回転
	if (Input::KeyUp.clicked) {
		rotate(map);
	}
	//↓が押されたら下に移動
	if (Input::KeyDown.clicked) {
		down(map);
	}
	//→が押されたら右に移動
	if (Input::KeyRight.clicked) {
		right(map);
	}
	//←が押されたら左に移動
	if (Input::KeyLeft.clicked) {
		left(map);
	}

	timer++;
	if (timer%50 == 0) {
		if (check_collision(map, x, y + 1)) {
			put(map);
			init();
		}
		else {
			y++;
		}
	}
}

void Piece::draw() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (piece[i][j]) {
				Rect(110 + (x + j) * BSIZE, 20 + (y + i) * BSIZE, BSIZE - 1, BSIZE - 1).draw({ Palette::Aqua, 80 });
			}
		}
	}
}

void Piece::put(std::vector<std::vector<bool> > &map) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (x + j >= 0 && x + j < WIDTH && y + i < HEIGHT && piece[i][j]) {
				map[i + y][j + x] = piece[i][j];
			}
		}
	}
}

void Piece::right(std::vector<std::vector<bool> > &map) {
	if (check_collision(map, x + 1, y) == false) {
		x++;
	}
}

void Piece::left(std::vector<std::vector<bool> > &map) {
	if (check_collision(map, x - 1, y) == false) {
		x--;
	}
}

void Piece::down(std::vector<std::vector<bool> > &map) {
	if (check_collision(map, x, y + 1) == false) {
		y++;
	}
	else {
		put(map);
		init();
	}
}

void Piece::rotate(std::vector<std::vector<bool> > &map) {
	std::vector<std::vector<bool> > t(4, std::vector<bool>(4));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			t[j][3 - i] = piece[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			piece[i][j] = t[i][j];
		}
	}
}

bool Piece::check_collision(std::vector<std::vector<bool> > &map, int xx, int yy) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (piece[i][j]) {
				//枠とのあたり判定
				if (xx + j < 0 || xx + j >= WIDTH || yy + i >= HEIGHT) {
					return true;
				}
				//マップにあるピースとのあたり判定
				if (map[i + yy][j + xx]) {
					return true;
				}
			}
		}
	}

	return false;
}


void Piece::init() {
	static std::vector<std::vector<std::vector<bool> > > pieces(6, std::vector<std::vector<bool> >(4, std::vector<bool>(4)));
	x = 3;
	y = 4;

	//棒
	pieces[0][1][0] = true;
	pieces[0][1][1] = true;
	pieces[0][1][2] = true;
	pieces[0][1][3] = true;

	//L
	pieces[1][0][0] = true;
	pieces[1][1][0] = true;
	pieces[1][2][0] = true;
	pieces[1][2][1] = true;

	//四角
	pieces[2][1][1] = true;
	pieces[2][1][2] = true;
	pieces[2][2][1] = true;
	pieces[2][2][2] = true;

	piece = pieces[Random(0, 2)];
}
