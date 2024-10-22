using System;


namespace TicTacToeGame
{
    class Board
    {
        public char[,] grid = new char[3, 3];
        
        public Board()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i, j] = '-';
                }
            }
        }
        public void PrintBoard()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Console.Write(grid[i, j] + " ");
                }
                Console.WriteLine();
            }
        }



        public bool CheckWin(char player)
        {
            for (int i = 0; i < 3; i++)
            {
                if (grid[i, 0] == player && grid[i, 1] == player && grid[i, 2] == player) return true;
                if (grid[0, i] == player && grid[1, i] == player && grid[2, i] == player) return true;
            }
            if (grid[0, 0] == player && grid[1, 1] == player && grid[2, 2] == player) return true;
            if (grid[0, 2] == player && grid[1, 1] == player && grid[2, 0] == player) return true;
            return false;
        }


        public bool IsDraw()
        {
            foreach (var cell in grid)
            {
                if (cell == '-') return false;
            }
            return true;
        }



        public bool IsValidMove(int row, int col)
        {
            return row >= 0 && row < 3 && col >= 0 && col < 3 && grid[row, col] == '-';
        }
    }




    namespace Players
    {
        class Player
        {
            public char symbol;
            
            public Player(char symbol)
            {
                this.symbol = symbol;
            }


            public virtual void MakeMove(Board board)
            {
                Console.WriteLine($"Игрок {symbol}, ваш ход! Введите номер строки и столбца (0, 1, 2): ");
                int row = int.Parse(Console.ReadLine());
                int col = int.Parse(Console.ReadLine());

                while (!board.IsValidMove(row, col))
                {
                    Console.WriteLine("Неверный ход! Попробуйте снова: ");
                    row = int.Parse(Console.ReadLine());
                    col = int.Parse(Console.ReadLine());
                }

                board.grid[row, col] = symbol;
            }
        }




        class Computer : Player
        {
            Random random = new Random();
            
            public Computer(char symbol) : base(symbol) {}



            public override void MakeMove(Board board)
            {
                int row, col;
                do
                {
                    row = random.Next(0, 3);
                    col = random.Next(0, 3);

                } while (!board.IsValidMove(row, col));

                Console.WriteLine($"Компьютер {symbol} сделал ход: {row}, {col}");
                board.grid[row, col] = symbol;
            }
        }
    }





    class Program
    {
        static void Main(string[] args)
        {
            Board board = new Board();
            Players.Player player1, player2;

            Random random = new Random();
            bool isPlayer1Turn = random.Next(0, 2) == 0;


            Console.WriteLine("Выберите режим игры: 1 - Игрок против компьютера, 2 - Игрок против игрока");
            int mode = int.Parse(Console.ReadLine());

            if (mode == 1)
            {
                player1 = new Players.Player('X');
                player2 = new Players.Computer('O');
            }
            else
            {
                player1 = new Players.Player('X');
                player2 = new Players.Player('O');
            }

            bool gameRunning = true;
            while (gameRunning)
            {
                board.PrintBoard();

                if (isPlayer1Turn)
                {
                    player1.MakeMove(board);
                    if (board.CheckWin(player1.symbol))
                    {
                        Console.WriteLine("Игрок X победил!");
                        gameRunning = false;
                    }
                }
                else
                {
                    player2.MakeMove(board);
                    if (board.CheckWin(player2.symbol))
                    {
                        Console.WriteLine(mode == 1 ? "Компьютер O победил!" : "Игрок O победил!");
                        gameRunning = false;
                    }
                }

                if (board.IsDraw())
                {
                    Console.WriteLine("Ничья!");
                    gameRunning = false;
                }

                isPlayer1Turn = !isPlayer1Turn;
            }

            board.PrintBoard();
        }
    }
}
