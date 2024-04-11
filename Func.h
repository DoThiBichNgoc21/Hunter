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

#define SDL_ERROR 1
#define IMAGE_ERROR 2
#define MIXER_ERROR 3
#define TTF_ERROR 4

using namespace std;

const string WINDOW_TITLE = "HUNTER";

const int SCREEN_WIDTH = 1280;           //kich co man hinh
const int SCREEN_HEIGHT = 720;

const int COMMON_BUTTON_WIDTH = 150;    // kich co cac nut chung
const int COMMON_BUTTON_HEIGHT = 98;
const int SMALL_BUTTON_WIDTH = 22;
const int SMALL_BUTTON_HEIGHT = 34;

const int PLAY_BUTTON_X = 565;      //vi tri nut Play
const int PLAY_BUTTON_Y= 250;
const int HELP_BUTTON_X = 565;      //vi tri nut help
const int HELP_BUTTON_Y = 357;
const int EXIT_BUTTON_X = 565;      //vi tri nut exit
const int EXIT_BUTTON_Y = 466;
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

//so luong khung hinh cua cac vat the
const int HEALTHBAR_FRAMES = 27;   // so khug hinh thanh mau
const int RUN_FRAMES = 5;          // so khung hinh con ech
const int FLYING_FRAMES = 6;       //so khung hinh con chim bay
const int APPLE_FRAMES = 2;        //so khung hinh qua tao
const int BACKGROUND_LAYER = 1;     // so lop nen

void LogError(string error, int error_code = SDL_ERROR);   //ghi thong diep va ma loi
#endif // FUNC_H_
