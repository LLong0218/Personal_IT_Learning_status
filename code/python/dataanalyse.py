# 导入模块
import pandas as pd
import matplotlib.pyplot as plt

# 读取文件进行处理
df = pd.read_excel("/Users/survey/数据分析课程调研.xlsx",usecols=[0,3,4,5,6,7,8,9,10,26],skiprows=[1])
df.drop(index = df[df['答题时长']<5].index,inplace = True)

# 对问卷答案进行可视化
plt.figure(1)

plt.subplot2grid((2,3),(0,0),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[2]].isnull()].index)
result1 = df1[list(df.columns)[2]].groupby(df[list(df.columns)[2]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[2])

plt.subplot2grid((2,3),(0,1),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[3]].isnull()].index)
result1 = df1[list(df.columns)[3]].groupby(df[list(df.columns)[3]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[3])

plt.subplot2grid((2,3),(0,2),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[4]].isnull()].index)
result1 = df1[list(df.columns)[4]].groupby(df[list(df.columns)[4]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[4])

plt.subplot2grid((2,3),(1,0),colspan=2,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[5]].isnull()].index)
result1 = df1[list(df.columns)[5]].groupby(df[list(df.columns)[5]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[5])

plt.subplot2grid((2,3),(1,2),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[6]].isnull()].index)
result1 = df1[list(df.columns)[6]].groupby(df[list(df.columns)[6]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[6])


plt.tight_layout()
plt.show()






# 对问题进行可视化
plt.figure(2)

plt.subplot2grid((3,3),(0,0),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[7]].isnull()].index)
result1 = df1[list(df.columns)[7]].groupby(df[list(df.columns)[7]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[7])

data1 = pd.read_excel("/Users/survey/数据分析课程调研.xlsx",usecols=[3,11,12,13,14,15,16],skiprows=1)
data1.drop(index = data1[data1["Unnamed: 3"]<5].index,inplace = True)
data1.drop("Unnamed: 3", axis=1,inplace = True)
data1.drop(index = data1[data1['Excel'].isnull()].index , inplace = True)
plt.subplot2grid((3,3),(0,1),colspan=2,rowspan=1)
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(data1.sum().index , data1.sum().values)
plt.title("Q8_您现在进行数据分析，会用到的工具是？（多选）")

plt.subplot2grid((3,3),(1,0),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[8]].isnull()].index)
result1 = df1[list(df.columns)[8]].groupby(df[list(df.columns)[8]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[8])

data2 = pd.read_excel("/Users/survey/数据分析课程调研.xlsx",usecols=[3,17,18,19,20,21],skiprows=1)
data2.drop(index = data2[data2["Unnamed: 3"]<5].index,inplace = True)
data2.drop("Unnamed: 3", axis=1,inplace = True)
data2.drop(index = data2[data2['步骤繁多，重复操作'].isnull()].index , inplace = True)
plt.subplot2grid((3,3),(1,1),colspan=2,rowspan=1)
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(data2.sum().index , data2.sum().values)
plt.title("Q9_基于目前的工具进行数据分析，会出现的问题是？（多选）")

plt.subplot2grid((3,3),(2,0),colspan=1,rowspan=1)
df1 = df.drop(index = df[df[list(df.columns)[9]].isnull()].index)
result1 = df1[list(df.columns)[9]].groupby(df[list(df.columns)[9]]).count()
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(result1.index , result1.values)
plt.title(list(df.columns)[9])

data3 = pd.read_excel("/Users/survey/数据分析课程调研.xlsx",usecols=[3,22,23,24,25],skiprows=1)
data3.drop(index = data3[data3["Unnamed: 3"]<5].index,inplace = True)
data3.drop("Unnamed: 3", axis=1,inplace = True)
data3.drop(index = data3[data3['学术目的'].isnull()].index , inplace = True)
plt.subplot2grid((3,3),(2,1),colspan=2,rowspan=1)
plt.rcParams['font.sans-serif'] = ['Arial Unicode MS']
plt.bar(data3.sum().index , data3.sum().values)
plt.title("Q10_想学习Python数据分析的目的是？")

plt.tight_layout()
plt.show()