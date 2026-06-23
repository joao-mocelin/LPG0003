#include <stdio.h>
#include <string.h>

struct Produto
{
    int codigo;
    char descricao[20];
    float peso;
};

void mostra_produto(struct Produto x){
    printf("\n %d %s %.2f",x.codigo,x.descricao,x.peso);
}

void inicializa_produto(struct Produto *x,int codigo, char *descricao, float peso){
    x->codigo = codigo;
    strcpy(x->descricao, descricao);
    x->peso = peso;
}

void le_produto(struct Produto *x){
    scanf("%d",&x->codigo);
    scanf(" %[^\n]",x->descricao);
    scanf("%f",&x->peso);
}

int main(){
    struct Produto feijao;
    feijao.codigo = 10001;
    strcpy(feijao.descricao, "Feijao Carioca 1,5kg");
    feijao.peso = 1.5;
    mostra_produto(feijao);
    inicializa_produto(&feijao,100,"feijao preto",2.0);
    mostra_produto(feijao);
    le_produto(&feijao);
    mostra_produto(feijao);
    return 0;
}