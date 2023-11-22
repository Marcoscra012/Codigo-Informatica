def nombreUsuario():
    nombre = input("Escribe tu nombre: ")
    apellido = input("Escribe tu apellido: ")

    username = nombre[0:3] + apellido[0:3]
    print(f' Tu nombre de usuario es {username}')

nombreUsuario()