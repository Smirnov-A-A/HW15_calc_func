/*  Приводится пример трех классов CalcLength, CalcArea, CalcVolume, в которых в виртуальной функции Calc()
возвращается соответственно длина окружности, площадь круга и объем шара.
    Для демонстрации создается функция ShowResult(), в которую передается указатель на базовый класс.
Функция вызывает виртуальную функцию Calc() по указателю. В теле функции ShowResult() неизвестно, экземпляр какого 
класса ей будет передан. Экземпляр будет сформирован во время выполнения.
*/

#include <iostream>


/////////////////////////////////Class CalcLength//////////////////////////////
class CalcLength {

public:
    //Constructor
    CalcLength (double d = 0): m_d(d) {

    }
    //Destructor
    virtual ~CalcLength() {

    }
    //Metod
    virtual double Calc() {
       return 3.14 * m_d;
    }

protected:
    double m_d;
};


/////////////////////////////////Class CalcArea//////////////////////////////
class CalcArea : public CalcLength {

public:
    //Constructor
    CalcArea (double d = 0): CalcLength(d) {

    }
    //Destructor
    virtual ~CalcArea() {

    }
    //Method
    virtual double Calc() override {
        return 3.14 * m_d * m_d / 4;
    }
};


////////////////////////////////Class CalcVolume/////////////////////////////
class CalcVolume : public CalcArea {

public:
    //Constructor
    CalcVolume (double d = 0): CalcArea(d) {

    }
    //Destructor
    virtual ~CalcVolume() {

    }
    //Method
    virtual double Calc() override {
        return 4 * 3.14 * (m_d * m_d * m_d / 8) / 3;
    }
};


//////////////////////////////Function ShowResult///////////////////////////
void ShowResult(CalcLength *pCalc) {

    std::cout << pCalc->Calc() << '\n';
}


////////////////////////////////////Main////////////////////////////////////
int main() {

    CalcLength length(1.0);
    CalcArea area(1.0);
    CalcVolume volume(1.0);

    int op = 0;

    CalcLength *pCalc_l = &length;
    CalcLength *pCalc_a = &area;
    CalcLength *pCalc_v = &volume;

    std::cout << "1 - calculate length" << '\n';
    std::cout << "2 - calculate area" << '\n';
    std::cout << "3 - calculate volume" << '\n';
    std::cout << "0 - exit" << '\n';

    do {
        do {
            std::cout << "Choose operation: ";
            std::cin >> op;
        }
        while (op < 0 || op > 3);

        switch (op) {
            case 0:
                std::cout << "Done!" << '\n';
                break;
            case 1:
                std::cout << "Length = ";
                ShowResult(pCalc_l);
                break;
            case 2:
                std::cout << "Area = ";
                ShowResult(pCalc_a);
                break;
            case 3:
                std::cout << "Volume = ";
                ShowResult(pCalc_v);
                break;
            default:
                break;
        }
    }
    while (op != 0);

    pCalc_l = nullptr;
    pCalc_a = nullptr;
    pCalc_v = nullptr;

    return 0;
}
