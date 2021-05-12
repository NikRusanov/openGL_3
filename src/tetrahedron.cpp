//
// Created by nik on 5/12/21.
//

#include "tetrahedron.h"
//#include "OpenGL_Lab.cpp"

const GLfloat mat_ambient2[] = { 0.7f, 0.7f, 0.7f };
const GLfloat mat_diffuse2[] = { 0.1f, 0.1f, 0.1f };
const GLfloat mat_specular2[] = { 0.1f, 0.1f, 0.1f };
const GLfloat high_shininess2[] = { 1.0f };

tetrahedron::tetrahedron() {
    Point3D p = points[get_bottom_point()];
    Move(p.inverse());
}


tetrahedron::~tetrahedron() {
}

void tetrahedron::Draw()
{
    rolling();

    if (isTextured) {
        glDisable(GL_COLOR_MATERIAL);
        glEnable(GL_TEXTURE_2D);

        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient2);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse2);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular2);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess2);
        if (keyp == 0)
        {
            for (int i = 0; i < 14; i++)
            {
                points[i].x += 3.0f;
            }
            keyp = 1;
        }

        for (int i = 0; i < 11; i++) {
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

            glNormal3d(points[faces[i][3]].x, points[faces[i][3]].y, points[faces[i][3]].z);
            glTexCoord2d(0.85f, 1.3f);
            glVertex3d(points[faces[i][3]].x, points[faces[i][3]].y, points[faces[i][3]].z);

            glEnd();
        }
        glDisable(GL_TEXTURE_2D);
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    }
    else {
        glEnable(GL_COLOR_MATERIAL);
        glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

        glColor3f(0, 0, 0);
        glLineWidth(1);
        glPointSize(3);
        for (int i = 0; i < 11; i++) {
            glBegin(GL_TRIANGLES);

            glVertex3d(points[faces[i][0]].x , points[faces[i][0]].y, points[faces[i][0]].z);
            glVertex3d(points[faces[i][1]].x , points[faces[i][1]].y, points[faces[i][1]].z);
            glVertex3d(points[faces[i][2]].x , points[faces[i][2]].y, points[faces[i][2]].z);
            glVertex3d(points[faces[i][3]].x , points[faces[i][3]].y, points[faces[i][3]].z);

            glEnd();
        }

        glBegin(GL_POINTS);

        glVertex3d(points[2].x , points[2].y, points[2].z);

        glEnd();


        glDisable(GL_COLOR_MATERIAL);
    }

}

int tetrahedron::get_bottom_point() {
    double minZ = points[0].z;
    int bottom_point_idx = 0;
    for (int i = 1; i < 14; i++)
        if (points[i].z < minZ)
        {
            bottom_point_idx = i;
            minZ = points[i].z;
        }
    return bottom_point_idx;
}

void tetrahedron::rolling() {

    if (!isRoll) return;

    Point3D saved = points[rotation_point].copy();
    bool p1x, p2x, p3x, p4x, p5x, p6x, p7x, p8x, p9x, p10x, p11x, p12x, p13x, p14x, p1y, p2y, p3y, p4y, p5y, p6y, p7y, p8y, p9y, p10y, p11y, p12y, p13y, p14y;
    p1x = ((points[0].x >= 2.2 || points[0].x <= -2.2) || ((points[0].x <= 2.2 || points[0].x >= 2.2) && (points[0].y >= 2.2 || points[0].y <= -2.2)));
    p2x = ((points[1].x >= 2.2 || points[1].x <= -2.2) || ((points[1].x <= 2.2 || points[1].x >= 2.2) && (points[1].y >= 2.2 || points[1].y <= -2.2)));
    p3x = ((points[2].x >= 2.2 || points[2].x <= -2.2) || ((points[2].x <= 2.2 || points[2].x >= 2.2) && (points[2].y >= 2.2 || points[2].y <= -2.2)));
    p4x = ((points[3].x >= 2.2 || points[3].x <= -2.2) || ((points[3].x <= 2.2 || points[3].x >= 2.2) && (points[3].y >= 2.2 || points[3].y <= -2.2)));
    p5x = ((points[4].x >= 2.2 || points[4].x <= -2.2) || ((points[4].x <= 2.2 || points[4].x >= 2.2) && (points[4].y >= 2.2 || points[4].y <= -2.2)));
    p6x = ((points[5].x >= 2.2 || points[5].x <= -2.2) || ((points[5].x <= 2.2 || points[5].x >= 2.2) && (points[5].y >= 2.2 || points[5].y <= -2.2)));
    p7x = ((points[6].x >= 2.2 || points[6].x <= -2.2) || ((points[6].x <= 2.2 || points[6].x >= 2.2) && (points[6].y >= 2.2 || points[6].y <= -2.2)));
    p8x = ((points[7].x >= 2.2 || points[7].x <= -2.2) || ((points[7].x <= 2.2 || points[7].x >= 2.2) && (points[7].y >= 2.2 || points[7].y <= -2.2)));
    p9x = ((points[8].x >= 2.2 || points[8].x <= -2.2) || ((points[8].x <= 2.2 || points[8].x >= 2.2) && (points[8].y >= 2.2 || points[8].y <= -2.2)));
    p10x = ((points[9].x >= 2.2 || points[9].x <= -2.2) || ((points[9].x <= 2.2 || points[9].x >= 2.2) && (points[9].y >= 2.2 || points[9].y <= -2.2)));
    p11x = ((points[10].x >= 2.2 || points[10].x <= -2.2) || ((points[10].x <= 2.2 || points[10].x >= 2.2) && (points[10].y >= 2.2 || points[10].y <= -2.2)));
    p12x = ((points[11].x >= 2.2 || points[11].x <= -2.2) || ((points[11].x <= 2.2 || points[11].x >= 2.2) && (points[11].y >= 2.2 || points[11].y <= -2.2)));
    p13x = ((points[12].x >= 2.2 || points[12].x <= -2.2) || ((points[12].x <= 2.2 || points[12].x >= 2.2) && (points[12].y >= 2.2 || points[12].y <= -2.2)));
    p14x = ((points[13].x >= 2.2 || points[13].x <= -2.2) || ((points[13].x <= 2.2 || points[13].x >= 2.2) && (points[13].y >= 2.2 || points[13].y <= -2.2)));
    p1y = ((points[0].y >= 2.2 || points[0].y <= -2.2) || ((points[0].y <= 2.2 || points[0].y >= 2.2) && (points[0].x >= 2.2 || points[0].x <= -2.2)));
    p2y = ((points[1].y >= 2.2 || points[1].y <= -2.2) || ((points[1].y <= 2.2 || points[1].y >= 2.2) && (points[1].x >= 2.2 || points[1].x <= -2.2)));
    p3y = ((points[2].y >= 2.2 || points[2].y <= -2.2) || ((points[2].y <= 2.2 || points[2].y >= 2.2) && (points[2].x >= 2.2 || points[2].x <= -2.2)));
    p4y = ((points[3].y >= 2.2 || points[3].y <= -2.2) || ((points[3].y <= 2.2 || points[3].y >= 2.2) && (points[3].x >= 2.2 || points[3].x <= -2.2)));
    p5y = ((points[4].y >= 2.2 || points[4].y <= -2.2) || ((points[4].y <= 2.2 || points[4].y >= 2.2) && (points[4].x >= 2.2 || points[4].x <= -2.2)));
    p6y = ((points[5].y >= 2.2 || points[5].y <= -2.2) || ((points[5].y <= 2.2 || points[5].y >= 2.2) && (points[5].x >= 2.2 || points[5].x <= -2.2)));
    p7y = ((points[6].y >= 2.2 || points[6].y <= -2.2) || ((points[6].y <= 2.2 || points[6].y >= 2.2) && (points[6].x >= 2.2 || points[6].x <= -2.2)));
    p8y = ((points[7].y >= 2.2 || points[7].y <= -2.2) || ((points[7].y <= 2.2 || points[7].y >= 2.2) && (points[7].x >= 2.2 || points[7].x <= -2.2)));
    p9y = ((points[8].y >= 2.2 || points[8].y <= -2.2) || ((points[8].y <= 2.2 || points[8].y >= 2.2) && (points[8].x >= 2.2 || points[8].x <= -2.2)));
    p10y = ((points[9].y >= 2.2 || points[9].y <= -2.2) || ((points[9].y <= 2.2 || points[9].y >= 2.2) && (points[9].x >= 2.2 || points[9].x <= -2.2)));
    p11y = ((points[10].y >= 2.2 || points[10].y <= -2.2) || ((points[10].y <= 2.2 || points[10].y >= 2.2) && (points[10].x >= 2.2 || points[10].x <= -2.2)));
    p12y = ((points[11].y >= 2.2 || points[11].y <= -2.2) || ((points[11].y <= 2.2 || points[11].y >= 2.2) && (points[11].x >= 2.2 || points[11].x <= -2.2)));
    p13y = ((points[12].y >= 2.2 || points[12].y <= -2.2) || ((points[12].y <= 2.2 || points[12].y >= 2.2) && (points[12].x >= 2.2 || points[12].x <= -2.2)));
    p14y = ((points[13].y >= 2.2 || points[13].y <= -2.2) || ((points[13].y <= 2.2 || points[13].y >= 2.2) && (points[13].x >= 2.2 || points[13].x <= -2.2)));
    double k;
    switch (rolling_direction) {

        case N:
            if (keyp == 1)
            {
                if (p1x && p2x && p3x && p4x && p5x && p6x && p7x && p8x && p9x && p10x && p11x && p12x && p13x && p14x)
                {

                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(0.005f, X);
                    Move(saved);
                    break;
                }
                else
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(-0.05f, X);
                    Move(saved);
                    break;
                }
            }
            else
            {
                Move(points[rotation_point].inverse());
                k = (points[2].y - points[rotation_point].y) / 95.0f;
                Rotate(0.005f, X);
                Move(saved);
                break;
            }
        case S:
            if (keyp == 1)
            {
                if (p1x && p2x && p3x && p4x && p5x && p6x && p7x && p8x && p9x && p10x && p11x && p12x && p13x && p14x)
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(-0.005f, X);
                    Move(saved);
                    break;
                }
                else
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(0.05f, X);
                    Move(saved);
                    break;
                }
            }
            else
            {
                Move(points[rotation_point].inverse());
                k = (points[2].y - points[rotation_point].y) / 95.0f;
                Rotate(-0.005f, X);
                Move(saved);
                break;
            }
        case W:
            if (keyp == 1)
            {
                if (p1y && p2y && p3y && p4y && p5y && p6y && p7y && p8y && p9y && p10y && p11y && p12y && p13y && p14y)
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(0.005f, Y);
                    Move(saved);
                    break;
                }
                else
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(-0.05f, Y);
                    Move(saved);
                    break;
                }
            }
            else
            {
                Move(points[rotation_point].inverse());
                k = (points[2].y - points[rotation_point].y) / 95.0f;
                Rotate(0.005f, Y);
                Move(saved);
                break;
            }
        case E:
            if (keyp == 1)
            {
                if (p1y && p2y && p3y && p4y && p5y && p6y && p7y && p8y && p9y && p10y && p11y && p12y && p13y && p14y)
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(-0.005f, Y);
                    Move(saved);
                    break;
                }
                else
                {
                    Move(points[rotation_point].inverse());
                    k = (points[2].y - points[rotation_point].y) / 95.0f;
                    Rotate(0.05f, Y);
                    Move(saved);
                    break;
                }
            }
            else
            {
                Move(points[rotation_point].inverse());
                k = (points[2].y - points[rotation_point].y) / 95.0f;
                Rotate(-0.005f, Y);
                Move(saved);
                break;
            }
//        case D:
//            glTranslatef(0, 0, -0.1);
//            break;
    }

    int new_rotation_point = get_bottom_point();
    if (rotation_point == new_rotation_point) return;

    rotation_point = new_rotation_point;
    points[rotation_point].z = 0;
}


void tetrahedron::StartRolling(Direction direction) {
    rotation_point = get_bottom_point();
    rolling_direction = direction;
    isRoll = true;
}

void tetrahedron::StopRolling() {
    rotation_point = -1;
    isRoll = false;
}

void tetrahedron::Move(Point3D delta) {
    for (int i = 0; i < 14; i++) {

        //if((points[1].x > 2.2 && points[2].x > 2.2 && points[0].x > 2.2 && points[3].x > 2.2) || (points[0].x < -2.2 && points[1].x < -2.2 && points[2].x < -2.2 && points[3].x < -2.2))
        //{
        //	keyp = 1;
        //}
        //else if ((points[1].y > 2.2 && points[2].y > 2.2 && points[0].y > 2.2 && points[3].y > 2.2) || (points[0].y < -2.2 && points[1].y < -2.2 && points[2].y < -2.2 && points[3].y < -2.2))
        //{
        //	keyp = 1;
        //}
        points[i].x += delta.x;
        points[i].y += delta.y;
        points[i].z += delta.z;
    }
}

void tetrahedron::Rotate(float angle, Axis axis) {
    float newX, newY, newZ;
    float matrix[4][4];
    CreateRotateMatrix(&matrix[0][0], angle, axis);

    for (int i = 0; i < 14; i++) {
        newX = matrix[0][0] * points[i].x + matrix[1][0] * points[i].y + matrix[2][0] * points[i].z + matrix[3][0];
        newY = matrix[0][1] * points[i].x + matrix[1][1] * points[i].y + matrix[2][1] * points[i].z + matrix[3][1];
        newZ = matrix[0][2] * points[i].x + matrix[1][2] * points[i].y + matrix[2][2] * points[i].z + matrix[3][2];
        points[i].x = newX; points[i].y = newY; points[i].z = newZ;
    }
}
