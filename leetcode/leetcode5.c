/* *
 * leetcode No.5 最长回文子串
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 示例 2：
 *
 * 输入: "cbbd"
 * 输出: "bb"
 */

#include <stdio.h>
#include <string.h>
//hardcore just use parse to find the longest one.
char * longestPalindrome(char * s)
{
        int i = 0;
        int j = 0;
        int c = 1;
        int length = strlen(s);
        int max_len = length;
        while(max_len > 0)
        {
                for(i = 0;i + max_len <= length; i++)
                {
                        c = 1;
                        for(j = 0;j < max_len/2;j++)
                        {
                                if(*(s+i+j) != *(s+i+ max_len-1-j))
                                {
                                        c = 0;
                                        break;
                                }
                        }
                        if (c)
                        {

                                *(s + i + max_len) = '\0';
                                return (s+i);
                        }
                }
                max_len --;

        }

        return (s);

}


void main(void)
{
        char s[] = "cbbd";
        char *a = longestPalindrome(s);
        printf("-----%s--\n", a);

}
