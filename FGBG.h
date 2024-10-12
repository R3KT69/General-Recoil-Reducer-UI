#include "dependencies.h"

SDL_Rect button[4];


void RenderForeground(SDL_Renderer *renderer, TTF_Font *myfont)
{
    SDL_Rect rect = {0, 0, 300, 30};
    text myText(myfont, "", {255,255,255});
    SDL_SetRenderDrawColor(renderer, 25, 25, 25, 0); 
    SDL_RenderFillRect(renderer, &rect);
    
    for (int i = 0; i < 4; i++)
    {
        button[i].x = i + 5 + (i * 55);
        button[i].y = 5;
        button[i].h = 20;
        button[i].w = 50;

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 0); 
        SDL_RenderFillRect(renderer, &button[i]);

        
    }
    myText.DrawText(*renderer, button[0].x + 3, button[0].y + 3, "Start");
    myText.DrawText(*renderer, button[1].x + 3, button[1].y + 3, "Stop");
    myText.DrawText(*renderer, button[2].x + 3, button[2].y + 3, "Help");
    myText.DrawText(*renderer, button[3].x + 3, button[2].y + 3, "About");
    
     
    
}

void RenderBackground(SDL_Renderer *renderer, TTF_Font *myfont)
{
    text myText2(myfont, "", {0,255,0});
    int offsetX = 16;
    int offsetY = 50;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    myText2.DrawText(*renderer, offsetX, 50, "-----------[Status]-----------");
    
    if (currentBtn == 0) // start
    {
        myText2.DrawText(*renderer, offsetX, offsetY*1.5, "Active");
    }

    if (currentBtn == 1) // stop
    {
        myText2.DrawText(*renderer, offsetX, offsetY*1.5, "Stopped");
    }

    if (currentBtn == 2) // help
    {
        myText2.DrawText(*renderer, offsetX, offsetY*1.5, "1. Click <Start>");
        myText2.DrawText(*renderer, offsetX, offsetY*1.5 + offsetX, "2. Alt-Tab to your game.");
        myText2.DrawText(*renderer, offsetX, offsetY*1.5 + (offsetX*2), "3. Left-Click mouse.");
    }

    if (currentBtn == 3) // about
    {
        myText2.DrawText(*renderer, offsetX, offsetY*1.5, "Version 0.1");
        myText2.DrawText(*renderer, offsetX, offsetY*1.5 + offsetX, "General Recoil Reducer.");
    }
    
    

}