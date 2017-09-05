#include "Map.h"



Map::Map()
{
	map.resize(20);
	for (int i = 0; i < 20; i++) {
		map[i].resize(10);
	}
}


Map::~Map()
{
}

void Map::update() {
	check_line();
}

void Map::check_line() {
	for (int y = HEIGHT - 1; y >= 0; y--) {
		int x;
		for (x = 0; x < WIDTH; x++) {
			if (map[y][x] == false) {
				break;
			}
		}
		if (x == 10) {
			shift(y);
		}
	}
}

void Map::shift(int yy) {
	for (int y = yy; y > 0; y--) {
		for (int x = 0; x < WIDTH; x++) {
			map[y][x] = map[y - 1][x];
		}
	}
}

void Map::draw() {
	//draw line
	Line(109, 20, 109, 20 + BSIZE*HEIGHT).draw();
	Line(110 + BSIZE*WIDTH, 20, 110 + BSIZE*WIDTH, 20 + BSIZE*HEIGHT).draw();
	Line(109, 20 + BSIZE*HEIGHT, 110 + BSIZE*WIDTH, 20 + BSIZE*HEIGHT).draw();

	//draw block
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (map[y][x]) {
				Rect(110 + BSIZE*x, 20 + BSIZE*y, 19, 19).draw({ Palette::Green, 200 });
			}
		}
	}
}