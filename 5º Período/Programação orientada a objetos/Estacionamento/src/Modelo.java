public class Modelo {
	
	private String nomeModelo;

	private Marca marca;	
	
//////////////////////////////////////////////////////////////////////////
	//CONSTRUTORES
	
	public Modelo(String nomeModelo, Marca marca) {
		this.nomeModelo = nomeModelo;
		this.marca = marca;
	}
	
//////////////////////////////////////////////////////////////////////////
	//NÃO CONSTRUTORES
	
	public String getModelo() {
		return this.nomeModelo;
	}

	public Marca getMarca() {
		return this.marca;
	}
}
