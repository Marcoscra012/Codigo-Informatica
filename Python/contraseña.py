# Longitud > 8
# Contenga al menos 1 mayúscula
# Contenga al menos 1 minúscula
# Contenga al menos 1 número
# Contenga al menos 1 carácter especial
# No tenga espacios en blanco

contraseña = input("Ponga una contraseña: ")
validez = True

if len(contraseña) > 7:
    print(f'validez len {validez}')
    # Mayúsculas
    for i in contraseña: 
        if i.upper() == i and i.isnumeric() == False: 
            break
        else: validez = validez and False
    print(f'validez may {validez}')
    
    # Minúsculas
    for i in contraseña:
        if i.lower() == i and i.isnumeric() == False: 
            print(i)
            break
        else: validez = validez and False
    print(f'validez min {validez}')
    
    # Números
    for i in contraseña: 
        if i.isnumeric() == True: 
            break
        else: validez = validez and False
    print(f'validez num {validez}')

    # Carácter especial
    for i in contraseña: 
        if i.isalnum() == False: 
            break
        else: validez = validez and False
    print(f'validez CE {validez}')

    # Espacios
    for i in contraseña: 
        if i.isspace() == True: 
            break
        else: validez = validez and False
    print(f'validez esp {validez}')
else: validez = validez and False

print(f'validez = {validez}')

if validez == False: print("La contraseña no es válida")
else: print("La contraseña es válida")