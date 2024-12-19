namespace WFormsMillionaire
{
    public class Presenter
    {
        public Form1 view;
        public Model model;
        public Presenter(Form1 form1, Model model)
        {
            view = form1;
            this.model = model;
            view.CloseWindow += CloseWindow;
            view.StartGame += GenerateQuestion;
            view.AnswerClick += CheckAnswer;
            view.StopButtonClick += StopGame;
            view.NewButtonClick += RestartGame;
            model.StartSound();
        }

        private void CloseWindow(object sender,EventArgs e)
        {
            view.Close();
        }
        private void GenerateQuestion(object sender, EventArgs e)
        {
            if (model.isGameStarted)
                model.StartSound();
            int curQuestion;
            do
            {
                curQuestion = model.PickRand();
            } while (model.IsQuestionFinished(model.questions[curQuestion]));

            model.finishedQuestions.Add(model.questions[curQuestion]);
            view.DisplayQuestion(model.questions[curQuestion]);
        }

        private void StopGame(object sender, EventArgs e)
        {
            view.DisplayPrizeScreen(model.StablePrize);
            model.finishedQuestions.Clear();
        }

        private async void CheckAnswer(object sender, EventArgs e)
        {
            bool isNextQuestion = false;
            view.OffAnswers();
            Question tempQ;
            int tempQInd;
            Answer tempAns;

            Button button = sender as Button;
            string qText = view.ReturnQuestionText();
            tempQ = model.questions.Where(q => q.Text == qText).First();
            tempQInd = model.questions.IndexOf(tempQ);

            tempAns = tempQ.Answers.Where(ans => ans.Text == button.Text).First();

            if (model.IsAnswerCorrect(tempAns))
            {
                isNextQuestion = true;
                int prize = ChangeIfCheckpoint(view.ReturnSelectedItem());
                if (prize != -1)
                    model.StablePrize = prize;

                view.PaintBack(sender, true); 
                model.Sound("true.wav");
                view.ChangeSelectedInListBox();
                if (model.StablePrize == 1000000)
                {
                    model.Sound("winner.wav");
                    StopGame(sender, e);
                    await Task.Delay(2000);

                }

            }
            else
            {
                view.PaintBack(sender, false);  
                model.Sound("false.wav");
            }

            await Task.Delay(2000);

            if (isNextQuestion == false) {
                model.Sound("summa.wav");
                StopGame(sender, e);
                await Task.Delay(2000);

            }

            view.PaintDefault(sender);
            GenerateQuestion(sender, e);

            view.OnAnswers();
        }

        public int ChangeIfCheckpoint(int selInd)
        {
            if (view.orangeItems[selInd] == true)
            {

                string itemText = view.GetListBoxItemText(selInd);  
                int dashIndex = itemText.IndexOf('-'); 

                string onlyDigit = itemText.Substring(dashIndex + 1).Trim();
                return int.Parse(onlyDigit);
            }

            return -1;

        }

        public void RestartGame(object sender,EventArgs e)
        {
            if (MessageBox.Show("Вы хотите начать новую игру?", "New game", MessageBoxButtons.OKCancel, MessageBoxIcon.Information) == DialogResult.OK)
            {
                view.RestartListBox();
                model.RestartAll();
                view.GetToMainScreen();
            }
            else
                return;
        }




    }
}
