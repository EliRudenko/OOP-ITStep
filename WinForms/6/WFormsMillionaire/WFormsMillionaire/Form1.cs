using System.Media;

namespace WFormsMillionaire
{
    public partial class Form1 : Form
    {
        public event EventHandler<EventArgs> CloseWindow;
        public event EventHandler<EventArgs> StartGame;
        public event EventHandler<EventArgs> AnswerClick;
        public event EventHandler<EventArgs> StopButtonClick;
        public event EventHandler<EventArgs> NewButtonClick;
        public event EventHandler<EventArgs> FiftyButtonClick;

        public Dictionary<int, bool> orangeItems = new Dictionary<int, bool>();
        public Form1()
        {
            InitializeComponent();
            answer1Button.Click += answer_Click;
            answer2Button.Click += answer_Click;
            answer3Button.Click += answer_Click;
            answer4Button.Click += answer_Click;
        }

        private void InitializeOrangeItems()
        {
            for (int i = 0; i < listBox1.Items.Count; i++)
            {
                if (i == 1 || i == 6 || i == 11)
                    orangeItems.Add(i, true);
                else
                    orangeItems.Add(i, false);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.StartPosition = FormStartPosition.Manual;
            this.Location = new Point(
                (Screen.PrimaryScreen.WorkingArea.Width - this.Width) / 2,
                (Screen.PrimaryScreen.WorkingArea.Height - this.Height) / 2
            );

            listBox1.DrawMode = DrawMode.OwnerDrawFixed;

            listBox1.DrawItem += new DrawItemEventHandler(listBox1_DrawItem);
            listBox1.Enabled = false;
            listBox1.ItemHeight = 27;
            listBox1.SelectedIndex = 15;

            prizeLabel.Left = (this.ClientSize.Width - prizeLabel.Width) / 2 - 350;
            prizeLabel.Top = (this.ClientSize.Height - prizeLabel.Height) / 2;

            EmptyAnswersAndQuestion();
            InitializeOrangeItems();
        }

        private void EmptyAnswersAndQuestion()
        {
            questionLabel.Text = answer1Button.Text = answer2Button.Text = answer3Button.Text = answer4Button.Text = string.Empty;
        }

        public string ReturnQuestionText()
        {
            return questionLabel.Text;
        }

        public string GetListBoxItemText(int ind)
        {
            return listBox1.Items[ind].ToString();
        }

        public void ChangeSelectedInListBox()
        {
            listBox1.SelectedIndex--;
        }

        public void RestartListBox()
        {
            listBox1.SelectedIndex = 15;
        }


        public void DisplayQuestion(Question question)
        {
            questionLabel.Text = question.Text;
            answer1Button.Text = question.Answers[0].Text;
            answer2Button.Text = question.Answers[1].Text;
            answer3Button.Text = question.Answers[2].Text;
            answer4Button.Text = question.Answers[3].Text;
        }

        public void PaintBack(object sender, bool flag) // if 1 == green,else == red
        {
            Button button = sender as Button;
            button.BackColor = flag ? Color.Green : Color.Red;

        }

        public void PaintDefault(object sender)
        {
            Button button = sender as Button;
            button.BackColor = Color.Black;
        }

        public void DisplayStart(object sender, EventArgs e)
        {
            if (MessageBox.Show("Нажмите ОК для начала игры", "START", MessageBoxButtons.OKCancel, MessageBoxIcon.Information) == DialogResult.Cancel)
                CloseWindow.Invoke(this, e);
            else
            {
                StartGame.Invoke(this, e);
            }
        }

        public void OffAnswers()
        {
            answer1Button.Tag = answer2Button.Tag = answer3Button.Tag = answer4Button.Tag = "disabled";
        }

        public void OnAnswers()
        {
            answer1Button.Tag = answer2Button.Tag = answer3Button.Tag = answer4Button.Tag = "enabled";
        }

        public int ReturnSelectedItem()
        {
            return listBox1.SelectedIndex;
        }

        public void GetToMainScreen()
        {
            BackgroundImage = new Bitmap("mil.jpg");
            ChangeMainScreenVisibility();
            prizeLabel.Visible = false;
            StartGame.Invoke(this, EventArgs.Empty);
        }

        public void ChangeMainScreenVisibility()
        {
            answer1Button.Visible = answer2Button.Visible = answer3Button.Visible = answer4Button.Visible = !answer1Button.Visible;
            questionLabel.Visible = !questionLabel.Visible;
        }

        public async void DisplayPrizeScreen(int prize)
        {

            ChangeMainScreenVisibility();
            prizeLabel.Visible = true;

            BackgroundImageLayout = ImageLayout.Stretch;


            if (prize == 1000000)
            {
                BackgroundImage = new Bitmap("vig.JPG");
                prizeLabel.Text = "Вы стали миллионером!!!";
                return;
            }

            BackgroundImage = new Bitmap("Vigrash.JPG");

            if (prize > 0)
                prizeLabel.Text = $"Поздравляю! Вы выиграли {prize}$";
            else
                prizeLabel.Text = "Удачи в следующий раз!";

        }


        private void listBox1_DrawItem(object sender, DrawItemEventArgs e)
        {
            ListBox list = (ListBox)sender;

            if (e.Index >= 0)
            {
                string item = list.Items[e.Index].ToString();

                float fontSize = 15.0f;
                Font largerFont = new Font(e.Font.FontFamily, fontSize);

                Brush brush = new SolidBrush(e.ForeColor);
                if (e.Index == 1 || e.Index == 6 || e.Index == 11)
                    brush = new SolidBrush(Color.Orange);

                e.DrawBackground();

                SizeF size = e.Graphics.MeasureString(item, largerFont);

                float x = e.Bounds.Left + (e.Bounds.Width / 2 - size.Width / 2);
                float y = e.Bounds.Top + (e.Bounds.Height / 2 - size.Height / 2);

                e.Graphics.DrawString(item, largerFont, brush, new PointF(x, y));

                e.DrawFocusRectangle();

                largerFont.Dispose();
            }
        }


        private void answer_Click(object sender, EventArgs e)
        {
            Button button = sender as Button;
            if (button.Tag == "disabled")
                return;

            AnswerClick.Invoke(sender, e);
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            CloseWindow.Invoke(this, EventArgs.Empty);
        }

        private void stopButton_Click(object sender, EventArgs e)
        {
            StopButtonClick.Invoke(sender, e);
        }

        private void newButton_Click(object sender, EventArgs e)
        {
            NewButtonClick.Invoke(sender, e);
        }

        private void fiftyButton_Click(object sender, EventArgs e)
        {
            FiftyButtonClick.Invoke(sender, e);
        }
    }
}
