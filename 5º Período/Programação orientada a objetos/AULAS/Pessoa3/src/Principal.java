import java.time.LocalDate;

public class Principal {

	public static void main(String[] args) {
		// testando os construtores
		Pessoa p1 = new Pessoa();
		Endereco e2 = new Endereco("Rua das Flores", 123, "Curitiba", "PR", "80123-123");
		Pessoa p2 = new Pessoa ("Ciclano de Tal", e2);
		Pessoa p3 = new Pessoa("Fulano de Tal", "ft_matador", new Endereco("Rua das Pinheiros", 987, "Araucaria", "PR", "85245-2453"));
		
		// p1.nome = "Seu folgado!"; // Nao pode acessar direto, pois nome é atributo privado
		p1.setNome("Beltrano de Tal");
		System.out.println(p1); // toString acionado de forma transparente
		System.out.println(p2);
		System.out.println(p3);
		
		// testando getters
		System.out.println(p1.getEndereco().getCidade());
		System.out.println(p2.getEndereco().getCidade());
		System.out.println(p3.getEndereco().getCidade());
		
		// testando toString redefinido na classe Endereço
		System.out.println(p1.getEndereco()); // toString de forma transparente
		System.out.println(p2.getEndereco().toString());
		System.out.println(p3.getEndereco().toString());
		
		// testando getEtiqueta
		//System.out.println(p1.getEndereco().getEtiquetaPostal());
		//System.out.println(p2.getEndereco().getEtiquetaPostal());
		System.out.println(p3.getNome());
		//System.out.println(p3.getEndereco().getEtiquetaPostal());
		
		// testando atributo dataNascimento
		p1.setDataNascimento(20, 12, 2010); // setter com dia, mes e ano int
		System.out.println(p1.getDataNascimento().toString());
		System.out.println(p1.getNome() + " possue " + p1.getIdade() + " anos de vida");
		
		p2.setDataNascimento(LocalDate.of(2019, 3, 24)); // setter com objeto LocalDate
		System.out.println(p2.getDataNascimento().toString());
		System.out.println(p2.getNome() + " possue " + p2.getIdade() + " anos de vida");
		
		System.out.println(p3.getDataNascimento().toString());
		// idade default atribuída pelo construtor
		System.out.println(p3.getNome() + " possue " + p3.getIdade() + " anos de vida");
		
		
	}
}
