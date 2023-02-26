#include "Presentador.h"

Presentador::Presentador(IView* view)
{
	m_view = view;
	Tienda* aux = new Tienda("La tiendita", "Colon 2050", "Lucia", "Lopez", "A20Z6");
	tiendita = aux;
	inicializarPrendas();
}

void Presentador::inicializarPrendas()
{
	//cargo prendas
	tiendita->cargarPrendas("pantalon", 750, true, true);//premium - chupin
	tiendita->cargarPrendas("pantalon", 250, true, false);//premium - comun
	tiendita->cargarPrendas("pantalon", 750, false, true);//standard - chupin
	tiendita->cargarPrendas("pantalon", 250, false, false);//standard - comun

	tiendita->cargarPrendas("camisa", 100, true, true, true);//premium - Mao - corta
	tiendita->cargarPrendas("camisa", 75, true, true, false);//premium - Mao - larga
	tiendita->cargarPrendas("camisa", 150, true, false, true);//premium - comun - corta
	tiendita->cargarPrendas("camisa", 175, true, false, false);//premium - comun - larga

	tiendita->cargarPrendas("camisa", 100, false, true, true);//standard - Mao - corta
	tiendita->cargarPrendas("camisa", 150, false, false, true);//standard - comun - corta
	tiendita->cargarPrendas("camisa", 75, false, true, false);//standard - Mao - larga
	tiendita->cargarPrendas("camisa", 175, false, false, false);//standard - comun - larga
}

void Presentador::mostrarDatosTienda()
{
	m_view->espacio();
	m_view->imprimirTextoSinSalto(tiendita->get_nombre());
	m_view->imprimirTextoSinSalto(" | ");
	m_view->imprimirTexto(tiendita->get_direccion());
}

void Presentador::mostrarDatosVendedor()
{
	m_view->espacio();
	m_view->imprimirTextoSinSalto(tiendita->get_vendedor()->get_nombre());
	m_view->espacio();
	m_view->imprimirTextoSinSalto(tiendita->get_vendedor()->get_apellido());
	m_view->imprimirTextoSinSalto(" | ");
	m_view->imprimirTexto(tiendita->get_vendedor()->get_codigoVendedor());
}

void Presentador::imprimirPrenda(Prenda* prenda)
{
	m_view->imprimirTextoSinSalto(prenda->get_tipo());
	m_view->imprimirTextoSinSalto(" - ");

	if (prenda->get_tipo() == "pantalon")
	{
		if (prenda->get_corteChupin())
		{
			m_view->imprimirTextoSinSalto("Corte chupin");
		}
		else
		{
			m_view->imprimirTextoSinSalto("Corte comun");
		}
	}
	else
	{
		if (prenda->get_cuelloMao())
		{
			m_view->imprimirTextoSinSalto("Cuello Mao");
		}
		else
		{
			m_view->imprimirTextoSinSalto("Cuello Comun");
		}

		m_view->imprimirTextoSinSalto(" - ");

		if (prenda->get_mangaCorta())
		{
			m_view->imprimirTextoSinSalto("Manga Corta");
		}
		else
		{
			m_view->imprimirTextoSinSalto("Manga Larga");
		}
	}

	m_view->imprimirTextoSinSalto(" - ");

	if (prenda->get_calidad())
	{
		m_view->imprimirTextoSinSalto("Premium");
	}
	else
	{
		m_view->imprimirTextoSinSalto("Standard");
	}
}

void Presentador::imprimirFecha(int dia, int mes, int anio)
{
	m_view->imprimirNumero(dia);
	m_view->imprimirTextoSinSalto("/");
	m_view->imprimirNumero(mes);
	m_view->imprimirTextoSinSalto("/");
	m_view->imprimirNumero(anio);
}
void Presentador::imprimirHora(int hora, int minuto)
{
	if (hora < 10)
	{
		m_view->imprimirNumero(0);
	}
	
	m_view->imprimirNumero(hora);
	m_view->imprimirTextoSinSalto(":");
	
	if (minuto < 10)
	{
		m_view->imprimirNumero(0);
	}
	m_view->imprimirNumero(minuto);
}

void Presentador::mostrarHistorialCotizacion()
{
	//tomo la cantidad total de elementos en el historial
	int cantidad = tiendita->get_vendedor()->get_historialCotizacion()->cantidadDeElementos();
	Cotizacion* aux;

	for (int i = 0; i < cantidad; i++)
	{
		aux = tiendita->get_vendedor()->get_historialCotizacion()->get_cotizacionPos(i);

		mostrarCotizacion(aux);
	}
}

void Presentador::mostrarCotizacion(Cotizacion* aux)
{
	m_view->imprimirTextoSinSalto(" Numero de identificacion: ............. ");
	m_view->imprimirNumero(aux->get_numeroID());
	m_view->saltoDeLinea();
	m_view->imprimirTextoSinSalto(" Fecha y hora de la cotizacion: ........ ");
	imprimirFecha(aux->get_dia(), aux->get_mes(), aux->get_anio());
	m_view->imprimirTextoSinSalto(" ");
	imprimirHora(aux->get_hora(), aux->get_minuto());
	m_view->saltoDeLinea();
	m_view->imprimirTextoSinSalto(" Codigo del Vendedor: .................. ");
	m_view->imprimirTextoSinSalto(aux->get_codigoVendedor());
	m_view->saltoDeLinea();
	m_view->imprimirTextoSinSalto(" Prenda cotizada: ...................... ");
	imprimirPrenda(aux->get_prenda());
	m_view->saltoDeLinea();
	m_view->imprimirTextoSinSalto(" Precio Unitario: ...................... $");
	m_view->imprimirNumero(aux->get_prenda()->get_precioUnitario());
	m_view->saltoDeLinea();
	m_view->imprimirTextoSinSalto(" Unidades cotizadas: ................... ");
	m_view->imprimirNumero(aux->get_cantUnidades());
	m_view->saltoDeLinea();
	m_view->imprimirTextoSinSalto(" Precio Final: ......................... $");
	m_view->imprimirNumero(aux->get_calculoCotizacion());
	m_view->saltoDeLinea();
	m_view->saltoDeLinea();
}

void Presentador::cotizar(Prenda* prenda, double precio, int cantidad)
{
	tiendita->realizarVenta(prenda, precio, cantidad);
}

void Presentador::mostrarUltimaCotizacion()
{
	Cotizacion* aux;
	int ultimo = tiendita->get_vendedor()->get_historialCotizacion()->cantidadDeElementos();

	aux = tiendita->get_vendedor()->get_historialCotizacion()->get_cotizacionPos(ultimo-1);

	mostrarCotizacion(aux);
}

bool Presentador::verificarCantidad(Prenda* prenda, int cantidad)
{
	bool resultado = tiendita->verificarVenta(prenda, cantidad);

	return resultado;
}