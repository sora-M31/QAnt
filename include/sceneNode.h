#ifndef _SCENENODE_H_
#define _SCENENODE_H_
namespace QtGLWindow
{
class SceneObject;
class SceneNode
{
    public:
        SceneNode(SceneObject* _pObject);
        ~SceneNode();
        SceneNode(const SceneNode& _param);
        void AddNext(SceneNode& _node);
        const SceneNode& operator=(const SceneNode&);
        /// pointer point to the childnode
        SceneNode* m_pNext;
        /// pointer pointing to the object attached with this node
        SceneObject* m_pObject;
    private:
        SceneNode();
};//end of class
}//end of namespace
#endif //end of define
