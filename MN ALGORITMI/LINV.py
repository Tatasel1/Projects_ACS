import numpy as np

def LINV(L):
    x=np.zeros_like(L)
    n=L.shape[0]
    for j in range(n):
        x[j,j]=1/L[j,j]
        if(j == n-1):
            break
        for i in range(j+1,n):
            s = 0
            for k in range(j, i):
                s += L[i, k] * x[k, j]
            x[i,j]= -s/L[i,i]
    return x
            
L = np.array([
    [2.0, 0.0, 0.0], 
    [4.0, 1.0, 0.0], 
    [6.0, 3.0, 5.0]
])

L2=LINV(L)
print(L2)

L3=np.linalg.inv(L)
print(np.round(L3,2))
    