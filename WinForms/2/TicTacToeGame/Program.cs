using System;
using System.Windows.Forms;

namespace TicTacToeGame
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            // Включаем визуальные стили и устанавливаем параметры совместимости
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            
            // Запускаем форму "TicTacToeForm"
            Application.Run(new TicTacToeForm());
        }
    }
}
