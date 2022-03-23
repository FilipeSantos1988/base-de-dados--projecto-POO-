#include "relatorio.h"



relatorio::relatorio(){
;}

relatorio::relatorio(string nomeRelatorio){
nPaises=0;
set_nome(nomeRelatorio);
}

string relatorio::get_nome(){
return nome;}

void relatorio::set_nome(string nomeRelatorio){
nome=nomeRelatorio;}


int relatorio::get_nPaises(){
return nPaises;}

void relatorio::set_nPaises(int numeroP){
nPaises=numeroP;}

//funcao criada para adicionar conteudo ao vector//
void relatorio::adicionarPaises(string nome,string genero,float tax1,float tax2,float tax3,float tax4){


casos.push_back(pessoas(nome,genero,tax1,tax2,tax3,tax4));
set_nPaises(get_nPaises()+1);//conforme e adicionado a quantidade de o membro atributo aumenta//

}

void relatorio::paisMaiorQntdCasos(){
int i=0;
int maior=0,indicePais=0;

for(i=0;i<(get_nPaises());i++){
   if(casos[i].maiorQntdCasos()>maior){
    indicePais=i;
    maior=casos[i].maiorQntdCasos();
   }}
cout<<"Maior Percentagem De Casos"<<endl;
cout<<"Nome Pais: "<<casos[indicePais].get_nomePais()<<endl;
cout<<"Genero: "<<casos[indicePais].get_genero()<<endl;
cout<<"maior quantidade: "<<casos[indicePais].maiorQntdCasos()<<endl;
}

void relatorio::paisMenorQntdCasos(){

int i=0;
int menor=100,indicePais=0;

for(i=0;i<(get_nPaises());i++){
   if(casos[i].menorQntdCasos()<menor){
    indicePais=i;
    menor=casos[i].menorQntdCasos();
   }}

cout<<"Menor Percentagem De Casos"<<endl;
cout<<"Nome Pais: "<<casos[indicePais].get_nomePais()<<endl;
cout<<"Genero: "<<casos[indicePais].get_genero()<<endl;
cout<<"maior quantidade: "<<casos[indicePais].menorQntdCasos()<<endl;
}

void relatorio::mostrarRegistos(){
int i=0;

for(i=0;i<casos.size();i++){
    cout<<"Nome Pais:"<<casos[i].get_nomePais()<<endl;
    cout<<"Sexo:"<<casos[i].get_genero()<<endl;
    casos[i].mostrarSuicidios();
    cout<<endl<<endl;}}

void relatorio::addRelatorio(ifstream &reg){

string nome,genero;
double tax1,tax2,tax3,tax4;
string string1;

int primeiraLinha=0;

//foi usada a funcacao stringstream para conseguir modificar o tipo da variavel//
if(reg.good()){
    while(!reg.eof()){
            if(primeiraLinha==0){
            getline(reg,string1,'\n');
            primeiraLinha=1;}
            else{
            getline(reg,string1,',');
            nome=string1;
            getline(reg,string1,',');
            string1.erase(remove(string1.begin(), string1.end(),' '), string1.end());
            genero=string1;
            stringstream ss;
            getline(reg,string1,',');
            ss<<string1;
            ss>>tax1;
            stringstream aa;
            getline(reg,string1,',');
            aa<<string1;
            aa>>tax2;
            stringstream bb;
            getline(reg,string1,',');
            bb<<string1;
            bb>>tax3;
            stringstream cc;
            getline(reg,string1,'\n');
            cc<<string1;
            cc>>tax4;
            casos.push_back(pessoas(nome,genero,tax1,tax2,tax3,tax4));
            set_nPaises(get_nPaises()+1);}}

casos.erase(casos.end()-1);
set_nPaises(get_nPaises()-1);
}}

void relatorio::ordenarPorCasos(){


int i=0,j=0;

for(i=0;i<casos.size()-1;i++){
    for(j=i+1;j<casos.size();j++){
        if(casos[i].maiorQntdCasos()>casos[j].maiorQntdCasos()){
          swap(casos[i],casos[j]);}}}

}


void relatorio::mostrarCasosPais(string nome){

int i=0;
    for(i=0;i<casos.size();i++){
        if(casos[i].get_nomePais()==nome){
            cout<<"Nome Pais: "<<casos[i].get_nomePais()<<endl;
            cout<<"Sexo: "<<casos[i].get_genero()<<endl;
            casos[i].mostrarSuicidios();
            cout<<endl<<endl;}}}


void relatorio::mostrarCasosPais(string nome ,int ano){


    int i=0;
    for(i=0;i<casos.size();i++){
        if(casos[i].get_nomePais()==nome){
            cout<<"Nome Pais: "<<casos[i].get_nomePais()<<endl;
            cout<<"Sexo: "<<casos[i].get_genero()<<endl;
            casos[i].mostrarAno(ano);
            cout<<endl<<endl;}}}

//interface//
void relatorio::menuRelatorio(){

int numero=10,ano,pesquisa=0;
float tax1,tax2,tax3,tax4;
string nome,genero;



    cout<<"**********************-------------------------------*********************************"<<endl;
    cout<<"*************************"<<"Banco de dados -Suicidios"<<"************************************"<<endl;
    cout<<"**********************-------------------------------********************************"<<endl;
    cout<<"*************************************************************************************"<<endl;
    cout<<"*------------------------------------------------------------------------------------*"<<endl;
    cout<<"|[1]->Adicionar registo ao relatorio                                                 |"<<endl;
    cout<<"|[2]->Mostra Pais com maior percentagem de casos por n habitante                     |"<<endl;
    cout<<"|[3]->Mostrar Pais com menor percentagem de casos por n habitante                    |"<<endl;
    cout<<"|[4]->Mostrar os Registos de todos os paises                                         |"<<endl;
    cout<<"|[5]->Ordenar casos por maior percentagem de suicidios ocorridos                     |"<<endl;
    cout<<"|[6]->Pesquisa avancada                                                              |"<<endl;
    cout<<"|[7]->comparar 2 Paises                                                              |"<<endl;
    cout<<"|[0]->Sair                                                                           |"<<endl;
    cout<<"*------------------------------------------------------------------------------------*"<<endl;
    cout<<"**************************************************************************************"<<endl;


while(numero!=0){

    cout<<"digite teclado..."<<endl;
    cin>>numero;

switch (numero){
    case 1:
        cout<<"Nome : ";
        cin >>nome;
        cout<<endl;
        cout<<"Genero: ";
        cin>>genero;
        cout<<endl;
        cout<<"taxa 1: ";
        cin>>tax1;
        cout<<endl;
        cout<<"taxa 2: ";
        cin>>tax2;
        cout<<endl;
        cout<<"taxa 3: ";
        cin>>tax3;
        cout<<endl;
        cout<<"taxa 4: ";
        cin>>tax4;
        cout<<endl;

       adicionarPaises(nome,genero,tax1,tax2,tax3,tax4);


    break;

    case 2:
        paisMaiorQntdCasos();

    break;

    case 3:
        paisMenorQntdCasos();
    break;

    case 4:
        mostrarRegistos();
    break;

    case 5:
        ordenarPorCasos();
    break;

    case 6:
        cout<<"Ex. Portugal,China(A primeira letra tem de ser maiscula)"<<endl;
        cout<<"Caso deseje pesquisar por Nome,digite->[1]\nCaso deseje pesquisar por Nome e ano,digite->[2]"<<endl;
        cin>>pesquisa;
        if(pesquisa==1){
            cout<<"digite o nome:"<<endl;
            cin>>nome;
            mostrarCasosPais(nome);}
        if(pesquisa==2){
            cout<<"Digite o nome"<<endl;
            cin>>nome;
            cout<<"digite o ano"<<endl;
            cin>>ano;
            mostrarCasosPais(nome,ano);}
            pesquisa=0;
    break;
    case 7:
        comparar2Paises();
    break;

    case 0:
        cout<<"O programa vai encerrrar"<<endl;
    break;

    default:
        cout<<"O comando nao existe"<<endl;
    break;}}
}



void relatorio::comparar2Paises(){

string nomePais1,nomePais2,generoPais1,generoPais2;
int i=0,indicePais1=0,indicePais2=0;
pessoas p1(" "," ",0,0,0,0);
int encontro1=0,encontro2=0;

cout<<"Digite o Nome do pais"<<endl;
fflush(stdin);
getline(cin,nomePais1);
cout<<"digite o genero"<<endl;
cin>>generoPais1;

cout<<"digite o nome do Pais 2"<<endl;
cin>>nomePais2;
cout<<"digite o genero do pais "<<endl;
cin>>generoPais2;



for(i=0;i<casos.size();i++){
        if(casos[i].get_genero()==generoPais1&&casos[i].get_nomePais()==nomePais1){
        indicePais1=i;
        encontro1=1;}
        if(casos[i].get_genero()==generoPais2&&casos[i].get_nomePais()==nomePais2){
        indicePais2=i;
        encontro2=1;}}


if(encontro1==1&&encontro2==1){
p1=casos[indicePais1]>casos[indicePais2];//funcao que faz uso da sobreCarga de Operadores

cout<<endl<<endl;
cout<<"O pais que teve mais entre<"<<casos[indicePais1].get_nomePais()<<"> e <"<<casos[indicePais2].get_nomePais()<<">"<<endl;
cout<<p1.get_nomePais()<<endl;
cout<<p1.get_genero()<<endl;
p1.mostrarSuicidios();}

else if(encontro1==0){
    cout<<"O pais :"<<nomePais1<<"nao se encontra na lista"<<endl;}

else{
  cout<<"O pais :"<<nomePais2<<"nao se encontra na lista"<<endl;
}}






