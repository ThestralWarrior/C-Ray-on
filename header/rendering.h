#ifndef RENDERING_H
#define RENDERING_H

#include "structs.h"

Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction, Color light, Color object, Color ambient);
void render(Scene scene, int sphere_count, Vector3 light_direction, Color light, Color ambient);
void applyFXAA(Color *image, int width, int height);

#endif