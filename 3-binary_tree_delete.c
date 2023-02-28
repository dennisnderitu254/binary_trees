#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 *
 * FUNCTIONALITY
 *
 * 1. If the tree is not empty, then we recursively
 * call the function on the left and right subtrees.
 *
 *  2. Then we free the memory allocated to the tree.
 *
 * Time Complexity: O(n)
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
