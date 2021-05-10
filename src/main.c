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


// Neste assignment iremos construir as fun��es b�sicas de uma calculadora
// de pilha, ou uma calculadora de utiliza a l�gica polonesa reversa.
// O programa utiliza a biblioteca cplx_op que cont�m as fun��es 
// da calculadora de n�meros complexos, implementada em assignemnts anteriores.
//
// Voc� deve implementar as fun��es push, pop, isEmptyStack e basicOpStack.
// As fun��es push, pop e isEmptyStack s�o fun��es para o gerenciamento de uma
// pilha. A pilha implementada por listas ligadas foi explicada e exemplificada
// em aula.
// Os n�s da pilha s�o compostos por elementos do tipo StackCplxNode, descritos
// em main.h. O tipo CplxNum, utilizado pelas fun��es para realizar as quatro
// opera��es b�sicas, encontra-se no .h do m�dulo das opera��es complexas: 
// cplx_op.
// 
// A fun��o push cria um n� do tipo StackCplxNode, atrav�s da aloca��o din�mica
// de mem�ria, e testa se a mem�ria para o n� foi criada, retornando o inteiro 5
// caso o S.O. n�o tenha criado.
// Caso tenha criado, a fun��o empilha o n� com o conte�do complex, retornando
// o inteiro zero para indicar uma opera��o bem sucedida.
// O prot�tipo e o corpo da fun��o encontram-se previamente implementados no
// programa.
//
// A fun��o pop retira o n� da pilha, libera no sistema a mem�ria referente ao n� 
// e retorna o valor do tipo CplxNum previamente carregado pelo n�.
// O prot�tipo e o corpo da fun��o encontram-se previamente implementados no
// programa.
//
// A fun��o isEmptyStack, tal como o pr�prio nome diz, testa se uma pilha est� vazia.
// Se estiver retorna 1 (TRUE), caso contr�rio retorna 0 (FALSE).
// 
// A fun��o basicOpStack utiliza a biblioteca clpx_op para realizar os c�lculos
// necess�rios na calculadora de pilha. Esta fun��o implementa a calculadora de pilha.
// A calculadora de pilha realiza a opera��o aritm�tica b�sica desejada utilizando
// como operandos os dois elementos mais ao topo da pilha. O elemento do topo � o
// primeiro operando e o elemento subsequente (logo abaixo do topo) � o segundo 
// operando. Na opera��o os dois elementos mais ao topo s�o sacados (popados) da
// pilha, a opera��o � realizada e o resultado � colocado (pushado) na (no topo da)
// pilha. Ex: [topo] op [abaixo do topo].
// A opera��o da fun��o � descrita abaixo.
// A fun��o basicOpStack recebe o endere�o do ponteiro da pilha e o armazena em topPtr,
// recebe o endere�o da string de comando e o armazena em cmd e recebe o endere�o da
// string que define o modo de sa�da do valor calculado (define a base do resultado) e
// o armazena em outputmode.
// Se topPtr for nulo, a fun��o deve retornar o inteiro -3
// Se a pilha estiver vazia, deve retornar o inteiro -2, pois faltam os dois operandos 
// para realizar a opera��o
// Se a pilha contiver apenas um elemento, um dos operandos estiver faltando, a fun��o
// retorna o inteiro -1
// Para qualquer problema encontrado na pilha, a pilha deve ser devolvida ao 
// sistema em seu estado original (deve permanecer inalterada).
// Se a pilha estiver em condi��es, ent�o, a opera��o deve ser realizada da seguinte
// forma:
// Sacam-se (S�o popados) os operandos da pilha e a opera��o aritm�tica b�sica � 
// realizada de acordo com os par�metros estipulados pelas vari�veis cmd e outputmode.
// Se por alguma raz�o a opera��o n�o der certo, os operandos na pilha devem ser 
// preservados e a fun��o deve retornar com a pilha com o conte�do sem altera��es.
// Obrigatoriamente seu c�digo deve utilizar as fun��es definidas anteriormente 
// para o gerenciamento da pilha.
// Nenhuma opera��o aritm�tica explicita deve ser realizada com os operandos. � 
// obrigat�rio utilizar a biblioteca cplx_op para isso e, mesmo assim, 
// opera��es aritm�ticas expl�citas ou de mais baixo n�vel n�o devem ser feitas.
// 
