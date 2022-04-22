#include <iostream>
#include <fstream>

#include "Vec3.hpp"
#include "Ray.hpp"

void WriteColor(std::ofstream& out, const Color& c)
{
	out << static_cast<uint32_t>(255.999 * c.r)
		<< " " << static_cast<uint32_t>(255.999 * c.g)
		<< " " << static_cast<uint32_t>(255.999 * c.b)
		<< std::endl;
}

int main()
{
	// Image
	constexpr double_t aspect = 16.0f / 9.0f;
	constexpr uint32_t width = 800;
	constexpr uint32_t height = static_cast<uint32_t>(width / aspect);

	// Camera
	constexpr double_t viewportHeight = 1.0f;
	constexpr double_t viewportWidth = aspect * viewportHeight;
	constexpr double_t focalLenght = 1.0f;

	Point origin(0.0f, 0.0f, 0.0f);
	Vec3 horizontal(viewportWidth, 0.0f, 0.0f);
	Vec3 vertical(0.0f, viewportHeight, 0.0f);
	Point lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0.0f, 0.0f, focalLenght);

	std::ofstream file;
	file.open("image.ppm");

	file << "P3" << std::endl;
	file << width << " " << height << std::endl;
	file << "255" << std::endl;

	for (uint32_t j = height; j > 0; --j)
	{
		for (uint32_t i = 0; i < width; ++i)
		{
			double_t u = static_cast<double_t>(i) / (width - 1);
			double_t v = static_cast<double_t>(j) / (height - 1);
			Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
			WriteColor(file, r.GetColor());
		}
	}

	file.close();

	return 0;
}