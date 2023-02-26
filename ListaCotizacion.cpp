#include "ListaCotizacion.h"

ListaCotizacion::~ListaCotizacion() 
{
	NodoCotizacion* aBrorrar = raiz;
	
	while (raiz != NULL)
	{
		raiz = raiz->sig;
		delete aBrorrar;
		aBrorrar = raiz;
	}
}

void ListaCotizacion::cargarLista(Cotizacion* aCargar)
{
	NodoCotizacion* aux = raiz;
	NodoCotizacion* nuevo = crearNodo(aCargar);

	if (aux == NULL)
	{
		raiz = nuevo;
		raiz->sig = NULL;
	}
	else
	{
		while (aux->sig != NULL)
		{
			//busco el ultimo elemento
			aux = aux->sig;
		}
		//encontre el ultimo y enlazo el nuevo nodo al ultimo
		aux->sig = nuevo;
	}
}

int ListaCotizacion::getUltimoId()
{
	int id;
	NodoCotizacion* aux = raiz;

	if (aux == NULL)
	{
		id = 1;
	}
	else
	{
		while (aux->sig != NULL)
		{
			//busco el ultimo elemento
			aux = aux->sig;
		}
		//encontre el ultimo retorno el ID
		id = aux->cotizacion->get_numeroID();
		id++;
	}
	return id;
}

int ListaCotizacion::cantidadDeElementos()
{
	NodoCotizacion* aux = raiz;
	int contador = 0;

	while (aux != NULL)
	{
		contador++;
		aux = aux->sig;
	}

	return contador;
}

Cotizacion* ListaCotizacion::get_cotizacionPos(int pos)
{
	NodoCotizacion* aux = raiz;
	Cotizacion* aEnviar = aux->cotizacion;

	for (int i = 0; i < pos; i++)
	{
		//busco la cotizacion
		aux = aux->sig;
	}

	aEnviar = aux->cotizacion;

	return aEnviar;
}