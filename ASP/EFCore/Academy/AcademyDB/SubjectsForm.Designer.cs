namespace AcademyDB
{
    partial class SubjectsForm
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
            textBox1 = new TextBox();
            listBoxSubjects = new ListBox();
            SuspendLayout();
            // 
            // buttonAdd
            // 
            buttonAdd.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonAdd.Location = new Point(38, 210);
            buttonAdd.Name = "buttonAdd";
            buttonAdd.Size = new Size(105, 49);
            buttonAdd.TabIndex = 0;
            buttonAdd.Text = "Add";
            buttonAdd.UseVisualStyleBackColor = true;
            buttonAdd.Click += buttonAdd_Click;
            // 
            // buttonDelete
            // 
            buttonDelete.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            buttonDelete.Location = new Point(214, 207);
            buttonDelete.Name = "buttonDelete";
            buttonDelete.Size = new Size(105, 52);
            buttonDelete.TabIndex = 1;
            buttonDelete.Text = "Delete";
            buttonDelete.UseVisualStyleBackColor = true;
            buttonDelete.Click += buttonDelete_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label1.Location = new Point(51, 76);
            label1.Name = "label1";
            label1.Size = new Size(69, 30);
            label1.TabIndex = 2;
            label1.Text = "Name";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(26, 109);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(117, 23);
            textBox1.TabIndex = 3;
            // 
            // listBoxSubjects
            // 
            listBoxSubjects.Font = new Font("Segoe UI", 15.75F, FontStyle.Regular, GraphicsUnit.Point, 204);
            listBoxSubjects.FormattingEnabled = true;
            listBoxSubjects.ItemHeight = 30;
            listBoxSubjects.Location = new Point(186, 35);
            listBoxSubjects.Name = "listBoxSubjects";
            listBoxSubjects.Size = new Size(159, 154);
            listBoxSubjects.TabIndex = 4;
            // 
            // SubjectsForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(348, 287);
            Controls.Add(listBoxSubjects);
            Controls.Add(textBox1);
            Controls.Add(label1);
            Controls.Add(buttonDelete);
            Controls.Add(buttonAdd);
            Name = "SubjectsForm";
            Text = "SubjectsForm";
            Load += SubjectsForm_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button buttonAdd;
        private Button buttonDelete;
        private Label label1;
        private TextBox textBox1;
        private ListBox listBoxSubjects;
    }
}