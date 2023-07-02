/*
cliente.c
*/

#include<stdbool.h>
#include<stdio.h> //printf
#include<string.h> //strlen
#include<sys/socket.h> //socket
#include<arpa/inet.h> //inet_addr
#include<stdlib.h>
#include<unistd.h>

typedef struct protocolData{
      char protocol[4];
      char ignore[1]; // -
      char data[1495];
} Data;

/*
     Para evitar strcmps infinitos na resposta do servidor,
     transformamos o protocolo de resposta em um int (str para int)
     e comparamos com os números definidos abaixo, que são os protocolos
     de resposta transformador em ints para colocar em um simples switch case
*/
// int Greet, GreetB, I_am, I_know, D_know, Say, Heard, ClientBye, ServerBye;

/*
      Protocolo
      formato
      [MSG]-[DATA]
      [4 x char][-][50 x char]
      "GRT!" - Greet (Equivalent to SYN)
      "GRTB" - Greet confirmation
      "I AM" - Sending password
      "OK  " - Acknowledge password
      "!!!!" - Wrong password
      "SAY!" - Client sending a message
      "UHUM" - Signal to the client the server is listening
      "BYE!" - End connection (client)
      "BYEB" - End connection (server)
*/

int main(int argc , char *argv[])
{
     char * GreetB = "GRTB";
     char * I_know = "OK  ";
     char * D_know = "!!!!";
     char * Heard = "UHUM";
     char * ServerBye = "BYEB";

     bool GREET, PASSOK, SAY, UHUM, BYE, BYEBYE, EXIT, skip_input;
     
     EXIT = GREET = PASSOK = SAY = UHUM = BYE = BYEBYE = skip_input = false;
     
     int sock, attemps = 0; // Tentativas em mandar mensagem sem resposta
     struct sockaddr_in server;
     char input[1495], *server_reply;
     Data * message, * reply;
     message= malloc(sizeof(Data));
     server_reply= malloc(sizeof(Data));

     //Criar socket
     sock = socket(AF_INET , SOCK_STREAM , 0);
     if (sock == -1)
     {
     printf("\nNao pude criar o socket!\n");
     }
     printf("\nSocket criado!\n");
     server.sin_addr.s_addr = inet_addr("127.0.0.1");
     server.sin_family = AF_INET;
     server.sin_port = htons( 10000 );
     //Conectar ao servidor
     if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
     {
          perror("\nconexao falhou. Error!\n");
          return 1;
     }
     printf("\nConectado ao servidor!\n");
     //mantendo comunicacao com o servidor

     do
     {
          /*
          Protocolo
          formato
          [MSG]-[DATA]
          [4 x char][-][50 x char]
          "GRT!" - Greet (Equivalent to SYN)
          "GRTB" - Greet confirmation
          "I AM" - Sending password
          "OK  " - Acknowledge password
          "!!!!" - Wrong password
          "SAY!" - Client sending a message
          "UHUM" - Signal to the client the server is listening
          "BYE!" - End connection (client)
          "BYEB" - End connection (server)

          Greet
          I_am
          I_know or D_know
          Say
          Heard
          ClientBye
          ServerBye
          */

          if (EXIT){
               printf("\nAplicação encerrando...");
               break;
          }
          memset(&input,'\0', sizeof(input));

          if (!GREET) 
          // Manda um primeiro greet
          // ou
          // Se o servidor não responde, manda outro
          {
               strcpy((char *) message, "GRT!-\0");
               skip_input = true;
          }

          else if (GREET && !PASSOK) // Reconhece o cliente mas não se identificou
          {
               strcpy((char *)message, "I AM-\0");
               printf("\nVocê precisa digitar sua senha!");
          }

          else if (PASSOK){ 
               strcpy((char *)message, "SAY!-\0");
               SAY = true;
               if (SAY && !UHUM)
                    printf("\nNão sabemos se a última mensagem foi entregue");
               UHUM = false;
          }

          if (!skip_input){
               printf("\nDigite sua mensagem : ");

               fgets(input,1495,stdin);
          }
          else 
               skip_input = false;
          if (!strncmp(input, "SAIR", 4))
          {
               strcpy((char *)message, "BYE!\0");
          }

          if((strlen(input)>0) && (input[strlen(input)-1] == '\n'))
               input[strlen(input)-1] = '\0';

          //Enviando mensagem ao servidor

          strcat(message->data, input);

          printf("\nCliente enviou: %s",message);

          if( send(sock , message, strlen((char *) message), 0) < 0)
          {
               printf("Send falhou!\n");
               return 1;
          }
          //Recebendo retorno do servidor
          if( recv(sock , server_reply , 2000 , 0) < 0)
          {
               printf("recv falhou!\n");
               break;
          }
          
          /*
          ------------------------------------------------------------
          Procesando resposta do servidor
          Respostas:
          Greet= "GRT!"
          GreetB = "GRTB"
          I_am = "I AM"
          I_know= "OK  "
          D_know= "!!!!"
          Say= "SAY "
          Heard = "UHUM"
          ClientBye= "BYE!"
          ServerBye = "BYEB"
          */
          reply = (Data *) server_reply;
          printf("\nServidor respondeu: %s", reply);
          if (!strncmp(reply->protocol, GreetB, 4))
          {
               GREET = true;
               printf("\nHandshake do servidor");
          }
          else if (!strncmp(reply->protocol, I_know, 4))
          {
               PASSOK = true;
               printf("\nACESSO PERMITIDO");
          }

          else if (!strncmp(reply->protocol, D_know, 4))
          {
               PASSOK = false;
               printf("\nACESSO NEGADO");
          }

          else if (!strncmp(reply->protocol, Heard, 4))
          {
               UHUM = true;
               printf("\nO servidor recebeu a mensagem");
          }

          else if (!strncmp(reply->protocol, ServerBye, 4))
          {
               EXIT = true;
          }

          memset(server_reply,'\0', sizeof(server_reply));
          memset(message, '\0', sizeof(message));
          memset(reply, '\0', sizeof(reply));

     } while (EXIT != true);

     free(server_reply);
     free(message);

     close(sock);
     return 0;
}