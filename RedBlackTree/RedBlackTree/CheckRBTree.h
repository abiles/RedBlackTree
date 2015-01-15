
enum CheckRBTree
{
	CHECK_START = 0,
	RB_INPUT_ERROR,
	NODE_ROOT_COLOR_ERROR,
	BLACK_HEIGHT_ERROR,
	SUCCESSIVE_RED_COLOR_ERROR,
	BINARY_SEARCH_TREE_ERROR,
	RB_NO_ERROR,
	CHECK_END,
};


int  printTree(Tree* tree, Node* node);
bool isBinarySearchTree(Tree* tree, Node* node);
int	 isRBTree(Tree* tree, Node* node);
bool isSameBH(Tree* tree, Node* node);
int  getBH(Tree* tree, Node* node);

//��� ������ ������ �������� �������� ���Ǵ� �Լ�
//�������� ������ true�̴�
bool isSameRedSuccessive(Tree* tree, Node* node);

