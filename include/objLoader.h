#ifndef _OBJ_H_
#define _OBJ_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>

#include "mesh.h"
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
        /// \brief Get vertices from the tokens
        /// \param _begin iterator pointing to the beginning of the line to be parsed
        void ParseVertex(std::vector<std::string>::iterator _begin);
        // --------------------------------------------------------------------------
        /// \brief Get uv coordinate from the tokens
        /// \param _begin iterator pointing to the beginning of the line to be parsed
        void ParseTexture(std::vector<std::string>::iterator _begin);
        // --------------------------------------------------------------------------
        /// \brief Get indice for a face from tokens
        /// \param _begin iterator pointing to the beginning of the line to be parsed
        /// \param _vertNum number of vertice in a face
        void ParseFace(std::vector<std::string>::iterator _begin,uint32_t _vertNum);
        // --------------------------------------------------------------------------
        /// \brief Print out vertex and face value
        void Check();
        // --------------------------------------------------------------------------
        /// \brief Load the parsed information in to array of vertex, uv and indices
        void Load();
    protected:
        ///array of vertices from file
        std::vector<GLfloat> m_vertexBuffer;
        ///array of uv coords from file
        std::vector<GLfloat> m_textureBuffer;
        ///array of faces from file
        std::vector<GLuint> m_faceBuffer;
    public:
        // --------------------------------------------------------------------------
        /// \brief Pointer to mesh
        Mesh* m_pMesh;
};//end of class
}//end of namespace
#endif //end of define
