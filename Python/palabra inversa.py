test = 0
while test == 0:
    palabra = input("Escribe una palabra: ")
    try:
        int(palabra)
        print("Eso no es una palabra!")
    except:
        test = 1
        
old_id = id(palabra)
palabra = sorted(palabra.lower())

print(f'Palabra ordenada: {palabra}')

if old_id == id(palabra):
    print("ID didn't change")
    print(f'old id: {id(old_id)} || new id:: {id(palabra)}')
else: 
    print("IDs are not equal")
    print(f'old id: {id(old_id)} || new id:: {id(palabra)}')
