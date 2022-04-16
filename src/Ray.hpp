#pragma once

#include "Vec3.hpp"

class Ray
{
public:
	Ray()
	{ }

	Ray(const Point& origin, const Vec3 &direction) : m_Origin(origin), m_Direction(direction)
	{ }

	inline const Point& Origin() const { return m_Origin; }
	
	inline const Point& Direction() const { return m_Direction; }
	
	inline Point At(float_t t) const
	{
		return m_Origin + m_Direction * t;
	}

	inline Point operator[](float_t t) const {
		return At(t);
	}

	inline Color GetColor() const
	{
		Vec3 unit = m_Direction.Unit();
		float_t t = 0.5 * (unit.y + 1.0f);
		return (1.0f - t) * Color(1.0f, 1.0f, 1.0f) + t * Color(0.7f, 0.5f, 1.0f);
	}

private:
	Point m_Origin;
	Vec3 m_Direction;
};