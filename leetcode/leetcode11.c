/*
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 示例：
 *
 * 输入：[1,8,6,2,5,4,8,3,7]
 * 输出：49
 */
#include <stdio.h>

static int minc(int a, int b) {
    return (a > b ? b : a);
}

int maxArea(int* height, int heightSize){
    int max = 0, i = 0, j = 0, t = 0, m = 0;
    for (i; i < heightSize; i ++)
    {
        if (*(height +i))
          m = max / (*(height +i));
        else
          continue;
        for (j=i+m+1; j < heightSize; j ++)
        {
            t = (j-i)*minc(*(height +i), *(height +j));
            if (max< t)
              max = t;
        }
    }
    return max;
}

void main(void)
{
    int a[2] = {0, 2};
    printf("%d\n", maxArea(a, 2));
    return;
}
