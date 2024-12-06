
namespace MVPPattern
{
    public class Presenter
    {
        IView view;
        Model model;
        Bitmap xImage, oImage;
        public Presenter(IView _view,Model _model ) { 
            view = _view;
            model = _model;
            xImage = model.GetXImage();
            oImage = model.GetOImage();

            SyncFields();
            view.StartButtonEvent += new EventHandler<EventArgs>(StartGame);
            view.GameButtonEvent += new EventHandler<EventArgs>(DoMove);

        }

        public void EasyModeMove()
        {
            int index = model.EasyBotMove();
            Bitmap img = model.CurrentMove == 'x' ? xImage : oImage;
            view.SetBgForButton(view.Buttons[index], img);
            SyncFields();
        }
        public void HardModeMove()
        {
            int index = model.HardBotMove();
            Bitmap img = model.CurrentMove == 'x' ? xImage : oImage;
            view.SetBgForButton(view.Buttons[index], img);
            SyncFields();
        }

        public void StartGame(object sender,EventArgs e)
        {
            model.CurrentMove = 'x';
            if (!view.EasyMode && !view.HardMode)
            {
                view.ShowError("Выберите сложность");
                return;
            }

            if (view.IsBotFirst)
            {
                if (view.EasyMode)
                    EasyModeMove();
                else
                    HardModeMove();

                model.ChangeCurrentMove();

            }

            view.EnableAllButtons();
            view.DisableAllOptions();
        }

        public void DoMove(object sender, EventArgs e)
        {
            Button btn= (Button)sender;
            if (btn.BackgroundImage != null) {
                view.ShowError("Ячейка уже занята");
                return;
            }

            if (btn.BackgroundImage == null)
            {
                if (model.CurrentMove == 'x')
                    view.SetBgForButton(btn, xImage);
                else
                    view.SetBgForButton(btn, oImage);

                if (model.CheckForWinner())
                {
                    string winner = model.CurrentMove == 'x' ? "Крестики" : "Нолики";
                    view.DisplayWinner(winner);
                }
                if (model.IsBoardFull())
                    view.DisplayDraw();

                SyncFields();

                model.ChangeCurrentMove();

                if (view.EasyMode)
                    EasyModeMove();
                else
                    HardModeMove();

                if (model.CheckForWinner())
                {
                    string winner = model.CurrentMove == 'x' ? "Крестики" : "Нолики";
                    view.DisplayWinner(winner);
                }
                if (model.IsBoardFull())
                    view.DisplayDraw();

                model.ChangeCurrentMove();

            }
        }

        public void SyncFields()
        {
            if (model.Buttons != null)
                view.Buttons = model.Buttons;
            else
                model.Buttons = view.Buttons;
        }
    }
}
