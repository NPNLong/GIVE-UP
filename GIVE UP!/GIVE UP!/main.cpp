#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "graphics.h"
#include "defs.h"
#include "mouse.h"
#include "game.h"
#include "effects.h"
#include "player.h"
#include "stage.h"
#include "obstacles.h"

using namespace std;

int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    Mix_Music *gMusic = graphics.loadMusic("Sound\\bgm\\Gametime.mp3");
    Mix_Music *gM;
    gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");

    graphics.play(gMusic);
    Mix_VolumeMusic(MUSIC_VOL);

    Mix_Chunk *menuSelect = graphics.loadSound("Sound\\sfx\\menuselect.wav");
    Mix_Chunk *menuChoose = graphics.loadSound("Sound\\sfx\\menuchoose.wav");
    Mix_Chunk *stageSound;

    intro(graphics);

    Mouse mouse;
    mouse.createMouse(graphics);

    Player player;
    player.createPlayer(graphics);

    SDL_Texture *mn = graphics.loadTexture("Image\\Menu\\Menu.png");
    SDL_Texture *mg;

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));

    bool quit = false;

    int countmenu = 1;
    int options = 1;
    bool playSound = true;//menu
    bool ingame = false;//da vao game hay khong(menu/level)
    int difficult = 0;

    bool oneMenu = true;//tranh lap menu
    bool oneStage = true;//tranh lap level

    int stage = 1;//man dang choi

    bool oneLevel = 1;//tranh lap 1 level
    bool onePause = 1;//tranh lap pause
    bool end = 0;//ending

    bool pauseGame = 0;//pause game

    float time = 0;//tgian no bom
    bool safe = 1; //tru an
    float mul; //tang do kho

    list<Obstacle> obs;//list chuong ngai vat
    Obstacle obstacle;

    vector<Alien> aln;//list chuong ngai vat chuyen dong
    Alien alien;
    alien.createAlien(graphics);

    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }

        if(!ingame){//menu

            if(oneMenu){
                graphics.play(gMusic);

                mouse.in = 0;

                countmenu = 1;

                playSound = true;//menu
                ingame = false;//da vao game hay khong(menu/level)
                difficult = 0;

                oneMenu = 0;
            }

            SDL_RenderClear(graphics.renderer);

            background.scroll(1);
            graphics.render(background);

            if (!end){
            menu(mn, graphics, mouse, e, countmenu, quit, playSound, ingame, options, difficult, menuSelect, menuChoose);
            }

            else{
                ending(mn, graphics, mouse, e, countmenu, end, playSound, ingame, menuSelect);
            }

            mouse.draw(graphics);//Chuột luôn phải để cuối

            if(ingame){
                SDL_RenderClear(graphics.renderer);
            }

            graphics.presentScene();
        }

        else{//vao game

            if(oneStage){
                //graphics.play(gM);
                oneStage = 0;

                if (difficult==1){
                    player.speed = 2;
                    player.health = 5;
                    mul = 1;
                }
                else if (difficult==2){
                    stage = 1;
                    player.speed = 3;
                    player.health = 3;
                    mul = 2;
                }
                else{
                    stage = 1;
                    player.speed = 4;
                    player.health = 2;
                    mul = 3;
                }
            }

            if(oneLevel){//tao chuong ngai vat

                player.dx = 0; player.dy = 0;
                player.character = graphics.loadTexture("Image\\Player 1.png");

                if (stage == 1){

                player.grax = 0;
                player.gray = 0;

                Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");

                SDL_DestroyTexture(alien.alien);
                alien.alien = graphics.loadTexture("Image\\Stage\\Alien.png");

                        obs.clear();
                        aln.clear();

                obstacle.createObstacle(69,244,1195,320);
                obs.push_front(obstacle);

                obstacle.createObstacle(1123,316,1194,598);
                obs.push_front(obstacle);

                obstacle.createObstacle(1122,526,175,596);
                obs.push_front(obstacle);

                obstacle.createObstacle(247,526,175,384);
                obs.push_front(obstacle);

                obstacle.createObstacle(246,456,1052,384);
                obs.push_front(obstacle);

                //alien.spawnPlayer(graphics, 100, 200, 100, 300, 4, 1, 0);
               // aln.push_back(alien);

                }

                else if (stage == 2){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");
                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = 0;

                obs.clear();
                aln.clear();

                obstacle.createObstacle(1298, 698,1365, 242);
                obs.push_front(obstacle);

                obstacle.createObstacle(1192, 598,70, 488);
                obs.push_front(obstacle);

                obstacle.createObstacle(174, 244,1298, 389);
                obs.push_front(obstacle);

                obstacle.createObstacle(280, 388,387, 422);
                obs.push_front(obstacle);

                obstacle.createObstacle(701, 389,809, 423);
                obs.push_front(obstacle);

                obstacle.createObstacle(490, 453,597, 488);
                obs.push_front(obstacle);

                obstacle.createObstacle(912, 452,1019, 488);
                obs.push_front(obstacle);
                }

                else if (stage == 3){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");
                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = 0;

                obs.clear();
                aln.clear();

                obstacle.createObstacle(173, 145,1363, 597);
                obs.push_front(obstacle);

                obstacle.createObstacle(123, 246,171, 350);
                obs.push_front(obstacle);

                obstacle.createObstacle(70, 493,120, 596);
                obs.push_front(obstacle);

                for(int i=0; i<5; i++){
                obstacle.createObstacle(245+i*211, 598,280+i*211, 650);
                obs.push_front(obstacle);

                obstacle.createObstacle(351+i*211, 648,385+i*211, 697);
                obs.push_front(obstacle);
                }
                }

                else if (stage == 4){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");
                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = 0;

                obstacle.createObstacle(1051, 491,1123, 631);
                obs.push_front(obstacle);

                obstacle.createObstacle(314, 244,245, 385);
                obs.push_front(obstacle);

                obstacle.createObstacle(246, 491,316, 627);
                obs.push_front(obstacle);

                obstacle.createObstacle(1051, 246,1118, 388);
                obs.push_front(obstacle);

                for (int i=0; i<5; i++){
                alien.spawnPlayer(graphics, 369+4*i*34.5, 268, 369+4*i*34.5, 615, 2*mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 369+(4*i+2)*34.5, 615, 369+(4*i+2)*34.5, 268, 2*mul, 1, 1);
                aln.push_back(alien);
                }
            }

                else if (stage == 5){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");

                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = 0;

                obstacle.createObstacle(318, 146,249, 214);
                obs.push_front(obstacle);

                obstacle.createObstacle(317, 278,249, 353);
                obs.push_front(obstacle);

                obstacle.createObstacle(249, 418,317, 486);
                obs.push_front(obstacle);

                obstacle.createObstacle(384, 146,1189, 216);
                obs.push_front(obstacle);

                obstacle.createObstacle(388, 280,1192, 353);
                obs.push_front(obstacle);

                obstacle.createObstacle(1054, 420,386, 488);
                obs.push_front(obstacle);

                obstacle.createObstacle(1121, 418,1192, 630);
                obs.push_front(obstacle);

                obstacle.createObstacle(239, 490,1055, 630);
                obs.push_front(obstacle);

                alien.spawnPlayer(graphics, 352, 478, 352, 153, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 737, 216, 737, 699, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1184, 386, 807, 386, mul, 0, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1184, 663, 742, 663, mul, 0, 0);
                aln.push_back(alien);
            }

            else if (stage == 6){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");

                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = 0;

                obstacle.createObstacle(106, 143,33, 350);
                obs.push_front(obstacle);

                obstacle.createObstacle(35, 456,108, 664);
                obs.push_front(obstacle);

                obstacle.createObstacle(212, 145,316, 316);
                obs.push_front(obstacle);

                obstacle.createObstacle(419, 145,529, 246);
                obs.push_front(obstacle);

                obstacle.createObstacle(843, 145,948, 246);
                obs.push_front(obstacle);

                obstacle.createObstacle(1054, 145,1161, 316);
                obs.push_front(obstacle);

                obstacle.createObstacle(212, 492,316, 663);
                obs.push_front(obstacle);

                obstacle.createObstacle(419, 562,529, 663);
                obs.push_front(obstacle);

                obstacle.createObstacle(843, 563,948, 663);
                obs.push_front(obstacle);

                obstacle.createObstacle(1054, 492,1161, 663);
                obs.push_front(obstacle);

                obstacle.createObstacle(211, 386,316, 421);
                obs.push_front(obstacle);

                obstacle.createObstacle(421, 318,527, 490);
                obs.push_front(obstacle);

                obstacle.createObstacle(633, 211,737, 595);
                obs.push_front(obstacle);

                obstacle.createObstacle(845, 317,948, 491);
                obs.push_front(obstacle);

                obstacle.createObstacle(1055, 387,1159, 421);
                obs.push_front(obstacle);

                obstacle.createObstacle(1336, 454,1265, 663);
                obs.push_front(obstacle);

                obstacle.createObstacle(1262, 146,1335, 352);
                obs.push_front(obstacle);

                for(int i=0; i<3; i++){
                alien.spawnPlayer(graphics, 123+6*i*35, 649, 123+6*i*35, 163, 2*mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 192+6*i*35, 163, 192+6*i*35, 649, 2*mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 752+6*i*35, 163, 752+6*i*35, 649, 2*mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 821+6*i*35, 649, 821+6*i*35, 163, 2*mul, 1, 1);
                aln.push_back(alien);
                }
            }

            else if (stage == 7){

                Mix_FreeMusic(gM);
                player.grax = 1;
                player.gray = 0;

                SDL_DestroyTexture(alien.alien);
                alien.alien = graphics.loadTexture("Image\\Stage\\Alien2.png");

                gM = graphics.loadMusic("Sound\\bgm\\Surface.mp3");
                obs.clear();
                aln.clear();

                obstacle.createObstacle(175, 245,282, 698);
                obs.push_front(obstacle);

                obstacle.createObstacle(385, 145,492, 596);
                obs.push_front(obstacle);

                obstacle.createObstacle(634, 246,740, 699);
                obs.push_front(obstacle);

                obstacle.createObstacle(875, 144,982, 595);
                obs.push_front(obstacle);

                obstacle.createObstacle(1086, 245,1192, 698);
                obs.push_front(obstacle);

                for(int i=0; i<1; i++){
                alien.spawnPlayer(graphics, 509+2*i*35, 683, 509+2*i*35, 163, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 544+2*i*35, 683, 544+2*i*35, 163, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 579+2*i*35, 163, 579+2*i*35, 683, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 614+2*i*35, 163, 614+2*i*35, 683, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 755+2*i*35, 163, 755+2*i*35, 683, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 788+2*i*35, 163, 788+2*i*35, 683, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 825+2*i*35, 683, 825+2*i*35, 163, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 858+2*i*35, 683, 858+2*i*35, 163, mul, 1, 1);
                aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 87, 440, 1276, 440, 2*mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1276, 193, 87, 193, 2*mul, 0, 0);
                aln.push_back(alien);

            }

            else if (stage == 8){

                player.grax = 1;
                player.gray = 0;

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\Surface.mp3");
                obs.clear();
                aln.clear();

                for(int i=0; i<5; i++){
                alien.spawnPlayer(graphics, 190+7*i*35, 579, 190+7*i*35, 689, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 190+7*i*35, 265, 190+7*i*35, 155, mul, 1, 1);
                aln.push_back(alien);

                }

                alien.spawnPlayer(graphics, 87, 474, 1276, 474, 3*mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1276, 439, 87, 439, 3*mul, 0, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 87, 404, 1276, 404, 3*mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1276, 369, 87, 369, 3*mul, 0, 0);
                aln.push_back(alien);
            }

            else if (stage == 9){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\Surface.mp3");

                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = -1;

                obstacle.createObstacle(105, 141,35, 349);
                obs.push_front(obstacle);

                obstacle.createObstacle(37, 492,105, 696);
                obs.push_front(obstacle);

                obstacle.createObstacle(211, 387,316, 698);
                obs.push_front(obstacle);

                obstacle.createObstacle(420, 453,528, 700);
                obs.push_front(obstacle);

                obstacle.createObstacle(632, 422,738, 699);
                obs.push_front(obstacle);

                obstacle.createObstacle(843, 598,946, 701);
                obs.push_front(obstacle);

                obstacle.createObstacle(1054, 315,1157, 701);
                obs.push_front(obstacle);

                obstacle.createObstacle(212, 144,317, 317);
                obs.push_front(obstacle);

                obstacle.createObstacle(422, 147,527, 385);
                obs.push_front(obstacle);

                obstacle.createObstacle(632, 146,737, 351);
                obs.push_front(obstacle);

                obstacle.createObstacle(843, 145,949, 527);
                obs.push_front(obstacle);

                obstacle.createObstacle(1052, 143,1159, 245);
                obs.push_front(obstacle);

                obstacle.createObstacle(1264, 144,1336, 350);
                obs.push_front(obstacle);

                obstacle.createObstacle(1336, 492,1264, 701);
                obs.push_front(obstacle);

                for(int i=0; i<6; i++){
                alien.spawnPlayer(graphics, 123+6*i*35, 684, 123+6*i*35, 163, 2*mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 192+6*i*35, 684, 192+6*i*35, 163, 2*mul, 1, 1);
                aln.push_back(alien);
                }


            }

            else if (stage == 10){
                obs.clear();
                aln.clear();

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\Surface.mp3");

                player.grax = -1;
                player.gray = 0;

                obstacle.createObstacle(774, 245,1193, 595);
                obs.push_front(obstacle);

                obstacle.createObstacle(177, 281,665, 349);
                obs.push_front(obstacle);

                obstacle.createObstacle(177, 492,665, 560);
                obs.push_front(obstacle);

                for(int i=0; i<16; i++){
                alien.spawnPlayer(graphics, 86+2*i*35, 684, 86+i*35*2, 163, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 121+2*i*35, 163, 121+i*35*2, 684, mul, 1, 0);
                aln.push_back(alien);
                }

                /*for(int i=9; i<16; i++){
                alien.spawnPlayer(graphics, 86+2*i*35, 684, 86+i*35*2, 163, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 121+2*i*35, 163, 121+i*35*2, 684, mul, 1, 0);
                aln.push_back(alien);
                }*/

                for(int i=0; i<6; i++){
                alien.spawnPlayer(graphics, 87, 614-35*i*2, 1276, 614-35*i*2, 2*mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1276, 579- 35*i*2, 87, 579- 35*i*2, 2*mul, 0, 0);
                aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 1276, 159, 87, 159, 2*mul, 0, 0);
                aln.push_back(alien);

            }

            else if (stage == 11){

                Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\Nuclear-Fusion-REDUX.mp3");

                SDL_DestroyTexture(alien.alien);
                alien.alien = graphics.loadTexture("Image\\Stage\\Alien3.png");

                        obs.clear();
                        aln.clear();

                player.grax = 0;
                player.gray = 1;

                obstacle.createObstacle(67, 560,671, 700);
                obs.push_front(obstacle);

                obstacle.createObstacle(772, 244,175, 456);
                obs.push_front(obstacle);

                obstacle.createObstacle(1298, 314,736, 596);
                obs.push_front(obstacle);

                for(int i=0; i<39; i++){
                    alien.spawnPlayer(graphics, 17+i*35, 3350 - (mul-1)*300, 17+i*35, 0, 1, 1, 1);
                aln.push_back(alien);
                }

                for(int i=0; i<3; i++){
                    alien.spawnPlayer(graphics, 1174-140*i, 684, 1174-140*i, 684, 0, 1, 1);
                    aln.push_back(alien);

                    alien.spawnPlayer(graphics, 1104-140*i, 614, 1104-140*i, 614, 0, 1, 1);
                    aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 1174-140*3, 684, 1174-140*3, 684, 0, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 719, 690, 719, 540, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 684, 690, 684, 540, mul, 1, 1);
                aln.push_back(alien);

                for(int i=0; i<3; i++){
                    alien.spawnPlayer(graphics, 614-140*i, 474, 614-140*i, 474, 0, 1, 1);
                    aln.push_back(alien);

                    alien.spawnPlayer(graphics, 579-140*i, 544, 579-140*i, 544, 0, 1, 1);
                    aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 614-140*3, 474, 614-140*3, 474, 0, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 81, 439, 162, 439, 1, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 162, 264, 81, 264, 1, 0, 0);
                aln.push_back(alien);

                for(int i=0; i<4; i++){
                    alien.spawnPlayer(graphics, 193+140*i, 230, 193+140*i, 230, 0, 1, 1);
                    aln.push_back(alien);

                    alien.spawnPlayer(graphics, 263+140*i, 160, 263+140*i, 160, 0, 1, 1);
                    aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 789, 264, 1280, 264, mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 789, 299, 1280, 299, mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1280, 159, 789, 159, mul, 0, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1280, 194, 789, 194, mul, 0, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1280, 229, 789, 229, mul, 0, 0);
                aln.push_back(alien);

            }

            else if (stage == 12){

                //Mix_FreeMusic(gM);
                gM = graphics.loadMusic("Sound\\bgm\\Nuclear-Fusion-REDUX.mp3");

                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = -1;

                obstacle.createObstacle(350, 279,174, 352);
                obs.push_front(obstacle);

                obstacle.createObstacle(773, 279,418, 351);
                obs.push_front(obstacle);

                obstacle.createObstacle(841, 279,1299, 351);
                obs.push_front(obstacle);

                obstacle.createObstacle(349, 316,418, 350);
                obs.push_front(obstacle);

                obstacle.createObstacle(773, 315,842, 351);
                obs.push_front(obstacle);

                obstacle.createObstacle(282, 403,385, 438);
                obs.push_front(obstacle);

                obstacle.createObstacle(564, 403,665, 438);
                obs.push_front(obstacle);

                obstacle.createObstacle(842, 457,1191, 595);
                obs.push_front(obstacle);

                obstacle.createObstacle(69, 492,210, 629);
                obs.push_front(obstacle);

                obstacle.createObstacle(280, 492,492, 630);
                obs.push_front(obstacle);

                obstacle.createObstacle(560, 491,774, 630);
                obs.push_front(obstacle);

                obstacle.createObstacle(209, 524,278, 596);
                obs.push_front(obstacle);

                obstacle.createObstacle(493, 527,561, 596);
                obs.push_front(obstacle);

                for(int i=0; i<5; i++){
                obstacle.createObstacle(1154-211*i, 210,1197-211*i, 279);
                obs.push_front(obstacle);

                obstacle.createObstacle(1049-211*i, 145,1092-211*i, 213);
                obs.push_front(obstacle);
                }

                for(int i=0; i<39; i++){
                    alien.spawnPlayer(graphics, 17+i*35, -8500 + mul*500, 17+i*35, 1366, 1, 1, 0);
                    aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 1225, 176, 211, 176, mul, 0, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 211, 246, 1225, 246, mul, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 87, 155, 87, 680, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 122, 680, 122, 155, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 157, 155, 157, 680, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 437, 369, 437, 476, 1, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 507, 476, 507, 369, 1, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 790, 510, 790, 370, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 825, 510, 825, 370, mul, 1, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 790, 580, 790, 686, mul, 1, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 825, 580, 825, 686, mul, 1, 0);
                aln.push_back(alien);

                for (int i=0; i<2; i++){
                alien.spawnPlayer(graphics, 858, 615-7*i*35, 1173, 615-7*i*35, 1, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 858, 685-7*i*35, 1173, 685-7*i*35, 1, 0, 1);
                aln.push_back(alien);
                }

                alien.spawnPlayer(graphics, 1208, 473, 1282, 473, 1, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 1282, 581, 1208, 581, 1, 0, 0);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 403, 650, 578, 650, 2*mul-1, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 403, 685, 578, 685, 2*mul-1, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 193, 650, 368, 650, 2*mul-1, 0, 1);
                aln.push_back(alien);

                alien.spawnPlayer(graphics, 193, 685, 368, 685, 2*mul-1, 0, 1);
                aln.push_back(alien);


            }

            else {
                obs.clear();
                aln.clear();

                player.grax = 0;
                player.gray = 0;

                obstacle.createObstacle(384, 402,456, 488);
                obs.push_front(obstacle);

                obstacle.createObstacle(524, 353,598, 441);
                obs.push_front(obstacle);

                obstacle.createObstacle(647, 402,720, 488);
                obs.push_front(obstacle);

                obstacle.createObstacle(771, 354,843, 440);
                obs.push_front(obstacle);

                obstacle.createObstacle(911, 402,984, 489);
                obs.push_front(obstacle);

                obstacle.createObstacle(1052, 352,1120, 388);
                obs.push_front(obstacle);

                obstacle.createObstacle(1051, 455,1123, 493);
                obs.push_front(obstacle);

            }

            }

            const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

            if (currentKeyStates[SDL_SCANCODE_ESCAPE]){
                pauseGame = 1;
            }

            //ham show mau, do kho
            //mode(graphics, difficult, mg);//rat lagggg
            //health(graphics, player, mg);

            if(!pauseGame){//check xem co pausegame khong

            if (stage == 1){
                    stage1(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 2){
                stage2(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 3){
                stage3(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 4){
                stage4(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 5){
                stage5(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 6){
                stage6(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 7){
                stage7(oneLevel, graphics, player, mn, gM, stage, stageSound);
            }
            else if (stage == 8){
                stage8(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 9){
                stage9(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 10){
                stage10(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 11){
                stage11(oneLevel, graphics, player, mn, gM, stage);
            }
            else if (stage == 12){
                stage12(oneLevel, graphics, player, mn, gM, stage, stageSound, mul, time, safe, ingame, oneMenu, oneStage, end, playSound);
            }
            else {
                stage12s(oneLevel, graphics, player, mn, stageSound, stage, mul, ingame, oneMenu, oneStage, end);
            }

            if(time<1200){
                for(int i=0; i<aln.size();i++){//check va cham

                aln[i].move();
                aln[i].update();
                aln[i].draw(graphics);
                //aln[i].render(graphics);

                //cout << aln[i].rect.x <<' ' <<aln[i].rect.y<<' '<<aln[i].speed<<' '<<aln[i].c<<' ';

                if (collision(aln[i].rect,player.rect)){
                        player.health --;
                        death(graphics, mn, player, oneLevel);
                }
                }
            }

            control(player);//dieu khien nhan vat
            player.draw(graphics);

            for(auto i : obs){//check va cham
                //i.render(graphics);
                if (collision(player.rect,i.rect)){
                        player.health --;
                        death(graphics, mn, player, oneLevel);
                }
            }
               if(player.health==0){//gameover
                gameOver(graphics, mn, player, ingame);
                oneMenu = 1;
                oneStage = 1;
               }

               if (end == 1){
                SDL_RenderClear(graphics.renderer);
                mn = graphics.loadTexture("Image\\Intro\\Intro 7.png");
                graphics.prepareImg(mn);
               }
            }

            else{
            if(onePause){
                countmenu = 1;

                playSound = true;//menu

                onePause = 0;
            }

            SDL_RenderClear(graphics.renderer);

            background.scroll(1);
            graphics.render(background);

            pauseMenu(mn, graphics, mouse, e, countmenu, pauseGame, playSound, ingame, oneMenu, oneLevel, oneStage, options, menuSelect, menuChoose);

            mouse.draw(graphics);//Chuột luôn phải để cuối

            }

            //mouse.draw(graphics);//Chuột luôn phải để cuối

            graphics.presentScene();
        }

        SDL_Delay(5);
    }

    SDL_DestroyTexture( background.texture );
    graphics.quit();
    return 0;
}
