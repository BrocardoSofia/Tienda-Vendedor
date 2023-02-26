#pragma once
#include"Prenda.h"

class Camisa :public Prenda
{
private:
	bool mangaCorta;//corta o larga
	bool cuelloMao;//mao o comun

public:
	Camisa(bool mangaCorta, bool cuelloMao, bool premium) :Prenda(premium)
	{
		tipo = "camisa";
		this->mangaCorta = mangaCorta;
		this->cuelloMao = cuelloMao;
	}

	~Camisa() {}

	void set_cantidadStock(int cantidadStock) { this->cantidadStock = cantidadStock; }
	void set_precioUnitario(double precioUnitario) { this->precioUnitario = precioUnitario; }
	string get_tipo() { return tipo; }
	bool get_calidad() { return premium; }
	double get_precioUnitario() { return precioUnitario; }
	int get_cantidadStock() { return cantidadStock; }
	bool get_cuelloMao() { return cuelloMao; }
	bool get_mangaCorta() { return mangaCorta; }
	bool get_corteChupin() { return false; }
	void restarStock(int unidades) { cantidadStock -= unidades; }
};