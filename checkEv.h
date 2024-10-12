#include "dependencies.h"


int mouseX, mouseY;
SDL_Point mousePos;
int currentBtn = 2;
bool flag = false;

bool checkEvent(SDL_Event &event)
{
    SDL_GetMouseState(&mouseX, &mouseY);
    mousePos.x = mouseX;
    mousePos.y = mouseY;
    
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            //cout << "clicked X" << endl;
            system("taskkill /IM rec.exe /F");
            return true;
        }

        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                for (int i = 0; i < 4; i++)
                {
                    if (SDL_PointInRect(&mousePos, &button[i]))
                    {
                        //cout << "clicked btn: " << i << endl;
                        currentBtn = i;

                        if (flag == false)
                        {
                            if (i == 0)
                            {
                                system("start src\\own\\rec.exe");
                                flag = true;
                            }
                        }
                        

                        if (i == 1)
                        {
                            system("taskkill /IM rec.exe /F");
                            flag = false;
                        }
                        

                        
                        
                    }
                }
            }
            
        }
    }
}