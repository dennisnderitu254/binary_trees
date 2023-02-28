#include "binary_trees.h"

/**
 * binary_tree_preorder - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is not empty and the function pointer is not NULL, then:
 * 2. Call the function pointer with the value of the current node.
 * 3. Call the function recursively on the left child.
 * 4. Call the function recursively on the right child.
 *
 * Time Complexity: O(n)
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);

		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
