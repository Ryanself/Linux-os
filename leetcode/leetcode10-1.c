#include <stdio.h>
/*
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 *
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *
 * 说明:
 *
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 示例 1:
 *
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 示例 2:
 *
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 示例 3:
 *
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 示例 4:
 *
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 示例 5:
 *
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 *
 * 输入:
 * s = "aaab"
 * p = "a*ab"
 * // 这种是否需要考虑呢？ 因为a*ab == a*b
 * // 如果考虑做法是需要先对p输入进行化简
 * // if *(p+1) == '*' && (*p == *(p+2))
 * // *(p+2)=''
 * //我们在输入时需要把''再次过滤掉
 * 输出: true
 *
 * */
#include <stdio.h>
#include <stdbool.h>

static bool isMatch(char * s, char * p)
{
        char *c = p;
        while(*(c+2))
        {
                if (*(c + 1) == '*' && (*c == *(c+2)))
                      *(c+2) = '-';
                c++;
        }
        while(*s)
        {
                switch (*p)
                {
                        case '\0':
                                return false;
                                break;
                        case '.':
                                if(*(p+1) != '*')
                                      p++;
                                s++;
                                break;
                        case '-':
                                p++;
                                break;
                        default:
                                if (*s == *p)
                                {
                                        if(*(p+1) != '*')
                                              p++;
                                        s++;
                                } else
                                {
                                        if(*(p+1) != '*')
                                        {
                                                return false;
                                        }
                                        else
                                              p+= 2;
                                }
                                break;
                }
        }
        printf("--%s-\n", p);
        while(*p)
        {
                if(*p == '-' || *(++p) == '*')
                      p++;
                else
                {
                        return false;
                }
        }
        return true;
}

void main(void)
{
#if 0
        char *s = "aa", *p = "a";
        if(isMatch(s, p))
              printf("s is %s p is %s  fail\n", s, p);

        char *s2 = "aa";
        char *p2 = "a*";
        if(!isMatch(s2, p2))
              printf("s2 is %s p2 is %s  fail\n", s2, p2);

        char s3[] = "ab";
        char p3[] = ".*";
        if(!isMatch(s3, p3))
              printf("s3 is %s p3 is %s  fail\n", s3, p3);

        char s4[] = "aab";
        char p4[] = "c*a*b";
        if(!isMatch(s4, p4))
              printf("s4 is %s p4 is %s  fail\n", s4, p4);

        char s5[] = "mississippi";
        char p5[] = "mis*is*p*.";
        if(isMatch(s5, p5))
              printf("s5 is %s p5 is %s  fail\n", s5, p5);
#endif
        char s6[] = "aab";
        char p6[] = "a*c*aab";
        if(!isMatch(s6, p6))
              printf("s6 is %s p6 is %s  fail\n", s6, p6);
        return;
}
