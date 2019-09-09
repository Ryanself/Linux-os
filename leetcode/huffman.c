#include <stdio.h>
#include <stdlib.h> //for malloc

// we use array to create. parenet&left&right is index of its ...
typedef struct
{
	int value;
	int parent, left, right;
}huff_node, *huffman_tree;

int find_smallest_node(int *a, int size)
{
	int i,j;
	j = 0;
	for(i = 0; i < size; i++)
		j = (a[j] > a[i]) ? i : j;
	return j;
}

// select the smallest two node that not init.
void select_tree(huffman_tree HT, int *s1, int *s2, int size)
{
	int i, m, n;
	i = m = n = 0;
	while(i < (2*size + 1) && HT[i].parent != 0)
	{
		i++;
	}
	m = i;

	while(i < (2*size + 1) && HT[i].parent != 0)
	{
		i++;
	}
	n = i;

	if (HT[m].value > HT[n].value)
	{
		n = m;
		m = i;
	}

	i++;
	for(i; i < 2*size - 1; i++)
	{
		if (HT[i].value != 0)
		      continue;
		if (HT[i].value < HT[m].value)
		{
			n = m;
			m = i;
		}
		else if (HT[i].value < HT[n].value)
		      n = i;
	}

	*s1 = m;
	*s2 = n;
}

int main(void)
{
	huffman_tree huffman;
	int i, size;
	int array[10] = {3, 34, 123, 57, 84, 14, 60, 23, 26, 352};
	size = 10;
	int n = 2*size;
	huffman = (huffman_tree)malloc(n*(sizeof(huff_node)));
	for(i = 0; i < size; i++)
	{
		huffman[i].value = array[i];
		huffman[i].left = huffman[i].right = huffman[i].parent = 0;
	}
	for(i = size + 1; i < 2*size - 1; i++)
	{
		huffman[i].left = huffman[i].right = huffman[i].parent = huffman[i].value = 0;
	}
	for(i = size + 1; i < 2*size - 1; i++)
	{
		int s1, s2;
		select_tree(huffman, &s1, &s2, size);
		huffman[s1].parent = huffman[s2].parent = i;
		huffman[i].left = s1;
		huffman[i].right = s2;
		huffman[i].value = huffman[s1].value + huffman[s2].value;
	}
	return 0;
}

//question: malloc must include stdlib.h or the compile may go wrong.
