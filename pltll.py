import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

priorities = ["Default","5", "8", "11", "14", "17", "20", "23", "26", "29", "32"]
Atime = []
Btime = []
Ctime = []

f = open('data.txt', 'r')
for row in f:
    row = row.split(' ')
    if row[0] == 'A':
        Atime.append(float(row[1]))
    elif row[0] == 'B':
        Btime.append(float(row[1]))
    elif row[0] == 'C':
        Ctime.append(float(row[1]))

dataDict = {'Priority': priorities, 'A': Atime, 'B': Btime, 'C': Ctime}
df = pd.DataFrame(dataDict)

df.plot(x='Priority', y=['A', 'B', 'C'], kind='bar')
plt.show()

# gn=np.array(Atime)
# gn=gn.astype(np.float)


# plt.hist(gn)
# plt.show()


# gn2=np.array(Btime)
# gn2=gn2.astype(np.float)

# plt.hist(gn2)
# plt.show()
# gn3=np.array(Ctime)
# gn3=gn3.astype(np.float)
# plt.hist(gn3)

# plt.show()



# plt.bar(priorities, Atime, color='g', label='File Data')


# plt.xlabel('Priorities', fontsize=12)
# plt.ylabel('Times', fontsize=12)

# plt.legend()
# plt.show()

# plt.bar(priorities, Btime, color='b', label='File Data')
# plt.xlabel('Priorities', fontsize=12)
# plt.ylabel('Times', fontsize=12)

# plt.legend()
# plt.show()



# plt.bar(priorities, Ctime, color='r', label='File Data')
# plt.xlabel('Priorities', fontsize=12)
# plt.ylabel('Times', fontsize=12)

# plt.legend()
# plt.show()
# #print("cheh")
