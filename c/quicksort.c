#include <stdio.h>
/*
 * write a quick sort.
 *
 * */
static void swap(int *a, int m, int n)
{
		int tmp = a[m];
		a[m] = a[n];
		a[n] = tmp;
}

// 快排中游标的选择 是随机选 还是选择从最左或者最右
// 结束条件
// 递归时 数组的划分
static void qsort(int *a, int l, int r)
{
		if (l < r)
		{
				int p = a[l];
				int i=l, j;
				for(j=l+1;j<=r;j++)
				{
						 if(a[j]<p)
						 {
								 i ++;
								 swap(a, i, j);
						 }

				}
				swap(a, i, l);
				qsort(a, l, i -1);
				qsort(a, i + 1, r);
		}
}

void main(void)
{
		int i = 0;
		int a[16] = {7, 5, 20, 8,
				12, 63, 9, 72,
				4, 21, 33, 16,
				53, 234, 52 ,33};
		for (i = 0; i < 16;i ++)
			  printf("%d ", a[i]);
		printf("\n---------------");
		qsort(a, 0, 15);
		for (i = 0; i < 16;i ++)
			  printf("%d ", a[i]);
		printf("\n---------------");

		return;
}

/*
 *   void QuickSort(SeqList R，int low，int high)
 *      { //对R[low..high]快速排序
 *        int pivotpos； //划分后的基准记录的位置
 *        if(low<high){//仅当区间长度大于1时才须排序
 *        pivotpos=Partition(R，low，high)； //对R[low..high]做划分
 *        QuickSort(R，low，pivotpos-1)； //对左区间递归排序
 *        QuickSort(R，pivotpos+1，high)； //对右区间递归排序
 *        }
 *      } //QuickSort
 */
