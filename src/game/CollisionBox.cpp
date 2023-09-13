#include "CollisionBox.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "../util/Globals.h"
#include "../util/KeyListener.h"

CollisionBox::CollisionBox(const float x,
                           const float y,
                           const float width,
                           const float height,
                           std::shared_ptr<b2World> world)
    : Box(x, y, width, height, world) {
  // Modify body
  body->SetType(b2_kinematicBody);
}

void CollisionBox::draw() {
  if (KeyListener::key[ALLEGRO_KEY_G]) {
    // Draw transform
    ALLEGRO_TRANSFORM trans;
    ALLEGRO_TRANSFORM prevTrans;

    // back up the current transform
    al_copy_transform(&prevTrans, al_get_current_transform());

    // scale using the new transform
    al_identity_transform(&trans);

    al_translate_transform(&trans, getX() * 20, getY() * -20);

    al_use_transform(&trans);

    al_draw_filled_rectangle(-(getWidth() / 2) * 20 + 1,
                             -(getHeight() / 2) * 20 + 1,
                             (getWidth() / 2) * 20 - 1,
                             (getHeight() / 2) * 20 - 1, al_map_rgb(255, 0, 0));

    al_use_transform(&prevTrans);
  }
}

// Get box type
int CollisionBox::getType() {
  return COLLISION;
}
