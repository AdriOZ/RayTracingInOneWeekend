#pragma once

#include <iostream>
#include <cmath>

struct Vec3
{
	union
	{
		double_t v[3];

		struct
		{
			double_t x, y, z;
		};

		struct
		{
			double_t r, g, b;
		};
	};

	Vec3(double_t v1, double_t v2, double_t v3) : x(v1), y(v2), z(v3)
	{ }

	Vec3() : x(0), y(0), z(0)
	{ }

	Vec3(const Vec3 &copy) : x(copy.x), y(copy.y), z(copy.z)
	{ }

	Vec3 operator-() const { return Vec3(-x, -y, -z); }

	double_t operator[](size_t i) const { return v[i]; }

	double_t& operator[](size_t i) { return v[i]; }

	Vec3& operator+=(const Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vec3& operator-=(const Vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vec3& operator*=(double_t t)
	{
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	Vec3& operator/=(double_t t)
	{
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}

	double_t Lenght() const
	{
		return sqrt(
			x * x +
			y * y +
			z * z
		);
	}

	double_t Dot(const Vec3& v) const
	{
		return x * v.x +
			y * v.y +
			z * v.z;
	}

	Vec3 Cross(const Vec3& v) const
	{
		return {
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		};
	}

	Vec3 Unit() const
	{
		double_t lenght = Lenght();
		return {
			x / lenght,
			y / lenght,
			z / lenght,
		};
	}
};

using Point = Vec3;
using Color = Vec3;

std::ostream& operator<<(std::ostream& out, const Vec3 &v)
{
	return out << v.x << " " << v.y << " " << v.z;
}

Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	};
}

Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	};
}

Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z
	};
}

Vec3 operator*(double_t f, const Vec3& v)
{
	return {
		v.x * f,
		v.y * f,
		v.z * f
	};
}

Vec3 operator*(const Vec3& v, double_t f)
{
	return f * v;
}

Vec3 operator/(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z
	};
}

Vec3 operator/(double_t f, const Vec3& v)
{
	return {
		v.x / f,
		v.y / f,
		v.z / f
	};
}

Vec3 operator/(const Vec3& v, double_t f)
{
	return f / v;
}

bool operator==(const Vec3& v1, const Vec3& v2)
{
	return v1.x == v2.x &&
		v1.y == v2.y &&
		v1.z == v1.z;
}

bool operator!=(const Vec3& v1, const Vec3& v2)
{
	return v1.x != v2.x ||
		v1.y != v2.y ||
		v1.z != v1.z;
}

bool operator>(const Vec3& v1, const Vec3& v2)
{
	return v1.Lenght() > v2.Lenght();
}

bool operator>=(const Vec3& v1, const Vec3& v2)
{
	return v1 == v2 || v1 > v2;
}

bool operator<(const Vec3& v1, const Vec3& v2)
{
	return v1.Lenght() > v2.Lenght();
}

bool operator<=(const Vec3& v1, const Vec3& v2)
{
	return v1 == v2 || v1 < v2;
}