#pragma once

#include "GameObject2D.h"
#include "../../utils/DynamicArray.h"

namespace serenity { namespace game {

	class Level
	{
	private:
		utils::DynamicArray<GameObject2D*>			 m_GameObjects;
		const GLchar*								 m_Name;

	public:
		Level			(
							const GLchar*		name
						);

	public:
		void				addGameObject(GameObject2D* gameObject);

	public:
		inline const GLchar*								getName() { return m_Name; }
		inline utils::DynamicArray<GameObject2D*>&			getGameObjectArray() { return m_GameObjects; }

	};

} }