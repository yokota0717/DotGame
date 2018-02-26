#pragma once
#include "../Object/Object.h"
#include "../Figure/Vec.h"
#include "../Collision/Collision.h"
#include "../Move/Move.h"

#include <string>

class Player :public  Object {
public:
	InputMove* move;
	Collider* mapCol;
	int pic;
	std::string path;

	Player(const std::string& path);

	void LoadPic();

	void init();
	void update();
	void updatePause();
	void updateSleep();
	void updateDestroy();

	void render();
	void renderPause();
	void renderSleep();
	void renderDestroy();
};

