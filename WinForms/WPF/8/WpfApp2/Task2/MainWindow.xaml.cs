using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Task2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Button btn = sender as Button;
            textBlock.Text += btn.Content.ToString();
        }

        private void Clear_Click(object sender, RoutedEventArgs e)
        {
            textBlock.Text = string.Empty;
        }

        private void Ok_Click(object sender, RoutedEventArgs e)
        {
            string pin = Convert.ToString(textBlock.Text);
            if (pin != "1111")
                MessageBox.Show("PIN is incorrect","Error",MessageBoxButton.OK,MessageBoxImage.Error);
            else
                MessageBox.Show("PIN is correct");

            textBlock.Text = string.Empty;

        }
    }
}