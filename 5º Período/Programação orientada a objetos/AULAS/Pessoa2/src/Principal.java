
public class Principal {

	public static void main(String[] args) {
		//perdeu o construtor vazio quando colocou o m�todo construtor (o que tem super)
		Pessoa p1 = new Pessoa();
		Pessoa p2 = new Pessoa("Renansko");
		Pessoa p3 = new Pessoa("Klisman", "Bereu joga f�cil");
		
		System.out.println(p1.toString());
		System.out.println(p2.toString());
		System.out.println(p3.toString());
		
	}

}
