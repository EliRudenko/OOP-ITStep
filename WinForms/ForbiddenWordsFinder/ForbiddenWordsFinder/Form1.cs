using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace ForbiddenWordsFinder
{
    public partial class Form1 : Form
    {
        private List<string> forbiddenWords = new List<string>();
        private string selectedFolder = "";

        public Form1()
        {
            InitializeComponent();
        }

        private void BtnAddWord_Click(object sender, EventArgs e)
        {
            string word = txtForbiddenWords.Text.Trim();
            if (!string.IsNullOrEmpty(word) && !forbiddenWords.Contains(word))
            {
                forbiddenWords.Add(word);
                lstForbiddenWords.Items.Add(word);
                txtForbiddenWords.Clear();
            }
        }

        private void BtnLoadForbiddenWords_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                forbiddenWords = File.ReadAllLines(openFileDialog.FileName).ToList();
                lstForbiddenWords.Items.Clear();
                lstForbiddenWords.Items.AddRange(forbiddenWords.ToArray());
            }
        }

        private void BtnSelectFolder_Click(object sender, EventArgs e)
        {
            if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
            {
                selectedFolder = folderBrowserDialog.SelectedPath;
                lblFolderPath.Text = "Выбрана папка: " + selectedFolder;
            }
        }

        private void BtnStart_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(selectedFolder) || forbiddenWords.Count == 0)
            {
                MessageBox.Show("Выберите папку и загрузите запрещённые слова.", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            lstFoundWords.Items.Clear();
            progressBar.Value = 0;
            string[] files = Directory.GetFiles(selectedFolder, "*.txt", SearchOption.AllDirectories);
            progressBar.Maximum = files.Length;

            foreach (string file in files)
            {
                string content = File.ReadAllText(file);
                foreach (string word in forbiddenWords)
                {
                    if (content.IndexOf(word, StringComparison.OrdinalIgnoreCase) >= 0)
                    {
                        lstFoundWords.Items.Add($"{Path.GetFileName(file)}: {word}");
                    }
                }

                progressBar.Value++;
            }
        }

        private void BtnSaveResult_Click(object sender, EventArgs e)
        {
            if (lstFoundWords.Items.Count == 0)
            {
                MessageBox.Show("Нет найденных запрещённых слов.", "Информация", MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            SaveFileDialog saveFileDialog = new SaveFileDialog { Filter = "Text files (*.txt)|*.txt" };
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                File.WriteAllLines(saveFileDialog.FileName, lstFoundWords.Items.Cast<string>());
                MessageBox.Show("Результаты сохранены.", "Успех", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }
    }
}
