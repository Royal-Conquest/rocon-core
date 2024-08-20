#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <string>




class Graphics {
public:
    Graphics(SDL_Renderer* renderer);
    ~Graphics();

    bool LoadImage(const std::string& filePath);
    void RenderImage(int x, int y);
    void Clear();
    void Present();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect destRect;
};

#endif // GRAPHICS_H
