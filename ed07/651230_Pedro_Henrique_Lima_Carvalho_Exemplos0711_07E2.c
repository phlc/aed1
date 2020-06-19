/*
PUC - Minas
Ciencia da Computação
AED1 - Turno Tarde
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
Estudo Dirigido 07
Exemplos 0711 - 07E2
*/

//dependencias
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faz nada
}//fim method00 ()

/**
write5xodd - Grava em arquivo multiplos de 5 impares em ordem crescente
comecando em 5
@param nome do arquivo e quantidade
*/
void write5xodd (char *file, int n)
{
    //condicao 
    if (n>=1)
    {
        //chamar write5xodd recursivamente
        write5xodd (file, n-1);

        //abrir arquivo
        FILE *arquivo = fopen(file, "at");

        //gravar no arquivo
        fprintf (arquivo, "%d\n", n*10-5);

        //fechar arquivo
        fclose (arquivo);
    }
}//fim write5xodd()

/**
Method01 - Ler uma quantidade do teclado e chama write5xodd ()
*/
void method01 ()
{
    //definir dados
    int n = 0;
    
    //identificar
    IO_id ("Exemplo 0711 - Method01");

    //ler quantidade
    n = IO_readint ("Entrar com quantidade:");

    //apagar eventual conteudo do arquivo
    FILE *arquivo = fopen ("method01.txt", "w");
    fclose (arquivo);

    //chamar write5xodd
    write5xodd ("method01.txt", n);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method01()

/**
write5xeven - Grava em arquivo multiplos de 5 pares em ordem decrescente
encerrando em 5
@param nome do arquivo e quantidade
*/
void write5xeven (char *file, int n)
{
    //condicao 
    if (n>=1)
    {
        //abrir arquivo
        FILE *arquivo = fopen(file, "at");

        //gravar no arquivo
        fprintf (arquivo, "%d\n", n*10);

        //fechar arquivo
        fclose (arquivo);

        //chamar write5xeven recursivamente
        write5xeven (file, n-1);

    }
}//fim write5xeven()

/**
Method02 - Ler uma quantidade do teclado e chama write5xeven ()
*/
void method02 ()
{
    //definir dados
    int n = 0;
    
    //identificar
    IO_id ("Exemplo 0712 - Method02");

    //ler quantidade
    n = IO_readint ("Entrar com quantidade:");

    //apagar eventual conteudo do arquivo
    FILE *arquivo = fopen ("method02.txt", "w");
    fclose (arquivo);

    //chamar write5x
    write5xeven ("method02.txt", n);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method02()

/**
Power5 - Grava em arquivo quantidade de valores da sequencia
1 5 25 125 625...
@param nome do arquivo e quantidade
*/
void power5 (char *file, int n)
{
    //abrir arquivo
    FILE *arquivo = fopen (file, "wt");

    //repetir n vezes
    for (int x = 0; x < n; x++)
    {
        //gravar no arquivo
        fprintf (arquivo, "%d\n", (int)pow (5, x));
    }//fim for

    //fechar arquivo
    fclose (arquivo);
}//fim power5 ()

/**
Method03 - Ler teclado e chamar power5
*/
void method03 ()
{
    //definir dados
    int x = 0;

    //identificar
    IO_id ("Exemplo 0713 - Method03");

    //ler quantidade
    x = IO_readint ("Entrar com quantidade:");

    //chamar power5()
    power5 ("method03.txt", x);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method03()

/**
InvPower5 - Grava em arquivo quantidade de valores da sequencia
...1/625 1/125 1/25 1/5 1
@param nome do arquivo e quantidade
*/
void invpower5 (char *file, int n)
{
    //abrir arquivo
    FILE *arquivo = fopen (file, "wt");

    //repetir n vezes
    for (int x = n-1; x >= 0; x--)
    {
        //gravar no arquivo
        fprintf (arquivo, "%lf\n", 1/pow (5, x));
    }//fim for

    //fechar arquivo
    fclose (arquivo);
}//fim invpower5 ()

/**
Method04 - Ler teclado e chamar invpower5
*/
void method04 ()
{
    //definir dados
    int x = 0;

    //identificar
    IO_id ("Exemplo 0714 - Method04");

    //ler quantidade
    x = IO_readint ("Entrar com quantidade:");

    //chamar invpower5()
    invpower5 ("method04.txt", x);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method04()

/**
InvPowerOdd - Grava em arquivo quantidade em valores reais
da sequencia 1 1/x 1/x3 1/x5...
@param nome do arquivo, quantidade, valor real
*/

void invpowerodd (char *file, int n, double x)
{
    //definir dados
    int counter = 1;
    
    //abrir arquivo
    FILE *arquivo = fopen (file, "wt");

    //gravar no arquivo 1
    fprintf (arquivo, "%s\n", "1");

    //repetir n vezes
    while (counter < n)
    {
        //gravar no arquivo
        fprintf (arquivo, "%lf\n", 1.0/pow(x,(counter*2-1)));

        //aumentar contador
        counter= counter + 1;
    }//fim while

    //fechar arquivo
    fclose (arquivo);
}//fim invpowerodd

/**
Method05 - Ler quantidade, valor real e chamar invpowerodd
*/
void method05 ()
{
    //definir dados
    int n = 0;
    double x = 0.0;

    //identificar
    IO_id ("Exemplo0715 - Method05");
    
    //ler teclado
    n = IO_readint ("Entrar com quantidade:");
    x = IO_readdouble ("Entrar com valor real:");

    //chamar invpowerodd
    invpowerodd ("method05.txt", n, x);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method05 ()

/**
ReadSum - Ler uma quantidade de valores de um arquivo e 
soma-las
@param nome do arquivo e quantidade
@return soma
*/
double readsum (char *file, int n)
{
    //definir dados
    double buffer = 0.0;
    double sum = 0.0;
    int y = 1;
    
    //abrir arquivo
    FILE *arquivo = fopen (file, "r");

    //ler primeira vez
    fscanf (arquivo, "%lf", &buffer);
    sum = buffer;

    //repetir
    while (!feof(arquivo) && y<n)
    {
        //ler novamente
        fscanf (arquivo, "%lf", &buffer);

        //somar
        sum = sum + buffer;

        //atualizar contador
        y = y +1;

    }//fim while

    //fechar arquivo
    fclose (arquivo);

    //encerrar
    return (sum);
}//fim readsum ()

/**
Method06 - Ler quantidade, chamar readsum e gravar em 
arquivo quantidade e seu resultado 
*/
void method06 ()
{
    //definir dados
    int n = 0;
    double soma = 0.0;

    //identificar
    IO_id ("Exemplo 0716 - Method06");

    //ler teclado
    n = IO_readint ("Entre com quantidade:");

    //chamar readsum
    soma = readsum ("method05.txt", n);

    //abrir arquivo
    FILE *file = fopen ("method06.txt", "at");

    // gravar em arquivo
    fprintf (file, "Quantidade: %d\nSoma: %lf\n", n, soma);

    //fechar arquivo
    fclose (file);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method06 ()

/**
 Method07 - Ler quantidade, chamar readsum e gravar em
 arquivo quantidade e resultado
 */
void method07 ()
{
    //definir dados
    int n = 0;
    double soma = 0.0;

    //identificar
    IO_id ("Exemplo 0717 - Method07");

    //ler teclado
    n = IO_readint ("Entre com quantidade:");

    //chamar readsum
    soma = readsum ("method04.txt", n);

    //abrir arquivo
    FILE *file = fopen ("method07.txt", "at");

    //gravar em arquivo
    fprintf (file, "Quantidade: %d\nSoma: %lf\n", n, soma);

    //fechar arquivo
    fclose (file);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method07 ()
/**
Fibonacci - Calcula o n termo da sequencia fibonacci
@param numero do termo
@return termo fibonacci
*/
int fibonacci (int n)
{   
    //definir dados
    int termo = 0;

    //condicao base
    if (n < 3)
    {
        termo = 1;
    }
    //condicao motor
    else
    {
        termo = fibonacci (n-1) + fibonacci (n-2);
    }
    //retorna
    return (termo);
}//fim fibonacci()

/**
Fiboodd - Calcula e grava em arquivo os primeiros 
n termos impares da serie Fibonacci
@param nome do arquivo numero de termos
@return string com todos os termos
*/
int *fiboodd (char *file, int n)
{
    //definir dados
    int termo = 0;
    int *termos = malloc (sizeof(int)*STR_SIZE);
    int counter = 1;
    int counter2 = 1;

    //abrir arquivo
    FILE *arquivo = fopen(file, "wt");

    //repetir n vezez
    while (counter <= n)
    {
        //chamar fibonacci
        termo = fibonacci (counter2); 

        //verificar se impar
        if (termo % 2 != 0)
        {
            //gravar arquivo
            fprintf (arquivo, "%d\n", termo);

            //armazena termo em termos
            termos[counter-1] = termo;

            //atualizar contador
            counter = counter + 1;
        }//fim if
        //atualizar contador2
        counter2 = counter2 + 1;
    }//fim while

    //fechar arquivo
    fclose (arquivo);

    //retorna termos
    return (termos);
}
/**
Method08 - Ler quantidade, chamar fiboodd e gravar
em arquivo quandiade e resultado
*/
void method08 ()
{
    //definir dados
    int n = 0;
    int *fibo = NULL;

    //identificar
    IO_id ("Exemplo0718 - Method08");

    //ler teclado
    n = IO_readint ("Entrar com valor:");

    //chamar fiboodd
    fibo = fiboodd("fiboodd.txt", n);

    //abrir arquivo
    FILE *file = fopen("method08.txt", "at");

    //gravar no arquivo termos
    for (int x = 0; x < n; x++)
    {
        fprintf (file, "%d ",fibo[x]);
    }

    //gravar no arquivo quantidade
    fprintf (file, " Quantidade: %d\n", n);

    //encerramento
    free(fibo);
    fclose(file);
    IO_pause ("Aperte ENTER para continuar");
}//fim method08 ()

/**
CountLower - Calcula a quantidade de letras minusculas de uma c
adeia de caracteres lida de um arquivo e grava resultado outro arquivo
@param nome o arquivo
@return quantidade de cadeias lidas
*/
int countlower (char *file)
{
    //definir dados
    int quantidade = 0;
    int minusculas = 0;
    char *buffer = malloc (sizeof (char) * STR_SIZE+1);

    //abrir arquivo
    FILE *arquivo = fopen(file, "rt");

    //repetir ate fim arquivo
    while (!feof(arquivo))
    {
        //ler linha do arquivo
        fgets (buffer, STR_SIZE, arquivo);

        //contar minusculas
        for (int x = 0; x < strlen(buffer); x++ )
        {
            if ('a'<= buffer[x] && buffer[x]<='z')
            {
                minusculas = minusculas + 1;
            }//fim if
        }//fim for
        
        //verificar se leu linha vazia
        if (buffer[0] != '\0')
        {    
            //gravar resultado em arquivo
            FILE *resultado = fopen("method09.txt", "at");
            fprintf (resultado, "Cadeia: %sMinusculas: %d\n", buffer, minusculas);
            fclose (resultado);

            //contar cadeias lidas
            quantidade = quantidade + 1;
        }//fim if

        //zerar buffer
        buffer[0] = '\0';

        //zerar contador de minusculas
        minusculas = 0;
    }//fim while
    
    //encerrar
    fclose (arquivo);
    free(buffer);
    return (quantidade);
}//fim countlower

/**
Method09 - Chamar countlower()
*/
void method09 ()
{
    //definir dados
    int linhas = 0;
    
    //identificar
    IO_id ("Exemplo 0719 - Method09");

    //chamar countlower
    linhas = countlower("caracteres1.txt");

    //mostrar linhas lidas
    printf("%s%d\n", "Linhas lidas: ", linhas);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method09 ()

/**
CountDigit - Calcula a quantidade de digitos de uma cadeia 
de caracteres lida de um arquivo e grava resultado outro arquivo
@param nome o arquivo
@return quantidade de digitos lidos
*/
int countdigit (char *file)
{
    //definir dados
    int quantidade = 0;
    int digitos = 0;
    char *buffer = malloc (sizeof (char) * STR_SIZE+1);

    //abrir arquivo
    FILE *arquivo = fopen(file, "rt");

    //repetir ate fim arquivo
    while (!feof(arquivo))
    {
        //ler linha do arquivo
        fgets (buffer, STR_SIZE, arquivo);

        //contar minusculas
        for (int x = 0; x < strlen(buffer); x++ )
        {
            if ('0'<= buffer[x] && buffer[x]<='9')
            {
                digitos = digitos + 1;
            }//fim if
        }//fim for
        
        //verificar se leu linha vazia
        if (buffer[0] != '\0')
        {    
            //gravar resultado em arquivo
            FILE *resultado = fopen("method10.txt", "at");
            fprintf (resultado, "Cadeia: %sDigitos: %d\n", buffer, digitos);
            fclose (resultado);

            //contar cadeias lidas
            quantidade = quantidade + 1;
        }//fim if

        //zerar buffer
        buffer[0] = '\0';

        //zerar contador de minusculas
        digitos = 0;
    }//fim while
    
    //encerrar
    fclose (arquivo);
    free(buffer);
    return (quantidade);
}//fim countdigit

/**
 Method10 - Chamar countdigit()
 */
void method10 ()
{
    //definir dados
    int linhas = 0;

    //identificar
    IO_id ("Exemplo 0720 - Method10");

    //chamar countdigit()
    linhas = countdigit("caracteres1.txt");

    //mostrar linhas lidas
    printf("%s%d\n", "Linhas lidas: ", linhas);

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method10 ()

/**
 Method11 - Gravar em arquivo divisores de um inteiro
 */ 
void method11 ()
{
    //definir dados
    int inteiro = 0;
    
    //identificar
    IO_id ("Exemplo 07E1 - Method11");

    //ler teclado
    inteiro = IO_readint ("Entrar com valor inteiro:");

    //abrir arquivo
    FILE *arquivo = fopen("method11.txt", "wt");

    //gravar numero no arquivo
    fprintf (arquivo, "Divisores de %d:\n", inteiro);

    //verificar divisores
    for(int x = 1; x <= inteiro; x++)
    {
        //se divisor gravar em arquivo
        if (inteiro % x == 0)
        {
            fprintf (arquivo, "%d\n", x);
        }//fim if
    }//fim for

    //encerrar
    fclose(arquivo);
    IO_pause ("Aperte ENTER para continuar");
}//fim method11()

/**
 CountNotAs - Conta quantas palavras de um arquivo 
 nao comeca com a letra A ou a
 @param nome do arquivo
 @return numero de palavras
 */
int countnotas (char *file)
{
    //definir dados
    int quantidade = 0;
    char *buffer = malloc(sizeof(char)*STR_SIZE);

    //abrir arquivo
    FILE *arquivo = fopen(file, "rt");

    //repetir ate fim do arquivo
    while (!feof(arquivo))
    {
        //ler palavra
        fscanf (arquivo, "%s", buffer);

        //verificar primeira letra
        if (!(buffer[0] == 'a' || buffer[0] == 'A'))
        {
            quantidade = quantidade + 1;
        }//fim if
    }//fim while

    //encerrar
    fclose (arquivo);
    return (quantidade);
}

/**
 Method12 - Chamar countnotas
 */ 
void method12 ()
{
    //definir dados
    int quantidade = 0;
    
    //identificar
    IO_id ("Exemplo 07E2 - Method12");

    //chamar countnotas
    quantidade = countnotas ("palavras1.txt");

    //mostrar quantidade
    printf ("%d%s\n", quantidade, " palavras nao comecam com 'A' ou 'a'");

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method12()

/**
Funcao Principal - Apresenta opcoes chama metodos
*/
int main ()
{
    //define dados
    int x = 0;

    //repetir opcoes ate escolher sair
    do
    {
        //identificar
        IO_id ("Exemplos 0711 - 07E2");
        
        //mostrar opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Parar e sair");
        IO_println ("1- Gravar quantidade de multiplos de 5 impares crescente em arquivo");
        IO_println ("2- Gravar quantidade de multiplos de 5 pares decrescente em arquivo");
        IO_println ("3- Gravar quantidade de valores da sequencia 1 5 25 125 625...");
        IO_println ("4- Gravar quantidade de valores da sequencia ... 1/625 1/125 1/25 1/5 1");
        IO_println ("5- Gravar quantidade de valores da sequencia  1/x 1/x3 1/x5..");
        IO_println ("6- Ler quantidade, ler valores de method05.txt e soma-los");
        IO_println ("7- Ler quantidade, ler valores de method04.txt e soma-los");
        IO_println ("8- Ler quantidade, gravar primeiros termos impares fibonacci");
        IO_println ("9- Ler cadeia de caracteres, contar minusculas e gravar em arquivo");
        IO_println ("10- Ler cadeia de caracteres, contar digitos e gravar em arquivo");
        IO_println ("11- Ler inteiro e gravar em arquivo divisores em ordem crescente");
        IO_println ("12- Ler palavras de arquivo e contar quantas !a ou !A");
        
        //ler teclado
        x=IO_readint ("\nEntrar com uma opcao:");

        //chamar metodo correspondente
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
        
    } while (x!=0);

    //encerrar
    IO_pause ("Aperte ENTER para encerrar");
    return (0);
}//fim main ()

/*
--------------------------observacoes
As vezes o terminal ou o programa, nao sei, 
grava por conta propria um method04-2.txt ao 
inves de sobrescrever (abertura do arquivo em "wt")
Mas como method04.txt e' aberto, apaga todo seu conteudo
--------------------------testes
method01    1, 3, 5
method02    1, 3, 5
method03    0, 1, 4
method04    0, 1, 4
method05    2 e 1, 3 e 3, 4 e 2.1
method06    1, 2, 4
method07    1, 3, 5
method08    1, 3, 5
method09    caracteres1.txt
method10    caracteres1.txt
method11    2, 4, 23, 42
method12    palavra1.txt
--------------------------resultados
method01    OK
method02    OK
methdo03    OK
method04    OK
method05    OK
method06    OK
method07    OK
method08    OK
method09    OK
method10    OK
method11    OK
method12    OK
*/