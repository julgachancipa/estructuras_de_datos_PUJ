/*
    Pontificia Universidad Javeriana

    2022-3

    Estructuras de datos

    Laura Gonzales
    Victoria Chavarro
    Emma Gachancipa
*/

#include <clocale>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include "genoma.h"

using namespace std;
using std::stoi;

//Funciones 
void ayuda(); 
int cmd(string comando);
bool file_is_empty(ifstream& pFile);
void cargar(string nombre_archivo); 
vector<string> split (string str, char bases);  
void conteo (char byte); 

int numFrec; 
vector< list<char> > secuencias; 

int main()
{
    // genoma infoGenetica;  
    bool salida = true;
    int comand;

    string comando, linea_comando;
    vector<list<char> >::iterator itsec;
    list<char>::iterator itlist;
  
    vector<string> palabras;
    string nombre_archivo;

    cout << "Ingresa comando deseado" << endl;
    cout << "Si no conoces los comandos ingresa: ayuda" << endl; 
  
    do {
        cout << "$ ";
    
        getline(cin, linea_comando);
        palabras = split(linea_comando, ' ');
        comando = palabras[0];
        comand = cmd(comando);

        switch (comand) {

            case 0:
                cout << "Ha salido del programa" << endl;
                break;
        
            case 1:
                cout << "Comando ingresado correctamente" << endl;
                ayuda();
                cout<<"Ingresa comando deseado"<<endl; 
                break;
        
            case 2:
                cout << "  Comando ingresado correctamente"<< endl;
                numFrec=0; 
                if (palabras.size() == 1)
                    cout <<"\nNo ha ingresado el nombre del archivo, \nvuelva a escribir comando"<<endl;
                else if (palabras.size() == 2) {
                    nombre_archivo = palabras[1];
                    cargar(nombre_archivo);
                cout<<endl<<"Ingresa comando deseado"<<endl; 
                } else
                    cout << "\n Los parametros no cumplen con los requisitos del comando";
                break;

            case 3:
                cout << "Comando ingresado correctamente" << endl;
                cout<<"El numero de secuencias que exiten en el archivo es:"<<numFrec<<endl;
                cout<<endl<<"Ingresa comando deseado"<<endl; 
                break;
        
            case 4:
                itsec = secuencias.begin();
                for (int i = 1; i <= numFrec; i++){
                    itlist = itsec->begin();
                    for ( ; itlist != itsec->end(); itlist++)
                    cout<<*itlist; 
                }
                cout << "Comando ingresado correctamente" << endl;
                cout<<"La lista de secuecias es:"; 
                
                cout<<"Ingresa comando deseado"<<endl; 
                break;
        
            case 5:
                cout << "Comando ingresado correctamente" << endl;
                cout<<"Ingresa comando deseado"<<endl; 
                break;
                case 6:
                cout << "Comando ingresado correctamente" << endl;
                cout<<"Ingresa comando deseado"<<endl; 
                break;
                case 7:
                cout << "Comando ingresado correctamente" << endl;
                cout<<"Ingresa comando deseado"<<endl; 
                break;

            case 8:
                if (palabras.size() == 1)
                    cout <<"\nNo ha ingresado el nombre del archivo, \nvuelva a escribir comando"<<endl;
                else if (palabras.size() == 2) {
                    nombre_archivo = palabras[1];
                    cargar(nombre_archivo); 
                cout << "  Comando ingresado correctamente"<< endl;
                    cout<<"Ingresa comando deseado"<<endl; 
                } else
                    cout << "\n Los parametros no cumplen con los requisitos del comando";
                break;

            case 9:
                if (palabras.size() == 1)
                    cout <<"\nNo ha ingresado el nombre del archivo, \nvuelva a escribir comando"<<endl;
                else if (palabras.size() == 2) {
                    nombre_archivo = palabras[1];
                    cargar(nombre_archivo);
                cout << "  Comando ingresado correctamente"<< endl;
                } else
                    cout << "\n Los parametros no cumplen con los requisitos del comando";
                break;

            case 10:
                if (palabras.size() == 1)
                    cout <<"\nNo ha ingresado el nombre del archivo, \nvuelva a escribir comando"<<endl;
                else if (palabras.size() == 2) {
                    nombre_archivo = palabras[1];
                    cargar(nombre_archivo);
                cout << "  Comando ingresado correctamente"<< endl;
                } else
                    cout << "\n Los parametros no cumplen con los requisitos del comando";
                break;

            case 11:
                cout << "Comando ingresado correctamente" << endl;
                break;
                default:
                cout << "El comando no existe" << endl;
                break;
        }
    } while (comand != 0);
}

vector<string> split(string str, char pattern) {

    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;

    while (posFound >= 0) {
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    return results;
}

//Función retorna comandos
int cmd(string comando) {
    if (comando == "ayuda")
        return 1;

    if (comando == "cargar")
        return 2;

    if (comando == "conteo")
        return 3;

    if (comando == "listar_secuencias")
        return 4;

    if (comando == "histograma")
        return 5;

    if (comando == "es_subsecuencia")
        return 6;

    if (comando == "enmascarar")
        return 7;

    if (comando == "guardar")
        return 8;

    if (comando == "codificar")
        return 9;

    if (comando == "decodificar")
        return 10;

    if (comando == "ruta_mas_corta")
        return 11;

    if (comando == "base_remota")
        return 12;

    if (comando == "salir")
        return 0;

    return 13;
}

//Función comando ayuda
void ayuda()
{
    cout << endl << " Lista de comandos: " << endl << endl;
    cout << "  - cargar nombre_archivo " << endl;
    cout << "  - conteo " << endl;
    cout << "  - listar_secuencias " << endl;
    cout << "  - histograma descripcion_secuencia " << endl;
    cout << "  - es_subsecuencia secuencia " << endl;
    cout << "  - enmascarar secuencia " << endl;
    cout << "  - guardar nombre_archivo " << endl;
    cout << "  - codificar nombre_archivo.fabin " << endl;
    cout << "  - decodificar nombre_archivo.fabin " << endl;
    cout << "  - ruta_mas_corta descripcion_secuencia i j x y " << endl;
    cout << "  - base_remota descripcion_secuencia i j " << endl;
    cout << "  - salir " << endl << endl;
}

bool file_is_empty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

//Función comando cargar 
void cargar(string nombre_archivo)
{
    Genoma genoma;

    int n_secuencias = 0;
    int pos;
    string myText, linea_secuencia, descripcion_secuencia;

    cout << endl << "cargando archivo:  " << nombre_archivo << endl;
    ifstream archivo_lectura(nombre_archivo);

    // Verificar si el archivo existe
    if (!archivo_lectura) {
        cout << endl << nombre_archivo << ":    No se encuentra o no puede leerse" << endl;
        return;
    }

    // Verificar si el archivo esta vacio
    if (file_is_empty(archivo_lectura)){
        cout << endl << nombre_archivo << ":    No contiene ninguna secuencia" << endl;
        return;
    }

    // Leer archivo
    while(getline (archivo_lectura, myText))
    {
        if (myText[0] == '>'){

            // obtener descripcion_secuencia
            pos = myText.find(">");
            descripcion_secuencia = myText.substr(pos+1);

            cout << ">>>" << descripcion_secuencia << endl;

            n_secuencias++;

        }
        else
        {
            // Agregar linea de secuencia
            cout << myText << endl << endl;
            linea_secuencia = myText;
            genoma.AgregarLineaSecuencia(descripcion_secuencia, linea_secuencia);
        }
    }
    archivo_lectura.close();
    cout << endl << "Se han cargado " << n_secuencias << " secuencias" << endl;
}


void conteo (char byte) 
{ 
    if(byte == '>')
        numFrec++; 
}  


void listar_secuencias (char byte)
{
    if(byte != '>')
    secuencias[numFrec-1].push_back(byte); 
}


void guardar(string nombre_archivo){
  
    ofstream escritura(nombre_archivo,ios::binary); 

    char byte; 
    escritura.write((char *) &byte, sizeof(char)); 
    escritura.close();
}