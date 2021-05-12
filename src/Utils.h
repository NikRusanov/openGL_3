#pragma once

#include "Point3D.h"

enum Axis
{
    X,
    Y,
    //Z
};

enum Direction
{
    N, S, W, E
};

void CreateRotateMatrix(float* mtx, float angle, Axis axis);
