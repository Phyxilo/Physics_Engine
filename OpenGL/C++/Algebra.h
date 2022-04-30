#include <iostream>
#include <math.h>

#define Debug(vec) debug(vec, #vec)
#define Pi 3.14159265
#define rad2Deg 180/Pi
#define deg2Rad Pi/180

using namespace std;


//---------------------Vector---------------------

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

  void Zero(void)
  {
    vector[0] = 0;
    vector[1] = 0;
    vector[2] = 0;
    vector[3] = 0;
  }

  void X(float i){ vector[0] = i;}
  void Y(float j){ vector[1] = j;}
  void Z(float k){ vector[2] = k;}
  void W(float w){ vector[3] = w;}

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

  void Zero(void)
  {
    vector[0] = 0;
    vector[1] = 0;
    vector[2] = 0;
  }

  void Translate(float x, float y, float z)
  {
    vector3 translated;

    translated.Construct(vector[0]+x, vector[1]+y, vector[2]+z);

    vector[0] = translated.vector[0]; vector[1] = translated.vector[1]; vector[2] = translated.vector[2];
  }

  void Rotate(float x, float y, float z)
  {
    vector3 rotated;

    rotated.Construct(vector[0]*(cos(x)*cos(y)) + vector[1]*(cos(x)*sin(y)*sin(z)-sin(x)*cos(z)) + vector[2]*(cos(x)*sin(y)*cos(z)+sin(x)*sin(z)),
                      vector[0]*(sin(x)*cos(y)) + vector[1]*(sin(x)*sin(y)*sin(z)+cos(x)*cos(z)) + vector[2]*(sin(x)*sin(y)*cos(z)-cos(x)*sin(z)),
                      -vector[0]*sin(y) + vector[1]*(cos(y)*sin(z)) + vector[2]*(cos(y)*cos(z)));

    vector[0] = rotated.vector[0]; vector[1] = rotated.vector[1]; vector[2] = rotated.vector[2];
  }

  void Scale(float x, float y, float z)
  {
    vector3 scaled;

    scaled.Construct(vector[0]*x, vector[1]*y, vector[2]*z);

    vector[0] = scaled.vector[0]; vector[1] = scaled.vector[1]; vector[2] = scaled.vector[2];
  }

  void X(float i){ vector[0] = i;}
  void Y(float j){ vector[1] = j;}
  void Z(float k){ vector[2] = k;}

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

  void Zero(void)
  {
    vector[0] = 0;
    vector[1] = 0;
  }

  void X(float i){ vector[0] = i;}
  void Y(float j){ vector[1] = j;}

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

  vector4 Multiply(vector4 vec, float mult)
  {
    vector4 res;

    res.Construct(vec.vector[0] * mult, vec.vector[1] * mult, vec.vector[2] * mult, vec.vector[3] * mult);

    return res;
  }

  float Dot (vector4 vec1, vector4 vec2)
  {
    return vec1.vector[0]*vec2.vector[0]
      + vec1.vector[1]*vec2.vector[1]
      + vec1.vector[2]*vec2.vector[2]
      + vec1.vector[3]*vec2.vector[3];
  }

  vector4 Inverse (vector4 vec)
  {
    vector4 inv;

    inv.Construct(-vec.vector[0], -vec.vector[1], -vec.vector[2], -vec.vector[3]);

    return inv;
  }

  float Angle(vector4 vec1, vector4 vec2)
  {
    return acos(Dot(vec1, vec2)/(Magnitude(vec1)*Magnitude(vec2)));
  }

  void debug(vector4 vec, const char *name)
  {
    cout << name << "(Vector4) => " << "X: " << vec.vector[0] << ", Y: " << vec.vector[1] << ", Z: " << vec.vector[2] << ", W: " << vec.vector[3] << endl;
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

  vector3 Multiply(vector3 vec, float mult)
  {
    vector3 res;

    res.Construct(vec.vector[0] * mult, vec.vector[1] * mult, vec.vector[2] * mult);

    return res;
  }

  float Dot (vector3 vec1, vector3 vec2)
  {
    return vec1.vector[0]*vec2.vector[0]
      + vec1.vector[1]*vec2.vector[1]
      + vec1.vector[2]*vec2.vector[2];
  }

  vector3 Cross (vector3 vec1, vector3 vec2)
  {
    vector3 crs;

    crs.Construct((vec1.vector[1] * vec2.vector[2]) - (vec2.vector[1] * vec1.vector[2]),
      (vec2.vector[0] * vec1.vector[2]) - (vec1.vector[0] * vec2.vector[2]),
      (vec1.vector[0] * vec2.vector[1]) - (vec2.vector[0] * vec1.vector[1]));

    return crs;
  }

  vector3 Inverse (vector3 vec)
  {
    vector3 inv;

    inv.Construct(-vec.vector[0], -vec.vector[1], -vec.vector[2]);

    return inv;
  }

  float Angle(vector3 vec1, vector3 vec2)
  {
    return acos(Dot(vec1, vec2)/(Magnitude(vec1)*Magnitude(vec2)));
  }

  void debug(vector3 vec, const char *name)
  {
    cout << name << "(Vector3) => " << "X: " << vec.vector[0] << ", Y: " << vec.vector[1] << ", Z: " << vec.vector[2] << endl;
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

  vector2 Multiply(vector2 vec, float mult)
  {
    vector2 res;

    res.Construct(vec.vector[0] * mult, vec.vector[1] * mult);

    return res;
  }

  float Dot (vector2 vec1, vector2 vec2)
  {
    return vec1.vector[0]*vec2.vector[0]
      + vec1.vector[1]*vec2.vector[1];
  }

  vector2 Inverse (vector2 vec)
  {
    vector2 inv;

    inv.Construct(-vec.vector[0], -vec.vector[1]);

    return inv;
  }

  float Angle(vector2 vec1, vector2 vec2)
  {
    return acos(Dot(vec1, vec2)/(Magnitude(vec1)*Magnitude(vec2)));
  }

  void debug(vector2 vec, const char *name)
  {
    cout << name << "(Vector2) => " << "X: " << vec.vector[0] << ", Y: " << vec.vector[1] << endl;
  }

} Vector2;

//---------------------Matrix---------------------

class matrix4
{
  public:

  float matrix[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  void Construct(float row11, float row12, float row13, float row14, float row21, float row22, float row23, float row24,
     float row31, float row32, float row33, float row34, float row41, float row42, float row43, float row44)
  {
    matrix[0][0] = row11; matrix[0][1] = row12; matrix[0][2] = row13; matrix[0][3] = row14;
    matrix[1][0] = row21; matrix[1][1] = row22; matrix[1][2] = row23; matrix[1][3] = row24;
    matrix[2][0] = row31; matrix[2][1] = row32; matrix[2][2] = row33; matrix[2][3] = row34;
    matrix[3][0] = row41; matrix[2][1] = row42; matrix[2][2] = row43; matrix[2][3] = row44;

  }

  void Zero()
  {
    matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
    matrix[1][0] = 0; matrix[1][1] = 0; matrix[1][2] = 0; matrix[1][3] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0; matrix[2][3] = 0;
    matrix[3][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0; matrix[2][3] = 0;
  }

  void Identity()
  {
    matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
    matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0;
    matrix[3][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0; matrix[2][3] = 1;
  }

  void Row1(float row11, float row12, float row13, float row14)
  {
    matrix[0][0] = row11; matrix[0][1] = row12; matrix[0][2] = row13; matrix[0][3] = row14;
  }
  void Row2(float row21, float row22, float row23, float row24)
  {
    matrix[1][0] = row21; matrix[1][1] = row22; matrix[1][2] = row23; matrix[1][3] = row24;
  }
  void Row3(float row31, float row32, float row33, float row34)
  {
    matrix[2][0] = row31; matrix[2][1] = row32; matrix[2][2] = row33; matrix[2][3] = row34;
  }
  void Row4(float row41, float row42, float row43, float row44)
  {
    matrix[3][0] = row41; matrix[3][1] = row42; matrix[3][2] = row43; matrix[3][3] = row44;
  }

};

class matrix3
{
  public:

  float matrix[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  void Construct(float row11, float row12, float row13, float row21, float row22, float row23, float row31, float row32, float row33)
  {
    matrix[0][0] = row11; matrix[0][1] = row12; matrix[0][2] = row13;
    matrix[1][0] = row21; matrix[1][1] = row22; matrix[1][2] = row23;
    matrix[2][0] = row31; matrix[2][1] = row32; matrix[2][2] = row33;

  }

  void Zero()
  {
    matrix[0][0] = 0; matrix[0][1] = 0; matrix[0][2] = 0;
    matrix[1][0] = 0; matrix[1][1] = 0; matrix[1][2] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 0;
  }

  void Identity()
  {
    matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0;
    matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0;
    matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1;
  }

  void Row1(float row11, float row12, float row13)
  {
    matrix[0][0] = row11; matrix[0][1] = row12; matrix[0][2] = row13;
  }
  void Row2(float row21, float row22, float row23)
  {
    matrix[1][0] = row21; matrix[1][1] = row22; matrix[1][2] = row23;
  }
  void Row3(float row31, float row32, float row33)
  {
    matrix[2][0] = row31; matrix[2][1] = row32; matrix[2][2] = row33;
  }

};

class matrix2
{
  public:

  float matrix[2][2] = {{0, 0}, {0, 0}};

  void Construct(float row11, float row12, float row21, float row22)
  {
    matrix[0][0] = row11; matrix[0][1] = row12;
    matrix[1][0] = row21; matrix[1][1] = row22;

  }

  void Zero()
  {
    matrix[0][0] = 0; matrix[0][1] = 0;
    matrix[1][0] = 0; matrix[1][1] = 0;
  }

  void Identity()
  {
    matrix[0][0] = 1; matrix[0][1] = 0;
    matrix[1][0] = 0; matrix[1][1] = 1;
  }

  void Row1(float row11, float row12)
  {
    matrix[0][0] = row11; matrix[0][1] = row12;
  }
  void Row2(float row21, float row22)
  {
    matrix[1][0] = row21; matrix[1][1] = row22;
  }

};

struct Matrix4Calc
{
  matrix4 Add(matrix4 mat1, matrix4 mat2)
  {
    matrix4 sum;

    for (int x = 0; x < 4; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        sum.matrix[x][y] = mat1.matrix[x][y] + mat2.matrix[x][y];
      }
    }
    return sum;
  }

  matrix4 Multiply(matrix4 mat, float mult)
  {
    matrix4 res;

    for (int x = 0; x < 4; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        res.matrix[x][y] = mat.matrix[x][y] * mult;
      }
    }
    return res;
  }

  matrix4 MxM(matrix4 mat1, matrix4 mat2)
  {
    matrix4 res;

    for (int x = 0; x < 4; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        float sum = 0;
        for (int z = 0; z < 4; z++)
        {
          sum += mat1.matrix[x][z] * mat2.matrix[z][y];
          //cout << mat1.matrix[x][z] * mat2.matrix[z][y] << endl;
        }
        res.matrix[x][y] = sum;
      }
    }
    return res;
  }

  vector4 MxV(matrix4 mat, vector4 vec)
  {
    vector4 res;

    for (int x = 0; x < 4; x++)
    {
      float sum = 0;
      for (int y = 0; y < 4; y++)
      {
        sum += mat.matrix[x][y] * vec.vector[y];
      }
      res.vector[x] = sum;
    }
    return res;
  }

  vector4 VxM(vector4 vec, matrix4 mat)
  {
    vector4 res;

    for (int x = 0; x < 4; x++)
    {
      float sum = 0;
      for (int y = 0; y < 4; y++)
      {
        sum += vec.vector[y] * mat.matrix[y][x];
      }
      res.vector[x] = sum;
    }
    return res;
  }

  matrix4 Transpose(matrix4 mat)
  {
    matrix4 res;

    for (int x = 0; x < 4; x++)
    {
      for (int y = 0; y < 4; y++)
      {
        res.matrix[x][y] = mat.matrix[y][x];
      }
    }
    return res;
  }

  /*
  float Determinant(matrix4 mat)
  {
    float res = 0;

    res = mat1.matrix[0][0]*(matrix[1][1]*matrix[2][2])-(matrix[1][2]*matrix[2][1])-
          mat1.matrix[0][1]*(matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][0])+
          mat1.matrix[0][2]*(matrix[1][0]*matrix[2][2])-(matrix[1][2]*matrix[2][1]);

    return res;
  }
  */

  void debug(matrix4 mat, const char* name)
  {
    cout << name << endl;
    cout << "Row 1: " << "|" << mat.matrix[0][0] << ", " << mat.matrix[0][1] << ", " << mat.matrix[0][2] << ", " << mat.matrix[0][3] << "|" << endl;
    cout << "Row 2: " << "|" << mat.matrix[1][0] << ", " << mat.matrix[1][1] << ", " << mat.matrix[1][2] << ", " << mat.matrix[1][3] << "|" << endl;
    cout << "Row 3: " << "|" << mat.matrix[2][0] << ", " << mat.matrix[2][1] << ", " << mat.matrix[2][2] << ", " << mat.matrix[2][3] << "|" << endl;
    cout << "Row 4: " << "|" << mat.matrix[3][0] << ", " << mat.matrix[3][1] << ", " << mat.matrix[3][2] << ", " << mat.matrix[3][3] << "|" << endl;
  }

} Matrix4;

struct Matrix3Calc
{
  matrix3 Add(matrix3 mat1, matrix3 mat2)
  {
    matrix3 sum;

    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        sum.matrix[x][y] = mat1.matrix[x][y] + mat2.matrix[x][y];
      }
    }
    return sum;
  }

  matrix3 Multiply(matrix3 mat, float mult)
  {
    matrix3 res;

    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        res.matrix[x][y] = mat.matrix[x][y] * mult;
      }
    }
    return res;
  }

  matrix3 MxM(matrix3 mat1, matrix3 mat2)
  {
    matrix3 res;

    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        float sum = 0;
        for (int z = 0; z < 3; z++)
        {
          sum += mat1.matrix[x][z] * mat2.matrix[z][y];
          //cout << mat1.matrix[x][z] * mat2.matrix[z][y] << endl;
        }
        res.matrix[x][y] = sum;
      }
    }
    return res;
  }

  vector3 MxV(matrix3 mat, vector3 vec)
  {
    vector3 res;

    for (int x = 0; x < 3; x++)
    {
      float sum = 0;
      for (int y = 0; y < 3; y++)
      {
        sum += mat.matrix[x][y] * vec.vector[y];
      }
      res.vector[x] = sum;
    }
    return res;
  }

  vector3 VxM(vector3 vec, matrix3 mat)
  {
    vector3 res;

    for (int x = 0; x < 3; x++)
    {
      float sum = 0;
      for (int y = 0; y < 3; y++)
      {
        sum += vec.vector[y] * mat.matrix[y][x];
      }
      res.vector[x] = sum;
    }
    return res;
  }

  matrix3 Transpose(matrix3 mat)
  {
    matrix3 res;

    for (int x = 0; x < 3; x++)
    {
      for (int y = 0; y < 3; y++)
      {
        res.matrix[x][y] = mat.matrix[y][x];
      }
    }
    return res;
  }

  float Determinant(matrix3 mat)
  {
    float res = 0;

    res = mat.matrix[0][0]*(mat.matrix[1][1]*mat.matrix[2][2])-(mat.matrix[1][2]*mat.matrix[2][1])-
          mat.matrix[0][1]*(mat.matrix[1][0]*mat.matrix[2][2])-(mat.matrix[1][2]*mat.matrix[2][0])+
          mat.matrix[0][2]*(mat.matrix[1][0]*mat.matrix[2][2])-(mat.matrix[1][2]*mat.matrix[2][1]);

    return res;
  }

  void debug(matrix3 mat, const char* name)
  {
    cout << name << endl;
    cout << "Row 1: " << "|" << mat.matrix[0][0] << ", " << mat.matrix[0][1] << ", " << mat.matrix[0][2] << "|" << endl;
    cout << "Row 2: " << "|" << mat.matrix[1][0] << ", " << mat.matrix[1][1] << ", " << mat.matrix[1][2] << "|" << endl;
    cout << "Row 3: " << "|" << mat.matrix[2][0] << ", " << mat.matrix[2][1] << ", " << mat.matrix[2][2] << "|" << endl;
  }

} Matrix3;

struct Matrix2Calc
{
  matrix2 Add(matrix2 mat1, matrix2 mat2)
  {
    matrix2 sum;

    for (int x = 0; x < 2; x++)
    {
      for (int y = 0; y < 2; y++)
      {
        sum.matrix[x][y] = mat1.matrix[x][y] + mat2.matrix[x][y];
      }
    }
    return sum;
  }

  matrix2 Multiply(matrix2 mat, float mult)
  {
    matrix2 res;

    for (int x = 0; x < 2; x++)
    {
      for (int y = 0; y < 2; y++)
      {
        res.matrix[x][y] = mat.matrix[x][y] * mult;
      }
    }
    return res;
  }

  matrix2 MxM(matrix2 mat1, matrix2 mat2)
  {
    matrix2 res;

    for (int x = 0; x < 2; x++)
    {
      for (int y = 0; y < 2; y++)
      {
        float sum = 0;
        for (int z = 0; z < 2; z++)
        {
          sum += mat1.matrix[x][z] * mat2.matrix[z][y];
          //cout << mat1.matrix[x][z] * mat2.matrix[z][y] << endl;
        }
        res.matrix[x][y] = sum;
      }
    }
    return res;
  }

  vector2 MxV(matrix2 mat, vector2 vec)
  {
    vector2 res;

    for (int x = 0; x < 2; x++)
    {
      float sum = 0;
      for (int y = 0; y < 2; y++)
      {
        sum += mat.matrix[x][y] * vec.vector[y];
      }
      res.vector[x] = sum;
    }
    return res;
  }

  vector2 VxM(vector2 vec, matrix2 mat)
  {
    vector2 res;

    for (int x = 0; x < 2; x++)
    {
      float sum = 0;
      for (int y = 0; y < 2; y++)
      {
        sum += vec.vector[y] * mat.matrix[y][x];
      }
      res.vector[x] = sum;
    }
    return res;
  }

  matrix2 Transpose(matrix2 mat)
  {
    matrix2 res;

    for (int x = 0; x < 2; x++)
    {
      for (int y = 0; y < 2; y++)
      {
        res.matrix[x][y] = mat.matrix[y][x];
      }
    }
    return res;
  }

  void debug(matrix2 mat, const char* name)
  {
    cout << name << endl;
    cout << "Row 1: " << "|" << mat.matrix[0][0] << ", " << mat.matrix[0][1] << "|" << endl;
    cout << "Row 2: " << "|" << mat.matrix[1][0] << ", " << mat.matrix[1][1] << "|" << endl;
  }

} Matrix2;
