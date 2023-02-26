#pragma once
#include<iostream>
#include<time.h>
#include "Tienda.h"
#include "IView.h"

using namespace std;

class Presentador
{
private:
	IView* m_view = nullptr;
	Tienda* tiendita;

public:
	Presentador(IView* view);
	~Presentador()
	{
		delete tiendita;
	}
	void inicializarPrendas();
	void mostrarDatosTienda();
	void mostrarDatosVendedor();
	void mostrarHistorialCotizacion();
	void imprimirPrenda(Prenda* prenda);
	void imprimirFecha(int dia, int mes, int anio);
	void imprimirHora(int hora, int minuto);
	void mostrarCotizacion(Cotizacion* aux);
	void cotizar(Prenda* prenda, double precio, int cantidad);
	void mostrarUltimaCotizacion();
	bool verificarCantidad(Prenda* prenda, int cantidad);
};

