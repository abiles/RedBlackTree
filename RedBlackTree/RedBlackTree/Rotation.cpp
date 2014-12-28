#include "stdafx.h"

int leftRotation(Tree* tree, Node* pivotNode)
{
	if (tree == nullptr || pivotNode == nullptr)
		return ROTATION_INPUT_ERROR;
	
	//leftRotation�̱� ������ ���� ����� ������ �ڽ��� Y�� �����Ѵ�
	Node* nodeY = pivotNode->m_RightChild;

	//���� ����� rightchild�� �ٲ�
	pivotNode->m_RightChild = nodeY->m_LeftChild;
	if (nodeY->m_LeftChild != tree->m_Nil)
		nodeY->m_LeftChild->m_Parent = pivotNode;

	//nodeY �θ� ����
	nodeY->m_Parent = pivotNode->m_Parent;
	//���� ��尡 Ʈ���� ��Ʈ������ Ȯ�� 
	if (pivotNode->m_Parent == tree->m_Nil)
		tree->m_Root = nodeY;
	//���� ����� �θ� ���� �θ𿡼� �ٶ� nodeY���� ���� ����
	else if (pivotNode->m_Parent->m_RightChild == pivotNode)
		pivotNode->m_Parent->m_RightChild = nodeY;
	else
		pivotNode->m_Parent->m_LeftChild = nodeY;

	//x�� y�� ���� �缳��
	pivotNode->m_Parent = nodeY;
	nodeY->m_LeftChild = pivotNode;

	return ROTATION_SUCCESS;
}

