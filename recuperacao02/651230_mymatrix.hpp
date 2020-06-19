/*
mymatrix.h
Author: Pedro Henrique Lima Carvalho
*/
 
// ----------------------------------------------- definicoes globais
#ifndef _MYMATRIX_H_
#define _MYMATRIX_H_

// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream; // para ler arquivo

class Matrix
{
    private: // area reservada
        int lines ;
        int columns;
        int** data ;

    public: // area aberta
        
        Matrix ( int lines, int columns )
        {
            // definir valores iniciais
            this->lines = lines;
            this->columns = columns;
            // reservar area
            data = new int* [ lines ];
            for ( int x = 0; x < lines; x=x+1 )
            {
                data [x] = new int [ columns ];
            } // end for
        } // end constructor

        ~Matrix ( )
        {
            if ( data != NULL )
            {
                for ( int x = 0; x < lines; x=x+1 )
                {               
                    delete ( data [ x ] );
                } // end for
                delete ( data );
            } // end if
        } // end destructor ( )

        void set ( int line, int column, int value )
        {
            if ( line < 0 || line >= lines ||
                 column < 0 || column >= columns )
            {
                cout << "\nERROR: Invalid position.\n";
            }       
            else
            {
                data [ line ][ column ] = value;
            } // end if
        } // end set ( )

        int get ( int line, int column )
        {
            int value = 0;
            if ( line < 0 || line >= lines ||
                 column < 0 || column >= columns )
            {
                cout << "\nERROR: Invalid position.\n";
            }
            else
            {
                value = data [ line ][ column ];
            } // end if
            return(value);
        }// end get()
        
        void print ( )
        {
            cout << endl;
            for ( int x = 0; x < lines; x=x+1 )
            {
                for ( int y = 0; y < columns; y=y+1 )
                {
                    cout << data[ x ][ y ] << "\t";
                } // end for
                cout << endl;
            } // end for
            cout << endl;
        } // end print ( )

        /**
        fread - metodo para preencher uma matriz lendo dados do arquivo
        @param nome do arquivo
        */
        void fread (std::string nome)
        {
            //definir dados
            ifstream arquivo;
            int linhas = 0;
            int colunas = 0;
            int valor = 0;

            //abrir arquivo
            arquivo.open (nome);

            //testar abertura
            if (!arquivo.is_open())
            {
                cout << "Erro ao abrir arquivo" << endl;
            }//fim if
            else
            {
                //ler linhas e colunas da matriz
                arquivo >> linhas;
                arquivo >> colunas;

                //verificar dimensoes
                if (linhas < 1 || colunas < 1)
                {
                    cout << "Tamanho da matriz invalido (fread)" << endl;
                }//fim if
                else
                {
                    //alocar memoria
                    this->lines = linhas;
                    this->columns = colunas;
                    data = new int* [ lines ];
                    for ( int x = 0; x < lines; x=x+1 )
                    {
                        data [x] = new int [ columns ];
                    }//fim for

                    //preencher matriz
                    for (int x=0; !arquivo.eof() && x<this->lines; x++)
                    {
                        for (int y=0; !arquivo.eof() && y<this->columns; y++)
                        {
                            arquivo >> valor;
                            this->set(x, y, valor);
                        }//fim for
                    }//fim for
                }//fim else
            }//fim else
        }//fim fread()

        /**
         * questao6 - Preenche a matriz no padrao estabelecido
         */
        void questao6 ( )
        {
            //definir dados
            int contador = 1;

            //verificar input
            if (this->lines<1 || this->columns<1)
            {
                cout << "Matriz de tamanho invalido" << endl;
            }//fim if
            else
            {
                //preencher matriz
                for (int x=0; x<this->lines; x++)
                {
                    for (int y=0; y<this->columns; y++)
                    {
                     if (x-y > 1 || x-y < -1)
                        {
                            this->data[x][y] = 0;
                        }//fim if
                        else
                        {
                            this->data[x][y] = contador;
                            contador++;
                        }//fim else
                    }//fim for
                }//fim for
            }//fim else
        }//fim questao6()

        /**
         * questao7 - Preenche a matriz no padrao estabelecido
         */
        void questao7 ( )
        {
            //definir dados
            int contador = 1;

            //verificar input
            if (this->lines<1 || this->columns<1)
            {
                cout << "Matriz de tamanho invalido" << endl;
            }//fim if
            else
            {
                //preencher matriz
                for (int y=this->columns-1; y>=0; y--)
                {
                    for (int x=this->lines-1; x>=0; x--)
                    {
                        if (x-y > 1 || x-y < -1)
                        {
                            this->data[x][y] = 0;
                        }//fim if
                        else
                        {
                            this->data[x][y] = contador;
                            contador++;
                        }//fim else
                    }//fim for
                }//fim for
            }//fim else
        }//fim questao7()

        /**
         * questao8 - Verifica se a matriz esta no padrao estabelecido
         */
        bool questao8 ( )
        {
            //definir dados
            int controle = 0;

            //verificar input
            if (this->lines<1 || this->columns<1)
            {
                cout << "Matriz de tamanho invalido" << endl;
            }//fim if
            else
            {
                controle = 1;
                //verificar se matriz quadrada
                if (this->lines != this-> columns)
                {
                    controle = 0;
                }//fim if

                //testar padroes
                for (int x=0; x<this->lines && controle==1; x++)
                {
                    for (int y=0; y<this->columns && controle==1; y++)
                    {
                        if (this->data[x][y] != (int) pow (x+1, y))
                        {
                            controle = 0;
                        }
                    }//fim for
                }//fim for
            }//fim else
            //retorno
            return (controle==1);
        }//fim questao8()

        /**
         * compareTo - Verifica se matrizes sao iguais
         * @param matriz a ser comparada
         * @return  0, se forem iguais, (+1) se o elemento diferente na primeira for maior, e
                    (- 1) se o elemento diferente na primeira for menor.
         */
        int compareTo (Matrix& other)
        {
            //definir dados
            int resposta = 0;

            //verificar input
            if (this->lines<1 || this->columns<1 || other.lines<1 || other.columns<1)
            {
                cout << "Matrizes de tamanho invalido (compareTo)" << endl;
                resposta = 2;
            }//fim if
            else
            {
                //verificar se matrizes tem tamanhos iguais
                if (this->lines != other.lines || this-> columns != other.columns)
                {
                     cout << "Matrizes de tamanhos diferentes" << endl;
                    resposta = 2;
                }//fim if

                //testar padroes
                for (int x=0; x<this->lines && resposta==0; x++)
                {
                    for (int y=0; y<this->columns && resposta==0; y++)
                    {
                        if(this->data[x][y] - other.data[x][y] > 0)
                        {
                            resposta = 1;
                        }//fim if
                        else if(this->data[x][y] - other.data[x][y] < 0)
                        {
                            resposta = -1;
                        }//fim else if
                    }//fim for
                }//fim for
            }//fim else
            //retorno
            return (resposta);
        }//fim questao8()
};//end Matrix
#endif