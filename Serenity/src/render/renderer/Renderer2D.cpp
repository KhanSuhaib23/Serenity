#include "Renderer2D.h"

namespace serenity { namespace render {

	const int Renderer2D::MAX_SPRITES;
	const int Renderer2D::VERTEX_SIZE;
	const int Renderer2D::MAX_INDICES;
	const int Renderer2D::MAX_VERTICES;
	const int Renderer2D::RENDER_BUFFER_SIZE;
	const int Renderer2D::MAX_TEXTURES;

	const int Renderer2D::POSITION_INDEX;
	const int Renderer2D::TEXTURE_ID_INDEX;
	const int Renderer2D::TEXTURE_COORDINATE_INDEX;
	const int Renderer2D::COLOR_INDEX;

	VertexArray* Renderer2D::m_VAO;
	Buffer* Renderer2D::m_VBO;
	IndexBuffer* Renderer2D::m_IBO;

	Sprite::VertexData* Renderer2D::m_VertexBuffer;

	int Renderer2D::m_IndexCount;


	void Renderer2D::init()
	{
		m_VAO = new VertexArray();
		m_VBO = new Buffer(NULL, RENDER_BUFFER_SIZE, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(POSITION_INDEX, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)offsetof(Sprite::VertexData, Sprite::VertexData::position));
		glVertexAttribPointer(TEXTURE_ID_INDEX, 1, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)offsetof(Sprite::VertexData, Sprite::VertexData::textureID));
		glVertexAttribPointer(TEXTURE_COORDINATE_INDEX, 2, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (const GLvoid*)offsetof(Sprite::VertexData, Sprite::VertexData::textureCoordinate));
		glVertexAttribPointer(COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, VERTEX_SIZE, (const GLvoid*)offsetof(Sprite::VertexData, Sprite::VertexData::color));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);

		m_VBO->unbind();

		GLuint indices[MAX_INDICES];

		int offset = 0;

		for (int i = 0; i < MAX_INDICES; i += 6)
		{
			indices[i + 0] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;
			offset += 4;
		}



		m_IBO = new IndexBuffer(indices, sizeof(indices));
		m_IBO->unbind();
		m_VAO->unbind();

	}

	void Renderer2D::begin()
	{
		m_VBO->bind();
		m_VertexBuffer = (Sprite::VertexData*) glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
	}


	void Renderer2D::submit()
	{
		game::Level* currentLevel = manager::LevelManager::getCurrentLevel();
		game::GameObject2D* gameObject;
		utils::LinkedList<game::GameObject2D*> unrendered;
		unrendered.copyDynamicArray(currentLevel->getGameObjectArray());

		begin();
		while (!unrendered.isEmpty())
		{
			int i = 0;
			while (!unrendered.isEmpty())
			{
				int size = unrendered.getSize();
 				if (i == 1)
				{
					int abc = 1;
				}
				gameObject = unrendered.peek(i);
				if (gameObject == nullptr)
				{
					break;
				}
				int tid = gameObject->getCurrentSpriteTextureID();
				if (tid < 0)
				{
					i++;
					if (i == unrendered.getSize())
					{
						break;
					}
					continue;
				}

				const maths::Vector2f& scale = gameObject->getCurrentSprite()->getScale();

				m_VertexBuffer->position = gameObject->position;
				m_VertexBuffer->textureID = static_cast<float>(tid);
				m_VertexBuffer->textureCoordinate = maths::Vector2f(0.0f, 0.0f);
				m_VertexBuffer->color = Color(255, 255, 0, 255);
				m_VertexBuffer++;

				m_VertexBuffer->position = maths::Vector3f(gameObject->position.x + scale.x, gameObject->position.y, gameObject->position.z);
				m_VertexBuffer->textureID = static_cast<float>(tid);
				m_VertexBuffer->textureCoordinate = maths::Vector2f(1.0f, 0.0f);
				m_VertexBuffer->color = Color(255, 255, 0, 255);
				m_VertexBuffer++;

				m_VertexBuffer->position = maths::Vector3f(gameObject->position.x + scale.x, gameObject->position.y + scale.y, gameObject->position.z);
				m_VertexBuffer->textureID = static_cast<float>(tid);
				m_VertexBuffer->textureCoordinate = maths::Vector2f(1.0f, 1.0f);
				m_VertexBuffer->color = Color(255, 255, 0, 255);
				m_VertexBuffer++;

				m_VertexBuffer->position = maths::Vector3f(gameObject->position.x, gameObject->position.y + scale.y, gameObject->position.z);
				m_VertexBuffer->textureID = static_cast<float>(tid);
				m_VertexBuffer->textureCoordinate = maths::Vector2f(0.0f, 1.0f);
				m_VertexBuffer->color = Color(255, 255, 0, 255);
				m_VertexBuffer++;

				m_IndexCount += 6;

				unrendered.pop(i);

			}
			end();
			flush();
			begin();
		}
		end();
	}

	void Renderer2D::end()
	{
		glUnmapBuffer(GL_ARRAY_BUFFER);
		m_VBO->unbind();
	}

	void Renderer2D::flush()
	{
		m_VAO->bind();
		m_IBO->bind();

		glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

		m_IBO->unbind();
		m_VAO->unbind();
		m_IndexCount = 0;
	}

} }