#include "stdafx.h"

int leftRotation(Tree* tree, Node* pivotNode)
{
	if (tree == nullptr || pivotNode == nullptr)
		return ROTATION_INPUT_ERROR;
	
	//leftRotation이기 때문에 기준 노드의 오른쪽 자식을 Y로 선언한다
	Node* nodeY = pivotNode->m_RightChild;

	//기준 노드의 rightchild를 바꿈
	pivotNode->m_RightChild = nodeY->m_LeftChild;
	if (nodeY->m_LeftChild != tree->m_Nil)
		nodeY->m_LeftChild->m_Parent = pivotNode;

	//nodeY 부모 설정
	nodeY->m_Parent = pivotNode->m_Parent;
	//기준 노드가 트리의 루트였는지 확인 
	if (pivotNode->m_Parent == tree->m_Nil)
		tree->m_Root = nodeY;
	//기준 노드의 부모를 보고 부모에서 바라본 nodeY와의 관계 설정
	else if (pivotNode->m_Parent->m_RightChild == pivotNode)
		pivotNode->m_Parent->m_RightChild = nodeY;
	else
		pivotNode->m_Parent->m_LeftChild = nodeY;

	//x와 y의 관계 재설정
	pivotNode->m_Parent = nodeY;
	nodeY->m_LeftChild = pivotNode;

	return ROTATION_SUCCESS;
}

