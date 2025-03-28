using System;
using System.Windows.Forms;

namespace TicTacToeGame
{
    public partial class TicTacToeForm : Form
    {
        private string[] buttons = new string[9];
        private string currentPlayer = "X";

        public TicTacToeForm()
        {
            InitializeComponent();
        }

        private void ButtonClick(object sender, EventArgs e)
        {
            var button = sender as Button;
            if (button != null && string.IsNullOrEmpty(button.Text))
            {
                button.Text = currentPlayer;
                buttons[Convert.ToInt32(button.Tag)] = currentPlayer;

                if (CheckWin())
                {
                    MessageBox.Show($"{currentPlayer} Wins!");
                    ResetGame();
                }
                else
                {
                    currentPlayer = (currentPlayer == "X") ? "O" : "X";
                }
            }
        }

        private bool CheckWin()
        {
            int[,] winCombinations = new int[,]
            {
                {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
                {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                {0, 4, 8}, {2, 4, 6}
            };

            for (int i = 0; i < 8; i++)
            {
                if (buttons[winCombinations[i, 0]] == currentPlayer &&
                    buttons[winCombinations[i, 1]] == currentPlayer &&
                    buttons[winCombinations[i, 2]] == currentPlayer)
                {
                    return true;
                }
            }
            return false;
        }

        private void ResetGame()
        {
            for (int i = 0; i < 9; i++)
            {
                buttons[i] = null;
            }
            foreach (Control control in Controls)
            {
                if (control is Button)
                {
                    control.Text = string.Empty;
                }
            }
            currentPlayer = "X";
        }
    }
}
