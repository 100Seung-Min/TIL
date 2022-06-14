import numpy as np

a = 3
b = [1, 2, 3]
a = np.array(a)
b = np.array(b)
# print(a + b)

a = np.random.randint(0, 5, size=(3,4))
b = np.random.randint(0, 5, size=(1, 4))
# print(a)
# print(b)
# print(a + b)

n_centroid = 5
n_data = 100
centroids = np.random.randint(0, 10, (n_centroid, 2))
data = np.random.randint(0, 10, (n_data, 2))

for sample in data:
  x, y = sample[0], sample[1]
  for centroid in centroids:
    centroid_x, centroid_y = centroid[0], centroid[1]
    distance = np.sqrt((x - centroid_x)**2 + (y-centroid_y)**2)

for sample in data:
  sample = sample.reshape((1, 2))
  distance = np.power(sample - centroids, 2)
  distance = np.sum(distance, axis=-1)
  distance = np.sqrt(distance)

centroids = centroids.reshape((1, n_centroid, 2))
data = data.reshape((n_data, 1, 2))

distances = (centroids - data)**2
distances = np.sum(distances, -1)
distances = np.sqrt(distances)
print(distances.shape)

data1 = np.random.normal(0, 1, (100, 2))
data2 = np.random.normal(0, 1, (200, 2))
data3 = np.random.normal(0, 1, (300, 2))

data1 = data1.reshape((1, 1, 100, 2))
data2 = data2.reshape((1, 200, 1, 2))
data3 = data3.reshape((300, 1, 1, 2))