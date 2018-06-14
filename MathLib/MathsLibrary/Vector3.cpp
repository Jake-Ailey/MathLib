#include "Vector3.h"
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>


Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::~Vector3()
{
}

Vector3 Vector3::operator + (Vector3 rhs)
{
	Vector3 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;

	return result;
}

Vector3 Vector3::operator + (float rhs)
{
	Vector3 result;
	result.x = this->x + rhs;
	result.y = this->y + rhs;
	result.z = this->z + rhs;

	return result;
}

Vector3 Vector3::operator += (Vector3 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;
}

Vector3 Vector3::operator += (float rhs)
{
	this->x += rhs;
	this->y += rhs;
	this->z += rhs;

	return *this;
}

Vector3 Vector3::operator - (Vector3 rhs)
{
	Vector3 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;

	return result;
}

Vector3 Vector3::operator - (float rhs)
{
	Vector3 result;
	result.x = this->x - rhs;
	result.y = this->y - rhs;
	result.z = this->z - rhs;

	return result;
}

Vector3 Vector3::operator -= (Vector3 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;

	return *this;
}

Vector3 Vector3::operator -= (float rhs)
{
	this->x -= rhs;
	this->y -= rhs;
	this->z -= rhs;

	return *this;
}

Vector3 Vector3::operator * (Vector3 rhs)
{
	Vector3 result;
	result.x = this->x * rhs.x;
	result.y = this->y * rhs.y;
	result.z = this->z * rhs.z;

	return result;
}

Vector3 Vector3::operator * (float rhs)
{
	Vector3 result;
	result.x = this->x * rhs;
	result.y = this->y * rhs;
	result.z = this->z * rhs;

	return result;
}

Vector3 Vector3::operator *= (Vector3 rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
	this->z *= rhs.z;

	return *this;
}

Vector3 Vector3::operator *= (float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;

	return *this;
}

Vector3 Vector3::operator / (Vector3 rhs)
{
	Vector3 result;
	if (rhs.x == 0)
		assert("Error: cannot divide by 0 (paramater.x)");
	else
	result.x = this->x / rhs.x;

	if (rhs.y == 0)
		assert("Error: cannot divide by 0 (paramater.y)");
	else
	result.y = this->y / rhs.y;

	if (rhs.z == 0)
		assert("Error: cannot divide by 0 (paramater.z)");
	else
	result.z = this->z / rhs.z;

	return result;
}

Vector3 Vector3::operator / (float rhs)
{
	Vector3 result;

	if (rhs == 0)
		assert("Error: cannot divide by 0 ");
	else
	result.x = this->x / rhs;
	result.y = this->y / rhs;
	result.z = this->z / rhs;

	return result;
}

Vector3 Vector3::operator /= (Vector3 rhs)
{
	if (rhs.x == 0)
		assert("Error: cannot divide by 0 (paramater.x)");
	else
	this->x /= rhs.x;

	if (rhs.y == 0)
		assert("Error: cannot divide by 0 (paramater.y)");
	else
	this->y /= rhs.y;

	if (rhs.z == 0)
		assert("Error: cannot divide by 0 (paramater.z)");
	else
	this->z /= rhs.z;

	return *this;
}

Vector3 Vector3::operator /= (float rhs)
{
	if (rhs == 0)
		assert("Error: cannot divide by 0");
	else
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;

	return *this;
}

float& Vector3::operator[](int index)
{
	if (index = 0)
		return x;

	else if (index = 1)
		return y;

	else if (index = 2)
		return z;

	else
	{
		assert(false && "Index was out of bounds");
		return x;
	}
}

Vector3::operator float*()
{
	return &x;
}

float Vector3::magnitude()
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

void Vector3::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

float Vector3::dot(Vector3 rhs)
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

Vector3 Vector3::cross(Vector3 rhs)
{
	Vector3 result;

	result.x = ((y * rhs.z) - (z * rhs.y));
	result.y = ((z * rhs.x) - (x * rhs.z));
	result.z = ((x * rhs.y) - (y * rhs.x));

	return result;
}


double Vector3::RadDeg(float radian)
{
	return ((radian * 180) / M_PI);
}

double Vector3::DegRad(float degree)
{
	return ((degree / 180) * M_PI);

}