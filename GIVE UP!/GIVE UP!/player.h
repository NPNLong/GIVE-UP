#ifndef _PLAYER__H
#define _PLAYER__H

struct Player {
    SDL_Rect rect;
    SDL_Texture *character;
    float dx = 0, dy = 0;
    float grax = 0, gray = 0;
    float speed;
    int health;


    void createPlayer(const Graphics& graphics) {
        character = IMG_LoadTexture(graphics.renderer, "Image\\Player 1.png");
        rect.h = PLAYER_SIZE;
        rect.w = PLAYER_SIZE;
    }

    void spawnPlayer(Graphics& graphics, int x, int y) {
        rect.x = x;
        rect.y = y;

        SDL_RenderCopy(graphics.renderer, character, NULL, &rect);
    }

    void draw(Graphics& graphics){
        SDL_RenderCopy(graphics.renderer, character, NULL, &rect);
    }

    void move() {
        rect.x += dx+grax;
        rect.y += dy+gray;
    }
    void turnNorth() {
        dy = -speed;
        dx = 0;
    }
    void turnSouth() {
        dy = speed;
        dx = 0;
    }
    void turnWest() {
        dy = 0;
        dx = -speed;
    }
    void turnEast() {
        dy = 0;
        dx = speed;
    }
};

#endif
