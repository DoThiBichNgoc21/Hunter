#include "BaseObject.h"
#include "Func.h"
#include "Botton.h"
#include "Ech.h"
#include "HoiMau.h"
#include "ThanhMau.h"
#include "TienIch.h"
#include "KeThu.h"

using namespace std;

//const string LAYER[BACKGROUND_LAYER] =
//{
//    "img/background/Backgroud.png",
//
//};

SDL_Window* g_Window = nullptr;
SDL_Renderer* g_Renderer = nullptr;
SDL_Color textColor = { 255, 255, 255 };
SDL_Color textColor2 = { 170, 0, 0};
TTF_Font* g_Front = nullptr;
TTF_Font* g_Front2 = nullptr;
Mix_Music* g_Music = nullptr;
Mix_Music* g_MenuMusic = nullptr;
Mix_Chunk* g_Click = nullptr;
Mix_Chunk* g_Jump = nullptr;
Mix_Chunk* g_Lose = nullptr;

SDL_Rect g_PlayButton[BUTTON_TOTAL];
SDL_Rect g_HelpButton[BUTTON_TOTAL];
SDL_Rect g_ExitButton[BUTTON_TOTAL];
SDL_Rect g_BackButton[BUTTON_TOTAL];
SDL_Rect g_PauseButton[BUTTON_TOTAL];
SDL_Rect g_ContinueButton[BUTTON_TOTAL];
SDL_Rect g_PlayAgainButton[BUTTON_TOTAL];
SDL_Rect g_CharacterClips[RUN_FRAMES];
SDL_Rect g_HealthBarClips[HEALTHBAR_FRAMES];
SDL_Rect g_EnemyClips[FLYING_FRAMES];
SDL_Rect g_AppleClips[APPLE_FRAMES];

BaseObject g_MenuTexture;
BaseObject g_InstructionTexture;
BaseObject g_BackgroundTexture;
BaseObject g_CharacterTexture;
BaseObject g_HealthBarTexture;
BaseObject g_GroundTexture;
BaseObject g_PlayButtonTexture;
BaseObject g_HelpButtonTexture;
BaseObject g_ExitButtonTexture;
BaseObject g_BackButtonTexture;
BaseObject g_PauseButtonTexture;
BaseObject g_ContinueButtonTexture;
BaseObject g_LoseTexture;
BaseObject g_Text1Texture;
BaseObject g_ScoreTexture;
BaseObject g_Text2Texture;
BaseObject g_HighScoreTexture;
BaseObject g_Text3Texture;
BaseObject g_HPTexture;

Button PlayButton(PLAY_BUTTON_X, PLAY_BUTTON_Y);
Button HelpButton(HELP_BUTTON_X, HELP_BUTTON_Y);
Button ExitButton(EXIT_BUTTON_X, EXIT_BUTTON_Y);
Button BackButton(BACK_BUTTON_X, BACK_BUTTON_Y);
Button PauseButton(PAUSE_BUTTON_X, PAUSE_BUTTON_Y);
Button ContinueButton(CONTINUE_BUTTON_X, CONTINUE_BUTTON_Y);

Character character;

HealthBar healthbar;


int main(int argc, char* argv[])
{
    if ( !Init() )
    {
        cout << "Khong khoi tao duoc." << endl;
    }
    else
    {
        if ( !LoadMedia() )
        {
            cout << "Khong tai duoc phuong tien." << endl;
        }
        else
        {
            bool Quit_Menu = false;
            bool Play_Again = false;

            Mix_PlayMusic ( g_MenuMusic, IS_REPEATITIVE );
            while ( !Quit_Menu )
            {
                SDL_Event e_Mouse;
                while (SDL_PollEvent(&e_Mouse) != 0)
                {
                    if ( e_Mouse.type == SDL_QUIT )
                    {
                        Quit_Menu = true;
                    }
                    bool Quit_Game = false;
                    XuliPlayButton(&e_Mouse, PlayButton, Quit_Menu, Play_Again, g_Click);  //Xử lí sự kiện tạo ra bởi các nút
                    XuliHelpButton(&e_Mouse, g_BackButton,
                                   HelpButton, BackButton,
                                     g_InstructionTexture, g_BackButtonTexture,
                                     g_Renderer, Quit_Game, g_Click);
                    XuliExitButton(&e_Mouse, ExitButton, Quit_Menu, g_Click);

                    if ( Quit_Game == true )
                    {
                        return 0;
                    }
                }

                g_MenuTexture.Render(0, 0, g_Renderer);                                    //Vẽ hình ảnh giao diện Menu

                SDL_Rect* currentClip_Play = &g_PlayButton[PlayButton.currentSprite];     //Vẽ nút Play lên màn
                PlayButton.Render(currentClip_Play, g_Renderer, g_PlayButtonTexture);

                SDL_Rect* currentClip_Help = &g_HelpButton[HelpButton.currentSprite];      //Vẽ nút Help lên màn
                HelpButton.Render(currentClip_Help, g_Renderer, g_HelpButtonTexture);

                SDL_Rect* currentClip_Exit = &g_ExitButton[ExitButton.currentSprite];      //Vẽ nut Exit lên màn
                ExitButton.Render(currentClip_Exit, g_Renderer, g_ExitButtonTexture);

                SDL_RenderPresent(g_Renderer);    //Hiển thị tất cả những tha đổi được  vẽ lên màn
            }

                while ( Play_Again )
                {
                    //cout << 1;

                    srand(time(NULL));
                    int time = 0;
                    int score = 0;
                    int acceleration = 0;
                    int frame_Character = 0;         //các biến animation( có thể thay đổi)
                    int frame_Enemy = 0;
                    int frame_Apple = 0;
                    int frame_HealthBar = 0;
                    string highscore = GetHighScoreFromFile("Max.txt");  //Lấy điểm số cao nhất từ tệp và lưu vào biến

                    SDL_Event e;
                    Enemy enemy1(ON_GROUND_ENEMY);
                    Enemy enemy2(ON_GROUND_ENEMY);
                    Enemy enemy3(IN_AIR_ENEMY);
                    Apple apple;

                    Mix_PlayMusic(g_Music, IS_REPEATITIVE);

                    TaoKeThu(enemy1, enemy2, enemy3, g_EnemyClips , g_Renderer);

                    TaoQua(apple, g_AppleClips, g_Renderer);

                    int OffSetSpeed_Ground = BASE_OFFSET_SPEED;
                    //vector<double> OffSetSpeed_BackGround( BACKGROUND_LAYER, BASE_OFFSET_SPEED );
                    int OffSetSpeed_BackGround = BASE_OFFSET_SPEED;
                    bool Quit = false;
                    bool Game_State = true;



                    int HP = 100;
                    while ( !Quit )
                    {
                        if ( Game_State )
                        {
                            UpdateGameTimeAndScore(time, acceleration, score);
                            while ( SDL_PollEvent(&e) != 0 )        //xử lí sự kiện bằng SDL_PollEvent
                            {
                                if ( e.type == SDL_QUIT )
                                {
                                     Quit = true;
                                     Play_Again = false;
                                }
                                XuliPauseButton(e, g_Renderer, g_ContinueButton, PauseButton, ContinueButton,
                                              g_ContinueButtonTexture, Game_State, g_Click);
                                character.Event(e, g_Jump);
                            }

                        SDL_SetRenderDrawColor(g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(g_Renderer);

                        RenderScrollingBackgroud( OffSetSpeed_BackGround, acceleration, g_BackgroundTexture, g_Renderer );
                        RenderScrollingGroud( OffSetSpeed_Ground, acceleration, g_GroundTexture, g_Renderer );

                        character.DiChuyen();
                        SDL_Rect* currentClip_Character = nullptr;
                        if (character.TrenMatDat())
                        {
                            currentClip_Character = &g_CharacterClips [frame_Character / SLOW_FRAME_CHAR];
                            character.Render ( currentClip_Character, g_Renderer, g_CharacterTexture );
                        }
                        else
                        {
                            currentClip_Character = &g_CharacterClips[0];
                            character.Render ( currentClip_Character, g_Renderer, g_CharacterTexture );
                        }

                        SDL_Rect* currentClip_HealthBar = nullptr;
                        currentClip_HealthBar = &g_HealthBarClips[frame_HealthBar];
                        healthbar.Render(currentClip_HealthBar, g_Renderer, g_HealthBarTexture);

                        enemy1.Move(acceleration);
                        enemy1.Render(g_Renderer);

                        enemy2.Move(acceleration);
                        enemy2.Render(g_Renderer);

                        SDL_Rect* currentClip_Enemy = &g_EnemyClips[frame_Enemy / SLOW_FRAME_ENEMY];
                        enemy3.Move(acceleration);
                        enemy3.Render(g_Renderer, currentClip_Enemy);

                        SDL_Rect* currentClip_Apple = &g_AppleClips[frame_Apple];
                        apple.Move(acceleration);
                        apple.Render(g_Renderer, currentClip_Apple);

                        SDL_Rect* currentClip_Pause = &g_PauseButton[PauseButton.currentSprite];
                        PauseButton.Render(currentClip_Pause, g_Renderer, g_PauseButtonTexture);

                        DrawPlayerScore(g_Text1Texture, g_ScoreTexture, textColor, g_Renderer, g_Front, score);
                        DrawPlayerHighScore(g_Text2Texture, g_HighScoreTexture, textColor, g_Renderer, g_Front, highscore);

                        if (KiemtraVaChamKeThu( character, enemy1, enemy2, enemy3,
                                                 currentClip_Character, currentClip_Enemy))
                        {
                            HP = HP - 1;
                            cout << HP << endl;
                            Mix_PlayChannel( MIX_CHANNEL, g_Lose, NOT_REPEATITIVE );

                        }
                        else if( KiemtraVaChamHoiMau(character, apple, currentClip_Character, currentClip_Apple))
                        {
                            if ( (HP+1) <= 100 ) HP = HP + 1;
                            cout << HP << endl;
                            Mix_PlayChannel( MIX_CHANNEL, g_Lose, NOT_REPEATITIVE );
                        }
                        if ( HP <= -1 )
                        {
                            Mix_PauseMusic();
                            UpdateHighScore("Max.txt", score, highscore);
                            Quit = true;
                        }
                        SDL_RenderPresent(g_Renderer);

                        KiemsoatHP(frame_HealthBar, HP);
                        KiemsoatEch(frame_Character);
                        KiemsoatKeThu(frame_Enemy);
                        KiemsoatHoiMau(frame_Apple, KiemtraVaChamHoiMau(character, apple,
                                                                           currentClip_Character,
                                                                           currentClip_Apple), apple.GetPosX() );

                    }
                }
                DrawLuaChonEndGame(g_LoseTexture, &e, g_Renderer, Play_Again);
                if (!Play_Again)
                {
                    enemy1.~Enemy();
                    enemy2.~Enemy();
                    enemy3.~Enemy();
                    apple.~Apple();
                }
            }
        }
    }
    Close();
    return 0;
}

bool Init()
{
    bool success = true;
    if ( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_VIDEO ) < 0 )
    {
        LogError("Khong the khoi tao SDL", SDL_ERROR);
        success = false;
    }
    else
    {
        if ( !SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
           cout <<"Tinh nang loc ket cau chua duoc mo" << endl;
        }
        g_Window = SDL_CreateWindow( WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                     SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if ( g_Window == NULL )
        {
            LogError("Khong the tao cua so", SDL_ERROR);
            success = false;
        }
        else
        {
            g_Renderer = SDL_CreateRenderer( g_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if ( g_Renderer == NULL )
            {
                LogError("Khong the tao trinh ket xuat", SDL_ERROR);
                success = false;
            }
            else
            {
                SDL_SetRenderDrawColor( g_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);     // Cài đặt màu vẽ mặc đinh của Render thành màu trắng
                int imgFlags = IMG_INIT_PNG;
                if ( !(IMG_Init(imgFlags) & imgFlags))
                {
                    LogError("Khong the khoi tao SDL_Image", SDL_ERROR);
                    success = false;
                }
                if ( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
                {
                   cout << "SDL_Mixer khong the khoi tao : " << Mix_GetError() << endl;
                    success = false;
                }
                if ( TTF_Init() == -1 )
                {
                    cout << "SDL_ttf khong the khoi tao: " << TTF_GetError() << endl;
                    success = false;
                }
            }
        }
    }
    return success;
}

bool LoadMedia()        //Tải các tài nguyên cần thiết cho chương trình; hình ảnh, âm thanh, front chữ...
{
    bool success = true;
    g_Music = Mix_LoadMUS("wav/background.mp3");                         //Tải lên nhạc background
    if ( g_Music == nullptr )
    {
        LogError("Khong tai duoc nhac background", MIXER_ERROR);
        success = false;
    }

    g_MenuMusic = Mix_LoadMUS("wav/menu.wav");
    if ( g_MenuMusic == nullptr )
    {
        LogError("Khong tai duoc nhac menu", MIXER_ERROR );
        success = false;
    }

    g_Click = Mix_LoadWAV("wav/mouse.wav");
    if ( g_Click == nullptr )
    {
        LogError("Khong tai duoc nhac mouse", MIXER_ERROR );
        success = false;
    }

    g_Jump = Mix_LoadWAV("wav/jump.wav");
    if ( g_Jump == nullptr )
    {
        LogError("Khong tai duoc nhac jump", MIXER_ERROR );
        success = false;
    }

    g_Lose = Mix_LoadWAV("wav/lose.wav");
    if ( g_Lose == nullptr )
    {
        LogError("Khong tai duoc nhac lose", MIXER_ERROR );
        success = false;
    }
    else
    {
        g_Front = TTF_OpenFont("font/font.ttf", 24);
        g_Front2 = TTF_OpenFont("font/font.ttf", 36);
        if ( g_Front == NULL )
        {
            LogError("Khong load duoc font", MIXER_ERROR );
            success = false;
        }
        else
        {
            if(!g_Text1Texture.LoadFromRenderedTexture("Diem cua ban: ", g_Front, textColor, g_Renderer))
            {
                cout << "Khong the hien thi ket cau text1" << endl;
                success = false;
            }
            if(!g_Text2Texture.LoadFromRenderedTexture("Diem cao: ", g_Front, textColor, g_Renderer))
            {
                cout << "Khong the hien thi ket cau text2" << endl;
                success = false;
            }
            if (!g_Text3Texture.LoadFromRenderedTexture("HP: ", g_Front2, textColor2, g_Renderer))
            {
                cout << "Khong the hien thi ket cau text3" << endl;
                success = false;
            }
            if ( !g_MenuTexture.LoadFromFile("img/background/Menu.png", g_Renderer ))
            {
                cout << "Khong the hien thi menu.png" << endl;
                success = false;
            }
            if ( !g_InstructionTexture.LoadFromFile("img/background/guide.png", g_Renderer))
            {
                cout << "Khong the hien thi guide.png" << endl;
                success = false;
            }
            if ( !g_PlayButtonTexture.LoadFromFile("img/button/Play.png", g_Renderer))
            {
                cout << "Khong the hien thi nut Play" << endl;
                success = false;
            }
            else
            {
                for ( int i = 0; i< BUTTON_TOTAL; ++i)
                {
                    g_PlayButton[i].x = 238 * i;
                    g_PlayButton[i].y = 0;
                    g_PlayButton[i].w = 238;
                    g_PlayButton[i].h = 82;
                }
            }

            if ( !g_HelpButtonTexture.LoadFromFile("img/button/Help.png", g_Renderer))
            {
                cout << "Khong the hien thi nut Help" << endl;
                success = false;
            }
            else
            {
                for ( int i = 0; i < BUTTON_TOTAL; ++i)
                {
                    g_HelpButton[i].x = 238 * i;
                    g_HelpButton[i].y = 0;
                    g_HelpButton[i].w = 238;
                    g_HelpButton[i].h = 82;
                }
            }

            if ( !g_BackButtonTexture.LoadFromFile("img/button/Back.png", g_Renderer))
            {
                cout << "Khong the hien thi nut Back" << endl;
                success = false;
            }
            else
            {
               for ( int i = 0; i < BUTTON_TOTAL; ++i )
               {
                  g_BackButton[i].x = 67 * i;
                  g_BackButton[i].y = 0;
                  g_BackButton[i].w = 67;
                  g_BackButton[i].h = 76;
               }
            }

            if ( !g_ExitButtonTexture.LoadFromFile("img/button/Exit.png", g_Renderer))
            {
                cout << "Khong the hien thi nut exit" << endl;
                success = false;
            }
            else
            {
                for ( int i = 0; i < BUTTON_TOTAL; ++i)
                {
                    g_ExitButton[i].x = 238 * i;
                    g_ExitButton[i].y = 0;
                    g_ExitButton[i].w = 238;
                    g_ExitButton[i].h = 82;
                }
            }

            if (!g_PauseButtonTexture.LoadFromFile("img/button/Pause.png", g_Renderer))
            {
                cout << "Khong the hien thi nut Pause" << endl;
                success = false;
            }
            else
            {
                for ( int i = 0; i < BUTTON_TOTAL; ++i )
                {
                    g_PauseButton[i].x = 67 * i;
                    g_PauseButton[i].y = 0;
                    g_PauseButton[i].w = 67;
                    g_PauseButton[i].h = 76;
                }
            }

            if ( !g_ContinueButtonTexture.LoadFromFile("img/button/Continue.png", g_Renderer))
            {
                cout << "Khong the hien thi nut Continue" << endl;
                success = false;
            }
            else
            {
                for ( int i = 0; i < BUTTON_TOTAL; ++i )
                {
                    g_ContinueButton[i].x = 67 * i;
                    g_ContinueButton[i].y = 0;
                    g_ContinueButton[i].w = 67;
                    g_ContinueButton[i].h = 76;
                }
            }

 //          for (int i = 0; i < BACKGROUND_LAYER; ++i)
  //         {
               if ( !g_BackgroundTexture.LoadFromFile("img/background/Background.png", g_Renderer))
               {
                   cout << "Khong the hien thi background img" << endl;
                   success = false;
               }
  //         }

           if ( !g_GroundTexture.LoadFromFile("img/background/ground.png", g_Renderer))
           {
               cout << "Khong the hien thi Ground" << endl;
               success = false;
           }

           if (!g_CharacterTexture.LoadFromFile("img/ech/echrun.png", g_Renderer))
           {
               cout << "Khong the hien thi nhan vat ech" << endl;
               success = false;
           }
           else
           {
                g_CharacterClips[0].x = 103 * 0;
                g_CharacterClips[0].y = 0;
                g_CharacterClips[0].w = 103;
                g_CharacterClips[0].h = 110;

                g_CharacterClips[1].x = 103 * 1;
                g_CharacterClips[1].y = 0;
                g_CharacterClips[1].w = 103;
                g_CharacterClips[1].h = 110;

                g_CharacterClips[2].x = 103 * 2;
                g_CharacterClips[2].y = 0;
                g_CharacterClips[2].w = 103;
                g_CharacterClips[2].h = 110;

                g_CharacterClips[3].x = 103 * 3;
                g_CharacterClips[3].y = 0;
                g_CharacterClips[3].w = 103;
                g_CharacterClips[3].h = 110;

                g_CharacterClips[4].x = 103 * 4;
                g_CharacterClips[4].y = 0;
                g_CharacterClips[4].w = 103;
                g_CharacterClips[4].h = 110;

//                g_CharacterClips[5].x = 110 * 5;
//                g_CharacterClips[5].y = 0;
//                g_CharacterClips[5].w = 110;
//                g_CharacterClips[5].h = 85;
           }

           if ( !g_HealthBarTexture.LoadFromFile("img/hp/hp.png", g_Renderer))
           {
               cout << "Khong the hien thi thanh mau" << endl;
               success = false;
           }
           else
           {
               g_HealthBarClips[0].x = 0;
               g_HealthBarClips[0].y = 50 * 0;
               g_HealthBarClips[0].w = 245;
               g_HealthBarClips[0].h = 50;

               g_HealthBarClips[1].x = 0;
               g_HealthBarClips[1].y = 50 * 1;
               g_HealthBarClips[1].w = 245;
               g_HealthBarClips[1].h = 50;

               g_HealthBarClips[2].x = 0;
               g_HealthBarClips[2].y = 50 * 2;
               g_HealthBarClips[2].w = 245;
               g_HealthBarClips[2].h = 50;

               g_HealthBarClips[3].x = 0;
               g_HealthBarClips[3].y = 50 * 3;
               g_HealthBarClips[3].w = 245;
               g_HealthBarClips[3].h = 50;

               g_HealthBarClips[4].x = 0;
               g_HealthBarClips[4].y = 50 * 4;
               g_HealthBarClips[4].w = 245;
               g_HealthBarClips[4].h = 50;

               g_HealthBarClips[5].x = 0;
               g_HealthBarClips[5].y = 50 * 5;
               g_HealthBarClips[5].w = 245;
               g_HealthBarClips[5].h = 50;

               g_HealthBarClips[6].x = 0;
               g_HealthBarClips[6].y = 50 * 6;
               g_HealthBarClips[6].w = 245;
               g_HealthBarClips[6].h = 50;

               g_HealthBarClips[7].x = 0;
               g_HealthBarClips[7].y = 50 * 7;
               g_HealthBarClips[7].w = 245;
               g_HealthBarClips[7].h = 50;

               g_HealthBarClips[8].x = 0;
               g_HealthBarClips[8].y = 50 * 8;
               g_HealthBarClips[8].w = 245;
               g_HealthBarClips[8].h = 50;

               g_HealthBarClips[9].x = 0;
               g_HealthBarClips[9].y = 50 * 9;
               g_HealthBarClips[9].w = 245;
               g_HealthBarClips[9].h = 50;

               g_HealthBarClips[10].x = 0;
               g_HealthBarClips[10].y = 50 * 10;
               g_HealthBarClips[10].w = 245;
               g_HealthBarClips[10].h = 50;

               g_HealthBarClips[11].x = 0;
               g_HealthBarClips[11].y = 50 * 11;
               g_HealthBarClips[11].w = 245;
               g_HealthBarClips[11].h = 50;

               g_HealthBarClips[12].x = 0;
               g_HealthBarClips[12].y = 50 * 12;
               g_HealthBarClips[12].w = 245;
               g_HealthBarClips[12].h = 50;

               g_HealthBarClips[13].x = 0;
               g_HealthBarClips[13].y = 50 * 13;
               g_HealthBarClips[13].w = 245;
               g_HealthBarClips[13].h = 50;

               g_HealthBarClips[14].x = 0;
               g_HealthBarClips[14].y = 50 * 14;
               g_HealthBarClips[14].w = 245;
               g_HealthBarClips[14].h = 50;

               g_HealthBarClips[15].x = 0;
               g_HealthBarClips[15].y = 50 * 15;
               g_HealthBarClips[15].w = 245;
               g_HealthBarClips[15].h = 50;

               g_HealthBarClips[16].x = 0;
               g_HealthBarClips[16].y = 50 * 16;
               g_HealthBarClips[16].w = 245;
               g_HealthBarClips[16].h = 50;

               g_HealthBarClips[17].x = 0;
               g_HealthBarClips[17].y = 50 * 17;
               g_HealthBarClips[17].w = 245;
               g_HealthBarClips[17].h = 50;

               g_HealthBarClips[18].x = 0;
               g_HealthBarClips[18].y = 50 * 18;
               g_HealthBarClips[18].w = 245;
               g_HealthBarClips[18].h = 50;

               g_HealthBarClips[19].x = 0;
               g_HealthBarClips[19].y = 50 * 19;
               g_HealthBarClips[19].w = 245;
               g_HealthBarClips[19].h = 50;

               g_HealthBarClips[20].x = 0;
               g_HealthBarClips[20].y = 50 * 20;
               g_HealthBarClips[20].w = 245;
               g_HealthBarClips[20].h = 50;

               g_HealthBarClips[21].x = 0;
               g_HealthBarClips[21].y = 50 * 21;
               g_HealthBarClips[21].w = 245;
               g_HealthBarClips[21].h = 50;

               g_HealthBarClips[22].x = 0;
               g_HealthBarClips[22].y = 50 * 22;
               g_HealthBarClips[22].w = 245;
               g_HealthBarClips[22].h = 50;

               g_HealthBarClips[23].x = 0;
               g_HealthBarClips[23].y = 50 * 23;
               g_HealthBarClips[23].w = 245;
               g_HealthBarClips[23].h = 50;

               g_HealthBarClips[24].x = 0;
               g_HealthBarClips[24].y = 50 * 24;
               g_HealthBarClips[24].w = 245;
               g_HealthBarClips[24].h = 50;

               g_HealthBarClips[25].x = 0;
               g_HealthBarClips[25].y = 50 * 25;
               g_HealthBarClips[25].w = 245;
               g_HealthBarClips[25].h = 50;

               g_HealthBarClips[26].x = 0;
               g_HealthBarClips[26].y = 50 * 26;
               g_HealthBarClips[26].w = 245;
               g_HealthBarClips[26].h = 50;
           }

           if (!g_LoseTexture.LoadFromFile("img/background/lose.png", g_Renderer))
           {
               cout << "Khong the hien thi Lose" << endl;
               success = false;
           }
        }
    }
    return success;
}

void Close()
{    //Giải phong các Texture.
    g_MenuTexture.Free();
    g_InstructionTexture.Free();
    g_CharacterTexture.Free();
    g_GroundTexture.Free();

    g_PlayButtonTexture.Free();
    g_ExitButtonTexture.Free();
    g_PauseButtonTexture.Free();
    g_HelpButtonTexture.Free();
    g_BackButtonTexture.Free();
    g_ContinueButtonTexture.Free();

    g_LoseTexture.Free();
    g_Text1Texture.Free();
    g_ScoreTexture.Free();
    g_Text2Texture.Free();
    g_HighScoreTexture.Free();
    g_Text3Texture.Free();
    g_HPTexture.Free();

//    for ( int i = 0; i < BACKGROUND_LAYER; ++i)
//    {
        g_BackgroundTexture.Free();
//    }

    Mix_FreeMusic(g_Music);
    Mix_FreeMusic(g_MenuMusic);
    Mix_FreeChunk(g_Click);
    Mix_FreeChunk(g_Lose);
    Mix_FreeChunk(g_Jump);

    g_Music = nullptr;
    g_MenuMusic = nullptr;
    g_Click = nullptr;
    g_Lose = nullptr;
    g_Jump = nullptr;

    SDL_DestroyRenderer(g_Renderer);
    g_Renderer = nullptr;

    SDL_DestroyWindow(g_Window);
    g_Window = nullptr;

    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}
