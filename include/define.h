#pragma once

namespace {
	const int SCREEN_WIDTH = 800,
		SCREEN_HEIGHT = 600;

	struct Rect {
		float left, top, right, bottom;
		Rect(float l, float t, float r, float b) :
			left(l),
			top(t),
			right(r),
			bottom(b)
		{}
	};

	//‰~Žü—¦
	const float PI = 3.14159265358979323846264338327950288f;

	int white = GetColor(255, 255, 255);
	int red = GetColor(255, 50, 50);
}