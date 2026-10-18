#include <iostream>
#include <windows.h>
#include "Integration.h" // Підключаємо контракт напарниці

// Створюємо просту тестову функцію f(x) = x * x (парабола)
double myTestFunction(double x) {
    return x * x;
}

int main() {
    std::cout << "=== Test Integration Library ===\n\n";

    std::cout << "1. IMPLICIT LINKING (Method: Rectangle)\n";
    // Викликаємо функцію rectangle напряму, бо ми підключили .lib
    double resultImplicit = rectangle(myTestFunction, 0.0, 10.0, 100);
    std::cout << "Integral of x^2 from 0 to 10 (approx): " << resultImplicit << "\n\n";

    std::cout << "2. EXPLICIT LINKING (Method: Simpson)\n";
    
    // Завантажуємо DLL вручну під час виконання програми
    HMODULE hLib = LoadLibraryA("IntegrationLib.dll");
    if (hLib != NULL) {
        // Оголошуємо тип вказівника на функцію simpson
        typedef double(*SimpsonFunc)(MathFunction, double, double, int);
        
        SimpsonFunc explicitSimpson = (SimpsonFunc)GetProcAddress(hLib, "simpson");
        
        if (explicitSimpson != NULL) {
            double resultExplicit = explicitSimpson(myTestFunction, 0.0, 10.0, 100);
            std::cout << "Integral of x^2 from 0 to 10 (approx): " << resultExplicit << "\n";
        } else {
            std::cout << "Error: Could not find 'simpson' function in DLL.\n";
        }
        // Звільняємо бібліотеку з пам'яті
        FreeLibrary(hLib);
    } else {
        std::cout << "Error: Could not load IntegrationLib.dll!\n";
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.get();
    return 0;
}