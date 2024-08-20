#ifndef DICCIONARY_H
#define DICCIONARY_H

#include <string>
#include "Commit.h"

using std::string;
using UGit::Commit;

namespace UDiccionary {
	struct Diccionary;

	//Precondicion:Ninguna
	//Postcondicion:Crea una instancia valida de @diccionary
	Diccionary* Create();

	//Precondicion:@diccionary debe ser una instancia valida
	// Postcondicion:Si @key no existe la agrega en @diccionario. Si @key existe reemplaza el valor
	// asociado por @value
	void Insert(Diccionary* diccionary, string key, Commit* value);
	
	//Precondicion:@diccionary es una instancia valida 
	//Postcondicion:Si @key existe en el diccionario, devuelve su @value. Si @key no existe, devuelve NULL
	Commit* Get(Diccionary* diccionary, string key);

	//Precondicion:@diccionary es una instancia valida
	//Postcondicion:Si @key existe en el diccionario, devuelve true.
	bool Contains(Diccionary* diccionary, string key);

	// Precondicion:@diccionary es una instancia valida
	// Postcondicion:Libera todos los recursos asociados a @diccionary
	void Destroy(Diccionary* diccionary);

}

#endif