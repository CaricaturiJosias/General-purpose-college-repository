package Amigo;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * <p>Classe do pacote Amigo</p>
 * <p>Lista de amigos � o registro de pessoas com acesso a biblioteca, as a��es que um amigo pode fazer � descrita em
 * {@linkplain Amigo}
 * @author Gabriel
 * @since 1.0
 * @see {@linkplain Biblioteca}
 */

public class ListaAmigos implements Serializable{

	private ArrayList<Amigo> alAmigos;
	
	/**
	 * M�todo construtor de uma lista de amigos sozinhas
	 */
	
	public ListaAmigos() { 
		this.alAmigos = new ArrayList<Amigo>();
	}
	
	/**
	 * M�todo construtor para hardcoded ou com leitura em disco r�gido
	 * @param ArrayList<Amigo> lista hardcoded ou lida em disco r�gido
	 * @see {@linkplain Amigo}
	 */
	
	public ListaAmigos(ArrayList<Amigo> lista) { 
		this.alAmigos = lista;
	}
	
	public ArrayList<Amigo> getAlAmigos() {
		return alAmigos;
	}
	// construtor
	// toString
	
	@Override
	public String toString() {
		String saida = "A lista de amigos � exibida a seguir\n";
		Iterator<Amigo> iterador = this.alAmigos.iterator();
		while (iterador.hasNext()) {
			Amigo current = iterador.next();
			saida = saida + "\nNome: "+current.getNomeAmigo()+"\nId do amigo: "+(current.getIdAmigo()+1)+"\n";
		}
		return saida;
	}

	public void addAmigos(Amigo amigo) {
		this.alAmigos.add(amigo);
	}	
}
