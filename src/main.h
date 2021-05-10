#pragma once
#ifndef MAIN_H
#define MAIN_H

#include "cplx_op.h"

// Estruturas do jogo de cartas com listas ligadas

typedef struct {
	const char* face; // define pointer face   
	const char* suit; // define pointer suit
	unsigned int face_number; // Define o n�mero da face da carta
	unsigned int suit_number; // Define o n�mero do naipe
	char* mode;
} Card; // end struct card  

struct listCardNode {
	Card card; /* Cada n� cont�m uma carta */
	struct listCardNode* nextPtr; /* Ponteiro para a pr�xima carta-n� */
}; /* end structure listCard */

typedef struct listCardNode ListCardNode; /* synonym for struct listNode */
typedef ListCardNode* ListCardNodePtr; /* synonym for ListNode* */

struct stackCplxNode {
	CplxNum cplx;
	struct stackCplxNode* nextPtr;
};
typedef struct stackCplxNode StackCplxNode;
typedef StackCplxNode* StackCplxNodePtr;

// Prot�tipos de fun��o
int push(StackCplxNodePtr* topPtr, CplxNum complex);
CplxNum pop(StackCplxNodePtr* topPtr);
int isEmptyStack(StackCplxNodePtr topPtr);
int basicOpStack(StackCplxNodePtr* topPtr, const char* cmd, const char* outputmode);

#endif // MAIN_H

