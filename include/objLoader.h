#ifndef _OBJ_H_
#define _OBJ_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <assert.h>

#include "mesh.h"
#include "texture.h"
#include "util.h"

namespace QtGLWindow
{
class ObjLoader
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        ObjLoader();
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~ObjLoader();
        // --------------------------------------------------------------------------
        /// \brief Parse the file passed in to get vertex,uv and face information
        /// \param Filename name of the file to load obj from
        void ParseFile(std::string Filename);
        // --------------------------------------------------------------------------
       /// \brief Print out vertex and face value
        void Check();
        // --------------------------------------------------------------------------
        /// \brief Load the parsed information in to array of vertex, uv and indices
        void Load();
        Mesh* m_pMesh;
        Texture* m_pTexture;
    protected:
        // --------------------------------------------------------------------------
        /// \brief Get vertices from the tokens
        /// \param _begin iterator pointing to the beginning of the line to be parsed
        void ParseVertex(std::vector<std::string>::iterator _begin);
        void ParseNormal(std::vector<std::string>::iterator _begin);
        // --------------------------------------------------------------------------
        /// \brief Get uv coordinate from the tokens
        /// \param _begin iterator pointing to the beginning of the line to be parsed
        void ParseTexture(std::vector<std::string>::iterator _begin);
        // --------------------------------------------------------------------------
        /// \brief Get indice for a face from tokens
        /// \param _begin iterator pointing to the beginning of the line to be parsed
        /// \param _vertNum number of vertice in a face
        void ParseFace(std::vector<std::string>::iterator _begin,uint32_t _vertNum);
        void CalculatVertexNormal();
        ///array of vertices from file
        std::vector<GLfloat> m_vertexBuffer;
        std::vector<GLfloat> m_normalBuffer;
        std::vector<GLfloat> m_normalInOrderBuffer;
        ///array of uv coords from file
        std::vector<GLfloat> m_textureBuffer;
        ///array of faces from file
        std::vector<GLuint> m_face;
};//end of class
}//end of namespace
#endif //end of define
