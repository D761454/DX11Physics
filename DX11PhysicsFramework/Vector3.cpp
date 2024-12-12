#include "Vector3.h"

Vector3::Vector3(void)
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::Magnitude(void)
{
    return (float)sqrt(x * x + y * y + z * z);
}

void Vector3::Normalize(void)
{
    float m = (float)sqrt(x * x + y * y + z * z);
    if (m <= tolerance) m = 1;
    x /= m;
    y /= m;
    z /= m;

    if (fabsf(x) < tolerance) x = 0.0f;
    if (fabsf(y) < tolerance) y = 0.0f;
    if (fabsf(z) < tolerance) z = 0.0f;
}

void Vector3::Reverse(void)
{
    x = -x;
    y = -y;
    z = -z;
}

/// <summary>
/// add given vector to this
/// </summary>
/// <param name="u"></param>
/// <returns></returns>
Vector3& Vector3::operator+=(Vector3 u)
{
    x += u.x;
    y += u.y;
    z += u.z;
    return *this;
}

/// <summary>
/// subtract given vector from this
/// </summary>
/// <param name="u"></param>
/// <returns></returns>
Vector3& Vector3::operator-=(Vector3 u)
{
    x -= u.x;
    y -= u.y;
    z -= u.z;
    return *this;
}

/// <summary>
/// scalar multiplication
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
Vector3& Vector3::operator*=(float s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

/// <summary>
/// scalar division
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
Vector3& Vector3::operator/=(float s)
{
    x /= s;
    y /= s;
    z /= s;
    return *this;
}

/// <summary>
/// reverse of the vector
/// </summary>
/// <param name=""></param>
/// <returns></returns>
Vector3 Vector3::operator-(void)
{
    return Vector3(-x, -y, -z);
}

/// <summary>
/// return value of given vector added to this
/// </summary>
/// <param name="u"></param>
/// <returns></returns>
Vector3 Vector3::operator+(Vector3 u)
{
    return Vector3(u.x + x, u.y + y, u.z + z);
}

/// <summary>
/// return value of the given vector subtracted from this
/// </summary>
/// <param name="u"></param>
/// <returns></returns>
Vector3 Vector3::operator-(Vector3 u)
{
    return Vector3(x - u.x, y - u.y, z - u.z);
}

/// <summary>
/// cross product / vector product
/// </summary>
/// <param name="u"></param>
/// <returns></returns>
Vector3 Vector3::operator^(Vector3 u)
{
    return Vector3(y * u.z - z * u.y,
        -x * u.z + z * u.x,
        x * u.y - y * u.x);
}

/// <summary>
/// dot product / scalar product
/// </summary>
/// <param name="u"></param>
/// <returns></returns>
float Vector3::operator*(Vector3 u)
{
    return (x * u.x + y * u.y + z * u.z);
}

/// <summary>
/// *scale vector by given
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
Vector3 Vector3::operator*(float s)
{
    return Vector3(x * s, y * s, z * s);
}

/// <summary>
/// /scale vector by given
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
Vector3 Vector3::operator/(float s)
{
    return Vector3(x / s, y / s, z / s);
}

float Vector3::TripleScalarProduct(Vector3 u, Vector3 v, Vector3 w)
{
    return float((u.x * (v.y * w.z - v.z * w.y)) +
        (u.y * (-v.x * w.z + v.z * w.x)) +
        (u.z * (v.x * w.y - v.y * w.x)));
}