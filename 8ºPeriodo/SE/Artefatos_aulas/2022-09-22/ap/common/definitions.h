#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// Tempo do timer que controla o desligamento temporário
// da valvula 1 quando o sensor s12 desliga
#define SM1_TIME_MS 2000
// Tempo do timer para controlar a bomba quando ela
// tem motivo para desligar
#define SM2_TIME_MS 2000
// Tempo do timer para a válvula 2 assim que o sensor s32 desliga
// e existe água no tanque 2
#define SM3_TIME_MS 2000
// Valor de variação da temperatura após atingir o
// valor superior e inferior à variação definida aqui
#define val_histerese 1
// Temperatura alvo do sistema de aquecimentos
#define temp_padrao 50
// Vazão da entrada do sistema ao tanque 1
#define vazao_v1_t1 .02
// Vazão entre o tanque 1 e o tanque 2
#define vazao_t1_t2 .04
// Vazão (bidirecional) entre o tanque 2 e o tanque 3
#define vazao_t2_t3 .06
// Vazão do tanque 3 ao ambiente de consumo
#define vazao_t3 0
// Variação de temperatura para aquecimento
#define delta_t_pos 0.1
// Variação de temperatura para resfriamento
#define delta_t_neg 0.07
#endif // DEFINITIONS_H
