#include <iostream>
#include <GL/glut.h>
#include <math.h>

#include "PhysEngine.h"

using namespace std;

GLfloat color[3] = {1,1,1};

GLfloat xRotated, yRotated, zRotated;
GLfloat xPos, yPos, zPos;
GLdouble radius=1;

void Ground(void);
void Projectile(vector3 objPos, vector3 objRot);
void display(void);
void reshape(int x, int y);

int oldT = 0;
int t = 0;
float deltaTime ()
{
  float dt;
  t = glutGet(GLUT_ELAPSED_TIME);
  dt = (t - oldT) / 1000.0;
  oldT = t;
  glutPostRedisplay();
  oldT = glutGet(GLUT_ELAPSED_TIME);

  return dt;
}

Body obj;
Friction air;

vector3 posVec;
vector3 velVec;
vector3 accVec;
vector3 rot3;
vector3 forceVec;

float timeElapsed = 0;
float timeInt = 0;

vector3 test1;
vector3 test2;
vector3 test3;

matrix3 mat1Test;
matrix3 mat2Test;

void Start()
{
  cout << "Start\n" << "-----------------------------------------" << endl;
  posVec.Construct(-30, -3.4, -80);
  velVec.Construct(5, 20, 5);
  accVec.Construct(0, -9.81f, 0);
  rot3.Construct(0, 0, 0);
  forceVec.Construct(0, 0, 0);

  test2.Construct(0.75f, 0.75f, 0.75f);
  air.airDensity = 1;

}

void Update()
{
  timeInt = deltaTime();
  timeElapsed += timeInt;
  if (timeElapsed < 15)
  {
    cout << "Update: " << timeElapsed << "\n"
    << "-----------------------------------------" << endl;
    //cout << "Position-> "  << "X: " << obj.position.vector[0] << ", Y: " << obj.position.vector[1] << ", Z: " << obj.position.vector[2] << endl;

    //air.Fluid(obj.velocity, test2, 1);
    Vector3.Debug(obj.velocity);

    obj.mass = 2;
    obj.Kinematics(posVec, velVec, Vector3.Add(accVec, air.airFriction), timeInt);

    //pos3 = obj.pos;
    //vel3 = obj.vel;
    //cout << "Pos-> "  << "X: " << obj.Pos.vector[0] << ", Y: " << obj.Pos.vector[1] << ", Z: " << obj.Pos.vector[2] << endl;
    //if (pos3.vector[1] <= -3.5f){cout << "Inside" << endl; pos3.vector[1] = -3.5f; vel3.vector[1] = -vel3.vector[1]*0.6f;}

    mat1Test.Construct(-10, 5, 4, 5, -7, 9, 8, 12, -11);
    mat2Test.Construct(-5, -15, 3, 2, 0, 19, 4, -2, 14);

    //Matrix3.Debug(Matrix3.Transpose(mat1Test));

  }

}


void idle(void)
{
  Update();
  display();
}

int main (int argc, char **argv)
{
    Start();
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutCreateWindow("Solid Sphere");

    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
	  glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}

void display(void)
{
  glMatrixMode(GL_MODELVIEW);
  // clear the drawing buffer.
  glClear(GL_COLOR_BUFFER_BIT);
  // clear the identity matrix.
  glLoadIdentity();
  // traslate the draw by z = -4.0
  // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
  Ground();
  Projectile(obj.position, rot3);
  //Test();

  glFlush();
  // sawp buffers called because we are using double buffering
  // glutSwapBuffers();
  xPos++;
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40,(GLdouble)x/(GLdouble)y,0.6,1000.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void Projectile(vector3 objPos, vector3 objRot)
{
  glPushMatrix();

  //glTranslatef(-35 + position[0], position[1], -80.0 + position[2]);
  glTranslatef(objPos.vector[0], objPos.vector[1] , objPos.vector[2]);
  // Red color used to draw.
  glColor3f(0.9, 0.3, 0.2);
  // changing in transformation matrix.
  // rotation about X axis
  glRotatef(objRot.vector[0],1.0,0.0,0.0);
  // rotation about Y axis
  glRotatef(objRot.vector[1],0.0,1.0,0.0);
  // rotation about Z axis
  glRotatef(objRot.vector[2],0.0,0.0,1.0);
  // scaling transfomation
  glScalef(1.0,1.0,1.0);
  // built-in (glut library) function , draw you a sphere.
  glutSolidSphere(radius,20,20);
  // Flush buffers to screen
  glPopMatrix();
}

void Ground(void)
{
  glPushMatrix();
  glTranslatef(0.0,-0.5f,0.0);

  glBegin(GL_POLYGON);
  glColor3fv(color);
  glVertex3f(  10, 0, -10 );
  glVertex3f(  10, 0,  10 );
  glVertex3f( -10, 0,  10 );
  glVertex3f( -10, 0, -10 );

  glEnd();

  glPopMatrix();
}
