package Amigo;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * <p>Classe do pacote Amigo</p>
 * <p>Lista de amigos é o registro de pessoas com acesso a biblioteca, as ações que um amigo pode fazer é descrita em
 * {@linkplain Amigo}
 * @author Gabriel
 * @since 1.0
 * @see {@linkplain Biblioteca}
 */

public class ListaAmigos implements Serializable{

	private ArrayList<Amigo> alAmigos;
	
	/**
	 * Método construtor de uma lista de amigos sozinhas
	 */
	
	public ListaAmigos() { 
		this.alAmigos = new ArrayList<Amigo>();
	}
	
	/**
	 * Método construtor para hardcoded ou com leitura em disco rígido
	 * @param ArrayList<Amigo> lista hardcoded ou lida em disco rígido
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
		String saida = "A lista de amigos é exibida a seguir\n";
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
