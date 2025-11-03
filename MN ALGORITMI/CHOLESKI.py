import numpy as np

A = np.array([
    [4, 2, 2],
    [2, 5, 1],
    [2, 1, 3]
])


def CHOL(A):
    n = A.shape[0]
    L = np.zeros((n, n))
    
    if A[0, 0] <= 0:
        print("A nu e pozitiv definita")
        return 0
    
    L[0, 0] = np.sqrt(A[0, 0])
    
    for i in range(1, n):
        L[i, 0] = A[i, 0] / L[0, 0]
    
    for k in range(1, n):
        s = 0
        for j in range(k):
            s += L[k, j] * L[k, j]
        
        lmbd = A[k, k] - s
        
        if lmbd <= 0:
            print("A nu e pozitiv definita")
            return 0
        
        L[k, k] = np.sqrt(lmbd)
        
        if k == n:
            break
        
        for i in range(k + 1, n):
            sum_val = 0
            for l in range(k):
                sum_val += L[i, l] * L[k, l]
            L[i, k] = (A[i, k] - sum_val) / L[k, k]
    
    return L

L = CHOL(A)
print(L)
