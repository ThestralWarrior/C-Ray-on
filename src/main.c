#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<omp.h>

#include "compute.h"
#include "structs.h"
#include "rendering.h"

int main() {
    int width = 400;
    int height = 400;

    Color sphere_color = (Color) {0.0f, 1.0f, 0.0f};
    Color light_color = (Color) {1.0f, 1.0f, 1.0f};
    Color ambient_color = (Color) {0.3f, 0.3f, 0.3f};

    Camera camera = {{0, 0, 1}, {0, 0, -1}};

    Sphere sphere1 = {(Vector3){0, 0, -10.0f}, 1};
    Sphere sphere2 = {(Vector3){-3, 1, -6.0f}, 1};
    Sphere sphere3 = {(Vector3){1, -1, -4.0f}, 1};

    Scene scene = (Scene){
        width,
        height,
        (Sphere[]){sphere1, sphere2, sphere3},
        &camera
    };

    Vector3 light_direction = {-1.0f, 0.0f, 0.0f};
    

    printf("Listing the contents of the scene.\n");
    for(int i = 0; i < 3; i++) {
        printf("(Sphere) Center: %f %f %f, Radius: %f, Colors: %f %f %f\n", scene.spheres[i].center.x, scene.spheres[i].center.y, scene.spheres[i].center.z, scene.spheres[i].radius);
    }
    printf("Starting rendering...\n");
    double start_time = omp_get_wtime();
    render(scene, 3, light_direction, light_color, sphere_color, ambient_color);
    double end_time = omp_get_wtime();
    printf("Rendering finished... Time taken %lfs.\n", end_time - start_time);
    return 0;
}
