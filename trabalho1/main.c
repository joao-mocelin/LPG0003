#include <stdio.h>

#define M 8 //N° de conjuntos
#define N 10 //N° de valores por conjunto

void bubbleSort(int mat[M][N], int indice) { 
    int aux, swap;
    
    for(int i = 0; i < N - 1; i++) {
        swap = 0; 
        
        for(int j = 0; j < N - 1 - i; j++) {
            
            if (mat[indice][j] == 0 && mat[indice][j + 1] != 0) {
                aux = mat[indice][j];
                mat[indice][j] = mat[indice][j + 1];
                mat[indice][j + 1] = aux;
                swap = 1;
            }
            else if (mat[indice][j] > mat[indice][j + 1] && mat[indice][j + 1] != 0 && mat[indice][j] != 0) {
                aux = mat[indice][j];
                mat[indice][j] = mat[indice][j + 1];
                mat[indice][j + 1] = aux;
                swap = 1;
            }
        }
        if(swap == 0) {
            break;
        }
    }
}

int isElement(int mat[M][N],int index, int element){ // Recebe a matriz, Linha e elemento a ser buscado na linha. Retorna 1 caso contenha o elemento e retorna 0 caso contrário.
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

void mostraConjunto(int mat[M][N], int conjunto){
    if(mat[conjunto][0] == 0){
        printf("Vazio");
        return;
    }
    for(int j = 0; j < N && mat[conjunto][j] != 0; j++){
        printf("%d ",mat[conjunto][j]);
    }
}

void mostraTodos(int mat[M][N], int conj){
    for (int i = 0; i < conj; i++)
    {
        printf("\nConjunto %d -> ",i);
        mostraConjunto(mat,i);
        printf("\n");
    }
}

void buscaMatriz(int mat[M][N], int key){
    int found = 0;
    printf("\nConjuntos que contem o valor %d:",key);
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N && mat[i][j] != 0; j++){
            if(mat[i][j] == key){
                printf("\nConjunto %d -> ",i);
                mostraConjunto(mat,i);
                found = 1;
            }
        }
    }
    if(found == 0){
        printf("\nNenhum conjunto contem a chave %d.",key);
    }
}

void removeConj(int mat[M][N], int index){
    for(int i = index; i < M-1; i++){  
        for(int j = 0; j < N; j++){
        mat[i][j] = mat[i+1][j];
        }
    }
    for(int i = 0; i < N; i++){
        mat[M-1][i] = 0;
        }
}

void uniaoM(int mat[M][N], int conj1, int conj2, int conjUniao){
    int i;
    for(i = 0; i < N && mat[conj1][i] != 0; i++)
    {
        mat[conjUniao][i] = mat[conj1][i];
    }
    int j = i;
    for(i = 0; i < N && mat[conj2][i] != 0; i++)
    {
        if(isElement(mat,conjUniao,mat[conj2][i]) == 0){
            if(j >= N){
            printf("\nERRO, uniao finalizada pois acabou o espaco no conjunto uniao!");
            return;
        }
            mat[conjUniao][j] = mat[conj2][i];
            j++;
        }
    }
    for(int k = j; k < N; k++) {
        mat[conjUniao][k] = 0;
    }
}

void intersecM(int mat[M][N], int conj1, int conj2, int conjIntersec){
    int i;
    int j = 0;
    for(i = 0; i < N && mat[conj1][i] != 0; i++)
    {
        if(isElement(mat,conj2,mat[conj1][i]) == 1){
            mat[conjIntersec][j] = mat[conj1][i];
            j++;
        }
    }
    for(int k = j; k < N; k++) {
        mat[conjIntersec][k] = 0;
    }
}

int main(){
    int matriz[M][N] = {0};
    int quantConjuntos = 0;
    int option = -1;
    int select, select2, free;
    while(option != 9){
        printf("\n\n\tGerenciamento de Conjuntos (%d/%d)\n",quantConjuntos,M);
        printf("\nMenu\n");
        printf("\n1) Criar novo conjunto vazio.");
        printf("\n2) Inserir dados em um conjunto.");
        printf("\n3) Remover um conjunto.");
        printf("\n4) Fazer a uniao entre dois conjuntos.");
        printf("\n5) Fazer a interseccao entre dois conjuntos.");
        printf("\n6) Mostrar um conjunto.");
        printf("\n7) Mostrar todos os conjuntos.");
        printf("\n8) Fazer busca por um valor.");
        printf("\n9) Sair do programa.\n");
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
            select = -1;
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
            if(quantConjuntos <= 0){
                printf("\nNao ha conjuntos para serem removidos");
                break;
            }
            select = -1;
            while(select < 0 || select > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto a ser removido: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(") ");
                scanf("%d",&select);
                if(select < 0 || select > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            quantConjuntos--;
            removeConj(matriz,select);
            break;

        case 4 : //fazer a uniao de conjuntos
            if(quantConjuntos <= 1){
                printf("\nNao ha conjuntos para serem unidos.");
                break;
            }
            if(quantConjuntos >= M){
                printf("\nNumero maximo de conjuntos atingido.");
                break;
            }
            select = -1;
            while(select < 0 || select > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto 1 a ser feita a uniao: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(") ");
                scanf("%d",&select);
                if(select < 0 || select > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            select2 = -1;
            while(select2 < 0 || select2 > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto 2 a ser feita a uniao: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(") ");
                scanf("%d",&select2);
                if(select2 < 0 || select2 > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            free = quantConjuntos;
            quantConjuntos++;
            uniaoM(matriz, select, select2, free);
            bubbleSort(matriz,free);
            printf("\nO novo conjunto foi criado na posicao %d",free);
            break;

        case 5 : //fazer a intersecção de conjuntos
            if(quantConjuntos <= 1){
                printf("\nNao ha conjuntos para ser feita a interseccao.");
                break;
            }
            if(quantConjuntos >= M){
                printf("\nNumero maximo de conjuntos atingido.");
                break;
            }
            select = -1;
            while(select < 0 || select > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto 1 a ser feita a interseccao: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(") ");
                scanf("%d",&select);
                if(select < 0 || select > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            select2 = -1;
            while(select2 < 0 || select2 > (quantConjuntos - 1)){
                printf("\nEscolha o conjunto 2 a ser feita a interseccao: (");
                for(int i = 0; i < quantConjuntos; i++){
                    printf("%d,",i);
                }
                printf(") ");
                scanf("%d",&select2);
                if(select2 < 0 || select2 > (quantConjuntos - 1)){
                    printf("\nConjunto invalido.");
                }
            }
            free = quantConjuntos;
            quantConjuntos++;
            intersecM(matriz, select, select2, free);
            bubbleSort(matriz,free);
            printf("\nO novo conjunto foi criado na posicao %d",free);
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
            printf("\nConjunto %d -> ",select);
            mostraConjunto(matriz,select);
            break;

        case 7 : //mostrar todos os conjuntos
            if(quantConjuntos <= 0){
                printf("\nNao ha conjuntos para serem mostrados");
                break;
            }
            printf("\nTemos %d conjuntos:\n",quantConjuntos);
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