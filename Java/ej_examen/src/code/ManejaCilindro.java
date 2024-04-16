package code;

import java.util.Scanner;

public class ManejaCilindro {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		Cilindro miCilindro;
		miCilindro = new Cilindro(10, 15, "rojo");
		
		System.out.println("El area del cilindro es " + miCilindro.devuelveArea());
		System.out.println("La longitud del cilindro es " + miCilindro.devuelveLongitud());
		
		System.out.println("Escribe el nuevo color: ");
		miCilindro.setColor(entrada.nextLine());
		
		System.out.println("El nuevo color es: " + miCilindro.getColor()); }

}
