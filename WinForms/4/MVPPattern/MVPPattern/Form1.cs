using System.Reflection;

namespace MVPPattern
{
    public partial class Form1 : Form, IView
    {

        public Form1()
        {
            InitializeComponent();
            Buttons = new Button[]
            {
                button1, button2, button3, button4, button5, button6,
                button7, button8, button9
            };


            for (int i = 0; i < Buttons.Length; i++)
            {
                Buttons[i].Tag = i; 
            }
        }

        public Button[] Buttons { get; set; }

        public bool EasyMode => easyMode.Checked;

        public bool HardMode => hardMode.Checked;

        public bool IsBotFirst => isBotFirst.Checked;

        public event EventHandler<EventArgs> StartButtonEvent;
        public event EventHandler<EventArgs> GameButtonEvent;

        public void DisableAllButtons()
        {
            foreach (var button in Buttons)
            {
                button.Enabled = false;
            }

        }

        public void DisableAllOptions()
        {
            isBotFirst.Enabled = easyMode.Enabled = hardMode.Enabled = false;
        }

        public void EnableAllButtons()
        {
            foreach (var button in Buttons)
            {
                button.Enabled = true;
            }
            AddBorders();

        }

        public void EnableAllOptions()
        {
            isBotFirst.Enabled = easyMode.Enabled = hardMode.Enabled = true;
        }

        public void SetBgForButton(Button button, Bitmap image)
        {
            button.BackgroundImage = image;
            button.BackgroundImageLayout = ImageLayout.Stretch;
        }

        private void AddBorders()
        {
            foreach (var button in Buttons)
            {
                button.FlatStyle = FlatStyle.Flat;
                button.FlatAppearance.BorderColor = Color.LightBlue;
                button.FlatAppearance.BorderSize = 1;
            }
        }

        public void DesignButtons(Button btn1, Button btn2, Button btn3)
        {
            btn1.FlatAppearance.BorderColor = btn2.FlatAppearance.BorderColor = btn3.FlatAppearance.BorderColor = Color.Red;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            DisableAllButtons();
        }

        private void startButton_Click(object sender, EventArgs e)
        {
            try
            {
                StartButtonEvent?.Invoke(this, EventArgs.Empty);
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        public void DisplayWinner(string winner)
        {
            MessageBox.Show($"�������� {winner}", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            foreach (var button in Buttons)
            {
                button.BackgroundImage = null;
                button.FlatAppearance.BorderColor = Color.LightBlue;
            }
            DisableAllButtons();
            EnableAllOptions();
        }

        public void DisplayDraw()
        {
            MessageBox.Show("�����!", "Game Over", MessageBoxButtons.OK, MessageBoxIcon.Information);
            foreach (var button in Buttons)
            {
                button.BackgroundImage = null;
                button.FlatAppearance.BorderColor = Color.LightBlue;
            }
            DisableAllButtons();
            EnableAllOptions();
        }

        private void button_Click(object sender, EventArgs e)
        {
            GameButtonEvent?.Invoke(sender, EventArgs.Empty);
        }

        public void ShowError(string message)
        {
            MessageBox.Show($"{message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
    }
}
