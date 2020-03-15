#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class CustomStack {
public:
    int size;
    int top;
    int* listArray;
    CustomStack(int maxSize) {
        size = maxSize; top = 0; listArray = new int[maxSize];
    }

    void push(int x) {
        if (top != size) {
            listArray[top++] = x;
        }
    }

    int pop() {
        if (top == 0) {
            return -1;
        }
        return listArray[--top];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(top, k); i++) {
            listArray[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */