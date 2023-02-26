#include "Cotizacion.h"

Cotizacion::Cotizacion(int numeroID, string codigoVendedor, Prenda* prenda, int unidades, double precio)
{
	__time64_t longTime;
	errno_t err;

	this->numeroID = numeroID;
	this->codigoVendedor = codigoVendedor;
	this->prenda = prenda;
	cantUnidades = unidades;

	//obtengo tiemno como entero 64bit
	_time64(&longTime);

	//conversion a tiempo local
	err = _localtime64_s(&tiempo, &longTime);

	//calculo cotizacion
	calculoCotizacion = calcularCotizacion(prenda, unidades, precio);
}

double Cotizacion::calcularCotizacion(Prenda* prenda, int cantUnidades, double precio)
{
	//obtengo el precio general
	precio = precio * cantUnidades;

	//calculo el descuento por tipo de prenda
	if (prenda->get_tipo() == "pantalon")
	{
		if (prenda->get_corteChupin())
		{
			precio = precio - (precio * 0.12);//si es chupin se rebaja 12%
		}
	}
	else
	{
		if (prenda->get_mangaCorta())
		{
			precio = precio - (precio * 0.1);//si es manga corta se rebaja 10%
		}

		if (prenda->get_cuelloMao())
		{
			precio = precio + (precio * 0.03);//si es cuello mao aumenta 3%
		}
	}

	//aplico si corresponde el aumento por calidad
	if (prenda->get_calidad())
	{
		precio = precio + (precio * 0.3);
	}

	return precio;
}