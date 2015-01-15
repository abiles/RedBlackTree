//Rotation 함수 부분만 정리해놓은 헤더

#pragma once

enum rotationError
{
	ROTATION_ERROR_START = 0,
	ROTATION_INPUT_ERROR,
	ROTATION_ERROR,
	ROTATION_SUCCESS,
	ROTATION_ERROR_END,
};

int leftRotation(Tree* tree, Node* pivotNode);
int rightRotation(Tree* tree, Node* pivotNode);