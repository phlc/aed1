/*
651230_produtos.hpp
Author: Pedro Henrique Lima Carvalho
*/
 
// ----------------------------------------------- definicoes globais
#ifndef _PRODUTOS_HPP_
#define _PRODUTOS_HPP_

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

class Produto
{
    private: // area reservada
        std::string nome;
        std::string* supermercados;
        int* codigos;
        double* precos;
        int controle;
        int tamanho;

    public: // area aberta
        
        Produto ( std::string nome, int quantidade )
        {
            // definir valores iniciais
            this->nome = nome;
            this->supermercados = new std::string[quantidade];
            this->codigos = new int[quantidade];
            this->precos = new double[quantidade];
            this->controle = 0;
            this->tamanho = quantidade;
        } // end constructor

        ~Produto ( )
        {
        } // end destructor ( )

        /**
         * insert - Insere novo supermercado, codido e preco do produto
         * @param nome do supermercado, codico e preco
         */
        void insert ( std::string supermercado, int codigo, double preco)
        {
            //verificar ocupacao do arranjo
            if ( controle >= tamanho)
            {
                cout << "Lista de supermercados cheia." << endl;
            }  
            else
            {
                //inserir dados
                this->supermercados[controle] = supermercado;
                this->codigos[controle] = codigo;
                this->precos[controle] = preco;
                
                //atualizar controle
                controle++;
            } // end if
        } // end insert ( )

        /**
         * remove - Remove um supermercado atraves de seu codigo
         * @param codigo do supermercado
         */
        void remove ( int codigo )
        {
            //define dados
            bool test = false;
            
            //verifica ha supermercado com o codigo na lista
            for (int x=0; x<controle; x++)
            {
                if (codigo == this->codigos[x])
                {
                    //atualiza test
                    test = true;

                    //remove supermercado movendo todos os demais
                    for (int y=x+1; y<controle; y++)
                    {
                        this->supermercados[y-1] = this->supermercados[y];
                        this->codigos[y-1] = this->codigos[y];
                        this->precos[y-1] = this->precos[y];
                    }//fim for

                    //atualiza controle
                    controle--;
                    
                }//fim if
            }//fim for

            //verifica se houve remocao
            if (!test)
                cout << "Supermercado nao encontrado" << endl;
        }// end remove()
        
        /**
         * print - mostra dados do produto
         */
        void print ( )
        {
            //mostrar nome do produto
            cout << endl;
            cout << "Produto: " << this->nome << endl;

            for ( int x = 0; x < controle; x++ )
            {
                cout << this->supermercados[x] << "\t"
                     << this->codigos[x] << "\t"
                     << "R$" << std::fixed << std::setprecision(2) << this->precos[x] << endl;
            } // end for
            cout << endl;
        } // end print ( )

        /**
        average - mostra o preco medido do produto
        @return preco medio do produto
        */
        double average ( )
        {
            //definir dados
            double media = 0;

            //somar precos
            for (int x=0; x<controle; x++)
            {
                media = media + this->precos[x];
            }//fim for

            //calcular media
            media = media/controle;
            
            //retorno
            return (media);
        }//fim average()

        /**
         * lower - mostra supermercados com precos inferiores a media
         */
        void lower ( )
        {
            //definir dados
            double media = this->average();

            //mostrar nome do produto
            cout << endl;
            cout << "Produto: " << this->nome << endl;
            cout << "Supermercados baratos:" << endl;

            //mostrar dados do supermercado com preco abaixo da media
            for ( int x = 0; x < controle; x++ )
            {
                if(media > this->precos[x])
                {
                    cout << this->supermercados[x] << "\t"
                         << "R$" << std::setprecision(2) << this->precos[x] << endl;
                }//fim if          
            } // end for
            cout << endl;           
        }//fim lower()

};//end Produto
#endif