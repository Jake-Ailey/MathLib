#include "Matrix4.h"
#include <math.h>

Matrix4::Matrix4()		
{
	m[0][0] = 1.0f;			//Initialising our matrix as an identity matrix
	m[0][1] = 0.0f;
	m[0][2] = 0.0f;
	m[0][3] = 0.0f;

	m[1][0] = 0.0f;
	m[1][1] = 1.0f;
	m[1][2] = 0.0f;
	m[1][3] = 0.0f;

	m[2][0] = 0.0f;
	m[2][1] = 0.0f;
	m[2][2] = 1.0f;
	m[2][3] = 0.0f;

	m[3][0] = 0.0f;
	m[3][1] = 0.0f;
	m[3][2] = 0.0f;
	m[3][3] = 1.0f;
}

Matrix4::Matrix4(float m00, float m01, float m02, float m03,		//Condensed down into visual 4x4 matrix for ease of readability 
				 float m10, float m11, float m12, float m13,
				 float m20, float m21, float m22, float m23,
				 float m30, float m31, float m32, float m33)
{
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;
	m[0][3] = m03;

	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;
	m[1][3] = m13;

	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
	m[2][3] = m23;

	m[3][0] = m30;
	m[3][1] = m31;
	m[3][2] = m32;
	m[3][3] = m33;
}

Matrix4::~Matrix4()
{
}

Vector4 Matrix4::operator*(Vector4 rhs)
{
	Vector4 result;

	result.x = (m[0][0] * rhs.x) + (m[1][0] * rhs.y) + (m[2][0] * rhs.z) + (m[3][0] * rhs.w);
	result.y = (m[0][1] * rhs.x) + (m[1][1] * rhs.y) + (m[2][1] * rhs.z) + (m[3][1] * rhs.w);
	result.z = (m[0][2] * rhs.x) + (m[1][2] * rhs.y) + (m[2][2] * rhs.z) + (m[3][2] * rhs.w);
	result.w = (m[0][3] * rhs.x) + (m[1][3] * rhs.y) + (m[2][3] * rhs.z) + (m[3][3] * rhs.w);

	return result;
}

Matrix4 Matrix4::operator*(Matrix4 rhs)
{
	Matrix4 result;

	result.m[0][0] = (m[0][0] * rhs.m[0][0]) + (m[1][0] * rhs.m[0][1]) + (m[2][0] * rhs.m[0][2]) + (m[3][0] * rhs.m[0][3]);
	result.m[0][1] = (m[0][1] * rhs.m[0][0]) + (m[1][1] * rhs.m[0][1]) + (m[2][1] * rhs.m[0][2]) + (m[3][1] * rhs.m[0][3]);
	result.m[0][2] = (m[0][2] * rhs.m[0][0]) + (m[1][2] * rhs.m[0][1]) + (m[2][2] * rhs.m[0][2]) + (m[3][2] * rhs.m[0][3]);
	result.m[0][3] = (m[0][3] * rhs.m[0][0]) + (m[1][3] * rhs.m[0][1]) + (m[2][3] * rhs.m[0][2]) + (m[3][3] * rhs.m[0][3]);

	result.m[1][0] = (m[0][0] * rhs.m[1][0]) + (m[1][0] * rhs.m[1][1]) + (m[2][0] * rhs.m[1][2]) + (m[3][0] * rhs.m[1][3]);
	result.m[1][1] = (m[0][1] * rhs.m[1][0]) + (m[1][1] * rhs.m[1][1]) + (m[2][1] * rhs.m[1][2]) + (m[3][1] * rhs.m[1][3]);
	result.m[1][2] = (m[0][2] * rhs.m[1][0]) + (m[1][2] * rhs.m[1][1]) + (m[2][2] * rhs.m[1][2]) + (m[3][2] * rhs.m[1][3]);
	result.m[1][3] = (m[0][3] * rhs.m[1][0]) + (m[1][3] * rhs.m[1][1]) + (m[2][3] * rhs.m[1][2]) + (m[3][3] * rhs.m[1][3]);

	result.m[2][0] = (m[0][0] * rhs.m[2][0]) + (m[1][0] * rhs.m[2][1]) + (m[2][0] * rhs.m[2][2]) + (m[3][0] * rhs.m[2][3]);
	result.m[2][1] = (m[0][1] * rhs.m[2][0]) + (m[1][1] * rhs.m[2][1]) + (m[2][1] * rhs.m[2][2]) + (m[3][1] * rhs.m[2][3]);
	result.m[2][2] = (m[0][2] * rhs.m[2][0]) + (m[1][2] * rhs.m[2][1]) + (m[2][2] * rhs.m[2][2]) + (m[3][2] * rhs.m[2][3]);
	result.m[2][3] = (m[0][3] * rhs.m[2][0]) + (m[1][3] * rhs.m[2][1]) + (m[2][3] * rhs.m[2][2]) + (m[3][3] * rhs.m[2][3]);

	result.m[3][0] = (m[0][0] * rhs.m[3][0]) + (m[1][0] * rhs.m[3][1]) + (m[2][0] * rhs.m[3][2]) + (m[3][0] * rhs.m[3][3]);
	result.m[3][1] = (m[0][1] * rhs.m[3][0]) + (m[1][1] * rhs.m[3][1]) + (m[2][1] * rhs.m[3][2]) + (m[3][1] * rhs.m[3][3]);
	result.m[3][2] = (m[0][2] * rhs.m[3][0]) + (m[1][2] * rhs.m[3][1]) + (m[2][2] * rhs.m[3][2]) + (m[3][2] * rhs.m[3][3]);
	result.m[3][3] = (m[0][3] * rhs.m[3][0]) + (m[1][3] * rhs.m[3][1]) + (m[2][3] * rhs.m[3][2]) + (m[3][3] * rhs.m[3][3]);

	return result;
}

Vector4& Matrix4::operator[](int index)
{
	return *((Vector4*)(&m[index]));
}

Matrix4::operator float*()
{
	return &m[0][0];
}

void Matrix4::setRotateX(float fRadians)
{
	m[1][1] = cosf(fRadians);
	m[1][2] = sinf(fRadians);		//swapped, apparently the slides had these the wrong way around.
	m[2][1] = -sinf(fRadians);
	m[2][2] = cosf(fRadians);
}

void Matrix4::setRotateY(float fRadians)
{
	m[0][0] = cosf(fRadians);
	m[0][2] = -sinf(fRadians);
	m[2][0] = sinf(fRadians);
	m[2][2] = cosf(fRadians);
}

void Matrix4::setRotateZ(float fRadians)
{
	m[0][0] = cosf(fRadians);
	m[0][1] = sinf(fRadians);		//swapped, apparently the slides had these the wrong way around.
	m[1][0] = -sinf(fRadians);
	m[1][1] = cosf(fRadians);
}

void Matrix4::setPosition(float x, float y, float z, float w)
{
	m[0][2] = x;
	m[1][2] = y;
	m[2][2] = z;
	m[3][2] = w;
}

void Matrix4::setPosition(Vector4 pos)
{
	m[0][2] = pos.x;
	m[1][2] = pos.y;
	m[2][2] = pos.z;
	m[3][2] = pos.w;
}

void Matrix4::setScale(float x, float y, float z, float w)
{
	m[0][0] = x;
	m[0][1] = y;
	m[0][2] = z;
	m[0][3] = w;
}

void Matrix4::setScale(Vector4 scale)
{
	m[0][0] = scale.x;
	m[0][1] = scale.y;
	m[0][2] = scale.z;
	m[0][3] = scale.w;
}

Vector4 Matrix4::getPosition()
{
	Vector4 result;
	result.x = m[0][2];
	result.y = m[1][2];
	result.z = m[2][2];


	return result;
}