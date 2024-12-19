namespace WFormsMillionaire
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            menuStrip1 = new MenuStrip();
            gameToolStrip = new ToolStripMenuItem();
            aboutToolStrip = new ToolStripMenuItem();
            newButton = new Button();
            exitButton = new Button();
            stopButton = new Button();
            questionLabel = new Label();
            answer1Button = new Button();
            answer2Button = new Button();
            answer3Button = new Button();
            answer4Button = new Button();
            groupBox1 = new GroupBox();
            groupButton = new Button();
            callButton = new Button();
            fiftyButton = new Button();
            listBox1 = new ListBox();
            prizeLabel = new Label();
            menuStrip1.SuspendLayout();
            groupBox1.SuspendLayout();
            SuspendLayout();
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { gameToolStrip, aboutToolStrip });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Size = new Size(1018, 24);
            menuStrip1.TabIndex = 0;
            menuStrip1.Text = "menuStrip1";
            // 
            // gameToolStrip
            // 
            gameToolStrip.Name = "gameToolStrip";
            gameToolStrip.Size = new Size(46, 20);
            gameToolStrip.Text = "Игра";
            // 
            // aboutToolStrip
            // 
            aboutToolStrip.Name = "aboutToolStrip";
            aboutToolStrip.Size = new Size(94, 20);
            aboutToolStrip.Text = "О программе";
            // 
            // newButton
            // 
            newButton.BackgroundImage = (Image)resources.GetObject("newButton.BackgroundImage");
            newButton.FlatStyle = FlatStyle.Flat;
            newButton.Location = new Point(0, 27);
            newButton.Name = "newButton";
            newButton.Size = new Size(61, 35);
            newButton.TabIndex = 1;
            newButton.UseVisualStyleBackColor = true;
            newButton.Click += newButton_Click;
            // 
            // exitButton
            // 
            exitButton.BackgroundImage = (Image)resources.GetObject("exitButton.BackgroundImage");
            exitButton.FlatStyle = FlatStyle.Flat;
            exitButton.Location = new Point(67, 27);
            exitButton.Name = "exitButton";
            exitButton.Size = new Size(61, 35);
            exitButton.TabIndex = 2;
            exitButton.UseVisualStyleBackColor = true;
            exitButton.Click += exitButton_Click;
            // 
            // stopButton
            // 
            stopButton.BackColor = SystemColors.ActiveCaptionText;
            stopButton.FlatAppearance.BorderSize = 0;
            stopButton.FlatStyle = FlatStyle.Flat;
            stopButton.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            stopButton.ForeColor = Color.Gold;
            stopButton.Location = new Point(144, 27);
            stopButton.Name = "stopButton";
            stopButton.Size = new Size(79, 35);
            stopButton.TabIndex = 3;
            stopButton.Text = "Стоп";
            stopButton.UseVisualStyleBackColor = false;
            stopButton.Click += stopButton_Click;
            // 
            // questionLabel
            // 
            questionLabel.AutoSize = true;
            questionLabel.BackColor = SystemColors.ActiveCaptionText;
            questionLabel.FlatStyle = FlatStyle.Flat;
            questionLabel.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 204);
            questionLabel.ForeColor = Color.Lime;
            questionLabel.Location = new Point(48, 341);
            questionLabel.MaximumSize = new Size(700, 100);
            questionLabel.MinimumSize = new Size(700, 80);
            questionLabel.Name = "questionLabel";
            questionLabel.Padding = new Padding(5, 10, 5, 10);
            questionLabel.Size = new Size(700, 80);
            questionLabel.TabIndex = 4;
            questionLabel.Text = "Как называется место на берегу, где обитают тюлени?";
            questionLabel.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // answer1Button
            // 
            answer1Button.BackColor = SystemColors.ActiveCaptionText;
            answer1Button.Font = new Font("Segoe UI", 11.25F, FontStyle.Regular, GraphicsUnit.Point, 204);
            answer1Button.ForeColor = Color.Lime;
            answer1Button.Location = new Point(48, 442);
            answer1Button.Name = "answer1Button";
            answer1Button.Padding = new Padding(5, 10, 5, 10);
            answer1Button.Size = new Size(312, 47);
            answer1Button.TabIndex = 5;
            answer1Button.Text = "button1";
            answer1Button.TextAlign = ContentAlignment.MiddleLeft;
            answer1Button.UseVisualStyleBackColor = false;
            // 
            // answer2Button
            // 
            answer2Button.BackColor = SystemColors.ActiveCaptionText;
            answer2Button.Font = new Font("Segoe UI", 11.25F, FontStyle.Regular, GraphicsUnit.Point, 204);
            answer2Button.ForeColor = Color.Lime;
            answer2Button.Location = new Point(48, 516);
            answer2Button.Name = "answer2Button";
            answer2Button.Padding = new Padding(5, 10, 5, 10);
            answer2Button.Size = new Size(312, 47);
            answer2Button.TabIndex = 6;
            answer2Button.Text = "button1";
            answer2Button.TextAlign = ContentAlignment.MiddleLeft;
            answer2Button.UseVisualStyleBackColor = false;
            // 
            // answer3Button
            // 
            answer3Button.BackColor = SystemColors.ActiveCaptionText;
            answer3Button.Font = new Font("Segoe UI", 11.25F, FontStyle.Regular, GraphicsUnit.Point, 204);
            answer3Button.ForeColor = Color.Lime;
            answer3Button.Location = new Point(436, 442);
            answer3Button.Name = "answer3Button";
            answer3Button.Padding = new Padding(5, 10, 5, 10);
            answer3Button.Size = new Size(312, 47);
            answer3Button.TabIndex = 7;
            answer3Button.Text = "button1";
            answer3Button.TextAlign = ContentAlignment.MiddleLeft;
            answer3Button.UseVisualStyleBackColor = false;
            // 
            // answer4Button
            // 
            answer4Button.BackColor = SystemColors.ActiveCaptionText;
            answer4Button.Font = new Font("Segoe UI", 11.25F, FontStyle.Regular, GraphicsUnit.Point, 204);
            answer4Button.ForeColor = Color.Lime;
            answer4Button.Location = new Point(436, 516);
            answer4Button.Name = "answer4Button";
            answer4Button.Padding = new Padding(5, 10, 5, 10);
            answer4Button.Size = new Size(312, 47);
            answer4Button.TabIndex = 8;
            answer4Button.Text = "button2";
            answer4Button.TextAlign = ContentAlignment.MiddleLeft;
            answer4Button.UseVisualStyleBackColor = false;
            // 
            // groupBox1
            // 
            groupBox1.BackColor = SystemColors.ActiveCaptionText;
            groupBox1.Controls.Add(groupButton);
            groupBox1.Controls.Add(callButton);
            groupBox1.Controls.Add(fiftyButton);
            groupBox1.ForeColor = Color.DarkOrange;
            groupBox1.Location = new Point(792, 27);
            groupBox1.Name = "groupBox1";
            groupBox1.Size = new Size(226, 86);
            groupBox1.TabIndex = 9;
            groupBox1.TabStop = false;
            groupBox1.Text = "Подсказки";
            // 
            // groupButton
            // 
            groupButton.BackColor = SystemColors.ActiveCaptionText;
            groupButton.BackgroundImage = (Image)resources.GetObject("groupButton.BackgroundImage");
            groupButton.BackgroundImageLayout = ImageLayout.Stretch;
            groupButton.Location = new Point(150, 22);
            groupButton.Name = "groupButton";
            groupButton.Size = new Size(66, 45);
            groupButton.TabIndex = 2;
            groupButton.UseVisualStyleBackColor = false;
            // 
            // callButton
            // 
            callButton.BackColor = SystemColors.ActiveCaptionText;
            callButton.BackgroundImage = (Image)resources.GetObject("callButton.BackgroundImage");
            callButton.BackgroundImageLayout = ImageLayout.Stretch;
            callButton.Location = new Point(78, 22);
            callButton.Name = "callButton";
            callButton.Size = new Size(66, 45);
            callButton.TabIndex = 1;
            callButton.UseVisualStyleBackColor = false;
            // 
            // fiftyButton
            // 
            fiftyButton.BackColor = SystemColors.ActiveCaptionText;
            fiftyButton.BackgroundImage = (Image)resources.GetObject("fiftyButton.BackgroundImage");
            fiftyButton.BackgroundImageLayout = ImageLayout.Stretch;
            fiftyButton.Location = new Point(6, 22);
            fiftyButton.Name = "fiftyButton";
            fiftyButton.Size = new Size(66, 45);
            fiftyButton.TabIndex = 0;
            fiftyButton.UseVisualStyleBackColor = false;
            fiftyButton.Click += fiftyButton_Click;
            // 
            // listBox1
            // 
            listBox1.BackColor = SystemColors.InactiveCaptionText;
            listBox1.ForeColor = Color.Lime;
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 15;
            listBox1.Items.AddRange(new object[] { "", "15 - 1000000", "14 - 500000", "13 - 250000", "12 - 125000", "11 - 64000", "10 - 32000", "9 - 16000", "8 - 8000", "7 - 4000", "6 - 2000", "5 - 1000 ", "4 - 500", "3 - 300", "2 - 200", "1 - 100" });
            listBox1.Location = new Point(792, 119);
            listBox1.MinimumSize = new Size(0, 700);
            listBox1.Name = "listBox1";
            listBox1.RightToLeft = RightToLeft.No;
            listBox1.Size = new Size(226, 694);
            listBox1.TabIndex = 11;
            // 
            // prizeLabel
            // 
            prizeLabel.AutoSize = true;
            prizeLabel.BackColor = Color.Transparent;
            prizeLabel.Font = new Font("Segoe UI", 36F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point, 204);
            prizeLabel.ForeColor = Color.Navy;
            prizeLabel.Location = new Point(277, 194);
            prizeLabel.MaximumSize = new Size(700, 0);
            prizeLabel.Name = "prizeLabel";
            prizeLabel.Size = new Size(167, 65);
            prizeLabel.TabIndex = 12;
            prizeLabel.Text = "label1";
            prizeLabel.TextAlign = ContentAlignment.MiddleCenter;
            prizeLabel.Visible = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = (Image)resources.GetObject("$this.BackgroundImage");
            ClientSize = new Size(1018, 575);
            Controls.Add(prizeLabel);
            Controls.Add(listBox1);
            Controls.Add(groupBox1);
            Controls.Add(answer4Button);
            Controls.Add(answer3Button);
            Controls.Add(answer2Button);
            Controls.Add(answer1Button);
            Controls.Add(questionLabel);
            Controls.Add(stopButton);
            Controls.Add(exitButton);
            Controls.Add(newButton);
            Controls.Add(menuStrip1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Location = new Point(784, 561);
            MainMenuStrip = menuStrip1;
            MaximizeBox = false;
            MinimizeBox = false;
            Name = "Form1";
            Text = "Кто хочет стать миллионером";
            Load += Form1_Load;
            Shown += DisplayStart;
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            groupBox1.ResumeLayout(false);
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private MenuStrip menuStrip1;
        private ToolStripMenuItem gameToolStrip;
        private ToolStripMenuItem aboutToolStrip;
        private Button newButton;
        private Button exitButton;
        private Button stopButton;
        private Label questionLabel;
        private Button answer1Button;
        private Button answer2Button;
        private Button answer3Button;
        private Button answer4Button;
        private GroupBox groupBox1;
        private Button fiftyButton;
        private Button groupButton;
        private Button callButton;
        private ListBox listBox1;
        private Label prizeLabel;
    }
}
