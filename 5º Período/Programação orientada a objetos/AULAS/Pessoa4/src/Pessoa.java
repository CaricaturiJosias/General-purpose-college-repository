import java.time.LocalDate;
import java.time.Period;

public class Pessoa {
	// private - é um modificador de acesso
	// garante que apenas métodos desta classe possam alterar este atributo
	// aumenta o encapsulamento, a segurança da classe
	private String nome;
	private String nickName; 
	private Endereco endereco;
	private LocalDate dataNascimento;
	
	// adicionar 2 construtores completo, alterar os demais
	// get (2 versoes) e set (2 versões)
	// getIdade (ano está, mês e dia)
	
	// sobrecarga do método construtor
	// temos agora 3 opções para criar objetos do tipo pessoa
	// overload o nome é igual e a assinatura é diferente
	// assinatura é o conjunto de parâmetros
	public Pessoa () {
		super();
		nome = "Sem nome";
		nickName = "Sem apelido";
		endereco = new Endereco();
		dataNascimento = LocalDate.of(1900, 1, 1); // default para não null
	}
	
	public Pessoa (String nome) {
		super();
		this.nome = nome;
		this.nickName = "Sem apelido";
		endereco = new Endereco();		
		dataNascimento = LocalDate.of(1900, 1, 1); // default para não null
	}
	
	public Pessoa(String nome, String nickName) {
		super(); // chamado ao construtor da super classe, neste caso construtor da Objet()
		this.nome = nome;
		// o this referencia este objeto
		// atribuindo o nome que veio como parâmetro para o atributo
		this.nickName = nickName;
		endereco = new Endereco();
		dataNascimento = LocalDate.of(1900, 1, 1); // default para não null
	}

	public Pessoa(String nome, Endereco endereco) {
		super();
		this.nome = nome;
		this.nickName = "Sem apelido";
		this.endereco = endereco;
		dataNascimento = LocalDate.of(1900, 1, 1); // default para não null
	}
	
	public Pessoa(String nome, String nickName, Endereco endereco) {
		super();
		this.nome = nome;
		this.nickName = nickName;
		this.endereco = endereco;
		dataNascimento = LocalDate.of(1900, 1, 1); // default para não null
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
		// colocaria código que testa o parâmetro
		// lançar excessões não aceitando em casos que forem necessários
		this.nome = nome;
		// ou seja, os getters podem conter lógica do negócio
		// regras de negócio garantindo a coerência dos atributos
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
		// lógica
		this.dataNascimento = diaNascimento;
	}

	public void setDataNascimento(int dia, int mes, int ano) {
		// lógica
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
