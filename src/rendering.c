#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rendering.h"
#include "compute.h"
#include "output.h"
#include "sphere.h"

Color shade(Sphere sphere, Vector3 point, Vector3 normal, Vector3 light_direction, Color light, Color object, Color ambient) {
    Vector3 unit_normal = normalize(normal);
    Vector3 unit_light_direction = normalize(light_direction);
    float cosine = dot(unit_normal, unit_light_direction);
    if(cosine < 0) cosine = 0.0f;
    Color ambientLightContribution = (Color) {
        object.r * ambient.r,
        object.g * ambient.g,
        object.b * ambient.b
    };
    Color diffusedLightContribution = (Color) {
        light.r * object.r * cosine,
        light.g * object.g * cosine,
        light.b * object.b * cosine
    };
    Color color = (Color) {
        ambientLightContribution.r + diffusedLightContribution.r,
        ambientLightContribution.g + diffusedLightContribution.g,
        ambientLightContribution.b + diffusedLightContribution.b
    };
    color.r = fminf(fmaxf(color.r, 0.0f), 1.0f);
    color.g = fminf(fmaxf(color.g, 0.0f), 1.0f);
    color.b = fminf(fmaxf(color.b, 0.0f), 1.0f);
    return color;
}

void renderSingleSphereOnly(int width, int height, Camera camera, Sphere sphere, Vector3 light_direction, Color light, Color object, Color ambient) {
    Color *image = malloc(width * height * sizeof(Color));
    if(image == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            float u = (float)x / (width - 1) * 2.0f - 1.0f;
            float v = 1.0f - (float)y / (height - 1) * 2.0f;
            Ray ray;
            ray.origin = camera.position;
            ray.direction = normalize((Vector3){u, v, -1.0f});
            float t1, t2;
            if(intersect_ray_sphere(ray, sphere, &t1, &t2)) {
                float t = t1 < t2 ? t1 : t2;
                Vector3 intersection = add(ray.origin, scale(ray.direction, t));
                Vector3 normal = normalize(sub(intersection, sphere.center));
                Color color = shade(sphere, intersection, normal, light_direction, light, object, ambient);
                image[y * width + x] = color;
            } else {
                image[y * width + x] = (Color) {0.5294f, 0.8078f, 0.9216f};
            }
        }
    }
    save_ppm_format(image, width, height);
}


void render(int width, int height, Camera camera, Scene scene, int sphere_count, Vector3 light_direction, Color light, Color object, Color ambient) {
    Color *image = malloc(width * height * sizeof(Color));
    if(image == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            float u = (float)x / (width - 1) * 2.0f - 1.0f;
            float v = 1.0f - (float)y / (height - 1) * 2.0f;
            Ray ray;
            ray.origin = camera.position;
            ray.direction = normalize((Vector3){u, v, -1.0f});
            float t;
            Sphere sphere;
            if(intersect_ray_spheres(ray, scene.spheres, sphere_count, &t, &sphere)) {
                Vector3 intersection = add(ray.origin, scale(ray.direction, t));
                Vector3 normal = normalize(sub(intersection, sphere.center));
                Color color = shade(sphere, intersection, normal, light_direction, light, object, ambient);
                image[y * width + x] = color;
            } else {
                image[y * width + x] = (Color) {0.5294f, 0.8078f, 0.9216f};
            }
            
        }
    }
    save_ppm_format(image, width, height);
}