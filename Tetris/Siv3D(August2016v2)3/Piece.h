#pragma once

class Piece {
public : 

	void make_block(int (&mino)[4][4]);
	void spin_block(int (&screen)[20][10],int (&mino)[4][4]);
	void draw_block(int (&mino)[4][4]);
	bool check_block(int (&screen)[20][10],int (&mino)[4][4],int xx,int yy);
	bool check_spin(int (&screen)[20][10],int(&mino)[4][4]);
	bool put_block(int (&screen)[20][10], int (&mino)[4][4]);

	void down(int(&screen)[20][10], int(&mino)[4][4]);
	void left(int(&screen)[20][10], int(&mino)[4][4]);
	void right(int(&screen)[20][10], int(&mino)[4][4]);
	void update(int(&screen)[20][10], int(&mino)[4][4]);

private:
	int i = 1;
	int x ;
	int y ;
	int timer;
	struct blocks{
		int I_mino[4][4] = { 
			{ 0, 0, 0, 0 },
			{ 1, 1, 1, 1 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 } 
		};
		int O_mino[4][4] = {
			{ 0, 0, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		};
		int T_mino[4][4] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 1, 1, 1 },
			{ 0, 0, 0, 0 }
		};
		int J_mino[4][4] = {
			{ 0, 0, 1, 0},
			{ 0, 0, 1, 0},
			{ 0, 1, 1, 0},
			{ 0, 0, 0, 0}
		};
		int L_mino[4][4] = {
			{ 0, 1, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		};
		int S_mino[4][4] = {
			{ 0, 0, 0, 0 },
			{ 0, 0, 1, 1 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		};
		int Z_mino[4][4] = {
			{ 0, 0, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 1, 1, 0 },
			{ 0, 0, 0, 0 }
		};
	}block;
};