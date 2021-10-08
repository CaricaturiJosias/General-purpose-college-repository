
public class Pessoa {
	private String nome;
	private String nickName;
	//sobrecarga do m�todo construtor
	//temos agora tr�s op��es para criar objetos pessoa
	//overload o nome � igual e a assinatura � diferente
	//assinatura � o conjunto de par�metros
	// objetos que podem ter diferentes entradas na constru��o
	public Pessoa() {
		super();
		this.nome = "sem nome";
		this.nickName = "sem apelido";
	}
	
	public Pessoa(String nome) {
		super();
		this.nome = nome;
		this.nickName = "sem apelido";
		
	}
	
	public Pessoa(String nome, String nickName) {
		super(); // chamado ao construtor da super classe, neste caso construtor da Objet()
		this.nome = nome;
		// o this referencia este objeto
		// atribuindo o nome que veio como par�metro para o atributo
		this.nickName = nickName;
	}

	@Override
	public String toString() {
		// redefinicao do metodo toString da Object
		// retornar uma informacao util que descreva textualmente o objeto
		return "Me chamo " + nome + ", mas sou realmente conhecido por " + nickName;
	}
	
	

	

}
