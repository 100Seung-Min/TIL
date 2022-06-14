import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

N = 100
cmap = cm.get_cmap('rainbow', lut=N)

fig, ax = plt.subplots(figsize=(10, 10))
for i in range(N):
  ax.scatter(i, i, color=cmap(i))
  
plt.show()