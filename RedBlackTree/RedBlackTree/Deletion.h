
#pragma once

enum DeletionError
{
	DELETION_ERROR_START = 0,
	DELETION_ERROR,
	DELETION_INPUT_ERROR,
	DELETION_MINIMUM_SEARCH_ERROR,
	DELETION_FIXUP_ERROR,
	DELETION_TRANS_SUCCESS,
	DELETION_FIXUP_SUCCESS,
	DELETION_SUCCESS,
	DELETION_ERROR_END,
};

int   transPlant(Tree* tree, Node* oldNode, Node* plantNode);
int   deletion(Tree* tree, Node* deleteNode);
int   deleteFixUp(Tree* tree, Node* fixUpNode);
Node* treeMinimum(Tree* tree, Node* inputNode);