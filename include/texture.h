#ifndef _TEXTURE_H_
#define _TEXTURE_H_
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Magick++.h>
#include <string>

namespace QtGLWindow
{
class Texture
{
    public:
        Texture();
        ~Texture();
        void LoadImage(const std::string& _filename);
        void MakeChecker();
        void LoadTexture();
        void BindTexture();
        GLuint GetTextureID();
    private:
        GLuint m_texture;
        uint8_t* m_data;
        uint32_t m_width;
        uint32_t m_height;
};//end of class
}//end of namespace
#endif //end of define
