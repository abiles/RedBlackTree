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

Node* treeMinimum(Tree* tree, Node* inputNode)
{
	if (tree == nullptr || inputNode == nullptr)
		return nullptr;

	Node* curNode = inputNode;

	while (curNode->m_LeftChild != tree->m_Nil)
	{
		curNode = curNode->m_LeftChild;
	}

	return curNode;
}

int deleteFixUp(Tree* tree, Node* fixUpNode)
{
	if (tree == nullptr || fixUpNode == nullptr)
		return DELETION_INPUT_ERROR;

	while (fixUpNode != tree->m_Root && fixUpNode->m_Color == BLACK)
	{
		if (fixUpNode == fixUpNode->m_Parent->m_LeftChild)
		{
			Node* siblingNode = fixUpNode->m_Parent->m_RightChild;
			if (siblingNode->m_Color == RED)
			{
				//case 5
				siblingNode->m_Color == BLACK;
				fixUpNode->m_Parent->m_Color = RED;
				if (leftRotation(tree, fixUpNode->m_Parent) != ROTATION_SUCCESS)
					return DELETION_FIXUP_ERROR;
				//로테이션후 사촌노드 바꾸기 
				siblingNode = fixUpNode->m_Parent->m_RightChild;
			}

			if (siblingNode->m_LeftChild->m_Color == BLACK &&
				siblingNode->m_RightChild->m_Color == BLACK)
			{
				//case 1
				//sibling의 자식 모두 BLACK
				siblingNode->m_Color == RED;
				fixUpNode = fixUpNode->m_Parent;
			}
			else
			{
				//sibling의 자식 둘중 적어도 하나가 RED인 상태
				if (siblingNode->m_RightChild->m_Color == BLACK)
				{
					//case3
					//오른쪽 자식이 BLACK
					siblingNode->m_LeftChild->m_Color = RED;
					if (rightRotation(tree, siblingNode) != ROTATION_SUCCESS)
						return DELETION_FIXUP_ERROR;
					siblingNode = fixUpNode->m_Parent->m_RightChild;
				}

				//case 2
				siblingNode->m_Color = fixUpNode->m_Parent->m_Color;
				fixUpNode->m_Parent->m_Color = BLACK;
				siblingNode->m_RightChild->m_Color = BLACK;
				if (leftRotation(tree, fixUpNode->m_Parent) != ROTATION_SUCCESS)
					return DELETION_FIXUP_ERROR;

				fixUpNode = tree->m_Root;
			}
		}
		else
		{
			Node* siblingNode = fixUpNode->m_Parent->m_LeftChild;
			if (siblingNode->m_Color == RED)
			{
				siblingNode->m_Color = BLACK;
				fixUpNode->m_Parent->m_Color = RED;
				if (rightRotation(tree, fixUpNode->m_Parent) != ROTATION_SUCCESS)
					return DELETION_FIXUP_ERROR;
				siblingNode = fixUpNode->m_Parent->m_LeftChild;
			}
			
			if (siblingNode->m_RightChild->m_Color == BLACK
				&& siblingNode->m_LeftChild->m_Color == BLACK)
			{
				siblingNode->m_Color = RED;
				fixUpNode = fixUpNode->m_Parent;
			}
			else
			{
				if (siblingNode->m_LeftChild->m_Color == BLACK)
				{
					siblingNode->m_RightChild->m_Color = BLACK;
					siblingNode->m_Color = RED;
					if (leftRotation(tree, siblingNode) != ROTATION_SUCCESS)
						return DELETION_FIXUP_ERROR;
					siblingNode = fixUpNode->m_Parent->m_LeftChild;
				}
				siblingNode->m_Color = fixUpNode->m_Parent->m_Color;
				fixUpNode->m_Parent->m_Color = BLACK;
				siblingNode->m_LeftChild->m_Color = BLACK;
				if (rightRotation(tree, fixUpNode->m_Parent) != ROTATION_SUCCESS)
					return DELETION_FIXUP_ERROR;
				fixUpNode = tree->m_Root;
			}
		}
	}

	fixUpNode->m_Color = BLACK;

	return DELETION_FIXUP_SUCCESS;
}


int deletion(Tree* tree, Node* deleteNode)
{
	if (tree == nullptr || deleteNode == nullptr)
		return DELETION_INPUT_ERROR;

	bool erasedColor = deleteNode->m_Color;
	Node* fixUpNode = nullptr;

	if (deleteNode->m_LeftChild = tree->m_Nil)
	{
		fixUpNode = deleteNode->m_RightChild;
		if (transPlant(tree, deleteNode, deleteNode->m_RightChild) != DELETION_TRANS_SUCCESS)
			return DELETION_ERROR;
	}
	else if (deleteNode->m_RightChild == tree->m_Nil)
	{
		fixUpNode = deleteNode->m_LeftChild;
		if (transPlant(tree, deleteNode, deleteNode->m_LeftChild) != DELETION_TRANS_SUCCESS)
			return DELETION_ERROR;
	}
	else
	{
		Node* successor = treeMinimum(tree, deleteNode->m_RightChild);
		
		if (successor == nullptr)
			return DELETION_MINIMUM_SEARCH_ERROR;

		erasedColor = successor->m_Color;
		fixUpNode = successor->m_RightChild;
		if (successor->m_Parent == deleteNode)
			fixUpNode->m_Parent = successor;
		else
		{
			if (transPlant(tree, successor, successor->m_RightChild) != DELETION_TRANS_SUCCESS)
				return DELETION_ERROR;
			successor->m_RightChild = deleteNode->m_RightChild;
			successor->m_RightChild->m_Parent = successor;
		}
		
		if (transPlant(tree, deleteNode, successor) != DELETION_TRANS_SUCCESS)
			return DELETION_ERROR;
		successor->m_LeftChild = deleteNode->m_LeftChild;
		successor->m_LeftChild->m_Parent = successor;
		successor->m_Color = deleteNode->m_Color;
	}

	if (erasedColor == BLACK)
	{
		if (deleteFixUp(tree, fixUpNode) != DELETION_FIXUP_SUCCESS)
			return DELETION_FIXUP_ERROR;
	}

	return DELETION_SUCCESS;
}



