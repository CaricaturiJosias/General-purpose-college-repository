import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;

public class Principal {
	
	// static faz de contato um atributo de classe
	private static ArrayList<Pessoa> contatos = new ArrayList<Pessoa>();
	
	public static void main(String[] args) {
		int opcao;
		Scanner teclado = new Scanner(System.in);
		do {
			System.out.println("\n=== Menu de opcoes ===\n");
			System.out.println("    0 - sair");
			System.out.println("    1 - cadastrar contato");
			System.out.println("    2 - listar contatos");
			System.out.println("    3 - ordenar contatos (A..Z)");  // Comparable
			System.out.println("    4 - ordenar contatos (Z..A)");  // ReverseOrder
			System.out.println("    5 - ordenar por nickname (A..Z)"); // Comparator
			System.out.println("    6 - ordenar contatos por idade decrescente)"); 
			System.out.println("    7 - imprimir calendario dos aniversarios durante o ano");
						
			System.out.print("\n    Opcao? ");
			opcao = teclado.nextInt();
					
			switch (opcao) {
			case 0:
				System.exit(0);
			case 1:
				// cadastro de contatos
				cadastrarPessoa();
				break;
			case 2:
				listarContatos();
				break;
			case 3:
				// sort � um m�todo static do Framework Collections
				// ir� ordenar a lista contatos em ordem ascendente da sua ordem natural A-Z
				// para tal os objetos de contaos, que s�o inst�ncias da classe Pessoa
				// que precisa implementar a interface Comparable<Pessoa>
				// o que exigem o m�todo compareTo
				Collections.sort(contatos);
				break;	
			case 4:
				// sort � um metodo com overload (sobrecarga)
				// pode ser apenas a ordem natural, como na linha 44 acima
				// ou na op��o de receber a lista e um comparator diferente
				// no caso, usando reversoOrder que tambem � metodo de Collections
				// gera-se a ordem inversa da ordem natural, ou seja, teremoz Z-A	
				Collections.sort(contatos, Collections.reverseOrder());   
				break;
			case 5:
				// neste caso queremos ordenar por nickname A-Z
				// outro atributo diferente da ordem natura
				// ent�o cria-se um novo Comparator
				// que exige a implementa��o do m�todo compare, que compara 2 objetos
				// para n�o criar uma classe explicitamente, o c�digo � inserido inline
				// na chamada ao sort, esta estrat�gia de codificar na instancia��o
				// do objeto � conhecida por Classes An�nimas 
				// que s�o tipos especiais de classes internas
				Collections.sort(contatos, new Comparator<Pessoa>() {
					@Override
					public int compare(Pessoa p1, Pessoa p2) {
						return p1.getNickName().compareToIgnoreCase(p2.getNickName());
					}				
				});   
				break;
			default:
				System.out.println("Opcao inexistente!");;
				break;
			}
		} while (opcao!=0);
	}
	
	// m�todo com static � um m�todo de classe
	private static void cadastrarPessoa() {
		Scanner teclado = new Scanner(System.in);
		String nome, nickName;
		Pessoa p;
		
		System.out.println("\n--- Cadastro de contato ---");
		System.out.print("\n    Nome: ");
		nome = teclado.nextLine();
		System.out.print("\n    Nickname: ");
		nickName = teclado.nextLine();
		p = new Pessoa(nome, nickName);
		contatos.add(p);	
	}

	// m�todo com static � um m�todo de classe
	private static void listarContatos() {
		/*
		System.out.println("\n--- Lista de contato ---\n");
		System.out.println("Total de contatos: " + contatos.size() + "\n");
		// estrategia 1
		// passando pelo ArrayList usando um loop com contador e metodo get/size
		for (int i=0; i<contatos.size(); i++) {
			// i � local ao for
			System.out.println(i+1 + ":    " + contatos.get(i).getNome());
		}
		*/
		
		/*
		System.out.println("\n--- Lista de contato ---\n");
		System.out.println("Total de contatos: " + contatos.size() + "\n");
		// estrategia 2
		// passando pelo ArrayList usando foreach, para cada contato do tipo Pessoa em contatos
		for (Pessoa contato : contatos) {  
			System.out.println(contato.getNome());
		}
		*/
		
		System.out.println("\n--- Lista de contato ---\n");
		System.out.println("Total de contatos: " + contatos.size() + "\n");
		// estrategia 3
		// passando pelo ArrayList usando sua capacidade de implementar a interface Iterator
		Iterator<Pessoa> it = contatos.iterator();
		while (it.hasNext()) {
			Pessoa p = it.next();  // p � local ao while
			System.out.println(p.getNome()+ "(" + p.getNickName() + ")");
		}
	}
}




