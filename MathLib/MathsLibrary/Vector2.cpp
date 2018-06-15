#include "Vector2.h"
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>

Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2 Vector2::operator + (Vector2 rhs)
{
	Vector2 result;
	result.x = this->x + rhs.x;
	result.y = this->y + rhs.y;

	return result;
}

Vector2 Vector2::operator + (float rhs)
{
	Vector2 result;
	result.x = this->x + rhs;
	result.y = this->y + rhs;

	return result;
}

Vector2 Vector2::operator += (Vector2 rhs)
{

	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

Vector2 Vector2::operator += (float rhs)
{
	this->x += rhs;
	this->y += rhs;

	return *this;
}

Vector2 Vector2::operator - (Vector2 rhs)
{
	Vector2 result;
	result.x = this->x - rhs.x;
	result.y = this->y - rhs.y;

	return result;
}

Vector2 Vector2::operator - (float rhs)
{
	Vector2 result;
	result.x = this->x - rhs;
	result.y = this->y - rhs;

	return result;
}

Vector2 Vector2::operator -= (Vector2 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

Vector2 Vector2::operator -= (float rhs)
{
	this->x -= rhs;
	this->y -= rhs;

	return *this;
}

Vector2 Vector2::operator * (Vector2 rhs)
{
	Vector2 result;
	result.x = this->x * rhs.x;
	result.y = this->y * rhs.y;

	return result;
}

Vector2 Vector2::operator * (float rhs)
{
	Vector2 result;
	result.x = this->x * rhs;
	result.y = this->y * rhs;

	return result;
}

Vector2 Vector2::operator *= (Vector2 rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;

	return *this;
}

Vector2 Vector2::operator *= (float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	
	return *this;
}

Vector2 Vector2::operator / (Vector2 rhs)
{
	Vector2 result;

	if (rhs.x == 0)
		assert("Error: cannot divide by 0 (paramater.x)");
	else
	result.x = this->x / rhs.x;

	if (rhs.y == 0)
		assert("Error: cannot divide by 0 (paramater.y)");
	else
	result.y = this->y / rhs.y;

	return result;
}

Vector2 Vector2::operator / (float rhs)
{
	Vector2 result;

	if (rhs == 0)
		assert("Error: cannot divide by 0");
	else
	result.x = this->x / rhs;
	result.y = this->y / rhs;

	return result;
}

Vector2 Vector2::operator /= (Vector2 rhs)
{
	if (rhs.x == 0)
		assert("Error: cannot divide by 0 (paramater.x)");
	else
		this->x /= rhs.x;

	if (rhs.y == 0)
		assert("Error: cannot divide by 0 (paramater.y)");
	else
		this->y /= rhs.y;

	return *this;
}

Vector2 Vector2::operator /= (float rhs)
{
	if (rhs == 0)
		assert("Error: cannot divide by 0");
	else
		this->x /= rhs;
		this->y /= rhs;

	return *this;
}

float& Vector2::operator[](int index)
{
	if (index = 0)
		return x;

	else if (index = 1)
		return y;

	else
	{
		assert(false && "Index was out of bounds");
		return x;
	}
}

Vector2::operator float*()
{
	return &x;
}

float Vector2::magnitude()
{
	return sqrtf((x * x) + (y * y));
}

void Vector2::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
}

float Vector2::dot(Vector2 rhs)
{
	return (x * rhs.x) + (y * rhs.y);
}

double Vector2::RadDeg(float radian)
{
	return ((radian * 180) / M_PI);
}

double Vector2::DegRad(float degree)
{
	return ((degree / 180) * M_PI);
		
}

double Vector2::angle(Vector2 rhs)
{
	return (acos(dot(rhs)));
}
