#include "Generador.h"

Generador::Generador(string archivo_nombre)
{
    ifstream mi_archivo(archivo_nombre);

    produccion = "";
    axioma = 'a';

    gramatica.clear();

    if(mi_archivo.is_open())
    {
        char origen;
        int peso;
        string  sep, destino;
        mi_archivo >> axioma;
        while(mi_archivo >> origen >> sep >> peso >> destino)
        {
            if(destino == "e")
                destino = "";
            gramatica[origen].reg.push_back(destino);
            gramatica[origen].pesos.push_back(peso);
        }
        mi_archivo.close();
    }

    for(auto& ori : gramatica)
    {
        std::discrete_distribution<int > d_tmp(
            ori.second.pesos.begin(), ori.second.pesos.end()
        );

        gramatica[ori.first].d = d_tmp;
    }
}

string Generador::genera(int profundidad)
{
    queue<pair<char, int>> cola;

    cola.push(make_pair(axioma, 0));

    while (not cola.empty())
    {
        char u   = cola.front().first;
        int prof = cola.front().second;
        cola.pop();

        produccion += u;

        int n = siguiente_paso(u);

        if(prof < profundidad)
            for (int i = 0; i < gramatica[u].reg[n].size(); ++i)
            {
                char v = gramatica[u].reg[n][i];
                cola.push(make_pair(v, prof+1));
            }
    }

    return produccion;
}

int Generador::siguiente_paso(char nodo)
{
    return gramatica[nodo].d(gen);
}
