#include "Actor.h"
#include "DxLib.h"
#include "../GameEngine/GameEngine.h"
#include "../define.h"

extern GameEngine* ge;

Player::Player(const std::string& path) :
	Object("Player"),
	move(new InputMove(32, 32, 5)),
	mapCol(new Box2DCollider(10, 32, 49, 32)),
	path(path)
{}

void Player::LoadPic() {
	pic = ge->graFac->GetGraph(path.c_str());
}

void Player::init() { 
	LoadPic();
}
void Player::update(){
	move->move();
}
void Player::updatePause(){}
void Player::updateSleep(){}
void Player::updateDestroy(){}

void Player::render(){
	int rectx = int(-32 + move->pos.x - ge->camera->pos.x);
	int recty = int(-32 + move->pos.y - ge->camera->pos.y);
	DrawRectGraph(/*int(-32 + move->pos.x - ge->camera->pos.x) , int(-32 + move->pos.y - ge->camera->pos.y)*/
					rectx,recty, 0, 0, 64, 64, pic, true, false);



	if (ge->debug) {
		DrawBox(rectx+10, recty+ 32, rectx+ 49, recty + 64, red, false);
		DrawFormatString(0, 0, red, "x:%d\ny:%d", move->pos.x, move->pos.y);
		DrawFormatString(0, 40, red, "%d", move->dir);
	}
	
}
void Player::renderPause(){}
void Player::renderSleep(){}
void Player::renderDestroy(){}
