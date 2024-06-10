#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    uart_1,
    uart_2
}id_e;

typedef struct
{
    void (*write)(id_e id , char s);
    void (*read) (id_e id);
}uart_interface;

void write_f (id_e id , char s)
{
    //funcion para write
    printf("entro a la funcion write\n\r");
}
void read_f (id_e id)
{
    printf("entro ala funcion read\n\r");
}

//method mapping
const  uart_interface u = {
    .read  = read_f,
    .write = write_f
}; 

int main() 
{
    uart_interface uart;
    uart.read(uart_1);
    uart.write(uart_1,'h');
    
    while (1) 
    {

    }
    return 0;
}
