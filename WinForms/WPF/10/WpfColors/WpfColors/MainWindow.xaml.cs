using System.Collections.Generic;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace WpfColors
{
    public partial class MainWindow : Window
    {
        private Dictionary<string, SolidColorBrush> savedColors = new Dictionary<string, SolidColorBrush>();

        public MainWindow()
        {
            InitializeComponent();
            UpdatePreview();
            BindEvents();
        }

        //ПРИЫЯЗКА!!
        private void BindEvents()
        {
            AlphaSlider.ValueChanged += (s, e) => UpdatePreview();
            RedSlider.ValueChanged += (s, e) => UpdatePreview();
            GreenSlider.ValueChanged += (s, e) => UpdatePreview();
            BlueSlider.ValueChanged += (s, e) => UpdatePreview();

            AlphaCheckBox.Checked += (s, e) => AlphaSlider.IsEnabled = true;
            AlphaCheckBox.Unchecked += (s, e) => AlphaSlider.IsEnabled = false;

            RedCheckBox.Checked += (s, e) => RedSlider.IsEnabled = true;
            RedCheckBox.Unchecked += (s, e) => RedSlider.IsEnabled = false;

            GreenCheckBox.Checked += (s, e) => GreenSlider.IsEnabled = true;
            GreenCheckBox.Unchecked += (s, e) => GreenSlider.IsEnabled = false;

            BlueCheckBox.Checked += (s, e) => BlueSlider.IsEnabled = true;
            BlueCheckBox.Unchecked += (s, e) => BlueSlider.IsEnabled = false;
        }

        //ПЕРВЫЙ
        private void UpdatePreview()
        {
            byte a = (byte)AlphaSlider.Value;
            byte r = (byte)RedSlider.Value;
            byte g = (byte)GreenSlider.Value;
            byte b = (byte)BlueSlider.Value;

            ColorPreview.Background = new SolidColorBrush(Color.FromArgb(a, r, g, b));

            //ЗНАЧЕНИЯ
            AlphaValue.Text = a.ToString();
            RedValue.Text = r.ToString();
            GreenValue.Text = g.ToString();
            BlueValue.Text = b.ToString();

            //Блокировка кнопки
            var colorKey = $"#{a:X2}{r:X2}{g:X2}{b:X2}";
            AddButton.IsEnabled = !savedColors.ContainsKey(colorKey);
        }





        //ДОБАВЛЕНИЕ 
        private void AddButton_Click(object sender, RoutedEventArgs e)
        {
            byte a = (byte)AlphaSlider.Value;
            byte r = (byte)RedSlider.Value;
            byte g = (byte)GreenSlider.Value;
            byte b = (byte)BlueSlider.Value;

            string colorKey = $"#{a:X2}{r:X2}{g:X2}{b:X2}";
            var color = new SolidColorBrush(Color.FromArgb(a, r, g, b));

            if (!savedColors.ContainsKey(colorKey))
            {
                savedColors[colorKey] = color;
                ColorsListBox.Items.Add(new { Key = colorKey, Value = color });
                UpdatePreview();
            }
        }





        //КДАЛЕНИЕ
        private void DeleteButton_Click(object sender, RoutedEventArgs e)
        {
            Button deleteButton = sender as Button;
            string colorKey = deleteButton.Tag.ToString();

            if (savedColors.ContainsKey(colorKey))
            {
                savedColors.Remove(colorKey);
                var itemToRemove = ColorsListBox.Items.Cast<object>().FirstOrDefault(i => ((dynamic)i).Key == colorKey);
                ColorsListBox.Items.Remove(itemToRemove);
                UpdatePreview();
            }
        }
    }
}
