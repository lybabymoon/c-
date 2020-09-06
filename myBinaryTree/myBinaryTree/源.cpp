#include <iostream>
#include "binaryTree.h"

int main()
{
	Tree tr;
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(3);
	root->right = new TreeNode(6);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(4);
	root->right->right = new TreeNode(8);

	tr.increasingBST(root);
	return 0;
}