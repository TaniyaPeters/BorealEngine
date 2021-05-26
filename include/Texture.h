#pragma once

namespace Boreal {
	class Texture {
	public:
		Texture(const char* texturePath);
		~Texture();
		void Bind();
		void UnBind();

	private:
		unsigned int m_Texture;
		int m_Width;
		int m_Height;
		int m_Channels;
	};
}