//Ʈ���� node�� �߰��ϴ� insertion 

#pragma once

enum InsertionError
{
	INSERTION_ERROR_START = 0,
	INSERTION_INPUT_ERROR,
	INSERTION_SUCCESS,
	INSERTION_ERROR_END,
};

int insertion(Tree* tree, Node* insertNode);
int insertionFixUp(Tree* tree, Node* fixUpNode);