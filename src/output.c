#include <stdio.h>
#include <stdlib.h>

#include "output.h"

void save_ppm_format(Color *image, int width, int height, char *name) {
    FILE *fptr = fopen(name, "wb");
    if(fptr == NULL) {
        fprintf(stderr, "Failed to open file.\n");
        exit(2);
    }
    fprintf(fptr, "P6\n%d %d\n255\n", width, height);
    for(int i = 0; i < width * height; i++) {
        unsigned char r = (unsigned char) (image[i].r * 255);
        unsigned char g = (unsigned char) (image[i].g * 255);
        unsigned char b = (unsigned char) (image[i].b * 255);
        fwrite(&r, 1, 1, fptr);
        fwrite(&g, 1, 1, fptr);
        fwrite(&b, 1, 1, fptr);
    }
    fclose(fptr);
    printf("Image generated at %s\n", name);
}