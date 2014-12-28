#include "stdafx.h"

int insertion(Tree* tree, Node* insertNode)
{
	if (tree == nullptr || insertNode == nullptr)
		return INSERTION_INPUT_ERROR;

	//�ʱ�ȭ
	Node* parentNode = tree->m_Nil;
	Node* curNode = tree->m_Root;

	//���̳ʸ� ��ġ�� curNode�� ��ġ�� ã�ư���
	while (curNode != tree->m_Nil)
	{
		parentNode = curNode;
		if (insertNode->m_Value < parentNode->m_Value)
			curNode = parentNode->m_LeftChild;
		else
			curNode = parentNode->m_RightChild;
	}

	//insertNode�� �θ� �������ش�
	insertNode->m_Parent = parentNode;

	//�θ��� ���¸� ���� �����ڽ� �������ڽ� Ȥ�� ��Ʈ�� ������ �����Ѵ�
	if (parentNode == tree->m_Nil)
		tree->m_Root = insertNode;
	else if (insertNode->m_Value < parentNode->m_Value)
		parentNode->m_LeftChild = insertNode;
	else
		parentNode->m_RightChild = insertNode;

	//���������� ���ش�
	insertNode->m_IsRed = true;
	insertNode->m_LeftChild = tree->m_Nil;
	insertNode->m_RightChild = tree->m_Nil;

	insertionFixUp(tree, insertNode);
}

int insertionFixUp(Tree* tree, Node* fixUpNode)
{
	if (tree == nullptr || fixUpNode == nullptr)
		return INSERTION_INPUT_ERROR;

	while (fixUpNode->m_Parent->m_IsRed)
	{
		Node* grandParent = fixUpNode->m_Parent->m_Parent;
		if (grandParent->m_LeftChild == fixUpNode->m_Parent)
		{
			Node* uncleNode = fixUpNode->m_Parent->m_Parent->m_RightChild;

			if (uncleNode->m_IsRed)
			{
				//�θ� �����̰� uncle�� ������ ��� 
				//case 1�� �ش�
				//�θ� uncle�� �������� �ٲ�
				fixUpNode->m_Parent->m_IsRed = false;
				uncleNode->m_IsRed = false;
				grandParent->m_IsRed = true;
			}
			else
			{
				//uncle�� �������ϰ��
				//fixup node�� leftchild��� case 2
				//rightchilde��� case 3�� �ȴ�

				//case 3
				if (fixUpNode->m_Parent->m_RightChild == fixUpNode)
				{
					fixUpNode = fixUpNode->m_Parent;
					leftRotation(tree, fixUpNode);
				}

				//case2
				fixUpNode->m_Parent->m_IsRed = false;
				fixUpNode->m_Parent->m_Parent->m_IsRed = true;
				rightRotation(tree, fixUpNode->m_Parent->m_Parent);
			}
		}
		else
		{
			Node* uncleNode = fixUpNode->m_Parent->m_Parent->m_LeftChild;
			
			if (uncleNode->m_IsRed)
			{
				grandParent->m_IsRed = true;
				fixUpNode->m_Parent->m_IsRed = false;
				uncleNode->m_IsRed = false;
			}
			else
			{
				if (fixUpNode->m_Parent->m_LeftChild == fixUpNode)
				{
					fixUpNode = fixUpNode->m_Parent;
					rightRotation(tree, fixUpNode);
				}

				fixUpNode->m_Parent->m_IsRed = false;
				fixUpNode->m_Parent->m_Parent->m_IsRed = true;
				leftRotation(tree, fixUpNode->m_Parent->m_Parent);
			}
		}
	}

	tree->m_Root->m_IsRed = false;
}
