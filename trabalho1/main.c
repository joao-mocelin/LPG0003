#include <stdio.h>

#define M 3 //N° de conjuntos
#define N 5 //N° de valores por conjunto

int isElement(int mat[M][N],int index, int element){
    for(int j = 0; j < N && mat[index][j] != 0; j++){
        if(mat[index][j] == element){
            return 1;
        }
    }
    return 0;
}

void insertData(int mat[M][N], int index){
    int conjCheio = 1;
    for(int j = 0; j < N; j++){
        if(mat[index][j] == 0){
            conjCheio = 0;
            printf("\nInsira o valor a ser inserido no conjunto:\n");
            int var;
            scanf("%d",&var);
            if(var == 0){
                for(int k = j; k < N; k++){
                    mat[index][k] = 0;
                }
                return;
            }
            if(isElement(mat,index,var) == 0){
                mat[index][j] = var;
            }
            else{
                printf("\nElemento ja esta no conjunto.");
                j--;
            }
        }
    }
    if(conjCheio == 1){
        printf("\nConjunto cheio!");
    }
}

void mostraTodos(int mat[M][N], int conj){
    for (int i = 0; i < conj; i++)
    {
        printf("\nConjunto %d:",i);
        for(int j = 0; j < N; j++){
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }
}

void mostraConjunto(int mat[M][N], int conjunto){
    for(int j = 0; j < N; j++){
        printf(" %d",mat[conjunto][j]);
    }
}

void buscaMatriz(int mat[M][N], int key){
    int bool = 0;
    printf("\nConjuntos que contem o valor %d:",key);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N && mat[i][j] != 0; j++){
            if(mat[i][j] == key){
                printf("\nConjunto %d -> ",i);
                mostraConjunto(mat,i);
                bool = 1;
            }
        }
    }
    if(bool == 0){
        printf("\nNenhum conjunto contem a chave %d.",key);
    }
}


int main(){
    int matriz[M][N] = {0};
    int quantConjuntos = 0;
    int option = -1;
    while(option != 9){
        printf("\n\n\tGerenciamento de Conjuntos (%d/%d)\n",quantConjuntos,M);
        printf("\nMenu\n");
        printf("\n1-Criar novo conjunto vazio.");
        printf("\n2-Inserir dados em um conjunto.");
        printf("\n3-Remover um conjunto.");
        printf("\n4-Fazer a uniao entre dois conjuntos.");
        printf("\n5-Fazer a interseccao entre dois conjuntos.");
        printf("\n6-Mostrar um conjunto.");
        printf("\n7-Mostrar todos os conjuntos.");
        printf("\n8-Fazer busca por um valor.");
        printf("\n9-Sair do programa.\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1 : //Criar conjunto vazio
            if(quantConjuntos >= M){
                printf("\nNumero maximo de conjuntos atingido.");
                break;
            }
            quantConjuntos++;
            break;

        case 2 : //Inserir dados em um conjunto
            if(quantConjuntos <= 0){
                printf("\nNao ha conjuntos para inserir dados");
                break;
            }
            int select = -1;
            while(select < 0 || select > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto a ser inserido os dados: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(")");
                scanf("%d",&select);
                if(select < 0 || select > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            insertData(matriz,select);
            break;

        case 3 : //remover um conjunto
            
            break;

        case 4 : //fazer a uniao de conjuntos
            
            break;

        case 5 : //fazer a intersecção de conjuntos
            
            break;

        case 6 : //mostrar um conjunto
            if(quantConjuntos <= 0){
                printf("\nNao ha conjuntos para serem mostrados");
                break;
            }
            select = -1;
            while(select < 0 || select > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto a ser mostrado: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(") ");
                scanf("%d",&select);
                if(select < 0 || select > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            mostraConjunto(matriz,select);
            break;

        case 7 : //mostrar todos os conjuntos
            if(quantConjuntos <= 0){
                printf("\nNao ha conjuntos para serem mostrados");
                break;
            }
            mostraTodos(matriz,quantConjuntos);
            break;

        case 8 : //fazer busca por um valor
            if(quantConjuntos <= 0){
                printf("\nNao ha conjuntos para serem mostrados");
                break;
            }
            int searchKey;            
            printf("\nInsira a chave de busca: ");
            scanf("%d",&searchKey);
            while (searchKey == 0)
            {
                printf("\n0 nao eh um valor valido.");
                printf("\nInsira a chave de busca: ");
                scanf("%d",&searchKey);
            }
            buscaMatriz(matriz,searchKey);
            break;

        case 9 : //sai do programa
            return 0;
        default: //caso opção invalida
            printf("\nOpcao invalida.");
            break;
        }
    }
    return 0;
}