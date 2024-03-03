import pandas as pd

# 使用read_csv()函数，获取文件"/Users/titanic/train.csv"，并赋值给df
df = pd.read_csv("D:\python_test_file/titanic/train.csv",encoding="utf-8")   
 
for i in [1,2,3]:
    Pclass=df[df["Pclass"]==i]["PassengerId"].count()
    # TODO 使用布尔索引、列索引和count()函数计算i船舱的总人数,并赋值给给Pclass
    Pclass_Survived=df[(df["Survived"]==1) & (df["Pclass"]==i)]["PassengerId"].count()

    # TODO 使用布尔索引、列索引和count()函数计算i船舱的存活人数,并赋值给Pclass_Survived
    Survived_rate=Pclass_Survived/Pclass

    # TODO 使用公式Pclass_Survived/Pclass，计算i号船舱的存活率，并赋值给Survived_rate
    print(f"{i}号船舱存活率是{Survived_rate}")