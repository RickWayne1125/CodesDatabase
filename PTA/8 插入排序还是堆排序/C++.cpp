#include<iostream>
#include<algorithm>
using namespace std;

int in[101], temp[101], ans[101], heap[101]; 
int n;   
//数组比较
bool sameArray(int A[], int B[]) {     
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) return false;
	}
	return true;
}
//输出当前结果
void out(int A[]) {    
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i < n - 1) cout << ' ';
	}
	cout << endl;
}
//插排判断
bool insertSort() {     
	int flag = 0;  
	for (int i = 1; i < n; i++) {       
		if (i != 1 && sameArray(ans, temp)) {
			flag = 1;    
		}
		int tmp = temp[i], j = i;
		while (j > 0 && temp[j - 1] > tmp) {
			temp[j] = temp[j - 1];
			j--;
		}
		temp[j] = tmp;
		if (flag) {
			return true;    
		}
	}
	return false;   
}
void heapSort() {
	int t = n;
	make_heap(heap, heap + t, less<int>());
	while (!sameArray(heap, ans) && t > 0) {
		pop_heap(heap, heap + t, less<int>());
		t--;
	}
	if (sameArray(heap, ans)) {
		pop_heap(heap, heap + t, less<int>());
		out(heap);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];    
		temp[i] = in[i];
		heap[i] = in[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> ans[i];   
	}
	if (insertSort()) {             
		cout << "Insertion Sort" << endl;
		out(temp);
	}
	else { 
		cout << "Heap Sort" << endl;
		heapSort();
	}
}