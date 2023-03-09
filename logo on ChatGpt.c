#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    window = SDL_CreateWindow("Logo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set the background color to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    // Clear the screen
    SDL_RenderClear(renderer);

    // Set the color to blue
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Draw a blue circle in the center of the screen
    SDL_Rect rect = { 320, 240, 100, 100 };
    SDL_RenderFillRect(renderer, &rect);

    // Update the screen
    SDL_RenderPresent(renderer);

    // Wait for the user to close the window
    while (true) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

