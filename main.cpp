#include <iostream>
#include <cmath>
using namespace std;
unsigned converting(string *code, int a, int b);
int main()
{
    system("cls");
    string *code = new string; // coded sygnal
    cout << "Enter the coded sygnal: ";
    cin >> *code;
    system("cls");
    cout << "Coded signal: " << *code << endl;
    cout << "Inversion: ";

    // Inverting the values of even outputs
    for (int i = 0; i < 8; i++){
        if((i + 1) % 2 == 0)
            (*code)[i] = ((*code)[i] == '1')?
                    '0' : '1';

    }
    cout << *code;

    // determining the sygment number
    unsigned short syg_num = converting(code, 1, 3);
    cout << "\nSygment number: " << syg_num;

    // Calculating the quantization level in the sygment
    unsigned short quant_lvl = converting(code, 4, 7);
    cout << "\nQuantization level: " << quant_lvl << endl;

    /*
     * Getting standart sygnals and sum them,
     * got the amplitude of encoded original sygnal
     */
    float amp_standart_main = 16;
    for (int i = 0; i < syg_num - 1; i++)
        amp_standart_main = amp_standart_main*2;
    float amp = (syg_num == 0)?
            0 : amp_standart_main;
    cout << "Standart signals: "
         << amp_standart_main << " ";

    for (int i = 0; i < 4; i++)
    {
        amp_standart_main /= 2;
        amp += (*code)[i+4] == '1'? amp_standart_main : 0;
        cout << amp_standart_main << "[" << (*code)[i+4] << "] ";
    }
    cout << "\nSignal amplitude: " << amp << " +- " << amp_standart_main / 2;

    delete code;
    return main();
}

unsigned converting(string *code, int a, int b){
    /*
     * This function makes conversation from
     * binary system to decimal
     */
    unsigned quant_lvl = 0;
    for (int i = a; i <= b; i++)
        quant_lvl += ((*code)[i] - '0') * pow(2, b - i);
    return quant_lvl;
}
