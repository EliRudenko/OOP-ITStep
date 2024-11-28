using System;
using System.Windows.Forms;

namespace WindowsFormsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            ExecuteTasks();
        }

        private void ExecuteTasks()
        {
            ShowResume();
            PlayGuessNumberGame();
        }

        // Задание 1: Вывод резюме через MessageBox
        private void ShowResume()
        {
            string resume = "Привет! Я программист, занимаюсь разработкой на C# и Windows Forms. " +
                            "Мой опыт позволяет мне создавать сложные и интересные приложения.";
            int messageBoxCount = 3;

            int partLength = resume.Length / messageBoxCount;

            for (int i = 0; i < messageBoxCount; i++)
            {
                string part = resume.Substring(i * partLength, 
                    i == messageBoxCount - 1 ? resume.Length - i * partLength : partLength);

                MessageBox.Show(part, $"Сообщение {i + 1}");
            }

            int averageSymbols = resume.Length / messageBoxCount;
            MessageBox.Show($"Среднее количество символов: {averageSymbols}", "Результат");
        }

        // Задание 2: Игра "Угадай число"
        private void PlayGuessNumberGame()
        {
            bool playAgain;

            do
            {
                int targetNumber = new Random().Next(1, 2001);
                int attempts = 0;
                int min = 1, max = 2000;
                bool guessed = false;

                while (!guessed)
                {
                    attempts++;
                    int guess = (min + max) / 2;

                    DialogResult result = MessageBox.Show(
                        $"Твое число {guess}?\n\nДа - угадал. " +
                        "Нет - уточни: больше или меньше.",
                        "Угадай число",
                        MessageBoxButtons.YesNoCancel,
                        MessageBoxIcon.Question);

                    if (result == DialogResult.Yes)
                    {
                        guessed = true;
                    }
                    else if (result == DialogResult.No)
                    {
                        DialogResult higherOrLower = MessageBox.Show(
                            "Число больше?",
                            "Подсказка",
                            MessageBoxButtons.YesNo,
                            MessageBoxIcon.Question);

                        if (higherOrLower == DialogResult.Yes)
                        {
                            min = guess + 1;
                        }
                        else
                        {
                            max = guess - 1;
                        }
                    }
                    else
                    {
                        MessageBox.Show("Игра отменена.", "Выход", MessageBoxButtons.OK, MessageBoxIcon.Information);
                        return;
                    }
                }

                MessageBox.Show($"Число угадано за {attempts} попыток!", "Результат", MessageBoxButtons.OK, MessageBoxIcon.Information);

                DialogResult playAgainResult = MessageBox.Show(
                    "Хочешь сыграть еще раз?",
                    "Новая игра",
                    MessageBoxButtons.YesNo,
                    MessageBoxIcon.Question);

                playAgain = playAgainResult == DialogResult.Yes;
            } while (playAgain);
        }
    }
}
