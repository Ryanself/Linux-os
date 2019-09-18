/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
 * 并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 示例：
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 */

#include <stdio.h>
#include <stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};

//先考虑最简单的情况 l1 > l2
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
	if (l1->val == 0 && l1->next == NULL)
	      return l2;
	if (l2->val == 0 && l2->next == NULL)
	      return l1;
	struct ListNode * l3 = l1;
	printf("zzzzzzzzz%d\n", l1->val);
	struct ListNode l4;
	l4.next = NULL;
	l4.val = 0;
	for (l2; l2->val != 0;)
	{
		l3->val = l3->val + l2->val;
		printf("%d l1 %d l3\n", l1->val, l3->val);
		if(l3->val > 9)
		{
			l3->val -= 10;
			if (l3->next)
				l3->next->val ++;
			else{
				printf("%d\n", l4.val);
				l4.val ++;
				printf("%d\n", l4.val);
				l3->next = &l4;
				break;
			}
		}
		if (l2->next ==NULL)
		      break;
		l3 = l3->next;
		l2 = l2->next;
	}
	if (l3->next && l3->next->val > 9)
	{
		l3->next->val -= 10;
		if (l3->next->next)
		      l3->next->next->val ++;
		else{
			l4.val = 1;
			l3->next->next = &l4;
		}
	}
	printf("%d l1 %d l3\n", l1->val, l3->val);

	return l1;
}

void main(void)
{
	struct ListNode *list1, *list2, *list3;
	list1 = malloc(sizeof(int));
	list1->next = NULL;
	list1->val = 6;
	list2 = malloc(sizeof(int));
	list2->next = NULL;
	list2->val = 6;
	list3 = addTwoNumbers(list1, list2);
	printf("finial %d %d\n",list3->val, list3->next->val);
}
