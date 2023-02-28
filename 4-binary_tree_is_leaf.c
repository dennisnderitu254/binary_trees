#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 * Return: 1 if node is a leaf
 * Otherwise - returns 0
 *
 * FUNCTIONALITY
 *
 * 1. If the node is NULL or the node has a left or right child, return 0.
 *
 * 2. Otherwise, return 1.
 *
 * Time Complexity: O(1)
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
