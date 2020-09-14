#include <bits/stdc++.h>

using namespace std;

struct stu {
    string name;
    string id;
    int grade;
};

bool cmp(stu x, stu y) {
    if (x.grade > y.grade) {
        return true;
    } else return false;
}

stu st[1005];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> st[i].name >> st[i].id >> st[i].grade;
    }
    sort(st,st+N,cmp);
    cout<<st[0].name<<' '<<st[0].id<<endl;
    cout<<st[N-1].name<<' '<<st[N-1].id<<endl;
    return 0;
}

