
#ifndef EXPRESSAO_H 
#define EXPRESSAO_H 

typedef struct { 
    char posFixa[512];     // Expressão na forma pos-fixa, como 3 12 4 + * 
    char inFixa[512];      // Expressão na forma infixa, como 3 * (12 + 4) 
    float Valor;           // Valor numérico da expressão   
} Expressao; 

char *getFormaInFixa(char *Str);      // Pós-fixa → Infixa
char *getFormaPosFixa(char *Str);     // Infixa → Pós-fixa
float getValorPosFixa(char *Str);     // Avalia pós-fixa
float getValorInFixa(char *Str);      // Avalia infixa

#endif 
