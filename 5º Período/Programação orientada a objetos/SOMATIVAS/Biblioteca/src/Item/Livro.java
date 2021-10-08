package Item;

import java.io.Serializable;

/**
 * <p>Classe do pacote Item<p/>
 * Livro diz respeito a qualquer obra literária com mais de 50 páginas
 * @author Cezário
 * @since 1.0
 */

public class Livro extends Item implements Serializable {
	
	private String autorLivro;
	private int totPagLivro;
	private String tipo = "Livro";
	
	
	/**
	 * Método construtor único pra Item Livro
	 * @param String autor do livro
	 * @param int totalPaginas autoexplicativo
	 * @param int IdItem Numeração do item na lista
	 * @param String tituloItem Nome do item no registro
	 * @param Disponibilidade dispItem Disponibilidade do item no momento de checagem
	 */
	
public Livro(String autor, int totalPaginas, int IdItem
		   , String tituloItem, Disponibilidade dispItem){
	super();
	this.autorLivro = autor;
	this.totPagLivro = totalPaginas;
	super.setIdItem(IdItem);
	super.setTituloItem(tituloItem);
	super.setDispItem(dispItem);
}


/**
 * @Override
 * toString modificado para Autor --> Titulo do livro
 */
public String toString() {
	String mensagem = "\n\nLivro do autor " + autorLivro
	 + "\nTítulo do livro: "+this.getTituloItem()+"\n\n";
	return mensagem;
}



public String getTipo() {
	return tipo;
}

public String getAutorLivro() {
	return autorLivro;
}

public void setAutorLivro(String autorLivro) {
	this.autorLivro = autorLivro;
}

public int getTotPagLivro() {
	return totPagLivro;
}

public void setTotPagLivro(int totPagLivro) {
	this.totPagLivro = totPagLivro;
}
	


}
