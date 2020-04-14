/*
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 *
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 *
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 *
 * 请你实现这个将字符串进行指定行数变换的函数：
 *
 * string convert(string s, int numRows);
 * 示例 1:
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 示例 2:
 *
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 *
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * */

/*
 *
 * 想法：字符串根据其长度为几n
 * 遍历字符串分别放进
 * a*n + b
 * a = 0时 1列
 * a > 0时 (a-1)n + b + 1 列
 * 据此可以遍历判断每个字符的位置。
 * 可能有、憨憨 但是第一想法是这样的= =
 * 20191208
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * convert(char * s, int numRows){
        int length = strlen(s);
        if (numRows == 1)
              return s;
        int num = 2*numRows -2;
        int i = 0;
        int j = 0;
        int n = 0;
        char *t = (char *)malloc(sizeof(char) * (length + 1));// (char *) 不可少 有些编译器会报错的
        //第一行
        while(j*num < length)
              t[n++] = s[num*(j++)];

        //中间的行数
        for(i = 1; i < numRows -1; i++)
        {
              j = 0;
              while((j*num + num -i) < length)
              {
                    t[n++] = s[num*j + i];
                    t[n++] = s[num*j +num - i];
                    j ++;
              }
              if((j*num + i) < length)
                    t[n++] = s[num*j + i];
        }

        //最后一行
        j = 0;
        while(j*num < length)
        {
              t[n++] = s[num*j + numRows -1];
              j++;
        }

        return t;
}

void main(void)
{

        char s[] = "LEETCODEISHIRING";
        int numRows = 2;
        char *m = convert(s, numRows);
        printf("%s-----------\n", m);
        return;
}
