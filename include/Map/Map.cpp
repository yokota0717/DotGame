#include "DxLib.h"
#include "Map.h"
#include "../Resource/Resource.h"
#include "../GameEngine/GameEngine.h"

extern GameEngine* ge;

Map::Map(int w, int h, int x, int y):
	Object("Map"),
	width(w),
	height(h),
	xSize(x),
	ySize(y)
{}

bool Map::LoadPic(const string& path) {
	chip = ge->graFac->GetGraph(path.c_str());
	if (chip != -1) { return true; }
	return false;
}

//bool Map::LoadPic(const string& path, int all, int xNum, int yNum, int xSize, int ySize) {
//	chip = (int*)malloc(sizeof(int)*all);
//	LoadDivGraph(path.c_str(), all, xNum, yNum, xSize, ySize, chip);
//	if (*chip != -1) return true;
//	return false;
//}

bool Map::LoadData(const string& path, const char delimiter) {
	ifstream ifs(path);
	if (!ifs) { return false; }
	while (!ifs.eof()) {
		//1行読み込み
		string buf;
		ifs >> buf;
		//読み込んだ文字列を文字列ストリームに
		istringstream sbuf(buf);
		string token;					//1マス分のデータ保管用
		int d;
		while (getline(sbuf, token, delimiter)) {
			//文字列を数値に変換
			stringstream s;
			s << token;
			s >> d;
			//配列に保存
			data.push_back(d);
		}
	}
	return true;
}

void Map::update() {

}
void Map::updatePause() {

}
void Map::updateSleep() {

}
void Map::updateDestroy() {

}
void Map::render() {
	for (int i = 0; i < width*height; ++i) {
		DrawRectGraph(int(64 * (i%width) - ge->camera->pos.x), int(64 * (i / height) - ge->camera->pos.y) , 64 * (data[i] % 10), 64 * (data[i] / 5), 64, 64, chip, false, false);
	}
}
void Map::renderPause() {

}
void Map::renderSleep() {

}
void Map::renderDestroy() {

}

