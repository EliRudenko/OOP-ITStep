namespace AcademyDB
{
    partial class LectureForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            comboBoxSubject = new ComboBox();
            label2 = new Label();
            listBox1 = new ListBox();
            textBoxName = new TextBox();
            label1 = new Label();
            buttonDelete = new Button();
            buttonAdd = new Button();
            comboBoxTeacher = new ComboBox();
            label3 = new Label();
            SuspendLayout();
            // 
            // comboBoxSubject
            // 
            comboBoxSubject.FormattingEnabled = true;
            comboBoxSubject.Location = new Point(42, 151);
            comboBoxSubject.Name = "comboBoxSubject";
            comboBoxSubject.Size = new Size(121, 23);
            comboBoxSubject.TabIndex = 35;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label2.Location = new Point(60, 118);
            label2.Name = "label2";
            label2.Size = new Size(81, 30);
            label2.TabIndex = 34;
            label2.Text = "Subject";
            // 
            // listBox1
            // 
            listBox1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 30;
            listBox1.Location = new Point(266, 24);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(198, 274);
            listBox1.TabIndex = 33;
            // 
            // textBoxName
            // 
            textBoxName.Location = new Point(42, 83);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(121, 23);
            textBoxName.TabIndex = 30;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(42, 50);
            label1.Name = "label1";
            label1.Size = new Size(141, 30);
            label1.TabIndex = 29;
            label1.Text = "Lecture Room";
            // 
            // buttonDelete
            // 
            buttonDelete.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonDelete.Location = new Point(325, 306);
            buttonDelete.Name = "buttonDelete";
            buttonDelete.Size = new Size(94, 43);
            buttonDelete.TabIndex = 28;
            buttonDelete.Text = "Delete";
            buttonDelete.UseVisualStyleBackColor = true;
            buttonDelete.Click += buttonDelete_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonAdd.Location = new Point(52, 306);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(94, 43);
            buttonAdd.TabIndex = 27;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // comboBoxTeacher
            // 
            comboBoxTeacher.FormattingEnabled = true;
            comboBoxTeacher.Location = new Point(42, 223);
            comboBoxTeacher.Name = "comboBoxTeacher";
            comboBoxTeacher.Size = new Size(121, 23);
            comboBoxTeacher.TabIndex = 37;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label3.Location = new Point(60, 190);
            label3.Name = "label3";
            label3.Size = new Size(84, 30);
            label3.TabIndex = 36;
            label3.Text = "Teacher";
            // 
            // LectureForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(500, 360);
            Controls.Add(comboBoxTeacher);
            Controls.Add(label3);
            Controls.Add(comboBoxSubject);
            Controls.Add(label2);
            Controls.Add(listBox1);
            Controls.Add(textBoxName);
            Controls.Add(label1);
            Controls.Add(buttonDelete);
            Controls.Add(buttonAdd);
            Name = "LectureForm";
            Text = "LectureForm";
            Load += LectureForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ComboBox comboBoxSubject;
        private Label label2;
        private ListBox listBox1;
        private TextBox textBoxName;
        private Label label1;
        private Button buttonDelete;
        private Button buttonAdd;
        private ComboBox comboBoxTeacher;
        private Label label3;
    }
}