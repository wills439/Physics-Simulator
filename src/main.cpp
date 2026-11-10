#include<SDL2/SDL.h>
#include<iostream>
#include<memory>

struct Vec2{
    float x,y;
};

struct Object{
    Vec2 pos,vel,acc;
};

int main(){
    const int scrwidth = 1280;
    const int scrheight = 720;
    
    //init sdl
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    
    auto window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(
        SDL_CreateWindow("Physics Simulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, scrwidth, scrheight, SDL_WINDOW_SHOWN),
        SDL_DestroyWindow
    );
    if(!window)
        std::cerr << "Window Error: " << SDL_GetError() << "\n";
    
    auto renderer = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(
        SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer
    );
    if(!renderer)
        std::cerr << "Renderer error: " << SDL_GetError() << "\n";

    std::cout << "Hello Wolrd\n";

    SDL_Event e;
    int running = 1;
    while(running){
        if(SDL_PollEvent(&e))
            if(e.type == SDL_QUIT)
                running = 0;

        SDL_SetRenderDrawColor(renderer.get(),0,0,0,0);
        SDL_RenderClear(renderer.get());
        SDL_RenderPresent(renderer.get());
    }

    return 0;
}