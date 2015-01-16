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
	nodeY->m_LeftChild = pivotNode;
	pivotNode->m_Parent = nodeY;

	return ROTATION_SUCCESS;
}

int rightRotation(Tree* tree, Node* pivotNode)
{
	if (tree == nullptr || pivotNode == nullptr)
		return ROTATION_INPUT_ERROR;

	Node* nodeX = pivotNode->m_LeftChild;

	pivotNode->m_LeftChild = nodeX->m_RightChild;
	if (nodeX->m_RightChild != tree->m_Nil)
		nodeX->m_RightChild->m_Parent = pivotNode;

	nodeX->m_Parent = pivotNode->m_Parent;

	if (nodeX->m_Parent == tree->m_Nil)
		tree->m_Root = nodeX;
	else if (nodeX->m_Parent->m_LeftChild == nodeX)
		nodeX->m_Parent->m_LeftChild = nodeX;
	else
		nodeX->m_Parent->m_RightChild = nodeX;

	nodeX->m_RightChild = pivotNode;
	pivotNode->m_Parent = nodeX;

	return ROTATION_SUCCESS;

}

