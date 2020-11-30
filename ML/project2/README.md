# 实验2 决策树算法实践
1.理解并描述决策树分类、回归算法原理。

2.编程实践，将决策树分类、回归算法分别应用于合适的数据集(如鸢尾花、波士顿房价预测、UCI数据集、Kaggle数据集)，要求算法至少用于两种数据集(分类2个，回归2个)。

## 决策树分类
```
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  0 Real:  0
Prediction:  2 Real:  1
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Before Pruning Accuracy:  0.94
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  0 Real:  0
Prediction:  0 Real:  0
Prediction:  2 Real:  1
Prediction:  0 Real:  0
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  0 Real:  0
Prediction:  2 Real:  2
After Pruning Accuracy:  0.96
```

## 决策树回归
```
Building Tree...
Prediction:  24.85 Real:  23.5
Prediction:  24.2 Real:  23.2
Prediction:  21.8 Real:  20.2
Prediction:  11.3 Real:  19.4
Prediction:  50.0 Real:  50.0
Prediction:  13.9 Real:  13.5
Prediction:  12.899999999999999 Real:  12.5
Prediction:  24.05 Real:  24.0
Prediction:  20.65 Real:  22.2
Prediction:  8.8 Real:  7.0
Prediction:  14.3 Real:  18.1
Prediction:  22.9 Real:  20.6
Prediction:  24.4 Real:  25.0
Prediction:  20.55 Real:  24.8
Prediction:  20.6 Real:  21.2
Prediction:  18.8 Real:  17.3
Prediction:  31.15 Real:  29.4
Prediction:  37.25 Real:  36.2
Prediction:  11.8 Real:  7.2
Prediction:  39.8 Real:  38.7
Prediction:  11.3 Real:  15.6
Prediction:  19.1 Real:  13.8
Prediction:  28.55 Real:  42.8
Prediction:  20.3 Real:  21.1
Prediction:  23.8 Real:  23.6
Prediction:  14.399999999999999 Real:  23.2
Prediction:  14.95 Real:  10.4
Prediction:  50.0 Real:  50.0
Prediction:  34.1 Real:  32.0
Prediction:  18.85 Real:  19.5
Prediction:  19.6 Real:  23.1
Prediction:  20.15 Real:  22.5
Prediction:  18.1 Real:  14.9
Prediction:  23.0 Real:  25.0
Prediction:  19.4 Real:  18.7
Prediction:  15.649999999999999 Real:  17.1
Prediction:  14.1 Real:  8.4
Prediction:  13.9 Real:  11.9
Prediction:  20.15 Real:  19.4
Prediction:  14.1 Real:  13.3
Prediction:  18.549999999999997 Real:  18.2
Prediction:  11.3 Real:  13.1
Prediction:  8.9 Real:  13.4
Prediction:  8.9 Real:  14.0
Prediction:  27.25 Real:  20.5
Prediction:  35.15 Real:  32.2
Prediction:  23.8 Real:  23.1
Prediction:  14.95 Real:  17.8
Prediction:  8.5 Real:  8.3
Prediction:  28.1 Real:  23.9
Prediction:  7.4 Real:  14.4
Prediction:  11.7 Real:  10.2
Prediction:  17.85 Real:  18.4
Prediction:  30.8 Real:  30.1
Prediction:  13.149999999999999 Real:  13.2
Prediction:  21.2 Real:  21.2
Prediction:  45.0 Real:  50.0
Prediction:  24.25 Real:  24.8
Prediction:  20.049999999999997 Real:  19.8
Prediction:  32.5 Real:  24.0
Prediction:  33.3 Real:  34.6
Prediction:  50.0 Real:  50.0
Prediction:  48.4 Real:  43.8
Prediction:  11.8 Real:  14.6
Prediction:  15.649999999999999 Real:  20.9
Prediction:  27.25 Real:  24.5
Prediction:  32.85 Real:  26.6
Prediction:  31.15 Real:  29.8
Prediction:  28.7 Real:  22.4
Prediction:  24.25 Real:  22.9
Prediction:  18.1 Real:  12.6
Prediction:  32.5 Real:  22.8
Prediction:  32.9 Real:  29.0
Prediction:  5.3 Real:  7.2
Prediction:  14.65 Real:  13.1
Prediction:  31.0 Real:  33.8
Prediction:  22.0 Real:  13.4
Prediction:  14.1 Real:  7.5
Prediction:  28.1 Real:  24.8
Prediction:  25.25 Real:  24.7
Prediction:  18.549999999999997 Real:  18.5
Prediction:  20.6 Real:  18.3
Prediction:  8.45 Real:  8.7
Prediction:  16.1 Real:  15.2
Prediction:  36.2 Real:  22.0
Prediction:  37.6 Real:  50.0
Prediction:  19.6 Real:  18.7
Prediction:  18.7 Real:  21.7
Prediction:  19.25 Real:  19.6
Prediction:  36.1 Real:  33.4
Prediction:  28.7 Real:  23.0
Prediction:  9.6 Real:  15.6
Prediction:  11.3 Real:  14.3
Prediction:  20.3 Real:  21.0
Prediction:  19.35 Real:  21.7
Prediction:  20.15 Real:  21.7
Prediction:  16.1 Real:  16.7
Prediction:  21.85 Real:  18.2
Prediction:  23.200000000000003 Real:  22.2
Prediction:  17.85 Real:  13.8
Prediction:  24.4 Real:  22.3
Prediction:  30.25 Real:  41.3
Prediction:  21.85 Real:  20.9
Prediction:  24.3 Real:  23.9
Prediction:  24.25 Real:  24.5
Prediction:  50.0 Real:  43.1
Prediction:  19.1 Real:  19.9
Prediction:  8.9 Real:  13.1
Prediction:  11.8 Real:  10.9
Prediction:  8.9 Real:  11.8
Prediction:  11.3 Real:  14.9
Prediction:  20.6 Real:  16.8
Prediction:  34.1 Real:  28.5
Prediction:  45.0 Real:  50.0
Prediction:  34.1 Real:  31.6
Prediction:  24.2 Real:  22.6
Prediction:  24.3 Real:  28.7
Prediction:  20.049999999999997 Real:  23.1
Prediction:  8.9 Real:  13.4
Prediction:  14.7 Real:  27.1
Prediction:  19.25 Real:  19.6
Prediction:  23.05 Real:  21.9
Prediction:  24.35 Real:  27.5
Prediction:  34.1 Real:  31.2
Prediction:  37.25 Real:  35.4
Prediction:  19.35 Real:  19.7
Prediction:  6.0 Real:  12.8
Prediction:  22.0 Real:  16.4
Prediction:  24.35 Real:  26.5
Prediction:  10.6 Real:  13.3
Prediction:  24.7 Real:  22.6
Prediction:  17.6 Real:  17.2
Prediction:  21.8 Real:  17.4
Prediction:  20.55 Real:  22.0
Prediction:  19.6 Real:  14.5
Prediction:  21.4 Real:  20.1
Prediction:  14.1 Real:  13.6
Prediction:  24.25 Real:  29.1
Prediction:  14.1 Real:  27.5
Prediction:  18.7 Real:  16.6
Prediction:  18.8 Real:  19.5
Prediction:  20.8 Real:  22.6
Prediction:  22.0 Real:  27.5
Prediction:  8.9 Real:  10.8
Prediction:  10.6 Real:  10.5
Prediction:  24.85 Real:  22.5
Prediction:  20.15 Real:  21.2
Prediction:  18.7 Real:  20.3
Prediction:  23.8 Real:  21.6
Prediction:  16.75 Real:  17.9
Prediction:  23.8 Real:  23.1
Prediction:  28.1 Real:  32.0
Prediction:  25.1 Real:  30.1
Prediction:  23.200000000000003 Real:  23.7
Prediction:  24.85 Real:  23.7
Prediction:  23.8 Real:  22.2
Prediction:  48.4 Real:  45.4
Prediction:  6.0 Real:  11.3
Prediction:  18.7 Real:  18.9
Prediction:  37.9 Real:  34.9
Prediction:  37.6 Real:  50.0
Prediction:  20.3 Real:  21.1
Prediction:  8.45 Real:  10.4
Prediction:  50.0 Real:  50.0
Prediction:  50.0 Real:  44.8
Prediction:  28.75 Real:  23.3
Prediction:  30.0 Real:  22.8
Prediction:  36.2 Real:  20.3
Prediction:  17.6 Real:  17.5
Root:
root:  5 6.676
left:  12 14.395
right:  5 7.4350000000000005
R2: 0.7951858850043194
MSE Bef:  199999.0
MSE Aft:  0.625
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  199999.0
MSE Aft:  0.5066666666666664
MSE Bef:  100000.00666666667
MSE Aft:  0.5899999999999997
MSE Bef:  100000.09
MSE Aft:  0.8320000000000003
MSE Bef:  100000.332
MSE Aft:  1.9983333333333355
MSE Bef:  2.5033333333333356
MSE Aft:  3.308749999999999
MSE Bef:  199999.0
MSE Aft:  0.5049999999999998
MSE Bef:  199999.0
MSE Aft:  0.625
MSE Bef:  100000.125
MSE Aft:  4.0
MSE Bef:  199999.0
MSE Aft:  0.7449999999999994
MSE Bef:  199999.0
MSE Aft:  0.745000000000002
MSE Bef:  1.4900000000000015
MSE Aft:  4.019999999999998
MSE Bef:  199999.0
MSE Aft:  0.8200000000000005
MSE Bef:  100000.32
MSE Aft:  2.9916666666666636
MSE Bef:  199999.0
MSE Aft:  0.5449999999999992
MSE Bef:  100000.045
MSE Aft:  0.9399999999999991
MSE Bef:  199999.0
MSE Aft:  1.2200000000000033
MSE Bef:  100000.72
MSE Aft:  5.7266666666666755
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  100000.005
MSE Aft:  0.6399999999999997
MSE Bef:  100000.14
MSE Aft:  0.7074999999999989
MSE Bef:  100000.2075
MSE Aft:  1.0129999999999995
MSE Bef:  100000.513
MSE Aft:  2.837142857142858
MSE Bef:  199999.0
MSE Aft:  0.5049999999999998
MSE Bef:  100000.005
MSE Aft:  4.5599999999999925
MSE Bef:  100004.06
MSE Aft:  10.907999999999996
MSE Bef:  13.745142857142854
MSE Aft:  37.22833333333332
MSE Bef:  199999.0
MSE Aft:  0.5049999999999998
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  100000.005
MSE Aft:  0.8316666666666658
MSE Bef:  1.3366666666666656
MSE Aft:  8.948
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  199999.0
MSE Aft:  0.5600000000000003
MSE Bef:  100000.06
MSE Aft:  1.8274999999999992
MSE Bef:  2.3724999999999996
MSE Aft:  8.799999999999994
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  100000.045
MSE Aft:  0.6266666666666667
MSE Bef:  100000.12666666666
MSE Aft:  1.1900000000000022
MSE Bef:  199999.0
MSE Aft:  0.5650000000000004
MSE Bef:  199999.0
MSE Aft:  0.7449999999999994
MSE Bef:  1.3099999999999998
MSE Aft:  1.9080000000000028
MSE Bef:  199999.0
MSE Aft:  1.1666666666666667
MSE Bef:  199999.0
MSE Aft:  0.5200000000000006
MSE Bef:  1.6866666666666674
MSE Aft:  1.8674999999999993
MSE Bef:  199999.0
MSE Aft:  0.5600000000000003
MSE Bef:  100000.06
MSE Aft:  0.7474999999999994
MSE Bef:  100000.2475
MSE Aft:  1.0600000000000003
MSE Bef:  100000.56
MSE Aft:  1.9792857142857099
MSE Bef:  199999.0
MSE Aft:  0.5133333333333328
MSE Bef:  100000.01333333334
MSE Aft:  0.8883333333333328
MSE Bef:  100000.38833333334
MSE Aft:  3.162142857142865
MSE Bef:  100002.66214285714
MSE Aft:  17.815555555555566
MSE Bef:  100017.31555555556
MSE Aft:  25.185454545454558
MSE Bef:  27.164740259740267
MSE Aft:  47.476666666666674
MSE Bef:  199999.0
MSE Aft:  0.6066666666666659
MSE Bef:  199999.0
MSE Aft:  1.219999999999999
MSE Bef:  199999.0
MSE Aft:  0.5266666666666665
MSE Bef:  100000.02666666667
MSE Aft:  0.6675
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  1.2125000000000004
MSE Aft:  2.3786666666666676
MSE Bef:  199999.0
MSE Aft:  1.625
MSE Bef:  199999.0
MSE Aft:  0.5049999999999998
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  1.0099999999999998
MSE Aft:  0.7533333333333332
MSE Bef:  100000.25333333333
MSE Aft:  1.713333333333332
MSE Bef:  3.338333333333332
MSE Aft:  8.043809523809527
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  100000.005
MSE Aft:  0.7866666666666686
MSE Bef:  100000.28666666667
MSE Aft:  2.153000000000003
MSE Bef:  100001.653
MSE Aft:  6.8735714285714264
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  100000.045
MSE Aft:  1.1533333333333333
MSE Bef:  100000.65333333334
MSE Aft:  3.4399999999999995
MSE Bef:  100002.94
MSE Aft:  7.279999999999993
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  100000.005
MSE Aft:  1.106666666666666
MSE Bef:  8.38666666666666
MSE Aft:  18.959999999999997
MSE Bef:  199999.0
MSE Aft:  0.5799999999999994
MSE Bef:  199999.0
MSE Aft:  0.8049999999999997
MSE Bef:  1.3849999999999991
MSE Aft:  3.614166666666665
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  100000.005
MSE Aft:  1.4866666666666644
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  100000.045
MSE Aft:  0.7466666666666661
MSE Bef:  100000.24666666667
MSE Aft:  1.1874999999999991
MSE Bef:  100000.6875
MSE Aft:  2.6049999999999986
MSE Bef:  199999.0
MSE Aft:  0.9049999999999987
MSE Bef:  100000.405
MSE Aft:  4.279999999999999
MSE Bef:  100003.78
MSE Aft:  12.154166666666667
MSE Bef:  14.759166666666665
MSE Aft:  35.06857142857144
MSE Bef:  199999.0
MSE Aft:  0.8199999999999992
MSE Bef:  100000.32
MSE Aft:  2.746666666666666
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  3.2916666666666665
MSE Aft:  9.574166666666667
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  199999.0
MSE Aft:  0.5050000000000001
MSE Bef:  1.0500000000000003
MSE Aft:  0.9666666666666652
MSE Bef:  100000.46666666666
MSE Aft:  1.8483333333333323
MSE Bef:  199999.0
MSE Aft:  1.219999999999999
MSE Bef:  100000.72
MSE Aft:  5.38666666666666
MSE Bef:  199999.0
MSE Aft:  0.5800000000000002
MSE Bef:  100000.08
MSE Aft:  0.645
MSE Bef:  100000.145
MSE Aft:  1.512
MSE Bef:  100001.012
MSE Aft:  3.368333333333338
MSE Bef:  8.754999999999997
MSE Aft:  16.676250000000003
MSE Bef:  199999.0
MSE Aft:  2.1250000000000004
MSE Bef:  199999.0
MSE Aft:  1.0000000000000004
MSE Bef:  100000.5
MSE Aft:  2.440000000000001
MSE Bef:  100001.94
MSE Aft:  7.0479999999999965
MSE Bef:  199999.0
MSE Aft:  3.2199999999999993
MSE Bef:  10.267999999999995
MSE Aft:  22.284999999999997
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  199999.0
MSE Aft:  0.5450000000000003
MSE Bef:  199999.0
MSE Aft:  0.6799999999999998
MSE Bef:  100000.18
MSE Aft:  1.3466666666666665
MSE Bef:  199999.0
MSE Aft:  0.505
MSE Bef:  100000.005
MSE Aft:  0.5866666666666669
MSE Bef:  1.9333333333333333
MSE Aft:  4.737500000000001
MSE Bef:  199999.0
MSE Aft:  0.6
MSE Bef:  100000.1
MSE Aft:  4.209999999999998
MSE Bef:  100003.71
MSE Aft:  12.66
MSE Bef:  199999.0
MSE Aft:  0.6800000000000008
MSE Bef:  100000.18
MSE Aft:  4.386666666666663
MSE Bef:  100003.88666666667
MSE Aft:  13.572000000000006
MSE Bef:  199999.0
MSE Aft:  0.5999999999999993
MSE Bef:  100000.1
MSE Aft:  1.1100000000000012
MSE Bef:  100000.61
MSE Aft:  4.313333333333334
MSE Bef:  100003.81333333334
MSE Aft:  10.874285714285719
MSE Bef:  199999.0
MSE Aft:  1.3450000000000009
MSE Bef:  12.21928571428572
MSE Aft:  53.18666666666667
MSE Bef:  199999.0
MSE Aft:  1.625
MSE Bef:  199999.0
MSE Aft:  0.5049999999999994
MSE Bef:  100000.005
MSE Aft:  0.5466666666666661
MSE Bef:  100000.04666666666
MSE Aft:  0.949999999999998
MSE Bef:  2.574999999999998
MSE Aft:  6.699999999999994
MSE Bef:  199999.0
MSE Aft:  0.7449999999999994
MSE Bef:  199999.0
MSE Aft:  0.5449999999999992
MSE Bef:  100000.045
MSE Aft:  0.8049999999999966
MSE Bef:  1.549999999999996
MSE Aft:  12.398666666666646
MSE Bef:  199999.0
MSE Aft:  1.479999999999998
MSE Bef:  100000.98
MSE Aft:  5.724999999999992
MSE Bef:  199999.0
MSE Aft:  0.5049999999999998
MSE Bef:  100000.005
MSE Aft:  0.5199999999999999
MSE Bef:  100000.02
MSE Aft:  0.915
MSE Bef:  6.639999999999992
MSE Aft:  68.68699999999998
MSE Bef:  199999.0
MSE Aft:  0.505
MSE Bef:  199999.0
MSE Aft:  2.5
MSE Bef:  199999.0
MSE Aft:  0.6799999999999966
MSE Bef:  100000.18
MSE Aft:  2.1799999999999966
MSE Bef:  4.679999999999996
MSE Aft:  38.85416666666666
MSE Bef:  199999.0
MSE Aft:  0.5200000000000006
MSE Bef:  100000.02
MSE Aft:  3.598666666666663
MSE Bef:  100003.09866666667
MSE Aft:  10.558749999999993
Prediction:  24.25 Real:  23.5
Prediction:  24.25 Real:  23.2
Prediction:  21.625 Real:  20.2
Prediction:  11.975 Real:  19.4
Prediction:  50.0 Real:  50.0
Prediction:  13.865625 Real:  13.5
Prediction:  14.149999999999999 Real:  12.5
Prediction:  21.3234375 Real:  24.0
Prediction:  21.875 Real:  22.2
Prediction:  9.575 Real:  7.0
Prediction:  16.675 Real:  18.1
Prediction:  21.55 Real:  20.6
Prediction:  26.53125 Real:  25.0
Prediction:  21.55 Real:  24.8
Prediction:  20.3 Real:  21.2
Prediction:  17.459375 Real:  17.3
Prediction:  31.825 Real:  29.4
Prediction:  36.806250000000006 Real:  36.2
Prediction:  9.25 Real:  7.2
Prediction:  44.287499999999994 Real:  38.7
Prediction:  11.975 Real:  15.6
Prediction:  16.78125 Real:  13.8
Prediction:  28.55 Real:  42.8
Prediction:  21.625 Real:  21.1
Prediction:  26.53125 Real:  23.6
Prediction:  14.149999999999999 Real:  23.2
Prediction:  14.524999999999999 Real:  10.4
Prediction:  44.287499999999994 Real:  50.0
Prediction:  29.725 Real:  32.0
Prediction:  18.368750000000002 Real:  19.5
Prediction:  17.375 Real:  23.1
Prediction:  19.5375 Real:  22.5
Prediction:  17.175 Real:  14.9
Prediction:  21.825 Real:  25.0
Prediction:  20.1875 Real:  18.7
Prediction:  15.649999999999999 Real:  17.1
Prediction:  14.524999999999999 Real:  8.4
Prediction:  13.9 Real:  11.9
Prediction:  19.5375 Real:  19.4
Prediction:  14.524999999999999 Real:  13.3
Prediction:  19.075 Real:  18.2
Prediction:  11.975 Real:  13.1
Prediction:  7.45 Real:  13.4
Prediction:  7.45 Real:  14.0
Prediction:  26.53125 Real:  20.5
Prediction:  34.1125 Real:  32.2
Prediction:  24.25 Real:  23.1
Prediction:  14.524999999999999 Real:  17.8
Prediction:  9.25 Real:  8.3
Prediction:  24.85625 Real:  23.9
Prediction:  6.6 Real:  14.4
Prediction:  11.7 Real:  10.2
Prediction:  18.5875 Real:  18.4
Prediction:  29.725 Real:  30.1
Prediction:  13.865625 Real:  13.2
Prediction:  21.125 Real:  21.2
Prediction:  47.5 Real:  50.0
Prediction:  23.9125 Real:  24.8
Prediction:  17.459375 Real:  19.8
Prediction:  31.825 Real:  24.0
Prediction:  34.1125 Real:  34.6
Prediction:  44.287499999999994 Real:  50.0
Prediction:  44.287499999999994 Real:  43.8
Prediction:  13.9875 Real:  14.6
Prediction:  15.649999999999999 Real:  20.9
Prediction:  26.53125 Real:  24.5
Prediction:  34.1125 Real:  26.6
Prediction:  31.825 Real:  29.8
Prediction:  26.53125 Real:  22.4
Prediction:  23.9125 Real:  22.9
Prediction:  17.175 Real:  12.6
Prediction:  31.825 Real:  22.8
Prediction:  31.425 Real:  29.0
Prediction:  6.6 Real:  7.2
Prediction:  13.865625 Real:  13.1
Prediction:  33.76875 Real:  33.8
Prediction:  23.175 Real:  13.4
Prediction:  14.524999999999999 Real:  7.5
Prediction:  24.85625 Real:  24.8
Prediction:  25.025 Real:  24.7
Prediction:  19.075 Real:  18.5
Prediction:  20.3 Real:  18.3
Prediction:  7.737499999999999 Real:  8.7
Prediction:  14.149999999999999 Real:  15.2
Prediction:  31.950000000000003 Real:  22.0
Prediction:  40.175 Real:  50.0
Prediction:  18.368750000000002 Real:  18.7
Prediction:  19.049999999999997 Real:  21.7
Prediction:  19.2 Real:  19.6
Prediction:  36.806250000000006 Real:  33.4
Prediction:  26.53125 Real:  23.0
Prediction:  11.975 Real:  15.6
Prediction:  11.975 Real:  14.3
Prediction:  21.625 Real:  21.0
Prediction:  21.85625 Real:  21.7
Prediction:  19.2 Real:  21.7
Prediction:  14.149999999999999 Real:  16.7
Prediction:  23.275 Real:  18.2
Prediction:  23.9125 Real:  22.2
Prediction:  18.5875 Real:  13.8
Prediction:  22.95 Real:  22.3
Prediction:  27.875 Real:  41.3
Prediction:  23.275 Real:  20.9
Prediction:  27.875 Real:  23.9
Prediction:  23.9125 Real:  24.5
Prediction:  44.287499999999994 Real:  43.1
Prediction:  16.78125 Real:  19.9
Prediction:  7.45 Real:  13.1
Prediction:  9.25 Real:  10.9
Prediction:  7.45 Real:  11.8
Prediction:  11.975 Real:  14.9
Prediction:  20.3 Real:  16.8
Prediction:  29.725 Real:  28.5
Prediction:  47.5 Real:  50.0
Prediction:  29.725 Real:  31.6
Prediction:  24.25 Real:  22.6
Prediction:  27.875 Real:  28.7
Prediction:  17.459375 Real:  23.1
Prediction:  7.45 Real:  13.4
Prediction:  15.475 Real:  27.1
Prediction:  19.2 Real:  19.6
Prediction:  22.575000000000003 Real:  21.9
Prediction:  23.175 Real:  27.5
Prediction:  29.725 Real:  31.2
Prediction:  36.806250000000006 Real:  35.4
Prediction:  21.85625 Real:  19.7
Prediction:  7.45 Real:  12.8
Prediction:  23.175 Real:  16.4
Prediction:  23.175 Real:  26.5
Prediction:  9.25 Real:  13.3
Prediction:  23.275 Real:  22.6
Prediction:  18.368750000000002 Real:  17.2
Prediction:  21.625 Real:  17.4
Prediction:  21.55 Real:  22.0
Prediction:  19.075 Real:  14.5
Prediction:  19.9 Real:  20.1
Prediction:  14.149999999999999 Real:  13.6
Prediction:  23.9125 Real:  29.1
Prediction:  14.524999999999999 Real:  27.5
Prediction:  19.049999999999997 Real:  16.6
Prediction:  17.459375 Real:  19.5
Prediction:  21.125 Real:  22.6
Prediction:  24.85625 Real:  27.5
Prediction:  7.45 Real:  10.8
Prediction:  9.25 Real:  10.5
Prediction:  24.25 Real:  22.5
Prediction:  19.5375 Real:  21.2
Prediction:  19.049999999999997 Real:  20.3
Prediction:  26.53125 Real:  21.6
Prediction:  16.78125 Real:  17.9
Prediction:  26.53125 Real:  23.1
Prediction:  24.85625 Real:  32.0
Prediction:  26.53125 Real:  30.1
Prediction:  23.9125 Real:  23.7
Prediction:  24.25 Real:  23.7
Prediction:  26.53125 Real:  22.2
Prediction:  44.287499999999994 Real:  45.4
Prediction:  7.45 Real:  11.3
Prediction:  19.049999999999997 Real:  18.9
Prediction:  36.806250000000006 Real:  34.9
Prediction:  40.175 Real:  50.0
Prediction:  21.625 Real:  21.1
Prediction:  7.737499999999999 Real:  10.4
Prediction:  50.0 Real:  50.0
Prediction:  44.287499999999994 Real:  44.8
Prediction:  27.925 Real:  23.3
Prediction:  24.85625 Real:  22.8
Prediction:  31.950000000000003 Real:  20.3
Prediction:  18.368750000000002 Real:  17.5
R2: 0.8198056428572369
```