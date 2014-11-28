#include <algorithm>
#include <map>
#include <string>
#include <fstream>
#include <queue>
#include <random>
#include <algorithm>

using std::map;
using std::vector;
using std::string;
using std::ifstream;
using std::queue;
using std::pair;
using std::make_pair;

struct regla {
    vector<string> reg;
    vector<int> pesos;
    std::discrete_distribution<int > d;
};

class Generador{
private:
    char axioma;
    string produccion;

    map<char, regla> gramatica;

    std::random_device rd;
    std::mt19937  gen;

    int siguiente_paso(char nodo);
public:

    //Constructor
    Generador(string);

    //el método principal
    string genera(int);
};