#pragma once

#undef __STRICT_ANSI__
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

#include <GL/glut.h>

#include "Point3D.h"
#include "Utils.h"
#include <cmath>


class tetrahedron
{
private:
    std::vector<Point3D> points = {
            Point3D(-1.000/2,   1.000f/2,     -1.000f/2),
            Point3D(-1.000/2,   -1.000f/2,    -1.000f/2),
            Point3D(1.000/2,   -1.000f/2,    -1.000f/2),
            Point3D(1.000/2,   1.000f/2,    -1.000f/2),
            Point3D(-1.000/2,   1.000f/2,    0.000f/2),
            Point3D(-1.000/2,   -1.000f/2,    0.000f/2),
            Point3D(0.000/2,   -1.000f/2,    0.000f/2),
            Point3D(0.000/2,   1.000f/2,    0.000f/2),
            Point3D(1.000/2,   -1.000f/2,    0.000f/2),
            Point3D(1.000/2,   1.000f/2,    0.000f/2),
            Point3D(1.000/2,   -1.000f/2,    1.000f/2),
            Point3D(1.000/2,   1.000f/2,    1.000f/2),
            Point3D(0.000/2,   -1.000f/2,    1.000f/2),
            Point3D(0.000/2,   1.000f/2,    1.000f/2)
    };

    int faces[11][4] = {
            {   0, 1, 2, 3	},
            {   0, 1, 5, 4	},
            {   0, 4, 2, 3	},
            {	1, 2, 8, 5	},
            {	3, 2, 8, 9	},
            {	4, 5, 6, 7	},
            {	7, 9, 11, 13	},
            {	13, 12, 10, 11	},
            {	9, 8, 10, 11	},
            {	7, 6, 12, 13	},
            {	6, 8, 10, 12	}
    };

    int rotation_point = 3;
    int get_bottom_point();
    bool isRoll = false;
    Direction rolling_direction;
    void rolling();

public:
    tetrahedron();
    ~tetrahedron();

    bool isTextured = true;
    int keyp;
    void Draw();
    void Move(Point3D delta);
    void StartRolling(Direction direction);
    void StopRolling();
    void Rotate(float angle, Axis axis);
};

