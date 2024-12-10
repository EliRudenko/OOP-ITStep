namespace MVPBooksForm
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
            bookNameLabel = new Label();
            bookAuthorLabel = new Label();
            bookGenreLabel = new Label();
            label4 = new Label();
            textBoxName = new TextBox();
            textBoxAuthor = new TextBox();
            textBoxGenre = new TextBox();
            textBoxYear = new TextBox();
            saveButton = new Button();
            deleteButton = new Button();
            richTextBox1 = new RichTextBox();
            deleteInput = new TextBox();
            SuspendLayout();
            // 
            // bookNameLabel
            // 
            bookNameLabel.AutoSize = true;
            bookNameLabel.Location = new Point(52, 37);
            bookNameLabel.Name = "bookNameLabel";
            bookNameLabel.Size = new Size(94, 15);
            bookNameLabel.TabIndex = 0;
            bookNameLabel.Text = "Название книги";
            // 
            // bookAuthorLabel
            // 
            bookAuthorLabel.AutoSize = true;
            bookAuthorLabel.Location = new Point(52, 70);
            bookAuthorLabel.Name = "bookAuthorLabel";
            bookAuthorLabel.Size = new Size(75, 15);
            bookAuthorLabel.TabIndex = 1;
            bookAuthorLabel.Text = "Автор книги";
            // 
            // bookGenreLabel
            // 
            bookGenreLabel.AutoSize = true;
            bookGenreLabel.Location = new Point(52, 103);
            bookGenreLabel.Name = "bookGenreLabel";
            bookGenreLabel.Size = new Size(38, 15);
            bookGenreLabel.TabIndex = 2;
            bookGenreLabel.Text = "Жанр";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(52, 144);
            label4.Name = "label4";
            label4.Size = new Size(73, 15);
            label4.TabIndex = 3;
            label4.Text = "Год издания";
            // 
            // textBoxName
            // 
            textBoxName.Location = new Point(152, 34);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(194, 23);
            textBoxName.TabIndex = 4;
            // 
            // textBoxAuthor
            // 
            textBoxAuthor.Location = new Point(152, 67);
            textBoxAuthor.Name = "textBoxAuthor";
            textBoxAuthor.Size = new Size(194, 23);
            textBoxAuthor.TabIndex = 5;
            // 
            // textBoxGenre
            // 
            textBoxGenre.Location = new Point(152, 100);
            textBoxGenre.Name = "textBoxGenre";
            textBoxGenre.Size = new Size(194, 23);
            textBoxGenre.TabIndex = 6;
            // 
            // textBoxYear
            // 
            textBoxYear.Location = new Point(152, 141);
            textBoxYear.Name = "textBoxYear";
            textBoxYear.Size = new Size(194, 23);
            textBoxYear.TabIndex = 7;
            // 
            // saveButton
            // 
            saveButton.Location = new Point(52, 247);
            saveButton.Name = "saveButton";
            saveButton.Size = new Size(132, 42);
            saveButton.TabIndex = 8;
            saveButton.Text = "Сохранить";
            saveButton.UseVisualStyleBackColor = true;
            saveButton.Click += saveButton_Click;
            // 
            // deleteButton
            // 
            deleteButton.Location = new Point(214, 247);
            deleteButton.Name = "deleteButton";
            deleteButton.Size = new Size(132, 42);
            deleteButton.TabIndex = 9;
            deleteButton.Text = "Удалить";
            deleteButton.UseVisualStyleBackColor = true;
            deleteButton.Click += deleteButton_Click;
            // 
            // richTextBox1
            // 
            richTextBox1.Location = new Point(469, 34);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.ReadOnly = true;
            richTextBox1.Size = new Size(218, 262);
            richTextBox1.TabIndex = 10;
            richTextBox1.Text = "";
            // 
            // deleteInput
            // 
            deleteInput.Location = new Point(214, 218);
            deleteInput.Name = "deleteInput";
            deleteInput.Size = new Size(132, 23);
            deleteInput.TabIndex = 11;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(735, 318);
            Controls.Add(deleteInput);
            Controls.Add(richTextBox1);
            Controls.Add(deleteButton);
            Controls.Add(saveButton);
            Controls.Add(textBoxYear);
            Controls.Add(textBoxGenre);
            Controls.Add(textBoxAuthor);
            Controls.Add(textBoxName);
            Controls.Add(label4);
            Controls.Add(bookGenreLabel);
            Controls.Add(bookAuthorLabel);
            Controls.Add(bookNameLabel);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MaximizeBox = false;
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label bookNameLabel;
        private Label bookAuthorLabel;
        private Label bookGenreLabel;
        private Label label4;
        private TextBox textBoxName;
        private TextBox textBoxAuthor;
        private TextBox textBoxGenre;
        private TextBox textBoxYear;
        private Button saveButton;
        private Button deleteButton;
        private RichTextBox richTextBox1;
        private TextBox deleteInput;
    }
}
