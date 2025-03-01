namespace AcademyDB
{
    partial class MainForm
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
            buttonSubjects = new Button();
            buttonTeachers = new Button();
            buttonCurators = new Button();
            buttonFaculties = new Button();
            buttonDepartments = new Button();
            buttonLectures = new Button();
            SuspendLayout();
            // 
            // buttonSubjects
            // 
            buttonSubjects.Font = new Font("Segoe UI", 15.75F);
            buttonSubjects.Location = new Point(129, 15);
            buttonSubjects.Name = "buttonSubjects";
            buttonSubjects.Size = new Size(141, 39);
            buttonSubjects.TabIndex = 0;
            buttonSubjects.Text = "Subjects";
            buttonSubjects.UseVisualStyleBackColor = true;
            buttonSubjects.Click += buttonSubjects_Click;
            // 
            // buttonTeachers
            // 
            buttonTeachers.Font = new Font("Segoe UI", 15.75F);
            buttonTeachers.Location = new Point(129, 60);
            buttonTeachers.Name = "buttonTeachers";
            buttonTeachers.Size = new Size(141, 46);
            buttonTeachers.TabIndex = 1;
            buttonTeachers.Text = "Teachers";
            buttonTeachers.UseVisualStyleBackColor = true;
            buttonTeachers.Click += buttonTeachers_Click;
            // 
            // buttonCurators
            // 
            buttonCurators.Font = new Font("Segoe UI", 15.75F);
            buttonCurators.Location = new Point(129, 112);
            buttonCurators.Name = "buttonCurators";
            buttonCurators.Size = new Size(141, 44);
            buttonCurators.TabIndex = 2;
            buttonCurators.Text = "Curators";
            buttonCurators.UseVisualStyleBackColor = true;
            buttonCurators.Click += buttonCurators_Click;
            // 
            // buttonFaculties
            // 
            buttonFaculties.Font = new Font("Segoe UI", 15.75F);
            buttonFaculties.Location = new Point(129, 162);
            buttonFaculties.Name = "buttonFaculties";
            buttonFaculties.Size = new Size(141, 42);
            buttonFaculties.TabIndex = 3;
            buttonFaculties.Text = "Faculties";
            buttonFaculties.UseVisualStyleBackColor = true;
            buttonFaculties.Click += buttonFaculties_Click;
            // 
            // buttonDepartments
            // 
            buttonDepartments.Font = new Font("Segoe UI", 15.75F);
            buttonDepartments.Location = new Point(129, 214);
            buttonDepartments.Name = "buttonDepartments";
            buttonDepartments.Size = new Size(141, 43);
            buttonDepartments.TabIndex = 4;
            buttonDepartments.Text = "Departments";
            buttonDepartments.UseVisualStyleBackColor = true;
            buttonDepartments.Click += buttonDepartments_Click;
            // 
            // buttonLectures
            // 
            buttonLectures.Font = new Font("Segoe UI", 15.75F);
            buttonLectures.Location = new Point(129, 263);
            buttonLectures.Name = "buttonLectures";
            buttonLectures.Size = new Size(141, 37);
            buttonLectures.TabIndex = 5;
            buttonLectures.Text = "Lectures";
            buttonLectures.UseVisualStyleBackColor = true;
            buttonLectures.Click += buttonLectures_Click;
            // 
            // MainForm
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(395, 312);
            Controls.Add(buttonLectures);
            Controls.Add(buttonDepartments);
            Controls.Add(buttonFaculties);
            Controls.Add(buttonCurators);
            Controls.Add(buttonTeachers);
            Controls.Add(buttonSubjects);
            Name = "MainForm";
            Text = "Form1";
            ResumeLayout(false);
        }

        #endregion

        private Button buttonSubjects;
        private Button buttonTeachers;
        private Button buttonCurators;
        private Button buttonFaculties;
        private Button buttonDepartments;
        private Button buttonLectures;
    }
}
