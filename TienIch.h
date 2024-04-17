#ifndef TIENICH_H_
#define TIENICH_H_

#include "BaseObject.h"
#include "Botton.h"
#include "Ech.h"
#include "KeThu.h"
#include "HoiMau.h"
#include "Ech.h"
#include "ThanhMau.h"
#include "Func.h"

#include <windows.h>

using namespace std;

bool Init();
bool LoadMedia();
void Close();

string GetHighScoreFromFile(string path);

void UpdateHighScore( string path, const int& score, const string& OldHighScore );

int UpdateGameTimeAndScore( int &time, int &speed, int &score );

void RenderScrollingBackgroud( vector<double> offSetSpeed,                               // Background cuộn
                          BaseObject (&g_BackgroundTexture) [BACKGROUND_LAYER],
                          SDL_Renderer* g_Renderer );

void RenderScrollingGroud ( int &speed, const int tangtoc,                              // Mặt đất cuộn
                           BaseObject g_GroundTexture,
                           SDL_Renderer* g_Renderer );

void XuliPlayButton( SDL_Event* e,
                  Button& PlayButton,
                  bool& QuitMenu,
                  bool& Play,
                  Mix_Chunk* g_Click);

void XuliHelpButton( SDL_Event* e,
                  SDL_Rect (&g_BackButton)[BUTTON_TOTAL],
                  Button& HelpButton,
                  Button& BackButton,
                  BaseObject g_InstructionTexture,
                  BaseObject g_BackButtonTexture,
                  SDL_Renderer* g_Renderer,
                  bool& QuitGame,
                  Mix_Chunk* g_Click);

void XuliExitButton( SDL_Event* e,
                    Button& ExitButton,
                    bool& Quit,
                    Mix_Chunk* g_Click);

void XuliContinueButton ( Button ContinueButton,
                         BaseObject g_ContinueButtonTexture,
                         SDL_Event& e,
                         SDL_Renderer* g_Renderer,
                         SDL_Rect(&g_ContinueButton)[BUTTON_TOTAL],
                         bool& Game_State,
                         Mix_Chunk* g_Click );

void XuliPauseButton ( SDL_Event &e,
                      SDL_Renderer* g_Renderer,
                      SDL_Rect (&g_PauseButton) [BUTTON_TOTAL],
                      Button& PauseButton,
                      Button ContinueButton,
                      BaseObject g_ContinueButtonTexture,
                      bool& game_state,
                      Mix_Chunk* g_Click );

void TaoKeThu ( Enemy& enemy1,
                Enemy& enemy2,
                Enemy& enemy3,
                SDL_Rect (&g_EnemyClips)[FLYING_FRAMES],
                SDL_Renderer* g_Renderer );

void TaoQua ( Apple& apple,
             SDL_Rect (&g_AppleClips)[APPLE_FRAMES],
             SDL_Renderer* g_Renderer);

bool KiemtraVaCham (Character character,
                    SDL_Rect* char_clip,
                    Enemy enemy,
                    SDL_Rect* enemy_clip = nullptr );

bool KiemtraVaCham2 ( Character character,
                      SDL_Rect* char_clip,
                      Apple apple,
                      SDL_Rect* apple_clip = nullptr );

bool KiemtraVaChamKeThu ( Character character,
                          Enemy enemy1,
                          Enemy enemy2,
                          Enemy enemy3,
                          SDL_Rect* char_clip,
                          SDL_Rect* enemy_clip = nullptr );

bool KiemtraVaChamHoiMau ( Character character,
                          Apple apple,
                           SDL_Rect* char_clip,
                           SDL_Rect* apple_clip = nullptr );

void KiemsoatHP ( int& frame, int hp);

void KiemsoatEch ( int& frame );

void KiemsoatKeThu ( int& frame );

void KiemsoatHoiMau ( int& frame, bool check, int location );

void DrawHPScore ( BaseObject g_TextTexture,
                   BaseObject g_HPTexture,
                   SDL_Color textColor,
                   SDL_Renderer* g_Renderer,
                   TTF_Font* g_Front,
                   const int& HP );

void DrawPlayerScore ( BaseObject g_TextTexture,
                     BaseObject g_ScoreTexture,
                     SDL_Color textColor,
                     SDL_Renderer* g_Renderer,
                     TTF_Font* g_Front,
                     const int& score );

void DrawPlayerHighScore ( BaseObject g_TextTexture,
                           BaseObject g_HighScoreTexture,
                           SDL_Color textColor,
                           SDL_Renderer* g_Renderer,
                           TTF_Font* g_Front,
                           const string& HighScore);

void DrawLuaChonEndGame ( BaseObject g_LoseTexture,
                         SDL_Event* e,
                         SDL_Renderer* g_Renderer,
                         bool& PlayAgain );

#endif // TIENICH_H_INCLUDED
