#include "binary_trees.h"

/**
 *binary_tree_insert_left - inserts a node as the left-child of another node
 *@parent: a pointer to the node to insert the left-child in
 *@value: the value to store in the new node
 *
 * Return: a pointer to the created node
 *
 * FUNCTIONALITY
 *
 * 1. If the parent is NULL, return NULL.
 * 2. Create a new node.
 * 3. If the new node is NULL, return NULL.
 * 4. If the parent’s left child is not NULL,
 * set the new node’s left child to the parent’s left child,
 * and set the parent of the parent’s left child to point to the new node.
 *
 * 5. Set the parent’s left child to point to the new node.
 * 6. Return a pointer to the new node.
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
