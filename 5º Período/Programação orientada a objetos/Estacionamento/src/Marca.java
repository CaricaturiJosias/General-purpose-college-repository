import java.util.ArrayList;
import java.util.Iterator;

public class Marca {

	private String nomeMarca;
	private ArrayList<Modelo> modelos = null;
	
//////////////////////////////////////////////////////////////////////////
	// CONSTRUTORES
	public Marca(String nome) {
		this.nomeMarca = nome;
		this.modelos = new ArrayList<Modelo>();
	}
	
	public Marca(String nome, Modelo modelo) {
		this.nomeMarca = nome;
		this.modelos.add(modelo);
	}
	
//////////////////////////////////////////////////////////////////////////
	//métodos não construtores
	
	public String getMarca() {
		return this.nomeMarca;
	}
	
	public void getModelosDaMarca() {
		if (this.modelos != null) {
			Iterator<Modelo> modelos = this.modelos.iterator();
			while(modelos.hasNext()) {
				Modelo modelo = modelos.next();
				System.out.println(this.modelos.indexOf(modelo)+" - "+modelo.getModelo());
			}
		}
	}
	public ArrayList<Modelo> getModelosMarca() {
		ArrayList<Modelo> Saida = new ArrayList<Modelo>();
		if (this.modelos != null) {
			Iterator<Modelo> modelos = this.modelos.iterator();
			while(modelos.hasNext()) {
				Saida.add(modelos.next());
			}
		}
		return Saida;
	}
	
	public void setModelo(Modelo modelo) {
		this.modelos.add(modelo);
	}
}
