#include "Matrix2.h"
#include <math.h>


Matrix2::Matrix2()
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
}


Matrix2::~Matrix2()
{
}


Matrix2::Matrix2(float m00, float m01,
				 float m10, float m11)
{
	m[0][0] = m00;
	m[0][1] = m01;

	m[1][0] = m10;
	m[1][1] = m11;
}


Vector2 Matrix2::operator*(Vector2 rhs)
{
	Vector2 result;

	result.x = (m[0][0] * rhs.x) + (m[1][0] * rhs.y);
	result.y = (m[0][1] * rhs.x) + (m[1][1] * rhs.y);

	return result;
}

Matrix2 Matrix2::operator*(Matrix2 rhs)
{
	Matrix2 result;

	result.m[0][0] = (m[0][0] * rhs.m[0][0]) + (m[1][0] * rhs.m[0][1]);
	result.m[0][1] = (m[0][1] * rhs.m[0][0]) + (m[1][1] * rhs.m[0][1]);

	result.m[1][0] = (m[0][0] * rhs.m[1][0]) + (m[1][0] * rhs.m[1][1]);
	result.m[1][1] = (m[0][1] * rhs.m[1][0]) + (m[1][1] * rhs.m[1][1]);

	return result;
}

Vector2& Matrix2::operator[](int index)
{
	return *((Vector2*)(&m[index]));

}

Matrix2::operator float*()
{
	return &m[0][0];
}

void Matrix2::setRotate(float fRadians)
{
	m[0][0] = cosf(fRadians);
	m[0][1] = sinf(fRadians);
	m[1][0] = -sinf(fRadians);
	m[1][1] = cosf(fRadians);
}

void Matrix2::setPosition(float x, float y)
{
	m[0][1] = x;
	m[1][1] = y;
}

void Matrix2::setPosition(Vector2 pos)
{
	m[0][1] = pos.x;
	m[1][1] = pos.y;
}

void Matrix2::setScale(float x, float y)
{
	m[0][0] = x;
	m[0][1] = y;
}

void Matrix2::setScale(Vector2 scale)
{
	m[0][0] = scale.x;
	m[0][1] = scale.y;
}

Vector2 Matrix2::getPosition()
{
	Vector2 result;
	result.x = m[0][2];
	result.y = m[1][2];
	return result;
}