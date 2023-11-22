#ENTRADA PROPORCIONADA:
cant_cadenas_a_comparar = 2
COr1 = "aggattcaaaa" #Cadena Original 1
C1 = "ag--tac--aa" #Cadena Muestra 1
COr2 = "aaaattttccaa" #Cadena Original 2
C2 = "a-g---t--caa" #Cadena Muestra 2

bases_COr1 = []
bases_C1 = []
bases_COr2 = []
bases_C2 = []
i = 0 
n = 0

while i < cant_cadenas_a_comparar*2: #Separar las bases de sus cadenas
    if i == 0:
        for base in COr1:
            bases_COr1.append(base)
    elif i == 1:
        for base in C1:
            bases_C1.append(base)
    elif i == 2:
        for base in COr2:
            bases_COr2.append(base)
    elif i == 3:
        for base in C2:
            bases_C2.append(base)
    i += 1
i = 0

while i < cant_cadenas_a_comparar: #Comparar cada base e ignorar si es un "-"
    if i == 0:
        while n < len(bases_COr1):
            if bases_C1[n] != bases_COr1[n]:
                if bases_C1[n] == "-":
                    iguales = iguales
                else:
                    iguales = False
                    break
            elif bases_C1[n] == bases_COr1[n]:
                iguales = True
            n += 1
        i += 1
        n = 0
        if iguales == True: print("SI")
        else: print("NO")
    elif i == 1:
        while n < len(bases_COr2):
            if bases_C2[n] != bases_COr2[n]:
                if bases_C2[n] == "-":
                    iguales = iguales
                else:
                    iguales = False
                    break
            elif bases_C2[n] == bases_COr2[n]:
                iguales = True
            n += 1
        i += 1
        if iguales == True: print("SI")
        else: print("NO")