#include "objLoader.h"

namespace QtGLWindow
{
//------------------------------------------------------------------------------
ObjLoader::ObjLoader()
    :m_pMesh( new Mesh() )
{
}
//------------------------------------------------------------------------------
ObjLoader::~ObjLoader()
{
    delete m_pMesh;
}
//------------------------------------------------------------------------------
void ObjLoader::ParseFile(std::string _Filename)
{
    std::ifstream fileIn;
    fileIn.open(_Filename.c_str());
    std::string lineBuffer;
    if(fileIn.is_open())
    {
       //get each line into a buffer
        while(!fileIn.eof())
        {
            getline(fileIn,lineBuffer,'\n');
            //tokenize the line buffer into result
            std::vector<std::string> result;
            Tokenize(lineBuffer, result, " ");
            //parse the line according to first token
            std::vector<std::string>::iterator it_first=result.begin();
            if(result.size()!=0)
            {
                if( *it_first == "v")
                {
                   // parsevertex(atof push back)
                   ParseVertex( it_first );
                   //std::cout<<"vertex"<<std::endl;
                }
                else if( *it_first == "#")
                {
                    //std::cout<<"comment"<<std::endl;
                }
                else if( *it_first == "vt")
                {
                    //std::cout<<"texture"<<std::endl;
                    //ParseTexture( it_first );
                }
                else if( *it_first == "f")
                {
                    //std::cout<<"face"<<std::endl;
                    uint32_t numberOfVert = result.size()-1;
                    ParseFace( it_first,numberOfVert);
                    //std::cout<<"face vert number "<<numberOfVert<<std::endl;
                }
                else
                {
                    //std::cout<<"unknown type"<<std::endl;
                }
            }
        }
    }
    else
    {
        std::cout<<"file not loaded"<<std::endl;
    }
    fileIn.close();
}

//------------------------------------------------------------------------------
void ObjLoader::ParseVertex(std::vector<std::string>::iterator _begin)
{
    ++_begin;
    for( uint32_t i=0; i<3; ++i)
    {
        m_vertexBuffer.push_back(atof((*_begin).c_str()));
        ++_begin;
    }

}
//-----------------------------------------------------------------------------
void ObjLoader::ParseTexture(std::vector<std::string>::iterator _begin)
{
    ++_begin;
    for( uint32_t i=0; i<2; ++i)
    {
        m_textureBuffer.push_back(atof((*_begin).c_str()));
        ++_begin;
    }

}
//------------------------------------------------------------------------------
void ObjLoader::ParseFace(std::vector<std::string>::iterator _begin, uint32_t _vertNum)
{
    ++_begin;
    if (_vertNum == 3)
    {
        for( uint32_t i=0; i<3; ++i)
        {
            std::vector<std::string> r;
            //std::cout<<*_begin<<std::endl;
            std::string str(*_begin);
            Tokenize(str, r, "/");
            m_faceBuffer.push_back(atof(r[0].c_str()));
            ++_begin;
        }
    }
    else if (_vertNum == 4)
    {
        std::vector<GLuint> temp;
        for( uint32_t i=0; i<4; ++i)
        {
            std::vector<std::string> r;
            //std::cout<<*_begin<<std::endl;
            std::string str(*_begin);
            Tokenize(str, r, "/");
            temp.push_back(atof(r[0].c_str()));
            ++_begin;
        }
        //transfer quad to triangle
        m_faceBuffer.push_back(temp[0]);
        m_faceBuffer.push_back(temp[1]);
        m_faceBuffer.push_back(temp[2]);
        m_faceBuffer.push_back(temp[2]);
        m_faceBuffer.push_back(temp[3]);
        m_faceBuffer.push_back(temp[0]);
    }
}
//------------------------------------------------------------------------------
void ObjLoader::Check()
{
    for(uint32_t i=0;i<m_pMesh->m_verSize;++i)
    {
        std::cout<<m_vertexBuffer[i]<<" "<<i<<std::endl;
    }
    for(uint32_t i=0;i<m_pMesh->m_faceSize;++i)
    {
        std::cout<<m_faceBuffer[i]<<" "<<i<<std::endl;
    }

}
//------------------------------------------------------------------------------
void ObjLoader::Load()
{
    //vertex
    m_pMesh->m_verSize = m_vertexBuffer.size();
    m_pMesh->m_vertex = new GLfloat[m_pMesh->m_verSize];
    for (uint32_t i=0; i< m_pMesh->m_verSize; ++i)
    {
        m_pMesh->m_vertex[i] = m_vertexBuffer[i];
    }
    /*/texture
    m_pMesh->m_uvSize = m_textureBuffer.size();
    m_pMesh->m_texture = new GLfloat[m_uvSize];
    for (uint32_t i=0; i< m_pMesh->m_uvSize; ++i)
    {
        m_pMesh->m_texture[i] = m_textureBuffer[i];
    }
    */
    //face
    m_pMesh->m_faceSize = m_faceBuffer.size();
    m_pMesh->m_face = new GLubyte[m_pMesh->m_faceSize];
    for (uint32_t i=0; i< m_pMesh->m_faceSize; ++i)
    {
        //in maya obj file, face start from 1 rather than 0!!!!!!!
        m_pMesh->m_face[i] = m_faceBuffer[i]-1;
    }
}
}//end of namespace
