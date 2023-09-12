/**
 * Collision Box
 * Danny Van Stemp
 * A collidable box. Implemented for more
 *   precise collision.
 * 09/07/2017
 **/

#ifndef COLLISIONBOX_H
#define COLLISIONBOX_H

#include "Box.h"

class CollisionBox : public Box {
 public:
  // Constructor
  CollisionBox(const float x,
               const float y,
               const float width,
               const float height,
               b2World* world);

  // Draw
  void draw() override;

  // Update
  void update(b2World* world) override{
      // Unused
  };

  // Get type
  int getType() override;
};

#endif  // COLLISIONBOX_H
