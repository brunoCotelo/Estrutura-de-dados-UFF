#include <stdio.h>
#include <stdlib.h>



// Estruturas

typedef enum ESTADO{    // Definição dos estados 
    E_LIVRE,
    E_OCUPADO,
    E_APAGADO
} ESTADO;

typedef struct ELEM{    // Estrutura dos elementos da tabela
    int chave;
    int valor;
    ESTADO estado;      // Estado definido pela estrutura acima
} ELEM;

typedef struct THEA{    // Tabela hash com endereçamento aberto
    int m;              // Tamanho do vetor
    ELEM* TH;           // Tabela em si
} THEA;


// Operações


int THEA_Chave_Hash(THEA* TH, int chave, int k){  // Calculo da chave hash (recebe a tabela, a chave e o k(que serve pra pegar o proximo endereço caso ja esteja ocupado))
    //TH->TH.chave = ((chave % TH->m) + k) % TH->m;
    return((chave % TH->m) + k) % TH->m;     // função h'(x,k) = (h(x) + k) % m
}

THEA* THEA_Criar(int m){    // Cria a tabela com M posiçoes
    THEA* novo;
    novo = malloc(sizeof(THEA));            // Aloca uma tabela
    novo->TH = malloc(sizeof(ELEM) * m);    // Aloca as M posiçoes da tabela do tamanho da estrutura ELEM
    novo->m = m;
    for(int i = 0; i < m; i++){
        novo->TH[i].estado = E_LIVRE;       // Seta todos os estados como "livres"
    }
    return novo;
}

int THEA_Inserir(THEA *TH, int chave, int valor){   // Insere os valores na tabela
    int h, k, h_inicial;
    k = 0;
    h = THEA_Chave_Hash(TH, chave, k);
    h_inicial = h;                                  // Salva o H inicial
    while(TH->TH[h].estado == E_OCUPADO){            // Enquanto o estado da posiçao H for ocupada
        if(TH->TH[h].chave == chave){               // Verifica se a chave da posiçao ocupada é igual a chave que esta sendo testada para inserçao
            break;
        }
        k++;                                        // Continua percorrendo para achar a proxima posiçao livre
        h = THEA_Chave_Hash(TH, chave, k);
        if(h == h_inicial){                         // Verifica se todas as posiçoes ja foram percorridas
            return -1;
        }
    }
    TH->TH[h].chave = chave;												// Insere os valores
    TH->TH[h].valor = valor;
    TH->TH[h].estado = E_OCUPADO;
    return h;
}


void imprime(THEA* th){															// Imprime a tabela
    for(int j = 0; j < th->m; j++){
        const char e = th->TH[j].estado == E_OCUPADO ? 'O'
            : (th->TH[j].estado == E_LIVRE ? 'L' : 'A');
        printf("%d: %d, %c\n", j, th->TH[j].valor, e);
    }
}


// Funçao principal


int main (){
    THEA* th;
    int m = 10, valor;
    th = THEA_Criar(m);
    for(int i = 0; i < th->m; i++){								// Faz um "for" para preencher do tamanho M de posiçoes na tabela
        printf("\n\nDigite o valor a ser inserido na tabela: ");
        scanf("%d", &valor);
        THEA_Inserir(th, valor, valor);
        imprime(th);
    }
    

    return 0;
}