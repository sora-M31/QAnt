//------------------------------------------------------------------------------
#include "mesh.h"
#include <iostream>
#include <math.h>
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
    //1 face has 9 data, 3 for ver, 3 for normal, 3 for texture
    //divide by three, so we know size of each type of data
    uint32_t size = _face.size()/3;
    // a vertex has 3 element
    if( _vertex.size()>0)
        m_verSize = size*3;
    else
        m_verSize = 0;
    // a vertex has 2 element
    if( _texture.size()>0)
        m_textureSize =size*2;
    else
        m_textureSize =0;
    // a normal has 3 element
    if( _normal.size()>0)
        m_normalSize = size*3;
    else
        m_normalSize=0;
    // a face has 3 sets of element,which is _face.size()/3;
    m_faceSize = size;

    std::cout<<m_verSize<<" vertex \n";
    std::cout<<m_textureSize<<"texture \n";
    std::cout<<m_normalSize<<"normal \n";
    std::cout<<m_faceSize<<"face \n";

    m_vertex = new GLfloat[m_verSize];
    m_texture = new GLfloat[m_textureSize];
    m_normal = new GLfloat[m_normalSize];
    m_face = new GLuint[m_faceSize];
    
    //get correspondence vertex and normal in the sequence of indice(face)
    for( uint32_t i=0; i< _face.size(); i+=3)
    {
        // maya face start from 1, each face have 3 sets of vertex/normal
        uint32_t faceIndex= (_face[i] -1)*3;
        //vertexes
        //x
        m_vertex[i] = _vertex[faceIndex];
        //y
        m_vertex[i+1] = _vertex[faceIndex+1];
        //z
        m_vertex[i+2] = _vertex[faceIndex+2];

        //textures
        //check if there's texture
        if(m_textureSize!=0)
        {
            uint32_t tIndex = (_face[i+1]-1)*2;
            //u
            m_texture[ i/3 *2] = _texture[tIndex];
            //v
            m_texture[ i/3 *2+1] = _texture[tIndex+1];
        }
#if 1
        ///normal
        uint32_t nIndex = (_face[i+2]-1)*3;
        //x
        m_normal[i] =  _normal[ nIndex];
        //y
        m_normal[i+1] =  _normal[ nIndex + 1];
        //z
        m_normal[i+2] =   _normal[ nIndex + 2];
#endif
#if 0
        ///averaged normal
        //x
        m_normal[i] =  _normal[ faceIndex];
        //y
        m_normal[i+1] =  _normal[ faceIndex + 1];
        //z
        m_normal[i+2] =   _normal[ faceIndex + 2];
#endif
#if 0
        faceIndex = -face[i+2]-1
        m_texture[i] = _texture[(_face[i+1]-1)*2];
        m_texture[i+1] = _texture[(_face[i+1]-1)*2+1];
#endif
    }
    for(uint32_t i=0; i<m_faceSize; i++)
    {
        m_face[i]=i;
    }
    std::cout<<"ready for vboloading\n";
    std::cout<<"vertex\n";
    for(uint32_t i=0; i<m_verSize; ++i)
    {
        if(i%3==2)
        std::cout<<m_vertex[i]<<"\n";
        else
        std::cout<<m_vertex[i]<<" ";
    }
    std::cout<<"texture\n";
    for(uint32_t i=0; i<m_textureSize; ++i)
    {
        if(i%2==1)
        std::cout<<m_texture[i]<<"\n";
        else
        std::cout<<m_texture[i]<<" ";
    }
    std::cout<<"normal\n";
    for(uint32_t i=0; i<m_normalSize; ++i)
    {
        if(i%3==2)
        std::cout<<m_normal[i]<<"\n";
        else
        std::cout<<m_normal[i]<<" ";
    }
}
#if 0
void Mesh::Smooth()
{
    for( uint32_t i=0; i<m_verSize; i+=3 )
    {
        if(
    }
}
#endif
//------------------------------------------------------------------------------
void Mesh::CreateVBO()
{
    //1 buffer object, name array m_vbopointer
    glGenBuffers(1,&m_vboPointer);
    //target,buffer name
    glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);
    //specify buffer data
    glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT) + m_normalSize * sizeof(GL_FLOAT) + m_textureSize*sizeof(GL_FLOAT), 0, GL_STATIC_DRAW );
    //glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT) + m_normalSize * sizeof(GL_FLOAT), 0, GL_STATIC_DRAW );

    glBufferSubData(GL_ARRAY_BUFFER, 0, m_verSize*sizeof(GL_FLOAT) , m_vertex);
    glBufferSubData(GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), m_normalSize * sizeof(GL_FLOAT), m_normal);
    glBufferSubData(GL_ARRAY_BUFFER, (m_verSize+m_normalSize)*sizeof(GL_FLOAT), m_textureSize * sizeof(GL_FLOAT), m_texture);
    //clear the buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
//------------------------------------------------------------------------------
void Mesh::UpdateVBO()
{
    glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);
    //specify buffer data
    glBufferData( GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), 0, GL_STATIC_DRAW );
    glBufferSubData(GL_ARRAY_BUFFER, 0, m_verSize*sizeof(GL_FLOAT), m_vertex);
    glBufferSubData(GL_ARRAY_BUFFER, m_verSize*sizeof(GL_FLOAT), m_normalSize * sizeof(GL_FLOAT), m_normal);
    glBufferSubData(GL_ARRAY_BUFFER, (m_verSize+m_normalSize)*sizeof(GL_FLOAT), m_textureSize * sizeof(GL_FLOAT), m_texture);
    //clear the buffer
    glBindBuffer(GL_ARRAY_BUFFER,0);
}
//------------------------------------------------------------------------------
void Mesh::DrawVBO()
{
    #define BUFFER_OFFSET(i) ((float*)NULL + i)
    if(m_vboPointer!=0)
    {
        glBindBuffer(GL_ARRAY_BUFFER,m_vboPointer);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glVertexPointer(3,GL_FLOAT,0,0);
        glNormalPointer(GL_FLOAT,0,BUFFER_OFFSET(m_verSize));
        glTexCoordPointer(2,GL_FLOAT,0,BUFFER_OFFSET(m_verSize+m_normalSize));
        glDrawElements(m_mode, m_faceSize, GL_UNSIGNED_INT, m_face);
        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);

        glBindBuffer(GL_ARRAY_BUFFER,0);
    }
    else
    {
        std::cout<<"create vbo first please!!!"<<std::endl;
    }
}

bool once=true;
//------------------------------------------------------------------------------
void Mesh::DrawNormal()
{
    if (once)
    {
        for(uint32_t i =0; i < m_faceSize*3; ++i)
            std::cout << "v" << i << "\t" << m_vertex[i] << "\n";
        for(uint32_t i =0; i < m_faceSize*3; ++i)
            std::cout << "n" << i << "\t" << m_normal[i] << "\n";
    }
    for( uint32_t i=0; i<m_verSize; i+=3)
    {
        GLfloat& vx = m_vertex[i];
        GLfloat& vy = m_vertex[i+1];
        GLfloat& vz = m_vertex[i+2];

        GLfloat& nx = m_normal[i];
        GLfloat& ny = m_normal[i+1];
        GLfloat& nz = m_normal[i+2];

        //normalise normal
#if 1 
        GLfloat length = sqrt(nx*nx+ ny*ny +nz*nz);
        m_normal[i]/=length;
        m_normal[i+1]/=length;
        m_normal[i+2]/=length;
#endif
        glBegin(GL_LINES);
            glVertex3f( vx,vy,vz);
            glVertex3f( vx+nx,vy+ny,vz+nz);
        glEnd();
    }

    once = false;
}
}//end of namespace
