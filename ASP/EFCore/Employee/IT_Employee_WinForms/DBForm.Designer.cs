namespace IT_Employee_WinForms
{
    partial class DBForm
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
            button1 = new Button();
            button2 = new Button();
            button3 = new Button();
            button5 = new Button();
            label1 = new Label();
            textBoxFirstName = new TextBox();
            textBoxLastName = new TextBox();
            label2 = new Label();
            label3 = new Label();
            comboBox1 = new ComboBox();
            SuspendLayout();
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 12F);
            button1.Location = new Point(25, 12);
            button1.Name = "button1";
            button1.Size = new Size(89, 53);
            button1.TabIndex = 0;
            button1.Text = "Добавить";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 12F);
            button2.Location = new Point(25, 73);
            button2.Name = "button2";
            button2.Size = new Size(89, 54);
            button2.TabIndex = 1;
            button2.Text = "Удалить";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 12F);
            button3.Location = new Point(25, 133);
            button3.Name = "button3";
            button3.Size = new Size(89, 50);
            button3.TabIndex = 2;
            button3.Text = "Изменить";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button5
            // 
            button5.Font = new Font("Segoe UI", 12F);
            button5.Location = new Point(25, 189);
            button5.Name = "button5";
            button5.Size = new Size(89, 44);
            button5.TabIndex = 4;
            button5.Text = "Искать";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(240, 12);
            label1.Name = "label1";
            label1.Size = new Size(41, 21);
            label1.TabIndex = 5;
            label1.Text = "Имя";
            // 
            // textBoxFirstName
            // 
            textBoxFirstName.Location = new Point(207, 36);
            textBoxFirstName.Name = "textBoxFirstName";
            textBoxFirstName.Size = new Size(109, 23);
            textBoxFirstName.TabIndex = 6;
            // 
            // textBoxLastName
            // 
            textBoxLastName.Location = new Point(207, 119);
            textBoxLastName.Name = "textBoxLastName";
            textBoxLastName.Size = new Size(109, 23);
            textBoxLastName.TabIndex = 8;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label2.Location = new Point(217, 95);
            label2.Name = "label2";
            label2.Size = new Size(75, 21);
            label2.TabIndex = 7;
            label2.Text = "Фамилия";
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label3.Location = new Point(217, 179);
            label3.Name = "label3";
            label3.Size = new Size(90, 21);
            label3.TabIndex = 9;
            label3.Text = "Должность";
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(207, 203);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(109, 23);
            comboBox1.TabIndex = 10;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(348, 245);
            Controls.Add(comboBox1);
            Controls.Add(label3);
            Controls.Add(textBoxLastName);
            Controls.Add(label2);
            Controls.Add(textBoxFirstName);
            Controls.Add(label1);
            Controls.Add(button5);
            Controls.Add(button3);
            Controls.Add(button2);
            Controls.Add(button1);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private Button button2;
        private Button button3;
        private Button button5;
        private Label label1;
        private TextBox textBoxFirstName;
        private TextBox textBoxLastName;
        private Label label2;
        private Label label3;
        private ComboBox comboBox1;
    }
}
