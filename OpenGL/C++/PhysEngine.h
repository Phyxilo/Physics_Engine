#include <iostream>
#include <math.h>

#include "Algebra.h"

using namespace std;


class Body
{
  private:

  vector3 intPos;
  vector3 intVel;
  vector3 intAcc;

  vector3 pos;
  vector3 vel;
  vector3 acc;

  int i = 0;

  public:

  vector3 position;
  vector3 velocity;
  vector3 acceleration;

  float mass = 1;

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

  vector3 Acceleration (vector3 force)
  {
    vector3 acc;

    acc.Construct(force.vector[0]/mass, force.vector[1]/mass, force.vector[2]/mass);

    return acc;
  }

  void Kinematics(vector3 r, vector3 v, vector3 a, float t)
  {
//------------------------------1
    /*
    Pos = r;
    Vel = v;
    Acc = a;
    */
//------------------------------2
    if (i < 1)
    {
      intPos = r;
      intVel = v;
      intAcc = a;

      i++;
    }

    //Pos = intPos;
    //Vel = intVel;

//------------------------------1
    //pos = Position(Pos, Vel, Acc, t);
    //vel = Velocity(Vel, Acc, t);
//------------------------------2
    position = Position(intPos, intVel, intAcc, t);
    velocity = Velocity(intVel, intAcc, t);
    acceleration = a;

    //cout << "v-> "  << "X: " << v.vector[0] << ", Y: " << v.vector[1] << ", Z: " << v.vector[2] << endl;

    intPos = position;
    intVel = velocity;
    intAcc = acceleration;

    if (intPos.vector[1] <= -3.5f){cout << "Inside" << endl; intPos.vector[1] = -3.5f; intVel.vector[1] = -intVel.vector[1]*0.6f;}

    //return pos;
  }
};

class Friction
{
  public:

  float airDensity = 2;
  vector3 airFriction;

  vector3 Fluid(vector3 vel, vector3 area, float dragCoef)
  {
    airFriction.Construct(-airDensity*dragCoef*area.vector[0]*vel.vector[0]/2, -airDensity*dragCoef*area.vector[1]*vel.vector[1]/2, -airDensity*dragCoef*area.vector[2]*vel.vector[2]/2 );
  }
};
