import java.time.LocalDate;
import java.time.format.TextStyle;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Locale;
import java.util.Scanner;

public class Principal {
	
	// static faz de contato um atributo de classe
	private static ArrayList<Pessoa> contatos = new ArrayList<Pessoa>();
	
	public static void main(String[] args) {
		int opcao;
		Scanner teclado = new Scanner(System.in);

		// inclusão hardcoded de algumas pessoas para teste das funcionalidades do programa
		contatos.add(new Pessoa("José Fulano", "Zé", 5, 10, 2000));
		contatos.add(new Pessoa("Ana Ciclano", "Aninha", 9, 4, 1985));
		contatos.add(new Pessoa("Otavio Beltrano", "Be", 20, 2, 1970));
		contatos.add(new Pessoa("Maria Fulano", "Mari", 25, 2, 1975));
		contatos.add(new Pessoa("Patricio Ciclano", "Cicinho", 20, 12, 1972));
		contatos.add(new Pessoa("Jean Fulano", "Jota", 31, 1, 1990));
		contatos.add(new Pessoa("Amanda Ciclano", "Amandinha", 20, 12, 1981));
		
		do {
			System.out.println("=== Menu de opcoes ===");
			System.out.println("    0 - sair");
			System.out.println("    1 - cadastrar contato");
			System.out.println("    2 - listar contatos");
			System.out.println("    3 - ordenar contatos (A..Z)");  // Comparable
			System.out.println("    4 - ordenar contatos (Z..A)");  // ReverseOrder
			System.out.println("    5 - ordenar por nickname (A..Z)"); // Comparator
			System.out.println("    6 - ordenar contatos por idade crescente"); 
			System.out.println("    7 - imprimir calendario dos aniversarios durante o ano");
			System.out.println("    8 - consultar contato");
			System.out.println("    9 - remover contato");
						
			System.out.print("\n    Opcao? ");
			opcao = teclado.nextInt();
			teclado.nextLine();
					
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
				// sort é um método static do Framework Collections
				// irá ordenar a lista contatos em ordem ascendente da sua ordem natural A-Z
				// para tal os objetos de contatos, que são instâncias da classe Pessoa
				// que precisa implementar a interface Comparable<Pessoa>
				// o que exigem o método compareTo
				Collections.sort(contatos);
				break;	
			case 4:
				// sort é um metodo com overload (sobrecarga)
				// pode ser apenas a ordem natural, como na linha 61 acima
				// ou na opção de receber a lista e um comparator diferente
				// no caso, usando reversoOrder que tambem é metodo de Collections
				// gera-se a ordem inversa da ordem natural, ou seja, teremoz Z-A	
				Collections.sort(contatos, Collections.reverseOrder());   
				break;
			case 5:
				// neste caso queremos ordenar por nickname A-Z
				// outro atributo diferente da ordem natura
				// então cria-se um novo Comparator
				// que exige a implementação do método compare, que compara 2 objetos
				// para não criar uma classe explicitamente, o código é inserido inline
				// na chamada ao sort, esta estratégia de codificar na instanciação
				// do objeto é conhecida por Classes Anônimas 
				// que são tipos especiais de classes internas
				Collections.sort(contatos, new Comparator<Pessoa>() {
					@Override
					public int compare(Pessoa p1, Pessoa p2) {
						return p1.getNickName().compareToIgnoreCase(p2.getNickName());
					}				
				});   
				break;
			case 6:
				Collections.sort(contatos, new Comparator<Pessoa>() {
					@Override
					public int compare(Pessoa p1, Pessoa p2) {
						int idadeP1, idadeP2;
						idadeP1 = p1.getIdade();
						idadeP2 = p2.getIdade();
						return idadeP1 - idadeP2;
						// return (p1.getIdade() - p2.getIdade());
						// não foi preciso fazer um if, pois a conta de subrtação
						// já devolve um negativo, nulo ou positivo
					}
					
				});
				break;
			case 7:
				// ----------------------------------------------------------
				// Etapa 1: vamos ordenar por data de nascimento e caso seja a mesma, por ordem alfabética
				Collections.sort(contatos, new Comparator<Pessoa>() {
					@Override
					public int compare(Pessoa p1, Pessoa p2) {
						// getDayOfYear() devolve um int de 1 a 365, ou seja, incorpora dia e mes
						int diaP1 = p1.getDataNascimento().getDayOfYear();						
						int diaP2 = p2.getDataNascimento().getDayOfYear();
						if (diaP1 != diaP2) {  // aniversário em dias diferentes, compara as datas
							return Integer.compare(diaP1, diaP2); 
							// usando o método compare da classe wraper Integer 
							// (poderia fazer conta ou fazer ifs)
						}  
						return p1.compareTo(p2);
						// se fazem aniversário no mesmo dia, compara alfabeticamente
					}
				});
				
				// ----------------------------------------------------------
				// Etapa 2: vamos imprimir um calendário anual de aniversários
				LocalDate hoje = LocalDate.now(); 
				System.out.println("\n--- Lista de Aniversariantes - " + hoje.getYear()+ " ---\n");
				 
				// português do Brasil, para pegar os nomes dos meses direto da API do Java
				Locale ptBr = new Locale ("pt", "BR");
				
				int mes = 0; 
				for (int i = 0; i < contatos.size(); i++) {
					Pessoa p = contatos.get(i);  
					int mesP = p.getDataNascimento().getMonthValue(); // pega o mês de nascimento
					if (mesP != mes){ // trocou para outro mês ?
						System.out.println("    > " + p.getDataNascimento().getMonth().getDisplayName(TextStyle.FULL, ptBr));
						mes = mesP;
					}
					// usando o print formatado (printf) para facilitar a composição da string em tela
					System.out.printf("        %02d - %s (Nasceu em %d - %d anos)\n", p.getDataNascimento().getDayOfMonth(), 
							p.getNome(), p.getDataNascimento().getYear(), p.getIdade());
				}
				break; 
			case 8:
				System.out.println("\n--- Consultar contato ---\n");
				System.out.print("    Nome a procurar: ");
				String nomeProcurado = teclado.nextLine();
				consultarContato(nomeProcurado);
				break;
			case 9:
				System.out.println("\n--- Remover contato ---\n");
				System.out.print("    Nome a procurar: ");
				String nomeRemover = teclado.nextLine();
				removerContato(nomeRemover);
				break;				
			default:
				System.out.println("Opcao inexistente!");;
				break;
			}
		} while (opcao!=0);
	}
	
	// método com static é um método de classe
	private static void cadastrarPessoa() {
		Scanner teclado = new Scanner(System.in);
		String nome, nickName;
		int dia, mes, ano;
		Pessoa p;
		
		System.out.println("\n--- Cadastro de contato ---");
		System.out.print("\n    Nome: ");
		nome = teclado.nextLine();
		System.out.print("    Nickname: ");
		nickName = teclado.nextLine();
		System.out.print("    Data de Nascimento (DD/MM/YYYY): ");
        String data = teclado.nextLine();
        String[] dataNasc = data.split("/"); // separando a string em tres partes de um vetor 
        dia = Integer.parseInt(dataNasc[0]); // primeira parte é o DD
        mes = Integer.parseInt(dataNasc[1]); // segunda parte é o MM
        ano = Integer.parseInt(dataNasc[2]); // terceira parte é o YYYY
        p = new Pessoa(nome, nickName, dia, mes, ano);
		contatos.add(p);	
	}

	// método com static é um método de classe
	private static void listarContatos() {
		/*
		System.out.println("\n--- Lista de contato ---\n");
		System.out.println("Total de contatos: " + contatos.size() + "\n");
		// estrategia 1
		// passando pelo ArrayList usando um loop com contador e metodo get/size
		for (int i=0; i<contatos.size(); i++) {
			// i é local ao for
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
		System.out.println("    Total de contatos: " + contatos.size() + "\n");
		// estrategia 3
		// passando pelo ArrayList usando sua capacidade de implementar a interface Iterator
		Iterator<Pessoa> it = contatos.iterator();
		while (it.hasNext()) {
			Pessoa p = it.next();  // p é local ao while
			System.out.println("    " + p.getNome()+ " (" + p.getNickName() + " - " + p.getIdade() + " anos)");
		}
	}
	
	private static void imprimePessoa(Pessoa p){
    	System.out.println("    Nome: " + p.getNome());
    	System.out.println("    NickName: " + p.getNickName());
    	System.out.println("    Nascimento: " + p.getDataNascimentoStr());
    	System.out.println("    Idade: " + p.getIdade());	
    }
	
    private static void consultarContato(String chave){
    	boolean achou = false;
    	for (Pessoa p : contatos) {
			if (p.getNome().toUpperCase().contains(chave.toUpperCase())){
				imprimePessoa(p);
				System.out.println();
				achou = true;
			}
		}
    	if (!achou){     
    		System.out.println("    Aviso: contato <"+ chave+ "> nao cadastrado!\n");
    	}
    }
    
    private static void removerContato(String chave){
    	boolean achou = false;
    	Scanner teclado = new Scanner(System.in);
		Iterator<Pessoa> it = contatos.iterator();
		while (it.hasNext()) {
			Pessoa p = it.next();
			if (p.getNome().toUpperCase().contains(chave.toUpperCase())){
				System.out.print("    Deseja remover <" + p.getNome() + "> da lista (S/N): ");
				String opcao = teclado.nextLine();
				if (opcao.toUpperCase().charAt(0) == 'S') {
					it.remove();
					System.out.println("    Contato removido da lista!");
				}
				achou = true;
			}
		}
    	if (!achou){     
    		System.out.println("    Aviso: contato <"+ chave+ "> nao cadastrado!\n");
    	}
    }
	
}




