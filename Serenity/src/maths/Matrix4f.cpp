#include "Matrix4f.h"

namespace serenity { namespace maths {
	
	Matrix4f::Matrix4f()
	{
		elements[0 + 0 * 4] = 0.0f;     //column major elements row + col * width
		elements[1 + 0 * 4] = 0.0f;
		elements[2 + 0 * 4] = 0.0f;
		elements[3 + 0 * 4] = 0.0f;
		elements[0 + 1 * 4] = 0.0f;
		elements[1 + 1 * 4] = 0.0f;
		elements[2 + 1 * 4] = 0.0f;
		elements[3 + 1 * 4] = 0.0f;
		elements[0 + 2 * 4] = 0.0f;
		elements[1 + 2 * 4] = 0.0f;
		elements[2 + 2 * 4] = 0.0f;
		elements[3 + 2 * 4] = 0.0f;
		elements[0 + 3 * 4] = 0.0f;
		elements[1 + 3 * 4] = 0.0f;
		elements[2 + 3 * 4] = 0.0f;
		elements[3 + 3 * 4] = 0.0f;
	}

	Matrix4f::Matrix4f(GLfloat diagonal)
	{
		elements[0 + 0 * 4] = diagonal;
		elements[1 + 0 * 4] = 0.0f;
		elements[2 + 0 * 4] = 0.0f;
		elements[3 + 0 * 4] = 0.0f;
		elements[0 + 1 * 4] = 0.0f;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 1 * 4] = 0.0f;
		elements[3 + 1 * 4] = 0.0f;
		elements[0 + 2 * 4] = 0.0f;
		elements[1 + 2 * 4] = 0.0f;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 2 * 4] = 0.0f;
		elements[0 + 3 * 4] = 0.0f;
		elements[1 + 3 * 4] = 0.0f;
		elements[2 + 3 * 4] = 0.0f;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4f::Matrix4f(GLfloat* data)
	{
		memcpy(this->elements, data, 16);
	}

	Matrix4f Matrix4f::orthographic(const float &left, const float &right, const float &bottom, const float &top, const float &near, const float &far)
	{
		Matrix4f res(1.0f);

		res.elements[0 + 0 * 4] = 2 / (right - left);
		res.elements[1 + 1 * 4] = 2 / (top - bottom);
		res.elements[2 + 2 * 4] = 2 / (near - far);
		res.elements[0 + 3 * 4] = (left + right) / (left - right);
		res.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		res.elements[2 + 3 * 4] = (near + far) / (near - far);

		return res;
	}

	Matrix4f Matrix4f::perspective(const float &fov, const float &aspectRatio, const float &near, const float &far)
	{
		Matrix4f res;

		float rfov = utils::MathUtils::toRadians(fov);
		float cot = 1.0f / tanf(rfov * 0.5f);

		res.elements[0 + 0 * 4] = cot / aspectRatio;
		res.elements[1 + 1 * 4] = cot;
		res.elements[2 + 2 * 4] = (near + far) / (near - far);
		res.elements[2 + 3 * 4] = (2 * near * far) / (near - far);
		res.elements[3 + 2 * 4] = -1.0f;

		return res;
	}

	Matrix4f Matrix4f::translate(const Vector3f &translation)
	{
		Matrix4f res(1.0f);

		res.elements[0 + 3 * 4] = translation.x;
		res.elements[1 + 3 * 4] = translation.y;
		res.elements[2 + 3 * 4] = translation.z;

		return res;
	}

	Matrix4f Matrix4f::scale(const Vector3f &scaleFactor)
	{
		Matrix4f res(1.0f);

		res.elements[0 + 0 * 4] = scaleFactor.x;
		res.elements[1 + 1 * 4] = scaleFactor.y;
		res.elements[2 + 2 * 4] = scaleFactor.z;

		return res;
	}

	Matrix4f Matrix4f::rotate(const float &angle, const Vector3f &axis)
	{
		Matrix4f res(1.0f);


		float rangle = utils::MathUtils::toRadians(angle);
		float cos = cosf(rangle);
		float sin = sinf(rangle);

		float magnitude = axis.magnitude();

		float x = axis.x / magnitude;
		float y = axis.y / magnitude;
		float z = axis.z / magnitude;

		res.elements[0 + 0 * 4] = (x * x * (1 - cos)) + (cos);
		res.elements[0 + 1 * 4] = (x * y * (1 - cos)) - (z * sin);
		res.elements[0 + 2 * 4] = (x * z * (1 - cos)) + (y * sin);
		res.elements[1 + 0 * 4] = (x * y * (1 - cos)) + (z * sin);
		res.elements[1 + 1 * 4] = (y * y * (1 - cos)) + (cos);
		res.elements[1 + 2 * 4] = (y * z * (1 - cos)) - (x * sin);
		res.elements[2 + 0 * 4] = (x * z * (1 - cos)) - (y * sin);
		res.elements[2 + 1 * 4] = (y * z * (1 - cos)) + (x * sin);
		res.elements[2 + 2 * 4] = (z * z * (1 - cos)) + (cos);

		return res;
	}

	Matrix4f Matrix4f::rotate(const maths::Quaternion &rotation)
	{
		using namespace utils;

		Matrix4f res(1.0f);

		float rangle = MathUtils::toRadians(rotation.w);
		float cos = cosf(rangle);
		float sin = sinf(rangle);

		float x = rotation.x;
		float y = rotation.y;
		float z = rotation.z;

		res.elements[0 + 0 * 4] = (x * x * (1 - cos)) + (cos);
		res.elements[0 + 1 * 4] = (x * y * (1 - cos)) - (z * sin);
		res.elements[0 + 2 * 4] = (x * z * (1 - cos)) + (y * sin);
		res.elements[1 + 0 * 4] = (x * y * (1 - cos)) + (z * sin);
		res.elements[1 + 1 * 4] = (y * y * (1 - cos)) + (cos);
		res.elements[1 + 2 * 4] = (y * z * (1 - cos)) - (x * sin);
		res.elements[2 + 0 * 4] = (x * z * (1 - cos)) - (y * sin);
		res.elements[2 + 1 * 4] = (y * z * (1 - cos)) + (x * sin);
		res.elements[2 + 2 * 4] = (z * z * (1 - cos)) + (cos);

		return res;
	}

	void Matrix4f::operator=(const Matrix4f &other)
	{
		memcpy(this->elements, other.elements, 4 * 4 * sizeof(float));
	}

	Matrix4f Matrix4f::operator*(const Matrix4f &other)
	{
		Matrix4f res;
		for (int i = 0; i < 4; i++)  // row
		{
			for (int j = 0; j < 4; j++) //col
			{
				float sum = 0.0f;
				for (int k = 0; k < 4; k++)
				{
					sum += elements[i + k * 4] * other.elements[k + j * 4];
				}
				res.elements[i + j * 4] = sum;
			}
		}
		return res;
	}

	void Matrix4f::operator*=(const Matrix4f &other)
	{
		Matrix4f res;

		for (int i = 0; i < 4; i++)  // row
		{
			for (int j = 0; j < 4; j++) //col
			{
				float sum = 0.0f;
				for (int k = 0; k < 4; k++)
				{
					sum += elements[i + k * 4] * other.elements[k + j * 4];
				}
				res.elements[i + j * 4] = sum;
			}
		}
		*this = res;

	}
	
	Vector3f Matrix4f::operator*(const Vector3f &other)
	{
		Vector3f res;

		res.x = (elements[0 + 0 * 4] * other.x) + (elements[0 + 1 * 4] * other.y) + (elements[0 + 2 * 4] * other.z) + (elements[0 + 3 * 4]);
		res.y = elements[1 + 0 * 4] * other.x + elements[1 + 1 * 4] * other.y + elements[1 + 2 * 4] * other.z + elements[1 + 3 * 4];
		res.z = elements[2 + 0 * 4] * other.x + elements[2 + 1 * 4] * other.y + elements[2 + 2 * 4] * other.z + elements[2 + 3 * 4];

		return res;
	}

	Quaternion Matrix4f::operator*(const Quaternion &other)
	{
		Quaternion res;

		res.x = (elements[0 + 0 * 4] * other.x) + (elements[0 + 1 * 4] * other.y) + (elements[0 + 2 * 4] * other.z) + (elements[0 + 3 * 4]);
		res.y = (elements[1 + 0 * 4] * other.x) + (elements[1 + 1 * 4] * other.y) + (elements[1 + 2 * 4] * other.z) + (elements[1 + 3 * 4]);
		res.z = (elements[2 + 0 * 4] * other.x) + (elements[2 + 1 * 4] * other.y) + (elements[2 + 2 * 4] * other.z) + (elements[2 + 3 * 4]);
		res.w = (elements[3 + 0 * 4] * other.x) + (elements[3 + 1 * 4] * other.y) + (elements[3 + 2 * 4] * other.z) + (elements[3 + 3 * 4]);

		return res;
	}
	
	std::ostream& operator<<(std::ostream& output, const Matrix4f& matrix)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				output << matrix.elements[i + j * 4] << " ";
			}
			output << "\n";
		}
		return output;
	}

} }