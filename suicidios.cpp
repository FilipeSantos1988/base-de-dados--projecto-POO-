#include "suicidios.h"

suicidios::suicidios(){
set_ano(0);
set_qntdCasos(0);}


suicidios::suicidios(int ano,float taxa){
    set_ano(ano);
    set_qntdCasos(taxa);}


int suicidios::get_ano(){
return ano;}


float suicidios::get_qntdCasos(){
return qntdCasos;}


void suicidios::set_ano(int anos){
ano=anos;}


void suicidios::set_qntdCasos(float taxas){
qntdCasos=taxas;}
