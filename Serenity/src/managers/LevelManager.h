#pragma once

#include "../gamehandler/2D/Level.h"

namespace serenity { namespace manager {

	class LevelManager
	{
	private:
		static utils::DynamicArray<game::Level*> m_Levels;
		static GLuint m_CurrentLevel;

	public:
		static void					addLevel				(game::Level*		level);
		static void					changeCurrentLevel		(const GLchar*		levelName);
		static game::Level*			getCurrentLevel			();



	//	static void submit()
	//	{
	//		getCurrentLevel()->submit();
	//	}

	};

} }