#include "stdafx.h"

int transPlant(Tree* tree, Node* oldNode, Node* plantNode)
{
	if (tree == nullptr || oldNode == nullptr || plantNode == nullptr)
		return DELETION_INPUT_ERROR;

	if (oldNode->m_Parent == tree->m_Nil)
		tree->m_Root = plantNode;
	else if (oldNode = plantNode->m_Parent->m_LeftChild)
		oldNode->m_Parent->m_LeftChild = plantNode;
	else
		oldNode->m_Parent->m_RightChild = plantNode;

	plantNode->m_Parent = oldNode->m_Parent;

	return DELETION_TRANS_SUCCESS;
}

int deletion(Tree* tree, Node* deleteNode)
{

}
