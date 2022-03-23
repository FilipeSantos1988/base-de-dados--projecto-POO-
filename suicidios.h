#ifndef SUICIDIOS_H_INCLUDED
#define SUICIDIOS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>


using namespace std;


class suicidios{
private:
    int ano;
    float qntdCasos;
public:
    suicidios();
    suicidios(int ano,float taxa);
    virtual~suicidios(){;}
    int get_ano();
    float get_qntdCasos();
    void set_ano(int);
    void set_qntdCasos(float);};




#endif // SUICIDIOS_H_INCLUDED//
