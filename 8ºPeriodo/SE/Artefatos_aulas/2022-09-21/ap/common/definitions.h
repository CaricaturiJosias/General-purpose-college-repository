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

#endif // DEFINITIONS_H
