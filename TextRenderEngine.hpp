#include <hb.h>
#include <hb-ft.h>
#include "GL.hpp"
#include <glm/glm.hpp>
#include <map>

#include <string>
#include <ft2build.h>
#include FT_FREETYPE_H  

class TextRenderEngine {
public:
	FT_Face ft_face;
	FT_Library ft_library;
	hb_font_t* hb_font;
	hb_buffer_t* hb_buffer;
	GLuint VAO, VBO;
	GLuint program;
	void load_font(std::string font_file);
	void init_gl();
	void TextRenderEngine::RenderText(std::string text, const glm::vec2& drawable_size, float x, float y, float scale, glm::vec3 color);
	struct Character {
		unsigned int textureID;  // ID handle of the glyph texture
		glm::ivec2   size;       // Size of glyph
		glm::ivec2   bearing;    // Offset from baseline to left/top of glyph
		unsigned int advance;    // Offset to advance to next glyph
	};

	std::map<char, Character> Characters;
	TextRenderEngine();
	~TextRenderEngine();

};