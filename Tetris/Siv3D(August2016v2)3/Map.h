#pragma once

class Map {
public :
	void draw_map(int(&screen)[20][10],int (&mino)[4][4]);
	int check_line(int (&screen)[20][10]);
	void erase_line(int(&screen)[20][10],int i);
	void map_down(int(&screen)[20][10],int i);
private :
	int down_k = 0;
	int hoge;
	//int screen[20][10] = { 0 };
};