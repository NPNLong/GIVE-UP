#ifndef _GAME__H
#define _GAME__H

#include "effects.h"
#include "player.h"

void intro(Graphics graphics){
    SDL_Texture *show = graphics.loadTexture("Image\\Intro\\Intro 1.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(2780);

    SDL_DestroyTexture( show );
    show = graphics.loadTexture("Image\\Intro\\Intro 2.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(2780);

    SDL_DestroyTexture( show );
    show = graphics.loadTexture("Image\\Intro\\Intro 3.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(2780);

    SDL_DestroyTexture( show );
    show = graphics.loadTexture("Image\\Intro\\Intro 4.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(1420);

    SDL_DestroyTexture( show );
    show = graphics.loadTexture("Image\\Intro\\Intro 5.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(350);

    SDL_DestroyTexture( show );
    show = graphics.loadTexture("Image\\Intro\\Intro 6.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(350);

    SDL_DestroyTexture( show );
    show = graphics.loadTexture("Image\\Intro\\Intro 7.png");
    graphics.prepareScene(show);
    graphics.presentScene();

    SDL_Delay(700);
    SDL_DestroyTexture( show );
}

void menu(SDL_Texture *mn, Graphics& graphics, Mouse& mouse, SDL_Event &e, int &count, bool &quit, bool &playSound, bool &ingame, int &options, int &difficult, Mix_Chunk *menuSelect, Mix_Chunk *menuChoose){

    mouse.update();
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (count == 1){

        if(mouse.point.x>545 && mouse.point.x<822){

        if(mouse.point.y>312 && mouse.point.y<367){
                mouse.in = 1;
                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\Menu1.png");

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 2;
                        }
                }

        }

        else if(mouse.point.y>397 && mouse.point.y<454){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\Menu2.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 3;
                        }
                }
        }

        else if(mouse.point.y>484 && mouse.point.y<542){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\Menu3.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 4;
                        }
                }
        }

        else if(mouse.point.y>567 && mouse.point.y<626){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\Menu4.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 5;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\Menu.png");
        }

        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\Menu.png");
        }
    }

    if (count == 2){

        if(mouse.point.y>228 && mouse.point.y<612){

        if(mouse.point.x>119 && mouse.point.x<368){
                mouse.in = 1;
                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\dif2.png");

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        Mix_FadeOutMusic(500);
                        Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\gamein.wav");
                        graphics.play(cS);
                        for (int i=0; i<12; i++){
                            SDL_DestroyTexture(mn);
                            mn = graphics.loadTexture("Image\\Menu\\dif1.png");
                            graphics.prepareImg(mn);
                            graphics.presentScene();

                            SDL_Delay(50);

                            SDL_DestroyTexture(mn);
                            mn = graphics.loadTexture("Image\\Menu\\dif2.png");
                            graphics.prepareImg(mn);
                            graphics.presentScene();

                            SDL_Delay(50);
                        }
                        mn = graphics.loadTexture("Image\\Menu\\dif1.png");
                        graphics.prepareImg(mn);
                        graphics.presentScene();
                        Mix_FreeChunk(cS);
                        SDL_DestroyTexture(mn);
                        ingame = 1;
                        difficult = 1;
                        changeScene(graphics);
                        }
                }
        }

        else if(mouse.point.x>559 && mouse.point.x<807){
                mouse.in = 1;
                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\dif3.png");

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        Mix_FadeOutMusic(500);
                        Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\gamein.wav");
                        graphics.play(cS);
                        for (int i=0; i<12; i++){
                            SDL_DestroyTexture(mn);
                            mn = graphics.loadTexture("Image\\Menu\\dif1.png");
                            graphics.prepareImg(mn);
                            graphics.presentScene();

                            SDL_Delay(50);

                            SDL_DestroyTexture(mn);
                            mn = graphics.loadTexture("Image\\Menu\\dif3.png");
                            graphics.prepareImg(mn);
                            graphics.presentScene();

                            SDL_Delay(50);
                        }
                        mn = graphics.loadTexture("Image\\Menu\\dif1.png");
                        graphics.prepareImg(mn);
                        graphics.presentScene();
                        Mix_FreeChunk(cS);
                        SDL_DestroyTexture(mn);
                        ingame = 1;
                        difficult = 2;
                        changeScene(graphics);
                        }
                }
        }

        else if(mouse.point.x>998 && mouse.point.x<1247){
                mouse.in = 1;
                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\dif4.png");

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        Mix_FadeOutMusic(500);
                        Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\gamein.wav");
                        graphics.play(cS);
                        for (int i=0; i<12; i++){
                            SDL_DestroyTexture(mn);
                            mn = graphics.loadTexture("Image\\Menu\\dif1.png");
                            graphics.prepareImg(mn);
                            graphics.presentScene();

                            SDL_Delay(50);

                            SDL_DestroyTexture(mn);
                            mn = graphics.loadTexture("Image\\Menu\\dif4.png");
                            graphics.prepareImg(mn);
                            graphics.presentScene();

                            SDL_Delay(50);
                        }
                        mn = graphics.loadTexture("Image\\Menu\\dif1.png");
                        graphics.prepareImg(mn);
                        graphics.presentScene();
                        Mix_FreeChunk(cS);
                        SDL_DestroyTexture(mn);
                        ingame = 1;
                        difficult = 3;
                        changeScene(graphics);
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\dif1.png");
        }

        }

        else if(mouse.point.x>76 && mouse.point.x<138 && mouse.point.y>122 && mouse.point.y<192){
            mouse.in = 1;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\dif1.png");

            if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 1;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\dif1.png");
        }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    if (count == 3){

        if (options == 1){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\settings1.png");
        }
        else if (options == 2 || options == 3){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\settings3.png");
            options = 3;
        }
        else if (options == 4 || options == 5){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\settings4.png");
            options = 5;
        }
        else if (options == 6){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\settings2.png");
        }

        if(mouse.point.x>763 && mouse.point.x<807){

        if(mouse.point.y>327 && mouse.point.y<369){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }


                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {

                        if (options == 1){
                                options = 2;
                                Mix_VolumeMusic(0);
                        }
                        else if (options == 3){
                                options = 1;
                                Mix_VolumeMusic(MUSIC_VOL);
                                graphics.play(menuSelect);
                        }
                        else if (options == 6){
                                options = 4;
                                Mix_VolumeMusic(MUSIC_VOL);
                                graphics.play(menuSelect);
                        }
                        else if (options == 5){
                                options = 6;
                                Mix_VolumeMusic(0);
                        }

                        }
                }
        }

        else if(mouse.point.y>423 && mouse.point.y<467){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {

                        if (options == 1){
                                options = 4;
                                Mix_Volume(-1, 0);
                        }
                        else if (options == 5){
                                options = 1;
                                Mix_Volume(-1, 128);
                                graphics.play(menuSelect);
                        }
                        else if (options == 6){
                                options = 2;
                                Mix_Volume(-1, 128);
                                graphics.play(menuSelect);
                        }
                        else if (options == 3){
                                options = 6;
                                Mix_Volume(-1, 0);
                        }

                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
        }

        }

        else if(mouse.point.x>292 && mouse.point.x<341 && mouse.point.y>218 && mouse.point.y<253){
            mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 1;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
        }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    if (count == 4){

        if(mouse.point.x>94 && mouse.point.x<172 && mouse.point.y>133 && mouse.point.y<185){
        mouse.in = 1;

        if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Menu\\howtoplay.png");

            if(SDL_PollEvent(&e)){
                    if(e.type==SDL_MOUSEBUTTONDOWN) {
                    graphics.play(menuSelect);
                    count = 1;
                    }
            }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\howtoplay.png");
        }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    if (count == 5){

        if(mouse.point.y>442 && mouse.point.y<505){

        if(mouse.point.x>453 && mouse.point.x<623){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\quit2.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        quit = true;
                        }
                }
        }

        else if(mouse.point.x>754 && mouse.point.x<924){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Menu\\quit3.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 1;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\quit1.png");
        }

        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Menu\\quit1.png");
        }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void control(Player &player){
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_W]||currentKeyStates[SDL_SCANCODE_UP]) player.turnNorth();
    if (currentKeyStates[SDL_SCANCODE_S]||currentKeyStates[SDL_SCANCODE_DOWN]) player.turnSouth();
    if (currentKeyStates[SDL_SCANCODE_A]||currentKeyStates[SDL_SCANCODE_LEFT]) player.turnWest();
    if (currentKeyStates[SDL_SCANCODE_D]||currentKeyStates[SDL_SCANCODE_RIGHT]) player.turnEast();

    player.move();
}

bool inside(int x, int y, SDL_Rect r) {
    return x > r.x && x < r.x+r.w && y > r.y && y < r.y+r.h;
}

bool collision(const SDL_Rect& r1, const SDL_Rect& r2) {
    return inside(r1.x, r1.y, r2) || inside(r1.x + r1.w, r1.y, r2) ||
            inside(r1.x, r1.y+r1.h, r2) || inside(r1.x+r1.w, r1.y+r1.h, r2);
}

void mode(Graphics &graphics, int difficult, SDL_Texture *mn){
    if (difficult==1){
        mn = graphics.loadTexture("Image\\Stage\\Mode\\Hard.png");
    }
    else if (difficult==2){
        mn = graphics.loadTexture("Image\\Stage\\Mode\\Insane.png");
    }
    else if (difficult==3){
        mn = graphics.loadTexture("Image\\Stage\\Mode\\Hell.png");
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void health(Graphics &graphics, Player &player, SDL_Texture *mn){
    if (player.health==5){
        mn = graphics.loadTexture("Image\\Stage\\Health\\5.png");
    }
    else if (player.health==4){
        mn = graphics.loadTexture("Image\\Stage\\Health\\4.png");
    }
    else if (player.health==3){
        mn = graphics.loadTexture("Image\\Stage\\Health\\3.png");
    }
    else if (player.health==2){
        mn = graphics.loadTexture("Image\\Stage\\Health\\2.png");
    }
    else if (player.health==1){
        mn = graphics.loadTexture("Image\\Stage\\Health\\1.png");
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void pauseMenu(SDL_Texture *mn, Graphics& graphics, Mouse& mouse, SDL_Event &e, int &count, bool &quit, bool &playSound, bool &ingame, bool &oneMenu, bool &oneLevel, bool &oneStage, int &options, Mix_Chunk *menuSelect, Mix_Chunk *menuChoose){

    mouse.update();
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (count == 1){

        if(mouse.point.x>550 && mouse.point.x<823){

        if(mouse.point.y>297 && mouse.point.y<352){
                mouse.in = 1;
                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Stage\\Pause\\pMenu1.png");

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        quit = 0;
                        }
                }

        }

        else if(mouse.point.y>382 && mouse.point.y<439){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Stage\\Pause\\pMenu2.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 2;
                        }
                }
        }

        else if(mouse.point.y>468 && mouse.point.y<522){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Stage\\Pause\\pMenu3.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 3;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pMenu.png");
        }

        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pMenu.png");
        }
    }

    if (count == 2){

        if (options == 1){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pSettings1.png");
        }
        else if (options == 2 || options == 3){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pSettings3.png");
            options = 3;
        }
        else if (options == 4 || options == 5){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pSettings4.png");
            options = 5;
        }
        else if (options == 6){
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pSettings2.png");
        }

        if(mouse.point.x>763 && mouse.point.x<807){

        if(mouse.point.y>327 && mouse.point.y<369){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }


                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {

                        if (options == 1){
                                options = 2;
                                Mix_VolumeMusic(0);
                        }
                        else if (options == 3){
                                options = 1;
                                Mix_VolumeMusic(MUSIC_VOL);
                                graphics.play(menuSelect);
                        }
                        else if (options == 6){
                                options = 4;
                                Mix_VolumeMusic(MUSIC_VOL);
                                graphics.play(menuSelect);
                        }
                        else if (options == 5){
                                options = 6;
                                Mix_VolumeMusic(0);
                        }

                        }
                }
        }

        else if(mouse.point.y>423 && mouse.point.y<467){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {

                        if (options == 1){
                                options = 4;
                                Mix_Volume(-1, 0);
                        }
                        else if (options == 5){
                                options = 1;
                                Mix_Volume(-1, 128);
                                graphics.play(menuSelect);
                        }
                        else if (options == 6){
                                options = 2;
                                Mix_Volume(-1, 128);
                                graphics.play(menuSelect);
                        }
                        else if (options == 3){
                                options = 6;
                                Mix_Volume(-1, 0);
                        }

                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
        }

        }

        else if(mouse.point.x>292 && mouse.point.x<341 && mouse.point.y>218 && mouse.point.y<253){
            mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 1;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
        }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    if (count == 3){

        if(mouse.point.y>442 && mouse.point.y<505){

        if(mouse.point.x>453 && mouse.point.x<623){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Stage\\Pause\\pQuit2.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        quit = 0;
                        mn = graphics.loadTexture("Image\\Stage\\Pause\\pQuit1.png");
                        graphics.prepareImg(mn);
                        SDL_DestroyTexture(mn);
                        Mix_FadeOutMusic(500);
                        changeScene(graphics);
                        SDL_RenderClear(graphics.renderer);
                        graphics.presentScene();

                        SDL_DestroyTexture(mn);

                        mn = graphics.loadTexture("Image\\Intro\\Intro 7.png");

                        dechangeScene(graphics, mn);

                        ingame = 0;
                        oneLevel = 1;
                        oneStage = 1;
                        oneMenu = 1;
                        }
                }
        }

        else if(mouse.point.x>754 && mouse.point.x<924){
                mouse.in = 1;

                if (playSound){
                    graphics.play(menuChoose);
                    playSound = false;
                }

                SDL_DestroyTexture(mn);
                mn = graphics.loadTexture("Image\\Stage\\Pause\\pQuit3.png");

                if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 1;
                        }
                }
        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pQuit1.png");
        }

        }

        else{
            mouse.in = 0;
            playSound = true;
            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Pause\\pQuit1.png");
        }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

void stageComplete(Graphics &graphics, Player &player){
    SDL_Texture *mn = graphics.loadTexture("Image\\Stage\\StageComplete\\1.png");;
    Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\StageComplete.wav");
    graphics.play(cS);

    for (int i=0; i<5; i++){
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Stage\\StageComplete\\2.png");
        player.character = graphics.loadTexture("Image\\Player 4.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_Delay(200);

        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Stage\\StageComplete\\1.png");
        player.character = graphics.loadTexture("Image\\Player 1.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_Delay(200);
    }
    changeScene(graphics);
    SDL_DestroyTexture(mn);
    //Mix_FreeChunk(cs);
}

void gameComplete(Graphics &graphics, Player &player, int mul, bool &ingame){
    SDL_Texture *mn = graphics.loadTexture("Image\\Stage\\StageComplete\\1.png");;
    Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\StageComplete.wav");
    graphics.play(cS);

    for (int i=0; i<10; i++){
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Stage\\StageComplete\\2.png");
        player.character = graphics.loadTexture("Image\\Player 4.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_Delay(200);

        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Stage\\StageComplete\\1.png");
        player.character = graphics.loadTexture("Image\\Player 1.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_Delay(200);
    }
    SDL_RenderClear(graphics.renderer);
    SDL_DestroyTexture(mn);
    mn = graphics.loadTexture("Image\\Stage\\GameComplete\\1.png");;
    cS = graphics.loadSound("Sound\\sfx\\GameComplete.wav");
    graphics.play(cS);

    for (int i=0; i<10; i++){
        SDL_DestroyTexture(mn);
        if (mul==3){
            mn = graphics.loadTexture("Image\\Stage\\Stage\\12.s.png");
        }

        else{
        mn = graphics.loadTexture("Image\\Stage\\Stage\\12.1.png");
        }

        graphics.prepareImg(mn);
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Stage\\GameComplete\\2.png");
        player.character = graphics.loadTexture("Image\\Player 4.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_Delay(200);

        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Stage\\GameComplete\\1.png");
        player.character = graphics.loadTexture("Image\\Player 1.png");
        player.draw(graphics);
        graphics.prepareImg(mn);
        graphics.presentScene();

        SDL_Delay(200);
    }
    changeScene(graphics);
    SDL_DestroyTexture(mn);

    SDL_RenderClear(graphics.renderer);
    graphics.presentScene();

    SDL_DestroyTexture(mn);

    mn = graphics.loadTexture("Image\\Intro\\Intro 7.png");

    dechangeScene(graphics, mn);
    SDL_DestroyTexture(mn);
    SDL_RenderClear(graphics.renderer);

    ingame = 0;
    //Mix_FreeChunk(cs);
}

void death(Graphics &graphics, SDL_Texture *mn, Player &player, bool &oneLevel){
    Mix_HaltMusic();
    player.dx = 0;
    player.dy = 30;
    SDL_DestroyTexture(mn);
    SDL_RenderClear(graphics.renderer);
    Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\Collision.wav");
    graphics.play(cS);

    for (int i=0; i<12; i++){
        SDL_DestroyTexture(player.character);
        player.character = graphics.loadTexture("Image\\Player 3.png");
        player.draw(graphics);
        graphics.presentScene();

        SDL_Delay(50);

        SDL_DestroyTexture(player.character);
        player.character = graphics.loadTexture("Image\\Player 2.png");
        player.draw(graphics);
        graphics.presentScene();

        SDL_Delay(50);
    }

    Mix_FreeChunk(cS);
    SDL_DestroyTexture(player.character);
    cS = graphics.loadSound("Sound\\sfx\\Falling.wav");
    graphics.play(cS);

    for (int i=0; i<50; i++){
        SDL_DestroyTexture(player.character);
        SDL_RenderClear(graphics.renderer);
        player.character = graphics.loadTexture("Image\\Player 2.png");
        player.move();
        player.draw(graphics);
        graphics.presentScene();

        SDL_Delay(5);
    }
    SDL_Delay(500);

    Mix_FreeChunk(cS);
    SDL_DestroyTexture(player.character);
    player.character = graphics.loadTexture("Image\\Player 1.png");
    cS = graphics.loadSound("Sound\\sfx\\HealthDecrease.wav");
    if (player.health==4){
            mn = graphics.loadTexture("Image\\Stage\\Death\\5.png");
            graphics.prepareScene(mn);
            graphics.presentScene();

            SDL_Delay(1000);

            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Death\\4.png");
            graphics.prepareScene(mn);
            graphics.play(cS);
            graphics.presentScene();

            SDL_Delay(1500);

            oneLevel = 1;
    }

    else if (player.health==3){
            mn = graphics.loadTexture("Image\\Stage\\Death\\4.png");
            graphics.prepareScene(mn);
            graphics.presentScene();

            SDL_Delay(1000);

            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Death\\3.png");
            graphics.prepareScene(mn);
            graphics.play(cS);
            graphics.presentScene();

            SDL_Delay(1500);

            oneLevel = 1;
    }

    else if (player.health==2){
            mn = graphics.loadTexture("Image\\Stage\\Death\\3.png");
            graphics.prepareScene(mn);
            graphics.presentScene();

            SDL_Delay(1000);

            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Death\\2.png");
            graphics.prepareScene(mn);
            graphics.play(cS);
            graphics.presentScene();

            SDL_Delay(1500);

            oneLevel = 1;
    }

    else if (player.health==1){
            mn = graphics.loadTexture("Image\\Stage\\Death\\2.png");
            graphics.prepareScene(mn);
            graphics.presentScene();

            SDL_Delay(1000);

            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Death\\1.png");
            graphics.prepareScene(mn);
            graphics.play(cS);
            graphics.presentScene();

            SDL_Delay(1500);

            oneLevel = 1;
    }

    else if (player.health==0){
            mn = graphics.loadTexture("Image\\Stage\\Death\\1.png");
            graphics.prepareScene(mn);
            graphics.presentScene();

            SDL_Delay(1000);

            SDL_DestroyTexture(mn);
            mn = graphics.loadTexture("Image\\Stage\\Death\\0.png");
            graphics.prepareScene(mn);
            graphics.play(cS);
            graphics.presentScene();

            SDL_Delay(1500);

            oneLevel = 1;
    }
    SDL_RenderClear(graphics.renderer);
    graphics.presentScene();
    SDL_Delay(1000);

    Mix_FreeChunk(cS);
    SDL_DestroyTexture(mn);

    player.dx = 0;
    player.dy = 0;
}

void gameOver(Graphics &graphics, SDL_Texture *mn, Player &player, bool &ingame){
    SDL_DestroyTexture(mn);
    SDL_RenderClear(graphics.renderer);
    Mix_Chunk *cS = graphics.loadSound("Sound\\sfx\\GameOver.wav");
    graphics.play(cS);

    mn = graphics.loadTexture("Image\\Stage\\GameOver\\1.png");
    graphics.prepareScene(mn);
    graphics.presentScene();

    SDL_Delay(1100);

    SDL_DestroyTexture(mn);
    mn = graphics.loadTexture("Image\\Stage\\GameOver\\2.png");
    graphics.prepareScene(mn);
    graphics.presentScene();

    SDL_Delay(1000);

    SDL_DestroyTexture(mn);
    mn = graphics.loadTexture("Image\\Stage\\GameOver\\3.png");
    graphics.prepareScene(mn);
    graphics.presentScene();

    SDL_Delay(3000);
    Mix_FreeChunk(cS);

    SDL_RenderClear(graphics.renderer);
    graphics.presentScene();
    SDL_Delay(1000);

    SDL_DestroyTexture(mn);

    mn = graphics.loadTexture("Image\\Intro\\Intro 7.png");

    dechangeScene(graphics, mn);

    ingame = 0;
}

void ending(SDL_Texture *mn, Graphics& graphics, Mouse& mouse, SDL_Event &e, int &count, bool &end, bool &playSound, bool &ingame, Mix_Chunk *menuSelect){

    mouse.update();
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if(count == 1){
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Ending\\1.png");

        if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 2;
                        }
                }
    }

    else if(count == 2){
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Ending\\2.png");

        if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 3;
                        }
                }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    else if(count == 3){
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Ending\\3.png");

        if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        count = 4;
                        }
                }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    else if(count == 4){
        SDL_DestroyTexture(mn);
        mn = graphics.loadTexture("Image\\Ending\\4.png");

        if(SDL_PollEvent(&e)){
                        if(e.type==SDL_MOUSEBUTTONDOWN) {
                        graphics.play(menuSelect);
                        end = 0;
                        count = 1;
                        }
                }

        if (currentKeyStates[SDL_SCANCODE_ESCAPE]) {
                graphics.play(menuSelect);
                count = 1;
        }
    }

    graphics.prepareImg(mn);
    SDL_DestroyTexture(mn);
}

#endif
