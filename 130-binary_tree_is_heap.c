#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. If the tree is not empty, then height = 1 + max of left height and right heights.
 * 3. Get the max of left and right heights for the current node recursively, and assign the height to the current node.
 * 4. Return the height of the current node.
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: tree to go through
 * Return: balanced
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is NULL, return 0.
 * 2. If the tree is not NULL, get the height of the left and right subtrees.
 * 3. Subtract the height of the right subtree from the height of the left subtree.
 * 4. Return the difference.
 *
 * Time Complexity: O(n)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int right = 0, left = 0, total = 0;

	if (tree)
	{
		left = ((int)binary_tree_height(tree->left));
		right = ((int)binary_tree_height(tree->right));
		total = left - right;
	}
	return (total);
}

/**
 * tree_is_perfect - function that says if a tree is perfect or not
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: tree to check
 * Return: 0 if is not a perfect or other number that is the level of height
 *
 * FUNCTIONALITY *
 * 1. If the tree is empty, return 0.
 * 2. If the tree is not empty, then check if the left and right subtrees are perfect.
 * 3. If the left and right subtrees are perfect, then check if the height of left and right subtrees are same.
 * 4. If the height of left and right subtrees are same, then return true.
 * 5. Else return false.
 *
 * Time Complexity: O(n)
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
	}
	else if (!tree->left && !tree->right)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * binary_tree_is_perfect - perfect or not a tree
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. Else, call the tree_is_perfect function.
 * 3. If the tree_is_perfect function returns a non-zero value, return 1.
 * 4. Else, return 0.
 *
 * Time Complexity: O(n)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: tree to check
 * Return: 1 is it is or 0 if not
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. If the left child is greater than the root, return 0.
 * 3. If the right child is greater than the root, return 0.
 * 4. If the tree is perfect, return 1.
 * 5. If the tree is balanced, check if the left subtree is perfect and the right subtree is a heap.
 * 6. If the tree is left-heavy, check if the left subtree is a heap and the right subtree is perfect.
 * 7. Otherwise, return 0.
 *
 * Time Complexity: O(n)
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bval;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	bval = binary_tree_balance(tree);
	if (bval == 0)
	{
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_heap(tree->right));
	}
	if (bval == 1)
	{
		return (binary_tree_is_heap(tree->left) && binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}
