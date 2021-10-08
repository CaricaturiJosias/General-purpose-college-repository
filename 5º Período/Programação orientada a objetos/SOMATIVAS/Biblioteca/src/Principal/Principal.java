package Principal;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.Iterator;
import java.util.Scanner;

import Amigo.Amigo;
import Amigo.ListaAmigos;
import Emprestimo.Emprestimo;
import Emprestimo.ListaEmprestimos;
import Item.Biblioteca;
import Item.ContaNetflix;
import Item.ContaSteam;
import Item.Disponibilidade;
import Item.Item;
import Item.Livro;
/**
 * <p>Classe do pacote Principal<p/>
 * <p>Parte principal para funcionamento do c�digo, cont�m fun��es est�ticas e utiliza fun��es de biblioteca para o funcionamento
 * do c�digo<p/>
 * @author Cez�rio
 * @since 1.0
 * @see {@linkplain Biblioteca}, {@linkplain Item}
 */
public class Principal {

	// n�o haver� vari�veis 'globais' static na main 
	
	public static void main(String[] args) throws InputMismatchException{
	    //hardcoded
		ArrayList<Item> itens = new ArrayList<Item>();
		Livro livro = new Livro("Muita gente", 1000, 0, "Head first Java", Disponibilidade.DISPONIVEL );
		itens.add(livro);
		Livro livro1 = new Livro("Patrick Rothtuss", 200, 1, "M�sica do sil�ncio", Disponibilidade.DISPONIVEL );
		itens.add(livro1);
		Livro livro2 = new Livro("Willian Gibson", 300, 2, "Neuromancer", Disponibilidade.DISPONIVEL );
		itens.add(livro2);
		Livro livro3 = new Livro("Paulo Leminski", 300, 3, "Toda poesia", Disponibilidade.DISPONIVEL );
		itens.add(livro3);
		ContaNetflix conta = new ContaNetflix("josiasMequetrefe", "SenhaSafad�nica123", 4, "Conta do Josias"
							                 , Disponibilidade.DISPONIVEL);
		itens.add(conta);
		
		ContaNetflix conta1 = new ContaNetflix("bereuJogaFacil", "kl_1234123521&%$", 5, "Conta do Bereu"
                , Disponibilidade.DISPONIVEL);
		itens.add(conta1);
		
		ContaNetflix conta2 = new ContaNetflix("revitanos16", "Vinicius8+", 6, "Conta do Renan"
		        , Disponibilidade.DISPONIVEL);
		itens.add(conta2);
		
		ContaSteam conta3 = new ContaSteam("vetete2000", "Baberkibe", 7, 7, "Conta do Trist�o", Disponibilidade.DISPONIVEL);
		itens.add(conta3);
		
		ContaSteam conta4 = new ContaSteam("jonathan@yahoo.pentateuco@gmail.com", "andropalmito", 20, 8, "Conta do JooJ"
										   , Disponibilidade.DISPONIVEL);
		itens.add(conta4);
		
		ContaSteam conta5 = new ContaSteam("lesbico3D", "blebis", 7, 9, "Conta do polido", Disponibilidade.DISPONIVEL);
		itens.add(conta5);
		
		ArrayList<String> nomes = new ArrayList<String>();
		nomes.add("Josias");
		nomes.add("Bereu");
		nomes.add("Jamelao");
		nomes.add("Vitor");
		nomes.add("Jonathan");
		nomes.add("Gustavo");
		nomes.add("Klisman");
		nomes.add("Renan");
		nomes.add("Habib's manager");
		Iterator<String> iterator = nomes.iterator();
		ListaAmigos hdAmigos = new ListaAmigos();
		int id = 0;
		while (iterator.hasNext()) {
			String nome = iterator.next();
			Amigo novoAmigo = new Amigo(id, nome);
			hdAmigos.addAmigos(novoAmigo);
			id++;
		}
		
		
		
		// A Biblioteca � criada usando seu construtor
		// Exemplo:
		Scanner input = new Scanner(System.in);
		Biblioteca bib = new Biblioteca("Biblioteca Pessoal");
		bib = leBiblioteca();
		bib.setLista(hdAmigos);
		bib.setAlItem(itens);
		System.out.println("Funcionando");
		do {
		    System.out.println("0 - sair\n"
		    +"1 - cadastrar item\n"
		    +"2 - cadastrar amigo\n"
		    +"3 - emprestar\n"
		    +"4 - devolver\n"
		    +"5 - listar emprestimos atuais\n"
		    +"6 - listar hist�rico de empr�stimos\n"
		    +"7 - listar biblioteca\n"
		    +"8 - alterar estado");
		    		
			int escolha, idAmigo, idItem, entrada = input.nextInt();
			LocalDateTime horarioDevolu��o;
			switch (entrada) {
				case 0:
					input.close();
					System.exit(0);
				case 1:
					escolha = getTipo();
					System.out.println(bib.cadastroItem(escolha));
					break;
				case 2:
					System.out.println(bib.cadastraAmigo()+" registrado\n");
					break;
				case 3:
					idAmigo = pegaIDAmigo(bib);
					idItem = pegaIDItem(bib);
					horarioDevolu��o = pegaDataDevolu��o();
					System.out.println((bib.emprestimo(idItem, idAmigo, horarioDevolu��o)));					
					break;
				case 4:
					idAmigo = pegaIDAmigo(bib);
					idItem = pegaIDItem(bib);
					System.out.println(bib.devolver(idItem, idAmigo));
					break;
				case 5:
					System.out.println(bib.listarEmprestimos());
					break;
				case 6:
					idItem = pegaIDItem(bib);
					System.out.println(bib.emprestimosItem(idItem));
					break;
				case 7:	
					Collections.sort(bib.getAlItem());
					System.out.println(bib.showItem()+"\n");
					break;
				case 8:
					idItem = pegaIDItem(bib);
					int idEstado = pegaEstado(bib, idItem);
					System.out.println(bib.mudaEstado(idItem, idEstado));
					System.out.println("Case 8");
					break;
			}
		gravaBiblioteca(bib);
		
		}while(1==1);	
	}
	
	/**
	 * <p>Fun��o para mostrar os itens presentes na biblioteca e obter o Id de qual o usu�rio deseja realizar uma opera��o</p>
	 * @param bib Biblioteca possuidora dos itens
	 * @return int representando o ID do item escolhido pelo usu�rio
	 * @see {@linkplain Biblioteca}, {@linkplain Item}
	 */
	
	static int pegaIDItem(Biblioteca bib){
		if (bib.getAlItem().size() == 0) {
			return -1;
		}
		if (bib.getLista().getAlAmigos().size() == 0) {
			return -1;
		}
		Scanner input = new Scanner(System.in);	
		System.out.println(bib.showItem());
		System.out.println("\nInsira o id desejado: ");
		int idEmprestimo = input.nextInt();
		while (idEmprestimo <= 0 || idEmprestimo > bib.getAlItem().size()+1){
			idEmprestimo = input.nextInt();	
		}
		return (idEmprestimo-1);
	}
	
	/**
	 * <p>Fun��o para mostrar os amigos presentes na lista de amigos da biblioteca e obter o Id de qual o usu�rio deseja realizar
	 *  uma opera��o</p>
	 * @param bib Biblioteca possuidora da lista de amigos
	 * @return int representando o ID do amigo autoidentificado pelo usu�rio
	 * @see {@linkplain Biblioteca}, {@linkplain ListaAmigos} e {@linkplain Amigo}
	 */
	
	 static int pegaIDAmigo(Biblioteca bib) {
		 System.out.println("Primeiramente se identifique\n"+ bib.getLista());
		 Scanner input = new Scanner(System.in);
		 int idEmprestador = 0;
		 while (idEmprestador <= 0){
			idEmprestador = input.nextInt();
		 }
		 return (idEmprestador-1);
	 }
	 
	 /**
		 * <p>Fun��o para coletar o estado desejado para mudan�a, de acordo com o estado atual do objeto</p>
		 * @param bib Biblioteca possuidora dos estados
		 * @param idItem id do item a ser analisado para mudan�a de estado
		 * @return int representando o estado que se deseja para modifica��o em fun��es da classe Biblioteca
		 * @see {@linkplain Biblioteca}, {@linkplain Disponibilidade}
		 */
	 
	 static int pegaEstado(Biblioteca bib, int idItem) {
		 Scanner input = new Scanner(System.in);
		 int escolha = -1;
		 Disponibilidade disponibilidade = bib.getAlItem().get(idItem).getDispItem();
		 String mensagem = null;
		 System.out.println("Selecione o estado desejado para o(a) "+bib.getAlItem().get(idItem).getTipo()
				 		  + "\nCom disponibilidade atual de: " + disponibilidade.toString());
		 switch (disponibilidade) {
		 	
		 	case DISPONIVEL:
		 		mensagem = "\n3 - Consulta local\n";
		 		
		 	case EMPRESTADO:
		 		if (mensagem == null) {
		 			mensagem = "";
		 		}
		 		System.out.println(
		 				 "\n\n"
					     + "\n1 - Danificado"
					     + "\n2 - Extraviado"
					     + mensagem
					     + "\nR: ");
			 	while (escolha<1||escolha>3) {
			 		while (input.hasNextInt()==false) {}
			 		escolha = input.nextInt();
			 	}
			 	break;
		 	
		 	case CONSULTALOCAL:
		 		mensagem = "\n1 - Dispon�vel";
		 		while(escolha != 4) {
		 			while (input.hasNextInt()==false) {}
			 		escolha = (input.nextInt()+3);
		 		}
		 		break;
		 	
		 	default:
		 		escolha = 0;
		 		break;
		 }
		 return escolha;
	 }
	 
	 /**
	  *  Coleta a data que o usu�rio d� no formato dd/mm para devolu��o de um item ao emprest�-lo
	  * @return LocalDateTime com a data esperada para devolu��o
	  */
	 
	 protected static LocalDateTime pegaDataDevolu��o() {
		Scanner input = new Scanner(System.in);
		LocalDateTime horaAgora = LocalDateTime.now();
		System.out.println("No momento o dia � "+horaAgora.format(DateTimeFormatter.ofPattern("dd/MM/uuuu"))
						 + " At� quando planeja devolver o item (desse ano, claro) (formato dd/mm)?" );
		String dataDada = input.next();
		LocalDateTime devolu��oPrevista = getTime(dataDada);
		if (devolu��oPrevista.isAfter(getTime(dataDada)) || devolu��oPrevista.isEqual(getTime(dataDada))){
			return devolu��oPrevista;
		} else {
			return null;
		}
	 }

	 /**
	  * Fun��o para obter o tempo em LocalDateTime por uma string em dd/mm
	  * @param dataDada String indicando o momento em dia/m�s para ser obtido em LocalDateTime atrav�s de transforma��es
	  * @return LocalDateTime do momento do ano indicado na string entrada incluindo mesmo ano de execu��o do c�digo e par�metros 
	  * de segundo, milisegundo e afins zeradas
	  * @see {@linkplain LocalDateTime}
	  */
	 
	 protected static LocalDateTime getTime(String dataDada) {
			//arruma o parser use.Delimiter("/") para separar entre /'s
			Scanner entrada = new Scanner(dataDada).useDelimiter("/");
			int Dia = Integer.parseInt(entrada.next());
			int Mes = Integer.parseInt(entrada.next());
			LocalDateTime data = LocalDateTime.of(LocalDateTime.now().getYear(), Mes, Dia, 0, 0);
			return data;
	}
	 
	 /**
	  *Fun��o para escolher o tipo de item a ser registrado dentre os 3 itens  
	  * @return int com a escolha dentre os 3 tipos de itens da biblioteca
	  * @see {@linkplain }
	  */
	 
	 protected static int getTipo() {
			Scanner input = new Scanner(System.in);
			System.out.println("\nSelecione o tipo de item\n"
					+ "1 - Livro\n"
					+ "2 - Conta da netflix\n"
					+ "3 - Conta da steam");
			int escolha = input.nextInt();
			return escolha;
	 }
	 
	 /**
	  * Fun��o para leitura de arquivo gravado em disco r�gido
	  * @return Inst�ncia de biblioteca com os dados do disco rigido incluidos em caso de sucesso, as uma inst�ncia vazia em caso de
	  * falha
	  */
	 
	 protected static Biblioteca leBiblioteca() {
		 Biblioteca saida;
		 String nomeBib = null;
		 ArrayList<Item> alItem = new ArrayList<Item>();
		 ListaEmprestimos alEmprestimo = new ListaEmprestimos();
		 ArrayList<Amigo> alAmigos = new ArrayList<Amigo>();
		 
		 ObjectInputStream leitura = null;
		 try {
			 System.out.println("Leitura");
			 leitura = new ObjectInputStream(new FileInputStream("c:\\temp\\Biblioteca.txt"));
			 System.out.println("Leu");
			 nomeBib = (String) leitura.readObject();
			 System.out.println("Nome");
			 alItem = (ArrayList<Item>) leitura.readObject();
			 System.out.println("Item");
			 alEmprestimo = (ListaEmprestimos) leitura.readObject();
			 System.out.println("Emprestimo");
			 alAmigos = (ArrayList<Amigo>) leitura.readObject();
			 System.out.println("Amigo");
		 } catch(IOException erroLeitura1) {
			 System.out.println(erroLeitura1.getMessage());
		 } catch(ClassNotFoundException erroClasseLeitura) {
			 System.out.println(erroClasseLeitura.getMessage());
		 } finally {
			 try {
				 if (leitura != null) {
					 leitura.close();}
			 } catch (IOException erroDeFechamento) {
				 System.out.println(erroDeFechamento.getMessage());
			 }
		 }		

		 saida = new Biblioteca(nomeBib);
		 if (alItem.isEmpty() || alAmigos.isEmpty() || alEmprestimo.getAlEmprestimos().isEmpty()) {
			 return new Biblioteca(saida);
		 }
		 saida.setAlItem(alItem);
		 saida.setLista(new ListaAmigos(alAmigos));
		 //saida.setListaEmp(new ListaEmprestimos(alEmprestimo));
		 return new Biblioteca(saida) ;
	 }
	 
	 /**
	  * Grava em disco rigido a inst�ncia atual da biblioteca, com todas as suas listas e nome
	  * @param bib biblioteca a ser salva de forma bin�ria em arquivo
	  */
	 
	 protected static void gravaBiblioteca(Biblioteca bib) {
		 ObjectOutputStream gravacao = null;
		 try {
			 System.out.println("Gravando");
			 gravacao = new ObjectOutputStream(new FileOutputStream("c:\\temp\\Biblioteca.txt"));
			 gravacao.writeObject(bib.getNomeBib());
			 gravacao.writeObject(bib.getAlItem());
			 gravacao.writeObject(bib.getAlEmprestimos());
			 gravacao.writeObject(bib.getLista().getAlAmigos());
		 } catch(IOException erroGravar){
			 System.out.println(erroGravar.getMessage());
		 }
		 finally {
			 try {
				gravacao.close();
			 } catch (IOException erroFechar) {
				System.out.println(erroFechar.getMessage());
			}
		 }
		 
	 }
}
