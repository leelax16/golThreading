#include "SDLstuff.h"

extern int rows;
extern int cols;
const int total = rows*cols;

int mx;
int my;
int speed = 200;

disp::disp(int rows, int cols, World *w){
    if(screeninit()){
        this->window = SDL_CreateWindow("GOL window", 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    1000, 
                                    800, 
                                    SDL_WINDOW_SHOWN);
        this->xOffset = (SDL_GetWindowSurface(window)->w)/cols;
        this->yOffset = (SDL_GetWindowSurface(window)->h)/rows;
        this->rWidth = (SDL_GetWindowSurface(window)->w -cols)/cols;
        this->rHeight = (SDL_GetWindowSurface(window)->h -rows)/rows;
        this->is_running = true;
        this->pause = true;
        this->w = w;
        this->rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        this->coda = TTF_OpenFont("Coda-Regular.ttf", 20);

    }
    else{
        std:: cout << "Failed to init.\n";
    }

}

disp::~disp(){

}

void disp::menu(){
    SDL_Color white = {255,255,255};
    SDL_Surface *message ==TTF_RenderText_Solid(this->coda, "this is a test");
    SDL_Texture* messageText = SDL_CreateTextureFromSurface(this->rend, messageText);

    SDL_FreeSurface(message); //dont need surface once it is uploaded as texture

    SDL_Rect = title;
    title.x = 100;
    title.y = 100;
    title.w = 400;
    title.h = 100;

    SDL_RenderCopy(this->rend, messageText, NULL, )
}

void disp::menuEvents(SDL_Event e){
    
}

bool disp::screeninit(){
    bool good = true;
                   // Declare a pointer

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
        good = false;
    }
    else{
        std::cout << "SDL video system is ready to go\n";
        if (window == NULL) {
            std::cout << "Could not create window: %s\n"<< SDL_GetError();
            good = false;
        }
    }  
    if(TTF_Init() < 0){
        std::cout << "SDL_ttf could not be initialized: " <<
                  TTF_GetError();
        good = false;
    }
    else{
        std::cout << "SDL_ttf system is ready to go\n";
    }     
    return good;
}

void disp::mainLoop(int rows, int cols){
    SDL_Event event;
    SDL_Rect rects[rows*cols];
    
    for (int x = 0; x<cols; x++){
        for (int y = 0; y<rows; y++){
            rects[(x*cols)+y].x = x*rWidth + x;
            rects[(x*cols)+y].y = .98*(y*rHeight + y);
            rects[(x*cols)+y].w = rWidth;
            rects[(x*cols)+y].h = .98*rHeight;
        }
    }
    drawCells(rects);
    SDL_RenderPresent(this->rend);
    while(this->is_running){
        handleInput(event, rects);
        if (!this->pause){
            main_thread_func(this->w);
            SDL_Delay(speed);
            SDL_SetRenderDrawColor(this->rend, 0,0,0,SDL_ALPHA_OPAQUE);
            SDL_RenderClear(this->rend);
            //SDL_Delay(5000);

            drawCells(rects);
            //if window is resized, resize cell squares

            SDL_RenderPresent(this->rend);


        }
        


    }
    end();
}

void disp::drawCells(SDL_Rect *rects){    
    for (int i = 0; i<total; i++){
        if (this->w->board[i].live){
            SDL_SetRenderDrawColor(this->rend, 0, 255, 255, SDL_ALPHA_OPAQUE);
        }
        else{
            SDL_SetRenderDrawColor(this->rend, 138, 134, 142, SDL_ALPHA_OPAQUE);
        }
        SDL_RenderFillRect(this->rend, &rects[i]);
    }
}

void disp::handleInput(SDL_Event e, SDL_Rect *rects){
    while (SDL_PollEvent(&e)) {
        switch(e.type){
            case SDL_QUIT:
                is_running = false;
                break;
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_SPACE:
                        if (!this->pause){
                            this->pause = true;
                        }
                        else{
                            this->pause = false;
                        }
                        break;

                    case SDLK_ESCAPE:
                        is_running = false;
                        break;
                    case SDLK_UP:
                        speed=speed+50;
                        break;
                    case SDLK_DOWN:
                        if(speed>50){
                            speed=speed-50;
                        }
                        break;

                }
            case SDL_MOUSEBUTTONDOWN:
                switch(e.button.button){
                    case SDL_BUTTON_LEFT:
                        this->mx = e.button.x/this->xOffset;
                        this->my = e.button.y/this->yOffset;
                        if (this->w->board[(mx*cols) + my].live){
                            this->w->board[(mx*cols) + my].live = 0;
                            if (this->pause){
                                drawCells(rects);
                                SDL_RenderPresent(this->rend);
                                
                            }
                            this->w->resets.push_back(&this->w->board[(mx*cols) + my]);
                        }
                        else{
                            this->w->board[(mx*cols) + my].live = 1;
                            if (this->pause){
                                drawCells(rects);
                                SDL_RenderPresent(this->rend);
                                this->w->alive.push_back(&this->w->board[(mx*cols) + my]);
                            }
                            else{
                                this->w->nextAlive.push_back(&this->w->board[(mx*cols) + my]);
                            }
                        }

                        break;

                    //case SDL_BUTTON_RIGHT:
                }

        }
        
    }
}

void disp::end(){
    
    TTF_CloseFont(this->coda);
    SDL_DestroyWindow(window);
    SDL_Quit();
}