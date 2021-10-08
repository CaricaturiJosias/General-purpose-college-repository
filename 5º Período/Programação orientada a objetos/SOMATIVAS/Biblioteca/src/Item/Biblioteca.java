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
 * <p>Biblioteca � uma classe representando um registro de livros, contas da Netflix e da Steam, onde � poss�vel
 * se cadastrar, realizar um empr�stimo e checar a disponibilidade de itens assim como alter�-la</p>
 * @since 1.0
 * @author Cez�rio
 * @see {@linkplain ContaNetflix}, {@linkplain Livro}, {@linkplain ListaAmigos}, {@linkplain ListaEmprestimos}
 */


public class Biblioteca implements Serializable{

	private String nomeBib;
	private ArrayList<Item> alItem;
	private ListaAmigos lista;
	private ListaEmprestimos alEmprestimos;
	
	/**
	 * Construtor padr�o para inicializa��o da biblioteca, somente com <code>nomeBib</code>
	 * 
	 * @param nomeBib Nome da biblioteca dado na cria��o de qualquer inst�ncia de {@linkplain Biblioteca}
	 * @param alItem Lista de itens em ArrayList<Item> (vide {@linkplain Item})
	 * @param lista Lista de amigos presentes nos registros da biblioteca (Vide {@linkplain ListaAmigos} e {@linkplain Amigo})
	 * @param alEmprestimos Lista de emprestimos, cont�m todos os empr�stimos existentes no c�digo (vide {@linkplain ListaEmprestimos} e
	 * {@linkplain Emprestimo})
	 */
	
	public Biblioteca(String nomeBib) {
		this.nomeBib = nomeBib;
		this.alItem = new ArrayList<Item>();
		this.lista = new ListaAmigos();
		this.alEmprestimos = new ListaEmprestimos();
		
	}
	
	/**
	 * <p>M�todo construtor de {@linkplain Biblioteca} quando � feita leitura de uma inst�ncia em disco r�gido</p>
	 * @param bib � a biblioteca lida em disco r�gido
	 * @param nomeBib Nome da biblioteca dado na cria��o de qualquer inst�ncia de {@linkplain Biblioteca}
	 * @param alItem Lista de itens em ArrayList<Item> (vide {@linkplain Item})
	 * @param lista Lista de amigos presentes nos registros da biblioteca (Vide {@linkplain ListaAmigos} e {@linkplain Amigo})
	 * @param alEmprestimos Lista de emprestimos, cont�m todos os empr�stimos existentes no c�digo, devolvidos ou n�o
	 * (vide {@linkplain ListaEmprestimos} e {@linkplain Emprestimo}) 
	 */
	
	//salvo em disco
	public Biblioteca(Biblioteca bib) {
		this.alItem = bib.getAlItem();
		this.lista = bib.getLista();
		this.nomeBib = bib.getNomeBib();
		this.alEmprestimos = bib.alEmprestimos;
	}
	
	// m�todos
	
	/**
	 * Fun��o feita para recuperar todos os empr�stimos com um �nico item (vide {@linkplain Item} e {@linkplain ListaEmprestimo})
	 * @param idItem Id dado pelo usu�rio para consulta do hist�rico
	 * @return A sa�da da a confirma��o ou falha do processo, no caso de confirma��o lista as caracter�sticas de cada empr�stimo (vide 
	 * {@linkplain Emprestimo}) em uma �nica string devolvida para o processo principal ({@linkplain Principal.Principal})
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
						+ "\nPrevis�o de entrega: " + prox.getDataDevolucao().format(DateTimeFormatter.ofPattern("dd/MM/uuuu"))
						+ "\nData real da entrega: ";
				
				if (prox.getDataDevolvido() == null) {
				saida = saida + "entrega n�o realizada at� o momento\n";
				
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
	 * Fun��o para expor todos os empr�stimos atualmente, ou seja, com disponibilidade EMPRESTADO no momento de checagem
	 * @return <code>String</code> com sucesso ou falha de obter registros, sucesso devolve a lista com todos os empr�stimos no momento,
	 * enquanto falha acusar� a falta de empr�stimos atualmente.
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
			saida = "Nenhum empr�stimo encontrado!";
		}
		return saida;
	}
	
	/**
	 * @param idEmprestimo Indica a numera��o do indiv�duo a emprestar o item em {@linkplain ListaAmigos}
	 * @param idEmprestador Indica a numera��o do item emprestado
	 * @param devolu��oPrevista Data dada pelo amigo emprestador no formato de LocalDateTime
	 * @return String - confirmador da opera��o, exibindo dados do item emprestado e acusador de falha caso necess�rio
	 * @see {@linkplain Emprestimo}, {@linkplain LocalDateTime} e {@linkplain Amigo}
	 */
	
	public String emprestimo(int idEmprestimo, int idEmprestador, LocalDateTime devolu��oPrevista) {
		LocalDateTime horaAgora = LocalDateTime.now();
		if (this.alItem.get(idEmprestimo).getDispItem() != Disponibilidade.DISPONIVEL) {
			return "\nItem n�o dispon�vel, pois ele est� registrado como " 
				 + this.alItem.get(idEmprestimo).getDispItem().toString();
		}		
		if (devolu��oPrevista.isAfter(horaAgora)) {
			this.alItem.get(idEmprestimo).setDispItem(Disponibilidade.EMPRESTADO);
			Emprestimo novoEmprestimo = new Emprestimo(idEmprestador, idEmprestimo, horaAgora, devolu��oPrevista
					, this.lista.getAlAmigos().get(idEmprestador), this.alItem.get(idEmprestimo));
			this.getListaEmp().getAlEmprestimos().add(novoEmprestimo);
			return "\nEmprestimo de um(a) " + novoEmprestimo.getItem().getTipo() + " feito com sucesso!\n";
		} else {
			return "\nN�o ser� poss�vel realizar o emprestimo nessa data, pois j� passou.\n";
		}
	}
	
	/**
	 * Fun��o para fazer a devolu��o de um item emprestado
	 * @param idItem Id do item a ser devolvido, checando se ele est� em regime de emprestimo
	 * @param idAmigo Id do amigo devolvendo o item, checando se ele foi aquele que o emprestou inicialmente
	 * @return String acusando sucesso ou falha da opera��o, sucesso evidenciando dados como data de entrega e item entregue
	 * @see {@linkplain Item}, {@linkplain Amigo}
	 */
	
	public String devolver(int idItem, int idAmigo){		
		String saida = "\nHouve algum erro";
		if (this.getAlItem().get(idItem).getDispItem() != Disponibilidade.EMPRESTADO) {
			return "\nO item com esse ID n�o � pass�vel de devolu��o.\n";
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
					saida = "Voc� n�o pode devolver esse item, pois n�o � o(a) " + daVez.getAmigo().getNomeAmigo();
				}
			}
		}
		return saida;
		}
	
	/**
	 * M�todo para cadastrar um Amigo na lista de amigos da biblioteca
	 * @return String confirmador� do registro
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
	 * @return String confirmador do registro com informa��es do novo item ou mensagem de erro denunciando algo errado
	 * @see {@linkplain Livro}, {@linkplain ContaSteam}, {@linkplain ContaNetflix} e {@linkplain Item}
	 */
	
	public String cadastroItem(int escolha) {
		String saida;
		Scanner input = new Scanner(System.in);
		String titulo, autor, usuario, senha;
		switch (escolha) {
			case 1:
				System.out.println("Insira o t�tulo do livro: ");
				titulo = input.nextLine();
				System.out.println("Insira o nome do autor: ");
				autor = input.nextLine();
				System.out.println("Insira o total de p�ginas: ");
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
				System.out.println("Insira o nome da conta (para visualiza��o): ");
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
				System.out.println("Insira o nome da conta (para visualiza��o): ");
				titulo = input.nextLine();
				System.out.println("Insira o usuario da conta: ");
				usuario = input.nextLine();
				System.out.println("Insira a senha da conta: ");
				senha = input.nextLine();
				System.out.println("Insira o n�mero de jogos na conta: ");
				int numJogos = input.nextInt();
				ContaSteam novaContaSteam = new ContaSteam(usuario, senha, numJogos, this.getAlItem().size()
														, titulo, Disponibilidade.DISPONIVEL);
				this.alItem.add(novaContaSteam);
				saida = novaContaSteam.toString();
				break;
				
			default:
				saida = "N�o foi selecionado um item v�lido";
				break;
		}
		return saida;
	}
	
	/**
	 * <p>Fun��o feita para simplificar amostragem dos itens registrados, usados em outras fun��es na classe Principal</p>
	 * <p>Est� na classe Biblioteca e n�o na Principal pois � necess�rio acesso aos itens</p>
	 * @return String com todos os itens listados na lista de itens da biblioteca atual
	 * @see {@linkplain Item}, {@linkplain Biblioteca} e {@linkplain Principal}
	 */
	
	public String showItem() {
		String Mensagem =null;
		Iterator<Item> iterador = this.alItem.iterator();
		while(iterador.hasNext()) {
			Item current = iterador.next();
			if (Mensagem != null) {
				Mensagem = Mensagem +"\n"+ current.toString()+"C�digo do item: "+(current.getIdItem()+1)+"\nDisponibilidade: "
									+ current.getDispItem().toString() ;
			} else {
				Mensagem = "\n" + current.toString()+"C�digo do item: "+(current.getIdItem()+1)+"\nDisponibilidade: "
						 + current.getDispItem().toString();
			}
		}
		return Mensagem;
	}
	
	/**
	 * <p>Fun��o para mudar o estado de disponibilidade de algum item via seu id na lista de itens da biblioteca</p>
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
				saida = "Estado mudado com sucesso para DISPON�VEL!";
				break;
			default:
				saida = "Estado n�o modificado com sucesso!";
				break;
		}
		return saida;
	}
	
	
	
	 // M�todos getters e setters 
	 
	
	
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
