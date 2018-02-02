#pragma once

#include <iostream>
#include <math.h>

namespace serenity { namespace maths {

	class Vector2f
	{
	public:
		float x;
		float y;

	public:
		Vector2f		();
		Vector2f		(
							float		x,
							float		y
						);

		~Vector2f		();

	public:
		float		magnitude			()											const;
		float		dot					(	const Vector2f&			other)			const;
		void		normalize			();

		Vector2f	operator-			()											const;

		Vector2f	operator+			(	const Vector2f&			other)			const;
		Vector2f	operator-			(	const Vector2f&			other)			const;	
		Vector2f	operator*			(	const float&			multiplier)		const;	
		Vector2f	operator/			(	const float&			divider)		const;		

		void		operator+=			(	const Vector2f&			other);
		void		operator-=			(	const Vector2f&			other);
		void		operator*=			(	const float&			multiplier);
		void		operator/=			(	const float&			divider);

		bool		operator==			(	const Vector2f&			other)			const;
		bool		operator!=			(	const Vector2f&			other)			const;
		bool		operator<			(	const Vector2f&			other)			const;
		bool		operator>			(	const Vector2f&			other)			const;
		bool		operator<=			(	const Vector2f&			other)			const;
		bool		operator>=			(	const Vector2f&			other)			const;
																			
		void		operator=			(	const Vector2f&			other);

	public:
		static float		magnitude			(	const Vector2f&			vector);
		static float		dot					(
													const Vector2f&			vector1,
													const Vector2f&			vector2
												);
		static Vector2f		normalize			(	const Vector2f&			vector);

		friend std::ostream& operator<<(std::ostream& output, const Vector2f& vector);
	};

	class Vector3f
	{
	public:
		float		x;
		float		y;
		float		z;

	public:
		Vector3f		();
		Vector3f		(
							float		x,
							float		y,
							float		z
						);

		~Vector3f		();

	public:
		float		magnitude			() const;
		float		dot					(	const Vector3f&			other)			const;
		Vector3f	cross				(	const Vector3f&			other);
		void		normalize			();

		Vector3f	operator-			();

		Vector3f	operator+			(	const Vector3f&			other)			const;
		Vector3f	operator-			(	const Vector3f&			other)			const;
		Vector3f	operator*			(	const float&			multiplier)		const;
		Vector3f	operator/			(	const float&			divider)		const;

		void		operator+=			(	const Vector3f&			other);
		void		operator-=			(	const Vector3f&			other);
		void		operator*=			(	const float&			multiplier);
		void		operator/=			(	const float&			divider);

		bool		operator==			(	const Vector3f&			other)			const;
		bool		operator!=			(	const Vector3f&			other)			const;
		bool		operator<			(	const Vector3f&			other)			const;
		bool		operator>			(	const Vector3f&			other)			const;
		bool		operator<=			(	const Vector3f&			other)			const;
		bool		operator>=			(	const Vector3f&			other)			const;
																			
		void		operator=			(	const Vector3f&			other);

	public:
		static float		magnitude		(	const Vector3f&			vector);
		static float		dot				(
												const Vector3f&			vector1,
												const Vector3f&			vector2
											);
		static Vector3f		cross			(
												const Vector3f&			vector1,
												const Vector3f&			vector2
											);
		static Vector3f		normalize		(	const Vector3f&			vector);

		friend std::ostream& operator<<(std::ostream& output, const Vector3f& vector);
	};

} }