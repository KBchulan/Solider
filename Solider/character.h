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

	void set_hp(int hp) {
		this->hp = hp;
	}

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
	const float FLOOR_Y = 620;				//�ذ����ֱ��������
	const float GRAVITY = 980 * 2;			//�������ٶ�

protected:
	int hp = 10;														//Ѫ��
	Vector2 position;													//��ɫ�ŵ�λ��
	Vector2 velocity;													//��ɫ�ٶ�
	float logic_height = 0;												//��ɫ�߼��߶�
	bool is_facing_left = true;											//��ɫ�Ƿ��泯���
	StateMachine state_machine;											//״̬��
	bool enable_gravity = true;											//�Ƿ���������
	bool is_invulnerable = false;										//�Ƿ��޵�
	Timer timer_invulnerable_blink;										//�޵���˸��ʱ��
	Timer timer_invulnerable_status;									//�޵�״̬��ʱ��
	bool is_blink_invisable = false;									//�Ƿ��޵���˸���ɼ�
	CollisionBox* hit_box = nullptr;									//������ײ��
	CollisionBox* hurt_box = nullptr;									//������ײ��
	AnimationGroup* current_animation = nullptr;						//��ǰ������
	std::unordered_map<std::string, AnimationGroup> animation_pool;		//�������


};


#endif // !_CHARACTER_H_
