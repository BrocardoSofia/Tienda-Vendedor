#pragma once
#include"Cotizacion.h"

class NodoCotizacion
{
public:
	Cotizacion* cotizacion;
	NodoCotizacion* sig;

	NodoCotizacion* crearNodo(Cotizacion* aCargar)
	{
		NodoCotizacion* nuevo = new NodoCotizacion();
		nuevo->cotizacion = aCargar;
		nuevo->sig = NULL;

		return nuevo;
	}
	~NodoCotizacion()
	{
		delete cotizacion;
	}
};