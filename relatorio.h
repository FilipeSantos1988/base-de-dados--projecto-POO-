#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "pessoas.h"
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class relatorio{
private:
    string nome;
    int nPaises;
    vector<pessoas>casos;
public:
    relatorio();
    relatorio(string nome);
    virtual~relatorio(){;}
    string get_nome();
    void set_nome(string nome);
    int get_nPaises();
    void set_nPaises(int);
    void adicionarPaises(string,string,float,float,float,float);//adicionar mais dados as classes//
    void paisMaiorQntdCasos();
    void paisMenorQntdCasos();
    void paisesOndegenero(string);
    void mostrarRegistos();
    void addRelatorio(ifstream &reg);//adicionar ficheiro, alem de criar um encapsulamento tinha no menu posso usalo para outros ficheiros com registos iguais
    void ordenarPorCasos();
    void menuRelatorio();
    void mostrarCasosPais(string nome);
    void mostrarCasosPais(string nome,int ano);
    void comparar2Paises();



};


#endif // RELATORIO_H_INCLUDED//
