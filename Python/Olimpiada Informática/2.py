#ENTRADA PROPORCIONADA:
num_de_casos = 2
num_de_esbirros_1 = 6
esbirros_1 = [2, 4, 6, 8], [2, 3, 4, 5], [5, 7, 7, 9], [2, 8, 3, 7], [6, 6, 4, 6], [2, 6, 4, 8]
num_de_esbirros_2 = 4
esbirros_2 = [1, 3, 5, 7], [3, 4, 2, 5], [5, 8, 7, 9], [2, 5, 4, 6]

i = 0 #control del numero de casos
n = 0 #control del numero de esbirros
a = 0
b = 0

while i < num_de_casos:
    if i == 0: #Primer grupo de esbirros
        while n < num_de_esbirros_1 - 1:
            if esbirros_1[n][0] <= esbirros_1[n][2] and esbirros_1[n][1] >= esbirros_1[n][3]: #El horario de mañana incluye el de tarde
                a += 1
            elif esbirros_1[n][2] <= esbirros_1[n][0] and esbirros_1[n][3] >= esbirros_1[n][1]: #El horario de tarde implica el de mañana
                a += 1
            n += 1
    n = 0
    if i == 1: #Segundo grupo de esbirros
        while n < num_de_esbirros_2 - 1:
            if esbirros_2[n][0] <= esbirros_2[n][2] and esbirros_2[n][1] >= esbirros_2[n][3]: #El horario de mañana incluye el de tarde
                b += 1
            elif esbirros_2[n][2] <= esbirros_2[n][0] and esbirros_2[n][3] >= esbirros_2[n][1]: #El horario de tarde implica el de mañana
                b += 1
            n += 1
    
    i += 1
print(a, b)