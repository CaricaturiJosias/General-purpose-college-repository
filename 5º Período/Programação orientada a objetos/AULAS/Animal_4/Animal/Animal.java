package Animal;

// ao tornar Animal uma classe abstrata ela n�o pode mais ser instanciada (n�o pode ter new)
// entretanto, ela continua possuindo construtor, pois a cria��o dos objetos das sub classes passam por ela
// da mesma forma, possui m�todos concretos que ser�o executados em inst�ncias das sub classes
/**
 * <p>Animal � uma classe abstrata contendo o nome e o peso dos diversos tipos de animais que ser�o 
 * modelados na aplica��o Zoo.</p>
 * 
 * <p>Esta classe demanda a implementa��o concreta do m�todo fazerBarulho().</p>
 *
 *	@since 1.0
 *  @author hfebe 
 *  @see Canideo
 */
public abstract class Animal implements Comparable<Animal>{

	private String nome;
	private float peso;
	
	/**
	 * @param nome  O nome pr�prio do animal
	 * @param peso  O peso de animal
	 */
	public Animal(String nome, float peso) {
		// existe uma chamada a super(); construtor da Object
		this.nome = nome;
		this.peso = peso;
	}

	/**
	 * @return O nome pr�prio do animal
	 */
	public String getNome() {
		return nome;
	}

	/**
	 * @param nome O nome pr�prio do animal
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
	 * @return Devolve a string: Meu nome � nome, e meu peso � peso
	 */
	@Override
	public String toString() {
		return "Meu nome � " + nome + ", e meu peso � " + peso + " kg.";
	}

	@Override
	public int compareTo(Animal animal) {
		return nome.compareToIgnoreCase(animal.nome);
	}
	
	// m�todo abstrato n�o possui c�digo, n�o possui implementa��o
	// ele exige sua implementa��o na primeira classes concreta abaixo na hierarquia
	public abstract String fazerBarulho();
	
}
