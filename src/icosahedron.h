#pragma once

#include <cmath>
#include <vector>

#include <GL/glut.h>

#include "Point3D.h"
#include "Utils.h"
#include <cmath>

class Icosahedron
{
private:
    std::vector<Point3D> points =
    {
        Point3D(-1.000f/2,   0.000f/2,     1.000f/2),
        Point3D(1.000f/2,   0.000f/2,    1.000f/2),
        Point3D(-1.000f/2,   0.000f/2,    -1.000f/2),
        Point3D(1.000f/2,   0.000f/2,    -1.000f/2),
        Point3D(0.000f/2,   1.000f/2,  1.000f/2),
        Point3D(0.000f/2,   1.000f/2,  -1.000f/2),
        Point3D(0.000f/2,   -1.000f/2,  1.000f/2),
        Point3D(0.000f/2,   -1.000f/2,  -1.000f/2),
//        Point3D(1.000f/2,   1.000f/2,  0.000f/2),
//        Point3D(-1.000f/2,   1.000f/2,  0.000f/2),
//        Point3D(1.000f/2, -1.000f/2, 0.000f/2),
//        Point3D(-1.000f/2,   -1.000f/2,  0.000f/2),
    };

    int faces[8][3] = {
    {5,1,0},
    {5,2,0},
    {5,2,3},
    {5,3,1},

    {6,1,3},
    {6,2,3},
    {6,2,0},
    {6,0,1}
    //{6,2,3},
//    {8,2,0},
//    {8,2,3},
//    {8,3,1},
//    {0,2,1},
//    {1,2,3}

//    {6,7,8},
//    {9,10,11}
    };

    int rotation_point = 3;
    int get_bottom_point();
    bool isRoll = false;
    Direction rolling_direction;
    void rolling();
    
public:
    Icosahedron();
    ~Icosahedron() =default;
    
    bool isTextured = true;
    
    void Draw();
    void Move(Point3D delta);
    void StartRolling(Direction direction);
    void StopRolling();
    void Rotate(float angle, Axis axis);
};

