#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "vector2.h"
#include "animation.h"
#include "collision_box.h"
#include "state_machine.h"

#include <string>
#include <easyx.h>
#include <unordered_map>

class Character {
public:
	Character();
	~Character();

	void decrease_hp();

	int get_hp()const {
		return hp;
	}

	void set_position(const Vector2& pos) {
		this->position = pos;
	}

	const Vector2& get_position()const {
		return position;
	}

	void set_velocity(const Vector2& vel) {
		this->velocity = vel;
	}

	const Vector2& get_velocity()const {
		return velocity;
	}

	Vector2 get_logic_center()const {
		return Vector2(position.x, position.y - logic_height / 2);
	}

	void set_gravity_enabled(bool enable) {
		enable_gravity = enable;
	}

	CollisionBox* get_hit_box() {
		return hit_box;
	}

	CollisionBox* get_hurt_box() {
		return hurt_box;
	}

	bool is_on_floor()const {
		return position.y >= FLOOR_Y;
	}

	float get_floor_y()const {
		return FLOOR_Y;
	}

	void make_invulnerable() {
		is_invulnerable = true;
		timer_invulnerable_status.restart();
	}

	virtual void on_input(const ExMessage& msg);
	virtual void on_update(float delta);
	virtual void on_render();

	virtual void on_hurt();

	void switch_state(const std::string& id);
	void set_animation(const std::string& id);

protected:
	struct AnimationGroup {
		Animation left;
		Animation right;
	};

protected:
	const float FLOOR_Y = 620;				//地板的竖直方向坐标
	const float GRAVITY = 980 * 2;			//重力加速度

protected:
	int hp = 10;														//血量
	Vector2 position;													//角色脚底位置
	Vector2 velocity;													//角色速度
	float logic_height = 0;												//角色逻辑高度
	bool is_facing_left = true;											//角色是否面朝左边
	StateMachine state_machine;											//状态机
	bool enable_gravity = true;											//是否启用重力
	bool is_invulnerable = false;										//是否无敌
	Timer timer_invulnerable_blink;										//无敌闪烁计时器
	Timer timer_invulnerable_status;									//无敌状态计时器
	bool is_blink_invisable = false;									//是否无敌闪烁不可见
	CollisionBox* hit_box = nullptr;									//攻击碰撞盒
	CollisionBox* hurt_box = nullptr;									//受伤碰撞盒
	AnimationGroup* current_animation = nullptr;						//当前动画组
	std::unordered_map<std::string, AnimationGroup> animation_pool;		//动画组池


};


#endif // !_CHARACTER_H_
