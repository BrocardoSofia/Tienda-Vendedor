#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include"Prenda.h"

using namespace std;

class Cotizacion
{
private:
	int numeroID;
	struct tm tiempo;
	string codigoVendedor;
	Prenda* prenda;
	int cantUnidades;
	double calculoCotizacion;

public:
	Cotizacion(int numeroID, string codigoVendedor, Prenda* prenda, int unidades, double precio);
	~Cotizacion() 
	{
		delete prenda;
	};
	int get_numeroID() { return numeroID; }
	int get_dia() { return tiempo.tm_mday; }
	int get_mes() { return tiempo.tm_mon + 1; }
	int get_anio() { return tiempo.tm_year + 1900; }
	int get_hora() { return tiempo.tm_hour; }
	int get_minuto() { return tiempo.tm_min; }
	string get_codigoVendedor() { return codigoVendedor; }
	Prenda* get_prenda() { return prenda; }
	int get_cantUnidades() { return cantUnidades; }
	double get_calculoCotizacion() { return calculoCotizacion; }
	double calcularCotizacion(Prenda* prenda, int cantUnidades, double precio);
};