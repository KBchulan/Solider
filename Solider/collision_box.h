#ifndef _COLLISION_BOX_H_
#define _COLLISION_BOX_H_

#include "vector2.h"
#include "collision_layer.h"

#include <functional>

class CollisionManager;

class CollisionBox {
	friend class CollisionManager;

public:
	void set_enabled(bool enable) {
		enabled = enable;
	}

	void set_layer_src(CollisionLayer layer) {
		layer_src = layer;
	}

	void set_layer_dst(CollisionLayer layer) {
		layer_dst = layer;
	}

	void set_on_collide(std::function<void()> func) {
		this->on_collide = func;
	}

	void set_size(const Vector2& size) {
		this->size = size;
	}

	const Vector2& get_size()const {
		return size;
	}

	void set_position(const Vector2& position) {
		this->position = position;
	}

private:
	Vector2 size;							//Åö×²Ïä×Ó³ß´ç
	Vector2 position;						//Åö×²Ïä×ÓÎ»ÖÃ
	bool enabled = true;					//Åö×²Ïä×ÓÊÇ·ñÆôÓÃ
	std::function<void()> on_collide;
	CollisionLayer layer_src = CollisionLayer::None;
	CollisionLayer layer_dst = CollisionLayer::None;
	
private:
	CollisionBox() = default;
	~CollisionBox() = default;

};



#endif // !_COLLISION_BOX_H_
