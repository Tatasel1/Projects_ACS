import numpy as np
import math as mth
rng = np.random.default_rng(0)

# ----------- Input ---------------------------
#  !! Sectiunea Input nu se modifica !!
m = 7 # nr de linii
n = 4 # nr de coloane
A = rng.integers(1,11, size=(m,n))
A = np.triu(A,-1)
A[m-1,:] = rng.integers(1,10, size=(1,n))
A = A.astype(float)
b = rng.integers(10, size=(m,1)).astype(float)
#-----------------------------------------------
print('------------A-------------\n', A)
print('------------b-------------\n', b.T)

def TORT(A):
  p=min(m-1,n)
  beta=np.zeros(p)
  U=np.copy(A)
  for k in range(p):
    sigma=np.sign(A[k,k])*mth.sqrt(A[k,k]*A[k,k]+A[k+1,k]*A[k+1,k]+A[m-1,k]*A[m-1,k])
    if sigma==0:
      beta[k]=0
    else:
      U[k,k]=A[k,k]+sigma
      U[k+1,k]=A[k+1,k]
      U[m-1,k]=A[m-1,k]
      beta[k]=sigma*U[k,k]
      A[k,k]= -sigma
      A[k+1,k]=0
      A[m-1,k]=0
      for j in range(k+1,n):
        tau=(U[k,k]*A[k,j]+U[k+1,k]*A[k+1,j]+U[m-1,k]*A[m-1,j])/beta[k]
        A[k,j]=A[k,j]-tau*U[k,k]
        A[k+1,j]=A[k+1,j]-tau*U[k+1,k]
        A[m-1,j]=A[m-1,j]-tau*U[m-1,k]
        
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


print(U)
print(R)
print(beta)

for k in range(n):
  tau=(U[k,k]*b[k]+U[k+1,k]*b[k+1]+U[m-1,k]*b[m-1])/beta[k]
  b[k]-=tau*U[k,k]
  b[k+1]-=tau*U[k+1,k]
  b[m-1]-=tau*U[m-1,k]

x=UTRIS(R[0:n,:],b[0:n])

x2=np.linalg.pinv(A)@b

print(x)

print(x2)

