#include "objLoader.h"
#include "util.h"
#include <assert.h>

namespace QtGLWindow
{
//------------------------------------------------------------------------------
ObjLoader::ObjLoader()
{
    m_pMesh = new Mesh();
}
//------------------------------------------------------------------------------
ObjLoader::~ObjLoader()
{
    if( m_pMesh)
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
       //get each line into a buffer and get indices
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
                   ParseVertex( it_first );
                }
                else if (*it_first == "vn")
                {
                    ParseNormal( it_first );
                }
                else if( *it_first == "vt")
                {
                    ParseTexture( it_first );
                }
                else if( *it_first == "f")
                {
                    uint32_t numberOfVert = result.size()-1;
                    ParseFace( it_first,numberOfVert);
                }
            }
        }
    }
    else
    {
        std::cout<<".obj file not loaded"<<std::endl;
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
//------------------------------------------------------------------------------
void ObjLoader::ParseNormal(std::vector<std::string>::iterator _begin)
{
    ++_begin;
    for( uint32_t i=0; i<3; ++i)
    {
        m_normalBuffer.push_back(atof((*_begin).c_str()));
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
            std::string str(*_begin);
            Tokenize(str, r, "/");

            //assert( r.size() == 3 );
            if (r.size() == 3 )
            {
                m_face.push_back( atoi( r[0].c_str() ) );
                m_face.push_back( atoi( r[1].c_str() ) );
                m_face.push_back( atoi( r[2].c_str() ) );
                ++_begin;
            }
            else if(r.size() ==2)
            {
                m_face.push_back( atoi( r[0].c_str() ) );
                m_face.push_back( 0 );
                m_face.push_back( atoi( r[1].c_str() ) );
                ++_begin;
            }
            else
            {
                std::cout<<r.size()<<" element\n";
            }
#if 0
            else
            {
                log( "Bad number of face parts %d", r.size() );
            }
#endif
        }
    }
    else
    {
        std::cout<<"only supporting triangle now...........\n";
    }
    #if 0
    else if (_vertNum == 4)
    {
        for( uint32_t i=0; i<3; ++i)
        {
            std::vector<std::string> r;
            std::string str(*_begin);
            Tokenize(str, r, "/");
            m_face.push_back( atoi( r[0].c_str() ) );
            m_face.push_back( atoi( r[1].c_str() ) );
            m_face.push_back( atoi( r[2].c_str() ) );
            ++_begin;
        }
        //transfer quad to triangle
    }
    #endif
}
//------------------------------------------------------------------------------
void ObjLoader::Check()
{
    std::cout<<"from obj loader\n";
    std::cout<<m_vertexBuffer.size()<<" vertex111111111111111111\n";
    for(uint32_t i=0;i<m_vertexBuffer.size();++i)
    {
        if(i%3 ==2)
            std::cout<<m_vertexBuffer[i]<<" \n";
        else
            std::cout<<m_vertexBuffer[i]<<" ";
    }

    std::cout<<m_vertexBuffer.size()<<" texture111111111111111111\n";
    for(uint32_t i=0;i<m_textureBuffer.size();++i)
    {
        if(i%2 ==1)
            std::cout<<m_textureBuffer[i]<<" \n";
        else
            std::cout<<m_textureBuffer[i]<<" ";
    }

    std::cout<<m_normalBuffer.size()<<" normal!!!!!!!!!!!!\n";
    for(uint32_t i=0;i<m_normalBuffer.size();++i)
    {
        std::cout<<"vn ";
        if( i%3 ==2)
            std::cout<<m_normalBuffer[i]<<" \n";
        else
            std::cout<<m_normalBuffer[i]<<" ";
    }
    std::cout<<m_face.size()<<" face!!!!!!!!!!!!!!\n";
    for(uint32_t i=0;i<m_face.size();++i)
    {
        if(i%9==8)
            std::cout<<m_face[i]<<"\n";
        else if( i%3 ==2)
            std::cout<<m_face[i]<<" ";
        else
            std::cout<<m_face[i]<<"/";
    }

}
//------------------------------------------------------------------------------
void ObjLoader::Load()
{
    if(m_pMesh)
    {
        Check();
        //CalculatVertexNormal();
       // m_pMesh->CreateDataArray( m_vertexBuffer, m_normalInOrderBuffer, m_textureBuffer, m_face);
        m_pMesh->CreateDataArray( m_vertexBuffer, m_normalBuffer, m_textureBuffer, m_face);
        m_vertexBuffer.erase(m_vertexBuffer.begin(),m_vertexBuffer.end());
        m_normalBuffer.erase(m_normalBuffer.begin(),m_normalBuffer.end());
        //m_normalInOrderBuffer.erase(m_normalInOrderBuffer.begin(),m_normalInOrderBuffer.end());
        m_textureBuffer.erase(m_textureBuffer.begin(),m_textureBuffer.end());
        m_face.erase(m_face.begin(),m_face.end());
}
}
//------------------------------------------------------------------------------
void ObjLoader::CalculatVertexNormal()
{

    //average normals at a vertex
    m_normalInOrderBuffer.resize(m_vertexBuffer.size(),0);
    //for every 3 sets of data(a vertex) in face
    // add the normal value to the normal[(face[i]-1)]
    uint32_t faceSize = m_face.size();
    for ( uint32_t i=0; i< faceSize; i+=3 )
    {
        //
        uint32_t vertexID = (m_face[i]-1)*3;
        uint32_t normalID = (m_face[i+2]-1)*3;
        m_normalInOrderBuffer[vertexID] += m_normalBuffer[normalID];
        m_normalInOrderBuffer[vertexID+1] += m_normalBuffer[normalID+1];
        m_normalInOrderBuffer[vertexID+2] += m_normalBuffer[normalID+2];
    }
}
}//end of namespace
