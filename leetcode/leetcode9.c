/*
 * 9.回文数
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 *
 * 输入: 121
 * 输出: true
 * 示例 2:
 *
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 示例 3:
 *
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 进阶:
 *
 * 你能不将整数转为字符串来解决这个问题吗？
 *
 * bool isPlaindrome(int x){
 * }
 * */

/*
 * 当然是字符串！
 * 不能转的话就整除取模好了
 * 参考8 得到翻转的数
 * 判断二者是否相等即可
 * 同样 注意溢出
 * 不过可能又多余了很多计算复杂度！
 * */

#include <stdio.h>
#include <stdbool.h>

static bool isPalindrome(int x)
{
        if (x < 0)
              return false;
        else
        {
                long int a = x, b = 0;
                while (a)
                {
                        b = 10*b + a%10;
                        a = a/10;
                }
                return (x == b);
        }
}

void main(void)
{
        if (!isPalindrome(121))
              printf("fail 121\n");

        if(isPalindrome(-121))
              printf("fail -121\n");

        if(isPalindrome(10))
              printf("fail 10\n");

        return;

}
