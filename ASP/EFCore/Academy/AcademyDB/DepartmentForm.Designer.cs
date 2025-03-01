namespace AcademyDB
{
    partial class DepartmentForm
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
            listBox1 = new ListBox();
            textBoxFinancing = new TextBox();
            salary = new Label();
            textBoxName = new TextBox();
            label1 = new Label();
            buttonDelete = new Button();
            buttonAdd = new Button();
            label2 = new Label();
            comboBox1 = new ComboBox();
            SuspendLayout();
            // 
            // listBox1
            // 
            listBox1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 30;
            listBox1.Location = new Point(261, 16);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(198, 274);
            listBox1.TabIndex = 24;
            // 
            // textBoxFinancing
            // 
            textBoxFinancing.Location = new Point(47, 174);
            textBoxFinancing.Name = "textBoxFinancing";
            textBoxFinancing.Size = new Size(100, 23);
            textBoxFinancing.TabIndex = 23;
            textBoxFinancing.KeyPress += textBoxFinancing_KeyPress;
            // 
            // salary
            // 
            salary.AutoSize = true;
            salary.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            salary.Location = new Point(47, 141);
            salary.Name = "salary";
            salary.Size = new Size(102, 30);
            salary.TabIndex = 22;
            salary.Text = "Financing";
            // 
            // textBoxName
            // 
            textBoxName.Location = new Point(47, 75);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(100, 23);
            textBoxName.TabIndex = 21;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(63, 42);
            label1.Name = "label1";
            label1.Size = new Size(69, 30);
            label1.TabIndex = 20;
            label1.Text = "Name";
            // 
            // buttonDelete
            // 
            buttonDelete.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonDelete.Location = new Point(320, 298);
            buttonDelete.Name = "buttonDelete";
            buttonDelete.Size = new Size(94, 43);
            buttonDelete.TabIndex = 19;
            buttonDelete.Text = "Delete";
            buttonDelete.UseVisualStyleBackColor = true;
            buttonDelete.Click += buttonDelete_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonAdd.Location = new Point(47, 298);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(94, 43);
            buttonAdd.TabIndex = 18;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label2.Location = new Point(55, 215);
            label2.Name = "label2";
            label2.Size = new Size(77, 30);
            label2.TabIndex = 25;
            label2.Text = "Faculty";
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(37, 248);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(121, 23);
            comboBox1.TabIndex = 26;
            // 
            // DepartmentForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(488, 371);
            Controls.Add(comboBox1);
            Controls.Add(label2);
            Controls.Add(listBox1);
            Controls.Add(textBoxFinancing);
            Controls.Add(salary);
            Controls.Add(textBoxName);
            Controls.Add(label1);
            Controls.Add(buttonDelete);
            Controls.Add(buttonAdd);
            Name = "DepartmentForm";
            Text = "DepartmentForm";
            Load += DepartmentForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListBox listBox1;
        private TextBox textBoxFinancing;
        private Label salary;
        private TextBox textBoxName;
        private Label label1;
        private Button buttonDelete;
        private Button buttonAdd;
        private Label label2;
        private ComboBox comboBox1;
    }
}