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
//------------------------------------------------------------------------------
void Mesh::CreateVBO()
{
    glGenBuffers(1,&m_vboPointer);
    glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);
    
    glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), m_vertex, GL_STATIC_DRAW );
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
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

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
