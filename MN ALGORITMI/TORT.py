import numpy as np

A=np.array([[4, 3, 5], [6, 3, 2]], dtype=float)
m=A.shape[0]
n=A.shape[1]


def TORT(A):
    p=min(m-1,n)
    beta=np.zeros(p)
    U=np.copy(A)
    for k in range(p):
        sigma=np.sign(A[k,k])*sum(np.sqrt(A[i,k]**2 for i in range(k,m)))
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

