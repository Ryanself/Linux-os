#include<stdio.h>
#include<math.h>

static int maxarea(int *height, int count)
{
	int i = 0;
	int j = count;
	int max = mid = l = r = self = 0;
	int maxl = maxr = 0;
	for ( i; i != j; )
	{
		self = 1;
		mid = abs((a[i] - a[j]))*(j - i + 1);
		l = abs((a[i]) - a[j - 1]))*(j - i);
		r = abs((a[i + 1] - a[j]))*(j - i);

		if (max > mid)
		      self = 0;
		else if (mid > l && mid > r) {
			self = 0;
			maxl = i;
			maxr = j;
			max = mid;
		}

		if (l > r)
			j --;
		else
			i ++;

		if (self) {
			maxl = i;
			maxr = j;
			max = max(l, r);
		}
	}

}

int main(){
	int a[] = {};
	int area = maxarea(a, );
	printf("----------------%d---------", area);
	return 0;
}
