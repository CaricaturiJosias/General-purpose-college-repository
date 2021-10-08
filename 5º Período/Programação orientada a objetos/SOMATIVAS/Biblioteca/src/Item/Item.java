package Item;

import java.io.Serializable;

/**
 * <p>Classe abstrata do pacote Item<p/>
 * <p>Item diz respeito a qualquer item que possa ser registrado na biblioteca, tendo assim os parâmetros abstratos de item </p>
 * @author Cezário
 * @since 1.0
 * @see {@linkplain Livro}, {@linkplain ContaNetflix} ,{@linkplain ContaSteam}
 */

public abstract class Item implements Comparable<Item>, Serializable{
	
	private int IdItem;
	private String tituloItem;
	private Disponibilidade dispItem;
	
	/**
	 * @Override
	 * compareTo com ignoreCase para o parâmetro titulo do item
	 */
	public int compareTo(Item item) {
		return tituloItem.compareToIgnoreCase(item.tituloItem);
	}
	
	public int getIdItem() {
		return IdItem;
	}
	
	public void setIdItem(int idItem) {
		IdItem = idItem;
	}
	public String getTituloItem() {
		return tituloItem;
	}
	public void setTituloItem(String tituloItem) {
		this.tituloItem = tituloItem;
	}
	public Disponibilidade getDispItem() {
		return dispItem;
	}
	public void setDispItem(Disponibilidade dispItem) {
		this.dispItem = dispItem;
	}
	
	public abstract String getTipo();
	
}



