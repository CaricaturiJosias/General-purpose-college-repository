import java.util.Scanner;

public class auladia0308 {
	//atributos de classe ("globais")
	//int x; // variavel de instancia
	//static int y; //variavel de classe
	public static void main(String[] args) {
		//variaveis locais
		//tipos primitivos
		int x, i;
		float f;
		// str no java é char
		char c = 65;
		String frase = "Ola mundo cruel!";
		System.out.println(frase);
		System.out.println("Variavel c: "+ c);
		System.out.println(frase.charAt(0));
		System.out.println(frase.charAt(frase.length()-1));
		System.out.println(frase.toUpperCase());
		f = c /2F;
		System.out.println("Variável f: " + f);
		System.out.printf("Var f:%f, var c:%c", f, c);
		
		Scanner scanner = new Scanner(System.in);
		System.out.println("Digite seu nome: ");
		String nome = scanner.nextLine();
		System.out.println("Bem vindo " +nome);
		System.out.println("Digite um número: ");
		i = scanner.nextInt();
		System.out.println("Digitou: "+i);
	}
}
