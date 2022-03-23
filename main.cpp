#include <iostream>
#include "relatorio.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

int main()
{
//abertura do relatorio com contructor e nome atribuido a class//
relatorio registo("suicidios");
//declaração da variavel que aponta para o arquivo//
ifstream reg("dataset.csv");
//adicionar o data set a estrectura de dados//
registo.addRelatorio(reg);
//abertura do menu do programa para interface com o usuario//
registo.menuRelatorio();

}

