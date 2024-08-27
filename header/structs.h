#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    float x, y, z;
} Vector3;

typedef struct {
    Vector3 origin;
    Vector3 direction;
} Ray;

typedef struct {
    float r, g, b;
} Color;

typedef struct {
    Vector3 center;
    float radius;
} Sphere;

typedef struct {
    Vector3 position;
    Vector3 direction;
} Camera;

typedef struct {
    int width;
    int height;
    Sphere *spheres;
    Camera* camera;
} Scene;

#endif