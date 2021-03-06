#ifndef _CUTILS_H
#define _CUTILS_H

#include "stdbool.h"
#include "time.h"

#define PI 3.14159265358979f

typedef struct point {
    float x, y;
} point;

typedef struct debug_data_t {
    float confidence;
    float data;
    point gradient_t;
    point normal_t;
    bool target_patch;
    bool source_patch;
} debug_data;

int within(int value, int minimum, int maximum);
int max(int a, int b);
int min(int a, int b);
int clamp(int value, int minimum, int maximum);
float norm(float x, float y);
float squared_distance3(unsigned char p[3], unsigned char q[3]);

void convoluion2D(float * src, int width, int height, float * kernel, int ksize, float * dst);

point get_ortogonal_to_contour(int x, int y, bool * mask, int width, int height);
static point vector_bisector(float ax, float ay, float bx, float by);
int within_c(int x, int y, int width, int height);

#endif
