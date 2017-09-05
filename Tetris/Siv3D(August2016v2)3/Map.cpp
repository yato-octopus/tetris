#include "Map.h"
#include <Siv3D.hpp>

void Map::draw_map(int(&screen)[20][10],int (&mino)[4][4]) {

	//ゲーム画面表示
	for (int i = 0; i <= 20; i++) {
		Line(0, 30 * i, 300, 30 * i).draw(2, Palette::White);
	}
	for (int n = 0; n <= 10; n++) {
		Line(30 * n, 600, 30 * n, 0).draw(2, Palette::White);
	}
	//ミノの状態を表示
	for (int i = 0; i <= 20; i++) {
		for (int n = 0; n <= 10; n++) {
			switch (screen[i][n]) {
			case 0:
				Rect(2 + 30 * n, 2 + 30 * i, 26, 26).draw(Palette::Black);
				break;
			case 1:
				Rect(2 + 30 * n, 2 + 30 * i, 26, 26).draw(Palette::Red);
				break;
			}
		}
	}
}

int Map::check_line(int (&screen)[20][10]) {
	int check_line;

	for (int i = 0; i < 20; i++) {
		check_line = 0;
		for (int n = 0;n < 10; n++) {
			check_line += screen[i][n];
			if (check_line == 10) {
				return i;
			}
		}
	}
	return -1;
}
void Map::erase_line(int(&screen)[20][10],int line_num) {
	if (line_num != -1) {
		for (int n = 0; n < 10; n++) {
			screen[line_num][n] = 0;
		}
	}
	hoge = line_num;
}
void Map::map_down(int(&screen)[20][10], int line_num) {
	if (line_num != -1&&hoge>down_k) {
		for (int n = 0; n < 10; n++) {
			screen[line_num][n] = screen[line_num - 1][n];
		}
		down_k++;
		map_down(screen, line_num - 1);
	}
	down_k = 0;
}