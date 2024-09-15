#ifndef _SWORD_H_
#define _SWORD_H_

#include "animation.h"
#include "collision_box.h"


class Sword {
public:
	Sword(const Vector2& position, bool move_left);
	~Sword();

	void on_update(float delta);
	void on_render();

	bool check_valid()const {
		return is_valid;
	}


private:
	const float SPEED_MOVE = 1250.0f;

private:
	Vector2 position;
	Vector2 velocity;
	Animation animation;
	bool is_valid = true;
	CollisionBox* collision_box = nullptr;

};


#endif // !_SWORD_H_
