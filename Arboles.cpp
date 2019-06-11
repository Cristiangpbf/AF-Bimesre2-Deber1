#include <iostream>

using namespace std;

struct Nodo{
        int dato;
        Nodo *derecho;
        Nodo *izquierdo;
    };

Nodo *crearNodosPadreHijos(int n); //n es igual al valor del dato del nodo

Nodo *arbolBinario=NULL;

void insertarNodosArbolBinario(Nodo *&arbolBinario, int n);

void mostrarArbolBinario(Nodo *arbolBinario, int separador);

void pre_orden (Nodo *&arbolBinario);

void in_orden (Nodo *&arbolBinario);

void post_orden (Nodo *&arbolBinario);


int main(){
    int n;
    for (int i=0; i<9; i++){
        cout<<"Insertar los elementos  ";
        cin>>n;
        insertarNodosArbolBinario(arbolBinario,n);
    }
    mostrarArbolBinario(arbolBinario,0);
    cout<<"\n pre-orden:  "<<endl;
    pre_orden(arbolBinario);
    cout<<"\n in-orden:  "<<endl;
    in_orden(arbolBinario);
   	cout<<"\n post-orden:  "<<endl;
    post_orden(arbolBinario);
   
    return 0;
}


Nodo *crearNodosPadreHijos(int n){
    Nodo *nuevo= new Nodo();
    nuevo -> dato=n;
    nuevo -> derecho=NULL;
    nuevo -> izquierdo=NULL;
    return nuevo;
}


void insertarNodosArbolBinario(Nodo *&arbolBinario, int n){
    if (arbolBinario==NULL){
        Nodo *nuevo = crearNodosPadreHijos(n);
        arbolBinario = nuevo;
    }else{
        int datoRaiz=arbolBinario -> dato;

        if(n<datoRaiz){
            insertarNodosArbolBinario(arbolBinario->izquierdo, n);
        }else{
            insertarNodosArbolBinario(arbolBinario->derecho, n);
        }
    }
}


void mostrarArbolBinario(Nodo *arbolBinario, int separador){
    if (arbolBinario==NULL){
        return;
    }else{
        mostrarArbolBinario(arbolBinario->derecho, separador +1);
        for(int i=0; i<=separador;i++){
            cout<<"     ";
        }
        cout<<arbolBinario ->dato<<endl;
        mostrarArbolBinario(arbolBinario->izquierdo, separador+1);
    }
}


void pre_orden (Nodo *&arbolBinario)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
        cout<<arbolBinario->dato<<"-";
        pre_orden(arbolBinario->izquierdo);
        pre_orden(arbolBinario->derecho);
    }    
}


void in_orden (Nodo *&arbolBinario)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
    	in_orden(arbolBinario->izquierdo);
        cout<<arbolBinario->dato<<"-";        
        in_orden(arbolBinario->derecho);
    }
}


void post_orden (Nodo *&arbolBinario)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
        post_orden(arbolBinario->izquierdo);
        post_orden(arbolBinario->derecho);
        cout<<arbolBinario->dato<<"-";        
    }
}