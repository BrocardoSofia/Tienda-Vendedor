#pragma once
#include"Prenda.h"

class Pantalon :public Prenda
{
private:
	bool corteChupin;//comun o chupin
public:
	Pantalon(bool corteChupin, bool premium) :Prenda(premium)
	{
		tipo = "pantalon";
		this->corteChupin = corteChupin;
	}

	~Pantalon() {}
	void set_cantidadStock(int cantidadStock) { this->cantidadStock = cantidadStock; }
	void set_precioUnitario(double precioUnitario) { this->precioUnitario = precioUnitario; }
	string get_tipo() { return tipo; }
	bool get_calidad() { return premium; }
	double get_precioUnitario() { return precioUnitario; }
	int get_cantidadStock() { return cantidadStock; }
	bool get_cuelloMao() { return false; }
	bool get_mangaCorta() { return false; }
	bool get_corteChupin() { return corteChupin; }
	void restarStock(int unidades) { cantidadStock -= unidades; }
};