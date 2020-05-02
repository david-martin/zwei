#include <cassert>
#include <algorithm>

#include "Tile.h"
#include "Entity.h"
#include "Transform.h"
#include "Animation.h"
#include "Layered.h"

#include "../src/Gfx.h"
#include "../src/Draw.h"

Tile::Tile(Entity &parent, Asset id)
        : Component(parent),
          id(id) {}


void Tile::pick(SDL_Rect &source) {
    assert(parent.hasComponent<Animation>());

    auto texture = Assets::instance().getTexture(id);
    auto animation = parent.getComponent<Animation>();

    // Tile position in the tilemap
    int scalar = animation->getCurrentFrame() - 1;
    source.x = (scalar * Gfx_Tile_Size) % texture->w;
    source.y = (scalar * Gfx_Tile_Size) / texture->w * Gfx_Tile_Size;
    source.w = Gfx_Tile_Size;
    source.h = Gfx_Tile_Size;
}

void Tile::render(LayerType layer) {
    assert(parent.hasComponent<Transform>());
    assert(parent.hasComponent<Layered>());

    // Check if the tile is in the layer that is currently rendered
    auto componentLayer = parent.getComponent<Layered>();
    if (componentLayer->layer != layer) {
        return;
    }

    // Tilemap rect
    SDL_Rect source;
    pick(source);

    // Screen rect
    SDL_Rect target;
    auto transform = parent.getComponent<Transform>();
    auto texture = Assets::instance().getTexture(id);

    RT_Camera.project(target, transform->p.x, transform->p.y);
    if (!RT_Camera.visible(target)) {
        return;
    }

    Draw::instance().draw(texture->mem, source, target);
}