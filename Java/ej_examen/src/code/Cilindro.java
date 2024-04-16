package code;

/*
 * Radio
 * altura
 * color
 */

public class Cilindro {
	int radio;
	int altura;
	String color;
	
	
	public Cilindro(int radio, int altura, String color) {
		this.radio = radio;
		this.altura = altura;
		this.color = color;
	}
	
	
	public int getRadio() {
		return radio;
	}
	public void setRadio(int radio) {
		this.radio = radio;
	}
	public int getAltura() {
		return altura;
	}
	public void setAltura(int altura) {
		this.altura = altura;
	}
	public String getColor() {
		return color;
	}
	public void setColor(String color) {
		this.color = color;
	}
	
	
	public double devuelveArea() {
		return Math.PI*Math.pow(radio, 2) + 2*Math.PI*radio*altura;
	}
	
	public double devuelveLongitud() {
		return Math.PI*altura*Math.pow(radio, 2);
	}
}
