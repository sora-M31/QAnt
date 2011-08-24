#ifndef _SCENENODE_H_
#define _SCENENODE_H_
namespace QtGLWindow
{
class SceneObject;
class SceneNode
{
    public:
        // --------------------------------------------------------------------------
        /// \brief Constructor
        /// \param _pObject Pointer to Object this node is paired
        SceneNode(SceneObject* _pObject);
        // --------------------------------------------------------------------------
        /// \brief Destructor
        ~SceneNode();
        // --------------------------------------------------------------------------
        /// \brief Copy constructor
        /// \param _param Scene node to copy from
        SceneNode(const SceneNode& _param);
        // --------------------------------------------------------------------------
        /// \brief Add node to this 
        /// \param _node Node to be added
        void AddNext(SceneNode& _node);
        // --------------------------------------------------------------------------
        /// \brief Operator = overload
        /// \param SceneNode Scene node to be assigned
        /// \return This node
        const SceneNode& operator=(const SceneNode&);
        /// pointer point to the next Node
        SceneNode* m_pNext;
        /// pointer pointing to the object attached with this node
        SceneObject* m_pObject;
    private:   
        // --------------------------------------------------------------------------
        /// \brief Default constructor
        SceneNode();
};//end of class
}//end of namespace
#endif //end of define
