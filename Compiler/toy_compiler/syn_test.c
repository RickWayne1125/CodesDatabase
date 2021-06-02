int a;
a = 12;
a = a + 1;
int b;
b=0;
int funct1(int x, int y){
    int a, b;
    a = 1;
    b = 0;
    int i;
    int ans;
    while (x < y)
    {
        ans = a & b;
        x = x + 1;
    };
    return ans;
};
int ans;
ans = funct1(int b, int a);