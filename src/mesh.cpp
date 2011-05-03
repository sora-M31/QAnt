#include "mesh.h"
#include <iostream>
namespace QtGLWindow
{
//------------------------------------------------------------------------------
Mesh::Mesh()
    :m_vertex(NULL),
    m_texture(NULL),
    m_face(NULL),
    m_vboPointer(NULL),
    m_mode(GL_TRIANGLES)
{
}
//------------------------------------------------------------------------------
Mesh::Mesh(
            GLfloat* _vertex,
            GLfloat* _texture,
            GLubyte* _face):
            m_vertex( _vertex),
            m_texture( _texture),
            m_face(_face),
            m_vboPointer(0),
            m_mode(GL_TRIANGLES)
{
}
//------------------------------------------------------------------------------
Mesh::~Mesh()
{
    if (m_verSize!=0)
    delete [] m_vertex;
    if (m_uvSize!=0)
    delete [] m_texture;
    if (m_faceSize!=0)
    delete [] m_face;
}

void Mesh::CreateDataArray(const std::vector<GLfloat>& _vertex, const std::vector<GLfloat>& _texture, const std::vector<GLubyte>& _face)
{
    this->m_verSize = _vertex.size();
    this->m_vertex = new GLfloat[this->m_verSize];
    for (uint32_t i=0; i< this->m_verSize; ++i)
    {
        this->m_vertex[i] = _vertex[i];
    }
    //texture
    this->m_uvSize = _texture.size();
    this->m_texture = new GLfloat[m_uvSize];
    for (uint32_t i=0; i< this->m_uvSize; ++i)
    {
        this->m_texture[i] = _texture[i];
    }
    //face
    this->m_faceSize = _face.size();
    this->m_face = new GLubyte[this->m_faceSize];
    for (uint32_t i=0; i< this->m_faceSize; ++i)
    {
        //in maya obj file, face start from 1 rather than 0!!!!!!!
        m_face[i] = _face[i]-1;
    }

}
//------------------------------------------------------------------------------
void Mesh::CreateVBO()
{
    //1 buffer object, name array m_vbopointer
    glGenBuffers(1,&m_vboPointer);
    //target,buffer name
    glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);
    //specify buffer data
    glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), m_vertex, GL_STATIC_DRAW );
    //clear the buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
//------------------------------------------------------------------------------
void Mesh::DrawVBO()
{
    if(m_vboPointer!=0)
    {
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);

    glVertexPointer(3,GL_FLOAT,0,0);

    glDrawElements(m_mode, m_faceSize, GL_UNSIGNED_BYTE, m_face);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glDisableClientState(GL_VERTEX_ARRAY);
    }
    else
    {
    std::cout<<"create vbo first please!!!"<<std::endl;
    }
}
}//end of namespace
