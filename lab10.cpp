// lab10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include <fstream>
#include <string>

using namespace std;
int numOfLenArray() {
    int userLen;
    cout << "Введите длинну масива: ";
    cin >> userLen;
    return userLen;

}


void makeFile(int userlen) {   
    ofstream outputFile("out.txt");
    if (outputFile) {
        cout << "Файл успешно создан!" << "\n";
    }
    else {
        cout << "Создание завершилось ошибкой." << "\n";
        exit(1);
    }
    for (int i = 0; i != userlen; i++) {
        outputFile << rand() << ' ';
    }
    cout << "Запись завершена" << "\n";
    outputFile.close();
}


int* readFile(int userlen) {
    ifstream inputFile("out.txt");  
    int* a = new int[userlen];
    string line;
    int i = 0;
    while (getline(inputFile, line, ' ')) {
        a[i] = stoi(line);
        i++;
    }
    inputFile.close();
    return a;
}


void dynamic_solution_1(int arr_size, int* numbers) {;
    ofstream sol_file("solution.txt");
    for (int i = 0; i < arr_size; i += 2) {
        sol_file << numbers[i] << '\t';
    }
    sol_file << "\n";
    for (int i = 1; i < arr_size; i += 2) {
        sol_file << numbers[i] << '\t'; 
    }
    sol_file.close();
}


int main()
{
    srand(time(0));
    setlocale(LC_ALL, "ru");
    int lenarr = numOfLenArray();
    makeFile(lenarr);
    int* arr = readFile(lenarr);
    cout << "Исходный массив в файле ";
    cout << "\n" << "Ответ в файле ";
    dynamic_solution_1(lenarr, arr);
    delete[] arr;
}
