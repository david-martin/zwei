#ifndef ZWEI_MIND_H
#define ZWEI_MIND_H

#include "../Entity.h"
#include "../Collider.h"

class Mind {
public:
    Mind(Entity &parent) : parent(parent) {}

    virtual ~Mind() {}

    virtual void plan(float dt) {}

    virtual int delay() { return 1000; }

    virtual bool activate() { return false; }

    virtual void render() { return; }

protected:

    Entity &parent;

};

#endif
