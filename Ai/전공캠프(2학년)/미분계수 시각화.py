import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

iteration = 20 # 업데잍 하는 횟수

cmap = cm.get_cmap('rainbow', lut=iteration)
x = np.linspace(-1, 5, 100)
y = (x-2)**2
fig, ax = plt.subplots(figsize=(10, 10))
ax.plot(x, y)

a = 4
b = (a-2)**2
ax.scatter(a, b, color='purple', s=100)

# training
learning_rate = 0.01
for i in range(iteration):
  diff = 2 * (a - 2)
  a_tmp = a - learning_rate * diff
  b_tmp = (a_tmp-2)**2

  ax.scatter(a_tmp, b_tmp, color=cmap(i))
  ax.plot([a, a_tmp], [b, b_tmp], color=cmap(i), linewidth=3)

  a = a_tmp
  b = b_tmp 

plt.show()