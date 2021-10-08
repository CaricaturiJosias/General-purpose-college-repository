package Amigo;

import java.io.Serializable;

/**
 * <p>Classe do pacote Amigo</p>
 * <p>Amigo representa uma pessoa com acesso a biblioteca, podendo emprestar e devolver os itens presentes nela</p>
 * @since 1.0
 * @author Cezário
 * @see {@linkplain ListaAmigos}, {@linkplain Item}, {@linkplain Emprestimo.Emprestimo}
 */

public class Amigo implements Serializable{

	private int idAmigo;
	private String nomeAmigo;
/**
 * Único construtor da classe Amigo
 * @param idAmigo int id do amigo na ListaAmigos
 * @param nomeAmigo String nome do Amigo
 */
	public Amigo (int idAmigo, String nomeAmigo) {
		this.setIdAmigo(idAmigo);
		this.setNomeAmigo(nomeAmigo);
	}

	public int getIdAmigo() {
		return idAmigo;
	}

	public void setIdAmigo(int idAmigo) {
		this.idAmigo = idAmigo;
	}

	public String getNomeAmigo() {
		return nomeAmigo;
	}

	public void setNomeAmigo(String nomeAmigo) {
		this.nomeAmigo = nomeAmigo;
	}

	@Override
	public String toString() {
		return "Amigo chamado " + this.nomeAmigo;
	}
}
