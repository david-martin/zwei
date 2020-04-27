#ifndef ZWEI_ASSETS_H
#define ZWEI_ASSETS_H

#include <unordered_map>
#include <memory>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "EMBEDDED/EmbeddedAsset.h"

enum Asset {
    FONT = 0,
    TILES
};

class Texture {
public:
    Texture(SDL_Texture *texture) : mem(texture) {}

    ~Texture();

    SDL_Texture *mem;
    int w;
    int h;
};

class Assets {
public:
    static Assets &instance() {
        static Assets instance;
        return instance;
    }

    Assets(Assets const &) = delete;

    void operator=(Assets const &) = delete;


    void addFont(Asset id, EmbeddedAsset &asset);

    void addTexture(Asset id, EmbeddedAsset &asset);

    void *getFont(Asset id);

    std::shared_ptr<Texture> getTexture(Asset id);

private:
    Assets() {}

    std::unordered_map<Asset, std::shared_ptr<Texture>> textures;
    std::unordered_map<Asset, EmbeddedAsset *> fonts;
};

#endif
