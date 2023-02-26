#pragma once
#include<iostream>
#include<string>
#include"Vendedor.h"
#include"Prenda.h"
#include"Pantalon.h"
#include"Camisa.h"
#include<list>

using namespace std;

class Tienda
{
private:
	string nombre;
	string direccion;
	Vendedor* vendedor;
	list<Prenda*>listaPrendas{};

public:
	Tienda(string nombre, string direccion, string nombreVendedor, string apellido, string codigoVendedor);
	~Tienda() 
	{
		delete vendedor;
		listaPrendas.clear();
	}
	Vendedor* get_vendedor() { return vendedor; }
	string get_nombre() { return nombre; }
	string get_direccion() { return direccion; }
	void cargarPrendas(string tipo, int cantidadStock, bool premium, bool cuelloMao, bool mangaCorta);
	void cargarPrendas(string tipo, int cantidadStock, bool premium, bool corteChupin);
	bool verificarVenta(Prenda* prenda, int cantidad);
	bool prendasIguales(Prenda* prenda1, Prenda* prenda2);
	void realizarVenta(Prenda* prenda, double precioUnitario, int unidades);
	void restarStock(Prenda* prenda, int unidades);
};
