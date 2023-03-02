#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the current node is greater than its children */
	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);
	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	/* Recursively check the left and right subtrees */
	if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
		return (0);

	return (1);
}
