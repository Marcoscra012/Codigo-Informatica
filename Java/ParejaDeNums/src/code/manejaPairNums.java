package code;

import java.util.Scanner;

public class manejaPairNums {

	public static void main(String[] args) {
		int num1;
		int num2;
		
		Scanner entrada = new Scanner(System.in);
		System.out.println("\nEscriba un numero: ");
		num1 = entrada.nextInt();
		System.out.println("\nEscriba otro numero ");
		num2 = entrada.nextInt();
		
		PairNums miPareja; // miPareja es un nuevo objeto de la clase PairNums
		miPareja = new PairNums(num1, num2);
		
		System.out.println("La suma vale: ");
		System.out.println(miPareja.Suma());
		
		System.out.println("La resta vale: ");
		System.out.println(miPareja.Resta());
		
		System.out.println("La multiplicacion vale: ");
		System.out.println(miPareja.Multiplicacion());
		
		System.out.println("La division vale: ");
		System.out.println(miPareja.Division());
	}

}
