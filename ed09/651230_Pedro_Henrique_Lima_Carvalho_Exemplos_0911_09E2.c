/*
PUC - Minas
Ciencia da Computacao
AED 1
Estudo Dirigido 09
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//definicoes
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faza nada
}//fim method00 ()

/**
read_matrix - Le do teclado as dimensoes e elementos de uma matriz real
@param numero de linhas, numero de colunas, matriz
*/
void read_matrix (int lines, int columns, double matrix [ ] [columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //repetir linhas
        for (int x=0; x<lines; x++)
        {
            //repetir colunas
            for (int y=0; y<columns; y++)
            {
                //ler teclado
                printf ("\n%s[%d][%d]: ", "Entre com o valor real para a posicao ", x, y);
                scanf ("%lf", &matrix[x][y]);
            }//fim for
        }//fim for
    }//fim if
    else
    {
        printf ("%s\n", "Dimensoes invalidas");
    }//fim else
}//fim read_matrix()

/**
print_matrix - Mostra na tela uma matriz
@param numero de linhas, numero de colunas, matriz
*/
void print_matrix (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //saltar uma linha
        printf ("\n");

        //repetir linhas
        for (int x=0; x<lines; x++)
        {
            for (int y=0; y<columns; y++)
            {
                printf ("\t%lf", matrix [x][y]);
            }//fim for
            printf ("\n");
        }//fim for
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes invalidas");
    }//fim else 
}//fim print_matrix()

/**
Method01 - Le uma matriz real do teclado e mostra na tela
*/
void method01 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0911");

    //ler teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar matriz
        print_matrix (lines, columns, matriz);
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method01 ()

/**
fprint_matrix - Grava uma matriz em um arquivo
@param numero de linhas, numero de colunas, matriz
*/
void fprint_matrix (int lines, int columns, double matrix [][columns], char *file)
{
    //definir dados
    FILE *arquivo = fopen (file, "wt");

    //testar dados
    if (lines>0 && columns>0 
        && arquivo != NULL && file != NULL)
    {
        //escrever dimensoes da matriz em arquivo
        fprintf (arquivo, "%d\n", lines);
        fprintf (arquivo, "%d\n", columns);

        //escrever elementos da matriz
        for (int x=0; x<lines; x++)
        {
            for (int y=0; y<columns; y++)
            {
                fprintf (arquivo, "%lf\n", matrix[x][y]);
            }//fim for
        }//fim for
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes invalidas");
    }//fim else
    
    //encerrar
    fclose (arquivo);
}//fim fprint_matrix

/**
fread_dimensions - Le as dimensoes de uma matriz em um arquivo
@param ponteiro para o numero de linhas, ponteiro para numero de colunas, nome do arquivo
*/
void fread_dimensions (int *p_lines, int *p_columns, char* file)
{
    //definir dados
    FILE *arquivo = fopen (file, "rt");

    //testar inputs
    if (p_lines != NULL && p_columns != NULL 
        && file != NULL && arquivo != NULL)
    {
        //ler numero de linhas
        fscanf (arquivo, "%d", p_lines);

        //ler numero de colunas
        fscanf (arquivo, "%d", p_columns);
    }//fim if
    else
    {
        printf ("\n%s\n", "Erro: fread_dimensions()");
    }//fim else
    
    //encerrar
    fclose(arquivo);
}//fim fread_dimensions

/**
fread_matrix - Le uma matriz de uma arquivo
@param numero de linhas, de colunas, matriz e nome do arquivo
*/
void fread_matrix (int lines, int columns, double matrix [][columns], char *file)
{
    //definir dados
    int linha = 0;
    int coluna = 0;
    FILE *arquivo = fopen (file, "rt");

    //testar dados
    if (lines>0 && columns>0 
        && file != NULL && arquivo != NULL)
    {
        //ler dimensoes da matriz
        fscanf (arquivo, "%d", &linha);
        fscanf (arquivo, "%d", &coluna);

        //testar dimensoes
        if (lines == linha && columns == coluna)
        {
            //preencher matriz
            for (int x=0; x<lines && !feof(arquivo); x++)
            {
                for (int y=0; y<columns && !feof(arquivo); y++)
                {
                    fscanf (arquivo, "%lf", &matrix[x][y]);
                }//fim for
            }//fim for
        }//fim if
    }//fim if
    else
    {
        printf ("\n%s\n", "Erro: fread_matrix()");
    }//fim else
    
    //encerrar
    fclose (arquivo);
}//fim fread_matrix()

/**
Method02 - Grava uma matriz em um arquivo
*/
void method02 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0912");

    //ler do teclado dimensoes da matriz
    lines = IO_readint("Entre com o numero de linhas da sua matriz: ");
    columns = IO_readint("Entre com o numero de colunas da sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //gravar matriz em arquivo
        fprint_matrix (lines, columns, matriz, "matriz.txt");

        //ler dimensoes da matriz de arquivo
        fread_dimensions(&lines, &columns, "matriz.txt");

        //criar matriz_2
        double matriz_2 [lines] [columns];

        //ler matriz_2 de arquivo
        fread_matrix (lines, columns, matriz_2, "matriz.txt");

        //mostar matriz_2
        print_matrix (lines, columns, matriz_2); 
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");  
}//fim method02 ()

/**
print_diag_princ - Se matriz for quadrada, mostra a diagonal principal
@param numero de linhas, de colunas e matriz
*/

void print_diag_princ (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {
            //saltar uma linha
            printf ("\n");
            
            //mostrar diagonal principal
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    //testar se valor da diagonal principal
                    if (x==y)
                    {
                        printf ("\t%lf", matrix [x][y]);
                    }//fim if
                    else
                    {
                        printf ("\t%s", "        ");
                    }//fim if
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else
}//fim print_diag_princ

/**
Method03 - Mostra os valores da diagonal principal se a matriz for quadrada
*/
void method03 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0913");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar diagonal principal
        print_diag_princ (lines, columns, matriz);

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method03 ()

/**
print_diag_secund - Se matriz for quadrada, mostra a diagonal secundaria
@param numero de linhas, de colunas e matriz
*/

void print_diag_secund (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {
            //saltar uma linha
            printf ("\n");
            
            //mostrar diagonal secundaria
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    //testar se valor da diagonal secundaria
                    if (x+y == lines-1)
                    {
                        printf ("\t%lf", matrix [x][y]);
                    }//fim if
                    else
                    {
                        printf ("\t%s", "        ");
                    }//fim if
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else
}//fim print_diag_secund

/**
Method04 - Mostra os valores da diagonal secundaria se a matriz for quadrada
*/
void method04 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0914");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar diagonal secundaria
        print_diag_secund (lines, columns, matriz);

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method04 ()

/**
print_under_princ - Se matriz for quadrada, mostra valores abaixo da diagonal principal
@param numero de linhas, de colunas e matriz
*/

void print_under_princ (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {
            //saltar uma linha
            printf ("\n");
            
            //mostrar valores abaixo diagonal principal
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    //testar se valor abaixo diagonal principal
                    if (x>y)
                    {
                        printf ("\t%lf", matrix [x][y]);
                    }//fim if
                    else
                    {
                        printf ("\t%s", "        ");
                    }//fim if
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else
}//fim print_under_princ

/**
Method05 - Mostra os valores abaixo da diagonal principal
*/
void method05 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0915");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar valores abaixo diagonal principal
        print_under_princ (lines, columns, matriz);

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method05 ()

/**
print_above_princ - Se matriz for quadrada, mostra valores acima da diagonal principal
@param numero de linhas, de colunas e matriz
*/

void print_above_princ (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {
            //saltar uma linha
            printf ("\n");
            
            //mostrar valores acima diagonal principal
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    //testar se valor acima diagonal principal
                    if (x<y)
                    {
                        printf ("\t%lf", matrix [x][y]);
                    }//fim if
                    else
                    {
                        printf ("\t%s", "        ");
                    }//fim if
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else
}//fim print_above_princ

/**
Method06 - Mostra valores acima da diagonal principal
*/
void method06 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0916");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar valore acima diagonal principal
        print_above_princ (lines, columns, matriz);

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method06 ()

/**
print_under_secund - Mostra valores abaixo da diagonal secundaria
@param numero de linhas, de colunas e matriz
*/

void print_under_secund (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {
            //saltar uma linha
            printf ("\n");
            
            //mostrar valores abaixo da diagonal secundaria
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    //testar se valor abaixo da diagonal secundaria
                    if (x+y > lines-1)
                    {
                        printf ("\t%lf", matrix [x][y]);
                    }//fim if
                    else
                    {
                        printf ("\t%s", "        ");
                    }//fim if
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else
}//fim print_under_secund

/**
Method07 - Mostra valores abaixo da diagonal secundaria
*/
void method07 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0917");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar valore abaixo diagonal secundaria
        print_under_secund (lines, columns, matriz);

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method07 ()

/**
print_above_secund - Mostra valores acima da diagonal secundaria
@param numero de linhas, de colunas e matriz
*/

void print_above_secund (int lines, int columns, double matrix [][columns])
{
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {
            //saltar uma linha
            printf ("\n");
            
            //mostrar valores acima da diagonal secundaria
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    //testar se valor acima da diagonal secundaria
                    if (x+y < lines-1)
                    {
                        printf ("\t%lf", matrix [x][y]);
                    }//fim if
                    else
                    {
                        printf ("\t%s", "        ");
                    }//fim if
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else
}//fim print_above_secund

/**
Method08 - Mostra valores acima da diagonal secundaria
*/
void method08 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0918");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //mostrar valore acima diagonal secundaria
        print_above_secund (lines, columns, matriz);

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method08 ()

/**
test_null_under_princ - Se matriz for quadrada, testa se todos 
valores abaixo da diagonal principal sao nulos
@param numero de linhas, de colunas e matriz
@return true se todos nulos else false
*/

bool test_null_under_princ (int lines, int columns, double matrix [][columns])
{
    //definir dados
    int counter = 0;
    
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {            
            //testar valores abaixo diagonal principal
            for (int x=0; x<lines && counter==0; x++)
            {
                for (int y=0; y<columns && counter==0; y++)
                {
                    //testar se valor abaixo diagonal principal
                    if (x>y)
                    {
                        //testar se valor nulo
                        if (matrix[x][y] != 0)
                        {
                            counter = 1;
                        }//fim if
                    }//fim if
                }//fim for
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    return (counter == 0);
}//fim print_under_princ

/**
Method09 - Testar se valores abaixo da diagonal principal nao sao todos nulos
*/
void method09 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0919");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0 && lines==columns)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //testa se sao todos nulos os valoes abaixo da diagonal principal
        if (test_null_under_princ (lines, columns, matriz))
        {
            printf ("\n%s\n", "Todos valores abaixo da diagonal principal sao nulos");
        }//fim if
        else
        {
            printf ("\n%s\n", "Valores abaixo da diagonal principal nao sao todos nulos");
        }//fim else

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method09 ()

/**
test_null_above_princ - Se matriz for quadrada, testa se todos 
valores acima da diagonal principal sao nulos
@param numero de linhas, de colunas e matriz
@return true se todos nulos else false
*/

bool test_null_above_princ (int lines, int columns, double matrix [][columns])
{
    //definir dados
    int counter = 0;
    
    //testar inputs
    if (lines>0 && columns>0)
    {
        //testar se matriz e' quadrada
        if ( lines == columns)
        {   
            //testar valores acima diagonal principal
            for (int x=0; x<lines && counter==0; x++)
            {
                for (int y=0; y<columns && counter==0; y++)
                {
                    //testar se valor acima diagonal principal
                    if (x<y)
                    {
                        //testar se valor nulo
                        if (matrix[x][y] != 0)
                        {
                            counter = 1;
                        }//fim if
                    }//fim if
                }//fim for
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else
    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    return (counter == 0);
}//fim print_above_princ

/**
Method10 - Testa se sao nulos os valores acima da diagonal principal
*/
void method10 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 0920");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0 && lines==columns)
    {
        //criar matriz
        double matriz [lines][columns];

        //preencher matriz
        read_matrix (lines, columns, matriz);

        //testa se sao todos nulos os valoes acima da diagonal principal
        if (test_null_above_princ (lines, columns, matriz))
        {
            printf ("\n%s\n", "Todos valores acima da diagonal principal sao nulos");
        }//fim if
        else
        {
            printf ("\n%s\n", "Valores acima da diagonal principal nao sao todos nulos");
        }//fim else

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method10 ()

/**
Method11 - Mostra uma matriz com valores decrescentes na horizontal
*/
void method11 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 09E1");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        int matriz [lines][columns];

        // testa se matriz e' quadrada
        if (lines == columns)
        {
            //preenche matriz
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    matriz[x][y] = ((lines * columns) - (lines*x + y));
                }//fim for
            }//fim for

            //mostrar matriz
            //saltar uma linha
            printf ("\n");

            //repetir linhas
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    printf ("\t%d", matriz [x][y]);
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method11 ()

/**
Method12 - Mostrar uma matriz com valores decrescentes na vertical
*/
void method12 ()
{
    //definir dados
    int lines = 0;
    int columns = 0;

    //identificar
    IO_id ("ED09 - Exemplo 09E2");

    //ler do teclado dimensoes da matriz
    lines = IO_readint ("Entre com o numero de linhas de sua matriz: ");
    columns = IO_readint ("Entre com o numero de colunas de sua matriz: ");

    //testar inputs
    if (lines>0 && columns>0)
    {
        //criar matriz
        int matriz [lines][columns];

        // testa se matriz e' quadrada
        if (lines == columns)
        {
            //preenche matriz
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    matriz[x][y] = ((lines * columns) - (x + columns*y));
                }//fim for
            }//fim for

            //mostrar matriz
            //saltar uma linha
            printf ("\n");

            //repetir linhas
            for (int x=0; x<lines; x++)
            {
                for (int y=0; y<columns; y++)
                {
                    printf ("\t%d", matriz [x][y]);
                }//fim for
                printf ("\n");
            }//fim for
        }//fim if
        else
        {
            printf ("\n%s\n", "Matriz nao e' quadrada");
        }//fim else

    }//fim if
    else
    {
        printf ("\n%s\n", "Dimensoes Invalidas");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method12 ()

/**
Funcao Principal - Apresenta menu de escolhas de metodos
*/

int main ()
{
    //definir dados
    int x = 0;

    //apresentar menu
    do
    {
        //identidicar
        printf ("\n");
        IO_id ("ED09 - Exemplos 0911 - 09E2");

        //opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Sair");
        IO_println ("1- Le uma matriz real do teclado.");
        IO_println ("2- Grava uma matriz em arquivo");
        IO_println ("3- Mostra somente os valores da diagonal principal de uma matriz");
        IO_println ("4- Mostra somente os valores da diagonal secundaria de uma matriz");
        IO_println ("5- Mostra valores abaixo da diagonal principal");
        IO_println ("6- Mostra valores acima da diagonal principal");
        IO_println ("7- Mostra valores abaixo da diagonal secundaria");
        IO_println ("8- Mostra valores acima da diagonal secundaria");
        IO_println ("9- Testar se todos valores abaixo da diagonal principal nao sao nulos");
        IO_println ("10- Testar se todos valores acima da diagonal principal sao nulos");
        IO_println ("11- Monta matriz com numeros decrescentes na horizontal");
        IO_println ("12- Monta matriz com numeros decrescentes na vertical");

        //ler teclado
        x = IO_readint ("Escolha uma das opcoes:");

        //chamar metodo de acordo com opcao
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
            method04 ();
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

            case 11:
            method11 ();
            break;

            case 12:
            method12 ();
            break;

            default:
            IO_pause ("Numero Invalido");
        }
                
    } while (x!=0); //fim while
    
    //encerrar
    IO_pause ("Aperte ENTER para terminar");

    //retorno
    return (0);

}//fim main

/*
------------------------------------Comentarios
Main:   
    v1- Funcionou como esperado;

method01:
    v1- Funcionou como esperado;

method02:
    v1- Funcionou como esperado;

method03:
    v1- Funcionou como esperado;

method04:
    v1- Funcionou como esperado;

method05:
    v1- Funcionou como esperado;

method06:
    v1- Funcionou como esperado;

method07:
    v1- Funcionou como esperado;

method08:
    v1- Funcionou como esperado;

method09:
    v1- Funcinou como esperado;

method10:
    v1- Funcionou como esperado;

method11:
    v1- subtraindo 1 a mais na ultima linha;
        subtraindo (3*x + y), substituido por (lines*x + y);
    v2- Funcionou como esperado;

method12:
    v1- Funcinou como esperado;

------------------------------------Testes
method01:   3 3; 2.1 2.4 44.5 4445.6 0.4 23.3 234.9 4.0 0.3
            0 1; 1 0; -1 -2;

method02:   2 3; 0.1 0.2 0.3 1.1 1.2 1.3
            0 1; 1 0; -1 -2;

method03:   3 3; 1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3
            2 3; 1.1 1.1 1.2 2.2 2.2 3.3

method04:   3 3; 1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3
            2 3; 1.1 1.1 1.2 2.2 2.2 3.3

method05:   3 3; 1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3
            2 3; 1.1 1.1 1.2 2.2 2.2 3.3

method06:   3 3; 1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3
            2 3; 1.1 1.1 1.2 2.2 2.2 3.3

method07:   3 3; 1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3
            2 3; 1.1 1.1 1.2 2.2 2.2 3.3

method08:   3 3; 1.1 1.2 1.3 2.1 2.2 2.3 3.1 3.2 3.3
            2 3; 1.1 1.1 1.2 2.2 2.2 3.3

method09:   3 3; 1.1 1.2 1.3. 0 2.2 2.3 0 0 3.3
            3 3; 1.1 0 0 2.1 2.2 0 3.1 3.2 3.3

method10:   3 3; 1.1 1.2 1.3. 0 2.2 2.3 0 0 3.3
            3 3; 1.1 0 0 2.1 2.2 0 3.1 3.2 3.3

method11:   2 2; 3 3; 4 4; 1 2;

method12:   2 2; 3 3; 4 4; 1 2;

*/
