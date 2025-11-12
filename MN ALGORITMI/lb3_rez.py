import numpy as np

A = np.load("key_odd.npy")
b = np.load("msg_odd.npy")

print(f"Vizualizare A: \n {A}")

sol = np.linalg.inv(np.copy(A))@np.copy(b)

def Crout(A):
    n = len(A)
    U = np.eye(n)
    L = np.zeros((n,n))

    L[0,0] = A[0,0]
    L[n-1,0] = A[n-1,0]
    for j in range(1,n):
        U[0,j] = A[0,j]/L[0,0]
    for k in range(1,n):
        L[n-1,k] = A[n-1,k]- L[n-1,0]*U[0,k]
        if k == n-1:
            break
        L[k,k] = A[k,k]


    return L, U

[Ll, Uu] = Crout(np.copy(A))
print('----------- L ---------------')
print(Ll)
print('----------- U ---------------')
print(Uu)
print('----------- A ---------------')
print(Ll @ Uu)

def LTRIS(L,b):
        n = len(L)
        y = np.zeros((n,1))
        for i in range(n-1):
            y[i] = b[i]/L[i,i]
        t =b[n-1]
        for j in range(n-1):
            t = t - L[n-1,j]*y[j]
        y[n-1] = t/L[n-1,n-1]
        return y

def UTRIS(U,y):
    n = len(U)
    x = np.copy(y)
    for j in range(1,n):
        x[0] = x[0] -U[0][j]*x[j]
    return x

y =LTRIS(Ll,b)
print(y)
x = UTRIS(Uu,y)

print('----------x------------')
print(x)

print('------------sol----------')
print(sol)
