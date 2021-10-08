import java.time.LocalDate;
import java.time.Period;

public class Pessoa {
	// private - � um modificador de acesso
	// garante que apenas m�todos desta classe possam alterar este atributo
	// aumenta o encapsulamento, a seguran�a da classe
	private String nome;
	private String nickName; 
	private Endereco endereco;
	private LocalDate dataNascimento;
	
	// adicionar 2 construtores completo, alterar os demais
	// get (2 versoes) e set (2 vers�es)
	// getIdade (ano est�, m�s e dia)
	
	// sobrecarga do m�todo construtor
	// temos agora 3 op��es para criar objetos do tipo pessoa
	// overload o nome � igual e a assinatura � diferente
	// assinatura � o conjunto de par�metros
	public Pessoa () {
		super();
		nome = "Sem nome";
		nickName = "Sem apelido";
		endereco = new Endereco();
		dataNascimento = LocalDate.of(1900, 1, 1); // default para n�o null
	}
	
	public Pessoa (String nome) {
		super();
		this.nome = nome;
		this.nickName = "Sem apelido";
		endereco = new Endereco();		
		dataNascimento = LocalDate.of(1900, 1, 1); // default para n�o null
	}
	
	public Pessoa(String nome, String nickName) {
		super(); // chamado ao construtor da super classe, neste caso construtor da Objet()
		this.nome = nome;
		// o this referencia este objeto
		// atribuindo o nome que veio como par�metro para o atributo
		this.nickName = nickName;
		endereco = new Endereco();
		dataNascimento = LocalDate.of(1900, 1, 1); // default para n�o null
	}

	public Pessoa(String nome, Endereco endereco) {
		super();
		this.nome = nome;
		this.nickName = "Sem apelido";
		this.endereco = endereco;
		dataNascimento = LocalDate.of(1900, 1, 1); // default para n�o null
	}
	
	public Pessoa(String nome, String nickName, Endereco endereco) {
		super();
		this.nome = nome;
		this.nickName = nickName;
		this.endereco = endereco;
		dataNascimento = LocalDate.of(1900, 1, 1); // default para n�o null
	}
	
	public Pessoa(String nome, String nickName, Endereco endereco, LocalDate dataNascimento) {
		super();
		this.nome = nome;
		this.nickName = nickName;
		this.endereco = endereco;
		this.dataNascimento = dataNascimento;
	}
	
	public Pessoa(String nome, String nickName, Endereco endereco, int dia, int mes, int ano) {
		super();
		this.nome = nome;
		this.nickName = nickName;
		this.endereco = endereco;
		// now no momento, of cria em data especificada nos argumentos
		this.dataNascimento = LocalDate.of(ano, mes, dia); 
	}
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		// colocaria c�digo que testa o par�metro
		// lan�ar excess�es n�o aceitando em casos que forem necess�rios
		this.nome = nome;
		// ou seja, os getters podem conter l�gica do neg�cio
		// regras de neg�cio garantindo a coer�ncia dos atributos
	}

	public String getNickName() {
		return nickName;
	}

	public void setNickName(String nickName) {
		this.nickName = nickName;
	}

	public Endereco getEndereco() {
		return endereco;
	}

	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}

	public LocalDate getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(LocalDate diaNascimento) {
		// l�gica
		this.dataNascimento = diaNascimento;
	}

	public void setDataNascimento(int dia, int mes, int ano) {
		// l�gica
		dataNascimento = LocalDate.of(ano, mes, dia);
	}
	
	public int getIdade() {
		int idade;
		LocalDate hoje = LocalDate.now();
		Period tempo = Period.between(dataNascimento, hoje);
		idade = tempo.getYears();
		return idade;
	}
	
	@Override
	public String toString() {
		String msg = "Me chamo " + nome;
		// redefinicao do metodo toString da Object
		// retornar uma informacao util que descreva textualmente o objeto
		if (nickName != "Sem apelido") {
			msg += ", mas sou realmente conhecido por " + nickName; 
		}
		return msg;
	}	

}
