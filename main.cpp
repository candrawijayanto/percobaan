#include<windows.h>
#ifdef APPLE
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

GLUquadricObj *Cylinder;
GLUquadricObj *Disk;
GLfloat angle1;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);
void mouse (int button, int state, int x, int y);
void mouseMotion(int x, int y);
double pin=0;

float xrot = 0.0;
float yrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
int is_depth;

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1000,750);
    glutInitWindowPosition(250,80);
    glutCreateWindow("DANIEL HARLIANO SITORUS - 672018275");
    init();

    glutDisplayFunc(tampil);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
}
void tampil(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glRotatef(xrot, 1,0,0);
    glRotatef(yrot, 0,1,0);
    glPushMatrix();

  




    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();


}

void idle(){
    if(!mouseDown){
        xrot += 0.3;
        yrot += 0.4;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    }else{
        mouseDown = false;
    }
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
    case 'w':
    case 'W':
        xrot -=1;
        glTranslatef(0.0,0.0,xrot);
        break;
    case 'd':
    case 'D':
        yrot +=1;
        glTranslatef(yrot,0.0,0.0);
        break;
    case 's':
    case 'S':
        xrot +=1;
        glTranslatef(0.0,0.0,xrot);
        break;
    case 'a':
    case 'A':
        yrot -=1;
        glTranslatef(yrot,0.0,0.0);
        break;
    case 'p':
    case 'P':
            if(pin==0)
                pin=1;
            else
                pin=0;
        break;
    case '2':
        xrot +=1;
        glRotatef(xrot,1.0,0.0,0.0);
        break;
    case '8':
        xrot -=1;
        glRotatef(xrot,1.0,0.0,0.0);
        break;
    case '6':
        yrot +=1;
        glRotatef(yrot,0.0,1.0,0.0);
        break;
    case '4':
        yrot -=1;
        glRotatef(yrot,0.0,1.0,0.0);
        break;
    case '5':
        if(is_depth){
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
    }
    tampil();
}
void ukuran(int lebar,int tinggi){
    if (tinggi==0)tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport (0, 0, lebar, tinggi);
    gluPerspective(100.0, lebar/tinggi,5.0,900.0);
    glTranslatef(0.0,-40.0,-300.0);
    glMatrixMode(GL_MODELVIEW);
}
