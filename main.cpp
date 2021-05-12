#include <GL/glut.h>
#include "src/icosahedron.h"

#include <string>

GLuint  texture_id;
struct texture
{
    int W;
    int H;
    unsigned char *Image;
} get_texture;

Icosahedron icosadreon;


GLfloat global_ambient[]    = { 0.0f, 0.0f, 0.0f, 1.0f };

GLfloat light_ambient[]	    = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat light_diffuse[]	    = { 0.5f, 0.5f, 0.5f, 0.1f };
GLfloat light_specular[]    = { 0.0f, 0.0f, 0.0f, 0.1f };
GLfloat light_position[]    = { 1.0, 1.0, 3.0 };
//GLfloat light_direction[]   = { 5.0, 1.0, 1.0 };
GLfloat light_direction[]   = { 5.0, 1.0, 10.0 };

const GLfloat mat_ambient[] =   { 0.2215,  0.3745,   0.2215 };
const GLfloat mat_diffuse[] =   { 0.17568, 0.61424,  0.17568 };
const GLfloat mat_specular[] =  { 0.433,   0.827811, 0.433 };
const GLfloat high_shininess[] = { 0.9f * 148 };

static long rotateN = 0;

int LoadTexture(char *FileName)
{
    FILE *F;
    if ((F = fopen(FileName, "rb")) == NULL)
        return 0;
    fseek(F, 18, SEEK_SET);
    fread(&(get_texture.W), 2, 1, F);
    fseek(F, 2, SEEK_CUR);
    fread(&(get_texture.H), 2, 1, F);

    printf("%d x %d\n", get_texture.W, get_texture.H);

    if ((get_texture.Image = (unsigned char *)malloc(sizeof(unsigned char) * 3 * get_texture.W * get_texture.H)) == NULL)
    {
        fclose(F);
        return 0;
    }
    fseek(F, 30, SEEK_CUR);
    fread(get_texture.Image, 3, get_texture.W * get_texture.H, F);

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, get_texture.W, get_texture.H, 0, GL_RGB, GL_UNSIGNED_BYTE, get_texture.Image);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, get_texture.W, get_texture.H, GL_RGB, GL_UNSIGNED_BYTE, get_texture.Image);
    free(get_texture.Image);
    fclose(F);

    return 1;
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
    case 't':
        icosadreon.isTextured = !icosadreon.isTextured;
        break;
    case 'w':
        icosadreon.StartRolling(N);
        break;
    case 'a':
        icosadreon.StartRolling(W);
        break;
    case 's':
        icosadreon.StartRolling(S);
        break;
    case 'd':
        icosadreon.StartRolling(E);
        break;
    case 'p':
        icosadreon.StopRolling();
        break;
    }
}

static void idle(void)
{
//    std::cout << rotateN << std::endl;
    glutPostRedisplay();
}

static void resize(int width, int height)
{
    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar * 0.7, ar * 0.7, -1.0, 1.0, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Draw field 
void drawPlane(void) {
//    glDisable(GL_COLOR_MATERIAL);
    glColor3f(0.5, 0.5, 0.5);

//    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, high_shininess);

    glBegin(GL_POLYGON);
        glVertex3d(-12, -12, 0);
        glVertex3d(12, -12, 0);
        glVertex3d(12, 12, 0);
        glVertex3d(-12, 12, 0);
    glEnd();

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glLoadIdentity();

    gluLookAt(9, 7, 5, 0, 0, 0, 0, 0, 1);

    glTranslatef(0.0, 0.0, -2.0);
    drawPlane();
    glTranslatef(0.0, 0.0, 2.0);

    glColor3f(1, 0, 0);
    glTranslatef(0.0, 0.0, -1.0);

//    glutSolidSphere(1,25,25);
    //glTranslatef(0.3, 0.8, 1.48);

    icosadreon.Draw();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(250, 0);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA);

    glutCreateWindow("tomilin course work");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glDepthMask(GL_TRUE);

    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    if (LoadTexture((char *)"./sbob.bmp") != 1)
        printf("ERROR WITH LOAD A TEXTURE\n");

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

//    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glutMainLoop();

    return 0;
}
