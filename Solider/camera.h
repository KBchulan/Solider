#ifndef _CAMERA_H_
#define _CAMERA_H_

#include"vector2.h"
#include"timer.h"

class Camera {
public:
	Camera() {
		timer_shake.set_wait_time(0.05f);
		timer_shake.set_one_shot(true);
		timer_shake.set_on_timeout([&]() {
			is_shaking = false;
			reset();
			});
	}
	~Camera() = default;

	const Vector2& get_position()const {
		return position;
	}

	void shake(float strength, int duration) {
		is_shaking = true;
		shaking_strlength = strength;

		timer_shake.set_wait_time(duration);
		timer_shake.restart();
	}

	void reset() {
		position.x = 0;
		position.y = 0;
	}

	void on_update(int delta) {
		timer_shake.on_update(delta);
		if (is_shaking) {
			position.x = (-50 + rand() % 100) / 50.0f * shaking_strlength;
			//position.y = (-50 + rand() % 100) / 50.0f * shaking_strlength;
		}
	}


	bool get_is_shaking()const {
		return is_shaking;
	}

private:
	Vector2 position;
	Timer timer_shake;
	bool is_shaking = false;
	float shaking_strlength = 0;

};


#endif // !_CAMERA_H_