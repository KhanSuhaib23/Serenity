//#define GLFW_INCLUDE_VULKAN

#include <iostream>

#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include <FreeImage\FreeImage.h>
#ifdef GLFW_INCLUDE_VULKAN
#include <vulkan\vulkan.h>
#endif

#include "src\render\Window.h"
#include "src\render\shaders\Shader.h"
#include "src\render\buffers\Buffer.h"
#include "src\render\buffers\VertexArray.h"
#include "src\render\buffers\IndexBuffer.h"
#include "src\utils\Time.h"
#include "src\utils\DynamicArray.h"
#include "src\maths\Vector.h"
#include "src\maths\Matrix4f.h"
#include "src\render\textures\Texture.h"
#include "src\render\color\Color.h"
#include "src\managers\TextureManager.h"
#include "src\render\renderables\Sprite.h"
#include "src\gamehandler\2D\Level.h"
#include "src\managers\LevelManager.h"
#include "src\render\renderer\Renderer2D.h"
#include "src\input\Input.h"


#include "ExampleGameObject.h"

#define NO_FRAME_LIMIT 0
#if 0
int main()
{

	using namespace serenity;
	using namespace render;
	using namespace utils;
	using namespace maths;
	using namespace manager;

	const GLsizei WIDTH = 960;
	const GLsizei HEIGHT = 540;

	const GLfloat ASPECT_RATIO = static_cast<GLfloat> (WIDTH) / static_cast<GLfloat> (HEIGHT);

	

	Window window(WIDTH, HEIGHT, "Serenity");


	window.init();
#if NO_FRAME_LIMIT
	window.disableFrameLimit();
#endif

	Shader shader("Basic.vert", "Basic.frag");

	int arr[2] = { 0, 1 };

	shader.enable();
	glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "projection_matrix"), 1, GL_FALSE, Matrix4f::perspective(90.0f, ASPECT_RATIO, 0.1f, 100.0f).elements);
	glUniform1iv(glGetUniformLocation(shader.m_ShaderID, "textures"), 2, arr);
	shader.disable();

	Vector3f pos(-0.5f, -0.5f, 0.0f);


	GLuint indices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	TextureManager tm;

	Texture *texture = new Texture("test.png", "testSprite");
	Texture *texture2 = new Texture("test2.png", "testSprite2");

	glActiveTexture(GL_TEXTURE0);
	texture->bind();
	glActiveTexture(GL_TEXTURE1);
	texture2->bind();

	/*
	GLfloat vertices[] =
	{
		-0.5f, -0.5f ,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
		 0.5f, -0.5f ,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,  0.0f,
		 0.5f,  0.5f ,  0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,  1.0f,
		-0.5f,  0.5f ,  0.0f,  1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  1.0f
	};
	*/
	glEnable(GL_DEPTH_TEST);

	GLfloat vertices[] = 
	{
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 1.0f,1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,

		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.0f,
		-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,0.0f,

		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, 1.0f,1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,1.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.0f,
		0.5f, -0.5f, -0.5f,  1.0f, 1.0f,0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		0.5f, -0.5f,  0.5f,  1.0f, 0.0f,0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,0.0f,

		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,1.0f,
		0.5f,  0.5f, -0.5f,  1.0f, 1.0f,1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,1.0f,
		0.5f,  0.5f,  0.5f,  1.0f, 0.0f,1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,1.0f
	};

	VertexArray* vao = new VertexArray();
	Buffer* vertex = new Buffer(vertices, sizeof(vertices), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (const GLvoid*) 0);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 9 * sizeof(GLfloat), (const GLvoid*) (3 * sizeof(GLfloat)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (const GLvoid*) (3 * sizeof(GLfloat)));
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (const GLvoid*)(5 * sizeof(GLfloat)));
	glEnableVertexAttribArray(0);
	//glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);

	IndexBuffer *ibo = new IndexBuffer(indices, sizeof(indices));
	vertex->unbind();
	vao->unbind();
	
	Vector3f position(0.0f, 0.0f, -3.0f);
	
	Matrix4f view = Matrix4f::translate(position);

	glClearColor(0.3f, 0.5f, 0.4f, 1.0f);
	Time timer;
	timer.setClock();
	while (!window.windowClosed())
	{
		window.clear();
		
		Matrix4f model = Matrix4f::rotate(timer.getElapsedTime() * 15.0f, Vector3f(1.0f, 0.0f, 1.0f));
		shader.enable(); 
		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(shader.m_ShaderID, "model_matrix");
		GLint viewLoc = glGetUniformLocation(shader.m_ShaderID, "view_matrix");
	
		// Pass them to the shaders
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model.elements);
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view.elements);
	
		vao->bind();
		texture->bind();
		texture2->bind();
		glDrawArrays(GL_TRIANGLES, 0, 36);
		texture->unbind();
		texture2->unbind();
		vao->unbind();

		window.update();
	}
}
#else

#define NUMBER 33
 
int main(int argc, char *argv[])
{

	using namespace serenity;
	using namespace render;
	using namespace utils;
	using namespace maths;
	using namespace manager;
	using namespace game;
	using namespace input;

	const GLsizei WIDTH = 960;
	const GLsizei HEIGHT = 540;

	const GLfloat ASPECT_RATIO = static_cast<GLfloat> (WIDTH) / static_cast<GLfloat> (HEIGHT);



	Window window(WIDTH, HEIGHT, "Serenity");

	

	window.init();

	window.disableFrameLimit();

	Shader shader("Basic.vert", "Basic.frag");

	int arr[32];

	for (int i = 0; i < 32; i++)
	{
		arr[i] = i;
	}
	shader.enable();
	glUniformMatrix4fv(glGetUniformLocation(shader.m_ShaderID, "view_matrix"), 1, GL_FALSE, Matrix4f::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f).elements);
	glUniform1iv(glGetUniformLocation(shader.m_ShaderID, "textures"), 32, arr);
	shader.disable();
	
	Texture* textures[NUMBER];// = new Texture("test.png", "testSprite");
	Sprite* sprites[NUMBER];
	ExampleGameObject* exGameObjs[NUMBER];
	Level *level = new Level("level1-1");
	//Texture *texture2 = new Texture("test2.png", "testSprite2");
	TextureManager* textureManager = new TextureManager();
	//textureManager->addTexture(texture);
	//textureManager->addTexture(texture2);

	char* string[NUMBER];
	
	for (int i = 0; i < NUMBER; i++)
	{
		string[i] = new char[3];
		string[i][2] = '\0';
		string[i][1] = (i + '0');
		string[i][0] = 't';
		textures[i] = new Texture("test.png", string[i]);
		textureManager->addTexture(textures[i]);
		sprites[i] = new Sprite(2.0f, 4.0f, textureManager, string[i]);

		exGameObjs[i] = new ExampleGameObject(Vector3f(i - NUMBER / 2.0f, i - NUMBER / 2.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f), string[i]);
		exGameObjs[i]->addSprite(sprites[i]);
		level->addGameObject(exGameObjs[i]);
		
	}

	LevelManager::addLevel(level);

	//Sprite *sprite = new Sprite(2.0f, 4.0f, textureManager, "testSprite");
	//Sprite *sprite1 = new Sprite(4.0f, 4.0f, textureManager, "testSprite2");

	
	//ExampleGameObject *go = new ExampleGameObject(Vector3f(2.0f, 3.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f), "player");
	//ExampleGameObject *go2 = new ExampleGameObject(Vector3f(-2.0f, -3.0f, 0.0f), Vector3f(0.0f, 0.0f, 0.0f), "player2");
	//go->addSprite(sprite);
	//go2->addSprite(sprite1);
	//level->addGameObject(go);	
	//level->addGameObject(go2);
	

	Renderer2D::init();

	while (!window.windowClosed())
	{

		window.clear();
		Input::update();
		if (Input::getKeyPressed(GLFW_KEY_A))
		{
			std::cout << "A Pressed" << std::endl;
		}
		
		shader.enable();
		Renderer2D::submit();

		//std::cout << window.getFPS() << std::endl;
		window.update();
	}


	return 0;
}
	


#endif