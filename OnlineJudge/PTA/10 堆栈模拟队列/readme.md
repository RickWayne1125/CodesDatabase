# 堆栈模拟队列
设已知有两个堆栈S1和S2，请用这两个堆栈模拟出一个队列Q。

所谓用堆栈模拟队列，实际上就是通过调用堆栈的下列操作函数:

    int IsFull(Stack S)：判断堆栈S是否已满，返回1或0；
    int IsEmpty (Stack S )：判断堆栈S是否为空，返回1或0；
    void Push(Stack S, ElementType item )：将元素item压入堆栈S；
    ElementType Pop(Stack S )：删除并返回S的栈顶元素。

实现队列的操作，即入队void AddQ(ElementType item)和出队ElementType DeleteQ()。

## 输入格式：

输入首先给出两个正整数N1和N2，表示堆栈S1和S2的最大容量。随后给出一系列的队列操作：A  item表示将item入列（这里假设item为整型数字）；D表示出队操作；T表示输入结束。
## 输出格式：

对输入中的每个D操作，输出相应出队的数字，或者错误信息ERROR:Empty。如果入队操作无法执行，也需要输出ERROR:Full。每个输出占1行。
## 输入样例 ：
```
3 2
A 1 A 2 A 3 A 4 A 5 D A 6 D A 7 D A 8 D D D D T

```
## 输出样例 ：
```
ERROR:Full
1
ERROR:Full
2
3
4
7
8
ERROR:Empty

```