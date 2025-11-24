#pragma once
#include <string>
#include "utilidades.h"
using namespace std;

void mostrarItems(int dados[5]);

bool obtuvoLlave(int dados[5], int ronda);

void mostrarInventarioSegunLlave( int &llaveGuardada);

int venderGemas(int dados[5], int &monedasAcum, bool gemasVendidas[]);

int venderLlaves(int dados[5], int &monedasAcum, bool descontarLlave, int llaveUsada);

void abrirCofre(int &monedasAcum, int dados[], int ronda, bool cofresAbiertos[], bool gemasVendidas[]);

void buscarTesoros (int &monedasAcum, int &llaveGuardada, int ronda, bool cofresAbiertos[], bool gemasVendidas[], bool &abrioConLlaveGuardada);

void jugarFase2(string &J1, string &J2, int &monedasAcumJ1, int &monedasAcumJ2,bool cofresAbiertosJ1[3], bool cofresAbiertosJ2[3],bool gemasVendidasJ1[3], bool gemasVendidasJ2[3],bool &abrioConLlaveGuardadaJ1, bool &abrioConLlaveGuardadaJ2);
