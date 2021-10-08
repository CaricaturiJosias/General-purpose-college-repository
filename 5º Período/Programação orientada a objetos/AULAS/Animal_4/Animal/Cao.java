package Animal;
/**
 * 
 */

/**
 * @author hfebe
 *
 */
public class Cao extends Canideo {

	/**
	 * @param nome  O nome próprio do animal
	 * @param peso  O peso de animal
	 */
	public Cao(String nome, float peso) {
		super(nome, peso);
	}
	
	public String cavarBuraco() {
		return  this.getNome() + " cavando buraco!";
	}
	
	public String latir() {
		return this.getNome() + " latindo: au, au, au, au.....";
	}

	@Override
	public String fazerBarulho() {
		return latir();
	}
}
