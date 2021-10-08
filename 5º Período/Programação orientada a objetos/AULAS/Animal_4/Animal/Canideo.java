/**
 * 
 */
package Animal;

/**
 * 
 * <p>Can�deo � uma fam�lia de mam�feros da ordem Carnivora que engloba c�es, lobos, chacais, coiotes e raposas.</p>
 *
 *	@since 4.0
 *  @author hfebe 
 *  @see Animal
 */
public abstract class Canideo extends Animal {

	/**
	 * @param nome  O nome pr�prio do animal
	 * @param peso  O peso de animal
	 */
	public Canideo(String nome, float peso) {
		super(nome, peso);
	}
	
	// Canideo, por se classe abstrata, n�o precisa implementar
	// public abstract String fazerBarulho();
	// ela passa a responsa adiante, para as classes concretas

	// esconderOsso � concreto, � comum a todas as suas sub classes
	public String esconderOsso() {
		return  this.getNome() + " escondendo seu osso!";
	}
	
	// idem, todas as filhas podem esconder Osso
	public String farejar() {
		return  this.getNome() + " farejando algo!";
	}
}
