namespace AcademyDB
{
    partial class CuratorForm
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
            textBoxSurname = new TextBox();
            label2 = new Label();
            textBoxName = new TextBox();
            label1 = new Label();
            buttonDelete = new Button();
            buttonAdd = new Button();
            SuspendLayout();
            // 
            // listBox1
            // 
            listBox1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 30;
            listBox1.Location = new Point(279, 20);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(198, 214);
            listBox1.TabIndex = 17;
            // 
            // textBoxSurname
            // 
            textBoxSurname.Location = new Point(59, 158);
            textBoxSurname.Name = "textBoxSurname";
            textBoxSurname.Size = new Size(100, 23);
            textBoxSurname.TabIndex = 14;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label2.Location = new Point(64, 125);
            label2.Name = "label2";
            label2.Size = new Size(95, 30);
            label2.TabIndex = 13;
            label2.Text = "Surname";
            // 
            // textBoxName
            // 
            textBoxName.Location = new Point(59, 88);
            textBoxName.Name = "textBoxName";
            textBoxName.Size = new Size(100, 23);
            textBoxName.TabIndex = 12;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(75, 55);
            label1.Name = "label1";
            label1.Size = new Size(69, 30);
            label1.TabIndex = 11;
            label1.Text = "Name";
            // 
            // buttonDelete
            // 
            buttonDelete.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonDelete.Location = new Point(332, 245);
            buttonDelete.Name = "buttonDelete";
            buttonDelete.Size = new Size(94, 43);
            buttonDelete.TabIndex = 10;
            buttonDelete.Text = "Delete";
            buttonDelete.UseVisualStyleBackColor = true;
            buttonDelete.Click += buttonDelete_Click;
            // 
            // buttonAdd
            // 
            buttonAdd.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonAdd.Location = new Point(65, 245);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(94, 43);
            buttonAdd.TabIndex = 9;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // CuratorForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(542, 308);
            Controls.Add(listBox1);
            Controls.Add(textBoxSurname);
            Controls.Add(label2);
            Controls.Add(textBoxName);
            Controls.Add(label1);
            Controls.Add(buttonDelete);
            Controls.Add(buttonAdd);
            Name = "CuratorForm";
            Text = "CuratorForm";
            Load += CuratorForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private ListBox listBox1;
        private TextBox textBoxSurname;
        private Label label2;
        private TextBox textBoxName;
        private Label label1;
        private Button buttonDelete;
        private Button buttonAdd;
    }
}