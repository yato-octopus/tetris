#pragma once
# include <vector>
# include <Siv3D.hpp>

# include "Map.h"

class Piece
{
public:
	Piece();
	~Piece();
	//�u���b�N�������鏈��
	void update(std::vector<std::vector<bool> > &map);
	//�u���b�N��\��
	void draw();

	//��]
	void rotate(std::vector<std::vector<bool> > &map);
	//�ړ�
	void right(std::vector<std::vector<bool> > &map);
	void left(std::vector<std::vector<bool> > &map);
	void down(std::vector<std::vector<bool> > &map);

private:
	//������
	void init();
	//�����蔻��̃`�F�b�N
	bool check_collision(std::vector<std::vector<bool> > &map, int xx, int yy);
	//�z�u����
	void put(std::vector<std::vector<bool> > &map);

	std::vector<std::vector<bool> > piece;
	int y, x;
	int timer;
};

