import numpy as np
import pandas as pd
from sklearn import svm
data = pd.read_csv('../data/watermelon_3a.csv')
X = data['Density'].values.reshape((data.shape[0], 1))
y = data['SugarContent']
model = svm.SVR()
model.fit(X, y)
print('LOSS:', np.sqrt(np.sum(np.square(model.predict(X) - y))))
