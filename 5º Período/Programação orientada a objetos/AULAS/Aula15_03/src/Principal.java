
public class Principal {

	public static void main(String[] args) {
		Pessoa p = new Pessoa();
		System.out.println(p); //roda de forma transparente o toString
		System.out.println(p.toString()); //toString herdado da object
		//classe object  é a super de toda API java
		System.out.println(p.getClass().getName());
		// p é instância de referência do objeto Pessoa
		// getClass é herança da classe object e devolve um objeto class
		// getClass devolve o nome da classe uma string
		System.out.println(p.getClass().getName().toUpperCase().charAt(0));
		System.out.println(p.getClass().getName().toUpperCase());
	
		//ALGORITMICO MODELAGEM PROGRAMAÇÃO OO
	}
}
