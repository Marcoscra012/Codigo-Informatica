package code;

public class PairNums
{
	// Atributos (declarar vars)
	int num1;
	int num2;
	/*
	 * long = int largo
	 * double = float con mas decimales
	 */
	
	
	// Metodos (funciones)
	// CONSTRUCTOR (reserva memoria)
	PairNums(int num1E, int num2E)
	{
		num1 = num1E;
		num2 = num2E;
	}
	
	// LO DEMAS
	int Suma()
	{
		return num1 + num2;
	}
	
	int Resta()
	{
		return num1 - num2;
	}
	
	int Multiplicacion()
	{
		return num1 * num2;
	}
	
	float Division() 
	{
		return num1 / num2;
		
	}
}