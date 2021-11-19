int avalia(char *tabuleiro[3][3], char *jogador){
    int bom = 0;
    int ruim = 0;
    int mruim = 0;
    int ganha =  0;
    int perde =  0;
    int cont =  0;
    // bom e ruim contam a quantidade de linhas que se podem colocar
    // ganha e perde contam marcas que o jogador ja tem
    // cont conta quantos espaços vazios tem
    // se um ganha/perde tiver 2 e tiver um espaço vazio em cont, tem como devolver 9 ou -9
    // mruim é para caso tenham duas linhas que o adversário pode fechar
    //percorre todas as casas do quadro

    // analiza linhas (usa tabuleiro [I][J])
    for (int i = 0; i < 3; i++){
        ganha = 0;
        perde = 0;
        for (int j = 0; j < 3; j++){
            if (tabuleiro[i][j] == jogador){
                ganha++;
            }
            else if (!strcmp(tabuleiro[i][j], jogador) && !(*tabuleiro[i][j] == ' ')){
                // não esta vazio ou com marca jogador, logo marca adversario  
                perde++;
            } else {
                // espaço vazio
                cont++;
            }
        }
        // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 1
        // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 2 && cont == 1)
            return(-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }
    // analiza colunas (usa tabuleiro [J][I])
    ganha =  0;
    perde =  0;
    cont =  0;
    for (int i = 0; i < 3; i++){
        ganha = 0;
        perde = 0;
        for (int j = 0; j < 3; j++){
            if (strcmp(tabuleiro[j][i], jogador)){
                ganha++;
            }
            else if (!strcmp(tabuleiro[j][i], jogador) && !(*tabuleiro[i][j] == ' ' )){
                perde++;
            } else {
                cont++;
            }
        }
        // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 2
        // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 3)
            return(-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }

    // analiza diagonais
    int i;
    int j;
    ganha =  0;
    perde =  0;
    cont =  0;
    for (i = 0, j = 0; i < 3; i++, j++){
        if (tabuleiro[i][j] == jogador){
                ganha++;
            }
            else if (!strcmp(tabuleiro[i][j], jogador) && !(*tabuleiro[i][j] == ' ')){
                // não esta vazio ou com marca jogador, logo marca adversario  
                perde++;
            } else {
                // espaço vazio
                cont++;
            }
    }
    // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 3
    // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 3)
            return](-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }
    ganha =  0;
    perde =  0;
    cont =  0;
    for (i = 3, j = 3; i > 0; i--, j--){
        if (tabuleiro[i][j] == jogador){
                    ganha++;
                }
                else if (!strcmp(tabuleiro[i][j], jogador) && !(*tabuleiro[i][j] == ' ')){
                    // não esta vazio ou com marca jogador, logo marca adversario  
                    perde++;
                } else {
                    // espaço vazio
                    cont++;
                }
    }
    // FUNÇÃO DE CHECAGEM REDUNDANTE PARTE 4
    // checa se tem 2 marcas e 1 vazio na linha para decretar vitoria
        if (ganha == 3)
            return (9);
        // checa se tem 2 marcas adversárias e uma vazia para definir como possível perda
        else if (perde == 3)
            return(-9);
        // se a linha não tem marcas do jogador a linha é possível para o oponente
        if (cont != 3){
            if (ganha == 0)
                ruim++;
            // se a linha não tem marcas do oponente a linha é possível
            else if (perde == 0)
                bom++;
        }
        else {
            ruim++;
            bom++;
        }
    }
    delete &i;
    delete &j;
    return(bom-ruim)
};