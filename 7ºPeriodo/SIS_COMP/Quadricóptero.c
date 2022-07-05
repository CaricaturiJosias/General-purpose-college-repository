#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "basic_io.h"

void Aristoteles(void *pvParameters);
void Platao(void *pvParameters);
void Nietzsche(void *pvParameters);
void Hegel(void *pvParameters);
void Kant(void *pvParameters);

TaskHandle_t AristotelesH;
TaskHandle_t PlataoH;
TaskHandle_t NietzscheH;
TaskHandle_t HegelH;
TaskHandle_t KantH;

void pega_garfo(char *filosofo)

// Criando a vari�vel para o sem�foro
xSemaphoreHandle xSemaphore = NULL;

// Variveis globais representando garfos, ela possui o nome do
// fil�sofo usando o garfo
char *garfo1[100] = "";
char *garfo2[100] = "";
char *garfo3[100] = "";
char *garfo4[100] = "";
char *garfo5[100] = "";

char[5][100] *garfos = [garfo1, garfo2, garfo3, garfo4, garfo5]

void pega_garfo(char *filosofo) 
{
	taskENTER_CRITICAL();
	{
		achado = 0;
		// strcmp((garfos[i]), "") retornar 0 significa
		// que o garfo i est� dispon�vel
		for (i = 0; strcmp((garfos[i]), "") == 0, i++) {
			strcpy(garfos[i], filosofo);
			achado++;
		}
		for (i = 0; strcmp((garfos[i]), "") == 0, i++) {
			strcpy(garfos[i], xTaskGetHandle(filosofo);
			achado++;
		}
		if (achado = true) { return true; }
		else			   { return false; }
	} 
	/*
	   A fun��o taskEXIT_CRITICAL() � utilizado para encerrar o acesso a uma se��o cr�tica.
	*/
	taskEXIT_CRITICAL();
}

int main_(void)
{
	// Fun��o para criar um sem�foro bin�rio
	xSemaphore = xSemaphoreCreateMutex();

	// Criando uma tarefa para cada um das cores do sinaleiro
	xTaskCreate(Aristoteles, "Arist�teles", 1000, NULL, 1, AristotelesH);
	xTaskCreate(Platao, "Plat�o", 1000, NULL, 1, PlataoH);
	xTaskCreate(Nietzsche, "Nietzsche", 1000, NULL, 1, NietzscheH);
	xTaskCreate(Hegel, "Hegel", 1000, NULL, 1, HegelH);
	xTaskCreate(Kant, "Kant", 1000, NULL, 1, KantH);

	// Iniciando o escalonador de tarefas
	vTaskStartScheduler();

	for (;;);
	return 0;
}

void Aristoteles(void* pvParameters)
{
	for (;; ){
		// Verificando se o sem�foro foi criado antes de utiliz�-lo
		if (xSemaphore != NULL) {	
			if (xSemaphoreTake(xSemaphore, (portTickType)10) == pdTRUE) {
				
				
				
				xSemaphoreGive(xSemaphore);
			}
		} else {
			// imprime a mensagem caso o sem�foro n�o tenha sido criado
			vPrintString("O semaforo n�o foi criado!\n");
		}
		vTaskDelay(portTICK_RATE_MS * 1000);
	}
	// A fun��o vTaskDelete() permite liberar explicitamente a tarefa
	vTaskDelete(NULL);
}
