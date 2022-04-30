#include <iostream>
#include <math.h>

using namespace std;

/*
class vector4
{
  public:

  float vector[4] = {0, 0, 0, 0};
  float originalVector[4] = {0, 0, 0, 0};

  void Construct(float i = 0, float j = 0, float k = 0, float w = 0)
  {
    vector[0] = i; originalVector[0] = i;
    vector[1] = j; originalVector[1] = j;
    vector[2] = k; originalVector[2] = k;
    vector[3] = k; originalVector[3] = w;
  }

  float Magnitude()
  {
    return sqrt(originalVector[0]*originalVector[0]
      + originalVector[1]*originalVector[1]
      + originalVector[2]*originalVector[2]
      + originalVector[3]*originalVector[3]);
  }

  void Normalize()
  {
    vector[0] = originalVector[0]/Magnitude();
    vector[1] = originalVector[1]/Magnitude();
    vector[2] = originalVector[2]/Magnitude();
    vector[3] = originalVector[3]/Magnitude();
  }

  void Reset()
  {
    vector[0] = originalVector[0];
    vector[1] = originalVector[1];
    vector[2] = originalVector[2];
    vector[3] = originalVector[3];
  }

};

class vector3
{
  public:

  float vector[3] = {0, 0, 0};
  float originalVector[3] = {0, 0, 0};

  void Construct(float i = 0, float j = 0, float k = 0)
  {
    vector[0] = i; originalVector[0] = i;
    vector[1] = j; originalVector[1] = j;
    vector[2] = k; originalVector[2] = k;
  }

  float Magnitude()
  {
    return sqrt(originalVector[0]*originalVector[0]
      + originalVector[1]*originalVector[1]
      + originalVector[2]*originalVector[2]);
  }

  void Normalize()
  {
    vector[0] = originalVector[0]/Magnitude();
    vector[1] = originalVector[1]/Magnitude();
    vector[2] = originalVector[2]/Magnitude();
  }

  void Reset()
  {
    vector[0] = originalVector[0];
    vector[1] = originalVector[1];
    vector[2] = originalVector[2];
  }

};

class vector2
{
  public:

  float vector[2] = {0, 0};
  float originalVector[2] = {0, 0};

  void Construct(float i = 0, float j = 0)
  {
    vector[0] = i; originalVector[0] = i;
    vector[1] = j; originalVector[1] = j;
  }

  float Magnitude()
  {
    return sqrt(originalVector[0]*originalVector[0]
      + originalVector[1]*originalVector[1]);
  }

  void Normalize()
  {
    vector[0] = originalVector[0]/Magnitude();
    vector[1] = originalVector[1]/Magnitude();
  }

  void Reset()
  {
    vector[0] = originalVector[0];
    vector[1] = originalVector[1];
  }

};
*/

class vector4
{
  public:

  float vector[4] = {0, 0, 0, 0};

  void Construct(float i = 0, float j = 0, float k = 0, float w = 0)
  {
    vector[0] = i;
    vector[1] = j;
    vector[2] = k;
    vector[3] = k;
  }

};

class vector3
{
  public:

  float vector[3] = {0, 0, 0};

  void Construct(float i = 0, float j = 0, float k = 0)
  {
    vector[0] = i;
    vector[1] = j;
    vector[2] = k;
  }

};

class vector2
{
  public:

  float vector[2] = {0, 0};

  void Construct(float i = 0, float j = 0)
  {
    vector[0] = i;
    vector[1] = j;
  }

};

struct Vector4Calc
{
  float Magnitude(vector4 vec)
  {
    return sqrt(vec.vector[0]*vec.vector[0]
      + vec.vector[1]*vec.vector[1]
      + vec.vector[2]*vec.vector[2]
      + vec.vector[3]*vec.vector[3]);
  }

  vector4 Normalize(vector4 vec)
  {
    vector4 norm;

    norm.Construct(vec.vector[0]/Magnitude(vec), vec.vector[1]/Magnitude(vec), vec.vector[2]/Magnitude(vec), vec.vector[2]/Magnitude(vec));

    return norm;
  }

  vector4 Add(vector4 vec1, vector4 vec2)
  {
    vector4 sum;

    sum.Construct(vec1.vector[0] + vec2.vector[0], vec1.vector[1] + vec2.vector[1], vec1.vector[2] + vec2.vector[2], vec1.vector[3] + vec2.vector[3]);

    return sum;
  }

} Vector4;

struct Vector3Calc
{
  float Magnitude(vector3 vec)
  {
    return sqrt(vec.vector[0]*vec.vector[0]
      + vec.vector[1]*vec.vector[1]
      + vec.vector[2]*vec.vector[2]);
  }

  vector3 Normalize(vector3 vec)
  {
    vector3 norm;

    norm.Construct(vec.vector[0]/Magnitude(vec), vec.vector[1]/Magnitude(vec), vec.vector[2]/Magnitude(vec));

    return norm;
  }

  vector3 Add(vector3 vec1, vector3 vec2)
  {
    vector3 sum;

    sum.Construct(vec1.vector[0] + vec2.vector[0], vec1.vector[1] + vec2.vector[1], vec1.vector[2] + vec2.vector[2]);

    return sum;
  }

} Vector3;

struct Vector2Calc
{
  float Magnitude(vector2 vec)
  {
    return sqrt(vec.vector[0]*vec.vector[0]
      + vec.vector[1]*vec.vector[1]);
  }

  vector2 Normalize(vector2 vec)
  {
    vector2 norm;

    norm.Construct(vec.vector[0]/Magnitude(vec), vec.vector[1]/Magnitude(vec));

    return norm;
  }

  vector2 Add(vector2 vec1, vector2 vec2)
  {
    vector2 sum;

    sum.Construct(vec1.vector[0] + vec2.vector[0], vec1.vector[1] + vec2.vector[1]);

    return sum;
  }

} Vector2;

/*
struct Vector4Calc
{
  float* Add(float* vec1, float* vec2)
  {
    float* sum = new float[4];

    sum[0] = vec1[0] + vec2[0];
    sum[1] = vec1[1] + vec2[1];
    sum[2] = vec1[2] + vec2[2];
    sum[3] = vec1[3] + vec2[3];

    return sum;
  }
} Vector4;

struct Vector3Calc
{
  float* Add(float* vec1, float* vec2)
  {
    float* sum = new float[3];

    sum[0] = vec1[0] + vec2[0];
    sum[1] = vec1[1] + vec2[1];
    sum[2] = vec1[2] + vec2[2];

    return sum;
  }
} Vector3;


struct Vector2Calc
{
  float* Add(float* vec1, float* vec2)
  {
    float* sum = new float[2];

    sum[0] = vec1[0] + vec2[0];
    sum[1] = vec1[1] + vec2[1];

    return sum;
  }
} Vector2;
*/
