import numpy as np
import matplotlib.pyplot as plt

rng = np.random.default_rng(0)
n = 6
# se creeaza o matrice cu valori aleatorii de la 1 la 99, de marime NxN
A = rng.integers(1, 100, size=(n, n))

# Pentru creerea celei de a doua matrici, fara valoare proprie dominanta, avem la dispozitie doua metode:
# I. 1. Cream o matrice diagonala D, care are aceeasi valoare pe diagonala punem aceeasi valoare in fiecare pozitie (sau similara).
#    2. Cream o matrice T, transformare de asemanare, care pastreaza spectrul de valori proprii
#    3. Construim cea de-a doua matrice cu formula B=TDT^(-1)
# II.   Cream o matrice superior/inferior triunghiulara si pe diagonala punem aceeasi valoare in fiecare pozitie (sau similara).
#       Se cunoaste faptul ca valorile proprii ale unei matrici superior/inferior triunghiulara se gasesc pe diagonala.
#
# B = [[5, 1, 6, 7, 8, 9],
#      [0, 5.0000001, 2, -1, 4, 3],
#      [0, 0, 5.0000002, 1, 6, 7],
#      [0, 0, 0, 5.0000002, 3, 8],
#      [0, 0, 0, 0, 5.0000000012, 5],
#      [0, 0, 0, 0, 0, 5.00000001]]

T = rng.integers(1, 100, size=(n, n))
D = np.diag([5, 5.0000001, 5.0000002, 5, 5.0000000012,5.0000001])
B = T.dot(D).dot(np.linalg.inv(T))

# Toleranta maxima. Aceasta trebuie sa fie mai mica de 1
tol = pow(10, -3)
maxiter = 10000
y=rng.random(n)

def MP(A,n):
    y=y/np.linalg.norm(y)
    i = 0
    e = 1
    while e > tol:
        if i > maxiter:
            print("Numar maxim de iteratii atins!")
            break
        z = A.dot(y)
        z = z/np.linalg.norm(z)
        e = np.abs(1-np.abs(z.T.dot(y)))
        y = z
        i += 1
        
    Lambda = np.divide(np.dot(A,y),y) [0]
    return z,Lambda,e,i


def MPI(A,n):
    y=rng.random(n)
    y=y/np.linalg.norm(y)
    i = 0
    e = 1
    while e > tol:
        if i > maxiter:
            print("Numar maxim de iteratii atins!")
            break
        mu = y.T.dot(A).dot(y)
        z = np.linalg.solve(mu*np.identity(n)-A,y)
        z = z/np.linalg.norm(z)
        e = np.abs(1-np.abs(z.T.dot(y)))
        y = z
        i += 1
    Lambda = np.transpose(np.power(y, i-2)).dot(A).dot(np.power(y, i-2))
    return z,Lambda,e,i