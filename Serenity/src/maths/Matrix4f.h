#pragma once

#include <GLEW\glew.h>

#include "Vector.h"
#include "Quaternion.h"
#include "../utils/MathUtils.h"

namespace serenity { namespace maths {

	class Matrix4f
	{
	public:
		union 
		{
			GLfloat			elements	[4 * 4];
			Quaternion		columns		[4 * 1];
		};

	public:
		Matrix4f		();
		Matrix4f		(GLfloat		diagonal);
		Matrix4f		(GLfloat*		data);

	public:
		static Matrix4f		orthographic		(
													const float&		left, 
													const float&		right, 
													const float&		bottom, 
													const float&		top, 
													const float&		near, 
													const float&		far
												);
		static Matrix4f		perspective			(
													const float&		fov, 
													const float&		aspectRatio, 
													const float&		near, 
													const float&		far
												);
		static Matrix4f		translate			(	const Vector3f&		translation);
		static Matrix4f		rotate				(	const Quaternion&	rotation);
		static Matrix4f		rotate				(
													const float&		angle,
													const Vector3f&		axis
												);
		static Matrix4f		scale				(	const Vector3f&		scale);

		void			operator=				(	const Matrix4f&		other);

		Matrix4f		operator*				(	const Matrix4f&		other);
		void			operator*=				(	const Matrix4f&		other);

		Vector3f		operator*				(	const Vector3f&		other);
		Quaternion		operator*				(	const Quaternion&	other);

		friend std::ostream& operator<<(std::ostream& output, const Matrix4f& matrix);
	};

} }