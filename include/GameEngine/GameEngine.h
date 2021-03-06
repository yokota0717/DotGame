#pragma once
#include "../Input/Input.h"
#include "../Figure/Vec.h"
#include "../Map/Map.h"
#include "../Resource/Resource.h"
#include "../Actor/Actor.h"

class GameEngine {
public:
	GameEngine();


	class Camera {
	public:
		float	width,			//描画幅 
				height;			//描画高さ
		Vec		pos;			//左上座標
		Vec		target;			//画面中心にとらえるもの
		float	angle;			//傾き
		float	zoom;			//拡大率

		Camera();
		void setPos(float, float);
		void setTarget(float, float);
		void setSize(float, float);
		void setAngle(float);
		void setZoom(float);

		void adjastPos();
	};
	Camera* camera;
	Keyboard keyboard;
	GPad* p1;
	GraphFactory* graFac;

	Object* root;

	Map* center;

	Player* player;

	bool debug;

	bool init();
	void update();
	void render();
};
extern GameEngine* ge;