#ifndef FUNC_H_
#define FUNC_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <ctime>
#include <sstream>

#define SPEED_INCREASEMENT 0.75
#define SCORE_INCREASEMENT 1
#define TIME_INCREASEMENT 1
#define FRAME_INCREASEMENT 1

#define MIX_CHANNEL -1

#define TIME_MAX 1000
#define GROUND 510
#define MAX_HEIGHT 330

#define SDL_ERROR 1
#define IMAGE_ERROR 2
#define MIXER_ERROR 3
#define TTF_ERROR 4

#define BASE_OFFSET_SPEED 0

#define GROUND_SPEED 5
#define ENEMY_SPEED 5
#define MAX_ENEMY_WIDTH 100

#define IN_AIR_ENEMY 1
#define ON_GROUND_ENEMY 0

#define SLOW_FRAME_CHAR 4
#define SLOW_FRAME_ENEMY 4
#define SLOW_FRAME_APPLE 7

#define IS_REPEATITIVE -1
#define NOT_REPEATITIVE 0

#define SMALL_BUTTON 1
#define COMMON_BUTTON 2


using namespace std;

const string WINDOW_TITLE = "HUNTER Game";

const int SCREEN_WIDTH = 904 ;           //kich co man hinh
const int SCREEN_HEIGHT = 680;

const int COMMON_BUTTON_WIDTH = 238;    // kich co cac nut chung
const int COMMON_BUTTON_HEIGHT = 82;
const int SMALL_BUTTON_WIDTH = 67;
const int SMALL_BUTTON_HEIGHT = 76;

const int PLAY_BUTTON_X = 333;      //vi tri nut Play
const int PLAY_BUTTON_Y= 300;
const int HELP_BUTTON_X = 333;      //vi tri nut help
const int HELP_BUTTON_Y = 420;
const int EXIT_BUTTON_X = 333;      //vi tri nut exit
const int EXIT_BUTTON_Y = 530;
const int BACK_BUTTON_X = 31;       //vi tri nut back
const int BACK_BUTTON_Y = 29;
const int PAUSE_BUTTON_X = 31;      //vi tri nut pause
const int PAUSE_BUTTON_Y = 29;
const int CONTINUE_BUTTON_X = 31;   //vi tri nut continue
const int CONTINUE_BUTTON_Y = 29;

const int TEXT_1_X = 1080;        //vi tri text1
const int TEXT_1_Y = 20;
const int TEXT_2_X = 1080;        //vi tri text2
const int TEXT_2_Y = 80;
const int TEXT_3_X = 600;         //vi tri text3
const int TEXT_3_Y = 30;
const int SCORE_X = 1200;         //vi tri ghi diem
const int SCORE_Y = 20;
const int HIGH_SCORE_X = 1200;    //vi tri diem cao nhat
const int HIGH_SCORE_Y = 80;
const int HP_X = 650;             //vi tri diem mau
const int HP_Y = 30;

const double LAYER_1_SPEED = 0.0;
const double LAYER_2_SPEED = 0.25;
const double LAYER_3_SPEED = 0.5;
const double LAYER_4_SPEED = 0.75;
const double LAYER_5_SPEED = 1.0;

//so luong khung hinh cua cac vat the
const int HEALTHBAR_FRAMES = 27;   // so khug hinh thanh mau
const int RUN_FRAMES = 5;          // so khung hinh con ech
const int FLYING_FRAMES = 6;       //so khung hinh con chim bay
const int APPLE_FRAMES = 2;        //so khung hinh qua tao
const int BACKGROUND_LAYER = 1;     // so lop nen

enum ButtonSprite
{
    BUTTON_MOUSE_OUT = 0,
    BUTTON_MOUSE_OVER = 1,
    BUTTON_TOTAL = 2
};

void LogError(string error, int error_code = SDL_ERROR);   //ghi thong diep va ma loi
#endif // FUNC_H_
