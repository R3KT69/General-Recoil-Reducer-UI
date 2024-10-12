#include "dependencies.h"
#include "checkEv.h"
#include "FGBG.h"

const int TARGET_FPS = 30;
const int FRAME_DELAY = 1000 / TARGET_FPS;

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    
    SDL_Window *window = SDL_CreateWindow("General Recoil Reducer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 300, 150, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Event event;
    TTF_Font *myfont = TTF_OpenFont("src\\own\\font.ttf", 16);
    Uint32 startTime;
    
    
    bool end = false;
    while (!end)
    {
        startTime = SDL_GetTicks();
        end = checkEvent(event);

        if (myfont == nullptr)
        {
            cerr << "TTF_OpenFont Error: " << TTF_GetError() << endl;
            cout << "Error: Font is null" << endl;
        }


        RenderBackground(renderer, myfont);
        RenderForeground(renderer, myfont);
        


        SDL_RenderPresent(renderer);
        
        // Framerate
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        if (elapsedTime < FRAME_DELAY) 
        {
            SDL_Delay(FRAME_DELAY - elapsedTime);  
        }
    }
    

    SDL_Quit();
    return 0;
}
