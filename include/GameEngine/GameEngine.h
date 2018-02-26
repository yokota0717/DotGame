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
		float	width,			//•`‰æ• 
				height;			//•`‰æ‚‚³
		Vec		pos;			//¶ãÀ•W
		Vec		target;			//‰æ–Ê’†S‚É‚Æ‚ç‚¦‚é‚à‚Ì
		float	angle;			//ŒX‚«
		float	zoom;			//Šg‘å—¦

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