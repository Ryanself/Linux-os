/**
 * leetcode No.3
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 示例 1:
 * 输入: "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */
#include <stdio.h>
int lengthOfLongestSubstring(char * s){
	int start = 0, end = 0, length = 0; //声明时初始化 速度更快
	char map[256] = {0};// 不初始化可能导致一些问题 判断的地方 因为其内存里不一定是0
	map[(int)*(s+start)] = 1;
	while(*(s + end) != 0)
	{
		printf("\n  end %d start %d \n", end, start);
		length = length > (end -start + 1) ? length : (end - start + 1);
		end ++;
		while(map[(int)*(s + end)] != 0)
		{
			map[(int)*(s+start)] = 0;
			start ++;// 考虑还能优化吗这里？
		}
		map[(int)*(s+end)] = 1;
	}
	return length;
}

void main(void)
{
	char *s1 = "abababbbcjwrbsfgwhsrirarjhajraarrrrazzzrer";
	char *s2 = "abcabcbb";
	int a = lengthOfLongestSubstring(s2);
	printf("string %s longestsubstring length is %d \n", s2, a);

}
