#include <iostream>
using namespace std;

class Nodo
{
public:
    int info;
    Nodo* sig;
    Nodo* ant;
public:
    Nodo();
    Nodo(int dato);
};

Nodo::Nodo()
{
    info = 0;
    sig = NULL;
    ant = NULL;
}

Nodo::Nodo(int dato)
{
    info = dato;
    sig = NULL;
    ant = NULL;
}

class ListaCircularDoblementeEnlazada
{
private:
    Nodo* raiz;
public:
    ListaCircularDoblementeEnlazada();
    bool esVacia();
    void insertarInicio(int e);
    void insertarFinal(int e);
    int eliminarInicio();
    int eliminarFinal();
    void mostrarLista();
};

ListaCircularDoblementeEnlazada::ListaCircularDoblementeEnlazada() { raiz = NULL; }

bool ListaCircularDoblementeEnlazada::esVacia()
{
    return (raiz == NULL);
}

void ListaCircularDoblementeEnlazada::insertarInicio(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        raiz = nuevo;
        raiz->sig = raiz; // El último nodo apunta al primer nodo
        raiz->ant = raiz; // El primer nodo apunta al último nodo
    }
    else
    {
        Nodo* aux = raiz;
        while (aux->sig != raiz)
        {
            aux = aux->sig;
        }

        nuevo->sig = raiz;
        nuevo->ant = aux;
        raiz->ant = nuevo;
        raiz = nuevo;
        aux->sig = raiz;
    }
}

void ListaCircularDoblementeEnlazada::mostrarLista()
{
    Nodo* aux = raiz;

    if (!esVacia())
    {
        cout << "raiz" << " <--> ";
        do
        {
            cout << aux->info << " <--> ";
            aux = aux->sig;
        } while (aux != raiz);
        cout << "raiz" << endl;
    }
    else
    {
        cout << "\nLa lista está vacía!\n";
    }
}

void ListaCircularDoblementeEnlazada::insertarFinal(int dato)
{
    Nodo* nuevo = new Nodo(dato);

    if (esVacia())
    {
        raiz = nuevo;
        raiz->sig = raiz; // El último nodo apunta al primer nodo
        raiz->ant = raiz; // El primer nodo apunta al último nodo
    }
    else
    {
        Nodo* aux = raiz;
        while (aux->sig != raiz)
        {
            aux = aux->sig;
        }

        nuevo->sig = raiz;
        nuevo->ant = aux;
        aux->sig = nuevo;
        raiz->ant = nuevo;
    }
}

int ListaCircularDoblementeEnlazada::eliminarInicio()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* aux = raiz;

        if (raiz->sig == raiz) // Si solo hay un elemento en la lista
        {
            raiz = NULL;
        }
        else
        {
            Nodo* temp = raiz;
            while (temp->sig != raiz)
            {
                temp = temp->sig;
            }
            raiz = raiz->sig;
            raiz->ant = temp;
            temp->sig = raiz;
        }

        dato = aux->info;
        delete aux;
    }

    return dato;
}

int ListaCircularDoblementeEnlazada::eliminarFinal()
{
    int dato = INT_MAX;

    if (!esVacia())
    {
        Nodo* aux = raiz;

        if (raiz->sig == raiz) // Si solo hay un elemento en la lista
        {
            raiz = NULL;
        }
        else
        {
            Nodo* anterior = NULL;
            while (aux->sig != raiz)
            {
                anterior = aux;
                aux = aux->sig;
            }

            anterior->sig = raiz;
            raiz->ant = anterior;
        }

        dato = aux->info;
        delete aux;
    }

    return dato;
}

int main()
{
    ListaCircularDoblementeEnlazada lista;

    lista.insertarFinal(1);
    lista.insertarFinal(2);
    lista.insertarFinal(3);

    cout << "Lista Circular Doblemente Enlazada:\n";
    lista.mostrarLista();

    return 0;
}

