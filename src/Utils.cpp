#include "Utils.h"
#include <cmath>

void CreateRotateMatrix(float* mtx, float angle, Axis axis)
{
    float* ptr = mtx;
    switch (axis)
    {
        case X:
            *(ptr++) = 1; *(ptr++) = 0;             *(ptr++) = 0;           *(ptr++) = 0;
            *(ptr++) = 0; *(ptr++) = cos(angle);    *(ptr++) = sin(angle);  *(ptr++) = 0;
            *(ptr++) = 0; *(ptr++) = -sin(angle);   *(ptr++) = cos(angle);  *(ptr++) = 0;
            *(ptr++) = 0; *(ptr++) = 0;             *(ptr++) = 0;           *(ptr++) = 1;
            break;
        case Y:
            *(ptr++) = cos(angle);  *(ptr++) = 0;   *(ptr++) = -sin(angle); *(ptr++) = 0;
            *(ptr++) = 0;           *(ptr++) = 1;   *(ptr++) = 0;           *(ptr++) = 0;
            *(ptr++) = sin(angle);  *(ptr++) = 0;   *(ptr++) = cos(angle);  *(ptr++) = 0;
            *(ptr++) = 0;           *(ptr++) = 0;   *(ptr++) = 0;           *(ptr++) = 1;
            break;
//        case Z:
//            *(ptr++) = cos(angle);  *(ptr++) = sin(angle);  *(ptr++) = 0;   *(ptr++) = 0;
//            *(ptr++) = -sin(angle); *(ptr++) = cos(angle);  *(ptr++) = 0;   *(ptr++) = 0;
//            *(ptr++) = 0;           *(ptr++) = 0;           *(ptr++) = 1;   *(ptr++) = 0;
//            *(ptr++) = 0;           *(ptr++) = 0;           *(ptr++) = 0;   *(ptr++) = 1;
//        break;
    }
}
