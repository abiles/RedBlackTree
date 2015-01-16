
#include "stdafx.h"

#define TREE_MAX_NUM 50

bool initTree(Tree* tree)
{
	if (tree == nullptr)
		return false;

	Node* nil = new Node();
	nil->m_Color = BLACK;

	tree->m_Nil = nil;
	tree->m_Root = nil;

	return true;
}

bool initNode(Tree* tree, Node* node)
{
	if (tree == nullptr || node == nullptr)
		return false;

	node->m_Value = rand() % TREE_MAX_NUM + 1;
	//node->m_LeftChild = tree->m_Nil;
	//node->m_RightChild = tree->m_Nil;

	return true;
}

int showMenu()
{
	system("cls");

	int caseNum = -1;
	printf_s("Show Case\n");
	printf_s("\n");
	printf_s("choise 1 : no Insertion\n");
	printf_s("choise 2 : 1 Insertion\n");
	printf_s("choise 3 : 7 Insertion\n");
	printf_s("choise 4 : 10 Insertion 3 Deletion\n");

	printf_s("exit = 0\n");
	printf_s("\n");
	printf_s("choice case : ");
	scanf_s("%d", &caseNum);

	printf_s("\n");
	return caseNum;
}

void caseChoice()
{
	srand(unsigned int(time(NULL)));

	int choisedCase = -1;

	do
	{
		choisedCase = showMenu();

		switch (choisedCase)
		{
		case 0:
			printf_s("Good Bye~!\n");
			getchar();
			getchar();
			break;
		case 1:
			nodeZeroCaseTree();
			break;
		case 2:
			onlyOneInsertionCaseTree();
			break;
		case 3:
			sevenInsertionCaseTree();
			break;
		case 4:
			tenInsertionThreeDeletionCaseTree();
			break;
		default:
			printf_s("It's not correct CaseNum, Please input again\n");
			getchar();
			getchar();
			break;
		}
		system("cls");

	} while (choisedCase != 0);


	
}

void nodeZeroCaseTree()
{
	printf_s("~~~ nodeZeroCase ~~~\n");

	Tree tree;
	initTree(&tree);

	printTree(&tree, tree.m_Root);

	isRBTree(&tree, tree.m_Root);

	printf_s("press Enter to next step\n");

	getchar();
	getchar();
}

void onlyOneInsertionCaseTree()
{
	printf_s("~~~ only 1 Insertion Case ~~~\n");

	Tree tree;
	initTree(&tree);

	Node node;
	initNode(&tree, &node);

	insertion(&tree, &node);
	
	printTree(&tree, tree.m_Root);
	
	isRBTree(&tree, tree.m_Root);

	printf_s("press Enter to next step\n");

	getchar();
	getchar();

}

void sevenInsertionCaseTree()
{
	printf_s("~~~ 7 Insertion Case ~~~\n");

	Tree tree;
	initTree(&tree);
	Node nodes[5];
	int countNum = 0;
	while (countNum < 5)
	{
		initNode(&tree, &nodes[countNum]);
		insertion(&tree, &nodes[countNum]);
		++countNum;
	}
	printTree(&tree, tree.m_Root);

	isRBTree(&tree, tree.m_Root);

	printf_s("press Enter to next step\n");

	getchar();
	getchar();
}

void tenInsertionThreeDeletionCaseTree()
{
	printf_s("~~~ 10 Insertion 3 Deletion Case ~~~\n");

	Tree tree;
	initTree(&tree);

	Node nodes[10];

	int insertCountNum = 0;
	int deleteCountNum = 0;
	while (insertCountNum < 10)
	{
		initNode(&tree, &nodes[insertCountNum]);
		insertion(&tree, &nodes[insertCountNum]);
		++insertCountNum;
	}

	printf_s("\n");
	printf_s("before delete\n");
	printf_s("\n");
	printTree(&tree, tree.m_Root);

	while (deleteCountNum < 3)
	{
		deletion(&tree, &nodes[deleteCountNum]);
		++deleteCountNum;
	}

	printf_s("\n");
	printf_s("after delete\n");
	printf_s("\n");
	printTree(&tree, tree.m_Root);

	isRBTree(&tree, tree.m_Root);

	printf_s("press Enter to next step\n");

	getchar();
	getchar();
}






