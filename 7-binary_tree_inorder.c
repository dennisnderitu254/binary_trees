#include "binary_trees.h"

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * FUNCTIONALITY *
 * 1. If the tree is not empty and the function pointer is not NULL, then
 * 2. Traverse the left subtree by calling the same function.
 * 3. Call the function pointer with the value of the current node.
 * 4. Traverse the right subtree by calling the same function.
 *
 * Time Complexity: O(n)
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
