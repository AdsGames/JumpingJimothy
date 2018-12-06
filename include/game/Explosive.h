/**
 * Explosive
 * Danny Van Stemp
 * Box that applys gravity in a direction
 * 21/09/2017
**/

#ifndef EXPLOSIVE_H
#define EXPLOSIVE_H

#include "Character.h"
#include "Box.h"

class Explosive : public Box {
  public:
    Explosive(const float x, const float y, const bool affectCharacter, Character *character, b2World *world);
    virtual ~Explosive() {};
    virtual void draw() override;
    virtual void update() override;

    void applyBlastImpulse(b2Body* body, b2Vec2 blastCenter, b2Vec2 applyPoint, const float blastPower);

    // Get type
    virtual int getType() override;

  private:
    // Pointer to character
    Character *gameCharacter;

    // Blast radius
    int blastRadius;

    // Power of explosive
    int blastPower;

    // Can affect character or not
    bool affect_character;

    // Is currently exploding
    bool is_exploding;
};

#endif // EXPLOSIVE_H
