#include "Piece.h"
#include <Siv3D.hpp>

void Piece::update(int(&screen)[20][10], int(&mino)[4][4]) {
	if (i) {
		make_block(mino);
		i--;
	}
	//���������ꂽ��s�[�X����]
	if (Input::KeyUp.clicked) {
		spin_block(screen,mino);
	}
	if (timer % 3 == 0) {
		//���������ꂽ�牺�Ɉړ�
		if (Input::KeyDown.pressed) {
			down(screen, mino);
		}
		//���������ꂽ��E�Ɉړ�
		if (Input::KeyRight.pressed) {
			right(screen, mino);
		}
		//���������ꂽ�獶�Ɉړ�
		if (Input::KeyLeft.pressed) {
			left(screen, mino);
		}
	}
	//��莞�Ԃŉ��Ɉړ�
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
	//�~�m����
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
	//�~�m���X�O�x��]
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
	//�~�m�̏�Ԃ�\��
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (mino[i][n]) {
				Rect((x + n) * 30 + 2, (y + i) * 30 + 2, 26, 26).draw(Palette::Aqua);
			}
		}
	}
}

bool Piece::check_block(int(&screen)[20][10], int (&mino)[4][4], int xx, int yy) {
	//�ړ������u���b�N�̔��f
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
	//�~�m�̏�Ԃ��}�b�v�ɑ��
	for (int i = 0; i < 4; i++) {
		for (int n = 0; n < 4; n++) {
			if (screen[i + y][n + x] == 0) {
				screen[i + y][n + x] = mino[i][n];
			}
		}
	}
	return true;
}
