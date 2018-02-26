#include "GameEngine.h"
#include "../define.h"
#include "../Input/Input.h"

GameEngine* ge = new GameEngine();

//----------------------------------------------------------------------------
//カメラ関連
//----------------------------------------------------------------------------
GameEngine::Camera::Camera() :
	width((float)SCREEN_WIDTH),
	height((float)SCREEN_HEIGHT),
	pos(Vec(-width / 2, -height / 2.0f)),
	target(Vec(0.0f,0.0f)),
	angle(0.0f),
	zoom(0.0f)
{}
//----------------------------------------------------------------------------
void GameEngine::Camera::setPos(float x, float y) {
	pos.x = x;
	pos.y = y;
}
//----------------------------------------------------------------------------
void GameEngine::Camera::setTarget(float x, float y) {
	target.x = x;
	target.y = y;
	//ターゲット座標からカメラの左上座標を求める
	float cx = target.x - SCREEN_WIDTH / 2;
	float cy = target.y - SCREEN_HEIGHT / 2;
	pos.x = cx;
	pos.y = cy;
}
//----------------------------------------------------------------------------
void GameEngine::Camera::setSize(float w, float h) {
	width = w;
	height = h;
}
//----------------------------------------------------------------------------
void GameEngine::Camera::setAngle(float a) {
	angle = a;
}
//----------------------------------------------------------------------------
void GameEngine::Camera::setZoom(float z) {
	zoom = z;
}
//----------------------------------------------------------------------------
void GameEngine::Camera::adjastPos() {
	Rect camera(pos.x, pos.y, pos.x + width, pos.y + height);
	Rect map(0, 0, float(ge->center->width*ge->center->xSize), float(ge->center->height*ge->center->ySize));

	if (camera.right > map.right) { ge->camera->pos.x = map.right - ge->camera->width; }
	if (camera.bottom > map.bottom) { ge->camera->pos.y = map.bottom - ge->camera->height; }
	if (camera.left < map.left) { ge->camera->pos.x = map.left; }
	if (camera.top < map.top) { ge->camera->pos.y = map.top; }
}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//★★★GameEngine★★★
//----------------------------------------------------------------------------
GameEngine::GameEngine():
	camera(new Camera()),
	p1(new GPad(1)),
	graFac(new GraphFactory()),
	root(new Object("Root")),
	center(new Map(30, 30)),
	player(new Player("./resource/graph/player.png")),
	debug(false)
{}

bool GameEngine::init(){
	center->LoadPic("./resource/graph/test.bmp");
	center->LoadData("./resource/map/test2.csv");
	player->init();

	root->insertAsChild(center);
	root->insertAsChild(player);
	return true;
}

void GameEngine::update() {
	keyboard.update();
	camera->setTarget(player->move->pos.x, player->move->pos.y);
	camera->adjastPos();

	root->updateWithChildren();
	//center->update();


	if (keyboard.getKey(KEY_INPUT_Z) == 1) {
		debug = !debug;
	}
}

void GameEngine::render() {
	//player->render();
	root->renderWithChildren();


	//center->render();
}