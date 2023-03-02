#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify - Rearranges the given binary tree rooted at node to satisfy
 * the Max Heap ordering property.
 *
 * @node: A pointer to the root node of the binary tree to be heapified.
 */
void heapify(binary_tree_t *node)
{
	binary_tree_t *largest = node;

	if (node->left && node->left->n > largest->n)
		largest = node->left;

	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		int temp = node->n;

		node->n = largest->n;
		largest->n = temp;
		heapify(largest);
	}
}

/**
 * array_to_heap - Builds a Max Binary Heap tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: A pointer to the root node of the created Binary Heap, or NULL
 * on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root = NULL;
	binary_tree_t **queue = NULL;
	binary_tree_t *node = NULL;
	size_t i, q_size = 0;

	if (!array || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		node = binary_tree_node(NULL, array[i]);
		if (!node)
		{
			free(queue);
			binary_tree_delete(root);
			return (NULL);
		}

		if (!root)
			root = node;

		else
		{
			node->parent = queue[(i - 1) / 2];
			if ((i - 1) % 2 == 0)
				queue[(i - 1) / 2]->left = node;
			else
				queue[(i - 1) / 2]->right = node;
		}

		queue = realloc(queue, sizeof(*queue) * (q_size + 1));
		if (!queue)
		{
			binary_tree_delete(root);
			return (NULL);
		}
		queue[q_size++] = node;
	}

	for (i = (size - 2) / 2; i + 1 > 0; i--)
		heapify(queue[i]);

	free(queue);
	return ((heap_t *)root);
}
