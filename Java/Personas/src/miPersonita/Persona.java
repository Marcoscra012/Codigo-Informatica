/**
 * 
 */
package miPersonita;

/**
 * Esta clase guarda informacion sobre los datos de una persona
 */
public class Persona 
{
	private String nombre;
	private String apellido1;
	private String apellido2;
	private float notaTIC;

	public Persona(String nombre, String apellido1, String apellido2, float notaTIC) {
		this.nombre = nombre;
		this.apellido1 = apellido1;
		this.apellido2 = apellido2;
		this.notaTIC = notaTIC;
	}

	public Persona(String nombre, String apellido1, String apellido2) {
		super();
		this.nombre = nombre;
		this.apellido1 = apellido1;
		this.apellido2 = apellido2;
	}

	public String getNombre() {
		return nombre;
	}

	public void setNombre(String nombre) {
		this.nombre = nombre;
	}

	public String getApellido1() {
		return apellido1;
	}

	public void setApellido1(String apellido1) {
		this.apellido1 = apellido1;
	}

	public String getApellido2() {
		return apellido2;
	}

	public void setApellido2(String apellido2) {
		this.apellido2 = apellido2;
	}

	public float getNotaTIC() {
		return notaTIC;
	}

	public void setNotaTIC(float notaTIC) {
		this.notaTIC = notaTIC;
	}

	String getNombreCompleto()
	{
		return nombre+ " " + apellido1 + " " + apellido2;
	}
}