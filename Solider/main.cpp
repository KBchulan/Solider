#include<easyx.h>
#include<chrono>
#include<thread>
#include<iostream>

#include "util.h"
#include "camera.h"
#include "resources_manager.h"
#include "collision_manager.h"
#include "character_manager.h"
#include "bullet_time_manager.h"

bool running = true;

static void draw_background() {
	static IMAGE* img_background = ResourcesManager::instance()->find_image("background");
	Rect rect_dst;
	if (!CollisionManager::instance()->get_is_coolided_each_frame()) {
		rect_dst = {
			(getwidth() - img_background->getwidth()) / 2,
			(getheight() - img_background->getheight()) / 2,
			img_background->getwidth(),
			img_background->getheight()
		};
	}
	else {
		rect_dst = {
			(getwidth() - img_background->getwidth()) / 2 + (int)CollisionManager::instance()->get_shake_camera().get_position().x,
			(getheight() - img_background->getheight()) / 2 + (int)CollisionManager::instance()->get_shake_camera().get_position().y,
			img_background->getwidth(),
			img_background->getheight()
		};
	}
	putimage_ex(img_background, &rect_dst);
}

static void draw_remain_hp(){
	static IMAGE* img_ui_heart = ResourcesManager::instance()->find_image("ui_heart");
	Rect rect_dst = { 0, 10, img_ui_heart->getwidth(), img_ui_heart->getheight() };
	for (int i = 0; i < CharacterManager::instance()->get_player()->get_hp(); i++){
		rect_dst.x = 10 + i * 40;
		putimage_ex(img_ui_heart, &rect_dst);
	}
}

int x = 0;
static void draw_enemy_hp() {
	RECT rect_hp = { 340,90,940,130 };
	rectangle(rect_hp.left, rect_hp.top, rect_hp.right, rect_hp.bottom);
	setfillcolor(RGB(209, 18, 18));
	int sum_hp = 600;
	if (x == 0)
		x = sum_hp / CharacterManager::instance()->get_enemy()->get_hp();
	RECT rect_hp_remain = { 340,90,340 + x * CharacterManager::instance()->get_enemy()->get_hp(), 130 };
	solidrectangle(rect_hp_remain.left, rect_hp_remain.top, rect_hp_remain.right, rect_hp_remain.bottom);
}

int main(int argc,char** argv) {
	using namespace std::chrono;

	HWND hwnd = initgraph(1280, 720, EX_SHOWCONSOLE);
	SetWindowText(hwnd, _T("made in whx"));

	try {
		ResourcesManager::instance()->load();
	}
	catch (const LPCTSTR id) {
		TCHAR err_msg[512];
		_stprintf_s(err_msg, _T("无法加载:%s"), id);
		MessageBox(hwnd, err_msg, _T("资源加载失败"), MB_OK | MB_ICONERROR);
		return -1;
	}

	play_audio(_T("bgm"), true);

	const nanoseconds frame_duration(1000000000 / 144);
	steady_clock::time_point last_tick = steady_clock::now();

	ExMessage msg;

	BeginBatchDraw();
	while (running) {

		while (peekmessage(&msg)) {
			//处理消息
			CharacterManager::instance()->on_input(msg);
		}

		steady_clock::time_point frame_start = steady_clock::now();
		duration<float> delta = duration<float> (frame_start - last_tick);

		//处理更新
		float scaled_delta = BulletTimeManager::instance()->on_update(delta.count());
		CharacterManager::instance()->on_update(scaled_delta);
		CollisionManager::instance()->process_collide();
		/*if (CollisionManager::instance()->get_is_coolided_each_frame()) {
			CollisionManager::instance()->get_shake_camera().on_update(scaled_delta);
			if (!CollisionManager::instance()->get_shake_camera().get_is_shaking()) {
				CollisionManager::instance()->set_is_coolided_each_frame(false);
			}
		}*/
		
		setbkcolor(RGB(0,0,0));
		cleardevice();

		draw_background();
		CharacterManager::instance()->on_render();
		//CollisionManager::instance()->on_debug_render();
		draw_remain_hp();
		draw_enemy_hp();

		FlushBatchDraw();

		last_tick = frame_start;
		nanoseconds sleep_duration = frame_duration - (steady_clock::now() - frame_start);
		if (sleep_duration > nanoseconds(0)) {
			std::this_thread::sleep_for(sleep_duration);
		}
	}

	EndBatchDraw();

	return 0;

}