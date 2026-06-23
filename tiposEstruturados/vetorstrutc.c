#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{
    int codigo;
    char descricao[20];
    float preco;
};

void mostra_produto(struct Produto x){
    printf("\n %d %s %.2f",x.codigo,x.descricao,x.preco);
}

void inicializa_produto(struct Produto *x,int codigo, char *descricao, float preco){
    x->codigo = codigo;
    strcpy(x->descricao, descricao);
    x->preco = preco;
}

void le_produto(struct Produto *x){
    scanf("%d",&x->codigo);
    scanf(" %[^\n]",x->descricao);
    scanf("%f",&x->preco);
}


int main(){
    int n;
    printf("\nQuantos produtos?");
    scanf("%d",&n);
    struct Produto *p = malloc(sizeof(struct Produto) * n);
    for(int i = 0; i < n; i++){
        le_produto(&p[i]);
    }
    for(int i = 0; i < n; i++){
        printf("\n");
        mostra_produto(p[i]);
    }
    return 0;
}