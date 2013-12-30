#include <iostream>
using namespace std;

class nodo{
	int numero;
	nodo *sig;
	public:
		nodo(int n, nodo *s = NULL){ //Constructor primer nodo
			numero = n;
			sig = s;
		}
		nodo();
		void mostrar();
		void add(nodo s); //Agraga otro nodo a la variable sig
		friend class lista;
};

typedef nodo *pnodo;

void nodo::mostrar(){
	cout << numero << "\n";
}

void nodo::add(nodo s){
	sig = &s;
	this->mostrar();
	s.mostrar();
}

class lista{
	pnodo primero, actual;
	public:
	    //Constructor
		lista(){
			primero = actual = NULL;
		}
		//Detructor: Elimina toda la lista
		~lista(){
			pnodo aux;
			while(primero){
				aux = primero;
				primero = primero->sig;
				delete aux;
			}
			actual = NULL;
		}
		void insertar(int v); //Ingresa un valor en la lista
		void borrar(int v); //Elimina un especifico dato de la lista
		bool vacia(){return primero == NULL;};
		void mostrar(); //Mustra todos los valores de la lista en pantalla
		void siguiente();	//Mueve a actual al sig nodo
		void inicio(){actual = primero;};
		void ultimo();	//Mueve actual a la ultima pos
		bool existeActual();
		int valorActual();
};

void lista::insertar(int v){ //Optimizar
    /*cout << "Insertar";
	pnodo nuevo = primero;
	while(nuevo){
        nuevo = nuevo->sig;
	}
	nuevo->sig = new nodo(v);*/
	if (vacia()){
		primero = new nodo(v, primero);
	}else{
	    pnodo nuevo;
		nuevo = primero;
		while(nuevo->sig){
			nuevo = nuevo->sig;
		}
		nuevo->sig = new nodo(v, nuevo->sig);
	}
}

void lista::borrar(int v){ //Optimizar
    pnodo aux = primero, anterior;
    while(aux){
        if(primero->numero == v){
            aux = primero;
            primero = primero->sig;
            break;
        }
        if(aux->numero == v){
            if(aux->sig == NULL){
                anterior->sig = NULL;
                delete aux;
                break;
            }
            anterior->sig = aux->sig;
            delete aux;
            break;
        }
        anterior = aux;
        aux = aux->sig;
    }
}

void lista::mostrar(){
	inicio();
	cout << "\nLista: ";
	while(actual){
        cout << actual->numero;
        if(actual->sig != NULL){
            cout << " - ";
        }
		siguiente();
	}
	cout << endl;
}

void lista::siguiente(){
	if(actual){
		actual= actual->sig;
	}
}

void lista::ultimo(){
	while(actual->sig){
		siguiente();
	}
}

bool lista::existeActual(){
	return actual != NULL;
}

int lista::valorActual(){
	return actual->numero;
}

int main(){
	lista l;
	l.insertar(99);
	for (int i = 0; i < 20; i++){
		l.insertar(i);
	}
	l.mostrar();
	l.borrar(190);
	l.mostrar();
	lista *l2;
	l2 = &l;
	delete l2;
	//Usar el ~ para eliminar
	//l2->mostrar();
}
