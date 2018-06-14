#include "Matrix3.h"
#include <math.h>



Matrix3::Matrix3()
{
	m[0][0] = 1.0f;
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
}

Matrix3::Matrix3(float m00, float m01, float m02,
				 float m10, float m11, float m12,
				 float m20, float m21, float m22)
{
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;

	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;

	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
}

Matrix3::~Matrix3()
{
}

Vector3 Matrix3::operator*(Vector3 rhs)
{
	Vector3 result;

	result.x = (m[0][0] * rhs.x) + (m[1][0] * rhs.y) + (m[2][0] * rhs.z);
	result.y = (m[0][1] * rhs.x) + (m[1][1] * rhs.y) + (m[2][1] * rhs.z);
	result.z = (m[0][2] * rhs.x) + (m[1][2] * rhs.y) + (m[2][2] * rhs.z);

	return result;
}

Matrix3 Matrix3::operator*(Matrix3 rhs)
{
	Matrix3 result;

	result.m[0][0] = (m[0][0] * rhs.m[0][0]) + (m[1][0] * rhs.m[0][1]) + (m[2][0] * rhs.m[0][2]); 
	result.m[0][1] = (m[0][1] * rhs.m[0][0]) + (m[1][1] * rhs.m[0][1]) + (m[2][1] * rhs.m[0][2]);
	result.m[0][2] = (m[0][2] * rhs.m[0][0]) + (m[1][2] * rhs.m[0][1]) + (m[2][2] * rhs.m[0][2]);

	result.m[1][0] = (m[0][0] * rhs.m[1][0]) + (m[1][0] * rhs.m[1][1]) + (m[2][0] * rhs.m[1][2]);
	result.m[1][1] = (m[0][1] * rhs.m[1][0]) + (m[1][1] * rhs.m[1][1]) + (m[2][1] * rhs.m[1][2]);
	result.m[1][2] = (m[0][2] * rhs.m[1][0]) + (m[1][2] * rhs.m[1][1]) + (m[2][2] * rhs.m[1][2]);

	result.m[2][0] = (m[0][0] * rhs.m[2][0]) + (m[1][0] * rhs.m[2][1]) + (m[2][0] * rhs.m[2][2]);
	result.m[2][1] = (m[0][1] * rhs.m[2][0]) + (m[1][1] * rhs.m[2][1]) + (m[2][1] * rhs.m[2][2]);
	result.m[2][2] = (m[0][2] * rhs.m[2][0]) + (m[1][2] * rhs.m[2][1]) + (m[2][2] * rhs.m[2][2]);

	return result;
}

Vector3& Matrix3::operator[](int index)
{
		return *((Vector3*)(&m[index]));	
}

Matrix3::operator float*()
{
	return &m[0][0];
}

void Matrix3::setRotateX(float fRadians)
{
	m[1][1] = cosf(fRadians);
	m[1][2] = sinf(fRadians);		//swapped, apparently the slides had these the wrong way around
	m[2][1] = -sinf(fRadians);
	m[2][2] = cosf(fRadians);
}

void Matrix3::setRotateY(float fRadians)
{
	m[0][0] = cosf(fRadians);
	m[0][2] = -sinf(fRadians);
	m[2][0] = sinf(fRadians);
	m[2][2] = cosf(fRadians);
}

void Matrix3::setRotateZ(float fRadians)
{
	m[0][0] = cosf(fRadians);
	m[0][1] = sinf(fRadians);		//swapped, apparently the slides had these the wrong way around
	m[1][0] = -sinf(fRadians);
	m[1][1] = cosf(fRadians);
}

void Matrix3::setPositionVec2(float x, float y)
{
	m[2][0] = x;
	m[2][1] = y;
}

void Matrix3::setPositionVec2(Vector2 pos)
{
	m[2][0] = pos.x;
	m[2][1] = pos.y;
}

void Matrix3::setPositionVec3(float x, float y, float z)
{
	m[2][0] = x;
	m[2][1] = y;
	m[2][2] = z;
}

void Matrix3::setPositionVec3(Vector3 pos)
{
	m[2][0] = pos.x;
	m[2][1] = pos.y;
	m[2][2] = pos.z;
}

void Matrix3::setScale(float x, float y, float z)
{
	m[0][0] = x;
	m[1][1] = y;
	m[1][2] = z;
}

void Matrix3::setScale(Vector3 scale)
{
	m[0][0] = scale.x;
	m[1][1] = scale.y;
	m[1][2] = scale.z;
}

Vector2 Matrix3::getPositionVec2()
{
	Vector2 result;
	result.x = m[2][0];
	result.y = m[2][1];
	return result;
}

Vector3 Matrix3::getPositionVec3()
{
	Vector3 result;
	result.x = m[2][0];
	result.y = m[2][1];
	result.z = m[2][2];
	return result;
}