#pragma once

# include <vector>
# include <Siv3D.hpp>

# define HEIGHT 20
# define WIDTH 10
# define BSIZE 20

class Map
{
public:
	Map();
	~Map();
	void update();
	void draw();

	std::vector<std::vector<bool> > map;
private:
	//
	void check_line();
	//下にシフト
	//下にシフトするだけで１列消したようになるため
	void shift(int y);
};

