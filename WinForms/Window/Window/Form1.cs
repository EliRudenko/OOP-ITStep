using System;
using System.IO;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
    }

    private async void btnCopy_Click(object sender, EventArgs e)
    {
        try
        {
            string sourceFile = txtSourceFile.Text;
            string destinationFile = txtDestinationFile.Text;

            if (string.IsNullOrEmpty(sourceFile) || string.IsNullOrEmpty(destinationFile))
            {
                MessageBox.Show("Please select both source and destination files.");
                return;
            }

            // Запуск асинхронного копирования
            await CopyFileAsync(sourceFile, destinationFile);
        }
        catch (Exception ex)
        {
            MessageBox.Show($"An error occurred: {ex.Message}");
        }
    }

    private async Task CopyFileAsync(string sourceFile, string destinationFile)
    {
        const int bufferSize = 4096;
        long totalBytes = new FileInfo(sourceFile).Length;
        long bytesCopied = 0;

        using (FileStream sourceStream = new FileStream(sourceFile, FileMode.Open, FileAccess.Read))
        using (FileStream destinationStream = new FileStream(destinationFile, FileMode.Create, FileAccess.Write))
        {
            byte[] buffer = new byte[bufferSize];
            int bytesRead;

            while ((bytesRead = await sourceStream.ReadAsync(buffer, 0, buffer.Length)) > 0)
            {
                await destinationStream.WriteAsync(buffer, 0, bytesRead);
                bytesCopied += bytesRead;

                int progress = (int)((bytesCopied * 100) / totalBytes);
                progressBar.Value = progress;
            }
        }

        MessageBox.Show("File copy completed.");
    }

    private void btnSelectSource_Click(object sender, EventArgs e)
    {
        using (OpenFileDialog openFileDialog = new OpenFileDialog())
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txtSourceFile.Text = openFileDialog.FileName;
            }
        }
    }

    private void btnSelectDestination_Click(object sender, EventArgs e)
    {
        using (SaveFileDialog saveFileDialog = new SaveFileDialog())
        {
            if (saveFileDialog.ShowDialog() == DialogResult.OK)
            {
                txtDestinationFile.Text = saveFileDialog.FileName;
            }
        }
    }
}
