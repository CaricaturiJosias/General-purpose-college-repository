
public class Principal {

	public static void main(String[] args) {
		//perdeu o construtor vazio quando colocou o método construtor (o que tem super)
		//Pessoa p1 = new Pessoa();
		// Neste caso, o construtor Pessoa sem argumentos foi disponibilizado pela Object
		// Ele existe por herança, cria a instância porém não popula atributos
		
		
		Pessoa p2 = new Pessoa("Klisman", "Bereu joga fácil");
		System.out.println(p2.toString());
		//System.out.println(p1.toString());
		
	}

}
