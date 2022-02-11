#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
//152 lineas
using namespace std;

struct Nodo{
    float dato;
    Nodo *siguiente;
};

void menu(Nodo *&, int &, float &);
void insertarLista(Nodo *&, float);
void mostrarLista(Nodo *);
void buscarLista(Nodo *, float);
void eliminarNodo(Nodo *&, float);
void eliminarLista(Nodo *&, float &);

int main(){
    Nodo *lista = NULL;
    Nodo *sum;

    int totalDatos = 0;
    float media = 0;
    float varianza = 0; // desviacion estandar

    system("cls");
    menu(lista,totalDatos,media);

    //calculo media
    if(totalDatos > 0)
        media = media/totalDatos;

    sum = lista;

    //hago la sumatoria de la varianza
    while(sum != NULL){
        varianza += (sum->dato - media)*(sum->dato - media);
        sum = sum->siguiente;


    }

    //hago la divicion y la raiz de la operacion
    if(totalDatos >= 2)
        varianza = sqrt((varianza/(totalDatos-1)));

    //muestro los resultados
    if(totalDatos >= 1)
        cout<<"\nLa media es: "<<media<<endl;
    else
        cout<<"No se puede calcular la media"<<endl;

    if(totalDatos >= 2)
        cout<<"La desviacion estandar es: "<<varianza<<endl;
    else
        cout<<"El total de datos es menor a 2, nose puede calcular la desviacion estandar"<<endl;


    getch();
    return 0;
}

//elijo la opcion que se desea hacer
void menu(Nodo *&lista, int &totalDatos, float &media){
    int opcion, nDatos;
    float dato;

    do{
        cout<<"\t -- MENU -- \n";
        cout<<"1. Insertar elemento a la lista"<<endl;
        cout<<"2. Mostrar lista"<<endl;
        cout<<"3. Buscar elemento en la lista"<<endl;
        cout<<"4. Eliminar elemento de la lista"<<endl;
        cout<<"5. Eliminar todos los elementos de la lista"<<endl;
        cout<<"6. Calcular desviacion estandar y salir"<<endl<<endl;

        cout<<"Opcion: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cout<<"Escriba el numero de datos que escribira: ";
            cin>>nDatos;
            totalDatos += nDatos;
    
            for(int i = 0; i<nDatos; i++){
                cout<<"Escriba el dato "<<i+1<<" : ";
                cin>>dato;
                insertarLista(lista,dato);

                media += dato;
            }

            break;
        
        case 2:
            mostrarLista(lista);
            cout<<"Fin de la lista"<<endl;
            break;
        
        case 3:
            cout<<"Digite un numero a buscar: "<<endl;
            cin>>dato;
            buscarLista(lista,dato);
            break;

        case 4:
            cout<<"Escriba elemento a eliminar: ";
            cin>>dato;

            if(totalDatos >= 1){
                totalDatos--;
                media-=dato;
            }
            eliminarNodo(lista,dato);
            break;

        case 5:
            totalDatos = 0;
            media = 0;
            cout<<".: Datos eliminados :. "<<endl;
            while(lista != NULL){
                eliminarLista(lista,dato);
                
                cout<<dato<<" -> ";
            }
            break;

        case 6:
            cout<<"Saliendo..."<<endl;
            break;

        default:
            cout<<"Nose reconoce este comando..."<<endl;
            break;
        }

        system("pause");
        system("cls");
    }while(opcion != 6);


}

//inserto elementos en la lista
void insertarLista(Nodo *&lista, float n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo ->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;

    }

    if(lista == aux1){
        lista = nuevo_nodo;

    }
    else{
        aux2->siguiente = nuevo_nodo;

    }

    nuevo_nodo->siguiente = aux1;

}

//muestro los elementos de la lista ligada
void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;

    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual = actual->siguiente;

    }

}

void buscarLista(Nodo *lista, float n){
    bool band = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual->dato <= n)){
        if(actual->dato == n){
            band = true;
        }
        
        actual = actual->siguiente;

    }

    if(band == true)
        cout<<"El elemento "<<n<<" existe"<<endl;
    else
        cout<<"El elemento "<<n<<" no fue encontrado"<<endl;

}

void eliminarNodo(Nodo *&lista, float n){
    //pregunta si la lista esta vacia
    if(lista != NULL){
        Nodo *auxBorrar;
        Nodo *anterior = NULL;

        auxBorrar = lista;

        //recorer lista
        while((auxBorrar != NULL) && (auxBorrar->dato != n)){
            anterior = auxBorrar;
            auxBorrar = auxBorrar->siguiente;

        }

        //El elemento no se encontro
        if(auxBorrar == NULL){
            cout<<"Elemento no encontrado"<<endl;

        }
        //el primer elemento se eleimina
        else if(anterior == NULL){
            lista = lista->siguiente;
            delete auxBorrar;
            cout<<"Elemento eliminado..."<<endl;
        }

        //el elemento esta en la lista y no es el primer nodo
        else{
            anterior->siguiente = auxBorrar->siguiente;
            delete auxBorrar;
            cout<<"Elemento eliminado..."<<endl;
        }

    }
}

void eliminarLista(Nodo *&lista, float &n){
    Nodo *aux = lista;
    n = aux->dato;

    lista = aux->siguiente;
    delete aux;

}