/*
PUC - Minas
Ciencia da Computacao
AED 1
ED08 - Exemplos 0811 - 08E2
Aluno: Pedro Henrique Lima Carvalho
Matricula: 651230
*/

//definicoes
#include "io.h"

/**
Method00 - Nao faz nada
*/
void method00()
{
    //nao faza nada
} //fim method00 ()

/**
Method01 - Le do teclado tamanho do arranjo
preenche o arranjo com valores pares positivos.
*/
void method01()
{
    //definir dados
    int n = 0;
    int inteiro = 0;
    int counter = 0;

    //identificar
    IO_id("ED08 - Exemplos 0811 - 08E2 - Metodo01");

    //ler teclado
    n = IO_readint("Entre com o tamanho do arranjo: ");

    //testar n
    if (n < 1)
    {
        printf("\n%s\n", "ERRO: Numero Invalido.");
    } //fim if
    else
    {
        //criar arranjo
        int array[n];

        //repetir ate arranjo todo preenchido
        while (counter < n)
        {
            //ler teclado
            inteiro = IO_readint("Entre com inteiro par positivo: ");

            //conferir input
            if (inteiro % 2 == 0 && inteiro > -1)
            {
                //preencher arranjo
                array[counter] = inteiro;

                //atualizar contador
                counter = counter + 1;
            } //fim if
            else
            {
                printf("%s\n", "Entre com valor par positivo");
            } //fim else
        }     //fim while
    }         //fim else

    //encerrar
    IO_pause("Aperte ENTER para Continuar");
} //fim method01 ()

/**
parespositivos - le um arquivo e escreve em
um arranjo  os numeros pares positivos
@param nome do arquivo e arranjo
Obs: O tamanho do arranjo constara na posicao 0.
*/
void parespositivos (char *file, int array[])
{
    //definir dados
    int valor = -1;
    int contador = 1;
    FILE *arquivo = fopen (file, "rt");

    //verificar arquivo
    if (arquivo != NULL)
    {   
        //conferir cada numero do arquivo
        while (!feof(arquivo))
        {
            //ler arquivo
            fscanf (arquivo, "%d", &valor);

            //conferir se par positivo
            if (valor>=0 && valor%2==0)
            {
                //guardar valor
                array[contador]=valor;

                //atualizar contador
                contador = contador + 1;
            }//fim if
        }//fim while
        
        //gravar tamanho do arranjo na posicao 0
        array[0] = contador;
    }//fim if
    
    //encerrar
    fclose (arquivo);
}//fim parespositivos

/**
Method02 - Le numeros de arquivo e separa pares positivos
*/
void method02()
{
    //definir dados
    int arranjo [80];
    FILE *arquivo = fopen ("parespositivos.txt", "wt");

    //identificar
    IO_id("ED08 - Exemplos 0811 - 08E2 - Metodo02");
    
    //ler arquivo e gravar arranjo
    parespositivos ("method02.txt", arranjo);

    //escrever arranjo em arquivo
    for (int x = 0; x < arranjo[0]; x++)
    {
        fprintf (arquivo, "%d\n", arranjo[x]);
    }//fim for

    //encerrar
    fclose (arquivo);
    IO_pause ("Aperte ENTER para continuar");
} //fim method02 ()

/**
randomint - gera um numero aleatorio inteiro dentro
de parametros
@param parametros inferior e superior
@return numero aleatorio
*/
int randomint (int inferior, int superior)
{
    //definir dados
    int resposta = 0;

    //gerar numero aleatorio dentro dos limites
    resposta = inferior + 1 + rand()%(superior - inferior - 1);

    //retorno
    return (resposta);
}//randomint ()

/**
f_escreverarranjo - Escreve em arquivo tamanho e elementos
de uma arranjo
@param nome do arquivo, tamanho e elementos
*/
void f_escreverarranjo (char *file, int n, int array[])
{
    //definir dados
    FILE *arquivo = fopen (file, "wt");    
        
    //gravar dados em arquivo
    fprintf (arquivo, "%d\n", n);
    for (int x=0; x<n; x++)
    {
        fprintf (arquivo, "%d\n", array[x]);
    }//fim for

    //encerrar
    fclose (arquivo);
}//fim f_escreverarranjo

/**
Method03 - Grava em um arquivo arranjo com elementos
gerados aleatoriamente
*/
void method03()
{
    //definir dados
    int inferior = 0;
    int superior = 0;
    int n = 0;

    //identificar
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo03");

    //ler teclado
    inferior = IO_readint ("Entrar com valor inferior do intervalo: ");
    superior = IO_readint ("Entrar com valor superior do intervalo: ");
    n = IO_readint ("Entrar com numero de elementos: ");

    //verificar inputs
    if ( n<1 || superior<=inferior)
    {
        printf("\n%s\n", "ERRO: Numero Invalido.");
    }//fim if
    else
    {
        //criar arranjo
        int array [n];

        srand(time(NULL));
        //armazenar elemenos no arranjo
        for (int x=0; x<n; x++)
        {
            array[x]=randomint (inferior, superior);
        }//fim if

        //escrever arquivo
        f_escreverarranjo("dados.txt", n, array);
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method03 ()

/**
f_lertamanho - Le o tamanho do arranjo de um arquivo
@param nome arquivo
@return tamanho do arranjo
*/
int f_lertamanho (char *file)
{
    //definir dados
    int tamanho = 0;
    FILE *arquivo = fopen (file, "rt");

    //verificar
    if (arquivo != NULL)
    {
        //ler tamanho
        fscanf (arquivo, "%d", &tamanho);
    }//fim if
    
    //retorno
    fclose(arquivo);
    return (tamanho);
}//fim f_lertamanho()

/**
 f_lerarranjo - Le um arranjo gravado em um arquivo
 @param arranjo destido da leitura, tamanho arranjo, arquivo fonte
*/
void f_lerarranjo (int array[], int n, char *file)
{
    //definir dados
    int termo = 0;
    FILE *arquivo = fopen (file, "rt");
    int lido = 0;
    int counter = 0;

    //ler tamanho
    fscanf (arquivo, "%d", &lido);

    //verificar tamanho
    if (n<1 || n!=lido)
    {
        printf ("%s\n", "ERRO: tamanho arranjo inconsistente");
    }//fim if
    else
    {
        //preencher arranjo
        while (!feof(arquivo) && counter<n)
        {
            //ler valor
            fscanf (arquivo, "%d", &lido);

            //gravar
            array[counter] = lido;

            //atualizar contador
            counter = counter + 1;
        }
    }//fim else
    //encerrar
    fclose (arquivo);
}//fim f_lerarranjo

/**
 maiorvalor - Verifica o maior elemento dentro de um arranjo
 @param arranjo e tamanho do arranjo
 @return maior elemento do arranjo
 */
int maiorvalor (int array[], int n)
{
    //definir dados
    int maior = 0;

    //estabelecer parametro
    maior = array[0];

    for (int x=1; x<n; x++)
    {
        if (array[x]>maior)
        {
            maior = array[x];
        }//fim if
    }//fim for

    //retorno
    return (maior);
}//fim maiorvalor ()

/**
Method04 - Le arranjo de arquivo e verifica maior elemento
*/
void method04()
{
    //definir dados
    int maior = 0;
    int n = 0;
 
    //identificar 
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo04");
    
    //verificar tamanho do arranjo
    n = f_lertamanho ("dados.txt");

    if (n<1)
    {
        printf("\n%s\n", "ERRO: Tamanho Invalido.");
    }//fim if
    else
    {
        //criar arranjo
        int array[n];

        //preencher arranjo
        f_lerarranjo (array, n, "dados.txt");

        //verificar o maior
        maior = maiorvalor (array, n);

        //mostrar o maior 
        printf("%s%d\n", "Maior valor: ", maior);
    }//fim else
    
    //encerrar
    IO_pause ("Aperte ENTER para terminar");
} //fim method04 ()

/**
 menorvalor - Verifica o menor elemento dentro de um arranjo
 @param arranjo e tamanho do arranjo
 @return maior elemento do arranjo
 */
int menorvalor (int array[], int n)
{
    //definir dados
    int menor = 0;

    //estabelecer parametro
    menor = array[0];

    for (int x=1; x<n; x++)
    {
        if (array[x]<menor)
        {
            menor = array[x];
        }//fim if
    }//fim for

    //retorno
    return (menor);
}//fim menorvalor ()

/**
Method05 - Le arranjo de arquivo e verifica menor elemento
*/
void method05()
{
    //definir dados
    int menor = 0;
    int n = 0;
 
    //identificar 
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo05");
    
    //verificar tamanho do arranjo
    n = f_lertamanho ("dados.txt");

    if (n<1)
    {
        printf("\n%s\n", "ERRO: Tamanho Invalido.");
    }//fim if
    else
    {
        //criar arranjo
        int array[n];

        //preencher arranjo
        f_lerarranjo (array, n, "dados.txt");

        //verificar o maior
        menor = menorvalor (array, n);

        //mostrar o maior 
        printf("%s%d\n", "Menor valor: ", menor);
    }//fim else
    
    //encerrar
    IO_pause ("Aperte ENTER para terminar");
} //fim method05 ()

/**
calc_media - Determina a media dos valores de um arranjo
@param tamanho do arranjo e arranjo
@return media
*/
double calc_media (int n, int array[])
{
    //definir dados
    double media = 0.0;

    //repetir por todos elementos
    for (int x=0; x<n; x++)
    {
        media = media + array[x];
    }//fim for

    //calcula media
    media = media/n;

    //encerra
    return (media);
}//fim calc_media()

/**
Method06 - Determina a media dos valores de uma arranjo
*/
void method06()
{
    //definir dados
    int tamanho = 0;
    double media = 0.0;
    int t_maiores = 0;
    int t_menores = 0;

    //identificar 
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo06");

    //verificar tamanho do arranjo
    tamanho = f_lertamanho ("dados.txt");

    if (tamanho<1)
    {
        printf("\n%s\n", "ERRO: Tamanho Invalido.");
    }//fim if
    else
    {
        //criar arranhos
        int principal [tamanho];
        int maiores [tamanho];
        int menores [tamanho];


        //ler arranjo
        f_lerarranjo (principal, tamanho, "dados.txt");

        //determinar media
        media = calc_media (tamanho, principal);

        // separar valores
        for (int x=0; x<tamanho; x++)
        {
            //maiores ou iguais
            if(principal[x]>=media)
            {
                //escrever maiores
                maiores[t_maiores]=principal[x];
                
                //atualizar tamanho maiores
                t_maiores=t_maiores+1;
            }//fim if
            else
            {
                //escrever menores
                menores[t_menores]=principal[x];

                //atualizar tamanho menores
                t_menores=t_menores+1;
            }
        }//fim for

        //gravar arquivos
        f_escreverarranjo ("maiores.txt", t_maiores, maiores);
        f_escreverarranjo ("menores.txt", t_menores, menores);
    }//fim if

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method06 ()

/**
crescente - Verifica se uma arranjo esta em ordem crescente
@param arranjo e tamanho do arranjo
@return verdadeiro para crescente falso para decrescente
*/
bool crescente (int array[], int n)
{
    //definir dados
    bool resposta = 0;
    int controle = 0;
    int contador = 1;

    //comparar elemento contador-1 com contador e verificar n
    while (controle==0 && contador<n && n>0)
    {
        //vefirica se elemenot contador-1 >= contador
        if(array[contador-1] >= array[contador])
        {
            //atualiza controle
            controle=1;
        }//fim if
        //atualiza contador
        contador = contador +1;
    }//fim while

    //retorno
    return (controle==0);
}//fim crescente
/**
Method07 - Verifica se arranjo esta em ordem crescente
*/
void method07()
{
    //definir dados
    int n = 5;
    int array [] = {1, 2, 3, 4, 5};
    bool ordem = 0;

    //identificar
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo07");

    //verificar ordem
    ordem = crescente (array, n);

    //mostrar resposta
    if (ordem==1)
    {
        printf("%s\n", "Arranjo em ordem crescente");
    }//fim if
    else
    {
        printf("%s\n", "Arranjo nao esta em ordem crescente");
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method07 ()

/**
acharvalor - Verifica se determinado valor esta em um arranjo
@param valor, arranjo, tamanho do arranjo e posicao inicial
@return verdadeiro se encontrado, falso se nao
*/
bool acharvalor (int valor, int array[], int n, int posicao)
{
    //definir dados
    bool resposta = 0;
    int controle = 0;

    //verificar tamanho
    if (n>0)
    {
        //procurar valor
        while(controle==0 && posicao<n)
        {
            //testar
            if (valor==array[posicao])
            {
                //atualizar controle
                controle=1;
            }
            //atualizar contador
            posicao = posicao + 1;
        }//fim while
    }//fim if

    //retorno
    return (resposta!=controle);
}//fim acharvalor
/**
Method08 - Verifica se determinado valor esta no arranjo
*/
void method08()
{
    //definir dados
    int n = 0;
    int valor = 0;
    int posicao = 0;
    bool resposta = 0;

    //identificar
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo08");

    //ler tamanho do arquivo
    n = f_lertamanho ("dados.txt");

    //verificar tamanho
    if (n<1)
    {
        printf("\n%s\n", "ERRO: Tamanho Invalido.");
    }//fim if
    else
    {
        //criar arranjo
        int array[n];

        //preencher arranjo
        f_lerarranjo (array, n, "dados.txt");

        //ler do teclado
        valor = IO_readint ("Entre com valor a ser procurado: ");
        posicao = IO_readint ("Entre com posicao de inicio da procura: ");

        //procurar valor
        resposta = acharvalor (valor, array, n, posicao);

        //mostrar resposta
        if (resposta==1)
        {
            printf ("%d%s%d\n", valor, " encontrado no arranjo a partir da posicao ", posicao);
        }//fim if
        else
        {
            printf ("%d%s%d\n", valor, "  NAO encontrado no arranjo a partir da posicao ", posicao);
        }//fim else        
    }//fim else
    
    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method08 ()

/**
qualposicao - Verifica se determinado valor esta em um arranjo e informa posicao
@param valor, arranjo, tamanho do arranjo e posicao inicial
@return -1 se nao encontrado ou posicao se encontrado
*/
int qualposicao (int valor, int array[], int n, int posicao)
{
    //definir dados
    int resposta = -1;
    int controle = 0;

    //verificar tamanho
    if (n>0)
    {
        //procurar valor
        while(controle==0 && posicao<n)
        {
            //testar
            if (valor==array[posicao])
            {
                //atualizar controle
                controle=1;
                resposta=posicao;
            }
            //atualizar contador
            posicao = posicao + 1;
        }//fim while
    }//fim if

    //retorno
    return (resposta);
}//fim qualposicao

/**
Method09 - Verifica se determinado valor esta no arranjo e posicao
*/
void method09()
{
    //definir dados
    int n = 0;
    int valor = 0;
    int posicao = 0;
    int resposta = 0;

    //identificar
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo09");

    //ler tamanho do arquivo
    n = f_lertamanho ("dados.txt");

    //verificar tamanho
    if (n<1)
    {
        printf("\n%s\n", "ERRO: Tamanho Invalido.");
    }//fim if
    else
    {
        //criar arranjo
        int array[n];

        //preencher arranjo
        f_lerarranjo (array, n, "dados.txt");

        //ler do teclado
        valor = IO_readint ("Entre com valor a ser procurado: ");
        posicao = IO_readint ("Entre com posicao de inicio da procura: ");

        //procurar valor
        resposta = qualposicao (valor, array, n, posicao);

        //mostrar resposta
        if (resposta!=-1)
        {
            printf ("%d%s%d\n", valor, " encontrado no arranjo na posicao ", resposta);
        }//fim if
        else
        {
            printf ("%d%s%d\n", valor, "  NAO encontrado no arranjo a partir da posicao ", posicao);
        }//fim else        
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method09 ()

/**
quantasvezes - Conta quantas vezes determinado valor esta em um arranjo
@param valor, arranjo, tamanho do arranjo e posicao
@return 0 se nao encontrado ou quantidade se encontrado
*/
int quantasvezes (int valor, int array[], int n, int posicao)
{
    //definir dados
    int quantidade = 0;

    //verificar tamanho
    if (n>0)
    {
        //procurar valor
        while (posicao<n)
        {
            //testar
            if (valor==array[posicao])
            {
                //atualizar controle
                quantidade = quantidade + 1;
            }
            //atualizar contador
            posicao = posicao + 1;
        }//fim while
    }//fim if

    //retorno
    return (quantidade);
}//fim quantasvezes

/**
Method10 - Verifica quantas vezes um valor se encontra no arranjo
*/
void method10()
{
    //definir dados
    int n = 0;
    int valor = 0;
    int posicao = 0;
    int resposta = 0;

    //identificar
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo10");

    //ler tamanho do arquivo
    n = f_lertamanho ("dados.txt");

    //verificar tamanho
    if (n<1)
    {
        printf("\n%s\n", "ERRO: Tamanho Invalido.");
    }//fim if
    else
    {
        //criar arranjo
        int array[n];

        //preencher arranjo
        f_lerarranjo (array, n, "dados.txt");

        //ler do teclado
        valor = IO_readint ("Entre com valor a ser procurado: ");
        posicao = IO_readint ("Entre com posicao de inicio da procura: ");

        //procurar valor
        resposta = quantasvezes (valor, array, n, posicao);

        //mostrar resposta
        if (resposta!=-1)
        {
            printf ("%d%s%d\n", valor, " foi encontrado no arranjo na seguinte quantidade: ", resposta);
        }//fim if
        else
        {
            printf ("%d%s%d\n", valor, "  NAO encontrado no arranjo a partir da posicao ", posicao);
        }//fim else        
    }//fim else

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method10 ()

/**
quantosdivisores - Calcula quantos sao os divisores de um numero
inteiro positivo
@param numero
@return quantidade de divisores
*/
int quantosdivisores (int x)
{
    //definir dados
    int quantidade = 0;

    //repetir de 1 a x
    for (int y=1; y<=x; y++)
    {
        //verificar se y e' divisor
        if (x%y==0)
        {
            //atualiza quantidade
            quantidade = quantidade + 1;
        } //fim if
    }//fim for

    //retorno
    return (quantidade);
}//fim quantosdivisores()

/**
quaisdivisores - Grava em um arranjo os divisores de um numero 
inteiro positivo. 
Obs: pressupoe que ja se saiba quantos sao os divisores
@param numero, quantidade de divisores e arranjo a ser gravado
*/
void quaisdivisores (int x, int n, int array[])
{
    //definir dados
    int contador = 1;
    int controle = 0;

    //verificar quantidade
    if (n>0)
    {
        //repetir ate encontrar todos divisores
        while (controle<n && contador<=x)
        {
            //verificar se contador e' divisor
            if (x%contador==0)
            {
                //grava no arranjo
                array[controle]=contador;

                //atualiza controle
                controle = controle + 1;
            } //fim if

            //atualiza contador
            contador = contador + 1;
        }//fim while
    }//fim if
}//fim quaisdivisores ()

/**
mostrararranjo - mostra arranjo no terminal
@param arranjo e tamanho do arranjo
*/
void mostrararranjo (int array[], int n)
{
    //mostrar cada item do arranjo
    for (int x=0; x<n; x++)
    {
        printf ("%d: %d\n", x, array[x]);
    }//fim for
}//fim mostrararranjo

/**
Method11 - 
*/
void method11()
{
    //definir dados
    int valor = 0;
    int n = 0;

    //identificar
    IO_id ("ED08 - Exemplos 0811 - 08E2 - Metodo11");

    //ler valor do teclado
    valor = IO_readint ("Entre com valor inteiro positivo: ");

    //verifica input
    if (valor>0)
    {
        //calcula quantos sao os divisores
        n = quantosdivisores (valor);

        //verifica se quantidade positiva
        if (n<1)
        {
            printf("\n%s\n", "ERRO: Tamanho Invalido.");
        }//fim if
        else
        {
            //cria arranjo
            int array [n];

            //preencher arranjo com divisores
            quaisdivisores (valor, n, array);

            //gravar arranjo em arquivo
            f_escreverarranjo ("divisores.txt", n, array);

            //mostrar arranjo na tela
            mostrararranjo (array, n);
        }//fim else
    }//fim if

    //encerrar
    IO_pause ("Aperte enter para continuar");
} //fim method11 ()

/**
spalavras - le um arquivo e separa as primeiras 10
palavras que nao comecem com a letra A ou a
@param nome do arquivo e arranjo para respostas
*/
void spalavras (char* file, char* array[])
{
    //definir dados
    int contador = 0;
    FILE *arquivo = fopen (file, "rt");
    char palavra [80];

    //ler arquivo ate achar 10 palavras
    while (contador <10 && !feof(arquivo))
    {
        //ler palavra
        fscanf (arquivo, "%s", palavra);
        
        //verificar primeira letra
        if (!(palavra[0]=='A' || palavra[0]=='a'))
        {
            //armazenar palavra
            strcpy (array[contador], palavra);
            
            //atualizar contador
            contador = contador + 1;
        }//fim if
    }//fim while

    //encerrar
    fclose (arquivo);
}//fim spalavras

/**
Method12 - Le as primeira 10 palavras de uma arquivo que 
nao comecem com A ou a e as mostra
*/
void method12()
{
    //definir dados
    char* palavras [10];

    //inicializar arranjo
    for (int x=0; x<10; x++)
    {
        palavras [x] = (char*) malloc (sizeof(char)*STR_SIZE);
        palavras [x][0] = '\0'; 
    }//fim for

    //identificar
    IO_id ("ED08 - Exemplos 0811 -08E2 - Metodo12");

    //chamar funcao que separa as palavras
    spalavras ("palavras.txt", palavras);

    //mostrar palavras
    for (int x=0; x<10; x++)
    {
        printf ("%s\n", palavras[x]);
    }//fim for

    //encerrar
    IO_pause ("Aperte ENTER para continuar");
} //fim method12 ()

/**
Funcao Principal - Apresenta menu de escolhas de metodos
*/

int main()
{
    //definir dados
    int x = 0;

    //apresentar menu
    do
    {
        //identidicar
        printf("\n");
        IO_id("ED08 - Exemplos 0811 - 08E2");

        //opcoes
        IO_println("Opcoes:");
        IO_println("0- Sair");
        IO_println("1- Preenche arranjo com valores pares positivos");
        IO_println("2- Le numeros de arquivo e separa pares positivos");
        IO_println("3- Grava arquivo com n valores aleatorios dentro dos limites");
        IO_println("4- Le arranjo de arquivo e verifica seu maior elemento");
        IO_println("5- Le arranjo de arquivo e verifica seu menor elemento");
        IO_println("6- Determina media dos valores e separa em 2 arquivos");
        IO_println("7- Verifica se um arranjo esta em ordem crescente");
        IO_println("8- Verifica se valor esta no arranjo");
        IO_println("9- Verifica se valor esta no arranjo e posicao se estiver");
        IO_println("10- Verifica quantas vezes valor e' encontrado no arranjo");
        IO_println("11- Calcula quais e quantos dividores de um inteiro");
        IO_println("12- Mostra as 10 primeira palavras de arquivo nao comeca A ou a");

        //ler teclado
        x = IO_readint("Escolha uma das opcoes: ");

        //chamar metodo de acordo com opcao
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
            method10();
            break;

        case 11:
            method11();
            break;

        case 12:
            method12();
            break;

        default:
            IO_pause("Numero Invalido");
        }

    } while (x != 0); //fim while

    //encerrar
    IO_pause("Aperte ENTER para terminar");

    //retorno
    return (0);

} //fim main

/*
------------------------------------Comentarios
Main:   
    v1- funcionou como esperado

method01:
    v1- funcionou como esperado

method02:
    v1- funcionou como esperado

method03:
    v1- gerou um numero a menos (a) e todos iguais (b)
    a) consertado: loop for comecando com 1
    b) srand(time(NULL)) nao pode ficar dentro da funcao;
    v2- funcionou como esperado, tem hora que nao grava (gravacao dentro do metodo);
    obs: gravando arquivo atraves de um metodo auxiliar gravou sempre

method04:
    v1- fechando o nome do arquivo ao inves do ponteiro;
    v2- funcionou como esperado;

method05:
    v1- funcionou como esperado;

method06:
    v1- funcionou como esperado;

method07:
    v1- contador do loop while nao estava sendo atualizado
        consertado com a expressao contador=contador+1;
    v2- funcionou como esperado;

method08:
    v1- primeira versao nao pedia posicao, comecava de 0;
    v2- funcionou como esperado;

method09:
    v1- funcionou como esperado;

method10:
    v1- funcionou como esperado

method11:
    v1- floating point exception 8, funcao quaisdivisores ()
    dividindo por 0;
    v2- programa em loop infinito, condicao do while de quaisdivisores ()
    estava || mudada para &&;
    v3- funcionou como esperado;

method12:
    v1- OS encerrou o programa: abort trap 6, loop while
    da funcao spalavrar com ||, mudado para &&;
    v2- abort trap 6 corrigido, escreveu a 10a palavra varias vezes,
    estava copiando as strings por = e nao strcpy;
    v3- funcionou como esperado;

------------------------------------Testes
method01:   3: -2, -1, 0
            5: -2, 1, 2, 3, 4
method02:   ARRAY.txt
            method02.txt
method03:   55 78 10
            10 1000 20
            1 100 20
method04:   ARRAY1.txt
            dados.txt
method05:   ARRAY1.txt
            dados.txt
method06:   ARRAY.txt
            dados.txt
method07:   {1, 2, 3, 4, 5}
            {1, 2, 3, 5, 4}
method08:   25 10, 99 0, 25 1 

method09:   9 1, 9 0, 100 0, 88 10

method10:   9 0, 9 5, 66 0, 18 0, 100 0

method11:   2, 3, 10, 100

method12:   palavras.txt
*/
