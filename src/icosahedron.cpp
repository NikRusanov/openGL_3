#include <iostream>
#include "icosahedron.h"

const GLfloat mat_ambient[] = { 1.7f, 1.7f, 1.7f };
const GLfloat mat_diffuse[] = { 5.1f, 5.1f, 5.1f };
const GLfloat mat_specular[] = { 0.3f, 0.3f, 0.3f };
const GLfloat high_shininess[] = { 25.0f };

Icosahedron::Icosahedron()
{
    Point3D p = points[get_bottom_point()];
    Move(p.inverse());
}

void Icosahedron::Draw()
{
    rolling();

    if (isTextured)
    {
        glDisable(GL_COLOR_MATERIAL);

        glEnable(GL_TEXTURE_2D);
        glEnable(GL_LIGHTING);

        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);

        for (int i = 0; i < 8; i++)
        {
            std::cout << "x[ " << i <<  "] " << points[i].x << std::endl;
            std::cout << "y[ " << i <<  "] " << points[i].y<< std::endl;
            glBegin(GL_POLYGON);
            glNormal3d(points[faces[i][0]].x, points[faces[i][0]].y, points[faces[i][0]].z);
            glTexCoord2d(0.5f, 0.0f);
            glVertex3d(points[faces[i][0]].x, points[faces[i][0]].y, points[faces[i][0]].z);

            glNormal3d(points[faces[i][1]].x, points[faces[i][1]].y, points[faces[i][1]].z);
            glTexCoord2d(1.0f, 0.3f);
            glVertex3d(points[faces[i][1]].x, points[faces[i][1]].y, points[faces[i][1]].z);

            glNormal3d(points[faces[i][2]].x, points[faces[i][2]].y, points[faces[i][2]].z);
            glTexCoord2d(0.6f, 1.0f);
            glVertex3d(points[faces[i][2]].x, points[faces[i][2]].y, points[faces[i][2]].z);
            glEnd();
        }
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    }
    else
    {
        glDisable(GL_LIGHTING);
        glColor3f(1.0, 1.0, 1.0);
        for (int i = 0; i < 8; i++)
        {
            glBegin(GL_TRIANGLES);
            glVertex3d(points[faces[i][0]].x, points[faces[i][0]].y, points[faces[i][0]].z);
            glVertex3d(points[faces[i][1]].x, points[faces[i][1]].y, points[faces[i][1]].z);
            glVertex3d(points[faces[i][2]].x, points[faces[i][2]].y, points[faces[i][2]].z);
            glEnd();
        }
        //    glBegin(GL_POINTS);
        //        glVertex3d(points[5].x, points[5].y, points[5].z);
        //    glEnd();
    }
}

int Icosahedron::get_bottom_point()
{
    double minZ = points[0].z;
    int bottom_point_idx = 0;
    for (int i = 1; i < 8; i++)
    {
        if (points[i].z < minZ)
        {
            bottom_point_idx = i;
            minZ = points[i].z;
        }
    }
    return bottom_point_idx;
}

void Icosahedron::rolling()
{
    if (!isRoll) return;

    Point3D saved = points[rotation_point].copy();
//    std::cout << "x=" << saved.x << std::endl;
//
//    std::cout << "y=" << saved.y<< std::endl;
    switch (rolling_direction)
    {


        case N:

            Move(points[rotation_point].inverse());
            Rotate(0.065f, X);
            Move(saved);
            break;
        case S:
            Move(points[rotation_point].inverse());
            Rotate(-0.065f, X);
            Move(saved);
            break;
        case W:
            Move(points[rotation_point].inverse());
            Rotate(0.065f, Y);
            Move(saved);
            break;
        case E:
            Move(points[rotation_point].inverse());
            Rotate(-0.065f, Y);
            Move(saved);
            break;
    }

    int new_rotation_point = get_bottom_point();
    if (rotation_point == new_rotation_point) return;

    rotation_point = new_rotation_point;
    points[rotation_point].z = 0;
}


void Icosahedron::StartRolling(Direction direction)
{
    rotation_point = get_bottom_point();
    rolling_direction = direction;
    isRoll = true;
}

void Icosahedron::StopRolling()
{
    rotation_point = -1;
    isRoll = false;
}

void Icosahedron::Move(Point3D delta)
{

        for (int i = 0; i < 8; i++)
        {

            points[i].x += delta.x;
            points[i].y += delta.y;
            points[i].z += delta.z;
        }
}

void Icosahedron::Rotate(float angle, Axis axis)
{
    float newX, newY, newZ;
    float matrix[4][4];
    CreateRotateMatrix(&matrix[0][0], angle, axis);

    for (int i = 0; i < 8; i++)
    {
        newX = matrix[0][0] * points[i].x + matrix[1][0] * points[i].y + matrix[2][0] * points[i].z + matrix[3][0];
        newY = matrix[0][1] * points[i].x + matrix[1][1] * points[i].y + matrix[2][1] * points[i].z + matrix[3][1];
        newZ = matrix[0][2] * points[i].x + matrix[1][2] * points[i].y + matrix[2][2] * points[i].z + matrix[3][2];
        points[i].x = newX; points[i].y = newY; points[i].z = newZ;
    }
}
