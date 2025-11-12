def UTRIS(U,b):
    n=b.shape[0]
    x=np.zeros(n, dtype=float)
    for i in range(n-1,-1,-1):
        suma=b[i]  #pentru versiuni de Numpy mai noi b[i].item()c
        for j in range(i+1,n):
            suma=suma-U[i,j]*x[j]
        x[i]=suma/U[i,i]
    return x