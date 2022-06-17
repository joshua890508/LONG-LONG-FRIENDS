#include "scene.h"

int mouse_x, mouse_y;

ALLEGRO_BITMAP *background = NULL;


bool pnt_in_rect(int px, int py, int x, int y, int w, int h) {
	if (px < w && py > y) {
        if(px > x && py < h) return true;
        else return false;
	}
	else return false;
}

void menu_process(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        mouse_state[event.mouse.button] = true;
        on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}
/*
void about_process(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}
void store_process(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}
void pause_process(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_state[event.mouse.button] = true;
			on_mouse_down(event.mouse.button, event.mouse.x, event.mouse.y);
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			mouse_state[event.mouse.button] = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        if (event.mouse.dx != 0 || event.mouse.dy != 0) {
            mouse_x = event.mouse.x;
            mouse_y = event.mouse.y;
        }
    }
}
*/

void on_mouse_down(int btn, int x, int y) {
	if (btn == 1) {
        if (window==SCENE_MENU)
        {
            if (pnt_in_rect(x, y, 350, 470, 495, 520)){
                judge_next_window = true;
                next=SCENE_GAME;
            }else if (pnt_in_rect(x, y, 350, 550, 475, 600)){
                judge_next_window = true;
                next=SCENE_ABOUT;
            }else if (pnt_in_rect(x, y, 330, 630, 530, 685)){
                judge_next_window = true;
                next=SCENE_HOWTOPLAY;
            }else if (pnt_in_rect(x, y, 350, 720, 480, 780)){
                judge_next_window = true;
                next=SCENE_STORE;
            }
        }
        else if (window==SCENE_ABOUT||window==SCENE_HOWTOPLAY||window==SCENE_WIN||window==SCENE_LOSE)
        {
            if (pnt_in_rect(x, y, 0, 0, 600, 900)){
                judge_next_window = true;
                next=SCENE_MENU;
            }
        }
        else if (window==SCENE_STORE)
        {
            if (pnt_in_rect(x, y, 0, 0, 120, 280)){
                judge_next_window = true;
                next=SCENE_MENU;
            }else if (pnt_in_rect(x, y, 285, 280, 383, 330)){
                judge_next_window = true;
                next=SCENE_ITEM;
            }else if (pnt_in_rect(x, y, 265, 470, 340, 500)){
                if(coin>=50 && !longneck)
                {
                    coin-=50;
                    longneck=true;
                }
            }else if (pnt_in_rect(x, y, 400, 470, 480, 500)){
                if(coin>=50 && !penguin)
                {
                    coin-=50;
                    penguin=true;
                }
            }
            else if (pnt_in_rect(x, y, 129, 640, 205, 673)){
                if(coin>=50 && !dog)
                {
                    coin-=50;
                    dog=true;
                }
            }
        }
        else if (window==SCENE_ITEM)
        {
            if (pnt_in_rect(x, y, 0, 0, 120, 280)){
                judge_next_window = true;
                next=SCENE_MENU;
            }else if (pnt_in_rect(x, y, 120, 280, 265, 330)){
                judge_next_window = true;
                next=SCENE_STORE;
            }
        }
        else if (window==SCENE_PAUSE)
        {
            if (pnt_in_rect(x, y, 300, 450, 600, 900)){
                judge_next_window = true;
                next=SCENE_MENU;
            }else if (pnt_in_rect(x, y, 0, 450, 300, 900)){
                judge_next_window = true;
                next=SCENE_STORE;
            }else if (pnt_in_rect(x, y, 300, 0, 600, 450)){
                judge_next_window = true;
                next=SCENE_HOWTOPLAY;
            }
        }
	}
}

void menu_init(){
    background = al_load_bitmap("./image/Menu (2).jpg");
    al_play_sample_instance(sample_instance);
}
void menu_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void menu_destroy(){
    al_destroy_bitmap(background);
}

void game_scene2_init(){
    al_stop_sample_instance(sample_instance);
    al_play_sample_instance(sample_instance2);

    character_init();
    nose_init();
    background = al_load_bitmap("./image/Menu (2).jpg");

}
void game_scene2_draw(){
    background = al_load_bitmap("./image/Game_backgound.jpg");
    al_draw_bitmap(background, 0, 0, 0);
    character_draw();
    nose_draw();
}
void game_scene2_destroy(){
    al_destroy_bitmap(background);
    character_destory();
    nose_destory();
}

void game_scene3_init(){
    background = al_load_bitmap("./image/about.jpg");
}
void game_scene3_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void game_scene3_destroy(){
    al_destroy_bitmap(background);
}

void game_scene4_init(){
    background = al_load_bitmap("./image/Howtoplay.jpg");
}
void game_scene4_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void game_scene4_destroy(){
    al_destroy_bitmap(background);
}

void game_scene5_init(){
    background = al_load_bitmap("./image/Store (1).jpg");
}
void game_scene5_draw(){
    al_draw_bitmap(background, 0, 0, 0);
    sprintf(c, "%d", coin);
    al_draw_text(font,al_map_rgb(0,0,0),390,200,0,c);
}
void game_scene5_destroy(){
    al_destroy_bitmap(background);
}

void game_scene6_init(){
    background = al_load_bitmap("./image/ITEM.jpg");
}
void game_scene6_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void game_scene6_destroy(){
    al_destroy_bitmap(background);
}

void game_scene7_init(){
    al_stop_sample_instance(sample_instance2);
    background = al_load_bitmap("./image/Pause.jpg");
}
void game_scene7_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void game_scene7_destroy(){
    al_destroy_bitmap(background);
}

void game_scene8_init(){
    background = al_load_bitmap("./image/Win.jpg");
}
void game_scene8_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void game_scene8_destroy(){
    al_destroy_bitmap(background);
}

void game_scene9_init(){
    background = al_load_bitmap("./image/Lose.jpg");
}
void game_scene9_draw(){
    al_draw_bitmap(background, 0, 0, 0);
}
void game_scene9_destroy(){
    al_destroy_bitmap(background);
}

