import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

data = pd.read_csv('train.csv')
dfX = pd.DataFrame(data, columns=['Survived', 'Pclass', 'AGE', 'Fare'])
print(dfX.describe())
print(dfX.corr())
sns.pairplot(dfX[['Survived', 'Pclass', 'AGE', 'Fare']])
plt.show()