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
		if (insertNode->m_Value < curNode->m_Value)
			curNode = curNode->m_LeftChild;
		else
			curNode = curNode->m_RightChild;
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

	insertNode->m_LeftChild = tree->m_Nil;
	insertNode->m_RightChild = tree->m_Nil;
	//빨강색으로 해준다
	insertNode->m_Color = RED;

	if (insertionFixUp(tree, insertNode) != INSERTION_FIXUP_SUCCESS)
		return INSERTION_ERROR;

	return INSERTION_SUCCESS;
}

int insertionFixUp(Tree* tree, Node* fixUpNode)
{
	if (tree == nullptr || fixUpNode == nullptr)
		return INSERTION_INPUT_ERROR;

	while (fixUpNode->m_Parent->m_Color == RED)
	{
		if (fixUpNode->m_Parent == fixUpNode->m_Parent->m_Parent->m_LeftChild)
		{
			Node* uncleNode = fixUpNode->m_Parent->m_Parent->m_RightChild;

			if (uncleNode->m_Color == RED)
			{
				//부모가 빨강이고 uncle도 빨강인 경우 
				//case 1에 해당
				//부모 uncle을 블랙으로 바꿈
				fixUpNode->m_Parent->m_Color = BLACK;
				uncleNode->m_Color = BLACK;
				fixUpNode->m_Parent->m_Parent->m_Color = RED;
				fixUpNode = fixUpNode->m_Parent->m_Parent;
			}
			else
			{
				//uncle이 검은색일경우
				//fixup node가 leftchild라면 case 2
				//rightchilde라면 case 3이 된다

				//case 3
				if (fixUpNode == fixUpNode->m_Parent->m_RightChild)
				{
					fixUpNode = fixUpNode->m_Parent;
					if (leftRotation(tree, fixUpNode) != ROTATION_SUCCESS)
						return INSERTION_FIX_UP_ERROR;
				}

				//case2
				fixUpNode->m_Parent->m_Color = BLACK;
				fixUpNode->m_Parent->m_Parent->m_Color = RED;
				if (rightRotation(tree, fixUpNode->m_Parent->m_Parent) != ROTATION_SUCCESS)
					return INSERTION_FIX_UP_ERROR;
			}
		}
		else
		{
			Node* uncleNode = fixUpNode->m_Parent->m_Parent->m_LeftChild;
			
			if (uncleNode->m_Color == RED)
			{
				fixUpNode->m_Parent->m_Color = BLACK;
				uncleNode->m_Color = BLACK;
				fixUpNode->m_Parent->m_Parent->m_Color = RED;
				fixUpNode = fixUpNode->m_Parent->m_Parent;
			}
			else
			{
				if (fixUpNode == fixUpNode->m_Parent->m_LeftChild)
				{
					fixUpNode = fixUpNode->m_Parent;
					if (rightRotation(tree, fixUpNode) != ROTATION_SUCCESS)
						return INSERTION_FIX_UP_ERROR;
				}

				fixUpNode->m_Parent->m_Color = BLACK;
				fixUpNode->m_Parent->m_Parent->m_Color = RED;
				if (leftRotation(tree, fixUpNode->m_Parent->m_Parent) != ROTATION_SUCCESS)
					return INSERTION_FIX_UP_ERROR;
			}
		}
	}

	tree->m_Root->m_Color = BLACK;

	return INSERTION_FIXUP_SUCCESS;
}

