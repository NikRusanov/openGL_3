#pragma once

typedef struct Point3D
{
    Point3D(double _x, double _y, double _z)
    {
        x = _x, y = _y; z = _z;
    }

    Point3D inverse()
    {
        return Point3D(-x, -y, -z);
    }

    Point3D copy()
    {
        return Point3D(x, y, z);
    }

    double x, y, z;
};

