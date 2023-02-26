#include "Tienda.h"

Tienda::Tienda(string nombre, string direccion, string nombreVendedor, string apellido, string codigoVendedor)
{
	Vendedor* nuevo = new Vendedor(nombreVendedor, apellido, codigoVendedor);
	vendedor = nuevo;
	this->nombre = nombre;
	this->direccion = direccion;
}

void Tienda::cargarPrendas(string tipo, int cantidadStock, bool premium, bool cuelloMao, bool mangaCorta)
{
	//creo una nueva camisa
	Camisa* aCargar = new Camisa(mangaCorta, cuelloMao, premium);
	aCargar->set_cantidadStock(cantidadStock);

	listaPrendas.push_back(aCargar);//agrego la camisa al final de la lista
}

void Tienda::cargarPrendas(string tipo, int cantidadStock, bool premium, bool corteChupin)
{
	//creo un nuevo pantalon
	Pantalon* aBorrar = new Pantalon(corteChupin, premium);

	aBorrar->set_cantidadStock(cantidadStock);
	listaPrendas.push_back(aBorrar);//agrego el pantalon al final de la lista
}

bool Tienda::verificarVenta(Prenda* prenda, int cantidad)
{
	bool resultado = false;
	for (auto element : listaPrendas)
	{
		//busco que la calidad y el tipo de prenda sean iguales
		if (prendasIguales(prenda, element) && (element->get_cantidadStock() >= cantidad))
		{
			//si son iguales y es stok es mayor a la cantidad a verificar
			resultado = true;
		}
	}
	return resultado;
}

bool Tienda::prendasIguales(Prenda* prenda1, Prenda* prenda2)
{
	bool resultado = false;
	if (prenda1->get_tipo() == prenda2->get_tipo())
	{
		//al ser iguales veo si es pantalon o camisa para seguir comparando
		if (prenda1->get_tipo() == "pantalon")
		{
			if ((prenda1->get_corteChupin() == prenda2->get_corteChupin()) && (prenda1->get_calidad() == prenda2->get_calidad()))
			{
				resultado = true;
			}
		}
		else
		{
			if ((prenda1->get_mangaCorta() == prenda2->get_mangaCorta()) && (prenda1->get_cuelloMao() == prenda2->get_cuelloMao()) && (prenda1->get_calidad() == prenda2->get_calidad()))
			{
				resultado = true;
			}
		}
	}
	return resultado;
}

void Tienda::realizarVenta(Prenda* prenda, double precioUnitario, int unidades)
{
	//obtener el ultimo id
	int id = vendedor->get_historialCotizacion()->getUltimoId();
	prenda->set_precioUnitario(precioUnitario);

	//verificar que se puede cotizar la cantidad de prendas
	if (verificarVenta(prenda, unidades))
	{
		Cotizacion* aCargar = new Cotizacion(id, vendedor->get_codigoVendedor(), prenda, unidades, precioUnitario);
		vendedor->get_historialCotizacion()->cargarLista(aCargar);
		restarStock(prenda, unidades);
	}
}

void Tienda::restarStock(Prenda* prenda, int unidades)
{
	for (auto element : listaPrendas)
	{
		if (prendasIguales(element, prenda))
		{
			element->restarStock(unidades);
		}
	}
}