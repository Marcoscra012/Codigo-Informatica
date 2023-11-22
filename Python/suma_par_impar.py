def suma():
    total_sum_par = 0
    total_sum_impar = 0
    final_num = int(input("Hasta que número quieres sumar? "))
    for i in range(1,final_num+1):
        if i%2 == 0: total_sum_par +=i
        else: total_sum_impar +=i
    print(f'total sum par = {total_sum_par}')
    print(f'total sum impar = {total_sum_impar}')

suma()