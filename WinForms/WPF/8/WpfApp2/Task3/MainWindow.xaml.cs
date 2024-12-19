using System.Text;
using System.Text.RegularExpressions;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Task3
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

        private void tb_TextChanged(object sender, TextChangedEventArgs e)
        {
            TextBox tb = sender as TextBox;
            string tbText = Convert.ToString(tb.Text);
            Regex regex = new Regex(@"^-?\d*\,?\d*$");
            if (regex.IsMatch(tbText))
                return;
            tb.Text = string.Empty;
        }

        private void equalBtn_Click(object sender, RoutedEventArgs e)
        {
            TextBox[] textBoxes = [tb1, tb2, tb3, tb4, tb5, tb6, tb7, tb8, tb9];

            if (textBoxes.All(tb => tb.Text.Length == 0))
            {
                tb1.Text = "0,12";
                tb2.Text = "0,74";
                tb3.Text = "2,02";
                tb4.Text = "3,41";
                tb5.Text = "-4,37";
                tb6.Text = "3,12";
                tb7.Text = "-5,32";
                tb8.Text = "8,51";
                tb9.Text = "1,98";
            }

            Task.Delay(2000).Wait();

            double[] tbDigits = new double[textBoxes.Length];
            for (int i = 0; i < textBoxes.Length; i++)
                tbDigits[i] =double.Parse(textBoxes[i].Text);


            double res = (tbDigits[0] * tbDigits[4] * tbDigits[8]) -
                         (tbDigits[0] * tbDigits[5] * tbDigits[7]) -
                         (tbDigits[1] * tbDigits[3] * tbDigits[8]) +
                         (tbDigits[1] * tbDigits[5] * tbDigits[6]) +
                         (tbDigits[2] * tbDigits[3] * tbDigits[7]) -
                         (tbDigits[2] * tbDigits[4] * tbDigits[6]);

            res = Math.Round(res, 2);

            resultTextBlock.Text = res.ToString();

        }
    }
}