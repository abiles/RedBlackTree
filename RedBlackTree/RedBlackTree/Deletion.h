
#pragma once

enum DeletionError
{
	DELETION_ERROR_START = 0,
	DELETION_INPUT_ERROR,
	DELETION_TRANS_SUCCESS,
	DELETION_SUCCESS,
	DELETION_ERROR_END,
};

int transPlant(Tree* tree, Node* oldNode, Node* plantNode);
int deletion(Tree* tree, Node* deleteNode);
int deleteFixUp(Tree* tree, Node* fixUpNode);