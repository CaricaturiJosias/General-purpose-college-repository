package Testes;
import Animal.Gato;

/**
 * 
 */

/**
 * @author hfebe
 *
 */
public class TestaAnimal1 {

	public static void main(String[] args) {
		// uma vez que Animal ficou Abstract, não pode mais ser instanciada
		//Animal a1 = new Animal("Animal X", 99); 
		Gato a2 = new Gato("Garfied", 21);  
		
		//System.out.println(a1);
		System.out.println(a2.toString());
		System.out.println(a2.seLamber());
		a2.setNome("Belinha");
		System.out.println(a2);
	}

}  
