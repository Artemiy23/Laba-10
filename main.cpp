#include <iostream>
#include <clocale>
#include <fstream>
#include <string> 

using namespace std;
/*
*   Программа получает на вход заданный динамический 
*   массив и осуществляет сдвиг элементов массива вправо 
*   на одну позицию, а первый элемент полученного массива 
*   становится 0.
*/
int main () 
{
    setlocale(LC_ALL, "ru_Ru.utf-8");
    
    size_t size;
    char buf[20];
    double *arr;
    ifstream input("input.txt");

    if (!input.is_open())
    {
        cerr << "Не возможно открыть файл.";
        return 1;
    }
    
    input >> buf;
    size = stod(buf);
    arr = new double[size];

    size_t i = 0;
    while (input >> buf) 
    {
        arr[i] = stod(buf);
        i++;
    }   

    input.close();

    for (size_t i = size-1; i > 0; i--) 
    {
        arr[i] = arr[i-1];
    }
    arr[0] = 0;

    ofstream output("output.txt");

    if (!output.is_open())
    {
        cerr << "Не возможно открыть файл.";
        return 1;
    }

    for (size_t i = 0; i < size; i++) 
    {
        output << arr[i] << ' ';
    }

    output.close();

    delete[] arr;
    return 0;
}