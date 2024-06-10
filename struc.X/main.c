#include <stdio.h>
#include <stdlib.h>

struct triangulo
{
  int   _base;
  float altura;
};

typedef struct
{
    float radio;
    float altura;
}cilindro;
#define pi 3.1416;
/*declaracion de variables*/
float res,res2;
/*declaracion de variables tipo struct*/
struct triangulo t;
/*declaracion de varialbes con typedef*/
cilindro c;
int main() 
{
    
    c.altura = 20;
    c.radio  = 5;
    
    t._base  = 10;
    t.altura = 5;
    
    res  = (t._base * t.altura) / 2;
    res2 = (3.1416 * (c.radio * c.radio))*c.altura; 
    
    printf("el area del triangulo es %0.2f",res);
    printf("el volumen del cilindro es %0.2f",res2);
    
    while (1);
    return 0;
}
