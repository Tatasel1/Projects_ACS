def LTRIS(L,b):
    n=b.shape[0]
    x=np.zeros(n, dtype=float)
    for i in range(n):
        suma=b[i]
        for j in range(i):
            suma=suma-L[i,j]*x[j]
        x[i]=suma/L[i,i]
    return x