#include "graphics.h"
#include <iostream>

// Construtor
Graphics::Graphics(SDL_Renderer* renderer) : renderer(renderer), texture(nullptr) {
    destRect = { 0, 0, 0, 0 }; // Inicializa o retângulo de destino
}

// Destruidor
Graphics::~Graphics() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

// Carregar imagem
bool Graphics::LoadImage(const std::string& filePath) {
    // Se já há uma textura carregada, destrua-a
    if (texture) {
        SDL_DestroyTexture(texture);
    }

    // Carregar a imagem
    SDL_Surface* surface = SDL_LoadBMP(filePath.c_str());
    if (!surface) {
        std::cerr << "Erro ao carregar a imagem: " << SDL_GetError() << std::endl;
        return false;
    }

    // Criar a textura a partir da superfície
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Erro ao criar textura: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return false;
    }

    // Definir o tamanho do retângulo de destino
    SDL_QueryTexture(texture, NULL, NULL, &destRect.w, &destRect.h);

    SDL_FreeSurface(surface);
    return true;
}

// Renderizar imagem
void Graphics::RenderImage(int x, int y) {
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
}

// Limpar a tela
void Graphics::Clear() {
    SDL_RenderClear(renderer);
}

// Apresentar na tela
void Graphics::Present() {
    SDL_RenderPresent(renderer);
}
