using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Effects;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace WPFKeyboard
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        string textToCompare = "Lorem ipsum odor amet, consectetuer adipiscing elit. Eleifend" +
            " molestie ornare conubia eget ut orci est litora molestie. Ullamcorper tincidunt hac enim" +
            " suspendisse consequat mauris auctor fusce egestas. Potenti" +
            " suspendisse dolor auctor himenaeos magna. Massa diam elit diam torquent curae at." +
            " Dolor nullam lorem finibus felis duis consectetur mollis. Egestas aliquet parturient" +
            " tempus fermentum suspendisse mattis dapibus. Elementum diam aptent natoque malesuada" +
            " habitasse per erat. Diam nisi ligula pulvinar neque venenatis augue venenatis dis." +
            " Ornare imperdiet proin eu; commodo hac ante? Eget convallis lacus feugiat accumsan in." +
            " Conubia imperdiet class nostra senectus erat ante rutrum felis. Vulputate aliquam est at;" +
            " curabitur dui aenean massa odio velit? Viverra dapibus aptent dis vitae pellentesque torquent." +
            " Dapibus praesent diam donec suscipit purus penatibus. Nunc eleifend ultricies venenatis semper" +
            " consequat maximus donec inceptos. Adipiscing risus vitae duis maecenas praesent dui. Metus" +
            " magna pulvinar nisi habitasse placerat. Lacinia eros sodales vestibulum sagittis gravida interdum" +
            " magnis cubilia. Curabitur sem himenaeos faucibus molestie cras at taciti eu lobortis." +
            " Magna bibendum taciti condimentum adipiscing rutrum purus amet molestie. Mi montes natoque" +
            " ultrices velit nascetur viverra sapien. Malesuada nec quisque interdum fusce sem magnis platea." +
            " Dictum iaculis nisi odio, a vehicula praesent." +
            " Facilisi phasellus vivamus sit sapien ligula imperdiet potenti sed." +
            " Cras nostra pellentesque interdum, finibus ut nam nisl. Lectus suspendisse facilisis urna vestibulum facilisi dis" +
            " nullam. Tortor dignissim rutrum facilisi lectus et quis egestas? Aenean mattis varius hac parturient aptent nulla" +
            " tempor dictum. Non nascetur massa ligula tincidunt cubilia. Lectus interdum ligula amet tincidunt aptent, proin" +
            " hendrerit elit. Laoreet finibus sit adipiscing habitant venenatis massa odio tempor. Convallis facilisi aenean;" +
            " congue nec sagittis euismod? Scelerisque metus netus ex litora dis, per integer erat. Tincidunt class eu placerat" +
            " tincidunt egestas. Cursus a pellentesque per lacinia venenatis fusce convallis nascetur?\r\n\r\nLuctus feugiat id" +
            " nibh sagittis integer diam velit finibus suscipit. Dis accumsan lobortis adipiscing scelerisque imperdiet accumsan." +
            " Vestibulum ante dictum odio sociosqu elit semper morbi. Felis vel massa suspendisse porttitor inceptos ex molestie." +
            " Primis habitasse mollis interdum interdum lacus semper. Diam felis cubilia arcu hendrerit sed porttitor.";

        bool isStarted = false;
        DispatcherTimer timer = new();
        int seconds = 0; /*int textInd = 0;*/ int caretInd = 0; int fails = 0;int speed = 0; int success = 0;
        Color successColor = Color.FromRgb(0, 255, 0);
        Color failColor = Color.FromRgb(255, 0, 0);
        Dictionary<Key,TextBlock> textBlockKeyPairs;
        public MainWindow()
        {
            InitializeComponent();
            printingPanel.Text = textToCompare;
            Title = "Keyboard Trainer";
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += Timer_Tick;
            stopButton.IsEnabled = false;
            textBlockKeyPairs = new Dictionary<Key, TextBlock>();
            InitializeDictionary();
        }

        private void InitializeDictionary()
        {
            textBlockKeyPairs.Add(Key.OemTilde, TextBlockTilde);
            textBlockKeyPairs.Add(Key.D1, TextBlockExclamation);
            textBlockKeyPairs.Add(Key.D2, TextBlockAt);
            textBlockKeyPairs.Add(Key.D3, TextBlockHash);
            textBlockKeyPairs.Add(Key.D4, TextBlockDollar);
            textBlockKeyPairs.Add(Key.D5, TextBlockPercent);
            textBlockKeyPairs.Add(Key.D6, TextBlockCaret);
            textBlockKeyPairs.Add(Key.D7, TextBlockAmpersand);
            textBlockKeyPairs.Add(Key.D8, TextBlockAsterisk);
            textBlockKeyPairs.Add(Key.D9, TextBlockLeftParenthesis);
            textBlockKeyPairs.Add(Key.D0, TextBlockRightParenthesis);
            textBlockKeyPairs.Add(Key.OemMinus, TextBlockUnderscore);
            textBlockKeyPairs.Add(Key.OemPlus, TextBlockPlus);
            textBlockKeyPairs.Add(Key.Back, TextBlockBackspace);

            textBlockKeyPairs.Add(Key.Tab, TextBlockTab);
            textBlockKeyPairs.Add(Key.Q, TextBlockQ);
            textBlockKeyPairs.Add(Key.W, TextBlockW);
            textBlockKeyPairs.Add(Key.E, TextBlockE);
            textBlockKeyPairs.Add(Key.R, TextBlockR);
            textBlockKeyPairs.Add(Key.T, TextBlockT);
            textBlockKeyPairs.Add(Key.Y, TextBlockY);
            textBlockKeyPairs.Add(Key.U, TextBlockU);
            textBlockKeyPairs.Add(Key.I, TextBlockI);
            textBlockKeyPairs.Add(Key.O, TextBlockO);
            textBlockKeyPairs.Add(Key.P, TextBlockP);
            textBlockKeyPairs.Add(Key.OemOpenBrackets, TextBlockLeftBrace);
            textBlockKeyPairs.Add(Key.OemCloseBrackets, TextBlockRightBrace);
            textBlockKeyPairs.Add(Key.OemPipe, TextBlockPipe);

            textBlockKeyPairs.Add(Key.Capital, TextBlockCapsLock);
            textBlockKeyPairs.Add(Key.A, TextBlockA);
            textBlockKeyPairs.Add(Key.S, TextBlockS);
            textBlockKeyPairs.Add(Key.D, TextBlockD);
            textBlockKeyPairs.Add(Key.F, TextBlockF);
            textBlockKeyPairs.Add(Key.G, TextBlockG);
            textBlockKeyPairs.Add(Key.H, TextBlockH);
            textBlockKeyPairs.Add(Key.J, TextBlockJ);
            textBlockKeyPairs.Add(Key.K, TextBlockK);
            textBlockKeyPairs.Add(Key.L, TextBlockL);
            textBlockKeyPairs.Add(Key.OemSemicolon, TextBlockSemicolon);
            textBlockKeyPairs.Add(Key.OemQuotes, TextBlockQuote);
            textBlockKeyPairs.Add(Key.Return, TextBlockEnter);

            textBlockKeyPairs.Add(Key.LeftShift, TextBlockShiftLeft);
            textBlockKeyPairs.Add(Key.Z, TextBlockZ);
            textBlockKeyPairs.Add(Key.X, TextBlockX);
            textBlockKeyPairs.Add(Key.C, TextBlockC);
            textBlockKeyPairs.Add(Key.V, TextBlockV);
            textBlockKeyPairs.Add(Key.B, TextBlockB);
            textBlockKeyPairs.Add(Key.N, TextBlockN);
            textBlockKeyPairs.Add(Key.M, TextBlockM);
            textBlockKeyPairs.Add(Key.OemComma, TextBlockLessThan);
            textBlockKeyPairs.Add(Key.OemPeriod, TextBlockGreaterThan);
            textBlockKeyPairs.Add(Key.OemQuestion, TextBlockQuestionMark);
            textBlockKeyPairs.Add(Key.RightShift, TextBlockShiftRight);

            textBlockKeyPairs.Add(Key.LeftCtrl, TextBlockCtrlLeft);
            textBlockKeyPairs.Add(Key.LWin, TextBlockWinLeft);
            textBlockKeyPairs.Add(Key.LeftAlt, TextBlockAltLeft);
            textBlockKeyPairs.Add(Key.Space, TextBlockSpace);
            textBlockKeyPairs.Add(Key.RightAlt, TextBlockAltRight);
            textBlockKeyPairs.Add(Key.RWin, TextBlockWinRight);
            textBlockKeyPairs.Add(Key.RightCtrl, TextBlockCtrlRight);
        }

        private void ClearEffects()
        {
            for (int i = 0; i < textBlockKeyPairs.Count; i++)
                textBlockKeyPairs.ElementAt(i).Value.Effect = null;

        }
        private void KeyboardKeyDown(object sender, KeyEventArgs e)
        {

        }


        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            startButton.IsEnabled = false;
            stopButton.IsEnabled = true;
            timer.Start();
            printingPanel.Focus();
            printingPanel.CaretIndex = 0;
            isStarted = true;
        }

        private void ChangeSpeedValue()
        {
            int speed;
            if (seconds > success)
                speed = success;
            else
                speed = success / seconds * 60;
            speedValue.Content = $"{speed} chars/min";
        }

        private void Timer_Tick(object? sender, EventArgs e)
        {

            if (seconds < 60)
            {
                Title = TimeSpan.FromSeconds(seconds).ToString(@"mm\:ss");
                seconds++;
            }
            else
            {
                MessageBox.Show($"Time is over! Your speed is {speedValue.Content}");
                timer.Stop();
                ClearAll();
            }

            ChangeSpeedValue();
        }

        private void PrintingPanel_PreviewKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Left || e.Key == Key.Right || e.Key == Key.Up || e.Key == Key.Down)
                e.Handled = true;

            if (!isStarted)
                return;

            ClearEffects();

            string currentChar = printingPanel.Text[caretInd].ToString();
            if (e.Key == Key.Space && currentChar == " " 
                || e.Key == Key.OemComma && currentChar == ","
                || e.Key == Key.OemPeriod && currentChar == ".")
            {
                printingPanel.CaretIndex = ++caretInd;
                success++;
                e.Handled = true; 
                return;
            }




            for (int i = 0; i < textBlockKeyPairs.Count; i++)
            {
                if (e.Key == textBlockKeyPairs.ElementAt(i).Key)
                {
                    DropShadowEffect outerGlowEffect = new DropShadowEffect
                    {
                        Color = Colors.Black,
                        BlurRadius = 27,
                        Opacity = 1,
                        ShadowDepth = 10,
                        Direction = -75
                    };
                    textBlockKeyPairs.ElementAt(i).Value.Effect = outerGlowEffect;
                }

            }
            if (e.Key == Key.LeftShift || e.Key == Key.RightShift || e.Key == Key.Tab)
                return;


            bool isCapsPressed = Keyboard.IsKeyToggled(Key.CapsLock);



            string pressedChar = isCapsPressed ? e.Key.ToString() : e.Key.ToString().ToLower();

            if (pressedChar == currentChar)
            {
                printingPanel.Background = new SolidColorBrush(successColor);
                printingPanel.CaretIndex = ++caretInd;
                success++;
            }

            else if (e.Key == Key.CapsLock)
                return;

            else
            {
                failsValue.Content = ++fails;
                printingPanel.Background = new SolidColorBrush(failColor);
            }

        }

        private void stopButton_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show($"Time is over! Your speed is {speedValue.Content}");
            stopButton.IsEnabled = false;
            startButton.IsEnabled = true;
            timer.Stop();
            ClearAll();
        }

        private void ClearAll()
        {
            caretInd = 0;
            printingPanel.CaretIndex = caretInd;
            Title = "Keyboard Trainer";
            fails = speed = success = 0;
            ClearEffects();
            BrushConverter bc = new BrushConverter();
            printingPanel.Background = (Brush)bc.ConvertFrom("#FFC9D1D8");
            speedValue.Content = failsValue.Content = "0 chars/min";
        }

    }
}