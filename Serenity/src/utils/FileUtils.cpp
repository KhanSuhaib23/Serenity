#include "FileUtils.h"

namespace serenity { namespace utils {

	GLchar* FileUtils::loadTextFile(const GLchar* filePath)
	{

		FILE* file = fopen(filePath, "rt");
		if (file == nullptr)
		{
			std::cout << "Unable To Open File From File Path : \"" << filePath << "\"" << std::endl;
			system("PAUSE");
			exit(-1);
		}

		fseek(file, 0, SEEK_END);
		GLuint length = ftell(file);
		fseek(file, 0, SEEK_SET);
		GLchar* text = new GLchar[length + 1];
		memset(text, 0, length + 1);
		fread(text, length, 1, file);

		return text;
	}

	BYTE* FileUtils::loadImageFile(const GLchar* filePath, GLuint& width, GLuint& height)
	{
		FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
		FIBITMAP *dib = nullptr;
		BYTE *pixels = nullptr;

		fif = FreeImage_GetFileType(filePath);

		if (fif == FIF_UNKNOWN)
		{
			fif = FreeImage_GetFIFFromFilename(filePath);
			if (fif == FIF_UNKNOWN)
			{
				std::cout << "Couldn't Determine File Format" << std::endl;
				system("PAUSE");
				return nullptr;
			}
		}

		if (FreeImage_FIFSupportsReading(fif))
		{
			dib = FreeImage_Load(fif, filePath, 0);
		}

		if (!dib)
		{
			std::cout << "Cannot Get Bit Map From File" << std::endl;
			system("PAUSE");
			return nullptr;
		}

		pixels = FreeImage_GetBits(dib);
		width = FreeImage_GetWidth(dib);
		height = FreeImage_GetHeight(dib);

		return pixels;


	}

} }