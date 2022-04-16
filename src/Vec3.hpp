#pragma once

#include <iostream>
#include <cmath>

class Vec3
{
public:
	union
	{
		float_t v[3];

		struct
		{
			float_t x, y, z;
		};

		struct
		{
			float_t r, g, b;
		};
	};

	Vec3(float_t v1, float_t v2, float_t v3) : x(v1), y(v2), z(v3)
	{ }

	Vec3() : x(0), y(0), z(0)
	{ }

	Vec3(const Vec3 &copy) : x(copy.x), y(copy.y), z(copy.z)
	{ }

	inline Vec3 operator-() const { return Vec3(-x, -y, -z); }

	inline float_t operator[](size_t i) const { return v[i]; }

	inline float_t& operator[](size_t i) { return v[i]; }

	inline Vec3& operator+=(const Vec3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	inline Vec3& operator-=(const Vec3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	inline Vec3& operator*=(float_t t)
	{
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}

	inline Vec3& operator/=(float_t t)
	{
		x /= t;
		y /= t;
		z /= t;
		return *this;
	}

	inline float_t Lenght() const
	{
		return sqrt(x * x + y * y + z * z);
	}

	inline float_t Dot(const Vec3& v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline Vec3 Cross(const Vec3& v) const
	{
		return {
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		};
	}

	inline Vec3 Unit() const
	{
		float_t lenght = Lenght();
		return {
			x / lenght,
			y / lenght,
			z / lenght,
		};
	}
};

using Point = Vec3;
using Color = Vec3;

inline std::ostream& operator<<(std::ostream& out, const Vec3 &v)
{
	return out << v.x << " " << v.y << " " << v.z;
}

inline Vec3 operator+(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
	};
}

inline Vec3 operator-(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	};
}

inline Vec3 operator*(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z
	};
}

inline Vec3 operator*(float_t f, const Vec3& v)
{
	return {
		v.x * f,
		v.y * f,
		v.z * f
	};
}

inline Vec3 operator*(const Vec3& v, float_t f)
{
	return f * v;
}

inline Vec3 operator/(const Vec3& v1, const Vec3& v2)
{
	return {
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z
	};
}

inline Vec3 operator/(float_t f, const Vec3& v)
{
	return {
		v.x / f,
		v.y / f,
		v.z / f
	};
}

inline Vec3 operator/(const Vec3& v, float_t f)
{
	return f / v;
}