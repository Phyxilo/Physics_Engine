#include <iostream>
#include <math.h>

#include "Algebra.h"

using namespace std;

/*
float posFunction(float r, float v, float a, float t)
{
  return r + v*t + (1/2)*a*t*t;
}

float velFunction(float v, float a, float t)
{
  return v + a*t;
}
*/

class Body
{
  /*
  private:
  float *Pos = new float[3];
  float *Vel = new float[3];
  float *Acc = new float[3];

  public:
  float* pos = new float[3];
  float* vel = new float[3];
  float* acc = new float[3];

  public:

  float* Position(float* r, float* v, float* a, float t)
  {
    float* pos = new float[3];

    pos[0] = r[0] + v[0]*t + (a[0]*t*t)/2;
    pos[1] = r[1] + v[1]*t + (a[1]*t*t)/2;
    pos[2] = r[2] + v[2]*t + (a[2]*t*t)/2;

    return pos;
  }

  float* Velocity(float* v, float* a, float t)
  {
    float* vel = new float[3];

    vel[0] = v[0] + a[0]*t;
    vel[1] = v[1] + a[1]*t;
    vel[2] = v[2] + a[2]*t;

    return vel;
  }

  float* Acceleration (float* force, float mass)
  {
    float* acc = new float[3];

    acc[0] = force[0]/mass;
    acc[1] = force[1]/mass;
    acc[2] = force[2]/mass;

    return acc;
  }

  float* Kinematics(float* r, float* v, float* a, float t)
  {

    Pos[0] = r[0]; Pos[1] = r[1]; Pos[2] = r[2];
    Vel[0] = v[0]; Vel[1] = v[1]; Vel[2] = v[2];
    Acc[0] = a[0]; Acc[1] = a[1]; Acc[2] = a[2];

    pos[0] = Position(Pos, Vel, Acc, t)[0]; pos[1] = Position(Pos, Vel, Acc, t)[1]; pos[2] = Position(Pos, Vel, Acc, t)[2];
    vel[0] = Velocity(Vel, Acc, t)[0]; vel[1] = Velocity(Vel, Acc, t)[1]; vel[2] = Velocity(Vel, Acc, t)[2];

    return pos;
  }
  */

  private:
  vector3 Pos;
  vector3 Vel;
  vector3 Acc;

  public:
  vector3 pos;
  vector3 vel;
  vector3 acc;

  public:

  vector3 Position(vector3 r, vector3 v, vector3 a, float t)
  {
    vector3 pos;

    pos.Construct(r.vector[0] + v.vector[0]*t + (a.vector[0]*t*t)/2,
    r.vector[1] + v.vector[1]*t + (a.vector[1]*t*t)/2,
    r.vector[2] + v.vector[2]*t + (a.vector[2]*t*t)/2);

    return pos;
  }

  vector3 Velocity(vector3 v, vector3 a, float t)
  {
    vector3 vel;

    vel.Construct(v.vector[0] + a.vector[0]*t,
    v.vector[1] + a.vector[1]*t,
    v.vector[2] + a.vector[2]*t);

    return vel;
  }

  vector3 Acceleration (vector3 force, float mass)
  {
    vector3 acc;

    acc.Construct(force.vector[0]/mass, force.vector[1]/mass, force.vector[2]/mass);

    return acc;
  }

  vector3 Kinematics(vector3 r, vector3 v, vector3 a, float t)
  {
    Pos.Construct(r.vector[0], r.vector[1], r.vector[2]);
    Vel.Construct(v.vector[0], v.vector[1], v.vector[2]);
    Acc.Construct(a.vector[0], a.vector[1], a.vector[2]);

    pos.Construct(Position(Pos, Vel, Acc, t).vector[0], Position(Pos, Vel, Acc, t).vector[1], Position(Pos, Vel, Acc, t).vector[2]);
    vel.Construct(Velocity(Vel, Acc, t).vector[0], Velocity(Vel, Acc, t).vector[1], Velocity(Vel, Acc, t).vector[2]);

    return pos;
  }
};
