#pragma once

#include "Vec3.hpp"

class Ray
{
public:
	Ray()
	{ }

	Ray(const Point& origin, const Vec3 &direction) : m_Origin(origin), m_Direction(direction)
	{ }

	const Point& Origin() const { return m_Origin; }
	
	const Point& Direction() const { return m_Direction; }
	
	Point At(double_t t) const { return m_Origin + m_Direction * t; }

	Point operator[](double_t t) const { return At(t); }

	Color GetColor() const
	{
		double_t hit = HitSphere(Point(0.0, 0.0, -1.0), 0.25);

		if (hit > 0.0)
		{
			Vec3 n = At(hit) - Vec3(0.0, 0.0, -1.0);
			return 0.5 * Color(n.x + 1.0, n.y + 1.0, n.z + 1.0);
		}

		Vec3 unit = m_Direction.Unit();
		double_t t = 0.5 * (unit.y + 1.0);
		return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.5, 1.0f);
	}

	double_t HitSphere(const Point& center, double_t radius) const
	{
		Vec3 oc = m_Origin - center;
		double_t a = m_Direction.Lenght();
		double_t halfB = oc.Dot(m_Direction);
		double_t c = oc.Lenght() - radius * radius;
		double_t d = halfB * halfB - a * c;
		return d < 0
			? -1
			: (-halfB - sqrt(d)) / (2.0 * a);
	}

private:
	Point m_Origin;
	Vec3 m_Direction;
};