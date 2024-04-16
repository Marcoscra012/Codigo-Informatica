package code;

public class Circulo {
	private int coordX;
	private int coordY;
	private int radio;
	
	public Circulo(int coordX, int coordY, int radio) {
		this.coordX = coordX;
		this.coordY = coordY;
		this.radio = radio;
	}

	public int getCoordX() {
		return coordX;
	}

	public void setCoordX(int coordX) {
		this.coordX = coordX;
	}

	public int getCoordY() {
		return coordY;
	}

	public void setCoordY(int coordY) {
		this.coordY = coordY;
	}

	public int getRadio() {
		return radio;
	}

	public void setRadio(int radio) {
		this.radio = radio;
	}
}

