/*
PUC - Minas
Ciencia da Computacao
AED 1
Refacao 01b
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//dependencias
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00 ()
{
    //nao faza nada
}//fim method00 ()

/**
Funcao 01a - Funcao Questao 1
@param inteiros x y
@return inteiro resultado
*/
int funcao01a (int x, int y)
{
    //definir dados
    int resultado = 0;

    if (y<0)
    {
        resultado = 10000 + funcao01a (x, -y);
    }//fim if
    else
    {
        if (y>0)
        {
            resultado = funcao01a(x+1, y/2)*10 + y%2;
        }//fim if
    }//fim else
    //encerrar
    return (resultado);
}//fim funcao01a

/**
Method01 - Questao 1
*/
void method01 ()
{
    //identificar
    IO_id ("Refacao 01b -  Questao 1");

    //mostrar resultado
    IO_printf ("f(x) = %d", funcao01a(0, 13));

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method01 ()

/**
funcao02 - Questao 2
@param cadeia de caracteres
@return verdadeiro ou falso
*/
bool funcao02(char* cadeia)
{
    //definir dados
    bool resultado = 0;

    //verificar cadeia
    if (cadeia == NULL)
    {
        printf ("%s\n", "Cadeia Inexistente");
    }//fim if
    else
    {
        //definir dados
        resultado = 1;
        int contador = 0;

        //repetir por toda cadeia
        while (cadeia[contador] != '\0' && resultado==1)
        {
            if (!(('0'<=cadeia[contador] && cadeia[contador]<='9') ||
                  ('a'<=cadeia[contador] && cadeia[contador]<='f') ||
                  ('A'<=cadeia[contador] && cadeia[contador]<='F')))
            {
                //altera resultado para falso
                resultado = 0;
            }//fim if
            //atualizar contador
            contador = contador + 1;
        }//fim while
    }//fim else
    
    //retorno
    return(resultado);
}//fim funcao02


/**
Method02 - Questao 2
*/
void method02 ()
{
    //identificar
    IO_id ("Refacao 01b -  Questao 2");

    //mostrar resultado 
    IO_printf ("resultado = %d\n", funcao02 ("1A2B")); //resultado = 1
    IO_printf ("resultado = %d\n", funcao02 ("1A2G")); //resultado = 0
    
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method02 ()

/**
tamanho - verifica o tamanho de um arquivo
@param nome do arquivo
@return tamanho do arquivo
*/
int tamanho (char* file)
{
    //definir dados
    int contador = 0;
    FILE* arquivo = fopen (file, "rt");

    //testar dados
    if (arquivo == NULL)
    {
        printf ("%s\n", "Erro ao abrir arquivo");
    }//fim if
    else
    {
        //definir dados
        double buffer = 0.0;

        //ler primeiro dado do arquivo
        fscanf (arquivo, "%lf", &buffer);

        //repetir ate fim do arquivo
        while (!feof(arquivo))
        {
            //atualizar contador
            contador = contador + 1;

            //ler de novo
            fscanf (arquivo, "%lf", &buffer);
        }//fim while
    }//fim else
    
    //encerrar
    fclose(arquivo);
    return (contador);
}//fim tamanho()

/**
funcao 03 - Questao 
@param nome do arquivo, tolerancia
@return numero de valores da segunda metade proximos ao primeiro valor 
*/
int funcao03 (char* file, double tol)
{
    //definir dados
    double n = 0.0;
    double buffer = 0.0;
    int resultado = 0;
    int size = 0;

    //verificar arquivo e tamanho
    size = tamanho(file);
    if (size < 1)
    {
        printf ("%s\n", "Erro tamanho arquivo");
    }//fim if
    else
    {
        //abrir arquivo (ja testado acima)
        FILE* arquivo = fopen (file, "rt");

        //ler primeiro numero
        fscanf (arquivo, "%lf", &n);

        //repetir na primeira metade
        for (int x = 1; x<size/2; x++)
        {
            //ler numero do arquivo
            fscanf (arquivo, "%lf", &buffer);
        }//fim for

        //repetir segunda metade do arquivo
        while (!feof(arquivo))
        {
            //ler numero do arquivo
            fscanf (arquivo, "%lf", &buffer);

            //testar se numero dentro do limite de tolerancia
            if (n-tol <= buffer && buffer <= n+tol)
            {
                resultado = resultado + 1;
            }//fim if
        }//fim while

        //fechar arquivo
        fclose(arquivo);

    }//fim else
    
    //encerrar
    return(resultado);
}//fim funcao3()

/**
Method03 - Questao 3
*/
void method03 ()
{
    //identificar
    IO_id ("Refacao 01b -  Questao 3");
    
    //mostrar resultado
    IO_printf ("resultado = %d\n", funcao03 ("DADOS.TXT", 0.001));

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method03 ()

/**
fmoda - funcao que verifica qual a moda de um arranjo
@param arranj0
@return moda
*/
int fmoda (int arr[])
{
    //definir dados
    int quant1 = 0;
    int quant2 = 0;
    int contador = 0;
    int moda = 0;
    int pos = 0;

    //atribuir a moda o 1 valor do arranjo
    moda = arr[0];

    //repetir ate fim do arranjo
    while (arr[contador] != 0)
    {
        //passar por todos elementos do arranjo novamente
        while (arr[pos] != 0)
        {
            //contar quantas vezes um numero repete
            if (arr[contador] == arr[pos])
            {
                quant2 = quant2 + 1;
            }//fim if

            //atualizar posicao
            pos = pos + 1;
        }//fim while

        //verificar se quantidade atual maior q anterior
        if (quant1 < quant2)
        {
            //atualizar quantidade e moda
            quant1 = quant2;
            moda = arr[contador];
        }//fim if
        if (quant1 == quant2) //empate
        {
            if (moda > arr[contador]) //criterio de desempate
            {
                //atualizar moda
                moda = arr[contador];
            }//fim if
        }//fim if

        //zerar quantidade e posicao
        quant2 = 0;
        pos = 0;
        
        //atualizar contador
        contador = contador + 1;
    }//fim while

    //retorno
    return (moda);
}//fim fmoda

/**
moda - copia para o primeiro arranjo todos valores diferentes da moda
@param arranjos
*/
void procedimento (int arr1[], int arr2[])
{
    //definir dados
    int moda = 0;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;

    //descobrir moda
    moda = fmoda(arr2);

    //passar por todos elementos arranho 2
    while (arr2[cont2] != 0)
    {
        //conferir se diferente de moda
        if (arr2[cont2] != moda)
        {
            //copiar valor para arranjo1
            arr1[cont1] = arr2[cont2];

            //atualizar contador
            cont1 = cont1 + 1;
        }//fim if

        //atualizar contador
        cont2 = cont2 + 1;
    }//fim while

    //fechar arranjo 1
    arr1[cont1] = moda * -1;

    //mostrar arranjo 1
    printf ("\n%s", "[");
    while (arr1[cont3] != (moda * -1))
    {
        printf (" %d", arr1[cont3]);

        //atualizar contador
        cont3 = cont3 + 1;
    }//fim while
    printf ("%s\n", "]");

}//fim procedimento

/**
Method04 - Questao 4
*/
void method04 ()
{
    //identificar
    IO_id ("Refacao 01b -  Questao 4");
    
    //definir dados
    int arr1[10];
    int arr2[] = { 1, 1, 1, 2, 2, 2, 3, 4, 5, 0};
    
    //chamar procedimento
    procedimento (arr1, arr2);
    
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
}//fim method04 ()


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
        IO_id ("Refacao 01b");

        //opcoes
        IO_println ("Opcoes:");
        IO_println ("0- Sair");
        IO_println ("1- Questao 1");
        IO_println ("2- Questao 2");
        IO_println ("3- Questao 3");
        IO_println ("4- Questao 4");
    

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
    v1- funcinou como esperado

method01:
    v1- funcionou como esperado

method02:
    v1- entrou em loop infinito. Faltou atualizar contador
    v2- funcionou como esperado

method03:
    v1- funcinou como esperda

method04:
    v1- funcinou como esperado


------------------------------------Testes
method01:   defaut

method02:   1A2B 1A2G

method03:   DADOS.TXT

method04:   1, 1, 1, 2, 2, 2, 3, 4, 5, 0

*/
