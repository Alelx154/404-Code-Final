import matplotlib.pyplot as plt
import numpy as np

xVals = []
yVals = []
#Change below filename to either linearOutFile.txt or binaryOutFile.txt
with open("linearOutFile.txt", 'r') as file:
    for line in file:
        # Split the line by comma and convert to float
        if(line.strip() != ""):
            x, y = line.strip().split(',')
            xVals.append(float(x))
            yVals.append(float(y))
xVals = np.array(xVals)
yVals = np.array(yVals)

plt.scatter(xVals, yVals, color='blue', label='Data points')
plt.xlabel('input size (n)')
plt.ylabel('execution time (ms)')
plt.title('Time Complexity')

coeffs = np.polyfit(xVals, yVals, 2)
poly_func = np.poly1d(coeffs)
x_trend = np.linspace(xVals.min(), xVals.max(), 2500)

plt.plot(x_trend, poly_func(x_trend), color='red')

plt.show()