//RedBlackTree�� �� ������ ������ ���� ����ü

#pragma once

struct Node
{
	Node* m_LeftChild = nullptr;
	Node* m_RightChild = nullptr;

	//node�� ������ red or black�̱� ������ red������ Ȯ���ؼ� �ƴ϶�� ������ ����
	bool  m_IsRed = true;
	int   m_Value = 0;
};