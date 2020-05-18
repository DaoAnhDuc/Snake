#include <iostream>
#include<vector>
#include <SDL.h> //2.0.5
#include <cstdlib>
#include <ctime>
#include <string>
#include "SDL_ultils.h"
using namespace std;

const int WIDTH = 60; // chiều rộng
const int HEIGHT = 30; //chiều dài
const int SIZE = 25; // độ lớn khối
int Map4[HEIGHT][WIDTH] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
const int FRUIT_NUMBER = 6; // số lần xuất hiện bóng to
const string WINDOW_TITLE = "Snake game";
const int SCREEN_WIDTH = WIDTH * SIZE ; // chiều rộng màn hình
const int SCREEN_HEIGHT = HEIGHT * SIZE;// chiều dài màn hình
const int SCORE_ADDED = 100; //Số điểm được cộng

int Score = 0; //Tổng Điểm
int ScoreAdded = SCORE_ADDED; //Điểm thêm vào mỗi lần ăn SMALL, ăn được BIG sẽ x3, điểm sẽ giảm theo thời gian
int FrameDuration = 90; //Độ delay của Snake

enum StatusMove{UP, DOWN, LEFT, RIGHT}; //trạng thái của Snake khi di chuyển
enum FruitSize{SMALL,BIG}; // Trạng thái của Fruit

//Tọa độ
struct Coordinates {
    int x, y;
};
struct Box {
    Coordinates coordinates;
    void reder(SDL_Renderer* renderer) {
        SDL_Rect filled_rect;
        filled_rect.x = coordinates.x * SIZE;
        filled_rect.y = coordinates.y *SIZE;
        filled_rect.w = SIZE;
        filled_rect.h = SIZE;
        SDL_SetRenderDrawColor(renderer, 133, 87, 13, 255); // green
        SDL_RenderFillRect(renderer, &filled_rect);
    }
};
struct Snake{
    Coordinates dot[100]; //Mảng lưu các Dot của Snake
    int n; // Số Dot hiện tại
    StatusMove statusMove;
};

struct Fruit{
    Coordinates coordinates;
    FruitSize fruitSize;
};

int random(int minN, int maxN){
    return minN + rand() % (maxN + 1 - minN);
}
//Kiểm tra xem Fruit có vướng Box không
bool checkFruit(int MAP[HEIGHT][WIDTH], int x, int y, Fruit fruit){
    if(fruit.fruitSize == SMALL){
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                if(MAP[i][j] == 1){
                    if(i == y/SIZE && x/SIZE == j
                      // || i == y/SIZE + 1 && x/SIZE == j
                      // || i == y/SIZE && x/SIZE + 1 == j
                      // || i == y/SIZE+1 && x/SIZE  +1 == j
                       ){
                        return false;
                    }
                }
            }
        }
    }else if(fruit.fruitSize == BIG){
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                if(MAP[i][j] == 1){
                    if(i == y/SIZE && x/SIZE == j
                       || i == y/SIZE + 1 && x/SIZE == j
                       || i == y/SIZE && x/SIZE + 1 == j
                       || i == y/SIZE + 1 && x/SIZE + 1 == j ){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
//Hàm vẽ Snake
void DrawDot(SDL_Renderer* renderer,int tdX,int tdY,string color){
    SDL_Rect filled_rect;
    filled_rect.x = tdX;
    filled_rect.y = tdY;
    filled_rect.w = SIZE;
    filled_rect.h = SIZE;
    if(color == "HEAD"){
        SDL_SetRenderDrawColor(renderer, 128, 128, 255, 255);
    }else if(color == "BODY"){
       SDL_SetRenderDrawColor(renderer, 153, 153, 255, 255);
    }
    SDL_RenderFillRect(renderer, &filled_rect);
}

//Hàm vẽ Fruit
void DrawFruit(SDL_Renderer* renderer,int tdX,int tdY,Fruit &fruit){
    SDL_Rect filled_rect;
    filled_rect.x = tdX;
    filled_rect.y = tdY;
    if(fruit.fruitSize == BIG){
        filled_rect.w = SIZE * 2;
        filled_rect.h = SIZE * 2;
    }else if(fruit.fruitSize == SMALL){
        filled_rect.w = SIZE;
        filled_rect.h = SIZE;
    }
    SDL_SetRenderDrawColor(renderer, 250, 128, 114, 0);
    SDL_RenderFillRect(renderer, &filled_rect);
}

//Khởi tạo Snake và Fruit ban đầu
void InitializationSnake(Snake &snake, Fruit &fruit, int MAP[HEIGHT][WIDTH]){
    snake.n = 1;
    snake.dot[0].x = SIZE;
    snake.dot[0].y = SIZE;
    snake.statusMove = RIGHT;
    fruit.fruitSize = SMALL;
    while(true){
        int fruitX = SIZE * random(1, WIDTH - 1);
        int fruitY = SIZE * random(1, HEIGHT - 1);
        if(checkFruit(MAP, fruitX, fruitY, fruit)==true){
            fruit.coordinates.x = fruitX;
            fruit.coordinates.y = fruitY;
            break;
        }
    }
}

void RenderMap(Snake snake, SDL_Renderer* renderer, Fruit fruit, int MAP[HEIGHT][WIDTH]){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    for(int i = 0; i < snake.n; i++){
        if(i == 0){
            DrawDot(renderer, snake.dot[i].x, snake.dot[i].y, "HEAD");
        }else{
            DrawDot(renderer, snake.dot[i].x, snake.dot[i].y, "BODY");
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if(MAP[i][j] == 1){
                Box box;
                box.coordinates.x = j;
                box.coordinates.y = i;
                box.reder(renderer);
            }
        }
    }
    DrawFruit(renderer, fruit.coordinates.x, fruit.coordinates.y, fruit);
    SDL_RenderPresent(renderer);
}

void AutoRun(Snake &snake){
    for(int i = snake.n - 1; i > 0 ; i--){
            snake.dot[i] = snake.dot[i-1];
    }
    if(snake.statusMove == UP){
        snake.dot[0].y -= SIZE;
    }
    else if(snake.statusMove == DOWN){
        snake.dot[0].y += SIZE;
    }
    else if(snake.statusMove == RIGHT){
        snake.dot[0].x += SIZE;
    }
    else if(snake.statusMove == LEFT){
        snake.dot[0].x -= SIZE;
    }

    if(snake.dot[0].x / SIZE == WIDTH){
        snake.dot[0].x = 0;
    }else if(snake.dot[0].x / SIZE == -1){
        snake.dot[0].x = (WIDTH) * SIZE;
    }
    if(snake.dot[0].y / SIZE == HEIGHT){
        snake.dot[0].y = 0;
    }else if(snake.dot[0].y / SIZE == -1){
        snake.dot[0].y = (HEIGHT) * SIZE;
    }
}

bool GameOver(Snake snake,int MAP[HEIGHT][WIDTH]){
    bool check = true;
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(MAP[i][j] == 1){
                if(snake.dot[0].x /SIZE == j && snake.dot[0].y/SIZE == i){
                     check = false;
                }
            }
        }
    }
    for(int i = 1; i < snake.n; i++){
        if(snake.dot[0].x == snake.dot[i].x && snake.dot[0].y == snake.dot[i].y){
            check = false;
        }
    }
    return check;
}

void HanldEatFruit(Snake &snake, Fruit &fruit, int MAP[HEIGHT][WIDTH]){
    if(fruit.fruitSize == SMALL){
        if(snake.dot[0].x == fruit.coordinates.x && snake.dot[0].y == fruit.coordinates.y){
            for(int i = snake.n; i > 0; i--){
                snake.dot[i] = snake.dot[i-1];
            }
            snake.n++;
            if(snake.statusMove == UP){
                snake.dot[0].y -= SIZE;
            }
            else if(snake.statusMove == DOWN){
                snake.dot[0].y += SIZE;
            }
            else if(snake.statusMove == RIGHT){
                snake.dot[0].x += SIZE;
            }
            else if(snake.statusMove == LEFT){
                snake.dot[0].x -= SIZE;
            }
            Score += ScoreAdded;
            cout << "n: " << snake.n << endl;
            cout << "+" << ScoreAdded << endl;
            if(snake.n % FRUIT_NUMBER == (FRUIT_NUMBER - 1)){
                fruit.fruitSize = BIG;
                while(true){
                    int fruitX = SIZE * random(1, WIDTH - 2);
                    int fruitY = SIZE * random(1, HEIGHT - 2);
                    if(checkFruit(MAP, fruitX, fruitY, fruit)==true){
                        fruit.coordinates.x = fruitX;
                        fruit.coordinates.y = fruitY;
                        break;
                    }
                }
            }else{
                fruit.fruitSize = SMALL;
                while(true){
                    int fruitX = SIZE * random(1, WIDTH - 1);
                    int fruitY = SIZE * random(1, HEIGHT - 1);
                    if(checkFruit(MAP, fruitX, fruitY, fruit)==true){
                        fruit.coordinates.x = fruitX;
                        fruit.coordinates.y = fruitY;
                        break;
                    }
                }
            }
            ScoreAdded = SCORE_ADDED;
            cout << snake.n << endl;
            cout << Score  << endl;
        }
    }else if(fruit.fruitSize == BIG){
        if(snake.dot[0].x == fruit.coordinates.x && snake.dot[0].y == fruit.coordinates.y
             || snake.dot[0].x == (fruit.coordinates.x + SIZE) && snake.dot[0].y == fruit.coordinates.y
             || snake.dot[0].x == fruit.coordinates.x && snake.dot[0].y == (fruit.coordinates.y + SIZE)
             || snake.dot[0].x == (fruit.coordinates.x + SIZE) && snake.dot[0].y == (fruit.coordinates.y + SIZE)){
            for(int i = snake.n; i > 0; i--){
                snake.dot[i] = snake.dot[i-1];
            }
            snake.n++;
            if(snake.statusMove == UP){
                snake.dot[0].y -= SIZE;
            }
            else if(snake.statusMove == DOWN){
                snake.dot[0].y += SIZE;
            }
            else if(snake.statusMove == RIGHT){
                snake.dot[0].x += SIZE;
            }
            else if(snake.statusMove == LEFT){
                snake.dot[0].x -= SIZE;
            }
            Score += ScoreAdded * 3;
            cout << "+" << ScoreAdded*3 << endl;
            cout << "n: " << snake.n << endl;
            while(true){
                int fruitX = SIZE * random(1, WIDTH - 1);
                int fruitY = SIZE * random(1, HEIGHT - 1);
                if(checkFruit(MAP, fruitX, fruitY, fruit)==true){
                    fruit.coordinates.x = fruitX;
                    fruit.coordinates.y = fruitY;
                    break;
                }
            }
            fruit.fruitSize = SMALL;
            ScoreAdded = SCORE_ADDED;
            cout << snake.n << endl;
            cout << Score  << endl;
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
    Fruit fruit;
    //MAP 1
      InitializationSnake(snake, fruit, Map4);
        while(GameOver(snake, Map4)){
            AutoRun(snake);
            //Handle
            HanldEatFruit(snake, fruit, Map4);
            //Show
            RenderMap(snake, renderer, fruit, Map4);

            if(ScoreAdded > 0){
                ScoreAdded -= 1;
            }
            SDL_Delay(FrameDuration);
            //Control
            if( SDL_PollEvent(&e) == 0) continue;
            if(e.type == SDL_QUIT) break;
            if(e.type == SDL_KEYDOWN){
                switch(e.key.keysym.sym){
                    case SDLK_ESCAPE: break;
                    case SDLK_LEFT:
                        if(snake.statusMove != RIGHT){
                             snake.statusMove = LEFT;
                        }
                        break;
                    case SDLK_RIGHT:
                        if(snake.statusMove != LEFT){
                             snake.statusMove = RIGHT;
                        }
                        break;
                    case SDLK_UP:
                        if(snake.statusMove != DOWN){
                             snake.statusMove = UP;
                        }
                        break;
                    case SDLK_DOWN:
                        if(snake.statusMove != UP){
                             snake.statusMove = DOWN;
                        }
                        break;
                    default: break;
                }
            }

    }
    cout << "GAME OVER :(" << endl;
    cout << "DOT: " << snake.n << endl;
    cout << "SCORE: " << Score << endl;
    quitSDL(window, renderer);
    return 0;
}
