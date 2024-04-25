#include "TienIch.h"

using namespace std;

string GetHighScoreFromFile(string path)      //Doc diem cao nhat tu mot tep tin roi tra no ve duoi dang string
{
    fstream HighScoreFile;
    string highscore;
    HighScoreFile.open(path, ios::in);
    HighScoreFile >> highscore;

    return highscore;
}

void UpdateHighScore( string path, const int& score, const string& OldHighScore )     //Cap nhat diem cao nhat trong tep tin
{
    int Diemcu = 0;
    fstream HighScoreFile;
    string NewHighScore;
    stringstream ChuyenDoiSangInt(OldHighScore);
    HighScoreFile.open(path, ios::out);

    ChuyenDoiSangInt >> Diemcu;
    if ( score > Diemcu )
    {
        Diemcu = score;
    }
    NewHighScore = to_string(Diemcu);

    HighScoreFile << NewHighScore;
}

int UpdateGameTimeAndScore( int& time, int& speed, int& score )      //Cập nhật thời gian và điểm max
{
    if ( time == TIME_MAX )
    {
        speed += SPEED_INCREASEMENT;
    }
    if ( time > TIME_MAX )
    {
        time = 0;
    }
    if ( time % 5 == 0 )
    {
        score += SCORE_INCREASEMENT;
    }
    time += TIME_INCREASEMENT;

    return time;
}

  void RenderScrollingBackgroud ( int &speed, const int tangtoc,              //Background cuộn
                           BaseObject g_BackgroundTexture,
                           SDL_Renderer* g_Renderer )
{
    speed -= GROUND_SPEED + tangtoc;
    if ( speed < -g_BackgroundTexture.GetWidth() )
    {
        speed = 0;
    }
    g_BackgroundTexture.Render( speed, 0, g_Renderer );
    g_BackgroundTexture.Render( speed + g_BackgroundTexture.GetWidth(), 0, g_Renderer );
}

void RenderScrollingGroud ( int &speed, const int tangtoc,                              // Mặt đất cuộn
                           BaseObject g_GroundTexture,
                           SDL_Renderer* g_Renderer )
{
    speed -= GROUND_SPEED + tangtoc;
    if ( speed < -g_GroundTexture.GetWidth() )
    {
        speed = 0;
    }
    g_GroundTexture.Render( speed, 0, g_Renderer );
    g_GroundTexture.Render( speed + g_GroundTexture.GetWidth(), 0, g_Renderer );
}

void XuliPlayButton( SDL_Event* e,
                  Button& PlayButton,
                  bool& QuitMenu,
                  bool& Play,
                  Mix_Chunk* g_Click)
{
   if ( e->type == SDL_QUIT )
   {
       QuitMenu = true;
   }
   if ( PlayButton.IsInside(e, COMMON_BUTTON))
   {
       switch( e->type )
       {
       case SDL_MOUSEMOTION:
        PlayButton.currentSprite = BUTTON_MOUSE_OVER;
        break;
       case SDL_MOUSEBUTTONDOWN:
        Play = true;
        QuitMenu = true;
        Mix_PlayChannel( MIX_CHANNEL, g_Click, 0);
        PlayButton.currentSprite = BUTTON_MOUSE_OVER;
        break;
       }
   }
   else
   {
       PlayButton.currentSprite = BUTTON_MOUSE_OUT;
   }
}

void XuliHelpButton( SDL_Event* e,
                  SDL_Rect (&g_BackButton)[BUTTON_TOTAL],
                  Button& HelpButton,
                  Button& BackButton,
                  BaseObject g_InstructionTexture,
                  BaseObject g_BackButtonTexture,
                  SDL_Renderer* g_Renderer,
                  bool& QuitGame,
                  Mix_Chunk* g_Click)
{
    if ( HelpButton.IsInside(e, COMMON_BUTTON))
    {
        switch( e->type )
       {
       case SDL_MOUSEMOTION:
        HelpButton.currentSprite = BUTTON_MOUSE_OVER;
        break;
       case SDL_MOUSEBUTTONDOWN:
        HelpButton.currentSprite = BUTTON_MOUSE_OVER;
        Mix_PlayChannel( MIX_CHANNEL, g_Click, NOT_REPEATITIVE);
        bool ReadDone = false;
        while (!ReadDone)
        {
            do{
                if (e->type == SDL_QUIT)
                {
                    ReadDone = true;
                    QuitGame = true;
                    Close();
                }
                else if ( BackButton.IsInside(e, COMMON_BUTTON))
                {
                    switch(e->type)
                    {
                        case SDL_MOUSEMOTION:
                        BackButton.currentSprite = BUTTON_MOUSE_OVER;
                        break;
                        case SDL_MOUSEBUTTONDOWN:
                        BackButton.currentSprite = BUTTON_MOUSE_OVER;
                        Mix_PlayChannel( MIX_CHANNEL, g_Click, NOT_REPEATITIVE);
                        ReadDone = true;
                        break;
                    }
                }
                else
                {
                    BackButton.currentSprite = BUTTON_MOUSE_OUT;
                }
                g_InstructionTexture.Render(0, 0, g_Renderer);
                SDL_Rect* currentClip_Back = &g_BackButton[BackButton.currentSprite];
                BackButton.Render(currentClip_Back, g_Renderer, g_BackButtonTexture);

                SDL_RenderPresent(g_Renderer);
            }
            while (SDL_PollEvent(e) != 0 && e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION);
        }
        break;
       }
    }
    else
    {
        HelpButton.currentSprite = BUTTON_MOUSE_OUT;
    }
}

void XuliExitButton( SDL_Event* e,
                    Button& ExitButton,
                    bool& Quit,
                    Mix_Chunk* g_Click)
{
    if ( ExitButton.IsInside(e, COMMON_BUTTON))
    {
        switch( e->type )
        {
    case SDL_MOUSEMOTION:
        ExitButton.currentSprite = BUTTON_MOUSE_OVER;
        break;
    case SDL_MOUSEBUTTONDOWN:
        Quit = true;
        ExitButton.currentSprite = BUTTON_MOUSE_OVER;
        Mix_PlayChannel( MIX_CHANNEL, g_Click, NOT_REPEATITIVE );
        break;
        }
    }
    else{
        ExitButton.currentSprite = BUTTON_MOUSE_OUT;
    }
}

void XuliContinueButton ( Button ContinueButton,
                         BaseObject g_ContinueButtonTexture,
                         SDL_Event& e,
                         SDL_Renderer* g_Renderer,
                         SDL_Rect (&g_ContinueButton)[BUTTON_TOTAL],
                         bool& Game_State,
                         Mix_Chunk* g_Click, bool &quitGame, bool &Play_Again )
{
    bool back_to_game = false;
    while ( !back_to_game )
    {
        do
        {
            if(e.type == SDL_QUIT)
            {
                quitGame = true;
                Play_Again = false;
                return;
            }
            if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 && Game_State == false )
            {
                switch (e.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    {
                        Game_State = true;
                        back_to_game = true;
                        ContinueButton.currentSprite = BUTTON_MOUSE_OVER;
                        Mix_PlayChannel( MIX_CHANNEL, g_Click, NOT_REPEATITIVE );
                        Mix_ResumeMusic();
                    }
                }
            }
            SDL_Rect* currentClip_Continue = &g_ContinueButton[ ContinueButton.currentSprite ];
            ContinueButton.Render( currentClip_Continue, g_Renderer, g_ContinueButtonTexture );

            SDL_RenderPresent( g_Renderer );
        }
        while ( SDL_WaitEvent( &e ) != 0);
    }
}

void XuliPauseButton ( SDL_Event& e,
                      SDL_Renderer* g_Renderer,
                      SDL_Rect (&g_ContinueButton)[BUTTON_TOTAL],
                      Button& PauseButton,
                      Button ContinueButton,
                      BaseObject g_ContinueButtonTexture,
                      bool& game_state,
                      Mix_Chunk* g_Click, bool &quitGame, bool &Play_Again )
{
    if ( e.type == SDL_KEYDOWN && e.key.repeat == 0 && game_state == true )
    {
        switch ( e.key.keysym.sym )
        {
        case SDLK_LEFT:
            PauseButton.currentSprite = BUTTON_MOUSE_OVER;
            game_state = false;
            XuliContinueButton( ContinueButton, g_ContinueButtonTexture, e, g_Renderer, g_ContinueButton, game_state, g_Click, quitGame, Play_Again);
            Mix_PlayChannel( MIX_CHANNEL, g_Click, NOT_REPEATITIVE );
            Mix_PauseMusic();
            break;
        }
    }
    PauseButton.currentSprite = BUTTON_MOUSE_OUT;
}

void TaoKeThu(Enemy& enemy1,
                Enemy& enemy2,
                Enemy& enemy3,
                SDL_Rect (&g_EnemyClips)[FLYING_FRAMES],
                SDL_Renderer * g_Renderer )
{
    enemy1.LoadFromFile( "img/KeThu/quai1.png", g_Renderer);
    enemy2.LoadFromFile( "img/KeThu/quai2.png", g_Renderer);
    enemy3.LoadFromFile( "img/KeThu/quai3.png", g_Renderer);
 {
        g_EnemyClips[0].x = 56 * 0;
        g_EnemyClips[0].y = 0;
        g_EnemyClips[0].w = 56;
        g_EnemyClips[0].h = 49;

        g_EnemyClips[1].x = 56 * 1;
        g_EnemyClips[1].y = 0;
        g_EnemyClips[1].w = 56;
        g_EnemyClips[1].h = 49;

        g_EnemyClips[2].x = 56 * 2;
        g_EnemyClips[2].y = 0;
        g_EnemyClips[2].w = 56;
        g_EnemyClips[2].h = 49;

        g_EnemyClips[3].x = 56 * 3;
        g_EnemyClips[3].y = 0;
        g_EnemyClips[3].w = 56;
        g_EnemyClips[3].h = 49;
   }
}

void TaoQua( Apple& apple,
             SDL_Rect (&g_AppleClips)[APPLE_FRAMES],
             SDL_Renderer* g_Renderer)
{
    apple.LoadFromFile( "img/KeThu/Qua.png", g_Renderer );
    {
        g_AppleClips[0].x = 46 * 0 ;
        g_AppleClips[0].y = 0;
        g_AppleClips[0].w = 46;
        g_AppleClips[0].h = 35;

        g_AppleClips[1].x = 46 * 1;
        g_AppleClips[1].y = 0;
        g_AppleClips[1].w = 46;
        g_AppleClips[1].h = 35;
    }
}

void TaoDa( Da& da,
            SDL_Rect (&g_DaClips)[DA_FRAMES],
            SDL_Renderer* g_Renderer)
{
     da.LoadFromFile("img/KeThu/da.png", g_Renderer );
     {
         g_DaClips[0].x = 178 * 0;
         g_DaClips[0].y = 0;
         g_DaClips[0].w = 178;
         g_DaClips[0].h = 279;

         g_DaClips[1].x = 178 * 1;
         g_DaClips[1].y = 0;
         g_DaClips[1].w = 178;
         g_DaClips[1].h = 279;
     }
}

void TaoBullet(Bullet& bullet,
               SDL_Renderer* g_Renderer)
{
    bullet.LoadFromFile("img/Bullet/Bullet.png", g_Renderer);
}

bool KiemTraVaCham3 (Character character__,
                     SDL_Rect* char_clip__,
                     Da da__,
                     SDL_Rect* da_clip__ )
{
    int left_a__ = character__.GetPosX();
    int right_a__ = character__.GetPosX() + char_clip__->w;
    int top_a__ = character__.GetPosY();
    int bottom_a__ = character__.GetPosY() + char_clip__->h;

     const int TRASH_PIXEL_1 = 9;
     const int TRASH_PIXEL_2 = 9;

     int left_b__ = da__.GetPosX() + TRASH_PIXEL_1;
     int right_b__ = da__.GetPosX() + char_clip__->w - TRASH_PIXEL_1;
     int top_b__ = da__.GetPosY();
     int bottom_b__ = da__.GetPosY() + char_clip__->h - TRASH_PIXEL_2;

     if ( right_a__ - TRASH_PIXEL_1 >= left_b__ && left_a__ + TRASH_PIXEL_1 <= right_b__ )
     {
         if ( bottom_a__ - TRASH_PIXEL_2 >= top_b__ )
         {
             return true;
         }
     }
     return false;
}

bool KiemTraVaCham4(Bullet bullet____,
                    SDL_Rect* bullet_clip____,
                    Da da____,
                    SDL_Rect* da_clip____)
{
    int left_a____ = bullet____.GetPosX();
	int right_a____ = bullet____.GetPosX() + bullet____.GetWidth();
	int top_a____ = bullet____.GetPosY();
	int bottom_a____ = bullet____.GetPosY() + bullet____.GetHeight();

	const int TRASH_PIXEL = 9;

    int left_b____ = da____.GetPosX() + TRASH_PIXEL;
    int right_b____ = da____.GetPosX() + da_clip____->w - TRASH_PIXEL ;
    int top_b____ = da____.GetPosY();
    int bottom_b____ = da____.GetPosY() + da_clip____->h - TRASH_PIXEL ;

    if (right_a____ >= left_b____ && left_a____ <= right_b____)
    {
        if (top_a____ <= bottom_b____ && top_a____ >= top_b____)
        {
            return true;
        }

        if (bottom_a____ >= bottom_b____ && bottom_a____ <= top_b____)
        {
            return true;
        }
    }

	return false;
}

bool KiemtraVaCham (Character character,
                    SDL_Rect* char_clip,
                    Enemy enemy,
                    SDL_Rect* enemy_clip )

{
    int left_a = character.GetPosX();
    int right_a = character.GetPosX() + char_clip->w;
    int top_a = character.GetPosY();
    int bottom_a = character.GetPosY() + char_clip->h;

    if ( enemy.GetType() == ON_GROUND_ENEMY )
    {
        const int TRASH_PIXEL_1 = 25;
        const int TRASH_PIXEL_2 = 30;

        int left_b = enemy.GetPosX();
        int right_b = enemy.GetPosX() + enemy.GetWidth();
        int top_b = enemy.GetPosY();
        int bottom_b = enemy.GetPosY() + enemy.GetHeight();

        if ( right_a - TRASH_PIXEL_1 >= left_b && left_a + TRASH_PIXEL_1 <= right_b )
        {
           if ( bottom_a - TRASH_PIXEL_2 >= top_b )
           {
               return true;
           }
        }
    }
    else if ( enemy.GetType() == IN_AIR_ENEMY )
    {
        const int TRASH_PIXEL_1 = 20;
        const int TRASH_PIXEL_2 = 10;

        int left_b = enemy.GetPosX() + TRASH_PIXEL_1;
        int right_b = enemy.GetPosX() + enemy_clip->w - TRASH_PIXEL_1;
        int top_b = enemy.GetPosY();
        int bottom_b = enemy.GetPosY() + enemy_clip->h - TRASH_PIXEL_2;

        if ( right_a >= left_b && left_a <= right_b )
        {
            if ( top_a <= bottom_b && bottom_a >= top_b )
            {
                return true;
            }
            if ( bottom_a >= bottom_b && bottom_a <= top_b )
            {
                return true;
            }
        }
    }
    return false;
}

bool KiemtraVaCham2 ( Character  character_,
                      SDL_Rect* char_clip_,
                      Apple apple_,
                      SDL_Rect* apple_clip_ )
{
    int left_a_ = character_.GetPosX();
    int right_a_ = character_.GetPosX() + char_clip_->w;
    int top_a_ = character_.GetPosY();
    int bottom_a_ = character_.GetPosY() + char_clip_->h;

     const int TRASH_PIXEL_1 = 0;
     const int TRASH_PIXEL_2 = 0;

     int left_b_ = apple_.GetPosX() + TRASH_PIXEL_1;
     int right_b_ = apple_.GetPosX() + apple_clip_->w - TRASH_PIXEL_1;
     int top_b_ = apple_.GetPosY();
     int bottom_b_ = apple_.GetPosY() + apple_clip_->h - TRASH_PIXEL_2;

     if ( right_a_ - TRASH_PIXEL_1 >= left_b_ && left_a_ + TRASH_PIXEL_1 <= right_b_ )
     {
         if ( bottom_a_ - TRASH_PIXEL_2 >= top_b_ && top_a_ + TRASH_PIXEL_2 <= bottom_b_)
         {
             return true;
         }
     }
     return false;
}

bool KiemtraVaChamKeThu ( Character character,
                          Enemy enemy1,
                          Enemy enemy2,
                          Enemy enemy3,
                          SDL_Rect* char_clip,
                          SDL_Rect* enemy_clip )
{
    if ( KiemtraVaCham( character, char_clip, enemy1 ) )
    {
        return true;
    }
    if ( KiemtraVaCham ( character, char_clip, enemy2 ) )
    {
        return true;
    }
    if ( KiemtraVaCham( character, char_clip, enemy3, enemy_clip ) )
    {
        return true;
    }
    return false;
}

bool KiemtraVaChamHoiMau ( Character character_,
                           Apple apple_,
                           SDL_Rect* char_clip_,
                           SDL_Rect* apple_clip_ )
{
    if ( KiemtraVaCham2 ( character_, char_clip_, apple_, apple_clip_ ) )
    {
        return true;
    }
    return false;
}

bool KiemTraVaChamDa(Character character__,
                     Da &da__,
                     SDL_Rect* char_clip__,
                     SDL_Rect* da_clip__,
                     Bullet bullet__,
                     SDL_Rect* bullet_clip__ )
{
    if ( KiemTraVaCham4( bullet__, bullet_clip__, da__, da_clip__ ) )
    {
        da__.Reset();
        //return false;
    }
    if ( KiemTraVaCham3( character__, char_clip__, da__, da_clip__))
    {
        return true;
    }
    return false;
}

void KiemsoatHP ( int& frame, int HP)
{
    if (HP == 100) frame = 0;
    if (HP >= 96 && HP < 100) frame = 1;
    if (HP >= 92 && HP < 96) frame = 2;
    if (HP >= 88 && HP < 92) frame = 3;
    if (HP >= 84 && HP < 88) frame = 4;
    if (HP >= 80 && HP < 84) frame = 5;
    if (HP >= 76 && HP < 80) frame = 6;
    if (HP >= 72 && HP < 76) frame = 7;
    if (HP >= 68 && HP < 72) frame = 8;
    if (HP >= 64 && HP < 68) frame = 9;
    if (HP >= 60 && HP < 64) frame = 10;
    if (HP >= 56 && HP < 60) frame = 11;
    if (HP >= 52 && HP < 56) frame = 12;
    if (HP >= 48 && HP < 52) frame = 13;
    if (HP >= 44 && HP < 48) frame = 14;
    if (HP >= 40 && HP < 44) frame = 15;
    if (HP >= 36 && HP < 40) frame = 16;
    if (HP >= 32 && HP < 36) frame = 17;
    if (HP >= 28 && HP < 32) frame = 18;
    if (HP >= 24 && HP < 28) frame = 19;
    if (HP >= 20 && HP < 24) frame = 20;
    if (HP >= 16 && HP < 20) frame = 21;
    if (HP >= 12 && HP < 16) frame = 22;
    if (HP >= 8 && HP < 12) frame = 23;
    if (HP >= 4 && HP < 8) frame = 24;
    if (HP > 0 && HP < 4) frame = 25;
    if (HP == 0) frame = 26;
}

void KiemsoatEch ( int& frame )
{
    frame += FRAME_INCREASEMENT;
    if ( frame / SLOW_FRAME_CHAR >= RUN_FRAMES )
    {
        frame = 0;
    }
}

void KiemsoatKeThu ( int& frame )
{
    frame += FRAME_INCREASEMENT;
    if ( frame / SLOW_FRAME_ENEMY >= FLYING_FRAMES )
    {
        frame = 0;
    }
}

void KiemsoatHoiMau ( int& frame, bool check, int location )
{
    if ( check == true )
    {
        frame = 1;
    }
    if ( location < -50 )
    {
        frame = 0;
    }
}

void DrawHPScore ( BaseObject g_TextTexture,       //Ve, hien thi diem mau
                   BaseObject g_HPTexture,
                   SDL_Color textColor,
                   SDL_Renderer* g_Renderer,
                   TTF_Font* g_Front,
                   const int& HP )
{
    g_TextTexture.Render( TEXT_3_X, TEXT_3_Y, g_Renderer );
    if ( g_HPTexture.LoadFromRenderedTexture(to_string(HP), g_Front, textColor, g_Renderer ) )
    {
        g_HPTexture.Render( HP_X, HP_Y, g_Renderer );
    }
}

void DrawPlayerScore ( BaseObject g_TextTexture,         //Ve, hien thi diem cua nguoi chơi len man hinh
                     BaseObject g_ScoreTexture,
                     SDL_Color textColor,
                     SDL_Renderer* g_Renderer,
                     TTF_Font* g_Front,
                     const int& score )
{
    g_TextTexture.Render( TEXT_1_X, TEXT_1_Y, g_Renderer );
    if ( g_ScoreTexture.LoadFromRenderedTexture( to_string(score), g_Front, textColor, g_Renderer ) )
    {
        g_ScoreTexture.Render( SCORE_X, SCORE_Y, g_Renderer );
    }
}

void DrawPlayerHighScore ( BaseObject g_TextTexture,          //Hien thi diem cao nhat cua nguoi choi len man
                           BaseObject g_HighScoreTexture,
                           SDL_Color textColor,
                           SDL_Renderer* g_Renderer,
                           TTF_Font* g_Front,
                           const string& HighScore)
{
    g_TextTexture.Render( TEXT_2_X, TEXT_2_Y, g_Renderer );
    if ( g_HighScoreTexture.LoadFromRenderedTexture(HighScore, g_Front, textColor, g_Renderer ) )
    {
        g_HighScoreTexture.Render( HIGH_SCORE_X, HIGH_SCORE_Y, g_Renderer );
    }
}

void DrawLuaChonEndGame ( BaseObject g_LoseTexture,
                         SDL_Event* e,
                         SDL_Renderer* g_Renderer,
                         bool& PlayAgain )
{
    if ( PlayAgain )
    {
        bool end_game = false;
        while ( !end_game )
        {
            while ( SDL_PollEvent(e) != 0 )
            {
                if ( e->type == SDL_QUIT )
                {
                    PlayAgain = false;
                }
                if ( e->type == SDL_KEYDOWN )
                {
                    switch ( e->key.keysym.sym )
                    {
                    case SDLK_SPACE:
                        end_game = true;
                        break;
                    case SDLK_ESCAPE:
                        end_game = true;
                        PlayAgain = false;
                        break;
                    }
                }
            }
            g_LoseTexture.Render( 0, 0, g_Renderer );
            SDL_RenderPresent( g_Renderer );
        }
    }
}











