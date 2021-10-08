package Animais;
import Interfaces.AnimalExtincao;

public class GatoMaracaja extends Felino implements AnimalExtincao {

	public GatoMaracaja(String nome, float peso) {
		super(nome, peso);
	}
	
	@Override
	public void atacar(Animal animal) {
		if (animal instanceof GatoMaracaja) {
			System.out.println("N�o vou atacar o/a "+animal.getNome()+" pois somos da mesma esp�cie");
		}
		else {
			System.out.println("Atacando um "+animal.euSouUm()+" chamado "+animal.getNome()+" porque n�o tenho medo!");

		}
	}

	@Override
	public void salve_me() {
		System.out.println("Sou um gato maracaja, estou em risco de extin��o! Ajude a me salvar, contate uma ONG! ");
	}

	@Override
	public void fazerBarulho() {
		System.out.println(getNome()+" n�o faz barulho pois tem cuidado com os arredores....");
	}

}
