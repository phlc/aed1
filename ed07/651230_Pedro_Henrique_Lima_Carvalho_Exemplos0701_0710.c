/*
PUC-Minas - Ciencia da Computacao
AED1
Turno: Tarde
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
Estudo Dirigido 07
*/

//dependencias
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faz nada
}//method00

/**
writeInts - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void writeInts ( chars fileName, int x )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "wt" );
    int y = 0;

    // repetir para a quantidade de dados
    for ( y = 1; y <= x; y = y + 1 )
    {
        // gravar valor
        fprintf ( arquivo, "%d\n", y );
    } // fim repetir
    
    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose ( arquivo );
} // fim writeInts ( )

/**
Method01 - Mostrar certa quantidade de valores.
*/
void method01 ( )
{
    // identificar
    IO_id ( "EXEMPLO0701 - Method01 - v0.0" );
    // executar o metodo auxiliar
    writeInts ( "DADOS1.TXT", 10 );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method01 ( )

/**
readInts - Ler de arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void readInts ( chars fileName )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "rt" );
    int x = 0;

    // tentar ler o primeiro
    fscanf ( arquivo, "%d", &x );

    // repetir enquanto houver dados
    while ( ! feof ( arquivo ) )
    {
        // mostrar valor
        printf ( "%d\n", x );

        // tentar ler o proximo
        fscanf ( arquivo, "%d", &x );
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose ( arquivo );
} // fim readInts ( )

/**
Method02.
*/
void method02 ( )
{
    // identificar
    IO_id ( "EXEMPLO0702 - Method02 - v0.0" );

    // executar o metodo auxiliar
    readInts ( "DADOS1.TXT" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method02 ( )

/**
writeDoubles - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void writeDoubles ( chars fileName, int x )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "wt" );
    int y = 0;

    // gravar quantidade de valores
    IO_fprintf ( arquivo, "%d\n", x );

    // repetir para a quantidade de dados
    for ( y = 1; y <= x; y = y + 1 )
    {
        // gravar valor
        IO_fprintf ( arquivo, "%lf\n", (0.1*y) );
    } // fim repetir

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose ( arquivo );
} // fim writeDoubles ( )

/**
Method03.
*/
void method03 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method03 - v0.0" );

    // executar o metodo auxiliar
    writeDoubles ( "DADOS2.TXT", 10 );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method03 ( )

/**
readDoubles - Ler de arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void readDoubles ( chars fileName )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "rt" );
    int x = 0 ;
    int y = 1 ;
    double z = 0.0;

    // tentar ler a quantidade de dados
    fscanf ( arquivo, "%d", &x );

    // repetir enquanto houver dados e
    // quantidade nao tiver sido alcancada
    while ( ! feof ( arquivo ) && y <= x )
    {
        // tentar ler
        fscanf ( arquivo, "%lf", &z );
        
        // mostrar valor
        printf ( "%2d: %lf\n", y, z );
        
        // passar ao proximo
        y = y + 1;
    } // fim repetir
    
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose ( arquivo );
} // fim readDoubles ( )

/**
Method04.
*/
void method04 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method04 - v0.0" );

    // executar o metodo auxiliar
    readDoubles ( "DADOS2.TXT" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method04 ( )

/**
writeText - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void writeText ( chars fileName )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "wt" );
    chars linha = IO_new_chars ( STR_SIZE );

    // repetir ate' desejar parar
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
    do
    {
        // ler do teclado
        strcpy ( linha, IO_readln ( "" ) );

        // gravar valor
        IO_fprintf ( arquivo, "%s\n", linha );
    }while ( strcmp ( "PARAR", linha ) != 0 );

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose ( arquivo );
} // fim writeText ( )

/**
Method05.
*/
void method05 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method05 - v0.0" );

    // executar o metodo auxiliar
    writeText ( "DADOS3.TXT" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method05 ( )

/**
readText - Ler de arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
*/
void readText ( chars fileName )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "rt" );
    chars linha = IO_new_chars ( STR_SIZE );

    // tentar ler o primeiro
    strcpy ( linha, IO_freadln ( arquivo ) );

    // repetir enquanto houver dados
    while ( ! feof (arquivo) && strcmp ( "PARAR", linha ) != 0 )
    {
        // mostrar valor
       printf ( "%s\n", linha );

      // tentar ler o proximo
        strcpy ( linha, IO_freadln ( arquivo ) );
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose ( arquivo );
} // fim readText ( )

/**
Method06.
*/
void method06 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method06 - v0.0" );

    // executar o metodo auxiliar
    readText ( "DADOS3.TXT" );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method06 ( )

/**
copyText - Copiar arquivo texto.
@param fileOut - nome do arquivo de saida (destino)
@param fileIn - nome do arquivo de entrada (origem )
*/
void copyText ( chars fileOut, chars fileIn )
{
    // definir dados
    FILE* saida = fopen ( fileOut, "wt" );
    FILE* entrada = fopen ( fileIn , "rt" );
    chars linha = IO_new_chars ( STR_SIZE );
    int contador = 0;

    // ler da origem
    strcpy ( linha, IO_freadln ( entrada ) );

    // repetir enquanto houver dados
    while ( ! feof ( entrada ) )
    {
        // contar linha lida
        contador = contador + 1;
        
        // gravar no destino,
        // EXCEPCIONALMENTE sem a ultima linha, nesse caso
        if ( strcmp ( "PARAR", linha ) != 0 )
        {
            IO_fprintln ( saida, linha );
        } // fim se
        
        // ler da origem
        strcpy ( linha, IO_freadln ( entrada ) );
    } // fim repetir

    // informar total de linhas copiadas
    IO_printf ( "Lines read = %d\n", contador );

    // fechar arquivos
    fclose ( saida );
    fclose ( entrada );
} // fim copyText ( )

/**
Method07.
*/
void method07 ( )
{
    // identificar
    IO_id ( "EXEMPLO0707 - Method07 - v0.0" );

    // executar o metodo auxiliar
    copyText ( "DADOS4.TXT", "DADOS3.TXT" );
    
    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method07 ( )

/**
appendText - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void appendText ( chars fileName )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "at" );
    chars linha = IO_new_chars ( STR_SIZE );

    // repetir ate' desejar parar
    IO_println ( "Gravar linhas (para terminar, entrar com \"PARAR\"):\n" );
    do
    {
        // ler do teclado
        strcpy ( linha, IO_readln ( "" ) );
        // gravar valor
        IO_fprintln ( arquivo, linha );
    }while ( strcmp ( "PARAR", linha ) != 0 );

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose ( arquivo );
    } // fim appendText ( )

/**
Method08.
*/

void method08 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method08 - v0.0" );

    // executar o metodo auxiliar
    appendText ( "DADOS4.TXT" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method08 ( )

/**
readWords - Ler palavras de arquivo.
@param fileName - nome do arquivo
*/
void readWords ( chars fileName )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "rt" );
    chars linha = IO_new_chars ( STR_SIZE );

    // tentar ler a primeira
    strcpy ( linha, IO_fread ( arquivo ) );
    
    // repetir enquanto houver dados
    while ( ! feof (arquivo) && strcmp ( "PARAR", linha ) != 0 )
    {
        // mostrar valor
        printf ( "%s\n", linha );

        // tentar ler o proximo
        strcpy ( linha, IO_fread ( arquivo ) );
    } // fim repetir

    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose ( arquivo );
} // fim readWords ( )

/**
Method09.
*/
void method09 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method09 - v0.0" );

    // executar o metodo auxiliar
    readWords ( "DADOS4.TXT" );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method09 ( )

/**
searchWord - Procurar palavra em arquivo.
@return true, se encontrar; false, caso contrario
@param fileName - nome do arquivo
@param word - palavra a procurar
*/
bool searchWord ( chars fileName, chars word )
{
    // definir dados
    FILE* arquivo = fopen ( fileName, "rt" );
    chars linha = IO_new_chars ( STR_SIZE );

    // tentar ler a primeira
    strcpy ( linha, IO_fread ( arquivo ) );

    // repetir enquanto houver dados
    while ( ! feof (arquivo) && strcmp ( word, linha ) != 0 )
    {
        // tentar ler o proximo
        strcpy ( linha, IO_fread ( arquivo ) );
    } // fim repetir
    
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose ( arquivo );

    // retornar resultado
    return ( strcmp ( word, linha ) == 0);
} // fim searchdWord ( )

/**
Method10.
*/
void method10 ( )
{
    // identificar
    IO_id ( "EXEMPLO0710 - Method10 - v0.0" );

    // procurar palavra
    IO_printf ( "Procurar (\"%s\") = %d\n", "pqr", searchWord ( "DADOS4.TXT", "pqr" ) );
    IO_printf ( "Procurar (\"%s\") = %d\n", "linha3", searchWord ( "DADOS4.TXT", "linha3" ) );

    // encerrar
    IO_pause ( "Apertar ENTER para continuar" );
} // fim method10 ( )

/**
Funcao Principal
*/
int main ()
{
    //definir dados
    int x = 0;

    //repetir ate desejar parar
    do
    {
        //identificar
        IO_id ("EXEMPLOS0701 - 0710");

        //mostrar opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Encerrar");
        IO_println ("1- Gravar em arquivo certa quantidade de valores (int)");
        IO_println ("2- Ler de arquivo certa quantidade de valores (int)");
        IO_println ("3- Gravar em arquivo certa quantidade de valores (double)");
        IO_println ("4- Ler de arquivo certa quantidade de valores (double)");
        IO_println ("5- Gravar em arquivo certa quantidade de valores (string)");
        IO_println ("6- Ler de arquivo certa quantidade de valores (string)");
        IO_println ("7- Copiar texto de um arquivo para outro");
        IO_println ("8- Continuar a gravar em arquivo certa quantidade de valores (string)");
        IO_println ("9- Ler palavras de um arquivo");
        IO_println ("10- Procurar palavra em arquivo");

        //ler teclado
        x=IO_readint ("Entrar com uma opcao:");

        switch (x)
        {
            case 0:
            method00 ();
            break;

            case 1:
            method01 ();
            break;

            case 2:
            method02 ();
            break;

            case 3:
            method03 ();
            break;

            case 4:
            method04();
            break;

            case 5:
            method05 ();
            break;

            case 6:
            method06 ();
            break;

            case 7:
            method07 ();
            break;

            case 8:
            method08 ();
            break;

            case 9:
            method09 ();
            break;

            case 10:
            method10 ();
            break;

            default:
            IO_pause ("Numero invalido");
        }//fim escolher
    } while (x!=0);
    
    //encerrar
    IO_pause ("Aperte ENTER para encerrar") ;
    return (0);  
}//fim main()

/*
------------------------ Observacoes
strcmp retorna 0 quando sao iguais
<1 quando primeira string menor q segunda 
>1 quando primeira string maior q segunda
Obs: maior ou menor nao em numero de caracteres
mas em ordem alfabetica ex: "az" menor que "za"
------------------------ Testes

------------------------ Resultados

*/