#include "../include/TablaHash.hpp"

int main()
{
    int tableSize, funcion_dispersion, td, n_bloques, funcion_explororacion;
    std::cout << "tamano de la tabla:" << std::endl;
    std::cin >> tableSize;
    std::cout << "funcion de dispersion: \n"
                 "  1.- Modulo \n"
                 "  2.- Suma \n"
                 "  3.- aleatoria "
              << std::endl;
    std::cin >> funcion_dispersion;
    fDispersion<long> *dispersionFunction;
    switch (funcion_dispersion)
    {
    case 1:
        dispersionFunction = new fD_modulo<long>(tableSize);
        break;
    case 2:
        dispersionFunction = new fD_suma<long>(tableSize);
        break;
    case 3:
        dispersionFunction = new fD_aleatoria<long>(tableSize);
        break;
    default:
        std::cout << "Opcion invalida" << std::endl;
        return 1;
    };
    std::cout << "tecnica de dispersion: \n"
                 "  1.- Abierta \n"
                 "  2.- Cerrada"
              << std::endl;
    std::cin >> td;
    TablaHash<long> *hashTable;
    switch (td)
    {
    case 1:
        hashTable = new TablaHash<long>(tableSize, dispersionFunction);
        break;
    case 2:
        std::cout << "tamano del bloque:" << std::endl;
        std::cin >> n_bloques;
        std::cout << "Seleccione una funcion de exploracion: \n"
                     "  1.- Lineal \n"
                     "  2.- Cuadratica \n"
                     "  3.- Doble dispersion \n"
                     "  4.- Redispersion "
                  << std::endl;
        std::cin >> funcion_explororacion;
        fExplorar<long> *explorationFunction;
        switch (funcion_explororacion)
        {
        case 1:
            explorationFunction = new fE_lineal<long>(tableSize, dispersionFunction);
            break;
        case 2:
            explorationFunction = new fE_cuadratica<long>(tableSize, dispersionFunction);
            break;
        case 3:
            explorationFunction = new fE_doble<long>(tableSize, dispersionFunction);
            break;
        case 4:
            explorationFunction = new fE_redisp<long>(tableSize, dispersionFunction);
            break;
        default:
            std::cout << "Opcion invalida" << std::endl;
            return 1;
        }
        hashTable = new TablaHash<long>(tableSize, dispersionFunction, n_bloques, explorationFunction);
        break;
    default:
        std::cout << "Opcion invalida" << std::endl;
        return 1;
    };

    // Menú
    while (true)
    {
        std::cout << "Seleccione una opcion: \n"
                     "  1.- Insertar \n"
                     "  2.- Buscar \n"
                     "  3.- Salir"
                  << std::endl;
        int opcion;
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:
            std::cout << "introduce el elemento a insertar:" << std::endl;
            long element;
            std::cin >> element;
            hashTable->insert(element);
if (            hashTable->insert(element))
{
            std::cout << "el elemento se ha insertado correctamente:" << std::endl;
}
else{
                std::cout << "el elemento no se pudo insertar:" << std::endl;

}

            break;
        case 2:
            std::cout << "introduce el elemento a buscar:" << std::endl;
            long element3;
            std::cin >> element3;
            if (hashTable->search(element3))
            {
                std::cout << "El elemento se encuentra en la tabla: " << std::endl;
            }
            else
            {
                std::cout << "El elemento se encuentra en la tabla: " << std::endl;
            }
            break;
        case 3:
            return 0;
        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }
    }
    return 0;
}
