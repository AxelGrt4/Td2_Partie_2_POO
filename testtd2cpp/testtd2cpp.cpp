#include <iostream>
using namespace std;


class Mystring {
private:
    //attributs
    int n;
    char* tab2;


public:

    //constructeurs
    Mystring(int, char*);
    Mystring(const char*);
    Mystring(int);
    Mystring();
    
    
    //destructeur
    ~Mystring();

    //méthodes
    void init();
    void affiche();
    Mystring(const Mystring&);
    Mystring& operator=(const Mystring&);
    void maj();
    void min();
    Mystring concat(Mystring);
};

Mystring::Mystring(int pn, char ptab[]) {
    cout << "\nconstructeur Mystring 1\n";
    n = pn;
    tab2 = new char[n];
    for (int i = 0; i < n; i++) {
        tab2[i] = ptab[i];
    }
    cout << endl;
}

Mystring::Mystring(const char* ptab) {
    cout << "\nConstructeur Mystring 2 \n";
    n = strlen(ptab);
    tab2 = new char[n];
    for (int i = 0; i < n; i++) {
        tab2[i] = ptab[i];
    }
}

Mystring::Mystring(int pn) {
    cout << "\nconstructeur Mystring 3\n";
    n = pn;
    tab2 = new char[n];
    for (int i = 0; i < n; i++) {
        tab2[i] = 0;
    }
}

Mystring::Mystring() {
    cout << "\nConstructeur par défaut\n";
    n = 0;
    tab2 = new char[n];
}




Mystring::Mystring(const Mystring& v) {
    n = v.n;
    tab2 = new char[n];
    cout << "\nconstructeur de recopie\n";
    for (int i = 0; i < n; i++) {
        tab2[i] = v.tab2[i];
    }
}

Mystring::~Mystring() {
    cout << "\nDestructeur Mystring\n";
    delete tab2;
}


Mystring& Mystring::operator=(const Mystring& v)
{
    cout << "\nSurcharge operateur =\n";
    if (this != &v) {
        delete tab2;
        tab2 = new char[n = v.n];
        for (int i = 0; i < n; i++) {
            tab2[i] = v.tab2[i];
        }
    }
    return *this;
}



void Mystring::init() {
    cout << "Saisissez les valeur\n";
    for (int i = 0; i < n; i++) {
        cin >> tab2[i];
    }
    cout << endl;
}


void Mystring::affiche() {
    for (int i = 0; i < n; i++) {
        cout << tab2[i];
    }
    cout << endl;
}

void Mystring::maj() {
    for (int i = 0; i < n; i++) {
        tab2[i] = toupper(tab2[i]);
    }
}

void Mystring::min() {
    for (int i = 0; i < n; i++) {
        tab2[i] = tolower(tab2[i]);
    }
}

Mystring Mystring::concat(Mystring v) {
    char* tab3 = new char[n + v.n];
    for (int i = 0; i < n; i++) {
        tab3[i] = tab2[i];
    }
    for (int i = 0; i < v.n; i++) {
        tab3[n + i] = v.tab2[i];
    }
    tab3[n + v.n] = '\0';
    cout << "tab3 = " << tab3 << endl;
    Mystring res(tab3);
    res.affiche();
    return res;
}



int main()
{
    Mystring s4;
}
