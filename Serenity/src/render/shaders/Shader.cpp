#include "Shader.h"

namespace serenity { namespace render {

	Shader::Shader() :
		Shader("Basic.vert", "Basic.frag")
	{

	}

	Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
	{
#ifdef BIT_32
		std::string temp1 = "../Serenity/src/render/shaders/vertex/";
#endif
#ifdef BIT_64
		std::string temp1 = "../Serenity/src/render/shaders/vertex/";
#endif
		temp1 += std::string(vertexPath);
		m_VertexPath = temp1.c_str();
#ifdef BIT_32
		std::string temp2 = "../Serenity/src/render/shaders/fragment/";
#endif
#ifdef BIT_64
		std::string temp2 = "../Serenity/src/render/shaders/fragment/";
#endif
		temp2 += std::string(fragmentPath);
		m_FragmentPath = temp2.c_str();

		m_ShaderID = load();
	}

	GLuint Shader::load()
	{
		GLint result;

		GLuint program = glCreateProgram();
		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

		const GLchar* vertexSource = utils::FileUtils::loadTextFile(m_VertexPath);
		glShaderSource(vertexShaderID, 1, &vertexSource, NULL);
		glCompileShader(vertexShaderID);
		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);

		if (!result)
		{
			std::cout << "Cannot Compile Vertex Shader" << std::endl;
			system("PAUSE");
			exit(-1);
		}

		const GLchar* fragmentSource = utils::FileUtils::loadTextFile(m_FragmentPath);
		glShaderSource(fragmentShaderID, 1, &fragmentSource, NULL);
		glCompileShader(fragmentShaderID);
		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);

		if (!result)
		{
			std::cout << "Cannot Compile Fragment Shader" << std::endl;
			system("PAUSE");
			exit(-1);
		}

		glAttachShader(program, vertexShaderID);
		glAttachShader(program, fragmentShaderID);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertexShaderID);
		glDeleteShader(fragmentShaderID);

		return program;

	}

	void Shader::enable()
	{
		glUseProgram(m_ShaderID);
	}

	void Shader::disable()
	{
		glUseProgram(0);
	}
		

} }