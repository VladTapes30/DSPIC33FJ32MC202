//4 bits -> RD0 RD1 RD2 RD3
//Variables:
#define LCD_PORT PORTB
#define LCD_TRIS TRISB

//Variables de configuracion
#define RW_PIN  LATBbits.LATB6
#define RW_TRIS TRISBbits.TRISB6

#define RS_PIN  LATBbits.LATB5
#define RS_TRIS TRISBbits.TRISB5

#define E_PIN   LATBbits.LATB4
#define E_TRIS  TRISBbits.TRISB4

//Función:
void LCD_Init(void);
void LCD_Comando(unsigned char cmd);
void LCD_XY(int x,int y);
void LCD_Cadena(const char *);
void LCD_Data(char);
