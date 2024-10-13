using System;


/*
//1
class Program
{
    static void Main()
    {
        int[] randomArray = GenerateRandomArray(10, 0, 5);
        Console.WriteLine("Исходный массив: " + string.Join(", ", randomArray));

        int[] compressedArray = CompressArray(randomArray);
        Console.WriteLine("Сжатый массив: " + string.Join(", ", compressedArray));
    }

    static int[] GenerateRandomArray(int size, int min, int max)
    {
        Random rand = new Random();
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = rand.Next(min, max + 1);
        }
        return array;
    }

    static int[] CompressArray(int[] arr)
    {
        int[] compressed = new int[arr.Length];
        int index = 0;

        foreach (int num in arr)
        {
            if (num != 0)
            {
                compressed[index] = num;
                index++;
            }
        }

        for (int i = index; i < compressed.Length; i++)
        { compressed[i] = -1; }

        return compressed;
    }
}
*/

/*
//2
class Program
{
    static void Main()
    {
        int N = 5;
        int[,] spiralMatrix = FillSpiralMatrix(N);

        Console.WriteLine("Матрица, заполненная по спирали:");
        PrintMatrix(spiralMatrix);
    }

    static int[,] FillSpiralMatrix(int N)
    {
        int[,] matrix = new int[N, N];
        int x = N / 2;
        int y = N / 2;
        matrix[x, y] = 1;

        int value = 2;
        int steps = 1;
        while (steps < N)
        {
            // Вверх
            for (int i = 0; i < steps; i++) { matrix[--x, y] = value++; }
            // Влево
            for (int i = 0; i < steps; i++) { matrix[x, --y] = value++; }
            steps++;
            // Вниз
            for (int i = 0; i < steps; i++) { matrix[++x, y] = value++; }
            // Вправо
            for (int i = 0; i < steps; i++) { matrix[x, ++y] = value++; }
            steps++;
        }

        for (int i = 0; i < steps - 1; i++) { matrix[--x, y] = value++; }

        return matrix;
    }

    static void PrintMatrix(int[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                Console.Write(matrix[i, j] + "\t");
            }

            Console.WriteLine();
        }
    }
}
*/

/*
//3
class Program
{
    static void Main()
    {
        int N = 3;
        int M = 4; 
        int[,] matrix = GenerateRandomMatrix(N, M, 0, 100);

        Console.WriteLine("Исходная матрица:");
        PrintMatrix(matrix);

        Console.WriteLine("Введите количество столбцов для сдвига:");
        int shiftAmount = int.Parse(Console.ReadLine());

        Console.WriteLine("Введите направление сдвига (1 - вправо, -1 - влево):");
        int direction = int.Parse(Console.ReadLine());

        int[,] shiftedMatrix = ShiftMatrixColumns(matrix, shiftAmount, direction);

        Console.WriteLine("Матрица после сдвига:");
        PrintMatrix(shiftedMatrix);
    }

    static int[,] GenerateRandomMatrix(int rows, int cols, int min, int max)
    {
        Random rand = new Random();
        int[,] matrix = new int[rows, cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {  matrix[i, j] = rand.Next(min, max + 1); }
        }
        return matrix;
    }

    static int[,] ShiftMatrixColumns(int[,] matrix, int shiftAmount, int direction)
    {
        int rows = matrix.GetLength(0);
        int cols = matrix.GetLength(1);
        int[,] shiftedMatrix = new int[rows, cols];

        shiftAmount = (shiftAmount % cols + cols) % cols;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int newCol = (direction == 1) ? (j + shiftAmount) % cols : (j - shiftAmount + cols) % cols;
                shiftedMatrix[i, newCol] = matrix[i, j];
            }
        }

        return shiftedMatrix;
    }

    static void PrintMatrix(int[,] matrix)
    {
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                Console.Write(matrix[i, j] + "\t");
            }

            Console.WriteLine();
        }
    }
}
*/