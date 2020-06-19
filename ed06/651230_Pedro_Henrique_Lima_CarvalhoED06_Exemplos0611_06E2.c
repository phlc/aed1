/*
PUC-Minas - Ciência da Computação
AED1 – Estudo Dirigido 06
Exemplos 0611 - 06E2
Author: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.h"

/**
Method00 - nao faz nada
*/
void method00 ()
{
   //nao faz nada
}//fim method00

/**
Method01a - mostra quantidade de valores impares 
em ordem crescente comecando em 5
*/
void method01a (int n)
{
   //condicao motor
   if (n > 1)
   {
      //chamar method01a recursivamente
      method01a (n-1);
      
      //mostrar n
      printf ("%d: %d\n", n, (4 + (n*2-1)));
   }
   //base
   else
   {
      //mostrar n = 1
      printf ("%d: %d\n", n, (4 + (n*2-1)));
   } 
}//fim method01a

/**
Method01 - Chama method01a
*/
void method01 ()
{
   //definir dados
   int n = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method01 - v0.0");
   
   //ler teclado conferindo se n > 0
   do
   {
      n = IO_readint ("Entrar com um valor inteiro: ");
   }while (n <= 0);
   
   //chamar method01a
   method01a (n);
    
   //encerrar
   IO_pause ("Aperte ENTER para continuar");
}//fim method01

/**
Method02a - Mostra quantidade de valores multiplos de 3
em ordem decrescente encerrando em 5
*/
void method02a (int n)
{
   //condicao motor
   if (n > 1)
   {
      //mostrar n
      printf ("%d: %d\n", n, (3 + (n*3)));
      
      //chamar method01a recursivamente
      method02a (n-1);
   }
   //base
   else
   {
      //mostrar n = 1
      printf ("%d: %d\n", n, (3 + (n*3)));
   } 
}//fim method02a

/**
Method02 - Chama method02a
*/
void method02 ()
{
   //definir dados
   int n = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method02 - v0.0");
   
   //ler teclado conferindo se n > 0
   do
   {
      n = IO_readint ("Entrar com um valor inteiro: ");
   }while (n <= 0);
   
   //chamar method01a
   method02a (n);
    
   //encerrar
   IO_pause ("Aperte ENTER para continuar");
}//fim method02

/**
Method03a - Mostra quantidade de valores da sequencia:
1 5 10 15..
*/
void method03a (int n)
{
   //condicao motor
   if (n > 1)
   {
      //chamar method03a recursivamente
      method03a (n-1);
      
      //mostrar n
      printf ("%d: %d\n", n, (n-1)*5);
   }//fim if
   else
   {
      printf ("%d: %d\n", n, n);
   }//fim else
}//fim method3a

/**
Method03 - Chama method03a
*/
void method03 ()
{
   //definir dados
   int n = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method03 - v0.0");
   
   //ler teclado conferindo se n > 0
   do
   {
      n = IO_readint ("Entrar com um valor inteiro: ");
   }while (n <= 0);
   
   //chamar method03a
   method03a (n);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar");
}//fim method03

/**
Method04a - Mostrar quantidade em valores decrescentes
da sequencia 1/625, 1/125, 1/25, 1/5, 1/1
*/
void method04a (int n)
{
   //condicao motor
   if (n > 1)
   {
      //mostrar n
      printf ("%d: 1/%d\n", n, (int)pow(5, (n-1)));
      
      //chamar method04a recursivamente
      method04a (n-1);
   }//fim if
   //condicao base
   else
   {
      printf ("%d: %d\n", n, n);
   }//fim else
}//fim method04a

/**
Method04 - Chama method04a
*/
void method04 ()
{
   //definir dados
   int n = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method04 - v0.0");
   
   //ler teclado conferido n >0
   do
   {
      n = IO_readint ("Entrar um valor inteiro: ");
   }while(n<=0);
   
   //chamar method04a
   method04a (n);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar");
}//fim method04

/**
Method05a - Mostra cada simbolo de uma cadeia
de caracteres separadamente
*/
void method05a (char* string, int n)
{
   //condicao motor
   if (n > 1)
   {
      //chamar method05a recursivamente
      method05a (string, n-1);
      
      //mostrar string[n-1]
      printf ("%d: %c\n", n, string[n-1]);
   }
   //condicao base
   else
   {
      printf ("%d: %c\n", n, string[n-1]);
   }
}//fim method05a

/**
Method05 - Chama method05a
*/
void method05 ()
{
   //definir dados
   char* string = malloc (sizeof (char) * STR_SIZE);
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method05 - v0.0");
   
   //ler teclado
   printf ("Entre com uma cadeia de caracteres: \n");
   scanf ("%s", string);
   
   //chamar method05a conferindo string
   if (string != NULL)
   {
      method05a (string, strlen(string));
   }//fim if
   
   //encerrar
   free (string);
   IO_pause ("Aperte ENTER para continuar");
}//fim method05

/**
Somar - Calcula a soma dos primeiros valores
impares positivos comecando em 3
*/
int somar (int n)
{
   //definir dados
   int soma = 0;
   
   //conferir valor de n
   if (n < 1)
   {
      return (0);
   }
   
   //condicao motor
   if (n > 1)
   {
      //chamar somar () recursivamente
      soma = (somar(n-1) + (n*2+1));
      
      //mostrar numero
      printf ("%d: %d\n", n, (n*2+1));
      
      //retorna soma
      return (soma); 
   }//fim if
   //base
   else
   {
      //mostra valor base
      printf ("%d: %d\n", n, 3);
      
      //retorna valor base
      return (3);
   }//else
   
}//fim somar

/**
Method06 - Chama somar()
*/
void method06 ()
{
   //definir dados
   int soma = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method06 - v0.0");
   
   //chamar soma()
   soma = somar (10);
   
   //mostrar soma
   printf ("%s%d", "Soma: ", soma);
   
   IO_pause ("Aperte ENTER para continuar");
   
}//fim method06

/**
Invsomar - Calcula a soma dos inversos primeiros valores
impares positivos comecando em 3
*/
double invsomar (int n)
{
   //definir dados
   double soma = 0.0;
   
   //conferir valor de n
   if (n < 1)
   {
      return (0.0);
   }
   
   //condicao motor
   if (n > 1)
   {
      //chamar somar () recursivamente
      soma = (invsomar(n-1) + 1.0/(double)(n*2+1));
      
      //mostrar numero
      printf ("%d: 1/%d= %lf\n", n, (n*2+1), 1.0/(double)(n*2+1));
      
      //retorna soma
      return (soma); 
   }//fim if
   //base
   else
   {
      //mostra valor base
      printf ("%d: 1/%d= %lf\n", n, 3, 1.0/3.0 );
      
      //retorna valor base
      return (1.0/3.0);
   }//else
   
}//fim invsomar

/**
Method07 - Chama invsomar()
*/
void method07 ()
{
   //definir dados
   double soma = 0.0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method07 - v0.0");
   
   //chamar soma()
   soma = invsomar (5);
   
   //mostrar soma
   printf ("%s%lf", "Soma: ", soma);
   
   IO_pause ("Aperte ENTER para continuar");
   
}//fim method07

/**
Fibopar - Calcula o n termo par da serie 
fibonacci comecanco em 1
@param - int n termo da serie, int counter contador
@return - termo da serie
*/
int fibopar (int n, int counter)
{
   //definir dados
   int termo = 0;
   int n_original = n; //necessario pois depois n sera incrementado
   
   // na primeira chamada de fibopar, reduz n para 1, assim, 
   // calcula todos os termos e nao salta nenhum termo par
   if (counter < n)
   {
      n=1;
   }//fim if
   
   do //loop enquanto contador nao contar o numero de termos pares
   {  
      // motor fibonacci
      if (n >= 3)
      {
         //a partir da segunda chamada, n e contador iguais assim 
         //nem a reducao de n para 1, nem o loop ocorrem daqui para frente
         termo = fibopar (n-1, n-1) + fibopar (n-2, n-2);
      }
      //base
      else
      {
         termo = 1;
      }
      //contador de termos pares
      if (termo % 2 == 0)
      {
         counter = counter + 1;
      }
      
      //testando de n=1 ate n de forma que entre n termos pares
      n = n+1;
        
   }while (counter < n_original); //contador ate numero de termos pares

   //retorna termo
   return (termo);
}

/**
Method08 - Chama fibopar ()
*/
void method08 ()
{
   //definir dados
   int termo = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method08 - v0.0");
   
   //chamar fibopar
   termo = fibopar (5, 0);
   
   //mostrar termo
   printf ("%s%d\n", "5o termo par da sequencia Fibonacci: ", termo);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar"); 
}//fim method08

/**
countdigiteven - Conta os digitos pares de uma 
cadeia de caracteres
@param char* string e int strlen(string)
@return int numero de caracteres
*/

int countdigiteven (char* string, int n)
{
   //definir dados
   int contagem = 0;
   
   //condicao motor
   if (n > 1 )
   {
      contagem = countdigiteven (string, n-1);
   }
   //verificar se caracter e' digito
   if ('0' <= string [n-1] && string [n-1] <= '9')
   {
      //verificar se digito e'par
      if ((int)string [n-1] % 2 == 0)
      {
         contagem = contagem +1;
      }//fim if
   }//fim if
   //retorna contagem
   return (contagem);
}//countdigiteven

/**
method09 - Chama countdigiteven ()
*/
void method09 ()
{
   //definir dados
   int contagem = 0;
   char string[] = "Ab1246$%09";
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method09 - v0.0");
   
   //chamar fibopar
   contagem = countdigiteven (string, strlen(string));
   
   //mostrar termo
   printf ("%s%s: %d\n", "Numero de digitos pares na cadeia: ", string, contagem);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar"); 
}//fim method09


/**
countupper - Conta as letras maiusculas de uma 
cadeia de caracteres
@param char* string e int strlen(string)
@return int numero de caracteres
*/

int countupper (char* string, int n)
{
   //definir dados
   int contagem = 0;
   
   //condicao motor
   if (n > 1 )
   {
      contagem = countupper (string, n-1);
   }
   //verificar se caracter e' digito
   if ('A' <= string [n-1] && string [n-1] <= 'Z')
   {
      contagem = contagem +1;
   }//fim if
   //retorna contagem
   return (contagem);
}//fim countupper

/**
method10 - Chama countupper ()
*/
void method10 ()
{
   //definir dados
   int contagem = 0;
   char string[] = "Ab1C6$%Lk";
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method10 - v0.0");
   
   //chamar fibopar
   contagem = countupper (string, strlen(string));
   
   //mostrar termo
   printf ("%s%s: %d\n", "Numero de maiusculas na cadeia: ", string, contagem);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar"); 
}//fim method10

/**
fdexn - Calcula f(x) para n termod da funcao
f(x)=1+x1+x3+x5+x7...
@param double x - variavel da funcao / int n - numero de termos
@return double - f(x).
*/
double fdexn (double x, int n)
{
   //definir dados
   double resultado = 0.0;
   
   //condicao motor
   if (n>1)
   {
      //chamar fdexn recusivamente
      resultado = fdexn (x, n-1);
      
      //calcula f(x) para termo n
      resultado = resultado + pow (x, (double)(n*2-3));
      
   }//fim if
   //base
   else
   {
      //resultado
      resultado = 1.0;
   }//fim else   
   
   //retorna resultado
   return (resultado);
}//fim fdexn

/**
method11 - Chama fdexn ()
*/
void method11 ()
{
   //definir dados
   double resultado = 0.0;
   double x = 0.0;
   int n = 0;
   
   //identificar
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method11 - v0.0");
   
   //ler teclado
   printf ("%s\n", "f(x)=1+x1+x3+x5... ");
   x = IO_readdouble ("Entre com o valor de x: ");
   n = IO_readint ("Entre com numero de termos a ser calculado: ");
   
   //chamar fdexn
   resultado = fdexn (x, n);
   
   //mostrar resultado
   printf ("%s%lf%s%lf%s%d\n", "f(", x, ") = ", resultado, 
            " | n = ", n);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar"); 
}//fim method11

/**
fatorial - Calcula o fatorial de um numero x
@param int x
@return fatorial de x
*/
int fatorial (int x)
{
   //definir dados
   int fat = 0;
   
   //condicao base
   if (x == 1 || x == 0)
   {
      fat = 1;
   }//fim if
   else
   {
      fat = x * fatorial (x-1);
   }//fim else
   
   //retorna fatoria
   return (fat);

}//fim fatorial

/**
fdee - Funcao que calcula e = 1+1/2!+2/3!+3/4!...
para n termos
@param int n - numero de termos
@return double e - e
*/
double fdee (int n)
{
   //definir dados
   double e = 0.0;
   
   //condicao base
   if (n == 1)
   {
      e = 1.0;
      
      //mostrar termo n
      printf ("%s%d", "e=", 1);
   }
   //motor
   else
   {
      e = (double)(n-1)/(double)fatorial (n);
      
      //somar e
      e = e + fdee (n-1);
      
      //mostra termo n
      printf ("+%d/%d!", n-1, n);
   }
   //retorna e
   return (e);
}//fim fdee

/**
Method12 - chama fdee
*/
void method12 ()
{
   //define dados
   double e = 0;
   int n = 0;
   
   //identifica
   IO_id ("\nEXEMPLO 0611 - 06E2 - Method12 - v0.0");
   
   //ler teclado
   printf ("%s\n", "e=1+1/2!+2/3!+4/5!+6/7!...");
   n = IO_readint ("Entre com numero de termos a ser calculado: ");
   
   //chama fdee para n termos
   e = fdee (n);
   
   //mostra e
   printf ("%s%lf%s%d\n", " = ", e, " | n = ", n);
   
   //encerrar
   IO_pause ("Aperte ENTER para continuar");
}//fim method12


/**
Funcao Principal - Lista de opcoes
*/

int main ()
{
   //dados
   int x = 0;
   
   //identificacao
   IO_id ("EXEMPLOS 0611 - 06E2 - Programa - v0.0");

   //repetir ate opcao de sair
   do
   {
      //mostrar opcoes
      IO_println ("0- Para sair");
      IO_println ("1- Ler teclado, mostrar quantidade de valores impares crescente comecando em 5");
      IO_println ("2- Ler teclado, mostrar quantidade de valores multiplos de 3 decrescente encerrando em 5");
      IO_println ("3- Ler teclado, mostrar quantidade da sequencia 1, 5, 10, 15...");
      IO_println ("4- Ler teclado, mostrar quantidade da sequencia ...1/625, 1/125, 1/25, 1/5, 1");
      IO_println ("5- Ler cadeia de caracteres, mostrar cada simbolo separadamente");
      IO_println ("6- Calcular a soma dos primeiros valores impares positivos comecando em 3");
      IO_println ("7- Calcular a soma dos inversos dos primeiros valores impares positivos comecando em 3");
      IO_println ("8- Calcular certo termo par da seria Fibonacci comecando em 1");
      IO_println ("9- Contar digitos pares de uma cadeia de caracteres");
      IO_println ("10- Contar maiusculas de uma cadeia de caracteres");
      IO_println ("11- Calcular n termos de f(x)=1+x1+x3...");
      IO_println ("12- Calcular n termos de e=1+1/2!+2/3!+4/5!...");

      //ler teclado
      x = IO_readint ("Selecione uma opcao: ");
      
      //chamar method correspondente a opcao
      switch (x)
      {
         case 0:
         method00();
         break;
         
         case 1:
         method01();
         break;
         
         case 2:
         method02();
         break;
         
         case 3:
         method03();
         break;
         
         case 4:
         method04();
         break;
         
         case 5:
         method05();
         break;
         
         case 6:
         method06();
         break;
         
         case 7:
         method07();
         break;
         
         case 8:
         method08();
         break;
         
         case 9:
         method09();
         break;
         
         case 10:
         method10 ();
         break;
         
         case 11:
         method11 ();
         break;
         
         case 12:
         method12 ();
         break;
         
         default:
         IO_println ("Opcao Invalida");
      }//fim switch
   }while (x!=0);//fim while
   
   //pausa
   IO_pause ("Aperte ENTER para terminar");
   
   //retorno
   return (0);
}// fim main ()

/*
----------------------------------------- documentacao complementar

----------------------------------------- notas / observacoes / comentarios

----------------------------------------- previsao de testes 
a.) 5, 0, 10
b.) 5, 0, 10
c.) 1, 0, 10
d.) 1, 0, 10
e.) as, aB4$
f.) 5, 10, 1
g.) 5, 10, 1
h.) 1, 3, 7
i.) das32, F3$5ˆh0
j.) das32, F3$5ˆh0
k.) 1, 5, 10
l.) 1, 5, 10
m.) 2.2 e 3, 2.0 e 5
n.) 4, 9, 10
------------------------------------------ historico
Versao   Data     Modificacao
0.1      13/09    esboco 

---------------------------------------------- testes
Versao   Teste
0.1      01. ( OK ) method01
0.2      01. ( OK ) method02
0.3      01. ( OK ) method03
0.4      01. ( OK ) method04
0.5      01. ( OK ) method05
0.6      01. ( OK ) method06
0.7      01. ( OK ) method07
0.8      01. ( OK ) method08
0.9      01. ( OK ) method09
0.10     01. ( OK ) method10
0.11     01. ( OK ) method11
0.12     01. ( OK ) method12

*/