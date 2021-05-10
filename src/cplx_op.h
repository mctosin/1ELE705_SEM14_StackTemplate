#pragma once
#ifndef CPLX_OP_H
#define CPLX_OP_H

// Estruturas da calculadora de números complexos

typedef struct {
	double a;
	double b;
} Cart;

typedef struct {
	double r;
	double g;
} Pol;

typedef union {
	Cart	cart;
	Pol		pol;
} Cplx;

typedef struct {
	Cplx s;
	char* mode;
} CplxNum;

extern const char cartesian[];

// Protótipos das funções da calculadora números complexos

unsigned basicOp(CplxNum* x, CplxNum y, const char* cmd, const char* outputmode);
unsigned polarinvertion(Pol* w, Pol p);
unsigned negativecartesian(Cart* x, Cart y);
unsigned somacartesiana(Cart* x, Cart y);
unsigned cartesian2polar(Pol* w, Cart x);
unsigned multiplypolar(Pol* w, Pol p);
unsigned normalizeangle(Pol* w);
unsigned polar2cartesian(Cart* x, Pol w);
unsigned complexsum(CplxNum* c1, CplxNum c2);
unsigned complexmultiply(CplxNum* c1, CplxNum c2);
unsigned complexsub(CplxNum* c1, CplxNum c2);
unsigned complexdvs(CplxNum* c1, CplxNum c2);


#endif
