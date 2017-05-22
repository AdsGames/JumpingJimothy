/**
 * BOX
 * Danny Vanstemp
 * 05/05/2017
**/
#ifndef BOX_H
#define BOX_H
#include <allegro5/allegro.h>
#include <Box2D/Box2D.h>
#include <tools.h>
#include <globals.h>

#define BOX 0
#define GOAT 2

class b2World;
class b2Body;
class b2BodyDef;
class b2Vec2;
class Sensor;
class Character;

class Box{
  public:


    // Constructors / Destructors
    Box();
    ~Box();

    void init(float, float, float, float,float,float,bool,BITMAP*,BITMAP*,BITMAP*,BITMAP*, b2World *);

    // Updates
    virtual void draw();
    virtual void update();

    // Setters
    void setStatic();
    void setDynamic(bool);
    void setOrientation(int);

    // Getters
    int getType(){ return type; };
    float getX(){ return x; };
    float getY(){ return y; };
    b2Body *getBody(){ return body; };

  protected:

    bool static_box;

    ALLEGRO_BITMAP *sprite;
    ALLEGRO_BITMAP *new_tiles[4];

    bool static_mode;
    int type;
    int orientation;

    b2Vec2 static_velocity;
    float static_angular_velocity;

    float x;
    float y;
    float angle;
    ALLEGRO_COLOR color;

    float width;
    float height;

    b2World *gameWorld;
    b2Body *body;
};


#endif // BOX_H
