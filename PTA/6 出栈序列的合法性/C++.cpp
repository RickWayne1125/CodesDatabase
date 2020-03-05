#include<iostream>
//#include "book.h"
using namespace std;
const int defaultSize = 1001;

template <typename E> class Stack {
private:
	void operator =(const Stack&) {}     // 重载赋值操作
	Stack(const Stack&) {}         // 拷贝操作

public:
	Stack() {}                       // 构造函数
	virtual ~Stack() {}              // 析构函数

	virtual void clear() = 0;
	virtual void enqueue(const E& it) = 0;
	virtual E dequeue() = 0;
	virtual const E& frontValue() const = 0;
	virtual int length() const = 0;
};


// 队列类Queue
template <typename E> class Queue {
private:
	void operator =(const Queue&) {}     // 重载赋值操作
	Queue(const Queue&) {}         // 拷贝函数

public:
	Queue() {}          // 构造函数
	virtual ~Queue() {} // 析构函数

	virtual void clear() = 0;
	virtual void enqueue(const E&) = 0;
	virtual E dequeue() = 0;
	virtual const E& frontValue() const = 0;
	virtual int length() const = 0;
};

//数组队列类AQueue
template <typename E> class AQueue : public Queue<E> {
private:
	int maxSize;               // 队列最大长度
	int front;                 // 队列头部元素值
	int rear;                  // 队列尾部元素值
	E* listArray;           // 用数组存储元素

public:
	AQueue(int size = defaultSize) {  // 构造函数
	  // 数组要开大一位
		maxSize = size + 1;
		rear = 0;  front = 1;
		listArray = new E[maxSize];
	}

	~AQueue() { delete[] listArray; } // 析构函数

	void clear() { rear = 0; front = 1; } // Reinitialize

	void enqueue(const E& it) {     // 将it添加进队列
		rear = (rear + 1) % maxSize;       // 环尾部后移
		listArray[rear] = it;
	}

	E dequeue() {           // 将头部元素弹出
		E it = listArray[front];
		front = (front + 1) % maxSize;    // 环头部后移
		return it;
	}

	const E& frontValue() const {  // 返回队列头部元素值
		return listArray[front];
	}

	virtual int length() const {	// 返回队列长度
		return ((rear + maxSize) - front + 1) % maxSize;
	}
};

// 完成下面的栈类QStack，使用其中的双队列实现入栈、出栈等基本运算
template <typename E>
class QStack : public Stack<E> {
private:
	int maxSize; // 栈的容量
	// 基于数组实现的队列
	AQueue<E> QA;	// 存储栈元素的队列
	AQueue<E> QB;	// 协助模拟栈的队列
public:
	QStack(int size = defaultSize) : QA(size), QB(size) // 初始化队列
	{
		maxSize = size;
	}
	~QStack() { }
	// 完成下列函数的代码

	// 清空栈
	void clear() {
		QA.clear();
		QB.clear();
	}
	// 将栈内全部元素输出打印一遍
	void out() {
		while (QA.length() != 0) {
			cout << QA.frontValue() << endl;
			QB.enqueue(QA.dequeue());
		}
		while (QB.length() != 0) {
			QA.enqueue(QB.dequeue());
		}
	}
	// 将it压入栈
	void enqueue(const E& it) {
		while (QA.length() != 0) {
			QB.enqueue(QA.dequeue());
		}
		QA.enqueue(it);
		while (QB.length() != 0) {
			QA.enqueue(QB.dequeue());
		}
	}
	// 将栈顶元素弹出
	E dequeue() {
		return QA.dequeue();
	}
	// 返回栈顶元素值
	const E& frontValue() const {
		return QA.frontValue();
	}
	// 返回栈长度
	virtual int length() const {
		return QA.length();
	}
};

//判断出栈顺序是否有效的函数
bool is_correct_pop_sequence(int A[], int n, int k) {
	QStack<int> temp;//模拟进出栈所用的临时栈
	int flag = 0;
	temp.clear();
	for (int i = 0; i < n; i++) {
		temp.enqueue(i + 1);
		if (temp.length() > k)	return false;
		while (temp.length()!=0) {
			if (temp.frontValue() == A[flag]) {
				temp.dequeue();
				flag++;
			}
			else break;
		}
	}
	if (temp.length() == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int N, K, m;
	cin >> K >> N >> m;
	int A[1001];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[j];
		}
		if (is_correct_pop_sequence(A, N, K)) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}
}


