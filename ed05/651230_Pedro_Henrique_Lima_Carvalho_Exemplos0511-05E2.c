/*
Exemplos 0511 - 05E2 - v0.0. - 07 / 09 / 2019
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
Method01a - Mostrar quantidade em valores multiplos de 2 crescente.
@param x - quantidade de valores a serem mostrados
*/
void method01a ( int x )
{
   // definir dado local
   int y = 1; // controle
   
   // repetir enquanto controle menor que a quantidade desejada
   while ( y <= x )
   {
      // mostrar valor
      IO_printf ( "%d%s%d\n", y, "o valor = ", (y*2 ));

      // passar ao proximo
      y = y + 1;
   } // fim se
} // fim method01a( )

/**
Method01 - Ler certa quantidade e mostrar em valores multiplos de 2 crescente.
OBS.: Preparacao e disparo de outro metodo.
*/
void method01 ( )
{
   //definir dados
   int quantidade = 0;
   
   // identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method01 - v0.0" );

   // ler uma quantidade do teclado
   quantidade = IO_readint ("Entrar com uma quantidade inteira: ");
   
   // executar o metodo auxiliar
   method01a ( quantidade );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
Method02a - Mostrar quantidade de valores pares multiplos de 3 crescente
@param x - quantidade de valores a serem mostrados
*/
void method02a (int x)
{
   //definir controle
   int y = 1;
      
   //repetir enquanto controle menor ou igual a quantidade
   while (y <= x)
   {
      //mostrar valor
      printf ("%d%s%d\n", y, "o valor: ", y*6);
         
      //aumentar controle
      y = y + 1;
   }
}//fim method02a ()

/**
Method02 - Ler certa quantidade e mostrar em valores pares multipllos de 3 crescente.
OBS.: Preparacao e disparo de outro metodo.
*/
void method02 ( )
{
   //define dados
   int quantidade = 0;
   
   // identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method02 - v0.0" );
   
   //ler certa quantidade do teclado
   quantidade = IO_readint (" Entrar com uma quantidade inteira: ");
   
   //executar metodo auxiliar
   method02a (quantidade); 
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03a - mostra quantidade em valores impares multiplos de 3 decrescente
@param int x - quantidade de valores a serem mostrado
*/
void method03a (int x)
{
   //define controle
   int y = 1;
   
   //repetir enquanto quantidade maior ou igual a controle
   while (x >= y)
   {
      //mostrar valor
      printf ("%d%s%d\n", x, "o valor: ", (x*6-3));
      x = x - 1;
   }
}//fim method03a ()

/**
Method03 - Ler quantidade e mostrar valores impares multiplos de 3 decrescente.
OBS.: Preparacao e disparo de outro metodo.
*/
void method03 ( )
{
   //definir dados
   int quantidade = 0;
   
   // identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method03 - v0.0" );
   
   //ler quantidade do teclado
   printf ("%s", "Entrar com uma quantidade inteira: ");
   scanf ("%d", &quantidade);

   //executar metodo auxiliar
   method03a (quantidade);   
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04a - mostra quantidade de valores crescentes nos denomiadores
multiplos de 2
@param int x - quantidade a ser mostrada
*/

void method04a (int x)
{
   //define denominador
   double y = 0.0;
   
   //define numerador
   double num = 1;
   
   //type casting x
   x = (double) x;
   
   //repetir enquanto controle menor ou igual a quantidade
   for (y = 1.0; y <= x; y = y + 1.0)
   {
      //mostrar valor
      printf ("%d%s%3d/%d =%7.4lf\n", 
      (int)y, "o valor:", (int)num, (int)(y*2), num/(y*2));
   }
  
}//fim method04a ()

/**
Method04 - ler quantidade e mostar em valores crescentes nos denominadores
multiplos de 2
OBS.: Preparacao e disparo de outro metodo.
*/
void method04 ( )
{
   //definir dados
   int quantidade = 0;
   
   // identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method04 - v0.0" );

   //ler quantidade do teclado
   quantidade = IO_readint ("Entrar com quantidade inteira: ");
   
   //executar metodo auxiliar
   method04a (quantidade);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05a - mostra quantidade em valores crescentes nos denominadores
da sequencia 1 1/x 1/x2 1/x3...
@param int quanidade - quantidade a ser mostrada
@param double valor - valor real a ser tratado
*/
void method05a (int quantidade, double valor)
{
   //definir controle
   double y = 0.0;
   
   //definir numerador
   double num = 1.0;
   
   // repetir enquanto controle menor que quantidade
   while (y < quantidade)
   {
      //mostrar valores
      printf ("%d%s%7.4lf/%7.4lf=%7.4lf\n", (int)(y+1.0), "o valor:",
               num, pow(valor,y), num/pow(valor,y));
               
      //aumentar controle
      y = y + 1;
   }
}//fim method05a ()

/**
Method05 - ler um valor real e uma quantidade, mostrar quantidade em valores
crescentes nos denominadores da sequencia 1 1/x 1/x2 1/x3...
*/
void method05 ( )
{
   //definir dados
   int quantidade = 0;
   double valor = 0;
   
   // identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method05 - v0.0" );

   //ler dados do teclado
   valor = IO_readdouble ("Entrar com um valor real: ");
   quantidade = IO_readint ("Entrar com quantidade inteira: ");
   
   //executar metodo auxiliar
   method05a (quantidade, valor);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
somaparesnao5 - calcula a soma dos primeiros valores pares positivos 
comecando em dois e nao multiplos de 5
@param int x - quantidade de valores
@return soma dos valores
*/
int somaparesnao5 (int x)
{
   //definir valores locais
   int soma = 0;
   int controle = 1;
   int contador = 1;
   int valor = 0;
   
   //repetir enquanto controle menor ou igual a quantidade x
   while (contador <= x)
   {
      //atribuir a valor numero par multiplo de controle
      valor = controle*2;
      
      //verificar se valor n 'e multiplo de 5
      if (valor%5 != 0)
      {
         //mostrar valor
         printf ("%d: %d\n", contador, valor);
         
         //atualizar soma
         soma = soma + valor;
         
         //atualizar controle
         contador = contador + 1;
      }
      //atualizar contador
      controle = controle + 1;
   }
   
   //retorna soma
   return (soma);
}//fim somaparesnao5 ()

/**
Method06 - calcular a somas dos primeiros valores pares positivos
comecando em 2 e nao multiplo de 5.
*/
void method06 ( )
{
   //definir valor
   int soma = 0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method06 - v0.0" );
   
   //chamar funcao somapares para soma
   soma = somaparesnao5 (10);
   
   //mostrar resultado
   printf ("\n%s%d\n", "Soma pares !multiplos de 5: ", soma);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
somainverso - calcula a soma dos inversos dos primeiros valores 
pares positivos comecando em dois e nao multiplos de 5
@param int x - quantidade de valores
@return soma dos valores
*/
double somainverso (int x)
{
   //definir valores locais
   double soma = 0.0;
   double controle = 1.0;
   int contador = 1;
   double valor = 0.0;
   double numerador = 1.0;
   
   //repetir enquanto controle menor ou igual a quantidade x
   while (contador <= x)
   {
      //atribuir a valor numero par multiplo de controle
      valor = numerador/(controle*2.0);
      
      //verificar se valor n 'e multiplo de 5
      if ((int)(controle*2)%5 != 0)
      {
         //mostrar valor
         printf ("%d:%7.4lf/%7.4lf=%7.4lf\n", 
                  contador, numerador, controle*2, valor);
         
         //atualizar soma
         soma = soma + valor;
         
         //atualizar controle
         contador = contador + 1;
      }
      //atualizar contador
      controle = controle + 1.0;
   }
   
   //retorna soma
   return (soma);
}//fim somainverso ()

/**
Method07 - calcular a somas dos inversos dos primeiros valores 
pares positivos comecando em 2 e nao multiplo de 5.
*/
void method07 ( )
{
   //definir valor
   double soma = 0.0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method07 - v0.0" );
   
   //chamar funcao somainverso para soma
   soma = somainverso (10);
   
   //mostrar resultado
   printf ("\n%s%lf\n", "Soma inversos pares !multiplos de 5: ", soma);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )


/**
somanaturais - calcula a soma dos primeiros numeros naturais 
comecando 1
@param int x - quantidade de valores
@return soma dos valores
*/
int somanaturais (int x)
{
   //definir valores locais
   int soma = 0;
   int contador = 1;
   
   //repetir enquanto controle menor ou igual a quantidade x
   while (contador <= x)
   {
      //mostrar valor
      printf ("%s: %d\n", "N. natural: ", contador);
         
      //atualizar soma
      soma = soma + contador;
         
      //atualizar controle
      contador = contador + 1;
   }
   
   //retorna soma
   return (soma);
}//fim somanaturais ()

/**
Method08 - calcula a soma dos primeiros numeros naturais 
comecando 1.
*/
void method08 ( )
{
   //definir valor
   int soma = 0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method08 - v0.0" );
   
   //chamar funcao somanaturais para soma
   soma = somanaturais (10);
   
   //mostrar resultado
   printf ("\n%s%d\n", "Soma naturais: ", soma);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
somaquadrado - calcula a soma dos quadrados dos 
primeiros numeros naturais comecando 1
@param int x - quantidade de valores
@return soma dos valores
*/
int somaquadrado (int x)
{
   //definir valores locais
   int soma = 0;
   int contador = 1;
   
   //repetir enquanto controle menor ou igual a quantidade x
   while (contador <= x)
   {
      //mostrar valor
      printf ("%d: %d\n", contador, contador*contador);
         
      //atualizar soma
      soma = soma + contador*contador;
         
      //atualizar controle
      contador = contador + 1;
   }
   
   //retorna soma
   return (soma);
}//fim somaquadrado ()

/**
Method09 - calcula a soma dos quadrados dos primeiros 
numeros naturais comecando 1.
*/
void method09 ( )
{
   //definir valor
   int soma = 0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method09 - v0.0" );
   
   //chamar funcao somaquadrado para soma
   soma = somaquadrado (10);
   
   //mostrar resultado
   printf ("\n%s%d\n", "Soma dos quadrados: ", soma);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
somainvnat - calcula a soma dos inversos dos primeiros numeros naturais 
comecando 1
@param int x - quantidade de valores
@return soma dos inversos dos valores
*/
double somainvnat (int x)
{
   //definir valores locais
   double soma = 0;
   double contador = 1.0;
   
   //repetir enquanto controle menor ou igual a quantidade x
   while (contador <= x)
   {
      //mostrar valor
      printf ("%s%s/%7.4lf = %7.4lf\n", "Inverso n. natural: ", "1.0000", contador, 1.0/contador);
         
      //atualizar soma
      soma = soma + 1.0/contador;
         
      //atualizar controle
      contador = contador + 1.0;
   }
   
   //retorna soma
   return (soma);
}//fim somainvnat ()

/**
Method10 - calcula a soma dos inversos dos primeiros numeros naturais 
comecando 1.
*/
void method10 ( )
{
   //definir valor
   double soma = 0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method10 - v0.0" );
   
   //chamar funcao somainvnat para somar
   soma = somainvnat (10);
   
   //mostrar resultado
   printf ("\n%s\t%lf\n", "Soma dos inversos naturais: ", soma);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
fatorial - calcula o fatorial de um numero inteiro
@param int x - inteiro a ser tratado
@return int fatorial - valor do fatorial
*/
int fatorial (int x)
{  
   //retorna 1 se x igual a 1 (fatorial de 1 == 1)
   if (x==1)
   {
      //mostrar ultimo x (1)
      printf ("%d", x);
      
      //retorna 1
      return (1);
   }
   // calcula recursivamente fatorial de x ate 1
   else
   {
      //mostra x
      printf ("%d%s", x, "*");
      
      //retorna x * fatorial de x-1
      return (x*fatorial(x-1));
   }
}//fim fatorial

/**
Method11 - ler um interiro do teclado, calcular e mostrar 
seu fatorial atraves de uma funcao.
*/
void method11 ( )
{
   //definir valor
   int fat = 0;
   int valor = 0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method11 - v0.0" );
   
   //ler valor inteiro do teclado maior que 0 confirmado
   do
   {
      valor = IO_readint ("Entrar com um valor inteiro: ");
   }
   while (valor < 1);
   
   //mostra numero a ser fatorado
   printf ("%d%s", valor, "! = ");
   
   //executar funcao fatorial
   fat = fatorial (valor);
   
   //mostrar valor do fatorial
   printf ("%s%d\n", " = ", fat);
   
   //encerrar
   IO_pause ("Apertar ENTER para continuar." ); 
}//fim method11

/**
fatorialsimples - calcula o fatorial de um numero inteiro 
sem mostrar processo
@param int x - inteiro a ser tratado
@return int fatorial - valor do fatorial
*/
int fatorialsimples (int x)
{  
   //retorna 1 se x igual a 1 (fatorial de 1 == 1)
   if (x==1)
   {
      //retorna 1
      return (1);
   }
   // calcula recursivamente fatorial de x ate 1
   else
   {
      //retorna x * fatorial de x-1
      return (x*fatorialsimples(x-1));
   }
}//fim fatorialsimples

/**
Method12 - ler um interiro do teclado, calcular e mostrar 
seu fatorial atraves de uma funcao.
*/
void method12 ( )
{
   //definir valor
   double resultado = 1.0;
   int valor = 0;
   
   //identificar
   IO_id ( "Exemplos 0511 - 05E2 - Method12 - v0.0" );
   
   //ler valor inteiro do teclado maior que 0 confirmado
   do
   {
      valor = IO_readint ("Entrar com um valor inteiro: ");
   }
   while (valor < 1);
   
   //mostrar f(n)
   printf ("%s%d%s", "f(", valor, ")= ");
   
   //executar f(n)=(1+2/3!)*(1+3/4!)*(1+4/5!)*... 
   for (int x = 1; x <= valor; x = x + 1)
   {
      resultado = resultado * (1.0 + (double)(x+1)/(double)(fatorialsimples (x+2)));
   }   
   
   //mostrar resultado
   printf ("%lf\n", resultado);
   
   //encerrar
   IO_pause ("Apertar ENTER para continuar." ); 
}//fim method12


/*
Funcao principal.
@return codigo de encerramento
*/
int main ( )
{
   // definir dado
   int x = 0; // definir variavel com valor inicial

   // repetir até desejar parar
   do
   {
      // identificar
      IO_id ( "Exemplos 0511 - 05E2 - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( " 0 - parar" );
      IO_println ( " 1 - ler quantidade e mostrar em multiplos de 2 crescente" );
      IO_println ( " 2 - ler quantidade e mostrar pares multiplos de 3 crescente" );
      IO_println ( " 3 - ler quantidade e mostrar impares multiplos de 3 decrescente" );
      IO_println ( " 4 - ler quantidade e mostrar multiplos de 2 crescente denominador" );
      IO_println ( " 5 - ler quantidade e valor, mostrar 1, 1/x, 1/x2, 1/x3..." );
      IO_println ( " 6 - calcular soma dos primeiros valores pares positivos [2,..], !x5" );
      IO_println ( " 7 - calcular soma dos inversos dos valores pares positivos [2,..],!x5" );
      IO_println ( " 8 - calcular soma dos primeiros valores naturais comecando em 1" );
      IO_println ( " 9 - calcular soma dos quadrados dos primeiros numeros naturais" );
      IO_println ( "10 - calcular soma dos inversos dos primeiros numeros naturais" );
      IO_println ( "11 - ler inteiro do teclado, calcular e mostrar seu fatorial" );
      IO_println ( "12 - ler inteiro do teclado, calcular e mostrar f(n) = (1+2/3!) *(1+3/4!)*..." );
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
         
         case 12:
         method12 ( );
         break;
         
         default:
         IO_println ( "ERRO: Valor invalido." );
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
a.) 5 -> { 1, 2, 3, 4, 5 }

---------------------------------------------- historico
Versao   Data     Modificacao
0.1      __/__    esboco

---------------------------------------------- testes
Versao    Teste
0.1       01. ( OK ) identificacao de programa
*/