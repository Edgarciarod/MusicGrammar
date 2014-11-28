#include <cstdio>
#include <string>
#include <cstdlib>
#include <map>
#include <iostream>

using std::string;
using std::map;
using std::endl;
using std::cout;

class Musico {
private:
    string partitura;
    const map<char,string> notas = {
            {'A', "440"},
            {'B', "493"},
            {'C', "523"},
            {'D', "587"},
            {'E', "659"},
            {'F', "698"},
            {'G', "783"}
    };

public:
    //Constructor
    Musico(string _partitura)
    {
        partitura = _partitura;
    }

    void toca()
    {
        for(auto& c : partitura)
        {
            string comando;
            comando += "beep -f ";
            comando += notas.at(c);
            comando += " -l 300";

            //cout << comando.c_str() << "\n";

            system( comando.c_str() );
        }
    }
};