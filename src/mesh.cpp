#include "mesh.h"
#include <iostream>
namespace QtGLWindow
{
//------------------------------------------------------------------------------
Mesh::Mesh()
    :m_vertex(NULL),
      m_normal(NULL),
    m_texture(NULL),
    m_face(NULL),
    m_vboPointer(NULL),
    m_mode(GL_TRIANGLES),
    m_verSize(0),
    m_normalSize(0),
    m_textureSize(0),
    m_faceSize(0)
{
}
//------------------------------------------------------------------------------
Mesh::~Mesh()
{
    if (m_verSize!=0)
    {
        delete [] m_vertex;
    }
    if (m_normalSize!=0)
    {
        delete [] m_normal;
    }
    if (m_textureSize!=0)
    {
        delete [] m_texture;
    }
    if (m_faceSize!=0)
    {
        delete [] m_face;
    }
}
//------------------------------------------------------------------------------
void Mesh::CreateDataArray(const std::vector<GLfloat>& _vertex, const std::vector<GLfloat>& _normal, const std::vector<GLfloat>& _texture, const std::vector<GLuint>& _face)
{
#if 0
    for (uint32_t i=0; i< m_verSize; ++i)
    {
        m_vertex[i] = _vertex[i];
    }
    //normal
    for (uint32_t i=0; i< m_normalSize; ++i)
    {
        m_normal[i] = _normal[i];
    }
    //texture
        for (uint32_t i=0; i< m_textureSize; ++i)
    {
        m_texture[i] = _texture[i];
    }
    //face
    m_faceSize = _face.size();
    m_face = new GLuint[m_faceSize];
    for (uint32_t i=0; i< m_faceSize; ++i)
    {
        //in obj file, face start from 1 rather than 0!!!!!!!
        m_face[i] = _face[i]-1;
        //std::cout << (int)(_face[i]) << ' ';
       // if (i%3 == 2)
         //   std::cout << '\n';
    }
#endif
    uint32_t size = _face.size()/3;
    m_verSize = size*3;
    m_textureSize =size*2;
    m_normalSize = size*3;
    m_faceSize = size;
    std::cout<<m_verSize<<"loaded vertex size\n";
    std::cout<<m_textureSize<<"loaded texture size\n";
    std::cout<<m_normalSize<<"loaded normal size\n";
    std::cout<<m_faceSize<<"loaded face size\n";

    m_vertex = new GLfloat[m_verSize];
    m_texture = new GLfloat[m_textureSize];
    m_normal = new GLfloat[m_normalSize];
    m_face = new GLuint[m_faceSize];

    for( uint32_t i=0; i< _face.size(); i+=3)
    {
        uint32_t faceIndex= (_face[i] -1)*3;
        m_vertex[i] = _vertex[faceIndex];
        std::cout<<"vertex "<<i<<"get from"<<faceIndex<<"\n";
        m_vertex[i+1] = _vertex[faceIndex+1];
        m_vertex[i+2] = _vertex[faceIndex+2];
#if 1
        m_normal[i] = _normal[ faceIndex];
        m_normal[i+1] = _normal[ faceIndex + 1];
        m_normal[i+2] = _normal[ faceIndex + 2];

        //faceIndex = -face[i+2]-1
        //m_texture[i] = _texture[(_face[i+1]-1)*2];
        //m_texture[i+1] = _texture[(_face[i+1]-1)*2+1];
#endif
    }
    for(uint32_t i=0; i<m_faceSize; i++)
    {
        m_face[i]=i;
    }
    for(uint32_t i=0; i<m_verSize; ++i)
    {
        if(i%3==2)
        std::cout<<m_vertex[i]<<"\n";
        else
        std::cout<<m_vertex[i]<<" ";
    }

    for(uint32_t i=0; i<m_normalSize; ++i)
    {
        if(i%3==2)
        std::cout<<m_normal[i]<<"\n";
        else
        std::cout<<m_normal[i]<<" ";
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
    //glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), 0, GL_STATIC_DRAW );
    glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT) + m_normalSize * sizeof(GL_FLOAT), 0, GL_STATIC_DRAW );
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_verSize*sizeof(GL_FLOAT) , m_vertex);
    glBufferSubData(GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), m_normalSize * sizeof(GL_FLOAT), m_normal);
    //clear the buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
//------------------------------------------------------------------------------
void Mesh::UpdateVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);
    //specify buffer data
    glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), 0, GL_STATIC_DRAW );
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_verSize*sizeof(GL_FLOAT)	, m_vertex);
    glBufferSubData(GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), m_normalSize * sizeof(GL_FLOAT), m_normal);
    //clear the buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
//------------------------------------------------------------------------------
void Mesh::DrawVBO()
{
    #define BUFFER_OFFSET(i) ((float*)NULL + i)
    if(m_vboPointer!=0)
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);

        glVertexPointer(3,GL_FLOAT,0,0);
        glNormalPointer(GL_FLOAT,0,BUFFER_OFFSET(m_verSize));

        glDrawElements(m_mode, m_faceSize, GL_UNSIGNED_INT, m_face);

        glBindBuffer(GL_ARRAY_BUFFER,0);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
    }
    else
    {
        std::cout<<"create vbo first please!!!"<<std::endl;
    }
}
}//end of namespace
