package Emprestimo;
import java.io.Serializable;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import Amigo.Amigo;
import Item.Item;

/**
 * <p>Classe do pacote Emprestimo</p>
 * <p>Empr�stimo diz respeito ao ato de emprestar algum item para algum amigo, registrando as caracter�sticas do feito, para ser
 * armazenado na lista de emprestimos</p>
 * @author Cez�rio
 * @since 1.0
 * @see {@linkplain ListaEmprestimo}, {@linkplain Amigo}
 */

public class Emprestimo implements Serializable {

	private static int idAmigo;
	private static int idItem;
	private LocalDateTime dataEmprestimo;
	private LocalDateTime dataDevolucao;
	private LocalDateTime dataDevolvido;
	
	// para a equipe pensar nesta repeti��o, pois pode-se obter os objetos pelo IDs
	// servir� para obter dados da pessoa que deve e o tipo de objeto para consulta e visualiza��o
	private Item item;
	private Amigo amigo;
	
	public Emprestimo(int idAmigo, int idItem, LocalDateTime dataEmprestado, LocalDateTime dataDevolucao, Amigo amigo
					 , Item item) {
		this.setDataDevolucao(dataDevolucao);
		this.setDataEmprestimo(dataEmprestado);
		this.setIdItem(idItem);
		this.setIdAmigo(idAmigo);
		this.setAmigo(amigo);
		this.setItem(item);
		this.setDataDevolvido(null);
	}
	
	
	/**
	 * @Override
	 * Override do m�todo toString para demonstra��o de atributos de um empr�stimo
	 */
	public String toString() {
		return this.item.getTipo() + "\nEmprestado(a) por " + this.amigo.getNomeAmigo() + " no dia " 
								   + this.dataEmprestimo.format(DateTimeFormatter.ofPattern("dd/MM/uuuu")) + "\nDevolu��o prevista em "
								   + this.dataDevolucao.format(DateTimeFormatter.ofPattern("dd/MM/uuuu"))
								   +"\nId do item: " + (this.item.getIdItem()+1)+"\n\n";
	}											



	public LocalDateTime getDataDevolvido() {
		return dataDevolvido;
	}

	public void setDataDevolvido(LocalDateTime dataDevolvido) {
		this.dataDevolvido = dataDevolvido;
	}

	public LocalDateTime getDataEmprestimo() {
		return dataEmprestimo;
	}
	public void setDataEmprestimo(LocalDateTime dataEmprestimo) {
		this.dataEmprestimo = dataEmprestimo;
	}
	public LocalDateTime getDataDevolucao() {
		return dataDevolucao;
	}
	public void setDataDevolucao(LocalDateTime dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}
	public int getIdItem() {
		return idItem;
	}
	public void setIdItem(int idItem) {
		this.idItem = idItem;
	}
	public Item getItem() {
		return item;
	}
	public void setItem(Item item) {
		this.item = item;
	}

	public int getIdAmigo() {
		return idAmigo;
	}

	public void setIdAmigo(int idAmigo) {
		this.idAmigo = idAmigo;
	}

	public Amigo getAmigo() {
		return amigo;
	}

	public void setAmigo(Amigo amigo) {
		this.amigo = amigo;
	}
}
