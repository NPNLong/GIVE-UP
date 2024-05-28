#ifndef _OBSTACLES__H
#define _OBSTACLES__H

struct Alien {
    SDL_Rect rect;
    SDL_Texture *alien;
    float dx , dy ;
    float ax, ay, bx, by;
    float speed;

    void createAlien(const Graphics& graphics) {
        alien = IMG_LoadTexture(graphics.renderer, "Image\\Stage\\Alien.png");
        rect.h = ALIEN_SIZE;
        rect.w = ALIEN_SIZE;
    }

    void spawnPlayer(Graphics& graphics, float a1x, float a1y, float b1x, float b1y, float speed1, bool up, bool reverse) {
        rect.x = a1x-rect.w/2;
        rect.y = a1y-rect.h/2;

        speed = speed1;

        if(a1x>b1x||a1y>b1y){
            bx=a1x; by=a1y; ax=b1x; ay=b1y;
        }
        else{
            ax=a1x; ay=a1y; bx=b1x; by=b1y;
        }

        if(up){
            if(!reverse){
            dy = speed;
            dx = 0;
            }
            else{
            dy = -speed;
            dx = 0;
            }
        }

        else{
            if(!reverse){
            dx = -speed;
            dy = 0;
            }
            else{
            dx = speed;
            dy = 0;
            }
        }

        SDL_RenderCopy(graphics.renderer, alien, NULL, &rect);
    }

    void draw(Graphics& graphics){
        SDL_RenderCopy(graphics.renderer, alien, NULL, &rect);
    }

    void update() {
        if ((rect.x <= ax-rect.w/2 && rect.y <= ay-rect.h/2)||(rect.x >= bx-rect.w/2 && rect.y >= by-rect.h/2)){
            dx=-dx;
            dy=-dy;
        }
    }

    void move() {
        rect.x += dx;
        rect.y += dy;
    }

    void render(const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 0, 255); // yellow
    SDL_RenderFillRect(graphics.renderer, &rect);
    }
};

struct Obstacle{
    SDL_Rect rect;

    void createObstacle(int x, int y, int x1, int y1){
    if(x < x1) rect.x = x;
    else rect.x = x1;
    if(y < y1) rect.y = y;
    else rect.y = y1;
    rect.w = abs(x - x1);
    rect.h = abs(y - y1);
    }

    void render(const Graphics& graphics) {
    SDL_SetRenderDrawColor(graphics.renderer, 255, 255, 0, 255); // yellow
    SDL_RenderFillRect(graphics.renderer, &rect);
}
};

#endif
