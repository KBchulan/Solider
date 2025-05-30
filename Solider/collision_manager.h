#ifndef _COLLISION_MANAGER_H_
#define _COLLISION_MANAGER_H_

#include "camera.h"
#include "collision_box.h"

#include <vector>

class CollisionManager {
public:
	static CollisionManager* instance();

	CollisionBox* create_collision_box();
	void destroy_collision_box(CollisionBox* collision_box);

	void process_collide();
	void on_debug_render();
	
	bool get_is_coolided_each_frame() const;
	void set_is_coolided_each_frame(bool is_coolided_each_frame);
	Camera& get_shake_camera();

private:
	Camera shake_camera;
	bool is_coolided_each_frame = false;

private:
	static CollisionManager* manager;

	std::vector<CollisionBox*> collision_box_list;

private:
	CollisionManager();
	~CollisionManager();

};

#endif // _COLLISION_MANAGER_H_
