/*Escreva uma função que realiza a união entre dois conjuntos de inteiros contidos nos
vetores v1 e v2. A função recebe os vetores e suas respectivas capacidades (n1 e n2) como
parâmetros de entrada e retorna o endereço do vetor alocado (contendo a união entre v1
e v2). Além disso, há um parâmetro passado por referência (ponteiro p3), que serve para
“retornar” a capacidade do vetor gerado. Faça o programa principal invocando a função (a
estrutura do programa é semelhante ao exemplo dado em aula – intersecção). Protótipo
da função:
*/
#include <stdio.h>
#include <stdlib.h>

int existe(int *v, int n, int key){
    for(int i = 0; i < n; i++){
        if(v[i] == key){
            return 1;
        }
    }
    return 0;
}

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ){
    int *uniao = 0;
    uniao = malloc(sizeof(int) * (n1+n2));
    *p3 = n1;
    for(int i = 0; i < n1; i++){
        uniao[i] = v1[i];
    }
    for(int i = 0; i < n2; i++){
        if(existe(uniao,*p3,v2[i]) == 0){
            uniao[*p3] = v2[i];
            *p3 += 1;
        }
    }
    uniao = realloc(uniao,sizeof(int) * (*p3));
    return uniao;
}

int main(){
    int n_v1, n_v2, *v1 = 0, *v2 = 0;
    printf("quantidade de valores v1:\n");
    scanf("%d",&n_v1);
    printf("quantidade de valores v2:\n");
    scanf("%d",&n_v2);
    v1 = malloc(sizeof(int) * n_v1);
    v2 = malloc(sizeof(int) * n_v2);
    for(int i = 0; i < n_v1; i++){
        printf("\nv1[%d]: ",i);
        scanf("%d",&v1[i]);
    }
    for(int i = 0; i < n_v2; i++){
        printf("\nv2[%d]: ",i);
        scanf("%d",&v2[i]);
    }
    system("cls");
    int n_uniao, *v_uniao = 0;
    v_uniao = uniao(v1,n_v1,v2,n_v2,&n_uniao);
    printf("\nVetor Uniao:");
    for(int i = 0; i < n_uniao; i++){
        printf("\nuniao[%d] = %d",i,v_uniao[i]);
    }
    free(v1);
    free(v2);
    free(v_uniao);
    return 0;
}