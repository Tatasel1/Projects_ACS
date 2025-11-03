import numpy as np

def UINV(U):
    x = np.zeros_like(U,dtype=float)
    n=U.shape[0]
    for j in range(n-1, -1, -1):
        x[j, j] = 1 / U[j, j]
        if j == 0:
            break
        for i in range(j-1, -1, -1):
            s = 0
            for k in range(i+1, j+1):
                s += U[i, k] * x[k, j]
            x[i, j] = -s / U[i, i]
    return x

U=np.array([[1,2,3],
            [0,4,5],
            [0,0,6]],dtype=float)

U2 = UINV(U)
U3 = np.linalg.inv(U)
print(np.round(U2, 2))
print(np.round(U3, 2))
