#ENTRADA PROPORCIONADA:
num_de_casos = 2
caso_1 = [7, 1, 9, 7, 17, 10, 4, 12]
caso_2 = [1, 13,]

n = 0 #Control del numero de casos
num_mayor = 0 

while n < num_de_casos:
    if n == 0:
        for fuerza in caso_1:
            if num_mayor - fuerza < 0:
                num_mayor = fuerza
        print(num_mayor + 1)

    if n == 1:
        for fuerza in caso_2:
            if num_mayor - fuerza < 0:
                num_mayor = fuerza
        print(num_mayor + 1)
    
    num_mayor = 0
    n += 1