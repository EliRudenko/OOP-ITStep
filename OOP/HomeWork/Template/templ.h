#include <iostream>

template <typename T>
class Matrix 
{
private:
    int rows;
    int cols;
    T** data;

public:
    Matrix(int rows, int cols);//выделяет память под  массив
    Matrix(const Matrix& add); // конструктор коп
    ~Matrix();

    void Im_Keyboard(); // заполнение с клавы
    void Im_Random(); // рандом
    void Print() const;

    //ПЕРЕГРУЗКИ ОПЕРАТОРОВ
    Matrix<T> operator+(const Matrix<T>& add) const; // +
    Matrix<T> operator-(const Matrix<T>& add) const; // -
    Matrix<T> operator*(const Matrix<T>& add) const; // *
    Matrix<T> operator/(const Matrix<T>& add) const; // /

    T findMax() const; //поиск максимума
    T findMin() const; // минимум


    Matrix<T>& operator=(const Matrix<T>& add); // оператор присваивания
};


template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) 
{
    data = new T*[rows];
    for (int i = 0; i < rows; ++i) { data[i] = new T[cols]; }
}

template <typename T>
Matrix<T>::Matrix(const Matrix& add) : rows(add.rows), cols(add.cols) 
{
    data = new T*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        data[i] = new T[cols];
        for (int j = 0; j < cols; ++j) { data[i][j] = add.data[i][j]; }
    }
}

template <typename T>
Matrix<T>::~Matrix() 
{
    for (int i = 0; i < rows; ++i) { delete[] data[i]; }

    delete[] data;
}

template <typename T>
void Matrix<T>::Im_Keyboard() 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        { 
            std::cin >> data[i][j];   
        }
        std::cout << "------" << std::endl; 
    }
    std::cout << std::endl;
}

template <typename T>
void Matrix<T>::Im_Random() 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) { data[i][j] = rand() % 100; }
    }
}

template <typename T>
void Matrix<T>::Print() const 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) { std::cout << data[i][j] << " "; }

        std::cout << std::endl;
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& add) const 
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) { result.data[i][j] = data[i][j] + add.data[i][j]; }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& add) const 
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) { result.data[i][j] = data[i][j] - add.data[i][j]; }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& add) const 
{
    Matrix<T> result(rows, add.cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < add.cols; ++j) 
        {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) { result.data[i][j] += data[i][k] * add.data[k][j]; }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& add) const 
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) { result.data[i][j] = data[i][j] / add.data[i][j]; }
    }
    return result;
}

template <typename T>
T Matrix<T>::findMax() const 
{
    T maxElement = data[0][0];
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (data[i][j] > maxElement) { maxElement = data[i][j]; }
        }
    }
    return maxElement;
}

template <typename T>
T Matrix<T>::findMin() const 
{
    T minElement = data[0][0];
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (data[i][j] < minElement) { minElement = data[i][j]; }
        }
    }
    return minElement;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& add) 
{
    if (this == &add) { return *this; }

    for (int i = 0; i < rows; ++i) { delete[] data[i]; }
    delete[] data;

    rows = add.rows;
    cols = add.cols;
    data = new T*[rows];

    for (int i = 0; i < rows; ++i) 
    {
        data[i] = new T[cols];
        for (int j = 0; j < cols; ++j) { data[i][j] = add.data[i][j]; }
    }

    return *this;
}
