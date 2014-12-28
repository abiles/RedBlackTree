//RedBlackTree의 각 노드들을 정의해 놓은 구조체

#pragma once

struct Node
{
	Node* m_Parent = nullptr;
	Node* m_LeftChild = nullptr;
	Node* m_RightChild = nullptr;

	//node의 색깔은 red or black이기 때문에 red인지만 확인해서 아니라면 블랙으로 간주
	bool  m_IsRed = true;
	int   m_Value = 0;
};

struct Tree
{
	Node* m_Nil = nullptr;
	Node* m_Root = nullptr;
};



