import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Scanner;

public class Estacionamento {

	private Vaga[] vagas;
	private ArrayList<Vaga> historico;
	private ArrayList<Marca> marcas;
	
	//por padrão o estacionamento inicia vazio no começo do código (sem hardcoded)
	
	public Estacionamento() {
		this.vagas = new Vaga[100];
		this.historico = new ArrayList<Vaga>();
		this.marcas = new ArrayList<Marca>();
	}
	//hardcoded
	public Estacionamento(Carro carros[], Marca marcas[]) {
		this.vagas = new Vaga[100];
		this.historico = new ArrayList<Vaga>();
		this.marcas = new ArrayList<Marca>();
		
		for (int i = 0; i<carros.length;i++) {
			this.vagas[i] = new Vaga(carros[i]);
		}
		for (int i = 0; i<marcas.length;i++) {
			this.marcas.add(marcas[i]);
		}
		
	}
	//hardcoded
	public void setCarro(Carro carro, LocalDateTime entrada, LocalDateTime saida) {
		Vaga novaVaga = new Vaga(carro, entrada, saida);
		for (int i = 0; i<100; i++) {
			if (this.vagas[i]==null) {
				this.vagas[i] = novaVaga;
				System.out.println("Carro registrado na vaga "+(i+1));
				this.historico.add(novaVaga);
				return;
				
			}
		}
	}
	
	public void setCarro() {			
		int opcao;
		Scanner entrada = new Scanner(System.in);
		System.out.println("Escolha uma das marcas");
		this.getMarcas();
		opcao = entrada.nextInt();
		entrada.nextLine();
		while (opcao== 0 || opcao > this.marcas.size()) {
			this.setMarca();
			System.out.println("Mostrando marcas novamente");
			this.getMarcas();
			opcao = entrada.nextInt();
		}
		//pega a marca, apresenta a escolhida, e prepara para apresentar os modelos
		while (opcao >= this.marcas.size()-1) {
				System.out.println("Marca escolhida: "+this.marcas.get(opcao-1).getMarca());
				Marca marcaEscolhida = this.marcas.get(opcao-1);
				//caso não existam modelos na marca
				if (marcaEscolhida.getModelosMarca().size() == 0) {
					System.out.println("Nenhum modelo encontrado, criação de um novo abaixo");
					this.setModelo(marcaEscolhida);
				}
				// get = mostrar os modelos
				this.getModelosUmaMarca(marcaEscolhida);
				marcaEscolhida.getModelosDaMarca();
				opcao = entrada.nextInt();
				//loop para caso o modelo desejado não esteja aparecendo
				while(opcao==0 || opcao>marcaEscolhida.getModelosMarca().size()) {
					this.setModelo(marcaEscolhida);
					System.out.println("Mostrando modelos novamente");
					this.getModelosUmaMarca(marcaEscolhida);
					opcao = entrada.nextInt();
				}
				//fim do loop
				// escolheu a marca e o modelo e a salvou em marcaEscolhida e nos modelos da marca, respectivamente
				Modelo modeloEscolhido = marcaEscolhida.getModelosMarca().get(opcao-1);
				System.out.println("Insira a placa do carro \nPlaca: ");					
				entrada.nextLine();
				String placa = entrada.next();
				while(placa.length()>9) {
					System.out.println("Insira uma placa de carro valida \nPlaca: ");					
					placa = entrada.next();
				}
				Carro carroFinal = new Carro(marcaEscolhida, modeloEscolhido, placa);
				for (int i = 0; i<100; i++) {
					if (this.vagas[i]==null) {
						Vaga vaga = new Vaga(carroFinal);		
						this.vagas[i] = vaga;
						System.out.println("Carro registrado na vaga "+(i+1));
						return;
					}
				}
			}
		}

	public void getCarro(int NumVaga){
		if (this.vagas[NumVaga-1]==null) {
			System.out.println("Esta vaga está vazia!");
			return;
		}
		else {
			if (this.vagas[NumVaga-1].getHoraSaida() == null) {
				this.vagas[NumVaga-1].setHoraSaida(LocalDateTime.now());
			}
			System.out.println("Valor da estadia do "+ this.vagas[NumVaga-1].getOcupaVaga().getModelo().getModelo()+
					" de placa "+this.vagas[NumVaga-1].getOcupaVaga().getPlaca()+ " é de R$" +this.vagas[NumVaga-1].getValor(this.vagas[NumVaga-1].getHoraSaida())
					+ "\nEntrou às \n" + DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss").format(this.vagas[NumVaga-1].getHoraEntrada())
					+ "\ne saiu às \n"+DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss").format(LocalDateTime.now()));
			this.historico.add(this.vagas[NumVaga-1]);
			this.vagas[NumVaga-1] = null;
		}
	}
	
	public Marca getMarca() {
		if (this.hasMarca() == false){
			System.out.println("Primeiramente, não existe nenhuma marca registrada, registre uma a seguir");
			this.setMarca();		 
			}
		Scanner input = new Scanner(System.in);
		System.out.println("Marcas registradas: ");
		this.getMarcas();
		int opcao = input.nextInt();
		while(opcao == 0 || opcao > this.marcas.size()) {
			if (opcao == 0) {
				this.setMarca();	
			}
			this.getMarcas();
			opcao = input.nextInt();
		}
		return this.marcas.get(opcao-1);
	}
	
	public void getMarcas() {
		if (this.marcas != null) {
			for (Marca marca: this.marcas) {
				System.out.println((this.marcas.indexOf(marca)+1)+" - "+marca.getMarca());
			}
			System.out.println("Insira o número da marca desejada\nNão encontrou sua marca? Adicione uma inserindo 0"
							 + "\nOpção: ");
			return;
		}
		else {
			System.out.println("Não foram encontradas marcas registradas");
		}
	}

	public void getModelosUmaMarca(Marca marca) {
		Iterator<Modelo> iterator = marca.getModelosMarca().iterator();
		while (iterator.hasNext()) {
			Modelo proximoModelo = iterator.next();
			System.out.println(marca.getModelosMarca().indexOf(proximoModelo)+1+" - "+proximoModelo.getModelo());
		}
		System.out.println("Insira o número do modelo desejado\nNão encontrou o modelo que deseja? Insira 0 para cadastrar "
				+ "um novo\nOpção: ");
	}
	
	public void getHistorico(LocalDateTime data) {
		ArrayList<Vaga> entraram = new ArrayList<Vaga>();
		ArrayList<Vaga> sairam = new ArrayList<Vaga>();
		String dataStr = DateTimeFormatter.ofPattern("dd/MM/yyyy").format(data);
		System.out.println("\n-------- Histórico --------"
						 + "\nDia: "+dataStr);
		Iterator<Vaga> iterador = this.historico.iterator();
		while(iterador.hasNext()) {
			Vaga vaga = iterador.next();
			if (vaga.getHoraEntrada().getDayOfYear() == data.getDayOfYear()) {
				entraram.add(vaga);
			}
			if (vaga.getHoraSaida().getDayOfYear() == data.getDayOfYear()) {
				sairam.add(vaga);
			}
		}
		//devolve os que entraram e sairam
		Iterator<Vaga> iteradorEntrada = entraram.iterator();
		Iterator<Vaga> iteradorSaida = sairam.iterator();
		System.out.println("Entrada de veículos\n");
		while (iteradorEntrada.hasNext()) {
			Vaga entrou = iteradorEntrada.next();
			System.out.print("Marca: "+entrou.getOcupaVaga().getMarca().getMarca()
							+"\nModelo: "+entrou.getOcupaVaga().getModelo().getModelo()
							+"\nPlaca: "+entrou.getOcupaVaga().getPlaca()
							+"\nEntrada: "+DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm").format(entrou.getHoraEntrada())+"\n\n");
		}
		float faturadoFinal = 0;
		System.out.println("\nSaída de veículos\n");
		while(iteradorSaida.hasNext()) {
			Vaga saiu = iteradorSaida.next();
			System.out.print("Marca: "+saiu.getOcupaVaga().getMarca().getMarca()
					+"\nModelo: "+saiu.getOcupaVaga().getModelo().getModelo()
					+"\nPlaca: "+saiu.getOcupaVaga().getPlaca()
					+"\nEntrada: "+DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm").format(saiu.getHoraEntrada())
					+"\nSaida: "+DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm").format(saiu.getHoraSaida())
					+"\nValor da estadia:  "+saiu.getValor()+"\n\n");
			faturadoFinal += saiu.getValor();
		}
		System.out.println("\nTotal de lucro ao final do dia: "+faturadoFinal+"\n\n");
	}


	public void setMarca() {
		Scanner input = new Scanner(System.in);
		System.out.println("Nova marca\n"
						 + "Insira o nome da nova marca: ");
		String marcaNome = input.next();
		System.out.println(marcaNome);
		Marca novaMarca = new Marca(marcaNome);
		this.marcas.add(novaMarca);
	}
	
	public void setModelo(Marca marca) {
		System.out.println("Insira o nome do modelo: ");
		Scanner scan = new Scanner(System.in); 
		String modelo = scan.next();
		Modelo novoModelo = new Modelo(modelo, marca);
		marca.setModelo(novoModelo);
	}
	public boolean hasMarca() {
		if (this.marcas.isEmpty() == true) {
			return false;
		}
		return true;
		}
}
		

