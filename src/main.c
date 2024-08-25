#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "compute.h"
#include "structs.h"
#include "rendering.h"

int main() {
    int width = 400;
    int height = 400;
    Camera camera = {{0, 0, 1}, {0, 0, -1}};
    Sphere sphere1 = {{0, 0, -10.0f}, 1};
    Sphere sphere2 = {{-3, 1, -6.0f}, 1};
    Sphere sphere3 = {{1, -1, -4.0f}, 1};
    Scene scene = (Scene){
        (Sphere[]){sphere1, sphere2, sphere3}
    };
    Vector3 light_direction = {-1.0f, 0.0f, 0.0f};
    Color sphere_color = {0.0f, 1.0f, 0.0f};
    Color light_color = {1.0f, 1.0f, 1.0f};
    Color ambient_color = {0.3f, 0.3f, 0.3f};
    printf("Listing the contents of the scene.\n");
    for(int i = 0; i < 3; i++) {
        printf("(Sphere) Center: %f %f %f, Radius: %f\n", scene.spheres[i].center.x, scene.spheres[i].center.y, scene.spheres[i].center.z, scene.spheres[i].radius);
    }
    printf("Starting rendering...\n");
    render(width, height, camera, scene, 3, light_direction, light_color, sphere_color, ambient_color);
    return 0;
}
