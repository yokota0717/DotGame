#pragma once
#include "../Object/Object.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Map: public Object {
public:
	int width, height;		//マップ全体の大きさ(マス数)
	int xSize, ySize;		//１マスの大きさ
	int chip;				//マップチップ
	vector<int> data;		//配置データ

	Map(int w, int h, int xSize = 64, int ySize = 64);
	bool LoadPic(const string& path);
	//bool LoadPic(const string& path, int allNum, int xNum, int yNum, int xSize = 64, int ySize = 64);
	bool LoadData(const string& path, const char delimiter = ',');
	
	void update();
	void updatePause();
	void updateSleep();
	void updateDestroy();

	void render();
	void renderPause();
	void renderSleep();
	void renderDestroy();
};
