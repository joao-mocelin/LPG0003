# Trabalho 1: Gerenciamento de Conjuntos

Este repositório contém a implementação do Trabalho 1 da disciplina de Linguagem de Programação, focado no gerenciamento de uma quantidade indeterminada de conjuntos de valores inteiros utilizando estruturas de matrizes estáticas.

---

## Requisitos Estruturais e Configurações

Antes de iniciar as funcionalidades, garanta a correta inicialização das estruturas de dados principais:

- [x] Definir as constantes M (máximo de conjuntos) e N (máximo de elementos por conjunto).
- [x] Declarar e inicializar a matriz MxN com zeros (indicando que está vazia).
- [x] Declarar e inicializar o contador global de conjuntos zerado.
- [x] Implementar a estrutura do loop principal (ciclo de repetições) com o menu de texto.

---

## Funcionalidades do Menu (Checklist)

Acompanhe o desenvolvimento de cada uma das opções do menu do sistema:

### Opções de Gerenciamento de Conjuntos
- [x] **1. Criar um novo conjunto vazio:** Incrementar o contador de conjuntos (caso seja menor que M).
- [x] **2. Inserir dados em um conjunto:**
  - [x] Solicitar o índice i e validar se 0 <= i < contador.
  - [x] Inserir múltiplos valores sequenciais até digitar 0 ou atingir o limite N.
  - [x] Garantir inserção "à direita" utilizando um contador de elementos para a linha.
  - [x] Implementar validação de valores únicos (evitar repetidos usando busca sequencial).
- [x] **3. Remover um conjunto:**
  - [x] Solicitar o índice i e validar o intervalo.
  - [x] Zerar a linha do conjunto removido.
  - [x] Deslocar/reorganizar os conjuntos abaixo dele "para cima" e decrementar o contador.

### Opções de Operações Algébricas
- [x] **4. Fazer a união entre dois conjuntos:** Receber dois índices, calcular a união (valores sem repetição) e adicionar o resultado como uma nova linha na matriz.
- [x] **5. Fazer a intersecção entre dois conjuntos:** Receber dois índices, calcular a intersecção (apenas valores presentes em ambos) e adicionar o resultado como uma nova linha na matriz.

### Opções de Visualização e Busca
- [x] **6. Mostrar um conjunto:** Exibir todos os elementos válidos de um conjunto dado o seu índice.
- [x] **7. Mostrar todos os conjuntos:** Listar na tela todos os conjuntos atualmente armazenados.
- [x] **8. Busca por um valor:** Ler um número inteiro do usuário e mostrar os índices de todos os conjuntos que o contêm.
- [x] **9. Sair do programa:** Encerrar o ciclo de repetições de forma limpa.

---

## Validações e Tratamento de Exceções

Garantir que o programa seja robusto e trate situações inesperadas:

- [x] Impedir a criação de novos conjuntos se o limite M for atingido.
- [x] Impedir a inserção de novos elementos se o limite N for atingido.
- [x] Garantir que o valor 0 seja interpretado estritamente como indicador de vazio/parada, nunca como valor válido.
- [x] Exibir mensagens adequadas se o usuário tentar listar/buscar dados quando não houver nenhum conjunto criado.
- [x] Tratar adequadamente a digitação de índices inválidos ou inexistentes.
- [x] Modularizar o código utilizando funções para a maioria das tarefas (como busca sequencial, exibição, etc.).
