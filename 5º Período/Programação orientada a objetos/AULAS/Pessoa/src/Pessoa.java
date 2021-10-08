
public class Pessoa {
	String nome;
	String nickName;
	
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
