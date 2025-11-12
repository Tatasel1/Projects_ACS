import numpy as np
import math as mth
rng = np.random.default_rng(0)
m=3
n=2
A = rng.integers(1,11, size=(m,n)).astype(float)


def TORT(A):
    p=min(m-1,n)
    beta=np.zeros(p)
    U=np.copy(A)
    for k in range(p):
        sigma = np.sign(A[k,k]) * mth.sqrt(sum(A[i,k]**2 for i in range(k,m)))
        if sigma==0:
            beta[k]=0
        else:
            U[k,k]=A[k,k]+sigma
            for i in range(k+1,m):
                U[i,k]=A[i,k]
            beta[k]=sigma*U[k,k]
            A[k,k]= -sigma
            for i in range(k+1,m):
                A[i,k]=0
            for j in range(k+1,n):
                tau=sum(U[i,k]*A[i,j] for i in range(k,m))
                tau=tau/beta[k]
                for i in range(k,m):
                    A[i,j]=A[i,j]-tau*U[i,k]
    return U,A,beta

def UTRIS(U,b):
    n=b.shape[0]
    x=np.zeros(n, dtype=float)
    for i in range(n-1,-1,-1):
        suma=b[i]  #pentru versiuni de Numpy mai noi b[i].item()c
        for j in range(i+1,n):
            suma=suma-U[i,j]*x[j]
        x[i]=suma/U[i,i]
    return x


U,R,beta=TORT(A)
b=rng.integers(1,11, size=(m,1)).astype(float)
x=np.zeros(n, dtype=float)
for k in range(n):
    tau=sum(U[i,k]*b[i] for i in range(k,m))
    tau=tau/beta[k]
    for i in range(k,m):
        b[i]=b[i]-tau*U[i,k]
    
x=UTRIS(R[:n,:],b[:n])
print("Solutia sistemului este: ", x)

