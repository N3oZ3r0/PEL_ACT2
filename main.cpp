#include<iostream>
#include<conio.h>

using namespace std;

struct nodo {
    float v;
    nodo *sgt;
    nodo *ntr;
};

void EliminarR(float d);

nodo *inicio = nullptr;

int tam() {
    int tam = 1;
    struct nodo *p;
    if (inicio == nullptr) {
        return 0;
    }
    p = inicio->sgt;
    while (p != inicio) {
        tam++;
        p = p->sgt;
    }
    return tam;
}

void Mostrar() {
    struct nodo *p;
    p = inicio;
    if (inicio == nullptr) {
        cout << "\nNo hay nada que imprimir\n";
    } else {
        cout << "\n Imprimiendo valores ... \n";
        while (p->sgt != inicio) {
            cout << float(p->v) << "->";
            p = p->sgt;
        }
        cout << float(p->v) << "\n";
    }
}

void InsertI(float v) {
    struct nodo *p;
    nodo *temp = new nodo;
    temp->v = v;
    if (inicio == nullptr) {
        inicio = temp;
        temp->sgt = inicio;
        temp->ntr = inicio;
    } else {
        p = inicio;
        while (p->sgt != inicio) {
            p = p->sgt;
        }
        p->sgt = temp;
        temp->ntr = p;
        inicio->ntr = temp;
        temp->sgt = inicio;
        inicio = temp;
    }

}

void InsertF(float v) {
    struct nodo *p;
    nodo *temp = new nodo;
    temp->v = v;
    if (inicio == nullptr) {
        inicio = temp;
        temp->sgt = inicio;
        temp->ntr = inicio;
    } else {
        p = inicio;
        while (p->sgt != inicio) {
            p = p->sgt;
        }
        p->sgt = temp;
        temp->ntr = p;
        inicio->ntr = temp;
        temp->sgt = inicio;
    }
}

bool InsertP(float v, int pos) {
    struct nodo *p;
    if (inicio == nullptr || pos == 1) {
        InsertI(v);
        return false;
    } else if (tam() < pos) {
        return true;
    } else if (pos == tam()) {
        InsertF(v);
        return false;
    } else {
        p = inicio;
        for (int i = 1; i < (pos - 1); i++) {
            p = p->sgt;
        }
        if (p != nullptr) {
            nodo *temp = new nodo;
            temp->v = v;
            temp->sgt = p->sgt;
            temp->ntr = p;
            if (p->sgt != nullptr) {
                p->sgt->ntr = temp;
            }
            p->sgt = temp;
            return false;
        }
    }
    return false;
}

void Mayor() {
    float A = 0.0;
    float M = 0.0;
    int R = 0;
    struct nodo *p;
    p = inicio;
    if (inicio == nullptr) {
        cout << "\nNo hay nada que imprimir\n";
    } else if (tam() == 1) {
        A = p->v;
        R++;
    } else {
        while (p->sgt != inicio) {
            A = p->v;
            if (A >= M) {
                if (M < A) {
                    M = A;
                    R = 0;
                }
            }
            if (M == A) {
                R++;
            }
            p = p->sgt;
        }
        A = p->v;
        if (A >= M) {
            if (M < A) {
                M = A;
                R = 0;
            }
        }
        if (M == A) {
            R++;
        }
    }

    cout << "\nEl mayor elemento es " << M << " y se repite " << R << " veces.\n";
}

float Suma() {
    float s = 0.0;
    struct nodo *p;
    p = inicio;
    if (inicio == nullptr) {
        cout << "\nNo hay nada que imprimir\n";
    } else {
        while (p->sgt != inicio) {
            s += p->v;
            p = p->sgt;
        }
        s += p->v;
    }
    return s;
}

void Orden() {
    if (inicio == nullptr) {
        cout << "\nNo hay nada que imprimir\n";
        return;
    }
    struct nodo *p;
    p = inicio;
    while (p->sgt != inicio) {
        if (p->v >= p->sgt->v) {
            cout << "\nLa lista no esta ordenada\n";
            return;
        } else {
            p = p->sgt;
        }
    }
    cout << "\nLa lista esta ordenada\n";

}

void EliminarI(float v) {
    int cont = 0;
    struct nodo *pc;
    pc = inicio;
    while (pc->sgt != inicio) {
        if (pc->v == v) {
            cont++;
        }
        pc = pc->sgt;
    }
    if (pc->v == v) {
        cont++;
    }
    for (int i = cont; i > 0; i--) {
        struct nodo *p;
        p = *&inicio;
        for (int j = 0; j <= tam(); j++) {
            if (p->v == v) {
                if (*&inicio->sgt == *&inicio) {
                    *&inicio = nullptr;
                } else {
                    struct nodo *temp;
                    temp = *&p;
                    if (temp == *&inicio) {
                        *&inicio = *&inicio->sgt;
                    }
                    temp->ntr->sgt = temp->sgt;
                    temp->sgt->ntr = temp->ntr;
                    delete temp;
                }
            }
            p = p->sgt;
        }
    }
    cout << "\nSe han borrado todos los " << float(v) << "!\n";
}

void EliminarR(float v, nodo *p) {
    if (*&inicio->sgt == *&inicio) {
        *&inicio = nullptr;
    } else {
        struct nodo *temp;
        temp = p;
        if (temp == *&inicio) {
            *&inicio = *&inicio->sgt;
        }
        temp->ntr->sgt = temp->sgt;
        temp->sgt->ntr = temp->ntr;
        delete temp;
    }
}

void Invertir() {
    if (inicio == nullptr) {
        cout << "\nNo hay nada que invertir\n";
        return;
    }
    struct nodo *temp;
    temp = inicio;
    while (temp->sgt != inicio) {
        struct nodo *antr = temp->ntr;
        struct nodo *sgte = temp->sgt;
        temp->sgt = antr;
        temp->ntr = sgte;
        temp = temp->ntr;

    }
    struct nodo *antr = temp->ntr;
    struct nodo *sgte = temp->sgt;
    temp->sgt = antr;
    temp->ntr = sgte;

    inicio = temp; //El ultimo nodo ahora es la cabeza de la lista
    temp->ntr = inicio->ntr;
    cout << "\nLista ordenada\n";

}

void Interca(int o, int d) {
    struct nodo *ori, *des;
    ori = des = inicio;

    for (int i = 1; i < o; i++) {
        ori = ori->sgt;
    }
    for (int i = 1; i < d; i++) {
        des = des->sgt;
    }
    float temp = ori->v;
    ori->v = des->v;
    des->v = temp;
    cout << "\nIntercambio realizado\n";

}

int main() {
    int enie = 164;
    int acen_I = 214;
    int acen_a = 160;
    int acen_i = 161;
    int acen_o = 162;
    int acen_u = 163;
    int acen_e = 130;
    int opc = 0;
    bool valido = false;
    bool error = false;
    float v = 0.0;
    int pos = 0;
    int o = 0;
    int d = 0;
    do {
        cout << "\n____________________________________________________________________\n\n";
        cout << " UNIVERSIDAD EUROPEA - ESCUELA DE ARQUITECTURA, INGENIER" << char(acen_I) << "A Y DISE" << char(enie)
             << "O\n";
        cout << "____________________________________________________________________\n\n";
        cout << "\t\t\t\t\t Francisco Af" << char(acen_a) << "n Rodr" << char(acen_i) << "guez\n\n";
        cout << "\t      << PROGRAMA PARA MANIPULAR LISTAS >>\n\n";
        cout << "  ** Seleccione una opci" << char(acen_o) << "n del menu [ 0-10 ] **\n\n";
        cout << "[ 1 ] Mostrar la lista\n[ 2 ] Insertar un elemento al INICIO de la lista\n";
        cout << "[ 3 ] Insertar un elemento al FINAL de la lista\n";
        cout << "[ 4 ] Insertar un elemento en una POSICION elegida por el usuario\n";
        cout << "[ 5 ] Calculo del MAYOR de los elementos y cuantas veces se REPITE\n";
        cout << "[ 6 ] SUMA de todos los datos de la lista\n[ 7 ] Comprobar si la lista est" << char(acen_a)
             << " ORDENADA\n";
        cout << "[ 8 ] ELIMINAR todas las OCURRENCIAS de un elemento dado en la lista\n";
        cout << "[ 9 ] INVERTIR la lista\n[ 10 ] INTERCAMBIAR 2 nodos DADOS en la lista\n[ 0 ] SALIR\n\n";
        cout << "\t     Ingrese su opci" << char(acen_o) << "n ? : ";
        cin >> opc;
        do {
            if (cin.fail()) {
                cout << "\nIntroduzca un n" << char(acen_u) << "mero del [ 0-10 ]: ";
                cin.clear();
                cin.ignore();
                cin >> opc;
            } else {
                valido = true;
            }
        } while (!valido);
        valido = false;
        switch (opc) {
            case 1:
                Mostrar();
                break;
            case 2:
                cout << "\nIndique el valor que quiere a" << char(enie) << "adir: ";
                cin >> v;
                InsertI(v);
                break;
            case 3:
                cout << "\nIndique el valor que quiere a" << char(enie) << "adir: ";
                cin >> v;
                InsertF(v);
                break;
            case 4:
                cout << "\nIndique el valor que quiere a" << char(enie) << "adir: ";
                cin >> v;
                cout << "\nIndique la posici" << char(acen_o) << "n en la que quiere a" << char(enie) << "adir (valor m"
                     << char(acen_i) << "nimo 1): ";
                cin >> pos;
                if (InsertP(v, pos)) {
                    cout << "\nPosici" << char(acen_o) << "n fuera de rango\n";
                }
                cout << "\nElemento a" << char(enie) << "adido\n";
                error = false;
                break;
            case 5:
                Mayor();
                break;
            case 6:
                cout << "\nLa suma de todos los elementos da :" << Suma() << "\n";
                break;
            case 7:
                Orden();
                break;
            case 8:
                cout << "\nIndique el valor que quiere eliminar: ";
                cin >> v;
                cout << "\nIndique el m" << char(acen_e) << "todo con el que quiere eliminar";
                cout << "\nIterativo [1]      Recursivo[2]";
                cout << "\nOpci" << char(acen_o) << "n: ";
                cin >> opc;
                switch (opc) {
                    case 1:
                        EliminarI(v);
                        cout << "\nSe han borrado todos los " << float(v) << "!\n";
                        break;
                    case 2:
                        int cont = 0;
                        struct nodo *pc;
                        pc = inicio;
                        while (pc->sgt != inicio) {
                            if (pc->v == v) {
                                cont++;
                            }
                            pc = pc->sgt;
                        }
                        if (pc->v == v) {
                            cont++;
                        }
                        for (int i = cont; i > 0; i--) {
                            struct nodo *p;
                            p = *&inicio;
                            for (int j = 0; j <= tam(); j++) {
                                if (p->v == v) {
                                    EliminarR(v, p);
                                }
                                p = p->sgt;
                            }
                        }
                        cout << "\nSe han borrado todos los " << float(v) << "!\n";
                        break;
                }
                break;
            case 9:
                Invertir();
                break;
            case 10:
                cout << "\nIntroduzca la posici" << char(acen_o) << "n de origen para intercambiar: ";
                cin >> o;
                cout << "\nIntroduzca la posici" << char(acen_o) << "n de origen para intercambiar: ";
                cin >> d;
                Interca(o, d);
                break;
            case 0:
                cout << "\nAdios\n";
                break;
            default:
                cout << "\nEsta no es una opci" << char(acen_o) << "n valida\n";
                break;
        }
    } while (opc != 0);
}