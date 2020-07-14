#include <iostream>
#include <cstring>
#include <string.h>
#include <conio.h>
#include <string>

const int longCad = 20;


using namespace std;

////////// Estructura del verctor ///////////

struct costPro{         //costPro - Costo por cada producto comprado
    char product[longCad + 1];
    int cantidad;                //Variables
    float pric,cost;};

//////////////////////Definicion de funciones//////////////////

void datos(costPro[],int); //Funcion para mostrar  datos del vector
void compra(costPro[],int); //Funcion para mostrar el costo x cada producto
void muestra(costPro[],int); //Funcion para mostrar la factura
float factura(costPro[],int); //Funcion para calcular el total de compra.

///////////////////FUNCION MAIN/////////////////////

int main(){
    int n;

    cout<<"Bienvendio a su programa de procesamiento de factura de compra...";
    cout<<endl;
    cout<<endl;


    cout<<"Por favor ingrese la cantidad de productos que se compraron: "; 
    cin>>n;

    if(n <= 0)
    {
        cout<<endl;
        cout<<"La cantidad de productos no es valida,por favor ingrese una cantidad valida..." << endl << endl;
        cout<<"Cantidad comprada de productos: ";
        cin>>n;
    }

    cin.ignore(100, '\n');
    
    costPro lista[n];
    
    datos (lista,n);
    compra (lista,n);
    muestra (lista,n);

cout<<"El total a pagar por su compra es:   $"<<factura (lista, n);
    
    getch();
    return 0;
}

/////////////////////////////////////////////////Funciones///////////////////////////////////////////

////////Funcion datos
void datos(costPro vector[],int x) 
{
   
    string cad;
for(int i = 0;i< x;i++)

{
   
    cout<<"Por favor ingrese los siguientes datos para calcular su factura: "<<endl;
    cout<<endl;
    cout<<"Nombre del producto: ";

    getline(cin, cad, '\n');
        strncpy(vector[i].product, cad.c_str( ), longCad);
        vector[i].product[longCad]='\0';
    
    cout<<"Cantidad de producto comprado: ";
    cin>>vector[i].cantidad;

 if(vector[i].cantidad <=0)
{
        cout<<endl;
        cout<<"No ha comprado nada, por favor ingrese una cantidad valida..." << endl << endl;

        cout<<"Cantidad de producto comprado: ";
        cin>>vector[i].cantidad;
    }

    
    cout<<"Precio por c/u de producto: ";
    cin>>vector[i].pric;

    while(vector[i].pric <=0)
    {
        cout<<endl;
        cout<<"Ese precio invalido, por favor ingrese una cantidad valida" << endl << endl;

        cout<<"Precio por c/u de producto: ";
        cin>>vector[i].pric;
    }
    cin.ignore(100, '\n');

}

}



////////////////Funcion costo X producto
void compra (costPro vector[],int x)
{ 
    for (int i=0; i<x; i++)
    {
        vector[i].cost = vector[i].cantidad*vector[i].pric;
    }
    
}

//////////////////Funcion muestra de factura
void muestra (costPro vector[],int x){
    cout<<endl;
    cout<<"  Factura de compra: " << endl;
    for (int i=0; i<x; i++)
    {
       cout<< "   Nombre del producto #" << i+1 << " : " << vector[i].product << endl;
       cout<< "   El precio por c/u de producto es:          $" << vector[i].pric << endl;
       cout<< "   La cantidad de unidades compradas de este articulo es:        " << vector[i].cantidad << endl;
       cout<< "   El costo total de la compra es:            $" << vector[i].cost << endl;
 
       cout<<endl;
    }
}

//////////////////Funcion total de compra:
float factura(costPro vector[], int x)

{
    float Total;

    for (int i=0; i<x; i++)
    {
        Total += vector[i].cost;
    }

    return Total;
}

