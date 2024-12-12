#pragma once
#define _USE_MATH_DEFINES

#include <math.h>

//Minimum tolerance before treating the value as 0
float const tolerance = 0.0001f;

class Vector3
{
public:
	float x, y, z;

    Vector3(void);
    Vector3(float x, float y, float z);

    Vector3& copy(Vector3& copy) {
        x = copy.x;
        y = copy.y;
        z = copy.z;
    }

    float Magnitude(void);
    void  Normalize(void);
    void  Reverse(void);

    Vector3& operator+=(Vector3 u);
    Vector3& operator-=(Vector3 u);
    Vector3& operator*=(float s);
    Vector3& operator/=(float s);
    Vector3 operator-(void);

    Vector3 operator+(Vector3 u);
    Vector3 operator-(Vector3 u);
    Vector3 operator^(Vector3 u);
    float operator*(Vector3 u);
    Vector3 operator*(float s);
    Vector3 operator/(float s);

    float TripleScalarProduct(Vector3 u, Vector3 v, Vector3 w);

private:

};
