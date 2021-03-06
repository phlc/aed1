/*
Exemplo0414 - v0.0. - 31 / 08 / 2019
Author: Pedro Henrique Lima Carvalho
*/

// dependencias
#include "io.h" // para definicoes proprias

/**
Funcao para determinar se letra e' maiuscula
return true se maiuscula, false se minuscula
parametro char
*/

bool isuppercase (char x)
{
   // testa se caractere e' maiusculo
   return (('A' <= x) && (x <= 'Z'));
}
//fim isuppercase

/**
Funcao para contar letras maiusculas de uma string
return int numero de maiusculas
parametro string
*/

int numerodemaiusculas (chars string)
{
   //define dados
   int tamanho = 0;
   int quantidade = 0;
   
   //afere tamanho string
   tamanho = strlen (string);
   
   //confere cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      //confere e conta maiusculas
      if (isuppercase (string [x]))
      {
         quantidade = quantidade + 1;
      }//fim se
   }//fim for
   
   //retorna quantidade
   return (quantidade);
}
//fim numerodemaiusculas

/**
Funcao para separar maiusculas de uma string em nova string
return string de maiusculas
parametros string
*/

chars sep_maiusculas (chars string)
{
   //define dados
   chars maiusculas = IO_new_chars (STR_SIZE);
   int contador = 0;
   int tamanho = 0;
   
   //verifica tamanho string
   tamanho = strlen (string);
   
   //confere cada caractere
   for (int x =0; x < tamanho; x = x + 1)
   {
      //verifica se e' maiuscula
      if (isuppercase (string [x]))
      {
         //armazer maiuscula
         maiusculas [contador] = string [x];
         
         //fechar string
         maiusculas [contador + 1] = EOS;
         
         //aumentar contador 
         contador = contador + 1;
      }//fim se
   }//fim for
   
   //retornar string de maiusculas
   return (maiusculas);
}
//fim sep_maiusculas

/**
Method00 - nao faz nada.
*/
void method00 ( )
   {
   // nao faz nada
   }// fim method00 ( )

/**
Method01 - Ler intervalo real fechado, quantidade, valores reais e 
mostrar quantos estao dentro e quantos estao fora.
*/
void method01 ( )
   {
   // definir dado
   double limite_inferior = 0.0;
   double limite_superior = 0.0;
   int quantidade = 0;
   double valor = 0.0;
   int contador_dentro = 0;
   int contador_fora= 0;

   // identificar
   IO_id ( "EXEMPLO0414 - Method01 - v0.0" );

   // ler do teclado
   limite_inferior = IO_readdouble ( "Entrar com limite inferior (real): ");
   
   // assegurar limite superior maior que limite inferior
   do
   {
      limite_superior = IO_readdouble( "Entrar com limite superior (real): ");
   }
   while (limite_superior <= limite_inferior);
   
   // ler quantidade
   quantidade = IO_readint ( "Entrar com uma quantidade: " );

   // repetir para a quantidade de vezes informada
   for (int x = 1; x <= quantidade; x = x + 1 )
   {
      // ler valor do teclardo
      valor = IO_readdouble (IO_concat (IO_tostring_d (x), ": "));
      
      //verificar se dentro ou fora do intervalo
      if ((limite_inferior <= valor) && (valor <= limite_superior))
      {
         contador_dentro = contador_dentro + 1;
      }
      else
      {
         contador_fora = contador_fora + 1;
      }
      
   } // fim repetir

   // mostrar quantos estao dentro do intervalo
   printf ("\n%s%d\n%s%d\n", "Quantos valores dentro do intervalo: ",
           contador_dentro, "Quantos valores fora do intervalo: ", contador_fora);
 
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
}// fim method01 ( )

/**
Method02 - Ler sequencia de caracteres, contar e mostrar letras maiusculas.
*/
void method02 ( )
{
   //definir dados
   chars sequencia = IO_new_chars (STR_SIZE);
   int contador = 0;
   int tamanho = 0;
   
   // identificar
   IO_id ( "EXEMPLO0414 - Method02 - v0.0" );
   
   //ler sequencia de caracteres
   sequencia = IO_readstring ("Entrar com sequencia de caracteres: ");
   
   //determinar tamanho da sequencia
   tamanho = strlen (sequencia);
   
   // conferir cada caractere de sequencia
   for (int x = 0; x < tamanho; x = x + 1)
   {
      // conferir se caractere e' letra maiuscula
      if (isuppercase (sequencia [x]))
      {
         contador = contador + 1;
      }
   }
   
   //mostrar quantidade de letras maiusculas
   printf ("\n%s%d\n", "Quantidade de letras maiusculas: ", contador);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
Method03 - Ler sequencia de caracteres, contar e mostrar quantidade de
maiusculas usando funcao que recebe string como parametro.
*/
void method03 ( )
{
   // definir dados
   chars sequencia = IO_new_chars (STR_SIZE);
   int quantidade = 0;
   
   // identificar
   IO_id ( "EXEMPLO0414 - Method03 - v0.0" );
   
   // ler dados
   sequencia = IO_readstring ("Entrar com uma sequencia de caracteres: ");
   
   // descobrir numero de maiusculas
   quantidade = numerodemaiusculas (sequencia);
   
   // mostrar numero de maiusculas
   printf ("\n%s%d\n", "Quantidade de letras maiusculas: ", quantidade);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
Method04 - Ler sequencia de caracteres e separar letras maiusculas
mediante uso de uma funcao definida para receber uma cadeia de 
caracteres.
*/
void method04 ( )
{
   //definer dados
   chars sequencia = IO_new_chars (STR_SIZE);
   chars maiusculas = IO_new_chars (STR_SIZE);
   
   // identificar
   IO_id ( "EXEMPLO0414 - Method04 - v0.0" );
   
   //ler sequencias de caracteres
   sequencia = IO_readstring ("Entrar com sequencia de caracteres: ");
   
   //separar maiusculas
   maiusculas = sep_maiusculas (sequencia);
   
   //mostrar maiusculas
   printf ("\n%s[%s]\n", "Letras maiusculas: ", maiusculas);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
Method05.
*/
void method05 ( )
{
   // identificar
   IO_id ( "EXEMPLO0414 - Method05 - v0.0" );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
   // identificar
   IO_id ( "EXEMPLO0414 - Method06 - v0.0" );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
   // identificar
   IO_id ( "EXEMPLO0414 - Method07 - v0.0" );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
   // identificar
   IO_id ( "EXEMPLO0414 - Method08 - v0.0" );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
   // identificar
   IO_id ( "EXEMPLO0414 - Method09 - v0.0" );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
   // identificar
   IO_id ( "EXEMPLO0414 - Method10 - v0.0" );

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

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
      IO_id ( "EXEMPLO0414 - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( " 0 - parar" );
      IO_println ( " 1 - ler intervalo fechado e verificar quantidade dentro e fora" );
      IO_println ( " 2 - ler caracteres, contar e mostrar maiusculas" );
      IO_println ( " 3 - ler caracteres, contar maiusculas com funcao (string)" );
      IO_println ( " 4 - ler caracteres, separar maiusculas com funcao (string)" );
      IO_println ( " 5 - " );
      IO_println ( " 6 - " );
      IO_println ( " 7 - " );
      IO_println ( " 8 - " );
      IO_println ( " 9 - " );
      IO_println ( "10 - " );
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

         default:
         IO_pause ( "ERRO: Valor invalido." );
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

a.) -1
b.) 0
c.) 5, -1.1 e 4.4 e { -1.2, -1.01, 1.2, 3.9, 5.1 }
d.) palavra, PALAVRA, Palavra, pALAVRA
e.) PALAVRA, Palavra, palavra, #$34erPQ
f.) PALAVRA, Palavra, palavra, %ˆ66fgBN

---------------------------------------------- historico
Versao      Data     Modificacao
0.1         31/08   esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/