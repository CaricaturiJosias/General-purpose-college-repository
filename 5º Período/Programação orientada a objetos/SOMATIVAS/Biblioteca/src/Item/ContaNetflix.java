package Item;

import java.io.Serializable;

/**
 * <p>Classe do pacote Item<p/>
 * <p>Conta netflix diz respeito a uma conta na plataforma de filmes e séries de mesmo nome (Netflix)</p> 
 * @author Cezário
 * @since 1.0
 * @see Item, Biblioteca
 */

public class ContaNetflix extends Item implements Serializable {

	private String usuario, senha, tipo = "Conta da Netflix";
	/**
	 * Descreve o construtor único de uma conta da netflix passível de ser registrada na biblioteca
	 * @param usuario Indica o usuário para login da conta
	 * @param senha Indica a senha para login da conta
	 * @param IdItem Indica a posição no array de itens
	 * @param tituloItem Indica o nome de registro dentro da biblioteca
	 * @param dispItem Indica a disponibilidade possível do item (vide {@link Disponibilidade})
	 */
	public ContaNetflix(String usuario, String senha
				  , int IdItem, String tituloItem, Disponibilidade dispItem) {
		super();
		this.senha = senha;
		this.usuario = usuario;
		super.setIdItem(IdItem);
		super.setTituloItem(tituloItem);
		super.setDispItem(dispItem);
	}

	/**
	 * @Override
	 * Método toString com padrão Tipo --> Nome da conta --> Usuario s
	 */

	public String toString() {
		String mensagem = "\n\nConta da netflix\nNome da conta em registro " + super.getTituloItem()
		  +"\nUsuario registrado: "+this.getUsuario()+"\n\n";
		return mensagem;
	}
	
	public String getTipo() {
		return tipo;
	}

	public String getUsuario() {
		return usuario;
	}

	public void setUsuario(String usuario) {
		this.usuario = usuario;
	}

	public String getSenha() {
		return senha;
	}

	public void setSenha(String senha) {
		this.senha = senha;
	}
}
