#include <iostream>

// Функция для добавления строки в конец двумерного динамического массива

int** addRow(int** array, int& rows, int cols) {
    // Создаем новый массив с дополнительной строкой
    int** newArray = new int* [rows + 1];

    // Копируем данные из старого массива в новый
    for (int i = 0; i < rows; ++i) {
        newArray[i] = array[i];
    }

    // Добавляем новую строку, инициализированную нулями
    newArray[rows] = new int[cols];

    // Удаляем старый массив
    delete[] array;

    // Увеличиваем количество строк
    ++rows;

    return newArray;
}

// Функция для удаления строки из конца двумерного динамического массива

int** removeRow(int** array, int& rows) {
    // Создаем новый массив без последней строки
    int** newArray = new int* [rows - 1];

    // Копируем данные из старого массива в новый
    for (int i = 0; i < rows - 1; ++i) {
        newArray[i] = array[i];
    }

    // Удаляем старый массив
    delete[] array;

    // Уменьшаем количество строк
    --rows;

    return newArray;
}

// Функция для добавления столбца в конец двумерного динамического массива

int** addColumn(int** array, int rows, int& cols) {
    // Создаем новый массив с дополнительным столбцом
    int** newArray = new int* [rows];

    // Копируем данные из старого массива в новый и добавляем нули в конец каждой строки
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[cols] + 1;
        for (int j = 0; j < cols; ++j) {
            newArray[i][j] = array[i][j];
        }
    }

    // Удаляем старый массив
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    // Увеличиваем количество столбцов
    ++cols;

    return newArray;
}

// Функция для удаления столбца из конца двумерного динамического массива

int** removeColumn(int** array, int rows, int& cols) {
    // Создаем новый массив без последнего столбца
    int** newArray = new int* [rows];

    // Копируем данные из старого массива в новый
    for (int i = 0; i < rows; ++i) {
        newArray[i] = new int[cols - 1];
        for (int j = 0; j < cols - 1; ++j) {
            newArray[i][j] = array[i][j];
        }
        delete[] array[i];
    }

    // Удаляем старый массив
    delete[] array;

    // Уменьшаем количество столбцов
    --cols;

    return newArray;
}
