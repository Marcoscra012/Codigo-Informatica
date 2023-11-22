# Que pida un numero de 3 o mas cifras
# Te devuelva la suma de sus cifras

num = str(input("Escribe un numero: "))
final = 0

for i in range (0, int(len(num))):
    final += int(num[i])

print(final)