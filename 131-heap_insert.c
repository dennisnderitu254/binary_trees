#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (root == NULL)
		return (NULL);

	/* Create a new node for the value */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* If the heap is empty, make the new node the root */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Traverse the heap to find the right position for the new node */
	parent = find_parent_node(*root);
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;

	/* Restore the Max Heap ordering property */
	heapify_up(new_node);

	return (new_node);
}

/**
 * find_parent_node - Finds the parent node for a new node in a Max Binary Heap
 * @root: Pointer to the root node of the Heap
 * Return: Pointer to the parent node for a new node
 */
heap_t *find_parent_node(heap_t *root)
{
	/* Start at the root */
	heap_t *current = root;

	/* Traverse the heap until we find an empty spot for the new node */
	while (current->left != NULL && current->right != NULL)
	{
		/* Compare the values of the children to decide which branch to take */
		if (current->left->n > current->right->n)
			current = current->left;
		else
			current = current->right;
	}

	return (current);
}

/**
 * heapify_up - Restores the Max Heap ordering property by swapping nodes
 * @node: Pointer to the node that needs to be moved up
 */
void heapify_up(heap_t *node)
{
	heap_t *parent;

	while (node->parent != NULL && node->n > node->parent->n)
	{
		parent = node->parent;
		swap_nodes(node, parent);
	}
}

/**
 * swap_nodes - Swaps the positions of two nodes in a Max Binary Heap
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp = node1->n;

	node1->n = node2->n;
	node2->n = temp;
}
