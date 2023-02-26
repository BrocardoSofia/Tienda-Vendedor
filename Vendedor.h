#pragma once
#include<iostream>
#include<string>
#include"ListaCotizacion.h"

using namespace std;

class Vendedor
{
private:
	string nombre;
	string apellido;
	string codigoVendedor;
	ListaCotizacion* historialCotizacion;

public:
	Vendedor(string nombre, string apellido, string codigoVendedor)
	{
		this->nombre = nombre;
		this->apellido = apellido;
		this->codigoVendedor = codigoVendedor;
		historialCotizacion = new ListaCotizacion();
	}

	~Vendedor() 
	{
		delete historialCotizacion;
	}
	string get_nombre() { return nombre; }
	string get_apellido() { return apellido; }
	string get_codigoVendedor() { return codigoVendedor; }
	ListaCotizacion* get_historialCotizacion() { return historialCotizacion; }
};
