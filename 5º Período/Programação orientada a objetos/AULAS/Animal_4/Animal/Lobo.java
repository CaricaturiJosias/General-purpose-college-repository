/**
 * 
 */
package Animal;

/**
 * @author hfebe
 *
 */
public class Lobo extends Canideo {

	/**
	 * @param nome
	 * @param peso
	 */
	public Lobo(String nome, float peso) {
		super(nome, peso);
	}
	
	public String uivar() {
		return this.getNome() + " uivando: auuuh, auuhhh, auuuhhh.....";
	}

	@Override
	public String fazerBarulho() {
		// TODO Auto-generated method stub
		return uivar();
	}	

}
