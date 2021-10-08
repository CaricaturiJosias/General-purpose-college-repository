package Animal;

// ao tornar Animal uma classe abstrata ela não pode mais ser instanciada (não pode ter new)
// entretanto, ela continua possuindo construtor, pois a criação dos objetos das sub classes passam por ela
// da mesma forma, possui métodos concretos que serão executados em instâncias das sub classes
/**
 * <p>Animal é uma classe abstrata contendo o nome e o peso dos diversos tipos de animais que serão 
 * modelados na aplicação Zoo.</p>
 * 
 * <p>Esta classe demanda a implementação concreta do método fazerBarulho().</p>
 *
 *	@since 1.0
 *  @author hfebe 
 *  @see Canideo
 */
public abstract class Animal implements Comparable<Animal>{

	private String nome;
	private float peso;
	
	/**
	 * @param nome  O nome próprio do animal
	 * @param peso  O peso de animal
	 */
	public Animal(String nome, float peso) {
		// existe uma chamada a super(); construtor da Object
		this.nome = nome;
		this.peso = peso;
	}

	/**
	 * @return O nome próprio do animal
	 */
	public String getNome() {
		return nome;
	}

	/**
	 * @param nome O nome próprio do animal
	 */
	public void setNome(String nome) {
		this.nome = nome;
	}

	/**
	 * @return O peso de animal
	 */
	public float getPeso() {
		return peso;
	}

	/**
	 * @param peso O peso de animal
	 */
	public void setPeso(float peso) {
		this.peso = peso;
	}

	/**
	 * @return Devolve a string: Meu nome é nome, e meu peso é peso
	 */
	@Override
	public String toString() {
		return "Meu nome é " + nome + ", e meu peso é " + peso + " kg.";
	}

	@Override
	public int compareTo(Animal animal) {
		return nome.compareToIgnoreCase(animal.nome);
	}
	
	// método abstrato não possui código, não possui implementação
	// ele exige sua implementação na primeira classes concreta abaixo na hierarquia
	public abstract String fazerBarulho();
	
}
