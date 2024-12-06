
namespace MVPPattern
{
    public interface IView
    {
        public Button[] Buttons { get; set; }
        public bool EasyMode { get; }
        public bool HardMode { get; }
        public bool IsBotFirst { get; }

        void DisableAllButtons();
        void EnableAllButtons();
        void DisableAllOptions();
        void EnableAllOptions();
        void DisplayWinner(string winner);
        void DisplayDraw();
        void ShowError(string message);
        void SetBgForButton(Button button,Bitmap image);
        event EventHandler<EventArgs> StartButtonEvent;
        event EventHandler<EventArgs> GameButtonEvent;
    }
}
