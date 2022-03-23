#include "pessoas.h"

pessoas::pessoas(){
;}

pessoas::pessoas(string nomePais,string genero,float ano2016,float ano2015, float ano2010, float ano2000){

this->nomePais=nomePais;
this->genero=genero;


    obitos.push_back(suicidios(2016,ano2016));
    obitos.push_back(suicidios(2015,ano2015));
    obitos.push_back(suicidios(2010,ano2010));
    obitos.push_back(suicidios(2000,ano2000));
    set_nObitos(4);}


string pessoas::get_nomePais(){
return nomePais;}

string pessoas::get_genero(){
return genero;}

int pessoas::get_nObitos(){
return nObitos;}


void pessoas::set_nomePais(string nPais){
nomePais=nPais;}

void pessoas::set_genero(string generos){
genero=generos;}

void pessoas::set_nObitos(int qntdObitos){
nObitos=qntdObitos;}


float pessoas::maiorQntdCasos(){

int i=0;
float maior=0;

for(i=0;i<nObitos;i++){
    if(obitos[i].get_qntdCasos()>maior){
        maior=obitos[i].get_qntdCasos();}}

return maior;
}



float pessoas::menorQntdCasos(){
int i=0;
float menor=100;

for(i=0;i<nObitos;i++){
    if(obitos[i].get_qntdCasos()<menor){
        menor=obitos[i].get_qntdCasos();}}

return menor;
}


void pessoas::mostrarSuicidios(){
int i=0;
for(i=0;i<nObitos;i++){
    cout<<"Ano: "<<obitos[i].get_ano()<<endl;
    cout<<"Quantidade Casos: "<<obitos[i].get_qntdCasos()<<endl;}}


void pessoas::mostrarAno(int ano){

int i=0;
int encontro=0;
for(i=0;i<obitos.size();i++){
    if(obitos[i].get_ano()==ano){
        encontro=1;
        cout<<obitos[i].get_qntdCasos();}}

if(encontro==0){
    cout<<"Não existem dados para esse ano"<<endl;
}
}

//operador de sobrecarga comparaçao de valores maximos de suicidios que houve entre um pais e o outro//
pessoas pessoas::operator>(pessoas &p){


if(this->maiorQntdCasos()>p.maiorQntdCasos())
    return pessoas(this->nomePais,this->genero,this->obitos[0].get_qntdCasos(),this->obitos[1].get_qntdCasos(),this->obitos[2].get_qntdCasos(),this->obitos[3].get_qntdCasos());
else {
    return p;}


}
