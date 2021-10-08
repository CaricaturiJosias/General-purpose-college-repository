

public class Carro {

	private String placa;
	
	private Modelo modelo;	
	
	private Marca marca;

//////////////////////////////////////////////////////////////////////////
	//CONSTRUTORES
	
	public Carro(Marca marca, Modelo modelo, String placa){
		this.placa = placa;
		this.modelo = modelo;
		this.marca = marca;
	}
	
	public Carro(Modelo modelo, String placa) {
		this.placa = placa;
		this.modelo = modelo;
		this.marca = modelo.getMarca();
	}
	
//////////////////////////////////////////////////////////////////////////
	//NÃO CONSTRUTORES
		
	public String getPlaca() {
		return placa;
	}

	public Marca getMarca() {
		return this.marca;
	}

	public Modelo getModelo() {
		return this.modelo;
	}
}
