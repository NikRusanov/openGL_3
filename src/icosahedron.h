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
        Point3D(1.000f/2,   1.000f/2,  0.000f/2),
        Point3D(-1.000f/2,   1.000f/2,  0.000f/2),
        Point3D(1.000f/2, -1.000f/2, 0.000f/2),
        Point3D(-1.000f/2,   -1.000f/2,  0.000f/2),
    };

    int faces[20][3] =
    {

        //{9,6,8},
      //  {6,9,5},
        //{6,5,8},

        //{9,6,4}


            {9,8,6,},
            {7,8,6},
            {6,9,5},
            {5,9,8}
            //    {8,5,9},
       // {5,9,8},

//        {6,9,5},
//        {6,5,8},
//        {9,5,4},
//        {4,5,8},
//
//        {4,8,1},
//        {8,10,1},
//
//        {8,3,10},
//        {5,3,8},
//
//        {5,2,3},
//        {2,7,3},
//        {7,10,3},
//        {7,6,10},
//        {7,11,6},
//        {11,0,6},
//        {0,1,6},
//        {6,1,10},
//        {9,0,11},
//        {9,11,2},
//        {9,2,5},
//        {7,2,11}
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

