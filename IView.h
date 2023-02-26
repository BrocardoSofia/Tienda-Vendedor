#pragma once
#include<string>

using namespace std;

class IView
{
public:
	virtual void imprimirTexto(string texto) = 0;
	virtual void imprimirTextoSinSalto(string texto) = 0;
	virtual void imprimirNumero(int num) = 0;
	virtual void imprimirNumero(float num) = 0;
	virtual void imprimirNumero(double num) = 0;
	virtual void pantallaPrincipal() = 0;
	virtual void espacio() = 0;
	virtual void saltoDeLinea() = 0;
};