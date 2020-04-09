#include <stdio.h>
#include <stdlib.h>

struct node
{
		int val;
		struct node *pNext;
};

static void printfN(struct node *node)
{
		printf("node values is---:\n");
		while (node)
		{
				printf("--%d\n", node->val);
				node = node->pNext;
		}
}

//head ->a
//head->next ->b
//b->next ->c
//b->next = a
//ba  c   这里可以迭代
static struct node* reverse(struct node *head)
{
		struct node *a, *b, *c;
		a = head;
		b = head->pNext;
		c = b->pNext;
		a->pNext = NULL;
		b->pNext = a;
		a = b;
		while(c->pNext)
		{
				b = c;
				c = b->pNext;
				b->pNext = a;
				a = b;
		}

		c->pNext = a;
		return c;
}

void main(void)
{
		struct node a, b, c, d;
		a.val = 1;
		b.val = 2;
		c.val = 3;
		d.val = 4;
		a.pNext = &b;
		b.pNext = &c;
		c.pNext = &d;
		d.pNext = NULL;
		printfN(&a);
		printfN(reverse(&a));
		return;
}
