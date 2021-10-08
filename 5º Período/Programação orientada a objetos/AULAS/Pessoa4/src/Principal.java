import java.util.ArrayList;


public class Principal {

	public static void main(String[] args) {
		// testando os construtores
		Pessoa p1 = new Pessoa("Josias Mequetrefe");
		Endereco e2 = new Endereco("Rua das Flores", 123, "Curitiba", "PR", "80123-123");
		Pessoa p2 = new Pessoa ("Ciclano de Tal", e2);
		Pessoa p3 = new Pessoa("Fulano de Tal", "ft_matador", new Endereco("Rua das Pinheiros", 987, "Araucaria", "PR", "85245-2453"));
		int v[] = new int[10];
		for (int i = 0; i < v.length; i++) {
			System.out.print(v[i]+" ");	
			}
		int m[][] = new int[4][4];
		m[2][2] = 21;
		System.out.println();
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.length; j++) {
				System.out.print(m[i][j]+" ");
			}
			System.out.println();
		}
		Pessoa equipe[] = new Pessoa[3]; //vetor de objetos Pessoa
		//atribuir valores
		equipe[0] = p1;
		equipe[1] = p2;
		equipe[2] = p3;
		for (int i = 0; i < 3; i++) {
			System.out.println(equipe[i].getNome());
		}
		
		//alocacao dinamica
		ArrayList<Pessoa> grupo = new ArrayList<Pessoa>();
		grupo.add(p1);
		grupo.add(p1);	
		grupo.add(p3);
		grupo.add(new Pessoa("Quarto membro da banda"));
		System.out.println(grupo);
		for (int i = 0; i < grupo.size(); i++) {
			System.out.println(grupo.get(i).getNome());
			
		}
	}
}
