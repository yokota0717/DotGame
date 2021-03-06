#include "Move.h"
#include "../GameEngine/GameEngine.h"

extern GameEngine* ge;

InputMove::InputMove(float x, float y, float s) :
	pos(Vec(x, y)),
	dir(0),
	speed(s)
{}

void InputMove::move() {
	int input = checkInput();
	//dir = checkInput();
	dir = input;
	Vec est;
	switch (dir) {
	case 0:
	default:
		est.Zero(); break;
	case 1:		//左
		est.x -= 1; break;
	case 2:		//上
		est.y -= 1; break;
	case 3:		//左上
		est.x -= 1; est.y -= 1; break;
	case 4:		//右
		est.x += 1; break;
	case 6:		//右上
		est.x += 1; est.y -= 1; break;
	case 8:		//下
		est.y += 1; break;
	case 9:		//左下
		est.x -= 1; est.y += 1; break;
	case 12:	//右下
		est.x += 1; est.y += 1; break;
	}
	est.Normalize();
	est *= speed;
	pos += est;
	dir = 0;
}

int InputMove::checkInput() {
	int input = 0;

	if (ge->keyboard.getKey(KEY_INPUT_LEFT) >= 1) {
		input += 1;
	}
	if (ge->keyboard.getKey(KEY_INPUT_UP) >= 1) {
		input += 2;
	}
	if (ge->keyboard.getKey(KEY_INPUT_RIGHT) >= 1) {
		input += 4;
	}
	if (ge->keyboard.getKey(KEY_INPUT_DOWN) >= 1) {
		input += 8;
	}

	return input;
}

bool InputMove::checkMove() {


	return false;
}