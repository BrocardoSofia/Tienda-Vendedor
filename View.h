#pragma once
#include<iostream>
#include<string>
#include <algorithm>
#include"IView.h"
#include"Presentador.h"

using namespace std;

class View:public IView
{
private:
	Presentador* presentador;
	void menuPrincipal();

public:
	View();
	~View();
	void imprimirTexto(string texto);
	void pantallaPrincipal();
	void espacio() { cout << " "; }
	void saltoDeLinea() { cout << "\n"; }
	void imprimirTextoSinSalto(string texto);
	void imprimirNumero(int num);
	void imprimirNumero(float num);
	void imprimirNumero(double num);
	void historialCotizacion();
	void cotizar();
	void mostrarMenuPrenda();
	void mostrarMenuManga();
	void mostrarMenuCuello();
	void mostrarMenuChupin();
	void mostrarMenuCalidad();
	void mostrarMenuPrecio();
	void mostrarMenuUnidades();
	int elegirTipoPrenda(string paso);
	double ingresarPrecioUnitario();
	int ingresarCantidad();
	void mostrarCotizacion();
	bool stringNumerico(string const& str);
};