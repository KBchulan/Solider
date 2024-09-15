#ifndef _PLAYER_STATE_NODES_H_
#define _PLAYER_STATE_NODES_H_

#include "timer.h"
#include "state_node.h"

class PlayerAttackState :public StateNode {
public:
	PlayerAttackState();
	~PlayerAttackState() = default;
	
	void on_enter()override;
	void on_update(float delta)override;
	void on_exit()override;

private:
	Timer timer;

private:
	void update_hit_box_position();
};

class PlayerDeadState :public StateNode {
public:
	PlayerDeadState();
	~PlayerDeadState() = default;
	
	void on_enter()override;
	void on_update(float delta)override;

private:
	Timer timer;

};

class PlayerFallState :public StateNode {
public:
	PlayerFallState() = default;
	~PlayerFallState() = default;
	
	void on_enter()override;
	void on_update(float delta)override;

};

class PlayerIdleState :public StateNode {
public:
	PlayerIdleState() = default;
	~PlayerIdleState() = default;

	void on_enter()override;
	void on_update(float delta)override;

};

class PlayerJumpState :public StateNode {
public:
	PlayerJumpState() = default;
	~PlayerJumpState() = default;

	void on_enter()override;
	void on_update(float delta)override;

};

class PlayerRollState :public StateNode {
public:
	PlayerRollState();
	~PlayerRollState() = default;

	void on_enter()override;
	void on_update(float delta)override;
	void on_exit()override;

private:
	Timer timer;

};

class PlayerRunState :public StateNode {
public:
	PlayerRunState() = default;
	~PlayerRunState() = default;

	void on_enter()override;
	void on_update(float delta)override;
	void on_exit()override;

};



#endif // !_PLAYER_STATE_NODES_H_
