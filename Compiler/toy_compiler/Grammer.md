# 语法分析设计

## 产生式结构
- left [char] 产生式左端非终结符
- right [vector<char>]/[string] 产生式右端串

## 产生式文件表示
*大写字母读入表示非终结符，小写字母读入表示终结符*
eg. 
```
E->E*E
E->e
```

## 