package Item;

import java.io.Serializable;

/**
 * <p>Classe do pacote Item<p/>
 * <p>Classe representa uma conta na plataforma de jogos online Steam, representando não só informações de login como a quantidade de jogos
 * que estão comprados pela conta</p>
 * @author Cezário
 * @since 1.0
 * @see Biblioteca, Item
 */

public class ContaSteam extends Item implements Serializable {
	private String usuario, senha;
	int numeroJogos;
	String tipo = "Conta da Steam";
	
	/**
	 * Método construtor único para o item
	 * @param String usuario para login do usuario
	 * @param String senha para login do usuario
	 * @param int numeroJogos quantidade de jogos na conta envolvida
	 * @param int IdItem Id do item na lista de itens da biblioteca utilizada
	 * @param String tituloItem Nome do registro na lista de itens
	 * @param Disponibilidade dispItem Disponibilidade 
	 */
	
	public ContaSteam(String usuario, String senha, int numeroJogos
			      , int IdItem, String tituloItem, Disponibilidade dispItem){
		super();
		this.senha = senha;
		this.usuario = usuario;
		this.numeroJogos = numeroJogos;
		super.setIdItem(IdItem);
		super.setTituloItem(tituloItem);
		super.setDispItem(dispItem);
	}

	public String getTipo() {
		return this.tipo;
	}

	/**
	 * @Override
	 * toString com sequência Tipo --> Titulo no registro --> Usuario --> número de jogos presentes
	 */
	public String toString() {
		String mensagem = "\n\nConta da Steam \nNome da conta em registro " + this.getTituloItem()+ " \nUsuario: " +this.usuario+"\n" +
						   "Com "+this.numeroJogos + " jogos \n\n";
		return mensagem;
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

	public int getNumeroJogos() {
		return numeroJogos;
	}

	public void setNumeroJogos(int numeroJogos) {
		this.numeroJogos = numeroJogos;
	}	
}
