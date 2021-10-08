package Testes;
import java.util.ArrayList;
import java.util.Collections;

import Animal.Animal;
import Animal.Cao;
import Animal.Gato;

public class TesteAnimal2 {

	public static void main(String[] args) {
		ArrayList<Animal> zoo = new ArrayList<Animal>(); 
		// armazenar qquer objeto Animal, ou sejam, qquer objeto que seja filho de Animal
		Gato g1 = new Gato("Garfied", 21);  
		Gato g2 = new Gato("Manda-Chuva", 5);
		Gato g3 = new Gato("Batatinha", 6);
		Cao c1 = new Cao("Scooby-Doo", 25);
		zoo.add(g1);
		zoo.add(g2);
		zoo.add(g3);
		zoo.add(c1);

		System.out.println("Animais no Zoo: " + zoo.size());
		for (Animal animal : zoo) {
			System.out.println (animal);
		}
		
		zoo.add(new Cao("Rin tin tin", 29));
		zoo.add(new Cao("Lassie", 29));
		System.out.println("\nAnimais no Zoo: " + zoo.size());
		Collections.sort(zoo);
		System.out.println("Ordem alfabética:");
		for (Animal animal : zoo) {
			System.out.println (animal);
		}		  
	}

}
