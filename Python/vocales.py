def vocales():
    palabra = input("Escribe una palabra: ")
    voc = ["a","e","i","o","u"]
    final = [""]

    for letra in palabra:
        if letra in voc:
            final = final.append(letra)
    print(final)

vocales()