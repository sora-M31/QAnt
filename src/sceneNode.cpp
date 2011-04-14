#include "sceneNode.h"
namespace QtGLWindow{
//------------------------------------------------------------------------------
SceneNode::SceneNode()
{
}
//------------------------------------------------------------------------------    
SceneNode::SceneNode(SceneObject* _pObject)
    : m_pNext(0),
      m_pObject(_pObject)
{
}
//------------------------------------------------------------------------------
SceneNode::SceneNode(const SceneNode& _param)
{
    this->m_pObject = _param.m_pObject;
    this->m_pNext = _param.m_pNext;
}
//------------------------------------------------------------------------------
SceneNode::~SceneNode()
{
    //delete
}
//------------------------------------------------------------------------------
void SceneNode::AddNext(SceneNode& _node)
{
    this->m_pNext = & _node;
}
//------------------------------------------------------------------------------
const SceneNode& SceneNode::operator=(const SceneNode&)
{
    return *this;
}
}//end of namespace
