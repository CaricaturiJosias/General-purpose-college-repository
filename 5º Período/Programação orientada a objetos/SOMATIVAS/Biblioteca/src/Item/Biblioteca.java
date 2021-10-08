package Item;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

import Amigo.Amigo;
import Amigo.ListaAmigos;
import Emprestimo.Emprestimo;
import Emprestimo.ListaEmprestimos;

/**<p>Classe do pacote Item</p>
 * <p>Biblioteca é uma classe representando um registro de livros, contas da Netflix e da Steam, onde é possível
 * se cadastrar, realizar um empréstimo e checar a disponibilidade de itens assim como alterá-la</p>
 * @since 1.0
 * @author Cezário
 * @see {@linkplain ContaNetflix}, {@linkplain Livro}, {@linkplain ListaAmigos}, {@linkplain ListaEmprestimos}
 */


public class Biblioteca implements Serializable{

	private String nomeBib;
	private ArrayList<Item> alItem;
	private ListaAmigos lista;
	private ListaEmprestimos alEmprestimos;
	
	/**
	 * Construtor padrão para inicialização da biblioteca, somente com <code>nomeBib</code>
	 * 
	 * @param nomeBib Nome da biblioteca dado na criação de qualquer instância de {@linkplain Biblioteca}
	 * @param alItem Lista de itens em ArrayList<Item> (vide {@linkplain Item})
	 * @param lista Lista de amigos presentes nos registros da biblioteca (Vide {@linkplain ListaAmigos} e {@linkplain Amigo})
	 * @param alEmprestimos Lista de emprestimos, contém todos os empréstimos existentes no código (vide {@linkplain ListaEmprestimos} e
	 * {@linkplain Emprestimo})
	 */
	
	public Biblioteca(String nomeBib) {
		this.nomeBib = nomeBib;
		this.alItem = new ArrayList<Item>();
		this.lista = new ListaAmigos();
		this.alEmprestimos = new ListaEmprestimos();
		
	}
	
	/**
	 * <p>Método construtor de {@linkplain Biblioteca} quando é feita leitura de uma instância em disco rígido</p>
	 * @param bib é a biblioteca lida em disco rígido
	 * @param nomeBib Nome da biblioteca dado na criação de qualquer instância de {@linkplain Biblioteca}
	 * @param alItem Lista de itens em ArrayList<Item> (vide {@linkplain Item})
	 * @param lista Lista de amigos presentes nos registros da biblioteca (Vide {@linkplain ListaAmigos} e {@linkplain Amigo})
	 * @param alEmprestimos Lista de emprestimos, contém todos os empréstimos existentes no código, devolvidos ou não
	 * (vide {@linkplain ListaEmprestimos} e {@linkplain Emprestimo}) 
	 */
	
	//salvo em disco
	public Biblioteca(Biblioteca bib) {
		this.alItem = bib.getAlItem();
		this.lista = bib.getLista();
		this.nomeBib = bib.getNomeBib();
		this.alEmprestimos = bib.alEmprestimos;
	}
	
	// métodos
	
	/**
	 * Função feita para recuperar todos os empréstimos com um único item (vide {@linkplain Item} e {@linkplain ListaEmprestimo})
	 * @param idItem Id dado pelo usuário para consulta do histórico
	 * @return A saída da a confirmação ou falha do processo, no caso de confirmação lista as características de cada empréstimo (vide 
	 * {@linkplain Emprestimo}) em uma única string devolvida para o processo principal ({@linkplain Principal.Principal})
	 */
		
	public String emprestimosItem(int idItem) {
		String saida ="";
		Iterator<Emprestimo> iterador = this.alEmprestimos.getAlEmprestimos().iterator();
		while (iterador.hasNext()) {
			Emprestimo prox = iterador.next();
			
			if (prox.getIdItem() == idItem) {
				saida = saida + "\n\n\nTitulo do item: " + this.getAlItem().get(idItem).getTituloItem()
						+ "\nEmprestimo feito para: " + prox.getAmigo().getNomeAmigo()
						+ "\nNo dia " + prox.getDataEmprestimo().format(DateTimeFormatter.ofPattern("dd/MM/uuuu"))
						+ "\nPrevisão de entrega: " + prox.getDataDevolucao().format(DateTimeFormatter.ofPattern("dd/MM/uuuu"))
						+ "\nData real da entrega: ";
				
				if (prox.getDataDevolvido() == null) {
				saida = saida + "entrega não realizada até o momento\n";
				
				} else {
				saida = saida + prox.getDataDevolvido().format(DateTimeFormatter.ofPattern("dd/MM/uuuu")) + "\n";
				}
			
			}
		}
		if (Objects.equals(saida, "")){
			saida = "Nenhum emprestimo encontrado para o item!\n";
		}
		return saida;
	}
	
	/**
	 * Função para expor todos os empréstimos atualmente, ou seja, com disponibilidade EMPRESTADO no momento de checagem
	 * @return <code>String</code> com sucesso ou falha de obter registros, sucesso devolve a lista com todos os empréstimos no momento,
	 * enquanto falha acusará a falta de empréstimos atualmente.
	 * @see {@linkplain Disponibilidade} e {@linkplain Emprestimo}
	 */
	
	public String listarEmprestimos() {
		String saida = null;
		Iterator<Emprestimo> iterador = this.alEmprestimos.getAlEmprestimos().iterator();
		while (iterador.hasNext()) {
			Emprestimo atual = iterador.next();
			if (atual.getItem().getDispItem() == Disponibilidade.EMPRESTADO) {
				if (saida == null){
					saida = atual.toString();
				} else {
					saida = saida + "\n\n" +atual.toString();
				}
			}
		}
		if (saida == null) {
			saida = "Nenhum empréstimo encontrado!";
		}
		return saida;
	}
	
	/**
	 * @param idEmprestimo Indica a numeração do indivíduo a emprestar o item em {@linkplain ListaAmigos}
	 * @param idEmprestador Indica a numeração do item emprestado
	 * @param devoluçãoPrevista Data dada pelo amigo emprestador no formato de LocalDateTime
	 * @return String - confirmador da operação, exibindo dados do item emprestado e acusador de falha caso necessário
	 * @see {@linkplain Emprestimo}, {@linkplain LocalDateTime} e {@linkplain Amigo}
	 */
	
	public String emprestimo(int idEmprestimo, int idEmprestador, LocalDateTime devoluçãoPrevista) {
		LocalDateTime horaAgora = LocalDateTime.now();
		if (this.alItem.get(idEmprestimo).getDispItem() != Disponibilidade.DISPONIVEL) {
			return "\nItem não disponível, pois ele está registrado como " 
				 + this.alItem.get(idEmprestimo).getDispItem().toString();
		}		
		if (devoluçãoPrevista.isAfter(horaAgora)) {
			this.alItem.get(idEmprestimo).setDispItem(Disponibilidade.EMPRESTADO);
			Emprestimo novoEmprestimo = new Emprestimo(idEmprestador, idEmprestimo, horaAgora, devoluçãoPrevista
					, this.lista.getAlAmigos().get(idEmprestador), this.alItem.get(idEmprestimo));
			this.getListaEmp().getAlEmprestimos().add(novoEmprestimo);
			return "\nEmprestimo de um(a) " + novoEmprestimo.getItem().getTipo() + " feito com sucesso!\n";
		} else {
			return "\nNão será possível realizar o emprestimo nessa data, pois já passou.\n";
		}
	}
	
	/**
	 * Função para fazer a devolução de um item emprestado
	 * @param idItem Id do item a ser devolvido, checando se ele está em regime de emprestimo
	 * @param idAmigo Id do amigo devolvendo o item, checando se ele foi aquele que o emprestou inicialmente
	 * @return String acusando sucesso ou falha da operação, sucesso evidenciando dados como data de entrega e item entregue
	 * @see {@linkplain Item}, {@linkplain Amigo}
	 */
	
	public String devolver(int idItem, int idAmigo){		
		String saida = "\nHouve algum erro";
		if (this.getAlItem().get(idItem).getDispItem() != Disponibilidade.EMPRESTADO) {
			return "\nO item com esse ID não é passível de devolução.\n";
		}
		LocalDateTime horaAgora = LocalDateTime.now();
		Iterator<Emprestimo> iterador = this.alEmprestimos.getAlEmprestimos().iterator();
		while (iterador.hasNext()) {
			Emprestimo daVez = iterador.next();
			if (daVez.getIdItem() == (idItem-1) && daVez.getDataDevolvido() == null) {
				if (daVez.getIdAmigo()==idAmigo) {
					this.alItem.get(idItem).setDispItem(Disponibilidade.DISPONIVEL);
					daVez.setDataDevolvido(horaAgora);
					saida = daVez.getItem().getTipo() + " " + this.alItem.get(idItem).getTituloItem()
							+ " devolvido(a) com sucesso no dia " 
							+ LocalDateTime.now().format(DateTimeFormatter.ofPattern("dd/MM/uuuu"));
				} else {
					saida = "Você não pode devolver esse item, pois não é o(a) " + daVez.getAmigo().getNomeAmigo();
				}
			}
		}
		return saida;
		}
	
	/**
	 * Método para cadastrar um Amigo na lista de amigos da biblioteca
	 * @return String confirmadorá do registro
	 * @see {@linkplain ListaAmigos} e {@linkplain Biblioteca}
	 */
	
	public String cadastraAmigo() {
		System.out.println("Cadastro de amigo\nInsira o nome para registro: ");
		Scanner input = new Scanner(System.in);
		String nome = input.next();
		Amigo novoAmigo = new Amigo(this.getLista().getAlAmigos().size(), nome);
		this.lista.addAmigos(novoAmigo);
		return novoAmigo.toString();
	}
	
	/**
	 * Registra um item no cadastro da biblioteca, podendo ser de qualquer um dos 3 tipos 
	 * @param escolha Int para indicar qual dos 3 tipos de itens vai ser registrado
	 * @return String confirmador do registro com informações do novo item ou mensagem de erro denunciando algo errado
	 * @see {@linkplain Livro}, {@linkplain ContaSteam}, {@linkplain ContaNetflix} e {@linkplain Item}
	 */
	
	public String cadastroItem(int escolha) {
		String saida;
		Scanner input = new Scanner(System.in);
		String titulo, autor, usuario, senha;
		switch (escolha) {
			case 1:
				System.out.println("Insira o título do livro: ");
				titulo = input.nextLine();
				System.out.println("Insira o nome do autor: ");
				autor = input.nextLine();
				System.out.println("Insira o total de páginas: ");
				while (input.hasNextInt() != true) {
					input.nextInt();
				}
				int totalEscolha = input.nextInt() ;
				Livro novoLivro = new Livro(autor, totalEscolha, this.getAlItem().size(), titulo
											, Disponibilidade.DISPONIVEL);
				this.alItem.add(novoLivro);
				saida = novoLivro.toString();
				break;
				
			case 2:
				System.out.println("Insira o nome da conta (para visualização): ");
				titulo = input.nextLine();
				System.out.println("Insira o usuario da conta: ");
				usuario = input.nextLine();
				System.out.println("Insira a senha da conta: ");
				senha = input.next();
				ContaNetflix novaContaNet = new ContaNetflix(usuario, senha, this.getAlItem().size()
										   , titulo, Disponibilidade.DISPONIVEL);
				this.alItem.add(novaContaNet);
				saida =  novaContaNet.toString();
				break;
				
			case 3:
				System.out.println("Insira o nome da conta (para visualização): ");
				titulo = input.nextLine();
				System.out.println("Insira o usuario da conta: ");
				usuario = input.nextLine();
				System.out.println("Insira a senha da conta: ");
				senha = input.nextLine();
				System.out.println("Insira o número de jogos na conta: ");
				int numJogos = input.nextInt();
				ContaSteam novaContaSteam = new ContaSteam(usuario, senha, numJogos, this.getAlItem().size()
														, titulo, Disponibilidade.DISPONIVEL);
				this.alItem.add(novaContaSteam);
				saida = novaContaSteam.toString();
				break;
				
			default:
				saida = "Não foi selecionado um item válido";
				break;
		}
		return saida;
	}
	
	/**
	 * <p>Função feita para simplificar amostragem dos itens registrados, usados em outras funções na classe Principal</p>
	 * <p>Está na classe Biblioteca e não na Principal pois é necessário acesso aos itens</p>
	 * @return String com todos os itens listados na lista de itens da biblioteca atual
	 * @see {@linkplain Item}, {@linkplain Biblioteca} e {@linkplain Principal}
	 */
	
	public String showItem() {
		String Mensagem =null;
		Iterator<Item> iterador = this.alItem.iterator();
		while(iterador.hasNext()) {
			Item current = iterador.next();
			if (Mensagem != null) {
				Mensagem = Mensagem +"\n"+ current.toString()+"Código do item: "+(current.getIdItem()+1)+"\nDisponibilidade: "
									+ current.getDispItem().toString() ;
			} else {
				Mensagem = "\n" + current.toString()+"Código do item: "+(current.getIdItem()+1)+"\nDisponibilidade: "
						 + current.getDispItem().toString();
			}
		}
		return Mensagem;
	}
	
	/**
	 * <p>Função para mudar o estado de disponibilidade de algum item via seu id na lista de itens da biblioteca</p>
	 * @param idItem Id do item que se deseja modificar
	 * @param idEstado Escolha entre as 4 formas de disponibilidade obtidas na Principal
	 * @return String confirmando o sucesso ou falha do processo, no caso de sucesso apresentando o novo estado do item
	 * @see {@linkplain Disponibilidade}
	 */
	
	public String mudaEstado(int idItem, int idEstado) {
		String saida = null;
		switch (idEstado) {
			case 1:
				this.getAlItem().get(idItem).setDispItem(Disponibilidade.DANIFICADO);
				saida = "Estado mudado com sucesso para DANIFICADO!";
				break;
			case 2:
				this.getAlItem().get(idItem).setDispItem(Disponibilidade.EXTRAVIADO);
				saida = "Estado mudado com sucesso para EXTRAVIADO!";
				break;
			case 3:
				this.getAlItem().get(idItem).setDispItem(Disponibilidade.CONSULTALOCAL);
				saida = "Estado mudado com sucesso para  CONSULTA LOCAL!";
				break;
			case 4: 
				this.getAlItem().get(idItem).setDispItem(Disponibilidade.DISPONIVEL);
				saida = "Estado mudado com sucesso para DISPONÍVEL!";
				break;
			default:
				saida = "Estado não modificado com sucesso!";
				break;
		}
		return saida;
	}
	
	
	
	 // Métodos getters e setters 
	 
	
	
	public String getNomeBib() {
		return this.nomeBib;
	}

	public void setNomeBib(String nomeBib) {
		this.nomeBib = nomeBib;
	}

	public ArrayList<Item> getAlItem() {
		return this.alItem;
	}

	public ListaAmigos getLista() {
		return this.lista;
	}

	public ListaEmprestimos getListaEmp() {
		return this.alEmprestimos;
	}

	public void setListaEmp(ListaEmprestimos listaEmp) {
		this.alEmprestimos = listaEmp;
	}

	public ListaEmprestimos getAlEmprestimos() {
		return alEmprestimos;
	}

	public void setAlEmprestimos(ListaEmprestimos alEmprestimos) {
		this.alEmprestimos = alEmprestimos;
	}

	public void setAlItem(ArrayList<Item> alItem) {
		this.alItem = alItem;
	}

	public void setLista(ListaAmigos lista) {
		this.lista = lista;
	}
	
}
