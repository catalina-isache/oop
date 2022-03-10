#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Matrice_Complexa;

class Numar_Complex {
    friend class Matrice_Complexa;

private:
    double real;
    double imaginar;
public:
    explicit Numar_Complex(double real_ = 0, double imaginar_ = 0) {
        this->real = real_;
        this->imaginar = imaginar_;
    }

    Numar_Complex(Numar_Complex &b) {     ///dc trebuie adresa aici??
        this->real = b.real;
        this->imaginar = b.imaginar;
    }

    ~Numar_Complex() {
        this->real = 0;
        this->imaginar = 0;
    } ///destructor

    void set_numar(double real_, double imaginar_) {
        real = real_;
        imaginar = imaginar_;
    }

    void set_real(double real_) {
        real = real_;
    }

    void set_imaginar(double imaginar_) {
        imaginar = imaginar_;
    }

    double get_real() const {
        return real;
    }

    double get_imaginar() const {
        return imaginar;
    }

    void afisare(std::ostream &os) const {
        if (real != 0) os << real;
        if (imaginar < 0) os << "-";
        else if (real != 0 && imaginar != 0) os << "+";
        if (imaginar != 0) os << "i*" << imaginar;
    }

    double modul() const {
        return sqrt(real * real + imaginar * imaginar);
    }

    Numar_Complex &operator+(const Numar_Complex &b) const {
        Numar_Complex *suma = new Numar_Complex;
        suma->real = real + b.real;
        suma->imaginar = imaginar + b.imaginar;
        return *suma;
    }

    Numar_Complex &operator*(const Numar_Complex &b) const {
        Numar_Complex *produs = new Numar_Complex;
        produs->real = real * b.real - imaginar * b.imaginar;
        produs->imaginar = real * b.imaginar + imaginar * b.real;
        return *produs;
    }

    Numar_Complex &operator/(const Numar_Complex &b) const {
        Numar_Complex *raport = new Numar_Complex;
        raport->real = (real * b.real + imaginar * b.imaginar) / (b.real * b.real + b.imaginar * b.imaginar);
        raport->imaginar = (imaginar * b.real - real * b.imaginar) / (b.real * b.real + b.imaginar * b.imaginar);
        return *raport;
    }

    Numar_Complex &operator=(Numar_Complex &b) {
        this->real = b.real;
        this->imaginar = b.imaginar;
        return *this;
    }

    bool operator!=(Numar_Complex &b) {
        bool ok = 1;
        if (this->real != b.real)
            ok = 0;
        if (this->imaginar != b.imaginar)
            ok = 0;
        return !ok;
    }

    bool operator==(Numar_Complex &b) {
        bool ok = 1;
        if (this->real != b.real)
            ok = 0;
        if (this->imaginar != b.imaginar)
            ok = 0;
        return ok;
    }

    friend std::istream &operator>>(std::istream &is, Numar_Complex &z) {
        cout << "Partea reala:";
        is >> z.real;
        cout << "Partea imaginara:";
        is >> z.imaginar;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, Numar_Complex &z) {
        z.afisare(os);
        return os;
    }
};

class Matrice_Complexa {
private:
    int nr_linii;
    int nr_coloane;
    Numar_Complex **matrice;
public:
    ///constructor initializare cu x
    Matrice_Complexa(Numar_Complex x, int nr_linii_, int nr_coloane_) {
        this->nr_linii = nr_linii_;
        this->nr_coloane = nr_coloane_;
        this->matrice = static_cast<Numar_Complex **>(malloc(nr_linii * sizeof(Numar_Complex *)));
        for (int i = 0; i < nr_linii; i++) {
            this->matrice[i] = static_cast<Numar_Complex *>(calloc(nr_coloane, sizeof(Numar_Complex)));
            for (int j = 0; j < nr_coloane; j++)
                this->matrice[i][j] = x;
        }
    }

    ///constructor initializare simplu
    Matrice_Complexa(int nr_linii_ = 0, int nr_coloane_ = 0) {
        this->nr_linii = nr_linii_;
        this->nr_coloane = nr_coloane_;
        matrice = static_cast<Numar_Complex **>(malloc(nr_linii * sizeof(Numar_Complex *)));
        for (int i = 0; i < nr_linii; i++) {
            matrice[i] = static_cast<Numar_Complex *>(calloc(nr_coloane, sizeof(Numar_Complex)));
        }
    }

    ///constructor copiere
    Matrice_Complexa(Matrice_Complexa &M) {
        this->nr_linii = M.nr_linii;
        this->nr_coloane = M.nr_coloane;
        matrice = static_cast<Numar_Complex **>(malloc(nr_linii * sizeof(Numar_Complex *)));
        for (int i = 0; i < nr_linii; i++) {
            matrice[i] = static_cast<Numar_Complex *>(calloc(nr_coloane, sizeof(Numar_Complex)));
        }
        for (int i = 0; i < nr_linii; i++)
            for (int j = 0; j < nr_coloane; j++)
                this->matrice[i][j] = M.matrice[i][j];
    }

    ///destructor
    ~Matrice_Complexa() {
        delete []matrice;
    }

    ///set si get
    void set_nr_linii(int nr_linii_) {
        nr_linii = nr_linii_;
    }

    void set_nr_coloane(int nr_coloane_) {
        nr_coloane = nr_coloane_;
    }

    int get_nr_linii() const {
        return nr_linii;
    }

    int get_nr_coloane() const {
        return nr_coloane;
    }

    ///operator []
    Numar_Complex *&operator[](const int &index) const {
        return matrice[index];
    }

    Matrice_Complexa &operator=(Matrice_Complexa const &M) {
        this->nr_linii = M.nr_linii;
        this->nr_coloane = M.nr_coloane;
        for (int i = 0; i < nr_linii; i++)
            for (int j = 0; j < nr_coloane; j++)
                this->matrice[i][j] = M.matrice[i][j];
        return *this;
    }

    bool &operator==(Matrice_Complexa const &M) {
        bool ok = 1;
        if (this->nr_linii != M.nr_linii)
            ok = 0;
        if (this->nr_coloane != M.nr_coloane)
            ok = 0;
        if (ok) {
            for (int i = 0; i < nr_linii; i++)
                for (int j = 0; j < nr_coloane; j++)
                    if (this->matrice[i][j] != M.matrice[i][j])
                        ok = 0;
        }
        return ok;
    }

    friend std::istream &operator>>(std::istream &os, Matrice_Complexa &M) {
        cout << "Intoruduceti " << M.nr_linii * M.nr_coloane << " elemente:\n";
        for (int i = 0; i < M.nr_linii; i++) {
            for (int j = 0; j < M.nr_coloane; j++) {
                cout << "Elementul (" << i << "," << j << ")\n";
                os >> M[i][j];
            }
        }
        return os;
    }

    friend std::ostream &operator<<(std::ostream &os, Matrice_Complexa &M) {
        for (int i = 0; i < M.nr_linii; i++) {
            for (int j = 0; j < M.nr_coloane; j++)
                os << M[i][j] << " ";
            os << '\n';
        }
        return os;
    }

    Matrice_Complexa &operator+(Matrice_Complexa &b) {
        Matrice_Complexa *suma = new Matrice_Complexa(b.nr_linii, b.nr_coloane);
        for (int i = 0; i < b.nr_linii; i++)
            for (int j = 0; j < b.nr_coloane; j++)
                suma->matrice[i][j] = this->matrice[i][j] + b[i][j];
        return *suma;
    }

    Matrice_Complexa &operator*(Matrice_Complexa &b) {
        Matrice_Complexa *produs = new Matrice_Complexa(b.nr_linii, b.nr_coloane);
        Numar_Complex temp, x;
        for (int i = 0; i < nr_linii; i++)
            for (int j = 0; j < b.nr_coloane; j++) {
                temp.set_numar(0, 0);
                for (int k = 0; k < nr_coloane; k++) {
                    x = matrice[i][k] * b[k][j];
                    temp = temp + x;
                }
                produs->matrice[i][j] = temp;
            }
        return *produs;
    }

    void citire_n_obiecte(int nr_obiecte, Matrice_Complexa ***n) { ////what is life
        Matrice_Complexa **array;
        array = new Matrice_Complexa *[nr_obiecte];
        for (int i = 0; i < nr_obiecte; ++i) {
            array[i] = new Matrice_Complexa;
            cin >> *this;
            array[i] = this;

        }
        *n = array;
    }

    void afisare_n_obiecte(int nr_obiecte, Matrice_Complexa **array) {
        for (int i = 0; i < nr_obiecte; i++)
            cout << *array[i];
    }
};


void citire_memorare_afisare_n_obiecte(int nr_obiecte, int nr_linii, int nr_coloane) {
    Matrice_Complexa M(nr_linii, nr_coloane);
    Matrice_Complexa **niz;
    M.citire_n_obiecte(nr_obiecte, &niz);
    M.afisare_n_obiecte(nr_obiecte, niz);
}

void meniu() {
    Matrice_Complexa M;
    int operatie;
    cout
            << "Introduceti cifra corespunzatoare intructiunii:\nOprire executie ->0\nInitializare matrice cu numar complex -> 1 \nInitializare matrice ->2 \nSeteaza numarul liniilor si coloanelor matricei M ->3 \n";
    cout
            << "Afla numarul liniilor si coloanelor matricei M -> 4 \nCitire, copiere si afisare matrice -> 5 \nAdunare 2 matrici ->6 \nInmultire 2 matrici ->7 \nCitire, memorare si afisare n matrici ->8 \n";

    while (cin >> operatie) {
        if (operatie == 0)
            break;
        if (operatie == 1) {
            cout << "Introduceti partea reala si imaginara a numarului complex:";
            int x, y;
            cin >> x >> y;
            Numar_Complex z(x, y);
            cout << "Introduceti numarul de linii si de coloane ala matricei:";
            cin >> x >> y;
            Matrice_Complexa M(z, x, y);
        }
        if (operatie == 2) {
            int x, y;
            cout << "Introduceti numarul de linii si de coloane ale matricei:";
            cin >> x >> y;
            Matrice_Complexa M2(x, y);
        }
        if (operatie == 3) {
            int x, y;
            cout << "Introduceti numarul de linii si de coloane ale matricei:";
            cin >> x >> y;
            M.set_nr_linii(x);
            M.set_nr_coloane(y);
        }
        if (operatie == 4) {
            int x, y;
            cout << "Numar linii: " << M.get_nr_linii() << "\nNumar coloane: " << M.get_nr_coloane();
        }
        if (operatie == 5) {
            int x, y;
            cout << "Introduceti numarul de linii si de coloane ale matricei:";
            cin >> x >> y;
            Matrice_Complexa M1(x, y), M2(x, y);
            cin >> M1;
            M2 = M1;
            cout << M2;
        }
        if (operatie == 6) {
            int x, y;
            cout << "Introduceti numarul de linii si de coloane ale matricei:";
            cin >> x >> y;
            Matrice_Complexa M1(x, y), M2(x, y);
            cin >> M1 >> M2;
            cout << M1 + M2;
        }
        if (operatie == 7) {
            int x, y;
            cout << "Introduceti numarul de linii si de coloane ale primei matrici:";
            cin >> x >> y;
            Matrice_Complexa M1(x, y);
            cout << "Introduceti numarul de linii si de coloane ale celei de a doua matrici:";
            cin >> x >> y;
            Matrice_Complexa M2(x, y);
            cin >> M1 >> M2;
            cout << M1 * M2;
        }
        if (operatie == 8) {
            int x, y, z;
            cout << "Introduceti numarul de obiecte, de linii si de coloane ala matricei:";
            cin >> x >> y >> z;
            citire_memorare_afisare_n_obiecte(x, y, z);
        }

    }

}


int main() {
    meniu();
    return 0;
}
