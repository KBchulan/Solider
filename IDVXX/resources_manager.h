#ifndef _RESOURCES_MANAGER_H_
#define _RESOURCES_MANAGER_H_

#include"atlas.h"

#include<string>
#include<easyx.h>
#include<unordered_map>

class ResourcesManager {
public:
	static ResourcesManager* instance();

	void load();

	Atlas* find_atlas(const std::string& id) const;
	IMAGE* find_image(const std::string& id) const;

private:
	static ResourcesManager* manager;

	std::unordered_map<std::string, Atlas*> atlas_pool;
	std::unordered_map<std::string, IMAGE*> image_pool;


private:
	ResourcesManager();
	~ResourcesManager();

	void flip_image(IMAGE* src_image, IMAGE* dst_image, int num_h = 1);
	void flip_image(const std::string& src_id, const std::string dst_id, int num_h = 1);
	void flip_atlas(const std::string& src_id, const std::string dst_id);

};

#endif // !_RESOURCES_MANAGER_H_
