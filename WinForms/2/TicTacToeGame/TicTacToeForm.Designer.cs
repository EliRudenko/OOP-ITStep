namespace TicTacToeGame
{
    partial class TicTacToeForm
    {
        private System.ComponentModel.IContainer components = null;

        private Button[] gameButtons = new Button[9];

        public TicTacToeForm()
        {
            InitializeComponent();  
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            this.ClientSize = new System.Drawing.Size(300, 300);
            this.Name = "TicTacToeForm";
            this.Text = "Tic Tac Toe";
            
            for (int i = 0; i < 9; i++)
            {
                gameButtons[i] = new Button
                {
                    Size = new System.Drawing.Size(80, 80),
                    Location = new System.Drawing.Point(80 * (i % 3), 80 * (i / 3)),
                    Tag = i.ToString()  
                };
                gameButtons[i].Click += ButtonClick; 
                this.Controls.Add(gameButtons[i]);
            }

            this.ResumeLayout(false);
        }
    }
}
