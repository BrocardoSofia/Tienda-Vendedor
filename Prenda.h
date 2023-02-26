#pragma once
#include<iostream>
#include<string>

using namespace std;

//clase abstracta
class Prenda
{
protected:
	string tipo;//pantalon o camisa
	bool premium; //premium o standard
	double precioUnitario;
	int cantidadStock;

public:
	Prenda(bool premium)
	{
		this->premium = premium;
		this->precioUnitario = 0;
		this->cantidadStock = 0;
	}
	virtual ~Prenda() = default;

	virtual void set_cantidadStock(int cantidadStock) = 0;
	virtual void set_precioUnitario(double precioUnitario) = 0;
	virtual string get_tipo() = 0;
	virtual bool get_calidad() = 0;
	virtual double get_precioUnitario() = 0;
	virtual int get_cantidadStock() = 0;
	virtual bool get_cuelloMao() = 0;
	virtual bool get_mangaCorta() = 0;
	virtual bool get_corteChupin() = 0;
	virtual void restarStock(int unidades) = 0;
};