#pragma once
# include <vector>
# include <Siv3D.hpp>

# include "Map.h"

class Piece
{
public:
	Piece();
	~Piece();
	//ブロックが落ちる処理
	void update(std::vector<std::vector<bool> > &map);
	//ブロックを表示
	void draw();

	//回転
	void rotate(std::vector<std::vector<bool> > &map);
	//移動
	void right(std::vector<std::vector<bool> > &map);
	void left(std::vector<std::vector<bool> > &map);
	void down(std::vector<std::vector<bool> > &map);

private:
	//初期化
	void init();
	//あたり判定のチェック
	bool check_collision(std::vector<std::vector<bool> > &map, int xx, int yy);
	//配置処理
	void put(std::vector<std::vector<bool> > &map);

	std::vector<std::vector<bool> > piece;
	int y, x;
	int timer;
};

