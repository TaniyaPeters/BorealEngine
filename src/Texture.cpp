#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glad/glad.h"

namespace Boreal {
	Texture::Texture(const char* texturePath) {
		unsigned char* data = stbi_load(texturePath, &m_Width, &m_Height, &m_Channels, 0);
		glGenTextures(1, &m_Texture);
		Bind();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		UnBind();
		stbi_image_free(data);
	}

	Texture::~Texture() {
		glDeleteTextures(1, &m_Texture);
	}

	void Texture::Bind() {
		glBindTexture(GL_TEXTURE_2D, m_Texture);
	}

	void Texture::UnBind() {
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}