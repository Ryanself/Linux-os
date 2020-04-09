#include <stdio.h>
struct ListNode {
        int val;
        struct ListNode *next;
};

struct ListNode l3;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        struct ListNode *l11 = l1;
        struct ListNode *l22 = l2;
        l3.val = 1;
        l3.next =NULL;
        int carry = 0;
        if ()
}

//we can leave carry utill we finish all the add to make code easier.
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
        struct ListNode *l11 = l1;
        struct ListNode *l22 = l2;
        l3.val = 1;
        l3.next =NULL;
              while (l11 && l22)
              {
                      //handle carry.
                      l11->val += carry;
                      l11->val += l22->val;
                      l22->val = l11->val;
                      if(l22->next && l11->next)
                      {
                              l22 = l22->next;
                              l11 = l11->next;
                      }
                      else
                            break;
              }

              if(l11->next || !(l22->next))
              {
                      l11 = l1;
                      while(l11->next)
                      {
                              if(l11->val > 9)
                              {
                                      l11->val -= 10;
                                      l11->next->val ++;
                              }
                              l11 = l11->next;
                      }

                      if (l11->val > 9)
                      {
                              l11->val -= 10;
                              l11->next = &l3;
                      }

                      return l1;
              } else
              {
                      l22 = l2;
                      while(l22->next)
                      {
                              if(l22->val > 9)
                              {
                                      l22->val -= 10;
                                      l22->next->val ++;
                              }
                              l22 = l22->next;
                      }

                      if (l22->val > 9)
                      {
                              l22->val -= 10;
                              l22->next = &l3;
                      }

                      return l2

              }
}

int main(void)
{
        return 0;
}
