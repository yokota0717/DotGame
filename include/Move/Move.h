#pragma once
#include "../Figure/Vec.h"

class InputMove {
public:
	Vec pos;
	int dir;
	float speed;

	InputMove(float x, float y, float s);

	void move();
	int checkInput();
	bool checkMove();
};

#define _USE_MATH_DEFINES
#include <math.h>
class Easing
{
private:
	float cnt;
public:

	Easing() :
		cnt(0)
	{};
	float Time(float duration) {
		if (cnt <= duration) {
			cnt += 0.1f;
		}
		return cnt;
	}
	void reset() {
		cnt = 0;
	}

	//Linear
	float Linear(float time, float start, float diff, float elapsed)
	{
		return diff*time / elapsed + start;
	}

	//Back
	float BackIn(float time, float start, float diff, float elapsed)
	{
		float s = 1.70158f;
		float postFix = time /= elapsed;
		return diff*(postFix)*time*((s + 1)*time - s) + start;
	}
	float BackOut(float time, float start, float diff, float elapsed)
	{

		float s = 1.70158f;

		return diff*((time = time / elapsed - 1)*time*((s + 1)*time + s) + 1) + start;
	}
	float BackInOut(float time, float start, float diff, float elapsed)
	{
		float s = 1.70158f;
		if ((time /= elapsed / 2) < 1) return diff / 2 * (time*time*(((s *= (1.525f)) + 1)*time - s)) + start;
		float postFix = time -= 2;
		return diff / 2 * ((postFix)*time*(((s *= (1.525f)) + 1)*time + s) + 2) + start;
	}

	//Bounce
	float BounceOut(float time, float start, float diff, float elapsed)
	{

		if ((time /= elapsed) < (1 / 2.75f))
		{
			return diff*(7.5625f*time*time) + start;
		}
		else if (time < (2 / 2.75f))
		{
			float postFix = time -= (1.5f / 2.75f);
			return diff*(7.5625f*(postFix)*time + .75f) + start;
		}
		else if (time < (2.5 / 2.75))
		{
			float postFix = time -= (2.25f / 2.75f);
			return diff*(7.5625f*(postFix)*time + .9375f) + start;
		}
		else
		{
			float postFix = time -= (2.625f / 2.75f);
			return diff*(7.5625f*(postFix)*time + .984375f) + start;
		}
	}
	float BounceIn(float time, float start, float diff, float elapsed)
	{
		return diff - BounceOut(elapsed - time, 0, diff, elapsed) + start;
	}
	float BounceInOut(float time, float start, float diff, float elapsed)
	{
		if (time < elapsed / 2) return BounceIn(time * 2, 0, diff, elapsed) * .5f + start;
		else return BounceOut(time * 2 - elapsed, 0, diff, elapsed) * .5f + diff*.5f + start;
	}

	//Circ
	float CircIn(float time, float b, float c, float d)	//ƒoƒO‚ ‚è
	{
		return -c * ((float)sqrt(1 - (time /= d)*time) - 1) + b;
	}
	float CircOut(float time, float b, float c, float d)
	{
		return c * (float)sqrt(1 - (time = time / d - 1)*time) + b;
	}
	float CircInOut(float time, float b, float c, float d)
	{
		if ((time /= d / 2) < 1) return -c / 2 * ((float)sqrt(1 - time*time) - 1) + b;
		return c / 2 * (float)(sqrt(1 - time*(time -= 2)) + 1) + b;
	}

	//Cubic
	float CubicIn(float time, float start, float diff, float elapsed)
	{
		return diff*(time /= elapsed)*time*time + start;
	}
	float CubicOut(float time, float start, float diff, float elapsed)
	{
		return diff*((time = time / elapsed - 1)*time*time + 1) + start;
	}
	float CubicInOut(float time, float start, float diff, float elapsed)
	{
		if ((time /= elapsed / 2) < 1) return diff / 2 * time*time*time + start;
		return diff / 2 * ((time -= 2)*time*time + 2) + start;
	}

	//Elastic
	float ElasticIn(float time, float start, float diff, float elapsed)
	{
		if (time == 0) return start;  if ((time /= elapsed) == 1) return start + diff;
		float p = elapsed*.3f;
		float a = diff;
		float s = p / 4;
		float postFix = static_cast<float>(a*pow(2, 10 * (time -= 1)));
		return -(postFix * (float)sin((time*elapsed - s)*(2 * static_cast<float>(M_PI)) / p)) + start;
	}

	float ElasticOut(float time, float start, float diff, float elapsed)
	{
		if (time == 0) return start;  if ((time /= elapsed) == 1) return start + diff;
		float p = elapsed*.3f;
		float a = diff;
		float s = p / 4;
		return (static_cast<float>(a*powf(2, -10 * time) * sin((time*elapsed - s)*(2 * static_cast<float>(M_PI)) / p) + diff + start));
	}

	float ElasticInOut(float time, float start, float diff, float elapsed)
	{
		if (time == 0) return start;  if ((time /= elapsed / 2) == 2) return start + diff;
		float p = elapsed*(.3f*1.5f);
		float a = diff;
		float s = p / 4;

		if (time < 1) {
			float postFix = static_cast<float>(a*pow(2, 10 * (time -= 1)));
			return -.5f*(postFix* (float)sin((time*elapsed - s)*(2 * static_cast<float>(M_PI)) / p)) + start;
		}
		float postFix = static_cast<float>(a*pow(2, -10 * (time -= 1)));
		return static_cast<float>(postFix * (float)sin((time*elapsed - s)*(2 * static_cast<float>(M_PI)) / p)*.5f + diff + start);
	}

	//Expo
	float ExpoIn(float time, float start, float diff, float elapsed)
	{
		return (time == 0) ? start : diff * static_cast<float>(powf(2, 10 * (time / elapsed - 1)) + start);
	}
	float ExpoOut(float time, float start, float diff, float elapsed)
	{
		return (time == elapsed) ? start + diff : diff * (static_cast<float>(-powf(2, -10 * time / elapsed) + 1)) + start;
	}

	float ExpoInOut(float time, float start, float diff, float elapsed)
	{
		if (time == 0) return start;
		if (time == elapsed) return start + diff;
		if ((time /= elapsed / 2) < 1) return diff / 2 * static_cast<float>(powf(2, 10 * (time - 1))) + start;
		return diff / 2 * (-powf(2, -10 * --time) + 2) + start;
	}

	//Quad
	float QuadIn(float time, float start, float diff, float elapsed)
	{
		return diff*(time /= elapsed)*time + start;
	}
	float QuadOut(float time, float start, float diff, float elapsed)
	{
		return -diff *(time /= elapsed)*(time - 2) + start;
	}
	float QuadInOut(float time, float start, float diff, float elapsed)
	{
		if ((time /= elapsed / 2) < 1) return ((diff / 2)*(time*time)) + start;
		return -diff / 2 * (((time - 2)*(--time)) - 1) + start;
	}

	//Quart
	float QuartIn(float time, float start, float diff, float elapsed)
	{
		return diff*(time /= elapsed)*time*time*time + start;
	}
	float QuartOut(float time, float start, float diff, float elapsed)
	{
		return -diff * ((time = time / elapsed - 1)*time*time*time - 1) + start;
	}
	float QuartInOut(float time, float start, float diff, float elapsed)
	{
		if ((time /= elapsed / 2) < 1) return diff / 2 * time*time*time*time + start;
		return -diff / 2 * ((time -= 2)*time*time*time - 2) + start;
	}

	//Quint
	float QuintIn(float time, float start, float diff, float elapsed)
	{
		return diff*(time /= elapsed)*time*time*time*time + start;
	}
	float QuintOut(float time, float start, float diff, float elapsed)
	{
		return diff*((time = time / elapsed - 1)*time*time*time*time + 1) + start;
	}

	float QuintInOut(float time, float start, float diff, float elapsed)
	{
		if ((time /= elapsed / 2) < 1) return diff / 2 * time*time*time*time*time + start;
		return diff / 2 * ((time -= 2)*time*time*time*time + 2) + start;
	}

	//Sine
	float SineIn(float time, float start, float diff, float elapsed)
	{
		return -diff * static_cast<float>((float)cos(time / elapsed * (M_PI / 2))) + diff + start;
	}
	float SineOut(float time, float start, float diff, float elapsed)
	{
		return diff * static_cast<float>((float)sin(time / elapsed * (M_PI / 2))) + start;
	}

	float SineInOut(float time, float start, float diff, float elapsed)
	{
		return -diff / 2 * static_cast<float>(((float)cos(M_PI*time / elapsed) - 1)) + start;
	}
};