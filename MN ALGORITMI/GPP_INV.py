import numpy as np

def UINV(U):
    x = np.zeros_like(U)
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

def GPP(A):
    p = list(range(n))
    M = np.zeros_like(A)
    U = np.zeros_like(A)
    for k in range(n-1):
        max_val = 0
        ik = k
        for i in range(k, n):
            if abs(A[i][k]) > max_val:
                max_val = abs(A[i][k])
                ik = i

        p[k] = ik
        if ik != k:
            A[[k, ik], :] = A[[ik, k], :]
            M[[k, ik], :] = M[[ik, k], :]

        for i in range(k + 1, n):
            M[i, k] = A[i, k] / A[k, k]
            A[i, k] = M[i, k]

        for i in range(k + 1, n):
            for j in range(k + 1, n):
                A[i, j] = A[i, j] - M[i, k] * A[k, j]

    U = np.triu(A)
    return U, M, p

A = np.array([[2, -1, 1],
              [4, 2, -2],
              [1, 1, 3]], dtype=float)
n = A.shape[0]

U, M, p = GPP(A)
X = UINV(U)

m = list(range(n))

for k in range(n-1, -1, -1):
    for i in range(k+1, n):
        m[i] = M[i, k]

    for i in range(k):
        s = 0
        for l in range(k+1, n):
            s += X[i, l] * M[l, k]
        X[i, k] -= s

    for i in range(k, n):
        s = 0
        for l in range(k+1, n):
            s += X[i, l] * M[l, k]
        X[i, k] -= s

    if p[k] != k:
        for i in range(n):
            X[i, k], X[i, p[k]] = X[i, p[k]], X[i, k]

print(X)
