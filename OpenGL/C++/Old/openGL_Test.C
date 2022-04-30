#include <iostream>
#include <GL/glut.h>
#include <math.h>

#include "PhysEngine.h"
//#include "Algebra.h"

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

float* position;
float* velocity;
float* acceleration;

Body obj;

vector3 posVec;
vector3 velVec;
vector3 accVec;
vector3 rot3;
vector3 forceVec;

vector3 pos3;
vector3 vel3;
vector3 acc3;

float timeElapsed = 0;
float timeInt = 0;

void Start()
{
  cout << "Start\n" << "-----------------------------------------" << endl;
  posVec.Construct(-30, 0, -80);
  velVec.Construct(5, 20, 5);
  accVec.Construct(0, -9.81f, 0);
  rot3.Construct(0, 0, 0);
  forceVec.Construct(0, 0, 0);


  /*
  position = posVec.vector;
  velocity = velVec.vector;
  acceleration = accVec.vector;
  */
  pos3 = posVec;
  vel3 = velVec;
  acc3 = accVec;

}

void Update()
{
  timeInt = deltaTime();
  timeElapsed += timeInt;
  if (timeElapsed < 15)
  {
    cout << "Update: " << timeElapsed << "\n"
    << "-----------------------------------------" << endl;
    /*
    obj.Kinematics(position, velocity, acceleration, timeInt);

    position = obj.pos;
    velocity = obj.vel;
    */

    obj.Kinematics(pos3, vel3, Vector3.Add(accVec, obj.Acceleration(forceVec, 2)), timeInt);

    pos3.Construct(obj.pos.vector[0], obj.pos.vector[1], obj.pos.vector[2]);
    vel3.Construct(obj.vel.vector[0], obj.vel.vector[1], obj.vel.vector[2]);

    //cout << "Position-> " << "X: " << position[0] << ", Y: " << position[1] << ", Z: " << position[2] << endl;
    //cout << "Velocity-> " << "X: " << velocity[0] << ", Y: " << velocity[1] << ", Z: " << velocity[2] << endl;

    //cout << "Position-> " << "X: " << pos3.vector[0] << ", Y: " << pos3.vector[1] << ", Z: " << pos3.vector[2] << endl;
    //cout << "Velocity-> " << "X: " << vel3.vector[0] << ", Y: " << vel3.vector[1] << ", Z: " << vel3.vector[2] << endl;

    //if (position[1] <= -0.5f){cout << "Inside" << endl; position[1] = -0.5f; velocity[1] = -velocity[1]*0.6f;}

    if (pos3.vector[1] <= -3.5f){cout << "Inside" << endl; pos3.vector[1] = -3.5f; vel3.vector[1] = -vel3.vector[1]*0.6f;}

    //cout << Vector3.Add(position, velocity)[1] << endl;
    //cout << Vector3.Normalize(velVec).vector[1] << endl;

  }

}


void idle(void)
{

	//xRotated += 0.01;
	//yRotated += 0.01;
  //zRotated += 0.01;
  Update();
  display();
}

int main (int argc, char **argv)
{
    Start();
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutCreateWindow("Solid Sphere");
    xRotated = yRotated = zRotated = 30.0;

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
  Projectile(pos3, rot3);
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
