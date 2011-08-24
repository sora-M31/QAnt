#ifndef _MESH_H_
#define _MESH_H_
#include <OpenGL/gl.h>
#include <stdint.h>
#include <vector>

namespace QtGLWindow
{
// --------------------------------------------------------------------------
/// \brief class mesh use vbo to draw mesh.
class Mesh
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        Mesh();
        // --------------------------------------------------------------------------
        /// \brief Destructor delete arrays allocated
        ~Mesh();
        // --------------------------------------------------------------------------
        /// \brief Initialize the array using the value of paseed in vertex, texture, face
        /// \param _vertex
        /// \param _texture
        /// \param _face
        void CreateDataArray(const std::vector<GLfloat>& _vertex, const std::vector<GLfloat>& _texture, const std::vector<GLuint>& _face);
        // --------------------------------------------------------------------------
        /// \brief Bind a buffer the size of vertex array with vbo
        void CreateVBO();
        // --------------------------------------------------------------------------
        /// \brief Update the vbo butter
        void UpdateVBO();
        // --------------------------------------------------------------------------
        /// \brief Draw vbo using indices
        void DrawVBO();
        // --------------------------------------------------------------------------
        /// \brief vertex array
        GLfloat* m_vertex;
        // --------------------------------------------------------------------------
        /// \brief uv array
        GLfloat* m_texture;
        // --------------------------------------------------------------------------
        /// \brief indice array
        GLuint* m_face;
        // --------------------------------------------------------------------------
        /// \brief vbo pointer
        GLuint m_vboPointer;
        // --------------------------------------------------------------------------
        /// \brief Geometry primitive type
        GLuint m_mode;
        // --------------------------------------------------------------------------
        /// \brief size of vertex array
        uint32_t m_verSize;
        // --------------------------------------------------------------------------
        /// \brief size of uv array
        uint32_t m_uvSize;
        // --------------------------------------------------------------------------
        /// \brief size of indice array
        uint32_t m_faceSize;
};//end of class
}//end of namespace
#endif //end of define
