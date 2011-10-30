#include "texture.h"
#include <iostream>

namespace QtGLWindow
{
//------------------------------------------------------------------------------
Texture::Texture()
    :m_data()
{}
//------------------------------------------------------------------------------
Texture::~Texture()
{
    glDeleteTextures(1, &m_texture );
}
//------------------------------------------------------------------------------
void Texture::LoadPng(const std::string& _filename)
{
    //get data from file to local array
    Magick::Image imageFile;
    imageFile.read(_filename);
    imageFile.flip();
    #if 1
    m_width = imageFile.rows();
    m_height = imageFile.columns();
    m_data = new uint8_t[ m_width * m_height * 4 ];
    imageFile.write( 0, 0, m_width, m_height, "RGBA", Magick::CharPixel, m_data);
    //imageFile.write( "output.png");
    #endif
}
//------------------------------------------------------------------------------
void Texture::LoadTexture()
{
    //get a texture name
    glGenTextures(1, &m_texture);
    glBindTexture( GL_TEXTURE_2D, m_texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
#if 1
    glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_REPLACE); // turn off modulation
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
#endif
    glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_data);
}
//------------------------------------------------------------------------------
void Texture::BindTexture()
{
    if(m_data)
    {
        glEnable( GL_TEXTURE_2D);
        glBindTexture( GL_TEXTURE_2D, m_texture );
    }
    else
    {
        std::cout<<"can't bind texture, no texture image loaded...\n";
    }
}
//------------------------------------------------------------------------------
GLuint Texture::GetTextureID()
{
    return m_texture;
}
}//end of namespace
