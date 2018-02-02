#include "Vector.h"

namespace serenity { namespace maths {

	Vector2f::Vector2f() :
		Vector2f(0.0f, 0.0f)
	{

	}

	Vector2f::Vector2f(float x, float y) :
		x		(x),
		y		(y)
	{

	}

	float Vector2f::dot(const Vector2f& other) const
	{
		return (x * other.x + y * other.y);
	}

	float Vector2f::magnitude() const
	{
		return sqrtf((x * x + y * y));
	}

	void Vector2f::normalize()
	{
		*this /= magnitude();
	}

	Vector2f Vector2f::operator-() const
	{
		return Vector2f(-x, -y);
	}

	Vector2f Vector2f::operator+(const Vector2f& other) const
	{
		return Vector2f(x + other.x, y + other.y);
	}

	Vector2f Vector2f::operator-(const Vector2f& other) const
	{
		return Vector2f(x - other.x, y - other.y);
	}

	Vector2f Vector2f::operator*(const float& multiplier) const
	{
		return Vector2f(x * multiplier, y * multiplier);
	}

	Vector2f Vector2f::operator/(const float& divider) const
	{
		return Vector2f(x / divider, y / divider);
	}

	void Vector2f::operator+=(const Vector2f& other)
	{
		x += other.x;
		y += other.y;
	}

	void Vector2f::operator-=(const Vector2f& other)
	{
		x -= other.x;
		y -= other.y;
	}

	void Vector2f::operator*=(const float& multiplier)
	{
		x *= multiplier;
		y *= multiplier;
	}

	void Vector2f::operator/=(const float& divider)
	{
		x /= divider;
		y /= divider;
	}

	bool Vector2f::operator==(const Vector2f& other) const
	{
		return (x == other.x && y == other.y);
	}

	bool Vector2f::operator!=(const Vector2f& other) const
	{
		return (x != other.x || y != other.y);
	}

	bool Vector2f::operator<(const Vector2f& other) const
	{
		return magnitude() < other.magnitude();
	}

	bool Vector2f::operator>(const Vector2f& other) const
	{
		return magnitude() > other.magnitude();
	}

	bool Vector2f::operator<=(const Vector2f& other) const
	{
		return magnitude() <= other.magnitude();
	}

	bool Vector2f::operator>=(const Vector2f& other) const
	{
		return magnitude() >= other.magnitude();
	}

	void Vector2f::operator=(const Vector2f& other)
	{
		x = other.x;
		y = other.y;
	}

	float Vector2f::magnitude(const Vector2f& other)
	{
		return other.magnitude();
	}

	float Vector2f::dot(const Vector2f& vector1, const Vector2f& vector2)
	{
		return vector1.dot(vector2);
	}

	Vector2f Vector2f::normalize(const Vector2f& vector)
	{
		return Vector2f(vector.x / vector.magnitude(), vector.y / vector.magnitude());
	}

	Vector2f::~Vector2f()
	{

	}

	std::ostream& operator<<(std::ostream& output, const Vector2f& vector)
	{
		output << "X : " << vector.x << ", Y : " << vector.y;
		return output;
	}

	/*-------------------------------------*/

	Vector3f::Vector3f() :
		Vector3f(0.0f, 0.0f, 0.0f)
	{

	}

	Vector3f::Vector3f(float x, float y, float z) :
		x		(x),
		y		(y),
		z		(z)
	{

	}

	float Vector3f::dot(const Vector3f& other) const
	{
		return (x * other.x + y * other.y + z * other.z);
	}

	Vector3f Vector3f::cross(const Vector3f& other)
	{
		return Vector3f(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	}

	float Vector3f::magnitude() const
	{
		return sqrtf((x * x + y * y + z * z));
	}

	void Vector3f::normalize()
	{
		*this /= magnitude();
	}

	Vector3f Vector3f::operator-()
	{
		return Vector3f(-x, -y, -z);
	}

	Vector3f Vector3f::operator+(const Vector3f& other) const
	{
		return Vector3f(x + other.x, y + other.y, z + other.z);
	}

	Vector3f Vector3f::operator-(const Vector3f& other) const
	{
		return Vector3f(x - other.x, y - other.y, z - other.z);
	}

	Vector3f Vector3f::operator*(const float& multiplier) const
	{ 
		return Vector3f(x * multiplier, y * multiplier, z * multiplier);
	}

	Vector3f Vector3f::operator/(const float& divider) const
	{
		return Vector3f(x / divider, y / divider, z / divider);
	}

	void Vector3f::operator+=(const Vector3f& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
	}

	void Vector3f::operator-=(const Vector3f& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
	}

	void Vector3f::operator*=(const float& multiplier)
	{
		x *= multiplier;
		y *= multiplier;
		z *= multiplier;
	}

	void Vector3f::operator/=(const float& divider)
	{
		x /= divider;
		y /= divider;
		z /= divider;
	}

	bool Vector3f::operator==(const Vector3f& other) const
	{
		return (x == other.x && y == other.y && z == other.z);
	}

	bool Vector3f::operator!=(const Vector3f& other) const
	{
		return (x != other.x || y != other.y || z != other.z);
	}

	bool Vector3f::operator<(const Vector3f& other) const
	{
		return magnitude() < other.magnitude();
	}

	bool Vector3f::operator>(const Vector3f& other) const
	{
		return magnitude() > other.magnitude();
	}

	bool Vector3f::operator<=(const Vector3f& other) const
	{ 
		return magnitude() <= other.magnitude();
	}

	bool Vector3f::operator>=(const Vector3f& other) const
	{
		return magnitude() >= other.magnitude();
	}

	void Vector3f::operator=(const Vector3f& other) 
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}

	float Vector3f::magnitude(const Vector3f& other)
	{
		return other.magnitude();
	}

	float Vector3f::dot(const Vector3f& vector1, const Vector3f& vector2)
	{
		return vector1.dot(vector2);
	}

	Vector3f Vector3f::cross(const Vector3f& vector1, const Vector3f& vector2)
	{
		return Vector3f(vector1.y * vector2.z - vector1.z * vector2.y, vector1.z * vector2.x - vector1.x * vector2.z, vector1.x * vector2.y - vector1.y * vector2.x);
	}

	Vector3f Vector3f::normalize(const Vector3f& vector)
	{
		return Vector3f(vector.x / vector.magnitude(), vector.y / vector.magnitude(), vector.z / vector.magnitude());
	}

	Vector3f::~Vector3f()
	{

	}

	std::ostream& operator<<(std::ostream& output, const Vector3f& vector)
	{
		output << "X : " << vector.x << ", Y : " << vector.y << ", Z : " << vector.z; 
		return output;
	}

} }