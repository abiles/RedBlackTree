#include "stdafx.h"

int printTree(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return -1;

	if (node == tree->m_Nil)
	{
	//	printf_s("NIL\n");
		return 0;
	}

	if (printTree(tree, node->m_LeftChild) == -1)
		return -1;

	printf_s("value : %d, color : %d, parent : %d \n",
			 node->m_Value, node->m_Color, node->m_Parent->m_Value);

	if (printTree(tree, node->m_RightChild) == -1)
		return -1;

	return 1;
}

bool isBinarySearchTree(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return false;
	
	if (node == tree->m_Nil)
		return true;

	if (node->m_LeftChild != tree->m_Nil)
	{
		if (node->m_Value < node->m_LeftChild->m_Value)
			return false;
	}

	if (node->m_RightChild != tree->m_Nil)
	{
		if (node->m_Value > node->m_RightChild->m_Value)
			return false;
	}

	if (!isBinarySearchTree(tree, node->m_LeftChild))
		return false;

	if (!isBinarySearchTree(tree, node->m_RightChild))
		return false;

	return true;
}

int isRBTree(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return RB_INPUT_ERROR;

	if (!isSameBH(tree, node))
	{
		printf_s("This tree has not same BH, It's Error\n");
		return BLACK_HEIGHT_ERROR;
	}
	else
	{
		printf_s("This tree has same BH\n");
	}

	if (isSameRedSuccessive(tree, node))
	{
		printf_s("This tree has same Successive Red, It's Error\n");
		return SUCCESSIVE_RED_COLOR_ERROR;
	}
	else
	{
		printf_s("This tree has not same Successive Red\n");
	}
	
	if (!isBinarySearchTree(tree, node))
	{
		printf_s("This tree is not BST, It's Error\n");
		return  BINARY_SEARCH_TREE_ERROR;
	}
	else
	{
		printf_s("This tree is BST\n");
	}

	return RB_NO_ERROR;
	
}

int getBH(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return -1;

	if (node == tree->m_Nil)
		return 1;

	int leftBH = getBH(tree, node->m_LeftChild);
	if (leftBH == -1)
		return -1;

	int rightBH = getBH(tree, node->m_RightChild);
	if (rightBH == -1)
		return -1;

	if (leftBH != rightBH)
		return -1;
	else
	{
		if (node->m_Color == BLACK)
			return leftBH + 1;
		else
			return leftBH;
	}
}

bool isSameBH(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return false;

	if (node->m_LeftChild == nullptr && node->m_RightChild == nullptr)
		return true;

	int leftBH = getBH(tree, node->m_LeftChild);
	if (leftBH == -1)
		return false;

	int rightBH = getBH(tree, node->m_RightChild);
	if (rightBH == -1)
		return false;

	if (leftBH == rightBH)
		return true;
	else
		return false;

}

bool isSameRedSuccessive(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return true;

	if (node == tree->m_Nil)
		return false;

	if (node->m_Color == RED)
	{
		if (node->m_LeftChild->m_Color == RED)
			return true;

		if (node->m_RightChild->m_Color == RED)
			return true;
	}

	if (isSameRedSuccessive(tree, node->m_LeftChild))
		return true;
	
	if (isSameRedSuccessive(tree, node->m_RightChild))
		return true;

	return false;
}





