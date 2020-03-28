#ifndef DATA_H
#define DATA_H


class Data
{
public:
    // die Daten (x,y), auf die Worker und MainWindow zugreifen wollen, wobei:
    // - der Lesezugriff von MainWindow nicht durch Schreiben des Workers und
    // - der Schreibzugriff von Worker nicht durch Lesen des MainWindows unterbrochen werden darf
    int x = 0;
    int y = 0;
};

#endif // DATA_H
