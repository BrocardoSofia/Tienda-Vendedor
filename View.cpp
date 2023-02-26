#include "View.h"

View::View()
{
	Presentador* aux = new Presentador(this);
	presentador = aux;
	menuPrincipal();
}

View::~View()
{
	delete presentador;
}

void View::imprimirTexto(string texto)
{
	cout << texto << endl;
}

void View::imprimirTextoSinSalto(string texto)
{
	cout << texto;
}

void View::imprimirNumero(int num)
{
	cout << num;
}

void View::imprimirNumero(float num)
{
	cout << num;
}

void View::imprimirNumero(double num)
{
	cout << num;
}

void View::pantallaPrincipal()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - MENU PRINCIPAL");
	imprimirTexto(" --------------------------------------");
	presentador->mostrarDatosTienda();
	imprimirTexto(" --------------------------------------");
	presentador->mostrarDatosVendedor();
	imprimirTexto(" --------------------------------------");
	imprimirTexto("\n SELECCIONE UNA OPCION DEL MENU:\n");
	imprimirTexto(" 1) Historial de Cotizaciones");
	imprimirTexto(" 2) Realizar Cotizacion");
	imprimirTexto(" 3) Salir\n");
}

void View::historialCotizacion()
{
	int exit = 0;

	presentador->mostrarHistorialCotizacion();
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Preciona 3 para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	do
	{
		cin >> exit;
	} while (exit != 3);
	
}

void View::mostrarMenuPrenda()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona 3 para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 1: Selecciona la prenda a cotizar:");
	imprimirTexto(" 1) Camisa");
	imprimirTexto(" 2) Pantalon");
	imprimirTexto(" ---------------------------------------------------");
}

void View::mostrarMenuManga()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona 3 para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 2.a: Seleccione el tipo de manga");
	imprimirTexto(" 1) Corta");
	imprimirTexto(" 2) Larga");
	imprimirTexto(" ---------------------------------------------------");
}

void View::mostrarMenuCuello()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona 3 para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 2.b: Seleccione el tipo de cuello");
	imprimirTexto(" 1) Mao");
	imprimirTexto(" 2) Comun");
	imprimirTexto(" ---------------------------------------------------");
}

void View::mostrarMenuChupin()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona 3 para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 2: Seleccione el tipo de corte");
	imprimirTexto(" 1) Chupin");
	imprimirTexto(" 2) Comun");
	imprimirTexto(" ---------------------------------------------------");
}

void View::mostrarMenuCalidad()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona 3 para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 3: Seleccione la calidad de la prenda");
	imprimirTexto(" 1) Standard");
	imprimirTexto(" 2) Premium");
	imprimirTexto(" ---------------------------------------------------");
}

void View::mostrarMenuPrecio()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona x para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 4: Ingrese el precio unitario de la prenda");
	imprimirTexto(" ---------------------------------------------------");
}

void View::mostrarMenuUnidades()
{
	system("cls");//limpio pantalla
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" Presiona x para volver al menu principal");
	imprimirTexto(" ---------------------------------------------------");
	imprimirTexto(" PASO 5: Ingrese la cantidad de unidades a cotizar");
	imprimirTexto(" ---------------------------------------------------");
}

void View::cotizar()
{
	int cantidad = 0, opcion, flagCantidad = 0;
	string tipo;
	bool premium = false, cuelloMao = false, mangaCorta = false, chupin = false;
	double precio = 0;
	Prenda* prenda = nullptr;
	
	opcion = elegirTipoPrenda("1");//aca elige el tipo (pantalon o camisa)

	if (opcion != 3)
	{
		if (opcion == 1)
		{
			tipo = "camisa";
			opcion = elegirTipoPrenda("2a");//aca elige la manga

			if (opcion != 3)
			{
				if (opcion == 1)
				{
					mangaCorta = true;
				}
				
				opcion = elegirTipoPrenda("2b");//aca elige el cuello

				if ((opcion != 3) && (opcion == 1))
				{
					cuelloMao = true;
				}
			}
		}
		else
		{
			tipo = "pantalon";

			opcion = elegirTipoPrenda("2");//aca elige si es chupin
			if ((opcion != 3) && (opcion == 1))
			{
				chupin = true;
			}
	
		}

		if (opcion != 3)
		{
			opcion = elegirTipoPrenda("3");//aca elige la calidad

			if (opcion != 3)
			{
				if (opcion == 2)
				{
					premium = true;
				}

				precio = ingresarPrecioUnitario();

				if (precio != -1)
				{
					//genero la prenda
					if (tipo == "pantalon")
					{
						prenda = new Pantalon(chupin, premium);
					}
					else
					{
						prenda = new Camisa(mangaCorta, cuelloMao, premium);
					}

					//ingresa cantidad y se verifica
					do
					{
						cantidad = ingresarCantidad();

						if (cantidad != -1)
						{
							if (presentador->verificarCantidad(prenda, cantidad))
							{
								flagCantidad = 1;
							}
							else
							{
								imprimirTexto(" Error: las unidades ingresadas son mayores a las unidades en stock");
								espacio();
								system("pause");
							}
						}
						else
						{
							flagCantidad = 1;
						}
					} while (flagCantidad == 0);


					if (cantidad != -1)
					{
						//cotizo
						if (tipo == "camisa")
						{
							//cotizo camisa
							presentador->cotizar(prenda, precio, cantidad);
						}
						else
						{
							//cotizo pantalon
							presentador->cotizar(prenda, precio, cantidad);
						}

						//muestro la ultima cotizacion
						mostrarCotizacion();
					}
				}
			}
		}
	}
	//si en algun momento la opcion es 3 sale de la funcion
}

void View::mostrarCotizacion()
{
	system("cls");
	imprimirTexto(" COTIZADOR EXPRESS - COTIZAR");
	imprimirTexto(" ---------------------------------------------------");
	presentador->mostrarUltimaCotizacion();
	imprimirTexto(" ---------------------------------------------------");
	system("pause");
}

double View::ingresarPrecioUnitario()
{
	string entrada;
	double precio;
	int flag = 0;

	do
	{
		mostrarMenuPrecio();
		espacio();
		imprimirTextoSinSalto("$");
		cin >> entrada;
		
		if (stringNumerico(entrada))
		{
			precio = stod(entrada);
			if (precio > 0)
			{
				flag = 1;
			}
			else
			{
				imprimirTexto("Error: el precio debe ser mayor a 0");
				system("pause");
			}
		}
		else if (entrada == "x" || entrada == "X")
		{
			precio = -1;
			flag = 1;
		}
		else
		{
			imprimirTexto("Opcion Invalida");
			system("pause");
		}
	} while (flag == 0);

	return precio;
}

int View::ingresarCantidad()
{
	string entrada;
	int unidades;
	int flag = 0;
	std::string::size_type sz;

	do
	{
		mostrarMenuUnidades();
		espacio();

		cin >> entrada;

		if (stringNumerico(entrada))
		{
			unidades = std::stoi(entrada, &sz);
			if (unidades > 0)
			{
				flag = 1;
			}
			else
			{
				imprimirTexto(" Las unidades deben ser mayores a 0");
			}
		}
		else if (entrada == "x" || entrada == "X")
		{
			flag = 1;
			unidades = -1;
		}
		else
		{
			imprimirTexto("Opcion Invalida");
			system("pause");
		}
	} while (flag == 0);

	return unidades;
}

int View::elegirTipoPrenda(string paso)
{
	char opcion;
	int flag = 0;
	int respuesta;
	do
	{
		if (paso == "1")
		{
			mostrarMenuPrenda();
		}
		else if (paso == "2a")
		{
			mostrarMenuManga();
		}
		else if (paso == "2b")
		{
			mostrarMenuCuello();
		}
		else if (paso == "2")
		{
			mostrarMenuChupin();
		}
		else
		{
			mostrarMenuCalidad();
		}

		espacio();

		cin >> opcion;
		if ((opcion == 49) || (opcion == 50) || (opcion == 51))
		{
			flag = 1;
			if (opcion == 49)
			{
				respuesta = 1;
			}
			else if (opcion == 50)
			{
				respuesta = 2;
			}
			else
			{
				respuesta = 3;
			}
		}
		else
		{
			imprimirTexto("Opcion Invalida");
			system("pause");
		}

	} while (flag == 0);

	return respuesta;
}

void View::menuPrincipal()
{
	char opcion;

	do
	{
		pantallaPrincipal();
		espacio();
		cin >> opcion;
			
		switch (opcion)
		{
		case 49:
			//mostrar historial de cotizaciones
			system("cls");//limpio pantalla
			imprimirTexto(" COTIZADOR EXPRESS - HISTORIAL COTIZACIONES");
			imprimirTexto(" ---------------------------------------------------");
			historialCotizacion();
			break;
		case 50:
			//realizar cotizacion
			cotizar();
			break;
		case 51:
			//salir - muestro mensaje de salida
			break;
		default:
			imprimirTexto("\nPor farvor ingrese un valor valido\n");
			system("pause");//pauso para visualizar el mensaje de error
			break;
		}

	} while (opcion != 51);
	
}

bool View::stringNumerico(string const& str)
{
	//verifica que el string sea un numero
	return !str.empty() && str.find_first_not_of("0123456789.-") == std::string::npos;
}