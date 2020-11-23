import numpy as np
import pandas as pd
from sklearn import svm
data = pd.read_csv('../data/watermelon_3a.csv')
X = data[['Density', 'SugarContent']]
y = data['Label'].values
linearSVModel = svm.SVC(kernel='linear', C=5000)
GaussianSVModel = svm.SVC(kernel='rbf', C=5000)
linearSVModel.fit(X, y)
GaussianSVModel.fit(X, y)
print('linearSVModel')
print(linearSVModel.support_vectors_)
print('GaussianSVModel')
print(GaussianSVModel.support_vectors_)