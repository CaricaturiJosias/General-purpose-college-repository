import java.util.Scanner;
import java.time.*;
import java.util.regex.Pattern;

public class Main{
	
	//Area do hardcoded
	static Marca Josias = new Marca("Josias");
	static Marca Vetete = new Marca("Vetete");
	static Marca JooJ = new Marca("JooJ");
	
	static Modelo Mequetrefe = new Modelo("Mequetrefe", Josias);
	static Modelo Hotdog = new Modelo("Hotdog", Josias);
	static Modelo Tasmania = new Modelo ("Tasmania", Josias);
	static Modelo CarroKibe = new Modelo("Carro Kibe", Vetete);
	static Modelo TrioEletrico = new Modelo("TrioEletrico", Vetete);
	static Modelo CarrinhoCondor = new Modelo ("Carrinho do condor", Vetete);
	static Modelo DiambaTron = new Modelo("DiambaTron", JooJ);
	static Modelo Pizza = new Modelo("Frango com catupiru", JooJ);
	static Modelo Hamburgi = new Modelo ("Onion rins", JooJ);
	
	static Carro SAS11 = new Carro(Mequetrefe,"saaaas");
	static Carro SAS12 = new Carro(Mequetrefe,"seeees");
	static Carro SAS13 = new Carro(Mequetrefe,"soooos");
	static Carro SAS21 = new Carro(Hotdog,"saaaas");
	static Carro SAS22 = new Carro(Hotdog,"seeees");
	static Carro SAS23 = new Carro(Hotdog,"soooos");
	static Carro SAS31 = new Carro(Tasmania,"saaaaas");
	static Carro SAS32 = new Carro(Tasmania,"seeeees");
	static Carro SAS33 = new Carro(Tasmania,"sooooos");

	static Carro SES11 = new Carro(CarroKibe,"saaaas");
	static Carro SES12 = new Carro(CarroKibe,"seeees");
	static Carro SES13 = new Carro(CarroKibe,"soooos");
	static Carro SES21 = new Carro(TrioEletrico,"saaaas");
	static Carro SES22 = new Carro(TrioEletrico,"seeees");
	static Carro SES23 = new Carro(TrioEletrico,"soooos");
	static Carro SES31 = new Carro(CarrinhoCondor,"saaaas");
	static Carro SES32 = new Carro(CarrinhoCondor,"seeees");
	static Carro SES33 = new Carro(CarrinhoCondor,"soooos");
	
	static Carro SOS11 = new Carro(DiambaTron,"saaaas");
	static Carro SOS12 = new Carro(DiambaTron,"seeees");
	static Carro SOS13 = new Carro(DiambaTron,"soooos");
	static Carro SOS21 = new Carro(Pizza,"saaaas");
	static Carro SOS22 = new Carro(Pizza,"seeees");
	static Carro SOS23 = new Carro(Pizza,"soooos");
	static Carro SOS31 = new Carro(Hamburgi,"saaaas");
	static Carro SOS32 = new Carro(Hamburgi,"seeees");
	static Carro SOS33 = new Carro(Hamburgi,"soooos");
	
	static Carro[] listaCarro = {SOS11, SOS12, SOS13, SOS21, SOS22, SOS23, SOS31, SOS32, SOS33, SES11, SES12,
								 SES13, SES21, SES22, SES23, SES31, SES32, SES33, SAS11, SAS12, SAS13, SAS21,
								 SAS22, SAS23, SAS31, SAS32, SAS33 };

	static Modelo[] listaModelos = {Mequetrefe, Hotdog, Tasmania, CarroKibe, TrioEletrico, CarrinhoCondor, DiambaTron, Pizza,
			Hamburgi};
	
	static Marca[] listaMarca = {Josias, Vetete, JooJ};	
	
	//fim da area do hardcoded
	public static void main(String[] args){
		
		//HARDCODED IMPLEMENTADO
		Estacionamento EstacionamentoDoBereu = new Estacionamento(listaCarro, listaMarca);
		for(Modelo modelo:listaModelos) {
			Josias.setModelo(modelo);
			Vetete.setModelo(modelo);
			JooJ.setModelo(modelo);
		}
		for (int i = 0; i<listaCarro.length; i++) {
			long a = new Long(i);
			EstacionamentoDoBereu.setCarro(listaCarro[i], LocalDateTime.now().plusHours(a*2), LocalDateTime.now().plusDays(a/2));
		}
		
		//FIM DO HARDCODED IMPLEMENTADO
				
		//menu
		Scanner input = new Scanner(System.in);
		System.out.println(	   "============= Inicio do sistema ===============");
		boolean para = true;
		do{
			
			System.out.println("============= Insira uma opção ================\n"
							 + " 0 - Fechar o programa\n"
							 + " 1 - Entrada de carro\n"
							 + " 2 - Saída de carro\n"
							 + " 3 - Registrar marcas\n"
							 + " 4 - Registrar modelos\n"
							 + " 5 - Consultar histórico\n"
							 + " Insira a opção: ");

			int entrada = input.nextInt();
			switch(entrada) {
			case 0:
				input.close();
				System.exit(0);
				
			case 1:
				if (EstacionamentoDoBereu.hasMarca() == false){
					System.out.println("Primeiramente, não existe nenhuma marca registrada, registre uma a seguir");
					EstacionamentoDoBereu.setMarca();		  }
				EstacionamentoDoBereu.setCarro();
				break;
			case 2:
				System.out.println("Insira a vaga do carro que deseja retirar");
				int vaga = input.nextInt();
				while(vaga>101) 		
				{	System.out.println("Número inválido ! Insira a vaga do carro que deseja retirar (1-100)");
					vaga = input.nextInt();}
				EstacionamentoDoBereu.getCarro(vaga);	
				break;
			case 3:
				EstacionamentoDoBereu.setMarca();
				break;
			case 4:
				Marca marca = EstacionamentoDoBereu.getMarca();
				EstacionamentoDoBereu.setModelo(marca);
				break;
			case 5:
				LocalDateTime data = getDiaHistorico();
				EstacionamentoDoBereu.getHistorico(data);
				break;
			default:
				System.out.println("Entrada inválida");
				para = false;
				break;
			}
			
		}while(para == true); 
		input.close();
		System.exit(1);
	}
	
	private static LocalDateTime getDiaHistorico() {
		System.out.println("Consulta do histórico \n"
				 		  +"Insira uma data (dd/mm/aaaa)"
						  +"\nPara realizar a checagem do dia");
		Scanner input = new Scanner(System.in);
		String dataDada = input.next();
		//arruma o parser use.Delimiter para separar entre /'s
		Scanner entrada = new Scanner(dataDada).useDelimiter("/");
		
		int Dia = Integer.parseInt(entrada.next());
		int Mes = Integer.parseInt(entrada.next());
		int Ano = Integer.parseInt(entrada.next());
		
		LocalDateTime data = LocalDateTime.of(Ano, Mes, Dia, 0, 0);
		
		return data;
	}
}


