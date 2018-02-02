#pragma once

#include <stddef.h>

#include "../../managers/LevelManager.h"
#include "../buffers/Buffer.h"
#include "../buffers/VertexArray.h"
#include "../buffers/IndexBuffer.h"
#include "../../utils/LinkedList.h"

namespace serenity { namespace render {

	class Renderer2D
	{
	private:
		static const int				MAX_SPRITES					=			10000;
		static const int				VERTEX_SIZE					=			sizeof(Sprite::VertexData);
		static const int				MAX_INDICES					=			MAX_SPRITES * 6;
		static const int				MAX_VERTICES				=			MAX_SPRITES * 4;
		static const int				RENDER_BUFFER_SIZE			=			MAX_VERTICES * VERTEX_SIZE;
		static const int				MAX_TEXTURES				=			32;

		static const int				POSITION_INDEX				=			0;
		static const int				TEXTURE_ID_INDEX			=			1;
		static const int				TEXTURE_COORDINATE_INDEX	=		    2;
		static const int				COLOR_INDEX					=			3;

		static VertexArray*				m_VAO;
		static Buffer*					m_VBO;
		static IndexBuffer*				m_IBO;

		static Sprite::VertexData*		m_VertexBuffer;

		static int						m_IndexCount;

	public:
		static void			init		();
		static void			begin		();
		static void			submit		();
		static void			end			();
		static void			flush		();

	};


} }
