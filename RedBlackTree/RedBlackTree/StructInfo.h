//RedBlackTree의 각 노드들을 정의해 놓은 구조체

#pragma once

enum Color
{
	BLACK = 0,
	RED,
};

struct Node
{
	Node* m_Parent = nullptr;
	Node* m_LeftChild = nullptr;
	Node* m_RightChild = nullptr;

	bool  m_Color = RED;
	int   m_Value = 0;
};

struct Tree
{
	Node* m_Nil = nullptr;
	Node* m_Root = nullptr;
};




