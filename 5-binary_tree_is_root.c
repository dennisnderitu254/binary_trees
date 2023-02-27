#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is a root,
 * Otherwise - returns 0
 *
 * FUNCTIONALITY
 *
 * 1. If the node is NULL or the node’s parent is not NULL, return 0.
 * 2. Otherwise, return 1.
 *
 * Time Complexity: O(1)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
