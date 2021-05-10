#include "main.h"
#include "cplx_op.h"
#include <math.h>
#include <stdlib.h>
#include <stddef.h>


int push(StackCplxNodePtr* topPtr, CplxNum complex) {
	
}


CplxNum pop(StackCplxNodePtr* topPtr) {
	
}


int isEmptyStack(StackCplxNodePtr topPtr) {
	
}


int basicOpStack(StackCplxNodePtr* topPtr, const char* cmd, const char* outputmode) {
	
}


// Neste assignment iremos construir as funções básicas de uma calculadora
// de pilha, ou uma calculadora de utiliza a lógica polonesa reversa.
// O programa utiliza a biblioteca cplx_op que contém as funções 
// da calculadora de números complexos, implementada em assignemnts anteriores.
//
// Você deve implementar as funções push, pop, isEmptyStack e basicOpStack.
// As funções push, pop e isEmptyStack são funções para o gerenciamento de uma
// pilha. A pilha implementada por listas ligadas foi explicada e exemplificada
// em aula.
// Os nós da pilha são compostos por elementos do tipo StackCplxNode, descritos
// em main.h. O tipo CplxNum, utilizado pelas funções para realizar as quatro
// operações básicas, encontra-se no .h do módulo das operações complexas: 
// cplx_op.
// 
// A função push cria um nó do tipo StackCplxNode, através da alocação dinâmica
// de memória, e testa se a memória para o nó foi criada, retornando o inteiro 5
// caso o S.O. não tenha criado.
// Caso tenha criado, a função empilha o nó com o conteúdo complex, retornando
// o inteiro zero para indicar uma operação bem sucedida.
// O protótipo e o corpo da função encontram-se previamente implementados no
// programa.
//
// A função pop retira o nó da pilha, libera no sistema a memória referente ao nó 
// e retorna o valor do tipo CplxNum previamente carregado pelo nó.
// O protótipo e o corpo da função encontram-se previamente implementados no
// programa.
//
// A função isEmptyStack, tal como o próprio nome diz, testa se uma pilha está vazia.
// Se estiver retorna 1 (TRUE), caso contrário retorna 0 (FALSE).
// 
// A função basicOpStack utiliza a biblioteca clpx_op para realizar os cálculos
// necessários na calculadora de pilha. Esta função implementa a calculadora de pilha.
// A calculadora de pilha realiza a operação aritmética básica desejada utilizando
// como operandos os dois elementos mais ao topo da pilha. O elemento do topo é o
// primeiro operando e o elemento subsequente (logo abaixo do topo) é o segundo 
// operando. Na operação os dois elementos mais ao topo são sacados (popados) da
// pilha, a operação é realizada e o resultado é colocado (pushado) na (no topo da)
// pilha. Ex: [topo] op [abaixo do topo].
// A operação da função é descrita abaixo.
// A função basicOpStack recebe o endereço do ponteiro da pilha e o armazena em topPtr,
// recebe o endereço da string de comando e o armazena em cmd e recebe o endereço da
// string que define o modo de saída do valor calculado (define a base do resultado) e
// o armazena em outputmode.
// Se topPtr for nulo, a função deve retornar o inteiro -3
// Se a pilha estiver vazia, deve retornar o inteiro -2, pois faltam os dois operandos 
// para realizar a operação
// Se a pilha contiver apenas um elemento, um dos operandos estiver faltando, a função
// retorna o inteiro -1
// Para qualquer problema encontrado na pilha, a pilha deve ser devolvida ao 
// sistema em seu estado original (deve permanecer inalterada).
// Se a pilha estiver em condições, então, a operação deve ser realizada da seguinte
// forma:
// Sacam-se (São popados) os operandos da pilha e a operação aritmética básica é 
// realizada de acordo com os parâmetros estipulados pelas variáveis cmd e outputmode.
// Se por alguma razão a operação não der certo, os operandos na pilha devem ser 
// preservados e a função deve retornar com a pilha com o conteúdo sem alterações.
// Obrigatoriamente seu código deve utilizar as funções definidas anteriormente 
// para o gerenciamento da pilha.
// Nenhuma operação aritmética explicita deve ser realizada com os operandos. É 
// obrigatório utilizar a biblioteca cplx_op para isso e, mesmo assim, 
// operações aritméticas explícitas ou de mais baixo nível não devem ser feitas.
// 
