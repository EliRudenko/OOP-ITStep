namespace MVPPattern
{
    public class Model
    {
        
        public Button[] Buttons { get; set; }
        public char CurrentMove { get; set; } = 'x';
        Bitmap xImage, oImage;

        public Model()
        {
            xImage = new Bitmap("x.jpg");
            oImage = new Bitmap("o.jpg");
        }

        public Bitmap GetXImage()
        {
            return xImage;
        }

        public Bitmap GetOImage()
        {
            return oImage;
        }

        public void ChangeCurrentMove()
        {
            CurrentMove = CurrentMove == 'x' ? 'o' : 'x';
        }

        private bool AreImagesEqual(Button btn1, Button btn2, Button btn3)
        {
            if (btn1.BackgroundImage != null && btn2.BackgroundImage != null && btn3.BackgroundImage != null)
                return btn1.BackgroundImage.Equals(btn2.BackgroundImage) && btn2.BackgroundImage.Equals(btn3.BackgroundImage);

            return false;
        }

        private void DesignButtons(Button btn1, Button btn2, Button btn3)
        {
            btn1.FlatAppearance.BorderColor = btn2.FlatAppearance.BorderColor = btn3.FlatAppearance.BorderColor = Color.Red;
        }

        private bool HorizontalCheck()
        {
            if (AreImagesEqual(Buttons[0], Buttons[1], Buttons[2]))
            {
                DesignButtons(Buttons[0], Buttons[1], Buttons[2]);
                return true;
            }

            if (AreImagesEqual(Buttons[3], Buttons[4], Buttons[5]))
            {
                DesignButtons(Buttons[3], Buttons[4], Buttons[5]);
                return true;
            }

            if (AreImagesEqual(Buttons[6], Buttons[7], Buttons[8]))
            {
                DesignButtons(Buttons[6], Buttons[7], Buttons[8]);
                return true;
            }

            return false;
        }

        private bool VerticalCheck()
        {
            if (AreImagesEqual(Buttons[0], Buttons[3], Buttons[6]))
            {
                DesignButtons(Buttons[0], Buttons[3], Buttons[6]);
                return true;
            }

            if (AreImagesEqual(Buttons[1], Buttons[4], Buttons[7]))
            {
                DesignButtons(Buttons[1], Buttons[4], Buttons[7]);
                return true;
            }

            if (AreImagesEqual(Buttons[2], Buttons[5], Buttons[8]))
            {
                DesignButtons(Buttons[2], Buttons[5], Buttons[8]);
                return true;
            }

            return false;
        }

        private bool DiagonalCheck()
        {
            if (AreImagesEqual(Buttons[0], Buttons[4], Buttons[8]))
            {
                DesignButtons(Buttons[0], Buttons[4], Buttons[8]);
                return true;
            }

            if (AreImagesEqual(Buttons[2], Buttons[4], Buttons[6]))
            {
                DesignButtons(Buttons[2], Buttons[4], Buttons[6]);
                return true;
            }

            return false;
        }
        public bool IsBoardFull()
        {
            return Buttons.All(b => b.BackgroundImage != null);
        }

        public bool CheckForWinner()
        {
            if (HorizontalCheck() || VerticalCheck() || DiagonalCheck())
                return true;

            return false;
        }

        public int EasyBotMove()
        {
            Random rand = new Random();
            List<Button> availableButtons = Buttons.Where(b => b.BackgroundImage == null).ToList();
            int index = rand.Next(availableButtons.Count);

            return index;
        }

        public int HardBotMove()
        {
            int index = TryWinningMove();
            if (index != -1)
            {
                return index; 
            }

            index = TryBlockOpponent();
            if (index != -1)
            {
                return index; 
            }

            if (Buttons[4].BackgroundImage == null)
            {
                return 4;
            }

            Random rand = new Random();
            List<Button> availableButtons = Buttons.Where(b => b.BackgroundImage == null).ToList();

            if (availableButtons.Count > 0)
            {
                Button selectedButton = availableButtons[rand.Next(availableButtons.Count)];
                return Array.IndexOf(Buttons, selectedButton);
            }

            return -1; 
        }



        private int TryBlockOpponent()
        {
            int index;

            index = TryBlockInLine(Buttons[0], Buttons[1], Buttons[2]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[3], Buttons[4], Buttons[5]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[6], Buttons[7], Buttons[8]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[0], Buttons[3], Buttons[6]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[1], Buttons[4], Buttons[7]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[2], Buttons[5], Buttons[8]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[0], Buttons[4], Buttons[8]);
            if (index != -1) return index;

            index = TryBlockInLine(Buttons[2], Buttons[4], Buttons[6]);
            if (index != -1) return index;

            return -1;
        }


        private int TryBlockInLine(Button btn1, Button btn2, Button btn3)
        {
            if (btn1.BackgroundImage != null && btn1.BackgroundImage.Equals(CurrentMove == 'x' ? oImage : xImage) &&
                btn2.BackgroundImage != null && btn2.BackgroundImage.Equals(CurrentMove == 'x' ? oImage : xImage) &&
                btn3.BackgroundImage == null)
            {
                return Array.IndexOf(Buttons, btn3);
            }

            if (btn1.BackgroundImage != null && btn1.BackgroundImage.Equals(CurrentMove == 'x' ? oImage : xImage) &&
                btn3.BackgroundImage != null && btn3.BackgroundImage.Equals(CurrentMove == 'x' ? oImage : xImage) &&
                btn2.BackgroundImage == null)
            {
                return Array.IndexOf(Buttons, btn2); 
            }

            if (btn2.BackgroundImage != null && btn2.BackgroundImage.Equals(CurrentMove == 'x' ? oImage : xImage) &&
                btn3.BackgroundImage != null && btn3.BackgroundImage.Equals(CurrentMove == 'x' ? oImage : xImage) &&
                btn1.BackgroundImage == null)
            {
                return Array.IndexOf(Buttons, btn1); 
            }

            return -1; 
        }




        private int TryWinningMove()
        {
            int index = TryCompleteLine(Buttons[0], Buttons[1], Buttons[2]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[3], Buttons[4], Buttons[5]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[6], Buttons[7], Buttons[8]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[0], Buttons[3], Buttons[6]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[1], Buttons[4], Buttons[7]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[2], Buttons[5], Buttons[8]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[0], Buttons[4], Buttons[8]);
            if (index != -1) return index;

            index = TryCompleteLine(Buttons[2], Buttons[4], Buttons[6]);
            if (index != -1) return index;

            return -1; 
        }


        private int TryCompleteLine(Button b1, Button b2, Button b3)
        {
            if (b1.BackgroundImage != null && b1.BackgroundImage.Equals(CurrentMove == 'o' ? oImage : xImage) &&
                b2.BackgroundImage != null && b2.BackgroundImage.Equals(CurrentMove == 'o' ? oImage : xImage) &&
                (b3.BackgroundImage == null))
            {
                return Array.IndexOf(Buttons, b3);  
            }

            if (b1.BackgroundImage != null && b1.BackgroundImage.Equals(CurrentMove == 'o' ? oImage : xImage) &&
                b3.BackgroundImage != null && b3.BackgroundImage.Equals(CurrentMove == 'o' ? oImage : xImage) &&
                (b2.BackgroundImage == null))
            {
                return Array.IndexOf(Buttons, b2); 
            }

            if (b2.BackgroundImage != null && b2.BackgroundImage.Equals(CurrentMove == 'o' ? oImage : xImage) &&
                b3.BackgroundImage != null && b3.BackgroundImage.Equals(CurrentMove == 'o' ? oImage : xImage) &&
                (b1.BackgroundImage == null))
            {
                return Array.IndexOf(Buttons, b1); 
            }

            return -1; 
        }
    }
}
