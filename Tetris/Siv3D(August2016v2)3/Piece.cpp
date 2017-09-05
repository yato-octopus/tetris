#include "Piece.h"
#include <Siv3D.hpp>

void Piece::update(int(&screen)[20][10], int(&mino)[4][4]) {
	if (i) {
		make_block(mino);
		i--;
	}
	//↑が押されたらピースを回転
	if (Input::KeyUp.clicked) {
		spin_block(screen,mino);
	}
	if (timer % 3 == 0) {
		//↓が押されたら下に移動
		if (Input::KeyDown.pressed) {
			down(screen, mino);
		}
		//→が押されたら右に移動
		if (Input::KeyRight.pressed) {
			right(screen, mino);
		}
		//←が押されたら左に移動
		if (Input::KeyLeft.pressed) {
			left(screen, mino);
		}
	}
	//一定時間で下に移動
	timer++;
	if (timer % 50 == 0) {
		if (check_block(screen, mino, x, y + 1)) {
			put_block(screen, mino);
			make_block(mino);
		}
		else {
			y++;
		}
	}

}

void Piece::make_block(int (&mino)[4][4]) {
	int random = Random(0, 6);
	x = 3;
	y = 0;
	timer = 1;
	//ミノ生成
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			switch (random) {
			case 0:
				mino[i][n] = block.I_mino[i][n];
				break;
			case 1:
				mino[i][n] = block.O_mino[i][n];
				break;
			case 2:
				mino[i][n] = block.T_mino[i][n];
				break;
			case 3:
				mino[i][n] = block.J_mino[i][n];
				break;
			case 4:
				mino[i][n] = block.L_mino[i][n];
				break;
			case 5:
				mino[i][n] = block.S_mino[i][n];
				break;
			case 6:
				mino[i][n] = block.Z_mino[i][n];
				break;
			}
		}
	}
}

bool Piece::check_spin(int (&screen)[20][10],int(&mino)[4][4]) {
	int hoge[4][4];
	int mino90[4][4];

	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			hoge[i][n] = mino[4][4];
		}
	}
		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {
				hoge[n][3 - i] = mino[i][n];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {
				mino90[i][n] = hoge[i][n];
			}
		}

	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (x + n< 0 || x + n >= 10) {
				if (x + n>= 10 || x + n< 0) {
					return true;
				}
			}
			
		}
	}
	return false;
}

void Piece::spin_block(int (&screen)[20][10],int (&mino)[4][4]) {
	//ミノを９０度回転
	int mino90[4][4];

	if (check_spin(screen,mino) == false) {
		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {
				mino90[n][3 - i] = mino[i][n];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int n = 0; n < 4; n++) {
				mino[i][n] = mino90[i][n];
			}
		}
	}
}

void Piece::draw_block(int(&mino)[4][4]) {
	//ミノの状態を表示
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (mino[i][n]) {
				Rect((x + n) * 30 + 2, (y + i) * 30 + 2, 26, 26).draw(Palette::Aqua);
			}
		}
	}
}

bool Piece::check_block(int(&screen)[20][10], int (&mino)[4][4], int xx, int yy) {
	//移動したブロックの判断
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (mino[i][n]) {
				if (xx + n < 0 || xx + n >= 10 || yy + i >= 20 || yy+i < 0) {
					return true;
				}
				if (screen[i + yy][n + xx]) {
					return true;
				}
			}
		}
	}
	return false;
}

void Piece::down(int(&screen)[20][10], int(&mino)[4][4]) {
	if (check_block(screen,mino, x, y + 1) == false) {
		y++;
	}
	else {
		put_block(screen,mino);
		make_block(mino);
	}
}

void Piece::left(int(&screen)[20][10], int(&mino)[4][4]) {
	if (check_block(screen, mino, x - 1, y) == false) {
		x--;
	}
}

void Piece::right(int(&screen)[20][10], int(&mino)[4][4]) {
	if (check_block(screen, mino, x + 1, y) == false) {
		x++;
	}
}

bool Piece::put_block(int(&screen)[20][10], int(&mino)[4][4]) {
	//ミノの状態をマップに代入
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (screen[i + y][n + x] == 0) {
				screen[i + y][n + x] = mino[i][n];
			}
		}
	}
	return true;
}
