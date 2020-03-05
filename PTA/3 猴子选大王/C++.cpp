#include <iostream>
using namespace std;
int main(){
	int n, a[1001], *p;
	int i, j, k;
	j = k = 0;
	cin >> n;
	p = a;
	for (i = 0; i < n; i++)
		*(p + i) = i + 1;
	i = 0;
	while (k < n - 1){
		if (*(p + i) != 0) j++;
		if (j == 3)
		{
			*(p + i) = 0;
			j = 0;
			k++;
		}
		i++;
		if (i == n) i = 0;//循环
	}
	while (*p == 0) p++;
	cout << *p << endl;
	return 0;
}