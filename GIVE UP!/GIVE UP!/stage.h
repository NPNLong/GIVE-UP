#ifndef _STAGE__H
#define _STAGE__H

#include <cmath>
#include <list>
#include "game.h"

using namespace std;

void stage1(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        gM = graphics.loadMusic("Sound\\bgm\\TravelingTheGalaxy.mp3");
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\1.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 110, 180);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\1.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>249 && player.rect.x+player.rect.w<315 && player.rect.y>459 && player.rect.y+player.rect.h<525){
        stageComplete(graphics, player);
        stage++;
        player.dx = 0; player.dy = 0;
        onelevel = 1;
    }

    else if(player.rect.x>69 && player.rect.x+player.rect.w<1299 && player.rect.y>144 && player.rect.y+player.rect.h<698){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\1.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage2(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\2.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 109, 636);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\2.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>1332 && player.rect.x+player.rect.w<1366 && player.rect.y>147 && player.rect.y+player.rect.h<242){
        stageComplete(graphics, player);
        stage++;
        player.dx = 0; player.dy = 0;
        onelevel = 1;
    }

    else if(player.rect.x>70 && player.rect.x+player.rect.w<1364 && player.rect.y>146 && player.rect.y+player.rect.h<697){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\2.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage3(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\3.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 107, 178);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\3.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>1332 && player.rect.x+player.rect.w<1366 && player.rect.y>597 && player.rect.y+player.rect.h<696){
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if(player.rect.x>70 && player.rect.x+player.rect.w<1364 && player.rect.y>144 && player.rect.y+player.rect.h<697){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\3.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage4(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\4.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 1059, 428);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\4.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>245 && player.rect.x+player.rect.w<282 && player.rect.y>387&& player.rect.y+player.rect.h<491){
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if(player.rect.x>244 && player.rect.x+player.rect.w<1123 && player.rect.y>244 && player.rect.y+player.rect.h<631){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\4.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage5(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\5.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 1143, 233);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\5.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>248 && player.rect.x+player.rect.w<315 && player.rect.y>632&& player.rect.y+player.rect.h<700){
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if(player.rect.x>244 && player.rect.x+player.rect.w<1192 && player.rect.y>146 && player.rect.y+player.rect.h<700){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\5.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage6(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\6.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 56, 391);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\6.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>1262 && player.rect.x+player.rect.w<1334 && player.rect.y>352&& player.rect.y+player.rect.h<453){
        Mix_FadeOutMusic(2000);
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if(player.rect.x>30 && player.rect.x+player.rect.w<1334 && player.rect.y>141 && player.rect.y+player.rect.h<667){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\6.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage7(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage, Mix_Chunk *stageSound){
    if (onelevel){

        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.0.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        graphics.play(gM);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.0.1.png");
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(1300);

        SDL_DestroyTexture(mn);
        graphics.play(gM);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.0.2.png");
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(1134);

        SDL_DestroyTexture(mn);
        graphics.play(gM);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.1.png");
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(1134);

        player.spawnPlayer(graphics, 109, 637);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(1534);

        SDL_DestroyTexture(mn);
        stageSound = graphics.loadSound("Sound\\sfx\\Falling.wav");
        graphics.play(stageSound);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.2.1.png");
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2268);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>1192 && player.rect.x+player.rect.w<1299 && player.rect.y>633&& player.rect.y+player.rect.h<698){
        Mix_FreeChunk(stageSound);
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if(player.rect.x>66 && player.rect.x+player.rect.w<1299 && player.rect.y>142 && player.rect.y+player.rect.h<700){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\7.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage8(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\8.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 108, 635);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\8.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>632 && player.rect.x+player.rect.w<736 && player.rect.y>388&& player.rect.y+player.rect.h<456){
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if((player.rect.x>70 && player.rect.x+player.rect.w<1298 && player.rect.y>597 && player.rect.y+player.rect.h<697)
            ||(player.rect.x>68 && player.rect.x+player.rect.w<346 && player.rect.y>317&& player.rect.y+player.rect.h<524)
            ||(player.rect.x>526 && player.rect.x+player.rect.w<841 && player.rect.y>317&& player.rect.y+player.rect.h<524)
            ||(player.rect.x>1017 && player.rect.x+player.rect.w<1298 && player.rect.y>319&& player.rect.y+player.rect.h<525)
            ||(player.rect.x>68 && player.rect.x+player.rect.w<1299 && player.rect.y>143&& player.rect.y+player.rect.h<245)){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\8.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    if(player.rect.x>1260 && player.rect.x+player.rect.w<1296 && player.rect.y>598&& player.rect.y+player.rect.h<698){
        player.rect.x =1145;
        player.rect.y =325;

        player.dx=0;
        player.dy=player.speed;
    }

    else if(player.rect.x>1123 && player.rect.x+player.rect.w<1193 && player.rect.y>319&& player.rect.y+player.rect.h<355){
        player.rect.x =1256;
        player.rect.y =634;

        player.dy=0;
        player.dx=-player.speed;
    }

    else if(player.rect.x>1123 && player.rect.x+player.rect.w<1193 && player.rect.y>485&& player.rect.y+player.rect.h<523){
        player.rect.x =1256;
        player.rect.y =178;

        player.dy=0;
        player.dx=-player.speed;
    }

    else if(player.rect.x>1261 && player.rect.x+player.rect.w<1296 && player.rect.y>146&& player.rect.y+player.rect.h<244){
        player.rect.x =1145;
        player.rect.y =486;

        player.dx=0;
        player.dy=-player.speed;
    }

    else if(player.rect.x>70 && player.rect.x+player.rect.w<105 && player.rect.y>146&& player.rect.y+player.rect.h<244){
        player.rect.x =198;
        player.rect.y =486;

        player.dx=0;
        player.dy=-player.speed;
    }

    else if(player.rect.x>176 && player.rect.x+player.rect.w<246 && player.rect.y>485&& player.rect.y+player.rect.h<523){
        player.rect.x =78;
        player.rect.y =178;

        player.dy=0;
        player.dx=player.speed;
    }

    else if(player.rect.x>176 && player.rect.x+player.rect.w<246 && player.rect.y>319&& player.rect.y+player.rect.h<354){
        player.rect.x =670;
        player.rect.y =330;

        player.dx=0;
        player.dy=player.speed;
    }

    else if(player.rect.x>668 && player.rect.x+player.rect.w<702 && player.rect.y>319&& player.rect.y+player.rect.h<354){
        player.rect.x =200;
        player.rect.y =330;

        player.dx=0;
        player.dy=player.speed;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage9(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\9.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 57, 407);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\9.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>1262 && player.rect.x+player.rect.w<1334 && player.rect.y>352&& player.rect.y+player.rect.h<491){
        stageComplete(graphics, player);
        stage++;
        onelevel = 1;
    }

    else if(player.rect.x>30 && player.rect.x+player.rect.w<1334 && player.rect.y>141 && player.rect.y+player.rect.h<702){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\9.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
        player.dx = 0; player.dy = 0;
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage10(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){
        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\10.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 1232, 635);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\10.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>69 && player.rect.x+player.rect.w<140 && player.rect.y>145 && player.rect.y+player.rect.h<212){
        Mix_FadeOutMusic(2000);
        stageComplete(graphics, player);
        stage++;
        player.dx = 0; player.dy = 0;
        onelevel = 1;
    }

    else if(player.rect.x>69 && player.rect.x+player.rect.w<1299 && player.rect.y>144 && player.rect.y+player.rect.h<698){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\10.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage11(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage){
    if (onelevel){

        mn = graphics.loadTexture("Image\\Stage\\Stage\\11.0.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        graphics.play(gM);
        player.spawnPlayer(graphics, 1232, 635);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\11.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(3200);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>1228 && player.rect.x+player.rect.w<1298 && player.rect.y>246 && player.rect.y+player.rect.h<314){
        stageComplete(graphics, player);
        stage++;
        player.dx = 0; player.dy = 0;
        onelevel = 1;
    }

    else if(player.rect.x>69 && player.rect.x+player.rect.w<1299 && player.rect.y>144 && player.rect.y+player.rect.h<698){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\11.1.png");
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage12(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Music *gM, int &stage, Mix_Chunk *stageSound, int mul, float &time, bool &safe, bool &ingame, bool &oneMenu, bool &oneStage, bool &end, bool &playSound){
    if (onelevel){
        time = 0;// thoigian bom no

        graphics.play(gM);

        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.1.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 1232, 215);//1232, 215  200, 650
        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.2.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_DestroyTexture(mn);
        stageSound = graphics.loadSound("Sound\\sfx\\NuclearAlarm.mp3");
        graphics.play(stageSound);
        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.2.1.png");
        graphics.prepareImg(mn);
        graphics.presentScene();
        SDL_Delay(2000);

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>69 && player.rect.x+player.rect.w<107 && player.rect.y>628 && player.rect.y+player.rect.h<698){
        if (mul == 3){

        Mix_FadeOutMusic(2000);
        stageComplete(graphics, player);
        stage++;
        player.dx = 0; player.dy = 0;
        onelevel = 1;

        }

        else{

        Mix_FadeOutMusic(2000);
        gameComplete(graphics, player, mul, ingame);
        player.dx = 0; player.dy = 0;
        stage = 1;
        onelevel = 1;
        oneMenu = 1;
        oneStage = 1;
        end = 1;

        }
    }

    else if(player.rect.x>69 && player.rect.x+player.rect.w<1299 && player.rect.y>144 && player.rect.y+player.rect.h<698){

        if (mul == 1){
            time ++;
        }
        else if (mul == 2){
            time += 1.5;
        }
        else if (mul == 3){
            time += 2;
        }

        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.1.png");

        if((player.rect.x>351 && player.rect.x+player.rect.w<415 && player.rect.y>278 && player.rect.y+player.rect.h<314)
           ||(player.rect.x>775 && player.rect.x+player.rect.w<841 && player.rect.y>278 && player.rect.y+player.rect.h<314)
           ||(player.rect.x>1249 && player.rect.x+player.rect.w<1298 && player.rect.y>350 && player.rect.y+player.rect.h<400)
           ||(player.rect.x>1249 && player.rect.x+player.rect.w<1298 && player.rect.y>652 && player.rect.y+player.rect.h<701)
           ||(player.rect.x>210 && player.rect.x+player.rect.w<277 && player.rect.y>488 && player.rect.y+player.rect.h<524)
           ||(player.rect.x>493 && player.rect.x+player.rect.w<560 && player.rect.y>488 && player.rect.y+player.rect.h<524)
           ||(player.rect.x>210 && player.rect.x+player.rect.w<277 && player.rect.y>598 && player.rect.y+player.rect.h<631)
           ||(player.rect.x>493 && player.rect.x+player.rect.w<560 && player.rect.y>598 && player.rect.y+player.rect.h<631)
           ||(player.rect.x>770 && player.rect.x+player.rect.w<847 && player.rect.y>523 && player.rect.y+player.rect.h<563)){
               if (safe){
                player.dx = 0;
                player.dy = 0;
                safe = 0;
                player.grax = 0;
                player.gray = 0;
               }
           }
        else{
            player.grax = 0;
            player.gray = -1;

            safe = 1;
        }
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
    }

    if (time >= 1200&&time<=1368){//no
        SDL_DestroyTexture(mn);
        SDL_RenderClear(graphics.renderer);
        if (playSound){
                    stageSound = graphics.loadSound("Sound\\sfx\\Explode.mp3");
                    graphics.play(stageSound);
                    playSound = false;
                }
        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.1.1.png");

        if((player.rect.x>351 && player.rect.x+player.rect.w<415 && player.rect.y>278 && player.rect.y+player.rect.h<314)
           ||(player.rect.x>775 && player.rect.x+player.rect.w<841 && player.rect.y>278 && player.rect.y+player.rect.h<314)
           ||(player.rect.x>1249 && player.rect.x+player.rect.w<1298 && player.rect.y>350 && player.rect.y+player.rect.h<400)
           ||(player.rect.x>1249 && player.rect.x+player.rect.w<1298 && player.rect.y>652 && player.rect.y+player.rect.h<701)
           ||(player.rect.x>210 && player.rect.x+player.rect.w<277 && player.rect.y>488 && player.rect.y+player.rect.h<524)
           ||(player.rect.x>493 && player.rect.x+player.rect.w<560 && player.rect.y>488 && player.rect.y+player.rect.h<524)
           ||(player.rect.x>210 && player.rect.x+player.rect.w<277 && player.rect.y>598 && player.rect.y+player.rect.h<631)
           ||(player.rect.x>493 && player.rect.x+player.rect.w<560 && player.rect.y>598 && player.rect.y+player.rect.h<631)
           ||(player.rect.x>770 && player.rect.x+player.rect.w<847 && player.rect.y>523 && player.rect.y+player.rect.h<563)){

           }
        else{
            player.health --;
            death(graphics, mn, player, onelevel);
        }
    }

    if (time == 402||time==798){//bao hieu
        stageSound = graphics.loadSound("Sound\\sfx\\NuclearAlarm.mp3");
        graphics.play(stageSound);
        playSound = true;
    }

    if (time == 1368){
            time = 0;
            Mix_FadeOutChannel(-1, 500);
            Mix_FreeChunk(stageSound);
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stage12s(bool &onelevel, Graphics &graphics, Player &player, SDL_Texture *mn, Mix_Chunk *stageSound, int &stage, int mul, bool &ingame,  bool &oneMenu, bool &oneStage, bool &end){
    if (onelevel){

        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.s.png");
        dechangeScene(graphics, mn);

        SDL_DestroyTexture(mn);
        player.spawnPlayer(graphics, 1072, 405);
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_RenderClear(graphics.renderer);
        SDL_DestroyTexture(mn);
        onelevel = 0;
    }

    if(player.rect.x>244 && player.rect.x+player.rect.w<313 && player.rect.y>384 && player.rect.y+player.rect.h<456){
        Mix_FadeOutMusic(2000);
        gameComplete(graphics, player, mul, ingame);
        player.dx = 0; player.dy = 0;
        stage = 1;
        onelevel = 1;
        oneMenu = 1;
        oneStage = 1;
        end = 1;
    }

    else if(player.rect.x>244 && player.rect.x+player.rect.w<1121 && player.rect.y>347 && player.rect.y+player.rect.h<492){
        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.s.png");

        if (player.rect.x>437 && player.rect.x+player.rect.w<535 && player.rect.y>337 && player.rect.y+player.rect.h<502){
            SDL_DestroyTexture(mn);
            SDL_RenderClear(graphics.renderer);

            mn = graphics.loadTexture("Image\\Stage\\Stage\\Secret.jpg");

            Mix_FreeChunk(stageSound);
            stageSound = graphics.loadSound("Sound\\sfx\\Secret.wav");
            graphics.play(stageSound);

            graphics.prepareImg(mn);
            graphics.presentScene();

            SDL_Delay(4000);

            SDL_RenderClear(graphics.renderer);
            graphics.presentScene();

            SDL_Delay(1500);

            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Stage\\12.s.png");
            player.spawnPlayer(graphics, 268, 408);
        }
    }

    else{
        player.health --;
        death(graphics, mn, player, onelevel);
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}
#endif
