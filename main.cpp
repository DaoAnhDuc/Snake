#include <iostream>
#include <SDL.h> //2.0.5
#include <cstdlib>
#include <ctime>
#include "SDL_ultils.h"
using namespace std;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;
const int COUNT_TIME = 1000;
const int SO_DOT_DE_BIG_HOA_QUA_XH = 5;
const string WINDOW_TITLE = "Snake game";
int size = 20;
int SPEED_SNAKE = 90;
int SCORE = 0;
int countTime = COUNT_TIME;
enum TrangThai{UP, DOWN, LEFT, RIGHT} ;
enum SizeHoaQua{SMALL,BIG};

struct ToaDo {
    int x, y;
};
struct Snake{
    ToaDo dot[100];
    int n;
    TrangThai tt;
};
struct HoaQua{
    ToaDo td;
    SizeHoaQua sizeHq;
};
int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
void DrawDot(SDL_Renderer* renderer,int tdX,int tdY,string color){
    SDL_Rect filled_rect;
    filled_rect.x = tdX;
    filled_rect.y = tdY;
    filled_rect.w = size;
    filled_rect.h = size;
    if(color == "HEAD"){
        SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);
    }else if(color == "BODY"){
       SDL_SetRenderDrawColor(renderer, 153, 153, 255, 255);
    }
    SDL_RenderFillRect(renderer, &filled_rect);
}
void DrawHoaQua(SDL_Renderer* renderer,int tdX,int tdY,HoaQua &hq){
    SDL_Rect filled_rect;
    filled_rect.x = tdX;
    filled_rect.y = tdY;
    if(hq.sizeHq == BIG){
        filled_rect.w = size * 2;
        filled_rect.h = size * 2;
    }else if(hq.sizeHq == SMALL){
        filled_rect.w = size;
        filled_rect.h = size;
    }
    SDL_SetRenderDrawColor(renderer, 250, 128, 114, 0);
    SDL_RenderFillRect(renderer, &filled_rect);
}
void KhoiTaoSnake(Snake &snake, HoaQua &hq){
    snake.n = 1;
    snake.dot[0].x = 0;
    snake.dot[0].y = 0;
    snake.tt = RIGHT;
    hq.sizeHq = SMALL;
    hq.td.x = 200;
    hq.td.y = 200;
}
void HienThiSnake(Snake snake, SDL_Renderer* renderer, HoaQua hq){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    for(int i = 0; i < snake.n; i++){
        if(i == 0){
            DrawDot(renderer, snake.dot[i].x, snake.dot[i].y, "HEAD");
        }else{
            DrawDot(renderer, snake.dot[i].x, snake.dot[i].y, "BODY");
        }
    }
    DrawHoaQua(renderer, hq.td.x, hq.td.y, hq);
    SDL_RenderPresent(renderer);
}
void AutoRun(Snake &snake){

    for(int i = snake.n - 1; i > 0 ; i--){
            snake.dot[i] = snake.dot[i-1];
    }
    if(snake.tt == UP){
        snake.dot[0].y -= size;
    }
    else if(snake.tt == DOWN){
        snake.dot[0].y += size;
    }
    else if(snake.tt == RIGHT){
        snake.dot[0].x += size;
    }
    else if(snake.tt == LEFT){
        snake.dot[0].x -= size;
    }
}
bool CheckLostGame(Snake snake,int minX, int minY, int maxX, int maxY){
    bool check = false;
    if(minX <= snake.dot[0].x && minY <= snake.dot[0].y && snake.dot[0].x + size <= maxX && snake.dot[0].y + size <= maxY){
         check = true;
    }
    for(int i = 1; i < snake.n; i++){
        if(snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y){
            check = false;
        }
    }
    return check;
}
void XuLy(Snake &snake, HoaQua &hq){
    if(hq.sizeHq == SMALL){
        if(snake.dot[0].x == hq.td.x && snake.dot[0].y == hq.td.y){
            for(int i = snake.n; i > 0; i--){
                snake.dot[i] = snake.dot[i-1];
            }
            snake.n++;
            if(snake.tt == UP){
                snake.dot[0].y -= size;
            }
            else if(snake.tt == DOWN){
                snake.dot[0].y += size;
            }
            else if(snake.tt == RIGHT){
                snake.dot[0].x += size;
            }
            else if(snake.tt == LEFT){
                snake.dot[0].x -= size;
            }
            SCORE += countTime;
            cout << "n: " << snake.n << endl;
            cout << "+" << countTime << endl;
            if(snake.n % SO_DOT_DE_BIG_HOA_QUA_XH == (SO_DOT_DE_BIG_HOA_QUA_XH - 1)){
                hq.sizeHq = BIG;
                hq.td.x = size * random(1, SCREEN_WIDTH / size - 2);
                hq.td.y = size * random(1, SCREEN_HEIGHT / size - 2);
            }else{
                hq.sizeHq = SMALL;
                hq.td.x = size * random(1, SCREEN_WIDTH / size - 1);
                hq.td.y = size * random(1, SCREEN_HEIGHT / size - 1);
            }
            countTime = COUNT_TIME;
            cout << snake.n << endl;
            cout << SCORE  << endl;
        }
    }else if(hq.sizeHq == BIG){
        if(snake.dot[0].x == hq.td.x && snake.dot[0].y == hq.td.y
             || snake.dot[0].x == (hq.td.x + size) && snake.dot[0].y == hq.td.y
             || snake.dot[0].x == hq.td.x && snake.dot[0].y == (hq.td.y + size)
             || snake.dot[0].x == (hq.td.x + size) && snake.dot[0].y == (hq.td.y + size)){
            for(int i = snake.n; i > 0; i--){
                snake.dot[i] = snake.dot[i-1];
            }
            snake.n++;
            if(snake.tt == UP){
                snake.dot[0].y -= size;
            }
            else if(snake.tt == DOWN){
                snake.dot[0].y += size;
            }
            else if(snake.tt == RIGHT){
                snake.dot[0].x += size;
            }
            else if(snake.tt == LEFT){
                snake.dot[0].x -= size;
            }
            SCORE += countTime*3;
            cout << "+" << countTime*3 << endl;
            cout << "n: " << snake.n << endl;
            hq.td.x = size * random(1, SCREEN_WIDTH / size - 1);
            hq.td.y = size * random(1, SCREEN_HEIGHT / size - 1);
            hq.sizeHq = SMALL;
            countTime = COUNT_TIME;
            cout << snake.n << endl;
            cout << SCORE  << endl;
         }
    }
}
int main(int argc, char *argv[]){
    srand(time(NULL)); //auto number
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    Snake snake;
    HoaQua hq;
    KhoiTaoSnake(snake, hq);
    while(CheckLostGame(snake, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)){
        AutoRun(snake);
        //Handle
        XuLy(snake, hq);
        //Show
        HienThiSnake(snake, renderer, hq);
        if(countTime > 0){
            countTime -= 5;
        }
        SDL_Delay(SPEED_SNAKE);
        //Control
        if( SDL_PollEvent(&e) == 0) continue;
        //if(e.type == SDL_QUIT) break;
        if(e.type == SDL_KEYDOWN){
            switch(e.key.keysym.sym){
                case SDLK_ESCAPE: break;
                case SDLK_LEFT:
                    snake.tt = LEFT;
                    break;
                case SDLK_RIGHT:
                    snake.tt = RIGHT;
                    break;
                case SDLK_UP:
                    snake.tt = UP;
                    break;
                case SDLK_DOWN:
                    snake.tt = DOWN;
                    break;
                default: break;
            }
        }
    }
    cout << "GAME OVER :(" << endl;
    cout << "DOT: " << snake.n << endl;
    cout << "SCORE: " << SCORE << endl;
    quitSDL(window, renderer);
    return 0;
}
