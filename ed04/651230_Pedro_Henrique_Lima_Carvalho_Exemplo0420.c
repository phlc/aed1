/*
Exemplo0420 - v0.0. - 01 / 09 / 2019
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
funcao para contar letras maiusculas e minusculas
return um arranjo de dois inteiros primeiro minusculas segundo maiusculas
parametro string
*/
ints conta_min_mai (chars string)
{
   //define dados
   ints contagem = IO_new_ints (2);
   int tamanho = 0;
   int c_minusculas = 0;
   int c_maiusculas = 0;
     
   //aferir tamanho string
   tamanho = strlen(string);
   
   //conferir cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      //conferir minusculas
      if (('a' <= string [x]) && (string [x] <= 'z'))
      {
         c_minusculas = c_minusculas + 1;
      }//fim se
      
      // conferir maiusculas
      if (isuppercase (string [x]))
      {
         c_maiusculas = c_maiusculas + 1;
      }// fim se
   }//fim for
   
   //preencher arranjo de ints
   contagem [0] = c_minusculas;
   contagem [1] = c_maiusculas;
   
   //retornar arranjo
   return (contagem);
}
//fim conta_min_mai

/**
Definir uma struct que armazene duas strings
*/

typedef struct
{
   char minusculas [STR_SIZE];
   char maiusculas [STR_SIZE];
}letras;//fim struct

/**
Funcao para separar minusculas e maiusculas de uma string em 
uma estrutura de 2 strings a primeira minusculas e a segunda maiuscula
return estrutura de 2 strings primeira minusculas e segunda maiusculas
parametros string
*/

letras sep_min_mai (chars string)
{
   //define dados
   letras letras;
   int c_maiusculas = 0;
   int c_minusculas = 0;
   int tamanho = 0;
   
   //verifica tamanho string
   tamanho = strlen (string);
   
   //confere cada caractere
   for (int x =0; x < tamanho; x = x + 1)
   {
      //verifica se e'minusculas
      if (('a'<=string[x]) && (string[x]<='z'))
      {
         //armazenar minuscula
         letras.minusculas [c_minusculas] = string [x];
         
         //fechar string
         letras.minusculas [c_minusculas + 1] = EOS;
         
         //aumentar contador
         c_minusculas = c_minusculas + 1;
      }//fim se
      
      //verifica se e' maiuscula
      if (isuppercase (string [x]))
      {
         //armazenar maiuscula
         letras.maiusculas [c_maiusculas] = string [x];
         
         //fechar string
         letras.maiusculas [c_maiusculas + 1] = EOS;
         
         //aumentar contador 
         c_maiusculas = c_maiusculas + 1;
      }//fim se
   }//fim for
   
   //retornar string de maiusculas
   return (letras);
}
//fim sep_min_mai

/**
Funcao para testar digitos pares de uma cadeia de caracteres
return verdadeiro se digito par, falso se digito impar ou nao digito
parametro um caractere 
*/

bool digitopar (char x)
{
   //testar se e' digito
   if (('0' <= x) && (x <= '9'))
   {
      //retorna verdadeiro se par
      return ((int)x % 2 == 0);

   }// fim se
   
   //retorna falso
   return (false);
}// fim digitopar

/**
Funcao para contar todos simbolos alfanumericos (letras e digitos)
em uma cadeia de caracteres
return int - numero de simbolos alfanumericos
parametros string
*/

int qnts_alfanum (chars string)
{
   //define dados
   int tamanho = 0;
   int contador = 0;
   
   //verifica tamanho string
   tamanho = strlen (string);
   
   //verifica cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      //verifica se caractere e' letra ou digito
      if ((('0' <= string [x]) && (string [x] <= '9')) || 
          (('a' <= string [x]) && (string [x] <= 'z')) ||
          (('A' <= string [x]) && (string [x] <= 'Z')))
      {
         //aumentar contador
         contador = contador + 1;
      }//fim se    
   }//fim for
   
   //retorna contador
   return (contador);
}//qnts_alfanum

/**
Funcao para separa todos simbolos alfanumericos (letras e digitos)
em uma nova cadeia de caracteres
return char de simbolos alfanumericos
parametros string
*/

chars sep_alfanum (chars string)
{
   //define dados
   int contador = 0;
   int tamanho = 0;
   chars alfanum = IO_new_chars (STR_SIZE);
   
   //verifica tamanho string
   tamanho = strlen (string);
   
   //verifica cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      //verifica se caractere e' letra ou digito
      if ((('0' <= string [x]) && (string [x] <= '9')) || 
          (('a' <= string [x]) && (string [x] <= 'z')) ||
          (('A' <= string [x]) && (string [x] <= 'Z')))
      {
         //acrescenter caractere em alfanum
         alfanum [contador] = string [x];

         //fechar string
         alfanum [contador+1] = EOS;
         
         //aumentar contador
         contador = contador + 1;
      }//fim se 
   }//fim for
   
   //retorna contador
   return (alfanum);
}//sep_alfanum

/**
Funcao para contar todos simbolos alfanumericos (letras e digitos)
em varias cadeias de caracteres
return int - numero de simbolos alfanumericos
parametros string e ponteiro de int para conta total
*/

int total_alfanum (chars string, int* total)
{
   //define dados
   int tamanho = 0;
   int contador = 0;
   
   //verifica tamanho string
   tamanho = strlen (string);
   
   //verifica cada caractere
   for (int x = 0; x < tamanho; x = x + 1)
   {
      //verifica se caractere e' letra ou digito
      if ((('0' <= string [x]) && (string [x] <= '9')) || 
          (('a' <= string [x]) && (string [x] <= 'z')) ||
          (('A' <= string [x]) && (string [x] <= 'Z')))
      {
         //aumentar contador
         contador = contador + 1;
      }//fim se    
   }//fim for
   
   //altera valor total
   *total = *total + contador;
   
   //retorna contador
   return (contador);
}//total_alfanum


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
   IO_id ( "EXEMPLO0420 - Method01 - v0.0" );

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
   IO_id ( "EXEMPLO0420 - Method02 - v0.0" );
   
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
   IO_id ( "EXEMPLO0420 - Method03 - v0.0" );
   
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
   IO_id ( "EXEMPLO0420 - Method04 - v0.0" );
   
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
Method05 - Ler sequencia de caracteres e contar minusculas e maiusculas
atraves de uma funcao definida para receber uma cadeia de caracteres
como parametro.
*/
void method05 ( )
{
   // define dados
   chars sequencia = IO_new_chars (STR_SIZE);
   ints contagem = IO_new_ints (2);
   
   // identificar
   IO_id ( "EXEMPLO0420 - Method05 - v0.0" );
   
   // ler sequencia
   sequencia = IO_readstring ("Entrar com uma sequencia de caracteres: ");
   contagem = conta_min_mai (sequencia);
   
   // mostrar quantidade de minusculas e maiusculas
   printf ("\n%s(%d)\n%s(%d)\n", "Quantidade de minusculas: ", contagem [0],
                                 "Quantidade de maiusculas: ", contagem [1]); 

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
Method06.
*/
void method06 ( )
{
   // definir dados
   chars sequencia = IO_new_chars (STR_SIZE);
   letras letras;
   
   // identificar
   IO_id ( "EXEMPLO0420 - Method06 - v0.0" );
   
   // ler teclado
   sequencia = IO_readstring ("Entrar com sequencia de caracteres: "); 
   
   // passar sequencia pela funcao
   letras = sep_min_mai (sequencia);
   
   printf ("\n%s[%s]\n%s[%s]\n", "Letras minusculas: ", letras.minusculas,
                                 "Letras maiusculas: ", letras.maiusculas);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
Method07.
*/
void method07 ( )
{
   // definir dados
   chars sequencia = IO_new_chars (STR_SIZE);
   int contador = 0;
   int tamanho = 0;
   
   // identificar
   IO_id ( "EXEMPLO0420 - Method07 - v0.0" );

   // ler teclado
   sequencia = IO_readstring ("Entrar com sequencia de caracteres: ");

   // verificar tamanho da sequencia
   tamanho = strlen (sequencia);
   
   // conferir cada caractere da sequencia
   for (int x = 0; x < tamanho; x = x + 1)
   {
      // testar se caractere corresponde a digito par
      if (digitopar (sequencia[x]))
      {
         contador = contador + 1;
         printf ("%d: %c\n", contador, sequencia[x]);
      }//fim se
   }//fim for

   //mostrar total de digitos
   printf ("%s%d\n", "Total de digitos: ", contador);

   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
Method08.
*/
void method08 ( )
{
   //define dados
   chars sequencia = IO_new_chars (STR_SIZE);
   int quantidade = 0;
   
   // identificar
   IO_id ( "EXEMPLO0420 - Method08 - v0.0" );
   
   //ler teclado
   sequencia = IO_readstring ("Entra com sequencia caracteres: ");
   
   //contar simbolos alfanumericos
   quantidade = qnts_alfanum (sequencia);

   //mostra quantidade
   printf ("\n%s%d\n", "Quantidade de simbolos alfanumericos: ", quantidade);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
Method09.
*/
void method09 ( )
{
   //define dados
   chars sequencia = IO_new_chars (STR_SIZE);
   chars alfanum = NULL;
   
   // identificar
   IO_id ( "EXEMPLO0420 - Method09 - v0.0" );
   
   //ler teclado
   sequencia = IO_readstring ("Entra com sequencia caracteres: ");
   
   //contar simbolos alfanumericos
   alfanum = sep_alfanum (sequencia);

   //mostra quantidade
   printf ("\n%s[%s]\n", "Simbolos alfanumericos: ", alfanum);
   
   // encerrar
   IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
Method10.
*/
void method10 ( )
{
   //define dados
   int quantidade = 0;
   int cada = 0;
   int total = 0;
   
   // identificar
   IO_id ( "EXEMPLO0420 - Method10 - v0.0" );
   
   //ler quantidade do teclado
   quantidade = IO_readint ("Entrar com quantidade de cadeias de caracteres: ");
   
   //criar um arranjo para armazenar todas as cadeias de caracteres
   char cadeias [quantidade][STR_SIZE];
   
   //ler quantas forem as cadeias de caracteres
   for (int x = 0; x < quantidade; x = x + 1)
   {
      // mostrar na tela 
      printf ("%s", "Entrar com sequencia caracteres: ");
      
      //ler cadeia do teclado
      scanf ("%s", cadeias[x]);
   }//fim for
   
   //passar cada cadeia pela funcao
   for (int x = 0; x < quantidade; x = x + 1)
   {
      //contar simbolos alfanumericos em cada cadeia
      cada = total_alfanum (cadeias[x], &total);
      
      //mostra quantidade de simbolos alfanumericos em cada palavra
      printf ("%s%d%s%d\n", "Quantidade de simbolos alfanumericos na "
               , (x+1),"a palavra: ", cada);
   }   
   
   //mostrar total de simbolos alfanumericos em cada palavra
   printf ("\n%s%d", "Total de simbolos alfanumericos em todas palavras: ", total);

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
      IO_id ( "EXEMPLO0420 - Programa - v0.0" );

      // ler do teclado
      IO_println ( "Opcoes" );
      IO_println ( " 0 - parar" );
      IO_println ( " 1 - ler intervalo fechado e verificar quantidade dentro e fora" );
      IO_println ( " 2 - ler caracteres, contar e mostrar maiusculas" );
      IO_println ( " 3 - ler caracteres, contar maiusculas com funcao (string)" );
      IO_println ( " 4 - ler caracteres, separar maiusculas com funcao (string)" );
      IO_println ( " 5 - ler caracteres, contar minusculas e maiusculas com funcao (string)" );
      IO_println ( " 6 - ler caracteres, separar minusculas e maiusculas com funcao (string)" );
      IO_println ( " 7 - ler caracteres, contar e mostrar digitos pares em cadeia com funcao (string)" );
      IO_println ( " 8 - ler caracteres, contar simbolos alfanumericos em uma cadeia de caracteres" );
      IO_println ( " 9 - ler caracteres, separar simbolos alfanumericos em cadeia de caracteres por funcao" );
      IO_println ( "10 - ler quantidade de caracteres, contar simbolos alfanumericos, calcular total de simbolos por funcao" );
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
g.) PALAVRA, Palavra, palavra, %ˆ66fghBN
h.) PALAVRA, Palavra, palavra, %ˆ66fghBN
i.) 246, 135, a2b3, azZA12#$56
j.) azAZ10, Az1#$, #$%ˆˆ
k.) azAZ10, Az1#$, #$%ˆˆ
l.) 3 e azAZ10, Az1#$, #$%ˆˆ


---------------------------------------------- historico
Versao      Data     Modificacao
0.1         31/08   esboco

---------------------------------------------- testes
Versao      Teste
0.1         01. ( OK ) identificacao de programa
*/