#include "stdafx.h"

int insertion(Tree* tree, Node* insertNode)
{
	if (tree == nullptr || insertNode == nullptr)
		return INSERTION_INPUT_ERROR;

	//초기화
	Node* parentNode = tree->m_Nil;
	Node* curNode = tree->m_Root;

	//바이너리 서치로 curNode의 위치를 찾아간다
	while (curNode != tree->m_Nil)
	{
		parentNode = curNode;
		if (insertNode->m_Value < parentNode->m_Value)
			curNode = parentNode->m_LeftChild;
		else
			curNode = parentNode->m_RightChild;
	}

	//insertNode의 부모를 설정해준다
	insertNode->m_Parent = parentNode;

	//부모의 형태를 보고 왼쪽자식 오른쪽자식 혹은 루트가 될지를 결정한다
	if (parentNode == tree->m_Nil)
		tree->m_Root = insertNode;
	else if (insertNode->m_Value < parentNode->m_Value)
		parentNode->m_LeftChild = insertNode;
	else
		parentNode->m_RightChild = insertNode;

	//빨강색으로 해준다
	insertNode->m_Color = RED;
	insertNode->m_LeftChild = tree->m_Nil;
	insertNode->m_RightChild = tree->m_Nil;

	insertionFixUp(tree, insertNode);
}

int insertionFixUp(Tree* tree, Node* fixUpNode)
{
	if (tree == nullptr || fixUpNode == nullptr)
		return INSERTION_INPUT_ERROR;

	while (fixUpNode->m_Parent->m_Color == RED)
	{
		Node* grandParent = fixUpNode->m_Parent->m_Parent;
		if (grandParent->m_LeftChild == fixUpNode->m_Parent)
		{
			Node* uncleNode = fixUpNode->m_Parent->m_Parent->m_RightChild;

			if (uncleNode->m_Color == RED)
			{
				//부모가 빨강이고 uncle도 빨강인 경우 
				//case 1에 해당
				//부모 uncle을 블랙으로 바꿈
				fixUpNode->m_Parent->m_Color = BLACK;
				uncleNode->m_Color = BLACK;
				grandParent->m_Color = RED;
			}
			else
			{
				//uncle이 검은색일경우
				//fixup node가 leftchild라면 case 2
				//rightchilde라면 case 3이 된다

				//case 3
				if (fixUpNode->m_Parent->m_RightChild == fixUpNode)
				{
					fixUpNode = fixUpNode->m_Parent;
					leftRotation(tree, fixUpNode);
				}

				//case2
				fixUpNode->m_Parent->m_Color = BLACK;
				fixUpNode->m_Parent->m_Parent->m_Color = RED;
				rightRotation(tree, fixUpNode->m_Parent->m_Parent);
			}
		}
		else
		{
			Node* uncleNode = fixUpNode->m_Parent->m_Parent->m_LeftChild;
			
			if (uncleNode->m_Color == RED)
			{
				grandParent->m_Color = RED;
				fixUpNode->m_Parent->m_Color = BLACK;
				uncleNode->m_Color = BLACK;
			}
			else
			{
				if (fixUpNode->m_Parent->m_LeftChild == fixUpNode)
				{
					fixUpNode = fixUpNode->m_Parent;
					rightRotation(tree, fixUpNode);
				}

				fixUpNode->m_Parent->m_Color = BLACK;
				fixUpNode->m_Parent->m_Parent->m_Color = RED;
				leftRotation(tree, fixUpNode->m_Parent->m_Parent);
			}
		}
	}

	tree->m_Root->m_Color = BLACK;
}

