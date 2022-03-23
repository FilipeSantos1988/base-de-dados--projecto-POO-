#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "suicidios.h"

using namespace std;

class pessoas{
private:
    string nomePais;
    string genero;
    vector<suicidios> obitos;
    int nObitos;
public:
    pessoas();
    pessoas(string nomePais,string genero,float ano2016,float ano2015, float ano2010, float ano2000);
    virtual~pessoas(){;}
    string get_nomePais();
    string get_genero();
    int get_nObitos();
    void set_nomePais(string);
    void set_genero(string);
    void set_nObitos(int);
    float maiorQntdCasos();
    float menorQntdCasos();
    void mostrarSuicidios();
    void mostrarAno(int ano);
    pessoas operator>(pessoas &p);//implementacao da sobrecarga de operadores
    };



#endif // PESSOAS_H_INCLUDED//
