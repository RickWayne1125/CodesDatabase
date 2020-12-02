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

**haberman**

```
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Before Pruning Accuracy:  0.6862745098039216
NH bef: 10.0
NH aft: 7.0
NH bef: 12.0
NH aft: 7.754887502163468
NH bef: 10.0
NH aft: 9.529325012980813
NH bef: 14.0
NH aft: 9.854752972273342
NH bef: 14.854752972273342
NH aft: 10.509775004326936
NH bef: 15.509775004326936
NH aft: 11.041843979966417
NH bef: 16.041843979966416
NH aft: 12.63547202339972
NH bef: 22.164797036380534
NH aft: 18.381151965421573
NH bef: 26.136039467585043
NH aft: 22.625817984613853
NH bef: 27.625817984613853
NH aft: 24.28421251514428
NH bef: 29.28421251514428
NH aft: 26.849325461837047
NH bef: 31.849325461837047
NH aft: 28.67133980298553
NH bef: 12.0
NH aft: 8.245112497836532
NH bef: 13.245112497836532
NH aft: 9.854752972273342
NH bef: 14.854752972273342
NH aft: 11.0
NH bef: 16.0
NH aft: 13.812908992306927
NH bef: 10.0
NH aft: 7.0
NH bef: 12.0
NH aft: 7.754887502163468
NH bef: 12.754887502163468
NH aft: 9.0
NH bef: 14.0
NH aft: 9.854752972273342
NH bef: 23.66766196458027
NH aft: 19.56425891682003
NH bef: 24.56425891682003
NH aft: 20.27094404679944
NH bef: 25.27094404679944
NH aft: 21.616102897978916
NH bef: 26.616102897978916
NH aft: 24.28421251514428
NH bef: 29.28421251514428
NH aft: 25.804526701214083
NH bef: 30.804526701214083
NH aft: 29.642782980345626
NH bef: 10.0
NH aft: 7.0
NH bef: 10.0
NH aft: 7.0
NH bef: 12.0
NH aft: 7.754887502163468
NH bef: 12.754887502163468
NH aft: 9.965802203643605
NH bef: 16.965802203643605
NH aft: 13.283418900152585
NH bef: 18.283418900152583
NH aft: 14.52804312292584
NH bef: 10.0
NH aft: 7.754887502163468
NH bef: 12.754887502163468
NH aft: 9.0
NH bef: 23.52804312292584
NH aft: 20.857738866014152
NH bef: 10.0
NH aft: 7.0
NH bef: 12.0
NH aft: 8.900134529890124
NH bef: 13.900134529890124
NH aft: 10.997175027996452
NH bef: 31.854913894010604
NH aft: 28.29615066716731
NH bef: 57.93893364751294
NH aft: 55.70174888857162
NH bef: 60.70174888857162
NH aft: 60.743818502798916
NH bef: 10.0
NH aft: 7.754887502163468
NH bef: 12.754887502163468
NH aft: 10.086166327180322
NH bef: 15.086166327180322
NH aft: 15.828921423310435
NH bef: 10.0
NH aft: 7.0
NH bef: 12.0
NH aft: 8.609640474436812
NH bef: 13.609640474436812
NH aft: 10.509775004326936
NH bef: 15.509775004326936
NH aft: 12.524422792029458
NH bef: 10.0
NH aft: 9.0
NH bef: 14.0
NH aft: 11.877840558577581
NH bef: 10.0
NH aft: 7.0
NH bef: 12.0
NH aft: 7.754887502163468
NH bef: 12.754887502163468
NH aft: 9.0
NH bef: 14.0
NH aft: 9.854752972273342
NH bef: 14.854752972273342
NH aft: 11.0
NH bef: 16.0
NH aft: 12.63547202339972
NH bef: 17.63547202339972
NH aft: 16.758425079813833
NH bef: 28.636265638391414
NH aft: 25.689790856719284
NH bef: 30.689790856719284
NH aft: 27.96862717564715
NH bef: 40.49304996767661
NH aft: 37.62935438832338
NH bef: 42.62935438832338
NH aft: 40.2752752394415
NH bef: 45.2752752394415
NH aft: 42.695711331246514
NH bef: 10.0
NH aft: 7.754887502163468
NH bef: 12.754887502163468
NH aft: 9.0
NH bef: 14.0
NH aft: 10.509775004326936
NH bef: 15.509775004326936
NH aft: 11.490224995673064
NH bef: 16.490224995673064
NH aft: 13.264662506490406
NH bef: 18.264662506490406
NH aft: 16.429011890285846
NH bef: 10.0
NH aft: 8.609640474436812
NH bef: 25.038652364722658
NH aft: 24.852652221489535
NH bef: 67.54836355273605
NH aft: 64.80749791889819
NH bef: 69.80749791889819
NH aft: 66.9534533757307
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
After Pruning Accuracy:  0.7843137254901961
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

```
Building Tree...
Prediction:  19.4 Real:  17.1
Prediction:  19.6 Real:  21.0
Prediction:  28.6 Real:  24.1
Prediction:  15.850000000000001 Real:  14.1
Prediction:  20.200000000000003 Real:  20.1
Prediction:  26.55 Real:  25.0
Prediction:  50.0 Real:  50.0
Prediction:  16.950000000000003 Real:  23.2
Prediction:  24.6 Real:  23.1
Prediction:  48.4 Real:  50.0
Prediction:  22.75 Real:  18.5
Prediction:  7.55 Real:  12.0
Prediction:  28.85 Real:  30.1
Prediction:  24.6 Real:  24.7
Prediction:  14.8 Real:  13.9
Prediction:  21.8 Real:  20.1
Prediction:  23.1 Real:  23.8
Prediction:  22.75 Real:  23.8
Prediction:  11.100000000000001 Real:  8.4
Prediction:  16.1 Real:  11.8
Prediction:  18.15 Real:  22.5
Prediction:  19.3 Real:  20.0
Prediction:  43.05 Real:  45.4
Prediction:  15.799999999999999 Real:  14.1
Prediction:  34.75 Real:  36.4
Prediction:  15.2 Real:  17.4
Prediction:  29.25 Real:  31.5
Prediction:  22.4 Real:  22.4
Prediction:  48.4 Real:  38.7
Prediction:  49.4 Real:  43.5
Prediction:  13.5 Real:  10.2
Prediction:  27.1 Real:  15.0
Prediction:  17.25 Real:  17.2
Prediction:  22.55 Real:  26.4
Prediction:  32.9 Real:  29.0
Prediction:  21.2 Real:  20.6
Prediction:  16.9 Real:  21.7
Prediction:  23.1 Real:  22.2
Prediction:  12.1 Real:  7.2
Prediction:  30.85 Real:  22.8
Prediction:  22.9 Real:  22.2
Prediction:  14.9 Real:  14.3
Prediction:  17.45 Real:  18.9
Prediction:  21.4 Real:  24.4
Prediction:  16.5 Real:  25.0
Prediction:  22.6 Real:  23.6
Prediction:  24.8 Real:  23.7
Prediction:  27.5 Real:  14.1
Prediction:  21.65 Real:  27.9
Prediction:  21.8 Real:  19.3
Prediction:  9.5 Real:  7.0
Prediction:  18.4 Real:  20.9
Prediction:  5.3 Real:  10.5
Prediction:  5.3 Real:  11.3
Prediction:  21.0 Real:  16.0
Prediction:  36.05 Real:  33.2
Prediction:  18.799999999999997 Real:  18.8
Prediction:  13.100000000000001 Real:  13.4
Prediction:  43.05 Real:  44.0
Prediction:  19.5 Real:  23.4
Prediction:  34.75 Real:  32.7
Prediction:  34.7 Real:  28.7
Prediction:  15.7 Real:  20.5
Prediction:  19.6 Real:  18.4
Prediction:  33.150000000000006 Real:  23.9
Prediction:  19.6 Real:  14.5
Prediction:  11.100000000000001 Real:  7.5
Prediction:  9.95 Real:  10.8
Prediction:  19.9 Real:  16.6
Prediction:  30.3 Real:  29.6
Prediction:  20.8 Real:  19.0
Prediction:  28.55 Real:  42.8
Prediction:  15.7 Real:  18.8
Prediction:  48.4 Real:  37.6
Prediction:  20.55 Real:  19.3
Prediction:  18.35 Real:  20.4
Prediction:  19.049999999999997 Real:  20.0
Prediction:  28.45 Real:  26.6
Prediction:  15.850000000000001 Real:  10.9
Prediction:  6.3 Real:  8.8
Prediction:  23.1 Real:  25.0
Prediction:  34.75 Real:  32.2
Prediction:  11.100000000000001 Real:  8.5
Prediction:  24.8 Real:  24.2
Prediction:  25.25 Real:  23.0
Prediction:  13.5 Real:  13.3
Prediction:  17.75 Real:  18.1
Prediction:  31.35 Real:  24.0
Prediction:  21.4 Real:  20.5
Prediction:  31.55 Real:  31.7
Prediction:  29.9 Real:  23.3
Prediction:  43.05 Real:  46.0
Prediction:  19.1 Real:  19.9
Prediction:  22.55 Real:  18.5
Prediction:  19.4 Real:  16.6
Prediction:  19.6 Real:  13.8
Prediction:  19.15 Real:  19.6
Prediction:  18.4 Real:  20.6
Prediction:  22.9 Real:  20.6
Prediction:  13.1 Real:  15.1
Prediction:  23.3 Real:  22.5
Prediction:  20.25 Real:  18.2
Prediction:  30.3 Real:  37.0
Prediction:  13.5 Real:  11.9
Prediction:  25.25 Real:  24.6
Prediction:  16.1 Real:  14.6
Prediction:  23.7 Real:  23.1
Prediction:  43.25 Real:  50.0
Prediction:  29.9 Real:  32.0
Prediction:  24.8 Real:  23.2
Prediction:  22.15 Real:  23.1
Prediction:  36.5 Real:  33.8
Prediction:  19.9 Real:  20.4
Prediction:  24.65 Real:  22.0
Prediction:  50.0 Real:  50.0
Prediction:  18.0 Real:  16.7
Prediction:  22.2 Real:  20.7
Prediction:  14.5 Real:  15.2
Prediction:  24.65 Real:  23.9
Prediction:  23.6 Real:  24.3
Prediction:  21.0 Real:  20.3
Prediction:  33.150000000000006 Real:  26.7
Prediction:  50.0 Real:  50.0
Prediction:  20.5 Real:  14.9
Prediction:  15.799999999999999 Real:  14.9
Prediction:  7.2 Real:  7.4
Prediction:  29.9 Real:  30.1
Prediction:  13.95 Real:  17.8
Prediction:  28.85 Real:  25.1
Prediction:  18.35 Real:  14.2
Prediction:  37.25 Real:  35.4
Prediction:  16.9 Real:  23.0
Prediction:  20.8 Real:  19.5
Prediction:  24.65 Real:  24.8
Prediction:  24.8 Real:  23.7
Prediction:  15.799999999999999 Real:  13.4
Prediction:  16.9 Real:  22.7
Prediction:  29.25 Real:  29.8
Prediction:  32.45 Real:  33.1
Prediction:  49.4 Real:  50.0
Prediction:  13.1 Real:  12.7
Prediction:  20.1 Real:  23.8
Prediction:  23.15 Real:  24.0
Prediction:  15.2 Real:  16.2
Prediction:  33.150000000000006 Real:  34.9
Prediction:  21.0 Real:  21.4
Prediction:  22.2 Real:  22.0
Prediction:  19.049999999999997 Real:  21.2
Prediction:  49.4 Real:  43.1
Prediction:  35.55 Real:  35.4
Prediction:  27.1 Real:  28.6
Prediction:  39.8 Real:  46.7
Prediction:  24.200000000000003 Real:  22.1
Prediction:  26.4 Real:  22.0
Prediction:  24.4 Real:  18.5
Prediction:  32.45 Real:  35.1
Prediction:  21.5 Real:  20.4
Prediction:  14.8 Real:  15.6
Prediction:  22.75 Real:  22.3
Prediction:  37.25 Real:  37.9
Prediction:  28.2 Real:  28.4
Prediction:  24.4 Real:  22.6
Prediction:  5.3 Real:  12.3
Prediction:  34.75 Real:  33.3
Prediction:  19.4 Real:  14.4
Prediction:  34.7 Real:  23.6
Prediction:  24.8 Real:  23.4
Prediction:  36.05 Real:  33.4
Prediction:  18.0 Real:  13.8
Root:
root:  12 9.95
left:  5 6.941
right:  12 16.085
R2: 0.8372062281424524
MSE Bef:  2.084999999999999
MSE Aft:  1.0849999999999993
MSE Bef:  2.1049999999999995
MSE Aft:  1.3075000000000008
MSE Bef:  2.307500000000001
MSE Aft:  1.5483333333333338
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.5683333333333334
MSE Aft:  3.786666666666666
MSE Bef:  2.1000000000000014
MSE Aft:  1.1000000000000014
MSE Bef:  2.5
MSE Aft:  1.5
MSE Bef:  2.585000000000001
MSE Aft:  1.5850000000000006
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.0466666666666669
MSE Bef:  2.046666666666667
MSE Aft:  1.3166666666666684
MSE Bef:  2.316666666666668
MSE Aft:  1.56857142857143
MSE Bef:  2.6485714285714295
MSE Aft:  3.654999999999998
MSE Bef:  2.080000000000001
MSE Aft:  1.080000000000001
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.1000000000000005
MSE Aft:  1.2066666666666674
MSE Bef:  2.045
MSE Aft:  1.0450000000000002
MSE Bef:  2.045
MSE Aft:  1.1800000000000008
MSE Bef:  2.200000000000001
MSE Aft:  1.6319999999999983
MSE Bef:  2.838666666666666
MSE Aft:  5.20914285714286
MSE Bef:  2.125
MSE Aft:  1.125
MSE Bef:  5.920000000000002
MSE Aft:  4.920000000000002
MSE Bef:  2.079999999999999
MSE Aft:  1.0799999999999994
MSE Bef:  2.1249999999999982
MSE Aft:  1.664999999999997
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.13
MSE Aft:  1.2649999999999997
MSE Bef:  2.9299999999999966
MSE Aft:  5.199999999999992
MSE Bef:  2.045
MSE Aft:  1.0450000000000002
MSE Bef:  2.045
MSE Aft:  2.26
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.0466666666666669
MSE Bef:  2.046666666666667
MSE Aft:  1.2100000000000006
MSE Bef:  2.210000000000001
MSE Aft:  3.3879999999999946
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.0866666666666676
MSE Bef:  2.086666666666668
MSE Aft:  1.9400000000000004
MSE Bef:  2.960000000000001
MSE Aft:  3.3120000000000003
MSE Bef:  2.3250000000000006
MSE Aft:  1.3250000000000006
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.01
MSE Aft:  1.1449999999999991
MSE Bef:  2.144999999999999
MSE Aft:  2.467999999999998
MSE Bef:  2.925000000000005
MSE Aft:  1.925000000000005
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  2.046666666666667
MSE Bef:  2.049999999999999
MSE Aft:  1.0499999999999994
MSE Bef:  3.125
MSE Aft:  2.125
MSE Bef:  2.0200000000000005
MSE Aft:  1.0200000000000005
MSE Bef:  6.824999999999982
MSE Aft:  8.384999999999987
MSE Bef:  2.7200000000000033
MSE Aft:  1.7200000000000033
MSE Bef:  2.125000000000001
MSE Aft:  1.1250000000000009
MSE Bef:  2.125000000000001
MSE Aft:  1.6066666666666682
MSE Bef:  3.7316666666666682
MSE Aft:  9.632500000000007
MSE Bef:  2.045
MSE Aft:  1.0450000000000002
MSE Bef:  2.045
MSE Aft:  1.2466666666666688
MSE Bef:  2.6050000000000013
MSE Aft:  1.8449999999999998
MSE Bef:  3.0916666666666686
MSE Aft:  5.267999999999998
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.3250000000000006
MSE Aft:  1.4600000000000004
MSE Bef:  2.0
MSE Aft:  1.0600000000000003
MSE Bef:  2.01
MSE Aft:  1.01
MSE Bef:  2.01
MSE Aft:  1.0500000000000003
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.0199999999999996
MSE Aft:  1.2466666666666661
MSE Bef:  2.2966666666666664
MSE Aft:  4.701333333333334
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.0199999999999996
MSE Aft:  1.1866666666666676
MSE Bef:  2.1866666666666674
MSE Aft:  1.487500000000003
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.0466666666666669
MSE Bef:  2.53416666666667
MSE Aft:  7.191999999999999
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.924999999999999
MSE Aft:  1.9249999999999994
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.0466666666666669
MSE Bef:  2.005
MSE Aft:  1.005
MSE Bef:  2.005
MSE Aft:  1.2000000000000006
MSE Bef:  2.2000000000000006
MSE Aft:  1.9350000000000018
MSE Bef:  2.125
MSE Aft:  1.125
MSE Bef:  2.125
MSE Aft:  1.7266666666666701
MSE Bef:  3.131666666666672
MSE Aft:  3.0950000000000086
MSE Bef:  5.03000000000001
MSE Aft:  11.77690476190477
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.2866666666666657
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.005
MSE Bef:  2.005
MSE Aft:  1.0199999999999998
MSE Bef:  2.065
MSE Aft:  1.1130000000000009
MSE Bef:  2.118000000000001
MSE Aft:  1.4238095238095267
MSE Bef:  2.7104761904761925
MSE Aft:  6.2325000000000035
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.0500000000000003
MSE Aft:  1.091666666666667
MSE Bef:  2.005
MSE Aft:  1.005
MSE Bef:  2.005
MSE Aft:  1.0866666666666662
MSE Bef:  2.086666666666666
MSE Aft:  1.4899999999999993
MSE Bef:  2.0649999999999986
MSE Aft:  1.064999999999999
MSE Bef:  2.5549999999999984
MSE Aft:  3.4354999999999962
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.005
MSE Aft:  1.0050000000000001
MSE Bef:  2.005
MSE Aft:  1.2866666666666657
MSE Bef:  2.2866666666666657
MSE Aft:  2.3074999999999966
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.2649999999999992
MSE Aft:  1.504999999999999
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.5249999999999986
MSE Aft:  2.641999999999994
MSE Bef:  2.244999999999999
MSE Aft:  1.271666666666666
MSE Bef:  2.005
MSE Aft:  1.005
MSE Bef:  2.13
MSE Aft:  1.2650000000000001
MSE Bef:  2.265
MSE Aft:  1.5080000000000005
MSE Bef:  2.5080000000000005
MSE Aft:  2.873333333333335
MSE Bef:  2.245000000000001
MSE Aft:  1.2450000000000008
MSE Bef:  2.245000000000001
MSE Aft:  2.5266666666666655
MSE Bef:  17.42499999999999
MSE Aft:  16.42499999999999
MSE Bef:  2.4050000000000002
MSE Aft:  1.4050000000000002
MSE Bef:  2.125000000000001
MSE Aft:  1.1250000000000009
MSE Bef:  2.530000000000001
MSE Aft:  4.853333333333337
MSE Bef:  3.325000000000001
MSE Aft:  2.3250000000000006
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.0199999999999996
MSE Aft:  1.0199999999999998
MSE Bef:  2.0399999999999996
MSE Aft:  4.219999999999999
MSE Bef:  2.3200000000000003
MSE Aft:  1.3200000000000005
MSE Bef:  2.1799999999999997
MSE Aft:  1.1799999999999997
MSE Bef:  2.1799999999999997
MSE Aft:  1.2399999999999998
MSE Bef:  2.2399999999999998
MSE Aft:  2.1474999999999995
MSE Bef:  9.9925
MSE Aft:  11.373000000000001
MSE Bef:  2.125
MSE Aft:  1.125
MSE Bef:  3.16
MSE Aft:  2.16
MSE Bef:  3.285
MSE Aft:  9.966666666666667
MSE Bef:  2.125
MSE Aft:  1.125
MSE Bef:  2.1449999999999996
MSE Aft:  1.7466666666666657
MSE Bef:  3.3516666666666652
MSE Aft:  2.6129999999999987
MSE Bef:  2.125
MSE Aft:  1.125
MSE Bef:  2.125
MSE Aft:  2.1666666666666665
Prediction:  20.9375 Real:  17.1
Prediction:  19.828125 Real:  21.0
Prediction:  26.8 Real:  24.1
Prediction:  15.225000000000001 Real:  14.1
Prediction:  20.9375 Real:  20.1
Prediction:  27.46875 Real:  25.0
Prediction:  49.7 Real:  50.0
Prediction:  17.262500000000003 Real:  23.2
Prediction:  23.75 Real:  23.1
Prediction:  49.2 Real:  50.0
Prediction:  21.8375 Real:  18.5
Prediction:  8.13125 Real:  12.0
Prediction:  28.175 Real:  30.1
Prediction:  23.75 Real:  24.7
Prediction:  14.8 Real:  13.9
Prediction:  21.175 Real:  20.1
Prediction:  23.75 Real:  23.8
Prediction:  21.8375 Real:  23.8
Prediction:  12.100000000000001 Real:  8.4
Prediction:  16.1 Real:  11.8
Prediction:  18.625 Real:  22.5
Prediction:  19.8125 Real:  20.0
Prediction:  41.425 Real:  45.4
Prediction:  16.525 Real:  14.1
Prediction:  33.95 Real:  36.4
Prediction:  14.575 Real:  17.4
Prediction:  30.0 Real:  31.5
Prediction:  23.075 Real:  22.4
Prediction:  49.2 Real:  38.7
Prediction:  49.7 Real:  43.5
Prediction:  13.65 Real:  10.2
Prediction:  27.1 Real:  15.0
Prediction:  16.9375 Real:  17.2
Prediction:  21.775 Real:  26.4
Prediction:  32.9 Real:  29.0
Prediction:  22.125 Real:  20.6
Prediction:  16.1 Real:  21.7
Prediction:  23.75 Real:  22.2
Prediction:  12.1 Real:  7.2
Prediction:  30.85 Real:  22.8
Prediction:  22.06875 Real:  22.2
Prediction:  13.975000000000001 Real:  14.3
Prediction:  18.0125 Real:  18.9
Prediction:  21.799999999999997 Real:  24.4
Prediction:  18.85 Real:  25.0
Prediction:  22.06875 Real:  23.6
Prediction:  25.628125 Real:  23.7
Prediction:  27.5 Real:  14.1
Prediction:  21.481250000000003 Real:  27.9
Prediction:  21.175 Real:  19.3
Prediction:  8.13125 Real:  7.0
Prediction:  18.95 Real:  20.9
Prediction:  6.4625 Real:  10.5
Prediction:  6.4625 Real:  11.3
Prediction:  21.775 Real:  16.0
Prediction:  36.7625 Real:  33.2
Prediction:  18.625 Real:  18.8
Prediction:  12.100000000000001 Real:  13.4
Prediction:  41.425 Real:  44.0
Prediction:  18.95 Real:  23.4
Prediction:  33.95 Real:  32.7
Prediction:  34.7 Real:  28.7
Prediction:  15.7 Real:  20.5
Prediction:  19.828125 Real:  18.4
Prediction:  33.95 Real:  23.9
Prediction:  19.828125 Real:  14.5
Prediction:  12.100000000000001 Real:  7.5
Prediction:  9.325 Real:  10.8
Prediction:  19.575 Real:  16.6
Prediction:  30.925 Real:  29.6
Prediction:  21.39375 Real:  19.0
Prediction:  28.55 Real:  42.8
Prediction:  15.7 Real:  18.8
Prediction:  49.2 Real:  37.6
Prediction:  21.175 Real:  19.3
Prediction:  18.61875 Real:  20.4
Prediction:  19.828125 Real:  20.0
Prediction:  27.35625 Real:  26.6
Prediction:  17.012500000000003 Real:  10.9
Prediction:  6.4625 Real:  8.8
Prediction:  23.75 Real:  25.0
Prediction:  33.95 Real:  32.2
Prediction:  12.100000000000001 Real:  8.5
Prediction:  25.628125 Real:  24.2
Prediction:  25.628125 Real:  23.0
Prediction:  13.65 Real:  13.3
Prediction:  19.125 Real:  18.1
Prediction:  31.7875 Real:  24.0
Prediction:  21.799999999999997 Real:  20.5
Prediction:  30.925 Real:  31.7
Prediction:  29.9 Real:  23.3
Prediction:  41.425 Real:  46.0
Prediction:  19.35 Real:  19.9
Prediction:  21.775 Real:  18.5
Prediction:  18.625 Real:  16.6
Prediction:  19.35 Real:  13.8
Prediction:  20.61875 Real:  19.6
Prediction:  18.95 Real:  20.6
Prediction:  22.06875 Real:  20.6
Prediction:  13.1 Real:  15.1
Prediction:  23.3 Real:  22.5
Prediction:  19.828125 Real:  18.2
Prediction:  30.925 Real:  37.0
Prediction:  13.65 Real:  11.9
Prediction:  25.628125 Real:  24.6
Prediction:  16.1 Real:  14.6
Prediction:  23.7 Real:  23.1
Prediction:  43.25 Real:  50.0
Prediction:  29.9 Real:  32.0
Prediction:  25.628125 Real:  23.2
Prediction:  22.15 Real:  23.1
Prediction:  36.7625 Real:  33.8
Prediction:  19.349999999999998 Real:  20.4
Prediction:  24.65 Real:  22.0
Prediction:  49.2 Real:  50.0
Prediction:  18.61875 Real:  16.7
Prediction:  21.799999999999997 Real:  20.7
Prediction:  13.81875 Real:  15.2
Prediction:  24.65 Real:  23.9
Prediction:  22.975 Real:  24.3
Prediction:  21.775 Real:  20.3
Prediction:  33.95 Real:  26.7
Prediction:  50.0 Real:  50.0
Prediction:  19.125 Real:  14.9
Prediction:  16.525 Real:  14.9
Prediction:  6.4625 Real:  7.4
Prediction:  29.9 Real:  30.1
Prediction:  14.575 Real:  17.8
Prediction:  28.175 Real:  25.1
Prediction:  18.61875 Real:  14.2
Prediction:  36.7625 Real:  35.4
Prediction:  16.1 Real:  23.0
Prediction:  21.39375 Real:  19.5
Prediction:  24.65 Real:  24.8
Prediction:  25.628125 Real:  23.7
Prediction:  16.525 Real:  13.4
Prediction:  16.1 Real:  22.7
Prediction:  30.0 Real:  29.8
Prediction:  31.7875 Real:  33.1
Prediction:  49.7 Real:  50.0
Prediction:  13.1 Real:  12.7
Prediction:  20.61875 Real:  23.8
Prediction:  22.125 Real:  24.0
Prediction:  14.575 Real:  16.2
Prediction:  33.95 Real:  34.9
Prediction:  21.775 Real:  21.4
Prediction:  20.9375 Real:  22.0
Prediction:  19.828125 Real:  21.2
Prediction:  49.7 Real:  43.1
Prediction:  34.375 Real:  35.4
Prediction:  27.1 Real:  28.6
Prediction:  41.425 Real:  46.7
Prediction:  23.75 Real:  22.1
Prediction:  25.628125 Real:  22.0
Prediction:  23.85 Real:  18.5
Prediction:  31.7875 Real:  35.1
Prediction:  20.61875 Real:  20.4
Prediction:  14.8 Real:  15.6
Prediction:  21.8375 Real:  22.3
Prediction:  36.7625 Real:  37.9
Prediction:  27.35625 Real:  28.4
Prediction:  23.85 Real:  22.6
Prediction:  6.4625 Real:  12.3
Prediction:  33.95 Real:  33.3
Prediction:  18.625 Real:  14.4
Prediction:  34.7 Real:  23.6
Prediction:  25.628125 Real:  23.4
Prediction:  36.7625 Real:  33.4
Prediction:  18.61875 Real:  13.8
R2: 0.8341799277426301
```
```
Building Tree...
Prediction:  16.6 Real:  15.0
Prediction:  17.05 Real:  18.0
Prediction:  14.433333333333332 Real:  14.9
Prediction:  13.366666666666667 Real:  14.1
Prediction:  24.549999999999997 Real:  25.3
Prediction:  18.7 Real:  15.6
Prediction:  50.0 Real:  50.0
Prediction:  19.566666666666666 Real:  14.5
Prediction:  19.0 Real:  16.6
Prediction:  17.05 Real:  15.6
Prediction:  27.0 Real:  23.7
Prediction:  14.133333333333333 Real:  17.8
Prediction:  11.5 Real:  11.5
Prediction:  23.2 Real:  21.4
Prediction:  14.133333333333335 Real:  12.7
Prediction:  23.0 Real:  24.8
Prediction:  23.75 Real:  21.2
Prediction:  17.200000000000003 Real:  23.7
Prediction:  14.433333333333332 Real:  16.4
Prediction:  20.8 Real:  19.6
Prediction:  19.566666666666666 Real:  18.3
Prediction:  16.1 Real:  21.7
Prediction:  20.633333333333333 Real:  29.8
Prediction:  18.5 Real:  20.2
Prediction:  23.599999999999998 Real:  22.9
Prediction:  20.8 Real:  15.3
Prediction:  18.2 Real:  18.3
Prediction:  5.633333333333333 Real:  10.2
Prediction:  24.96666666666667 Real:  34.9
Prediction:  14.133333333333335 Real:  15.2
Prediction:  23.9 Real:  23.3
Prediction:  20.6 Real:  20.5
Prediction:  5.633333333333333 Real:  10.5
Prediction:  11.45 Real:  15.2
Prediction:  16.8 Real:  23.2
Prediction:  24.2 Real:  23.7
Prediction:  50.0 Real:  50.0
Prediction:  28.6 Real:  27.1
Prediction:  24.5 Real:  37.0
Prediction:  19.900000000000002 Real:  23.1
Prediction:  10.95 Real:  14.9
Prediction:  23.099999999999998 Real:  19.2
Prediction:  20.4 Real:  11.9
Prediction:  17.833333333333332 Real:  17.5
Prediction:  21.96666666666667 Real:  21.7
Prediction:  20.4 Real:  27.5
Prediction:  15.9 Real:  13.8
Prediction:  20.4 Real:  20.6
Prediction:  18.833333333333332 Real:  21.8
Prediction:  20.4 Real:  18.6
Prediction:  18.833333333333332 Real:  17.6
Prediction:  18.85 Real:  23.4
Prediction:  10.95 Real:  11.7
Prediction:  17.200000000000003 Real:  14.6
Prediction:  19.900000000000002 Real:  20.1
Prediction:  22.1 Real:  19.9
Prediction:  18.85 Real:  21.7
Prediction:  23.099999999999998 Real:  21.6
Prediction:  8.5 Real:  15.1
Prediction:  26.0 Real:  20.3
Prediction:  25.1 Real:  29.1
Prediction:  45.099999999999994 Real:  50.0
Prediction:  17.6 Real:  16.0
Prediction:  35.9 Real:  43.1
Prediction:  33.900000000000006 Real:  32.7
Prediction:  17.200000000000003 Real:  18.5
Prediction:  16.0 Real:  17.9
Prediction:  22.13333333333333 Real:  23.2
Prediction:  16.6 Real:  19.1
Prediction:  23.200000000000003 Real:  24.4
Prediction:  27.5 Real:  30.1
Prediction:  23.9 Real:  28.0
Prediction:  14.133333333333335 Real:  19.5
Prediction:  13.4 Real:  13.8
Prediction:  36.849999999999994 Real:  34.7
Prediction:  21.0 Real:  22.6
Prediction:  20.35 Real:  18.8
Prediction:  23.099999999999998 Real:  22.6
Prediction:  38.7 Real:  42.8
Prediction:  23.85 Real:  22.4
Prediction:  22.03333333333333 Real:  20.4
Prediction:  24.2 Real:  27.0
Prediction:  20.0 Real:  20.6
Prediction:  45.099999999999994 Real:  37.6
Prediction:  23.2 Real:  22.2
Prediction:  14.433333333333332 Real:  13.5
Prediction:  21.7 Real:  20.1
Prediction:  21.96666666666667 Real:  20.9
Prediction:  24.96666666666667 Real:  29.6
Prediction:  20.35 Real:  19.5
Prediction:  18.833333333333332 Real:  22.8
Prediction:  14.433333333333332 Real:  13.4
Prediction:  20.4 Real:  23.1
Prediction:  23.0 Real:  23.0
Prediction:  35.9 Real:  33.2
Prediction:  24.4 Real:  20.8
Prediction:  19.45 Real:  18.5
Prediction:  18.85 Real:  20.5
Prediction:  15.533333333333333 Real:  13.8
Prediction:  15.9 Real:  12.7
Prediction:  5.633333333333333 Real:  8.8
Prediction:  23.9 Real:  26.6
Prediction:  16.6 Real:  13.8
Prediction:  27.5 Real:  26.7
Prediction:  24.85 Real:  22.2
Prediction:  20.4 Real:  19.4
Prediction:  24.3 Real:  23.9
Prediction:  45.65 Real:  50.0
Prediction:  13.366666666666667 Real:  9.5
Prediction:  8.5 Real:  13.6
Prediction:  24.4 Real:  20.2
Prediction:  30.46666666666667 Real:  31.2
Prediction:  17.566666666666666 Real:  19.3
Prediction:  13.466666666666667 Real:  19.4
Prediction:  27.5 Real:  29.9
Prediction:  10.95 Real:  9.6
Prediction:  23.85 Real:  22.0
Prediction:  32.75 Real:  32.0
Prediction:  33.900000000000006 Real:  34.9
Prediction:  23.099999999999998 Real:  18.5
Prediction:  24.96666666666667 Real:  22.0
Prediction:  8.5 Real:  13.1
Prediction:  50.0 Real:  48.8
Prediction:  13.466666666666667 Real:  17.8
Prediction:  20.75 Real:  25.0
Prediction:  16.566666666666666 Real:  23.1
Prediction:  14.133333333333335 Real:  13.1
Prediction:  23.2 Real:  22.6
Prediction:  24.2 Real:  24.6
Prediction:  16.8 Real:  19.9
Prediction:  23.0 Real:  25.0
Prediction:  24.333333333333332 Real:  20.0
Prediction:  24.4 Real:  23.8
Prediction:  17.05 Real:  16.2
Prediction:  33.599999999999994 Real:  35.4
Prediction:  50.0 Real:  42.3
Prediction:  16.15 Real:  18.2
Prediction:  8.4 Real:  8.8
Prediction:  24.2 Real:  22.8
Prediction:  22.0 Real:  21.4
Prediction:  23.9 Real:  26.6
Prediction:  19.0 Real:  17.5
Prediction:  10.95 Real:  14.5
Prediction:  23.599999999999998 Real:  21.6
Prediction:  17.200000000000003 Real:  12.0
Prediction:  23.75 Real:  24.5
Prediction:  8.5 Real:  10.5
Prediction:  11.5 Real:  9.7
Prediction:  33.599999999999994 Real:  31.0
Prediction:  13.366666666666667 Real:  11.8
Prediction:  21.166666666666668 Real:  20.6
Prediction:  18.3 Real:  12.6
Prediction:  33.599999999999994 Real:  36.1
Prediction:  23.75 Real:  22.9
Prediction:  22.03333333333333 Real:  22.6
Prediction:  11.5 Real:  12.8
Prediction:  11.05 Real:  13.9
Prediction:  26.0 Real:  36.2
Prediction:  20.35 Real:  23.1
Prediction:  15.9 Real:  10.9
Prediction:  18.5 Real:  22.7
Prediction:  20.633333333333333 Real:  17.8
Prediction:  14.433333333333332 Real:  12.7
Prediction:  21.166666666666668 Real:  21.4
Prediction:  29.333333333333332 Real:  32.2
Prediction:  17.200000000000003 Real:  19.7
Prediction:  19.900000000000002 Real:  19.1
Prediction:  36.849999999999994 Real:  33.3
Prediction:  17.833333333333332 Real:  19.3
Root:
root:  5 6.978
left:  12 14.399999999999999
right:  12 4.68
R2: 0.8346099666243294
MSE Bef:  1.2500000000000022
MSE Aft:  0.7500000000000021
MSE Bef:  1.4916666666666656
MSE Aft:  0.9916666666666656
MSE Bef:  1.7416666666666676
MSE Aft:  3.9219999999999984
MSE Bef:  1.0650000000000002
MSE Aft:  0.5650000000000001
MSE Bef:  1.4000000000000015
MSE Aft:  0.9000000000000015
MSE Bef:  1.4000000000000015
MSE Aft:  1.440000000000002
MSE Bef:  1.7649999999999992
MSE Aft:  1.2649999999999992
MSE Bef:  1.0866666666666673
MSE Aft:  0.5866666666666674
MSE Bef:  1.1066666666666674
MSE Aft:  1.0474999999999994
MSE Bef:  1.5474999999999994
MSE Aft:  2.068333333333337
MSE Bef:  1.7999999999999998
MSE Aft:  1.2999999999999998
MSE Bef:  1.7999999999999998
MSE Aft:  6.590000000000003
MSE Bef:  1.6516666666666646
MSE Aft:  1.1516666666666646
MSE Bef:  1.3466666666666676
MSE Aft:  0.8466666666666676
MSE Bef:  1.9983333333333322
MSE Aft:  6.807499999999999
MSE Bef:  1.0099999999999998
MSE Aft:  0.5099999999999999
MSE Bef:  1.0550000000000002
MSE Aft:  0.5950000000000005
MSE Bef:  1.5950000000000006
MSE Aft:  1.748333333333334
MSE Bef:  1.2466666666666661
MSE Aft:  0.7466666666666661
MSE Bef:  1.6066666666666642
MSE Aft:  1.1066666666666642
MSE Bef:  1.6066666666666642
MSE Aft:  3.6274999999999977
MSE Bef:  1.046666666666666
MSE Aft:  0.5466666666666659
MSE Bef:  1.0516666666666659
MSE Aft:  0.7925000000000001
MSE Bef:  1.0099999999999998
MSE Aft:  0.5099999999999999
MSE Bef:  1.0099999999999998
MSE Aft:  0.6700000000000002
MSE Bef:  1.4625000000000004
MSE Aft:  2.446666666666668
MSE Bef:  1.1266666666666667
MSE Aft:  0.6266666666666667
MSE Bef:  1.1266666666666667
MSE Aft:  1.0675000000000003
MSE Bef:  1.5675000000000003
MSE Aft:  2.0799999999999987
MSE Bef:  3.290000000000001
MSE Aft:  2.790000000000001
MSE Bef:  1.420000000000002
MSE Aft:  0.9200000000000019
MSE Bef:  1.0650000000000008
MSE Aft:  0.5650000000000008
MSE Bef:  1.4850000000000028
MSE Aft:  7.415000000000002
MSE Bef:  1.140000000000001
MSE Aft:  0.6400000000000011
MSE Bef:  2.58666666666667
MSE Aft:  2.5186666666666713
MSE Bef:  1.0466666666666669
MSE Aft:  0.5466666666666669
MSE Bef:  1.0466666666666669
MSE Aft:  0.7100000000000006
MSE Bef:  1.0066666666666668
MSE Aft:  0.5066666666666668
MSE Bef:  1.2666666666666664
MSE Aft:  0.8199999999999998
MSE Bef:  1.5300000000000005
MSE Aft:  3.4662857142857244
MSE Bef:  1.1249999999999996
MSE Aft:  0.6249999999999997
MSE Bef:  1.1249999999999996
MSE Aft:  1.0475
MSE Bef:  4.754166666666662
MSE Aft:  5.76666666666666
MSE Bef:  1.52
MSE Aft:  1.02
MSE Bef:  1.525
MSE Aft:  2.714999999999997
MSE Bef:  1.0050000000000001
MSE Aft:  0.5050000000000001
MSE Bef:  1.0050000000000001
MSE Aft:  0.5275000000000007
MSE Bef:  1.0275000000000007
MSE Aft:  0.7480000000000011
MSE Bef:  1.0466666666666669
MSE Aft:  0.5466666666666669
MSE Bef:  1.294666666666668
MSE Aft:  2.3674999999999997
MSE Bef:  1.1800000000000008
MSE Aft:  0.6800000000000008
MSE Bef:  1.1800000000000008
MSE Aft:  2.119999999999999
MSE Bef:  1.8533333333333326
MSE Aft:  1.3533333333333326
MSE Bef:  2.2999999999999994
MSE Aft:  4.7399999999999975
MSE Bef:  2.7050000000000023
MSE Aft:  2.2050000000000023
MSE Bef:  1.9799999999999986
MSE Aft:  1.4799999999999986
MSE Bef:  1.9799999999999986
MSE Aft:  7.36
MSE Bef:  1.2049999999999994
MSE Aft:  0.7049999999999994
MSE Bef:  1.2049999999999994
MSE Aft:  2.267499999999999
MSE Bef:  3.8099999999999996
MSE Aft:  3.3099999999999996
MSE Bef:  4.85
MSE Aft:  18.039999999999996
MSE Bef:  1.8666666666666665
MSE Aft:  1.3666666666666665
MSE Bef:  1.106666666666667
MSE Aft:  0.6066666666666669
MSE Bef:  1.9733333333333334
MSE Aft:  6.6320000000000014
MSE Bef:  1.0066666666666666
MSE Aft:  0.5066666666666666
MSE Bef:  2.131666666666667
MSE Aft:  1.7325000000000002
MSE Bef:  1.2466666666666675
MSE Aft:  0.7466666666666674
MSE Bef:  7.133333333333335
MSE Aft:  6.633333333333334
MSE Bef:  7.380000000000001
MSE Aft:  20.69833333333333
MSE Bef:  1.0099999999999996
MSE Aft:  0.5099999999999996
MSE Bef:  1.0099999999999996
MSE Aft:  2.7599999999999993
MSE Bef:  1.0400000000000005
MSE Aft:  0.5400000000000005
MSE Bef:  5.845000000000004
MSE Aft:  6.317000000000004
MSE Bef:  1.0599999999999987
MSE Aft:  0.5599999999999988
MSE Bef:  1.1399999999999997
MSE Aft:  0.7599999999999996
MSE Bef:  1.2599999999999996
MSE Aft:  1.6133333333333326
MSE Bef:  1.0399999999999998
MSE Aft:  0.5399999999999997
MSE Bef:  1.06
MSE Aft:  0.9200000000000016
MSE Bef:  1.4650000000000019
MSE Aft:  4.378333333333337
MSE Bef:  3.5716666666666654
MSE Aft:  3.0716666666666654
MSE Bef:  3.5716666666666654
MSE Aft:  14.727999999999994
MSE Bef:  1.0
MSE Aft:  2.46875
MSE Bef:  2.6900000000000066
MSE Aft:  2.1900000000000066
MSE Bef:  1.2000000000000015
MSE Aft:  0.7000000000000014
MSE Bef:  1.2000000000000015
MSE Aft:  2.1399999999999997
MSE Bef:  2.459999999999993
MSE Aft:  1.959999999999993
MSE Bef:  1.9399999999999953
MSE Aft:  1.4399999999999955
MSE Bef:  4.584999999999997
MSE Aft:  10.433000000000014
MSE Bef:  2.446666666666669
MSE Aft:  1.946666666666669
MSE Bef:  1.9999999999999978
MSE Aft:  1.4999999999999978
MSE Bef:  3.4466666666666668
MSE Aft:  19.93550000000002
Prediction:  16.1 Real:  15.0
Prediction:  17.05 Real:  18.0
Prediction:  15.883333333333333 Real:  14.9
Prediction:  12.066666666666666 Real:  14.1
Prediction:  24.825 Real:  25.3
Prediction:  18.05 Real:  15.6
Prediction:  50.0 Real:  50.0
Prediction:  18.96666666666667 Real:  14.5
Prediction:  19.450000000000003 Real:  16.6
Prediction:  17.05 Real:  15.6
Prediction:  27.65 Real:  23.7
Prediction:  14.833333333333332 Real:  17.8
Prediction:  11.5 Real:  11.5
Prediction:  23.2 Real:  21.4
Prediction:  14.133333333333335 Real:  12.7
Prediction:  23.0 Real:  24.8
Prediction:  25.5 Real:  21.2
Prediction:  17.200000000000003 Real:  23.7
Prediction:  15.883333333333333 Real:  16.4
Prediction:  19.816666666666666 Real:  19.6
Prediction:  18.96666666666667 Real:  18.3
Prediction:  16.1 Real:  21.7
Prediction:  20.633333333333333 Real:  29.8
Prediction:  18.96666666666667 Real:  20.2
Prediction:  23.9 Real:  22.9
Prediction:  19.816666666666666 Real:  15.3
Prediction:  18.2 Real:  18.3
Prediction:  6.466666666666667 Real:  10.2
Prediction:  24.96666666666667 Real:  34.9
Prediction:  14.133333333333335 Real:  15.2
Prediction:  24.51875 Real:  23.3
Prediction:  20.6 Real:  20.5
Prediction:  6.466666666666667 Real:  10.5
Prediction:  9.6 Real:  15.2
Prediction:  16.8 Real:  23.2
Prediction:  23.9 Real:  23.7
Prediction:  50.0 Real:  50.0
Prediction:  28.6 Real:  27.1
Prediction:  24.51875 Real:  37.0
Prediction:  19.450000000000003 Real:  23.1
Prediction:  12.066666666666666 Real:  14.9
Prediction:  22.549999999999997 Real:  19.2
Prediction:  20.4 Real:  11.9
Prediction:  17.833333333333332 Real:  17.5
Prediction:  22.241666666666667 Real:  21.7
Prediction:  20.4 Real:  27.5
Prediction:  15.9 Real:  13.8
Prediction:  20.4 Real:  20.6
Prediction:  19.816666666666666 Real:  21.8
Prediction:  20.4 Real:  18.6
Prediction:  19.816666666666666 Real:  17.6
Prediction:  19.2 Real:  23.4
Prediction:  12.066666666666666 Real:  11.7
Prediction:  16.1 Real:  14.6
Prediction:  19.450000000000003 Real:  20.1
Prediction:  23.25 Real:  19.9
Prediction:  19.6 Real:  21.7
Prediction:  22.549999999999997 Real:  21.6
Prediction:  9.900000000000002 Real:  15.1
Prediction:  26.0 Real:  20.3
Prediction:  24.825 Real:  29.1
Prediction:  44.5 Real:  50.0
Prediction:  18.05 Real:  16.0
Prediction:  34.75 Real:  43.1
Prediction:  32.75 Real:  32.7
Prediction:  17.200000000000003 Real:  18.5
Prediction:  16.6 Real:  17.9
Prediction:  22.858333333333334 Real:  23.2
Prediction:  16.1 Real:  19.1
Prediction:  22.858333333333334 Real:  24.4
Prediction:  28.1875 Real:  30.1
Prediction:  24.51875 Real:  28.0
Prediction:  14.133333333333335 Real:  19.5
Prediction:  12.225000000000001 Real:  13.8
Prediction:  35.29166666666666 Real:  34.7
Prediction:  20.575 Real:  22.6
Prediction:  19.6 Real:  18.8
Prediction:  22.549999999999997 Real:  22.6
Prediction:  38.7 Real:  42.8
Prediction:  23.85 Real:  22.4
Prediction:  20.866666666666667 Real:  20.4
Prediction:  23.9 Real:  27.0
Prediction:  20.866666666666667 Real:  20.6
Prediction:  44.5 Real:  37.6
Prediction:  23.2 Real:  22.2
Prediction:  15.883333333333333 Real:  13.5
Prediction:  21.7 Real:  20.1
Prediction:  22.241666666666667 Real:  20.9
Prediction:  24.96666666666667 Real:  29.6
Prediction:  19.6 Real:  19.5
Prediction:  19.816666666666666 Real:  22.8
Prediction:  15.883333333333333 Real:  13.4
Prediction:  20.4 Real:  23.1
Prediction:  23.0 Real:  23.0
Prediction:  34.75 Real:  33.2
Prediction:  23.25 Real:  20.8
Prediction:  19.2 Real:  18.5
Prediction:  19.6 Real:  20.5
Prediction:  14.833333333333332 Real:  13.8
Prediction:  15.9 Real:  12.7
Prediction:  6.466666666666667 Real:  8.8
Prediction:  24.51875 Real:  26.6
Prediction:  16.1 Real:  13.8
Prediction:  28.1875 Real:  26.7
Prediction:  23.975 Real:  22.2
Prediction:  20.4 Real:  19.4
Prediction:  24.3 Real:  23.9
Prediction:  45.65 Real:  50.0
Prediction:  12.066666666666666 Real:  9.5
Prediction:  9.900000000000002 Real:  13.6
Prediction:  23.25 Real:  20.2
Prediction:  29.958333333333336 Real:  31.2
Prediction:  16.858333333333334 Real:  19.3
Prediction:  13.466666666666667 Real:  19.4
Prediction:  28.1875 Real:  29.9
Prediction:  12.066666666666666 Real:  9.6
Prediction:  23.85 Real:  22.0
Prediction:  32.15 Real:  32.0
Prediction:  32.75 Real:  34.9
Prediction:  22.549999999999997 Real:  18.5
Prediction:  25.583333333333336 Real:  22.0
Prediction:  9.900000000000002 Real:  13.1
Prediction:  50.0 Real:  48.8
Prediction:  13.466666666666667 Real:  17.8
Prediction:  21.133333333333333 Real:  25.0
Prediction:  16.566666666666666 Real:  23.1
Prediction:  14.133333333333335 Real:  13.1
Prediction:  23.2 Real:  22.6
Prediction:  23.9 Real:  24.6
Prediction:  16.8 Real:  19.9
Prediction:  23.0 Real:  25.0
Prediction:  23.816666666666666 Real:  20.0
Prediction:  23.25 Real:  23.8
Prediction:  17.05 Real:  16.2
Prediction:  34.75 Real:  35.4
Prediction:  50.0 Real:  42.3
Prediction:  16.858333333333334 Real:  18.2
Prediction:  8.4 Real:  8.8
Prediction:  23.9 Real:  22.8
Prediction:  22.549999999999997 Real:  21.4
Prediction:  24.51875 Real:  26.6
Prediction:  19.450000000000003 Real:  17.5
Prediction:  12.066666666666666 Real:  14.5
Prediction:  23.9 Real:  21.6
Prediction:  16.1 Real:  12.0
Prediction:  25.5 Real:  24.5
Prediction:  9.900000000000002 Real:  10.5
Prediction:  11.5 Real:  9.7
Prediction:  34.75 Real:  31.0
Prediction:  12.066666666666666 Real:  11.8
Prediction:  22.083333333333336 Real:  20.6
Prediction:  18.05 Real:  12.6
Prediction:  34.75 Real:  36.1
Prediction:  25.5 Real:  22.9
Prediction:  20.866666666666667 Real:  22.6
Prediction:  11.5 Real:  12.8
Prediction:  12.225000000000001 Real:  13.9
Prediction:  26.0 Real:  36.2
Prediction:  19.6 Real:  23.1
Prediction:  15.9 Real:  10.9
Prediction:  18.96666666666667 Real:  22.7
Prediction:  20.633333333333333 Real:  17.8
Prediction:  15.883333333333333 Real:  12.7
Prediction:  22.083333333333336 Real:  21.4
Prediction:  31.21666666666667 Real:  32.2
Prediction:  17.200000000000003 Real:  19.7
Prediction:  19.450000000000003 Real:  19.1
Prediction:  35.29166666666666 Real:  33.3
Prediction:  17.833333333333332 Real:  19.3
R2: 0.8449562956155273
```

**haberman**
```
C:\Users\Ricky\AppData\Local\Programs\Python\Python37\python.exe "C:\Program Files\JetBrains\PyCharm 2019.3.4\plugins\python\helpers\pydev\pydevconsole.py" --mode=client --port=52818
import sys; print('Python %s on %s' % (sys.version, sys.platform))
sys.path.extend(['C:\\Resources\\github\\OnlineCodes\\ML', 'C:/Resources/github/OnlineCodes/ML'])
PyDev console: starting.
Python 3.7.4 (tags/v3.7.4:e09359112e, Jul  8 2019, 20:34:20) [MSC v.1916 64 bit (AMD64)] on win32
runfile('C:/Resources/github/OnlineCodes/ML/project2/DecisionTree.py', wdir='C:/Resources/github/OnlineCodes/ML/project2')
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Before Pruning Accuracy:  0.6470588235294118
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  2
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  2
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  2 Real:  2
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
Prediction:  1 Real:  1
Prediction:  2 Real:  1
Prediction:  1 Real:  1
After Pruning Accuracy:  0.7450980392156863
```