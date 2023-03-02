#include "binary_trees.h"
#include <stddef.h>

#include <stddef.h>

int is_complete(const binary_tree_t *tree);
int is_max_heap(const binary_tree_t *tree, int max);

/**
 * FUNCTIONALITY *
 *
 * The binary_tree_is_heap function first checks if the tree is complete
 * using the is_complete function.
 * A complete tree is a binary tree in which all levels are completely
 * filled except possibly the lowest, which is filled from the left.
 *
 * If the tree is complete, the function then checks if it is a
 * valid Max Binary Heap using the is_max_heap function.
 * This function recursively checks that each node's value is less than
 * or equal to its parent's value, and that the left and right
 * subtrees are also valid Max Binary Heaps.
 *
 * If the tree is a valid Max Binary Heap, the function returns 1.
 * Otherwise, it returns 0.
 *
 * Note that this implementation assumes that the values in the
 * binary tree are non-negative.
 * If the values can be negative,
 * the max parameter in the is_max_heap function
 * should be changed to the minimum possible value.
 *
 */

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 *
 * Time Complexity: O(n)
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	if (!is_complete(tree))
		return 0;

	return is_max_heap(tree, tree->n);
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 *
 * Time Complexity: O(n)
 */

int is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 1;

	if (tree->left == NULL && tree->right == NULL)
		return 1;

	if (tree->left != NULL && tree->right != NULL)
		return is_complete(tree->left) && is_complete(tree->right);

	return 0;
}

/**
 * is_max_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: A pointer to the root node of the tree to check
 * @max: The maximum value allowed for any node in the tree
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 *
 * Time Complexity: O(n)
 */

int is_max_heap(const binary_tree_t *tree, int max)
{
	if (tree == NULL)
		return 1;

	if (tree->n > max)
		return 0;

	return is_max_heap(tree->left, tree->n) && is_max_heap(tree->right, tree->n);
}
