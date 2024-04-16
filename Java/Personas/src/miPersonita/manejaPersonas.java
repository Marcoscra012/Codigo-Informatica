package miPersonita;

import java.util.Scanner;

public class manejaPersonas {

	public static void main(String[] args) {
		Scanner entrada = new Scanner(System.in);
		Persona alumnos[] = new Persona[3];
		
		alumnos[0] = new Persona("Antonio", "Lopez", "Polo");
		alumnos[1] = new Persona("Manuel", "Plou", "Ledesma");
		alumnos[2] = new Persona("Juana", "de la Vega", "Prospera");
		
		for(int i = 0; i < 3; i++){
			System.out.println("Escriba la nota: ");
			alumnos[i].setNotaTIC(entrada.nextFloat());
		}
	}
}

	
