/*
Exemplo03E1 - v0.0. - 25 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
Method00 - nao faz nada.
*/
void method00 ( )
   {
   // nao faz nada
   } // fim method00 ( )

/**
Method01 -  Verificar letra maiuscula.
*/
void method01 ( )
{
   // definir dado
   char palavra[STR_SIZE];
   int tamanho = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method01 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma palavra: " );
   scanf ("%s", palavra);
   
   // verificar tamanho da palavra
   tamanho = strlen (palavra);
   
   // passar por cada letra da palavra
   for (int x = 0; x < tamanho; x = x +1)
   {
      // verificar se letra é maiuscula
      if ((65 <= (int) palavra [x]) && ((int) palavra [x] <= 90))
      {
         printf ("%c\n", palavra [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02 -  Verificar letra maiuscula e contar.
*/
void method02 ( )
{
   // definir dado
   char palavra[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method02 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma palavra: " );
   scanf ("%s", palavra);
   
   // verificar tamanho da palavra
   tamanho = strlen (palavra);
   
   // passar por cada letra da palavra
   for (int x = 0; x < tamanho; x = x +1)
   {
      // verificar se letra é maiuscula
      if ((65 <= (int) palavra [x]) && ((int) palavra [x] <= 90))
      {
         contador = contador + 1;
         printf ("%s(%i) %s[%c]\n","Contagem: ", contador, "Letra: ", palavra [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03 -  Verificar letra maiuscula e contar do fim para o comeco.
*/
void method03 ( )
{
   // definir dado
   char palavra[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method03 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma palavra: " );
   scanf ("%s", palavra);
   
   // verificar tamanho da palavra
   tamanho = (strlen (palavra)) - 1;
   
   // passar por cada letra da palavra do fim para o comeco
   for (int x = tamanho; x >= 0; x = x - 1)
   {
      // verificar se letra é maiuscula
      if ((65 <= (int) palavra [x]) && ((int) palavra [x] <= 90))
      {
         contador = contador + 1;
         printf ("%s(%i) %s[%c]\n","Contagem: ", contador, "Letra: ", palavra [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )


/**
Method04 -  Verificar letra maiuscula e minuscula.
*/
void method04 ( )
{
   // definir dado
   char cadeia[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method04 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma cadeia de caracteres: " );
   scanf ("%s", cadeia);
   
   // verificar tamanho da cadeia de caracterees
   tamanho = strlen (cadeia);
   
   // passar por cada letra da palavra do fim para o comeco
   for (int x = 0; x < tamanho; x = x + 1)
   {
      // verificar se letra é maiuscula ou minuscula
      if (((65 <= (int) cadeia [x]) && ((int) cadeia [x] <= 90)) || ((97 <= (int) cadeia [x]) && ((int) cadeia [x] <= 122)))
      {
         contador = contador + 1;
         printf ("%s(%i) %s[%c]\n","Contagem: ", contador, "Letra: ", cadeia [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05 -  Verificar digitos.
*/
void method05 ( )
{
   // definir dado
   char cadeia[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method05 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma cadeia de caracteres: " );
   scanf ("%s", cadeia);
   
   // verificar tamanho da cadeia de caracterees
   tamanho = (strlen (cadeia) - 1);
   
   // passar por cada caracter da palavra do fim para o comeco
   for (int x = tamanho; x >= 0; x = x - 1)
   {
      // verificar se letra é maiuscula ou minuscula
      if ((48 <= (int) cadeia [x]) && ((int) cadeia [x] <= 57))
      {
         contador = contador + 1;
         printf ("%s(%i) %s[%c]\n","Contagem: ", contador, "Digito: ", cadeia [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )


/**
Method06 -  Verificar tudo o que nao for letra ou digito.
*/
void method06 ( )
{
   // definir dado
   char cadeia[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method06 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma cadeia de caracteres: " );
   scanf ("%s", cadeia);
   
   // verificar tamanho da cadeia de caracteres
   tamanho = strlen (cadeia);
   
   // passar por cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      // verificar se nao e digito, maiuscula ou minuscula
      if (!(((48 <= (int) cadeia [x]) && ((int) cadeia [x] <= 57)) || ((65 <= (int) cadeia [x]) && ((int) cadeia [x] <= 90)) || ((97 <= (int) cadeia [x]) && ((int) cadeia [x] <= 122))))
      {
         //contar
         contador = contador + 1;
         printf ("%s(%i) %s[%c]\n","Contagem: ", contador, "Caractere: ", cadeia [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07 -  Ler intervalo de inteiros, quantidade de inteiros,
ler a quantidade indicada de inteiros, contar e mostrar multiplos de 5.
*/
void method07 ( )
{
   // definir dado
   int limite_inferior = 0;
   int limite_superior = 0;
   int quantidade = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method07 - v0.0" );
   
   // ler do teclado
   limite_inferior = IO_readint ( "Entrar com limite inferior: " );
   limite_superior = IO_readint ( "Entrar com limite superior: " );
   quantidade = IO_readint ( "Quantidade de valores inteiros: " );
   
   // arranjo para armazenar numeros
   int numeros [quantidade];
   
   // ler tantos valores quantos indicados pela quantidade
   for (int x = 0; x < quantidade; x = x +1)
   {
      //armazenar inteiro
      numeros [x] = IO_readint ( "Entrar com inteiro: ");    
   }   
   
   // verificar numero multiplo de 5
   for (int x = 0; x < quantidade; x = x +1)   
   {   
      if (numeros [x] % 5 == 0)
      {
         contador = contador + 1;
         printf ("%s(%d) %s(%d)\n","Contagem: ", contador, "Inteiro: ", numeros [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08 -  Ler intervalo de inteiros, quantidade de inteiros,
ler a quantidade indicada de inteiros, contar e mostrar multiplos de 3
nao multiplos de 5.
*/
void method08 ( )
{
   // definir dado
   int limite_inferior = 0;
   int limite_superior = 0;
   int quantidade = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method08 - v0.0" );
   
   // ler do teclado
   limite_inferior = IO_readint ( "Entrar com limite inferior: " );
   limite_superior = IO_readint ( "Entrar com limite superior: " );
   quantidade = IO_readint ( "Quantidade de valores inteiros: " );
   
   // arranjo para armazenar numeros
   int numeros [quantidade];
   
   // ler tantos valores quantos indicados pela quantidade
   for (int x = 0; x < quantidade; x = x +1)
   {
      //armazenar inteiro
      numeros [x] = IO_readint ( "Entrar com inteiro: ");    
   }   
   
   // verificar numero multiplo de 3 nao de 5
   for (int x = 0; x < quantidade; x = x +1)   
   {   
      if ((numeros [x] % 3 == 0) && !(numeros [x] % 5 == 0))
      {
         contador = contador + 1;
         printf ("%s(%d) %s(%d)\n","Contagem: ", contador, "Inteiro: ", numeros [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )


/**
Method09 -  Ler intervalo de reais, quantidade de reais,
ler a quantidade indicada de reais, contar e mostrar impares dentro
do intervalo.
*/
void method09 ( )
{
   // definir dado
   double limite_inferior = 0.0;
   double limite_superior = 0.0;
   int quantidade = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method09 - v0.0" );
   
   // ler do teclado
   limite_inferior = IO_readdouble ( "Entrar com limite inferior: " );
   
      // confirmar valor do limite superior
   do
   {
      limite_superior = IO_readdouble ( "Entrar com limite superior: " );
   }
   while (limite_superior <= limite_inferior);
   
   quantidade = IO_readint ( "Quantidade de valores reais: " );
   
   // arranjo para armazenar numeros
   double numeros [quantidade];
   
   // ler tantos valores quantos indicados pela quantidade
   for (int x = 0; x < quantidade; x = x +1)
   {
      //armazenar valor real
      numeros [x] = IO_readdouble ( "Entrar com valor real: ");    
   }   
   
   // verificar numero dentro o intervalo e impar
   for (int x = 0; x < quantidade; x = x +1)   
   {   
      if ((limite_inferior <= numeros [x] ) && (numeros [x] <= limite_superior) && (((int) numeros [x]) %2 !=0))
      {
         contador = contador + 1;
         printf ("%s(%d) %s(%lf)\n","Contagem: ", contador, "Valor real: ", numeros [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )


/**
Method10 -  Ler intervalo de reais menores que 1 e diferentes de 0, 
confirmar intervalos, pedir quantidade de reais, ler a quantidade indicada de reais,
contar e mostrar todos os valores lidos que tenham parte fracionaria dentro do intervalo.
*/
void method10 ( )
{
   // definir dado
   double limite_inferior = 0.0;
   double limite_superior = 0.0;
   int quantidade = 0;
   int contador = 0;
   int p_inteira = 0;
   double p_fracionaria = 0.0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method10 - v0.0" );
   
   // ler do teclado
      // confirmar valor do limite inferior menor que 1 != 0
   do
   {
      limite_inferior = IO_readdouble ( "Entrar com limite inferior: " );
   }
   while ((limite_inferior >= 1) || (limite_inferior == 0));
         
      // confirmar valor do limite superior
   do
   {
      limite_superior = IO_readdouble ( "Entrar com limite superior: " );
   }
   while ((limite_superior <= limite_inferior) || (limite_superior >= 1) || (limite_superior == 0));
   
   quantidade = IO_readint ( "Quantidade de valores reais: " );
   
   // arranjo para armazenar numeros
   double numeros [quantidade];
   
   // ler tantos valores quantos indicados pela quantidade
   for (int x = 0; x < quantidade; x = x +1)
   {
      //armazenar valor real
      numeros [x] = IO_readdouble ( "Entrar com valor real: ");    
   }   
   
   // subtrair parte inteira do numero
   for (int x = 0; x < quantidade; x = x +1)   
   {   
      p_inteira = (int) numeros [x];
      p_fracionaria = numeros [x] - p_inteira;
      
      // verificar condicao: partes fracionarias dentro do intervalo
      if ((limite_inferior <= p_fracionaria) && (p_fracionaria <= limite_superior))
      {
         contador = contador + 1;
         printf ("%s(%d) %s(%lf)\n","Contagem: ", contador, "Valor real: ", numeros [x]); 
      }
      // passar ao proximo valor
   } // fim repetir
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Method11 -  Verificar tudo o que nao for letra ou digito e separar.
*/
void method11 ( )
{
   // definir dado
   char cadeia[STR_SIZE];
   char n_alfanumerica[STR_SIZE];
   int tamanho = 0;
   int contador = 0;
   
   // identificar
   IO_id ( "EXEMPLO03E1 - Method11 - v0.0" );
   
   // ler do teclado o valor inicial
   IO_println ( "Entrar com uma cadeia de caracteres: " );
   scanf ("%s", cadeia);
   
   // verificar tamanho da cadeia de caracteres
   tamanho = strlen (cadeia);
   
   // passar por cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      // verificar se nao e digito, maiuscula ou minuscula
      if (!(((48 <= (int) cadeia [x]) && ((int) cadeia [x] <= 57)) || ((65 <= (int) cadeia [x]) && ((int) cadeia [x] <= 90)) || ((97 <= (int) cadeia [x]) && ((int) cadeia [x] <= 122))))
      {
         // armazenar arquivos nao alfanumericos
         n_alfanumerica[contador] = cadeia [x];
         
         // fechar string
         n_alfanumerica[contador+1] = '\0';
         
         //contar
         contador = contador + 1;
      }
      // passar ao proximo valor
   } // fim repetir
   //mostrar a cadeia nao alfanumerica
   printf ("\n%s%s\n","Cadeia nao alfanumerica: ", n_alfanumerica);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method011 ( )



/*
Funcao principal.
@return codigo de encerramento
*/
int main ( )
   {

   // definir dado
   int x = 0;

   // repetir até desejar parar
   do
   {

      // identificar
      IO_id ( "EXEMPLO03E1 - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( "0 - parar" );
      IO_println ( "1 - teste letras maiusculas" );
      IO_println ( "2 - teste letras maiusculas com contagem" );
      IO_println ( "3 - teste letras maiusculas com contagem do fim" );
      IO_println ( "4 - teste cadeia de caracteres letras com contagem" );
      IO_println ( "5 - teste cadeia de caracteres digitos com contagem do fim" );
      IO_println ( "6 - teste cadeia de caracteres tudo menos letra e digito com contagem" ); 
      IO_println ( "7 - teste multiplos de 5, pedir intervalo e quantidade." );
      IO_println ( "8 - teste multiplos de 3, nao de 5, pedir intervalo e quantidade." );
      IO_println ( "9 - teste quantidade de impares reais, dentro de intervalo, confirmado. ");
      IO_println ( "10 - teste valores reais com parte fracionaria dentro de intervalo confirmado. ");
      IO_println ( "11 - teste linha do teclado, separa e mostra valores nao alfanumericos." );
      IO_println ( "" );
      x = IO_readint ( "Entrar com uma opcao: " );

      // testar valor
      switch ( x )
      {
         case 0:
         method00 ( );
         break;

         case 1:
         method01 ( );
         break;
         
         case 2:
         method02 ( );
         break;
         
         case 3:
         method03 ( );
         break;
         
         case 4:
         method04 ( );
         break;
         
         case 5:
         method05 ( );
         break;
         
         case 6:
         method06 ( );
         break;
         
         case 7:
         method07 ( );
         break;
         
         case 8:
         method08 ( );
         break;
         
         case 9:
         method09 ( );
         break;
         
         case 10:
         method10 ( );
         break;
         
         case 11:
         method11 ( );
         break;

         default:
         IO_pause ( "ERRRO: numero invalido.");
      } // fim escolher

   }
   while ( x != 0 );

   // encerrar
   IO_pause ( "Apertar ENTER para terminar" );
   return ( 0 );
} // fim main( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes
a.) 0
b.) 1 e AbCdEf
c.) 2 e AbCdEf
d.) 3 e AbCdEf
e.) 4 e df@3%6TT6&&
f.) 5 e a\0F:9
g.) 6 e /09:@AZ[`az{
h.) 7 e 3 5 6 10 9 15
i.) 8 e 3 5 12 15 13 21 30
j.) 9 e 3.4 2.2 5.5 6.7 8.7
k.) 10 e 0.34 0.45 0.56 -3.58 -6.57
l.) 11 e df@4%65%&j*4FwR

---------------------------------------------- historico

Versao   Data     Modificacao
0.1      25/08    esboco

---------------------------------------------- testes
Versao   Teste
0.1      01. ( OK ) identificacao de programa
*/