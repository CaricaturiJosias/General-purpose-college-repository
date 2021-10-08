import java.time.LocalDate;
import java.time.Period;
import java.time.format.DateTimeFormatter;

public class Pessoa implements Comparable<Pessoa> {
	// interface Comparable<Pessoa> exige o m�todo compareTo
	// com isso, pode ser usada para ordena��o natural
	private String nome;
	private String nickName; 
	private Endereco endereco;
	private LocalDate dataNascimento;
		
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
	
	public Pessoa(String nome, String nickName, int dia, int mes, int ano) {
		this(nome, nickName); // this() chama outro construtor da pr�pria classe
		                      // this.  � para acessar um atributo, normalmente para diferenciar 
						      // o identifcador do par�metro do identificado do atributo
		this.dataNascimento = LocalDate.of(ano, mes, dia); 
	}
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		// colocaria c�digo que testa o par�metro
		// lan�ar exce��es n�o aceitando em casos que forem necess�rios
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
	
	public String getDataNascimentoStr() {
		DateTimeFormatter formatoBr = DateTimeFormatter.ofPattern("dd/MM/yyyy");
		return dataNascimento.format(formatoBr);
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

	
	// a ordenacao natural ocorre com um atributo escolhido pelo programador
	// como significativo, como o mais natural para ordenar objetos da classe
	// neste caso � o atributo nome
	// o compareTo ira devolver um numero inteiro negativo, zero ou positivo
	// se o this.nome for menor, igual ou maior que nome do objeto passado como par�mtro
	@Override
	public int compareTo(Pessoa pessoa) {
		return nome.compareToIgnoreCase(pessoa.getNome());
		// n�o foi necess�rio fazer um conjunto do ifs pois o atributo � uma String
		// que tamb�m implements Comparable<String>
		// portanto, bastou retornar o compareToIgnoreCase j� dispon�vel na classe String 
		
	}	
}
