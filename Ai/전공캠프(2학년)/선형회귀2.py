import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

t_a, t_b = -1, 4
N = 200
X = np.random.normal(loc=0, scale=1, size=(N, ))
Y = t_a * X + t_b
noise = 0.3 * np.random.normal(loc=0, scale=1, size=(N, ))
Y += noise # noise추가

a, b = -2, 5
X_min, X_max = X.min(), X.max()
Y_min = a*X_min + b
Y_max = a*X_max + b

fig, ax = plt.subplots(figsize=(10, 10))
ax.scatter(X, Y, alpha=0.5)
ax.plot([X_min, X_max], [Y_min, Y_max])
ax.axvline(x=0, linestyle=':', linewidth=1)
ax.axhline(y=0, linestyle=':', linewidth=1)

learning_rate = 0.03
iteration = N
cmap = cm.get_cmap('rainbow', lut=iteration)

fig2, ax2 = plt.subplots(figsize=(10, 5))
ax2.axhline(y=t_a, linestyle=':', color='red')
ax2.axhline(y=t_b, linestyle=':', color='blue')
losses = []
for i in range(iteration):
  x, y = X[i], Y[i]
  pred = a * x + b
  J = (y - pred) ** 2
  losses.append(J)

  diff_a = 2*(y - pred)*(-x)
  diff_b = 2*(y - pred)*(-1)

  a = a - learning_rate * diff_a
  b = b - learning_rate * diff_b
  ax2.scatter(i, a, color='red')
  ax2.scatter(i, b, color='blue')

  X_min, X_max = X.min(), X.max()
  Y_min = a*X_min + b
  Y_max = a*X_max + b
  ax.plot([X_min, X_max], [Y_min, Y_max], color=cmap(i), alpha=0.5)
  
fig3, ax3 = plt.subplots(figsize=(10, 5))
ax3.plot(losses)

plt.show()