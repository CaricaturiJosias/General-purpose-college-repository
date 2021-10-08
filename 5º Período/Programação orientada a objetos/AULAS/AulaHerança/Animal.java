
public class Animal {

	private String nome;
	private float peso;
	
	/**
	 * @param nome
	 * @param peso
	 */
	public Animal(String nome, float peso) {
		// existe uma chamada a super();
		this.nome = nome;
		this.peso = peso;
	}

	/**
	 * @return the nome
	 */
	public String getNome() {
		return nome;
	}

	/**
	 * @param nome the nome to set
	 */
	public void setNome(String nome) {
		this.nome = nome;
	}

	/**
	 * @return the peso
	 */
	public float getPeso() {
		return peso;
	}

	/**
	 * @param peso the peso to set
	 */
	public void setPeso(float peso) {
		this.peso = peso;
	}

	@Override
	public String toString() {
		return "Meu nome é " + nome + ", e meu peso é " + peso + " kg.";
	}
	
}
