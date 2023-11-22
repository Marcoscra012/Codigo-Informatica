n1 = int(input("Introduce un numero: "))
n2 = int(input("Introduce un numero: "))
print("Sumar\nRestar\nMultiplicar\nDividir")
op = input("Qué quieres hacer?: ")

def suma(a, b): return(a+b)
def resta(a, b): return(a-b)
def multiplicación(a, b): return(a*b)
def división(a, b): return(a/b)

if op == "Sumar": print(suma(n1, n2))
elif op == "Restar": print(resta(n1, n2))
elif op == "Multiplicar": print(multiplicación(n1, n2))
elif op == "Dividir": print(división(n1, n2))