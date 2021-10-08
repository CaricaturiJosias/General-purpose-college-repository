package Testes;
import java.util.ArrayList;

import Animal.*;

public class TesteAnimal3 {

	public static void main(String[] args) {
		ArrayList<Animal> zoo = new ArrayList<Animal>(); 
		// armazenar qquer objeto Animal, ou sejam, qquer objeto que seja filho de Animal
		Gato g1 = new Gato("Garfied", 21);  
		Gato g2 = new Gato("Manda-Chuva", 5);
		Gato g3 = new Gato("Batatinha", 6);
		Cao c1 = new Cao("Scooby-Doo", 25);
		zoo.add(g1);
		zoo.add(c1);
		zoo.add(g2);
		zoo.add(g3);
		zoo.add(new Cao("Rin tin tin", 29));
		zoo.add(new Cao("Lassie", 29));
		System.out.println("Animais no Zoo: " + zoo.size());

		for (Animal animal : zoo) {
			System.out.println ("\n"+animal.fazerBarulho());
			
			// instanceof verifica se o objeto em questão (da classe Animal) é também instância de (Gato)
			if (animal instanceof Gato) {
				Gato g = (Gato)animal;  // usando variável local para coerção
				System.out.println(g.seLamber());
			}
			if (animal instanceof Cao) {
				System.out.println(((Cao)animal).esconderOsso());
				// usando direto apenas para invocar esconderOsso
			}
		}		  
	}

}
