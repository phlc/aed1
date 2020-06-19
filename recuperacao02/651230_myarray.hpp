/*
651230_myarray.hpp 
Author: Pedro Henrique Lima Carvalho
*/

// ----------------------------------------------- definicoes globais
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

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
using std::ifstream ; // para ler arquivo


class Array
{
    private: // area reservada
        int length;
        int *data;

    public: // area aberta
        Array ( int n )
        {
            // definir valor inicial
            length = n;
            data = NULL;

            // reservar area
            if ( n > 0 )
            {
                data = new int [ length ];
            }
        } // end constructor

        void free ( )
        {
            if ( data != NULL )
            {
                delete ( data );
                data = NULL;
            } // end if
        } // end free ( )

        void set ( int position, int value )
        {
            if ( 0 <= position && position <= length )
            {
                data [ position ] = value;
            } // end if
        } // end set ( )

        int get ( int position )
        {
            int value = 0;
            if ( 0 <= position && position <= length )
            {
                value = data [ position ];
            } // end if
            return ( value );
        } // end get ( )

        int get_length ( )
        {
            return ( length );
        } // end get ( )

        void print ( )
        {
            cout << endl;
            for ( int x = 0; x < length; x=x+1 )
            {
                cout << setw( 3 ) << x << " : "
                     << setw( 9 ) << data[ x ]
                     << endl;
            } // end for
            cout << endl;
        } // end print ( )

        /**
        fread - metodo para preencher um arranjo lendo dados do arquivo
        @param nome do arquivo
        @return referencia do arranjo
        */
        Array& fread (std::string nome)
        {
            //definir dados
            ifstream arquivo;
            int tamanho = 0;
            int valor = 0;
            Array *p_arranjo = nullptr;

            //abrir arquivo
            arquivo.open (nome);

            //testar abertura
            if (!arquivo.is_open())
            {
                cout << "Erro ao abrir arquivo" << endl;
            }//fim if
            else
            {
                //ler tamanho do arranjo
                arquivo >> tamanho;

                //verificar tamanho
                if (tamanho < 1)
                {
                    cout << "Tamanho do arranjo invalido (fread)" << endl;
                }//fim if
                else
                {
                    //criar arrajo
                    p_arranjo = new Array (tamanho);

                    //preencher arranho
                    for (int x=0; !arquivo.eof() && x<p_arranjo->length; x++)
                    {
                        arquivo >> valor;
                        p_arranjo->set(x, valor);
                    }//fim for
                }//fim else
            }//fim else

            //retorno
            return(*p_arranjo);
        }//fim fread

        /**
        fprint - Grava os dados de um arranjo em um arquivo
        @param - nome do arquivo
        */
        void fprint (std::string nome)
        {
            //testar input
            if (this->length < 1)
            {
                cout << "Tamanho do arranjo invalido (fprint)" << endl;
            }//fim if
            else
            {
                //definir dados
                ofstream arquivo;

                //abrir arquivo
                arquivo.open (nome);

                //gravar tamanho
                arquivo << this->length << endl;

                //gravar dados
                for (int x=0; x<this->length; x++)
                {
                    arquivo << this->get(x) << endl;
                }//fim for
            }//fim else
        }//fim fprint ()

        /**
        invertSort - ordena um arranjo em forma decrescente
        */
        void invertSort ( )
        {   
            //definir dados
            int buffer = 0;
            int controle = 0;
            
            //testar input
            if (this->length < 1)
            {
                cout << "Tamanho do arranjo invalido (invertSort)" <<  endl;
            }//fim if
            else
            {   
                while (controle == 0)
                {
                    controle = 1;
                    for (int x=1; x<this->length; x++)
                    {
                        if (this->get(x) > this->get(x-1))
                        {
                            buffer = this->get(x-1);
                            this->set(x-1, this->get(x));
                            this->set(x, buffer);
                            controle = 0;
                        }//fim if 
                    }//fim for
                }//fim whilw
            }//fim else
        }

        /**
        invert - inverte os elementos de um arranjo
        @param referencia de um arranjo
        */
        Array& invert (Array& arranjo)
        {
            //definir dados
            Array* p_arranjo = nullptr;
            
            //testar input
            if (arranjo.length < 1)
            {
                cout << "Tamanho do arranjo invalido (invert)" <<  endl;
            }//fim if
            else
            {
                //criar arranjo
                p_arranjo = new Array(arranjo.length);


                //atribuir tamanho
                p_arranjo->length = arranjo.length;

                //inverter elementos
                for (int x=0; x<p_arranjo->length; x++)
                {
                    //gravar invertido
                    p_arranjo->set(x, arranjo.get(arranjo.length-1-x));
                }//fim for
            }//fim else

            //retorno
            return(*p_arranjo);
        }//fim invert()

        /**
         * lower_2nd - mostra o segundo menor valor de um arranjo
         * @return - segundo menor valor
         */

        int lower_2nd ()
        {
            //definir dados
            int menor = 0;
            int resposta = 0;
            
            //testar input
            if (this->length < 2)
            {
                cout << "Tamanho do arranjo invalido (lower_2nd)" <<  endl;
            }//fim if
            else
            {
                //estabelecer referencia
                int menor = this->data[0];
                if (this->data[1]>menor)
                {
                    menor = this->data[1];
                }//fim if

                for (int x=0; x<this->length; x++)
                {
                    //descobri menor e segundo menor
                    if (menor >= this->data[x])
                    {
                        resposta = menor;
                        menor = this->data[x];
                    }//fim if
                }//fim for
            }// fim else

            return (resposta);
        } //fim lower_2nd()

        void filter (Array& arr1, Array& arr2)
        {
            //testar input
            if (arr1.length < 1 || arr2.length < 1)
            {
                cout << "Tamanho do arranjo invalido (lower_2nd)" <<  endl;
            }//fim if
            else
            {
                //definir dados
                int counter = 0;
                
                //alocar memoria para data de this 
                this->data = new int[arr1.length];

                //comparar arranjos
                for (int x=0; x<arr1.length; x++)
                {
                    for (int y=0; y<arr2.length; y++)
                    {
                        //verficcar elementos iguais
                        if (arr1.get(x) == arr2.get(y))
                        {
                            this->set(counter, arr1.get(x));
                            counter++;
                            this->length = counter;
                        }//fim if
                    }//fim for
                }//fim for
            }//fim else
        }//fim filter()

        /**
         * convert - converte um arranjo binario em seu correspondente decimal
         */
        int convert ()
        {
            //definir dados
            int decimal = 0;

            //testar input
            if (this->length < 1)
            {
                decimal = -1;
                cout << "Tamanho do arranjo invalido (convert)" <<  endl;
            }//fim if
            else
            {
                //testar se arranjo binario
                for (int x=0; x<this->length; x++)
                {
                    if (this->data[x] !=0 && this->data[x] != 1)
                    {
                        decimal = -1;
                        cout << "Erro: Arranjo nao binario" << endl;
                    }//fim if
                }//fim for

                //converter para decimal
                for (int x=0; x<this->length && decimal!=-1; x++)
                {
                    decimal = decimal +( this->data[x] * (int) pow (2, this->length-1-x));
                }//fim for
            }//fim else
            
            //retorno
            return (decimal);
        }//fim convert()
};
#endif