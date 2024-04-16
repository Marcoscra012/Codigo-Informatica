package code;

import java.util.Scanner;

public class ManejaCirculo {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		System.out.println("Vamos a hacer un circulito");
		Circulo miCirculito;
		miCirculito = new Circulo(15, 20, 2);
		System.out.println("El area es: " + miCirculito.devuelveArea());
		System.out.println("Nuevo valor de la coord x: ");
		int nuevaCoordX = entrada.nextInt();
		miCirculito.setCoordX(nuevaCoordX);
		System.out.println("La nueva coordenada x vale: " + miCirculito.getCoordX());
	}
}