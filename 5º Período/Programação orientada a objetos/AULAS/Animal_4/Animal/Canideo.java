/**
 * 
 */
package Animal;

/**
 * 
 * <p>Canídeo é uma família de mamíferos da ordem Carnivora que engloba cães, lobos, chacais, coiotes e raposas.</p>
 *
 *	@since 4.0
 *  @author hfebe 
 *  @see Animal
 */
public abstract class Canideo extends Animal {

	/**
	 * @param nome  O nome próprio do animal
	 * @param peso  O peso de animal
	 */
	public Canideo(String nome, float peso) {
		super(nome, peso);
	}
	
	// Canideo, por se classe abstrata, não precisa implementar
	// public abstract String fazerBarulho();
	// ela passa a responsa adiante, para as classes concretas

	// esconderOsso é concreto, é comum a todas as suas sub classes
	public String esconderOsso() {
		return  this.getNome() + " escondendo seu osso!";
	}
	
	// idem, todas as filhas podem esconder Osso
	public String farejar() {
		return  this.getNome() + " farejando algo!";
	}
}
