#pragma once
#include"Cotizacion.h"
#include"NodoCotizacion.h"

class ListaCotizacion :public NodoCotizacion
{
private:

	NodoCotizacion* raiz;

public:
	ListaCotizacion()
	{
		raiz = NULL;
	}
	~ListaCotizacion();
	void cargarLista(Cotizacion* aCargar);
	int getUltimoId();
	int cantidadDeElementos();
	Cotizacion* get_cotizacionPos(int pos);
};