#include "cplx_op.h"
#include <stddef.h>
#define _USE_MATH_DEFINES
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>

#define Nsmall 1e-14

const char polar[] = { "polar" };
const char cartesian[] = { "cartesian" };

const char add[] = "add";
const char sub[] = "sub";
const char mul[] = "mul";
const char dvs[] = "dvs";


unsigned basicOp(CplxNum* x, CplxNum y, const char* cmd, const char* outputmode) {
    unsigned ret = 0;

    // Seleciona o comando
    if (cmd == NULL) {

        return 1;
    }
    else if (strcmp(cmd, add) == 0) {
        ret = complexsum(x, y);
        if (ret != 0) return ret;
    }
    else if (strcmp(cmd, sub) == 0) {
        ret = complexsub(x, y);
        if (ret != 0) return ret;
    }
    else if (strcmp(cmd, mul) == 0) {
        ret = complexmultiply(x, y);
        if (ret != 0) return ret;
    }
    else if (strcmp(cmd, dvs) == 0) {
        ret = complexdvs(x, y);
        if (ret != 0) return ret;
    }
    else {

        return 1;
    }

    // Verifica a base do resultado a ser retornado
    if (outputmode == NULL) {
        // A base é a mesma de x
        return 0;
    }
    else if (strcmp(outputmode, x->mode) == 0) {
        // A base é a mesma de x
        return 0;
    }
    else if (strcmp(outputmode, (char*)polar) == 0) {
        // Converte x para a base polar e ajusta mode
        cartesian2polar(&x->s.pol, x->s.cart);
        x->mode = (char*)polar;
        return 0;
    }
    else if (strcmp(outputmode, (char*)cartesian) == 0) {
        // Converte x para a base cartesiana e ajusta mode
        polar2cartesian(&x->s.cart, x->s.pol);
        x->mode = (char*)cartesian;
        return 0;
    }
    else {
        // Outputmode errado
        return 1;
    }

}

unsigned complexsub(CplxNum* c1, CplxNum c2) {
    unsigned ret = 0;
    Cart c2_cart;
    //Se c2 for polar
         //  transforma em cartesiano
         //  negativa 
         //  transforma em polar
         //else
         //  negativa
    if (strcmp(c2.mode, polar) == 0) {
        ret = polar2cartesian(&c2_cart, c2.s.pol);
        if (ret != 0) return ret;
        ret = negativecartesian(&c2_cart, c2_cart);
        if (ret != 0) return ret;
        ret = cartesian2polar(&c2.s.pol, c2_cart);
        if (ret != 0) return ret;
    }
    else {
        ret = negativecartesian(&c2.s.cart, c2.s.cart);
        if (ret != 0) return ret;
    }
    // soma
    ret = complexsum(c1, c2);
    //if (ret != 0) return ret;
    return ret;
}

unsigned complexdvs(CplxNum* c1, CplxNum c2) {
    unsigned ret = 0;
    Pol c2_pol;

    // Se c2 for cartesiano
       //   transforma em polar
       //   inverte
       //   transforma em cartesiano
       // else
       // inverte
    if (strcmp(c2.mode, cartesian) == 0) {
        ret = cartesian2polar(&c2_pol, c2.s.cart);
        if (ret != 0) return ret;
        ret = polarinvertion(&c2_pol, c2_pol);
        if (ret != 0) return ret;
        ret = polar2cartesian(&c2.s.cart, c2_pol);
        if (ret != 0) return ret;
    }
    else {
        ret = polarinvertion(&c2.s.pol, c2.s.pol);
        if (ret != 0) return ret;
    }
    // multiplica
    ret = complexmultiply(c1, c2);
    //if (ret != 0) return ret;
    return ret;
}

unsigned polarinvertion(Pol* w, Pol p) {

    // Normaliza o ângulo de p
    //  A norma de p será sempre positiva e 
    //  o ângulo será sempre entre -M_PI < p.g <= M_PI
    normalizeangle(&p);

    // Se a norma é zero, então o angulo também é zero
    if (fabs(p.r - 0.0) < Nsmall)
        p.g = 0;

    w->g = -p.g;

    if ((p.r) <= 1 / _HUGE_ENUF) {
        w->r = INFINITY;
        return 2;
    }

    if ((p.r) >= _HUGE_ENUF) {
        w->r = 0.0;
        w->g = 0.0;
        return 0;
    }

    w->r = 1 / p.r;

    return 0;

}

unsigned negativecartesian(Cart* x, Cart y) {
    x->a = -y.a;
    x->b = -y.b;

    return 0;

}

unsigned somacartesiana(Cart* x, Cart y) {

    x->a = x->a + y.a;
    x->b = x->b + y.b;

    return 0;
}

unsigned cartesian2polar(Pol* w, Cart x) {

    w->r = sqrt(x.a * x.a + x.b * x.b);
    w->g = atan2(x.b, x.a);

    return 0;
}

unsigned multiplypolar(Pol* w, Pol p) {

    // Testa para uma ou outra entrada zero
    if (!(w->r != 0.0) || !(p.r != 0)) {
        w->g = 0.0;
        w->r = 0.0;
        return 0;
    }

    // Soma os ângulos
    w->g = w->g + p.g;
    normalizeangle(w);

    // Testa para uma ou outra entrada infinita
    if (w->r >= INFINITY || p.r >= INFINITY) {
        w->r = INFINITY;
        return 2;
    }

    // Testa se as duas entradas tem números gigantescos
    if (w->r >= _HUGE_ENUF && p.r >= _HUGE_ENUF) {
        w->r = INFINITY;
        return 2;
    }

    // Multiplica as normas
    w->r = w->r * p.r;

    return 0;
}

// Normaliza o ângulo no intervalo PI > ângulo >= PI
unsigned normalizeangle(Pol* w) {
    long double angle, n_angle, frac;
    long long int integ;

    n_angle = w->g / (2 * M_PI); // Quantidade de 2PI existem em w->g
    integ = (long long int) n_angle; // Quantidades inteiras de 2PI existem em n_angle
    frac = (n_angle - (long double)integ); // Separa a fração de 2PI existe em n_angle
    angle = frac * 2 * M_PI; // 0 <= |angle| < 2*PI
    if (angle >= 0) {
        if (angle > M_PI) {
            w->g = -(2 * M_PI - angle);
        }
        else {
            w->g = angle;
        }
    }
    else {
        angle = -angle;
        if (angle > M_PI) {
            w->g = (2 * M_PI - angle);
        }
        else {
            w->g = -angle;
        }
    }
    // Marretada numérica
    // Se o ângulo estiver na vizinhança de PI, então é PI
    if ((M_PI - fabsl(w->g)) < Nsmall) {
        w->g = M_PI;
    }

    // Se a norma de w for menor que zero,
    //  subtrai PI (180o) do angulo de w
    //  inverte o sinal da norma de w
    //  renormaliza
    if (w->r < 0) {
        w->g = w->g - M_PI;
        w->r = -w->r;

        // Renormaliza
        angle = w->g;
        if (angle >= 0) {
            if (angle > M_PI) {
                w->g = -(2 * M_PI - angle);
            }
            else {
                w->g = angle;
            }
        }
        else {
            angle = -angle;
            if (angle > M_PI) {
                w->g = (2 * M_PI - angle);
            }
            else {
                w->g = -angle;
            }
        }
        // Marretada numérica
        // Se o ângulo estiver na vizinhança de PI, então é PI
        if ((M_PI - fabsl(w->g)) < Nsmall) {
            w->g = M_PI;
        }
    }

    return 0;
}

unsigned polar2cartesian(Cart* x, Pol w) {

    if (w.r == 0.0) {
        x->a = 0.0;
        x->b = 0.0;
        return 0;
    }

    if (w.r >= INFINITY) {
        x->a = INFINITY;
        x->b = INFINITY;
        return 2;
    }

    if (w.g >= INFINITY) {
        x->a = INFINITY;
        x->b = INFINITY;
        return 2;
    }

    // normalizeangle(&w);

    x->a = w.r * cos(w.g);
    x->b = w.r * sin(w.g);

    return 0;
}

unsigned complexsum(CplxNum* c1, CplxNum c2) {

    Cart c1_cart, c2_cart;
    unsigned ret;

    if (strcmp(c1->mode, cartesian) == 0) {
        if (strcmp(c2.mode, polar) == 0) {
            // Transforma c2 para cartesiano em c2_cart
            ret = polar2cartesian(&c2_cart, c2.s.pol);
            if (ret != 0) {
                return ret;
            }
            // Soma c1 e c2_cart
            ret = somacartesiana(&c1->s.cart, c2_cart);
            if (ret != 0) {
                return ret;
            }
        }
        else {
            // Soma c1 e c2
            ret = somacartesiana(&c1->s.cart, c2.s.cart);
            if (ret != 0) {
                return ret;
            }
        }
    }
    else {
        if (strcmp(c2.mode, polar) == 0) {
            // transforma c1 e c2 para cartesiano em c1_cart e em c2_cart
            ret = polar2cartesian(&c1_cart, c1->s.pol);
            if (ret != 0) {
                return ret;
            }
            ret = polar2cartesian(&c2_cart, c2.s.pol);
            if (ret != 0) {
                return ret;
            }
            // soma c1_cart e c2_cart
            ret = somacartesiana(&c1_cart, c2_cart);
            if (ret != 0) {
                return ret;
            }
            // transforma c1_cart para polar em c1
            ret = cartesian2polar(&c1->s.pol, c1_cart);
            if (ret != 0) {
                return ret;
            }
        }
        else {
            // transforma c1 para cartesiano em c1_cart
            ret = polar2cartesian(&c1_cart, c1->s.pol);
            if (ret != 0) {
                return ret;
            }
            // soma c1_cart e c2
            ret = somacartesiana(&c1_cart, c2.s.cart);
            if (ret != 0) {
                return ret;
            }
            // transforma c1_cart para polar em c1
            ret = cartesian2polar(&c1->s.pol, c1_cart);
            if (ret != 0) {
                return ret;
            }
        }
    }

    return 0;
}

unsigned complexmultiply(CplxNum* c1, CplxNum c2) {
    Pol c1_pol, c2_pol;
    unsigned ret;

    if (strcmp(c1->mode, cartesian) == 0) {
        if (strcmp(c2.mode, polar) == 0) {
            // transforma c1 para polar em c1_pol
            ret = cartesian2polar(&c1_pol, c1->s.cart);
            if (ret != 0) {
                return 2;
            }
            // multiplica c1_pol por c2
            ret = multiplypolar(&c1_pol, c2.s.pol);
            if (ret != 0) {
                return 2;
            }
            // transforma c1_pol para cartesiano em c1
            ret = polar2cartesian(&c1->s.cart, c1_pol);
            if (ret != 0) {
                return 2;
            }
        }
        else {
            // transforma c1 para polar em c1_pol
            ret = cartesian2polar(&c1_pol, c1->s.cart);
            if (ret != 0) {
                return 2;
            }
            // transforma c2 para polar em c2_pol
            ret = cartesian2polar(&c2_pol, c2.s.cart);
            if (ret != 0) {
                return 2;
            }
            // multiplica c1_pol por c2_pol
            ret = multiplypolar(&c1_pol, c2_pol);
            if (ret != 0) {
                return 2;
            }
            // transforma c1_pol para cartesiano em c1
            ret = polar2cartesian(&c1->s.cart, c1_pol);
            if (ret != 0) {
                return 2;
            }
        }
    }
    else {
        if (strcmp(c2.mode, polar) == 0) {
            // multiplica c1 por c2
            ret = multiplypolar(&c1->s.pol, c2.s.pol);
            if (ret != 0) {
                return 2;
            }
        }
        else {
            // transforma c2 para polar em c2_pol
            ret = cartesian2polar(&c2_pol, c2.s.cart);
            if (ret != 0) {
                return 2;
            }
            // multiplica c1 por c2_pol
            ret = multiplypolar(&c1->s.pol, c2_pol);
            if (ret != 0) {
                return 2;
            }
        }
    }

    return 0;
}
