import numpy as np
import matplotlib.pyplot as plt

img_path = './test.jpg'
img = plt.imread(img_path)
img = np.mean(img, axis=-1)
H, W = img.shape

sobel_x = np.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
sobel_y = np.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]])
img_filtered1 = np.zeros(shape=(H-2, W-2))
img_filtered2 = np.zeros(shape=(H-2, W-2))
for i in range(H-2):
  for j in range(W-2):
    window = img[i:i+3, j:j+3]
    # z = np.sum(window * sobel_x)
    z = np.abs(np.sum(window * sobel_x))
    img_filtered1[i, j] = z

    # z = np.sum(window * sobel_y)
    z = np.abs(np.sum(window * sobel_y))
    img_filtered2[i, j] = z

fig, axes = plt.subplots(1, 3, figsize=(15, 5))
axes[0].imshow(img, cmap='gray')
axes[1].imshow(img_filtered1, cmap='gray')
axes[2].imshow(img_filtered2, cmap='gray')
fig.tight_layout()
plt.show()