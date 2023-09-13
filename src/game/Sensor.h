/**
 * Sensor
 * Danny Vanstemp
 * Senses physics bodies
 * 05/05/2017
 **/

#ifndef SENSOR_H
#define SENSOR_H

#include "Box.h"

class b2World;
class b2Body;
class b2BodyDef;
class b2Vec2;
class keyListener;
class b2JointDef;
class b2WeldJointDef;

class Sensor : public Box {
 public:
  // Constructor
  Sensor(const float x, const float y, const float width, const float height);

  void init(b2World*, b2Body*);
  void createBody(int bodyType, bool fixedRotation);

  // Colliding with something
  bool isColliding();

  // Colliding with dynamic body
  bool isCollidingWithDynamicBody();

  // Colliding with any body
  bool isCollidingWithBody(b2Body*);

  // Update sensor
  void update(b2World* world) override{
      // Unused
  };

  // Draw sensor
  void draw() override;

  // Get type
  int getType() override;

 private:
  b2World* gameWorld;
};

#endif  // SENSOR_H
