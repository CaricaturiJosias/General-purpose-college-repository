
public class Pessoa {
	private String nome;
	private String nickName;
	//sobrecarga do método construtor
	//temos agora três opções para criar objetos pessoa
	//overload o nome é igual e a assinatura é diferente
	//assinatura é o conjunto de parâmetros
	// objetos que podem ter diferentes entradas na construção
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
		// atribuindo o nome que veio como parâmetro para o atributo
		this.nickName = nickName;
	}

	@Override
	public String toString() {
		// redefinicao do metodo toString da Object
		// retornar uma informacao util que descreva textualmente o objeto
		return "Me chamo " + nome + ", mas sou realmente conhecido por " + nickName;
	}
	
	

	

}
