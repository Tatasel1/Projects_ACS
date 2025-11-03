import numpy as np

def CROUT(A):
    n = A.shape[0]
    L = np.zeros((n, n))
    U = np.eye(n)

    for i in range(n):
        L[i, 0] = A[i, 0]

    for j in range(1, n):
        U[0,j] = A[0,j] / L[0,0]

   

    for k in range(1, n):
        for i in range(k, n):
            sum=0
            for l in range(k):
                sum += (L[i,l] * U[l,k])
            L[i,k] =A[i,k]- sum

        if k == n-1:
            break

        for j in range(k+1, n):
            sum2=0
            for l in range(k):
                sum2 += L[k,l] * U[l,j]
            U[k,j] = (A[k,j] - sum2) / L[k,k]

    return L,U

A = np.array([
    [4, 3, 2],
    [6, 3, 1],
    [2, 1, 3]
], dtype=float)

L, U = CROUT(A)

print("Matricea L:")
print(L)
print("\nMatricea U:")
print(U)
