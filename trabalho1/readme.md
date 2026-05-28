# 🧮 Trabalho 1: Gerenciamento de Conjuntos

[cite_start]Este repositório contém a implementação do **Trabalho 1** da disciplina de **Linguagem de Programação**, focado no gerenciamento de uma quantidade indeterminada de conjuntos de valores inteiros utilizando estruturas de matrizes estáticas[cite: 72].

---

## 🛠️ Requisitos Estruturais e Configurações

[cite_start]Antes de iniciar as funcionalidades, Garanta a correta inicialização das estruturas de dados principais[cite: 76, 78]:

- [x] [cite_start]Definir as constantes `M` (máximo de conjuntos) e `N` (máximo de elementos por conjunto)[cite: 73, 75, 102].
- [x] [cite_start]Declarar e inicializar a matriz `MxN` com zeros (indicando que está vazia)[cite: 73, 76].
- [x] [cite_start]Declarar e inicializar o contador global de conjuntos zerado[cite: 78, 79].
- [x] [cite_start]Implementar a estrutura do loop principal (ciclo de repetições) com o menu de texto[cite: 80].

---

## 💻 Funcionalidades do Menu (Checklist)

[cite_start]Acompanhe o desenvolvimento de cada uma das opções do menu do sistema[cite: 80]:

### Opções de Gerenciamento de Conjuntos
- [x] **1. [cite_start]Criar um novo conjunto vazio:** Incrementar o contador de conjuntos (caso seja menor que `M`)[cite: 81].
- [x] **2. [cite_start]Inserir dados em um conjunto:** - [ ] Solicitar o índice $i$ e validar se $0 \le i < \text{contador}$[cite: 82].
  - [x] [cite_start]Inserir múltiplos valores sequenciais até digitar `0` ou atingir o limite `N`[cite: 84].
  - [x] [cite_start]Garantir inserção "à direita" utilizando um contador de elementos para a linha[cite: 85, 86].
  - [x] [cite_start]Implementar validação de valores únicos (evitar repetidos usando busca sequencial)[cite: 87, 88, 89].
- [x] **3. [cite_start]Remover um conjunto:** - [ ] Solicitar o índice $i$ e validar o intervalo[cite: 90].
  - [x] [cite_start]Zerar a linha do conjunto removido[cite: 91].
  - [x] [cite_start]Deslocar/reorganizar os conjuntos abaixo dele "para cima" e decrementar o contador[cite: 91, 93].

### Opções de Operações Algébricas
- [x] **4. [cite_start]Fazer a união entre dois conjuntos:** Receber dois índices, calcular a união (valores sem repetição) e adicionar o resultado como uma nova linha na matriz[cite: 94, 95].
- [x] **5. [cite_start]Fazer a intersecção entre dois conjuntos:** Receber dois índices, calcular a intersecção (apenas valores presentes em ambos) e adicionar o resultado como uma nova linha na matriz[cite: 96].

### Opções de Visualização e Busca
- [x] **6. [cite_start]Mostrar um conjunto:** Exibir todos os elementos válidos de um conjunto dado o seu índice[cite: 97].
- [x] **7. [cite_start]Mostrar todos os conjuntos:** Listar na tela todos os conjuntos atualmente armazenados[cite: 98].
- [x] **8. [cite_start]Busca por um valor:** Ler um número inteiro do usuário e mostrar os índices de todos os conjuntos que o contêm[cite: 99].
- [x] **9. [cite_start]Sair do programa:** Encerrar o ciclo de repetições de forma limpa[cite: 80, 100].

---

## ⚠️ Validações e Tratamento de Exceções

[cite_start]Garantir que o programa seja robusto e trate situações inesperadas[cite: 105, 106]:

- [x] [cite_start]Impedir a criação de novos conjuntos se o limite `M` for atingido[cite: 74, 75, 103].
- [x] [cite_start]Impedir a inserção de novos elementos se o limite `N` for atingido[cite: 74, 75, 84, 103].
- [x] [cite_start]Garantir que o valor `0` seja interpretado estritamente como indicador de vazio/parada, nunca como valor válido[cite: 76, 77, 84].
- [x] [cite_start]Exibir mensagens adequadas se o usuário tentar listar/buscar dados quando não houver nenhum conjunto criado[cite: 105].
- [x] [cite_start]Tratar adequadamente a digitação de índices inválidos ou inexistentes[cite: 106].
- [x] [cite_start]Modularizar o código utilizando **funções** para a maioria das tarefas (como busca sequencial, exibição, etc.)[cite: 89, 104].
