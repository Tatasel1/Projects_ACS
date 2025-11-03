import numpy as np

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
det=1
for k in range(n):
    det*=U[k,k]
for k in range(n-1):
    if(p[k] != k):
        det= -det
        
print(det)