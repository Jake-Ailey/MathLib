#include "Vector4.h"
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>


Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4::~Vector4()
{
}

Vector4 Vector4::operator + (Vector4 rhs)
{
	Vector4 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;
	result.z = this->z + rhs.z;
	result.w = this->w + rhs.w;

	return result;
}

Vector4 Vector4::operator + (float rhs)
{
	Vector4 result;
	result.x = this->x + rhs;
	result.y = this->y + rhs;
	result.z = this->z + rhs;
	result.w = this->w + rhs;

	return result;
}


Vector4 Vector4::operator - (Vector4 rhs)
{
	Vector4 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;
	result.z = this->z - rhs.z;
	result.w = this->w - rhs.w;

	return result;
}

Vector4 Vector4::operator - (float rhs)
{
	Vector4 result;
	result.x = this->x - rhs;
	result.y = this->y - rhs;
	result.z = this->z - rhs;
	result.w = this->w - rhs;

	return result;
}

Vector4 Vector4::operator * (Vector4 rhs)
{
	Vector4 result;
	result.x = this->x * rhs.x;
	result.y = this->y * rhs.y;
	result.z = this->z * rhs.z;
	result.w = this->w * rhs.w;

	return result;
}

Vector4 Vector4::operator * (float rhs)
{
	Vector4 result;
	result.x = this->x * rhs;
	result.y = this->y * rhs;
	result.z = this->z * rhs;
	result.w = this->w * rhs;

	return result;
}

Vector4 Vector4::operator / (Vector4 rhs)
{
	Vector4 result;
	result.x = this->x / rhs.x;
	result.y = this->y / rhs.y;
	result.z = this->z / rhs.z;
	result.w = this->w / rhs.w;

	return result;
}

Vector4 Vector4::operator / (float rhs)
{
	Vector4 result;
	result.x = this->x / rhs;
	result.y = this->y / rhs;
	result.z = this->z / rhs;
	result.w = this->w / rhs;

	return result;
}

float& Vector4::operator[](int index)
{
	if (index = 0)
		return x;

	else if (index = 1)
		return y;

	else if (index = 2)
		return z;

	else if (index = 3)
		return w;

	else
	{
		assert(false && "Index was out of bounds");
		return x;
	}
}

Vector4::operator float*()
{
	return &x;
}

float Vector4::magnitude()
{
	return sqrtf((x * x) + (y * y) + (z * z));
}

void Vector4::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

float Vector4::dot(Vector4 rhs)
{
	return (x * rhs.x) + (y * rhs.y) + (z * rhs.z);
}

Vector4 Vector4::cross(Vector4 rhs)
{
	Vector4 result;

	result.x = ((y * rhs.z) - (z * rhs.y));
	result.y = ((z * rhs.x) - (x * rhs.z));
	result.z = ((x * rhs.y) - (y * rhs.x));
	result.w = 0;

	return result;
}

double Vector4::RadDeg(float radian)
{
	return ((radian * 180) / M_PI);
}

double Vector4::DegRad(float degree)
{
	return ((degree / 180) * M_PI);

}