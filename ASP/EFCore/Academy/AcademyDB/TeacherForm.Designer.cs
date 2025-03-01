namespace AcademyDB
{
    partial class TeacherForm
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
            buttonAdd = new Button();
            buttonDelete = new Button();
            label1 = new Label();
            textBoxName = new TextBox();
            textBoxSurname = new TextBox();
            label2 = new Label();
            textBoxSalary = new TextBox();
            salary = new Label();
            listBox1 = new ListBox();
            SuspendLayout();
            // 
            // buttonAdd
            // 
            buttonAdd.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonAdd.Location = new Point(21, 243);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(94, 43);
            buttonAdd.TabIndex = 0;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // buttonDelete
            // 
            buttonDelete.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonDelete.Location = new Point(286, 243);
            buttonDelete.Name = "buttonDelete";
            buttonDelete.Size = new Size(94, 43);
            buttonDelete.TabIndex = 1;
            buttonDelete.Text = "Delete";
            buttonDelete.UseVisualStyleBackColor = true;
            buttonDelete.Click += buttonDelete_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(37, 18);
            label1.Name = "label1";
            label1.Size = new Size(69, 30);
            label1.TabIndex = 2;
            label1.Text = "Name";
            // 
            // textBoxName
            // 
            textBoxName.Location = new Point(21, 51);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(100, 23);
            textBoxName.TabIndex = 3;
            // 
            // textBoxSurname
            // 
            textBoxSurname.Location = new Point(21, 121);
            textBoxSurname.Name = "textBoxSurname";
            textBoxSurname.Size = new Size(100, 23);
            textBoxSurname.TabIndex = 5;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label2.Location = new Point(26, 88);
            label2.Name = "label2";
            label2.Size = new Size(95, 30);
            label2.TabIndex = 4;
            label2.Text = "Surname";
            // 
            // textBoxSalary
            // 
            textBoxSalary.Location = new Point(21, 191);
            textBoxSalary.Name = "textBoxSalary";
            textBoxSalary.Size = new Size(100, 23);
            textBoxSalary.TabIndex = 7;
            textBoxSalary.KeyPress += textBoxSalary_KeyPress;
            // 
            // salary
            // 
            salary.AutoSize = true;
            salary.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            salary.Location = new Point(37, 158);
            salary.Name = "salary";
            salary.Size = new Size(68, 30);
            salary.TabIndex = 6;
            salary.Text = "Salary";
            // 
            // listBox1
            // 
            listBox1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 30;
            listBox1.Location = new Point(235, 18);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(198, 214);
            listBox1.TabIndex = 8;
            // 
            // TeacherForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(445, 316);
            Controls.Add(listBox1);
            Controls.Add(textBoxSalary);
            Controls.Add(salary);
            Controls.Add(textBoxSurname);
            Controls.Add(label2);
            Controls.Add(textBoxName);
            Controls.Add(label1);
            Controls.Add(buttonDelete);
            Controls.Add(buttonAdd);
            Name = "TeacherForm";
            Text = "TeacherForm";
            Load += TeacherForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button buttonAdd;
        private Button buttonDelete;
        private Label label1;
        private TextBox textBoxName;
        private TextBox textBoxSurname;
        private Label label2;
        private TextBox textBoxSalary;
        private Label salary;
        private ListBox listBox1;
    }
}