import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;

public class Vaga {
	
	private Carro ocupaVaga;
	
	private LocalDateTime horaEntrada;
	
	private LocalDateTime horaSaida;
	
	private float valor = 10;
//////////////////////////////////////////////////////////////////////////
	//CONSTRUTORES
	
	public Vaga(Carro ocupaVaga) {
		this.ocupaVaga = ocupaVaga;
		this.horaEntrada = LocalDateTime.now();
		this.horaSaida = null;
	}
	
	public Vaga() {
		this.ocupaVaga = null;
		this.horaSaida = null;
	}
	// overload para hardcoded
	public Vaga(Carro carro, LocalDateTime entrada, LocalDateTime saida) {
		this.ocupaVaga = carro;
		this.horaEntrada = entrada;
		this.horaSaida = saida;
	}
//////////////////////////////////////////////////////////////////////////
	//NÃO CONSTRUTORES
	public Carro getOcupaVaga(){
		return this.ocupaVaga;
	}
	public void setOcupaVaga(Carro carro) {
		this.ocupaVaga = carro;
		this.horaEntrada = LocalDateTime.now();
	}
	
	public LocalDateTime getHoraEntrada() {
		return this.horaEntrada;
	}
	
	public void setHoraSaida(LocalDateTime saida) {
		 this.horaSaida = saida;
	}
	public LocalDateTime getHoraSaida() {
		return this.horaSaida;
	}
	
	public float getValor(LocalDateTime horaSaida) {
		long minutos =  ChronoUnit.MINUTES.between(horaEntrada, horaSaida);
		if (minutos > 60){
			int min = (int)minutos-60;
			min = min/15;
			this.valor += min*2;
		}
		return valor;
	}
	public float getValor() {
		long minutos =  ChronoUnit.MINUTES.between(horaEntrada, horaSaida);
		if (minutos > 60){
		int min = (int)minutos-60;
		int quartoDeHora = min/15;
		this.valor = 10 + quartoDeHora*2;
		}
		return valor;
	}
}

