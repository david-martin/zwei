#ifndef ZWEI_ANIMATION_H
#define ZWEI_ANIMATION_H

#include <unordered_map>
#include <vector>

#include "Component.h"
#include "../alg/Direction.h"

class Animation : public Component {
public:
    Animation(Entity &parent, float speed, bool repeat);

    void update(float dt) override;

    void addAnimationFrame(int a);

    void addAnimationFrame(int n, int s, int e, int w);

    int getCurrentFrame(Direction d = N);

    float speed;

    bool repeat;

private:

    void addFrameForDirection(Direction d, int frame);

    float animationCount = 0;

    int currentIndex = 0;

    int frameCount = 0;

    std::unordered_map<Direction, std::vector<int>> frames;
};


#endif