using System.Windows.Forms;
using System;

namespace ForbiddenWordsFinder
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код генератора компонента

        private void InitializeComponent()
        {
            this.grpControls = new System.Windows.Forms.GroupBox();
            this.txtForbiddenWords = new System.Windows.Forms.TextBox();
            this.btnAddWord = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.btnLoadForbiddenWords = new System.Windows.Forms.Button();
            this.btnSelectFolder = new System.Windows.Forms.Button();
            this.btnSaveResult = new System.Windows.Forms.Button();
            this.lblForbiddenWords = new System.Windows.Forms.Label();
            this.lblFolderPath = new System.Windows.Forms.Label();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.lstForbiddenWords = new System.Windows.Forms.ListBox();
            this.lstReport = new System.Windows.Forms.ListBox();
            this.lstFoundWords = new System.Windows.Forms.ListBox();
            this.grpReport = new System.Windows.Forms.GroupBox();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.folderBrowserDialog = new System.Windows.Forms.FolderBrowserDialog();
            this.grpControls.SuspendLayout();
            this.grpReport.SuspendLayout();
            this.SuspendLayout();
            // 
            // grpControls
            // 
            this.grpControls.Controls.Add(this.txtForbiddenWords);
            this.grpControls.Controls.Add(this.btnAddWord);
            this.grpControls.Controls.Add(this.btnStart);
            this.grpControls.Controls.Add(this.btnLoadForbiddenWords);
            this.grpControls.Controls.Add(this.btnSelectFolder);
            this.grpControls.Controls.Add(this.btnSaveResult);
            this.grpControls.Controls.Add(this.lblForbiddenWords);
            this.grpControls.Controls.Add(this.lblFolderPath);
            this.grpControls.Controls.Add(this.progressBar);
            this.grpControls.Controls.Add(this.lstForbiddenWords);
            this.grpControls.Location = new System.Drawing.Point(12, 12);
            this.grpControls.Name = "grpControls";
            this.grpControls.Size = new System.Drawing.Size(685, 294);
            this.grpControls.TabIndex = 0;
            this.grpControls.TabStop = false;
            // 
            // txtForbiddenWords
            // 
            this.txtForbiddenWords.Location = new System.Drawing.Point(214, 30);
            this.txtForbiddenWords.Name = "txtForbiddenWords";
            this.txtForbiddenWords.Size = new System.Drawing.Size(194, 22);
            this.txtForbiddenWords.TabIndex = 1;
            // 
            // btnAddWord
            // 
            this.btnAddWord.BackColor = System.Drawing.Color.LightSkyBlue;
            this.btnAddWord.Location = new System.Drawing.Point(414, 30);
            this.btnAddWord.Name = "btnAddWord";
            this.btnAddWord.Size = new System.Drawing.Size(100, 22);
            this.btnAddWord.TabIndex = 2;
            this.btnAddWord.Text = "Добавить";
            this.btnAddWord.UseVisualStyleBackColor = true;
            this.btnAddWord.Click += new System.EventHandler(this.BtnAddWord_Click);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.GreenYellow;
            this.btnStart.Location = new System.Drawing.Point(368, 197);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(146, 30);
            this.btnStart.TabIndex = 7;
            this.btnStart.Text = "Старт";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.BtnStart_Click);
            // 
            // btnLoadForbiddenWords
            // 
            this.btnLoadForbiddenWords.BackColor = System.Drawing.Color.LightSkyBlue;
            this.btnLoadForbiddenWords.Location = new System.Drawing.Point(214, 64);
            this.btnLoadForbiddenWords.Name = "btnLoadForbiddenWords";
            this.btnLoadForbiddenWords.Size = new System.Drawing.Size(300, 40);
            this.btnLoadForbiddenWords.TabIndex = 3;
            this.btnLoadForbiddenWords.Text = "Загрузить txt файл";
            this.btnLoadForbiddenWords.UseVisualStyleBackColor = true;
            this.btnLoadForbiddenWords.Click += new System.EventHandler(this.BtnLoadForbiddenWords_Click);
            // 
            // btnSelectFolder
            // 
            this.btnSelectFolder.BackColor = System.Drawing.Color.LightSkyBlue;
            this.btnSelectFolder.Location = new System.Drawing.Point(214, 131);
            this.btnSelectFolder.Name = "btnSelectFolder";
            this.btnSelectFolder.Size = new System.Drawing.Size(300, 40);
            this.btnSelectFolder.TabIndex = 4;
            this.btnSelectFolder.Text = "Выбрать папку";
            this.btnSelectFolder.UseVisualStyleBackColor = true;
            this.btnSelectFolder.Click += new System.EventHandler(this.BtnSelectFolder_Click);
            // 
            // btnSaveResult
            // 
            this.btnSaveResult.BackColor = System.Drawing.Color.LightSkyBlue;
            this.btnSaveResult.Location = new System.Drawing.Point(10, 247);
            this.btnSaveResult.Name = "btnSaveResult";
            this.btnSaveResult.Size = new System.Drawing.Size(505, 27);
            this.btnSaveResult.TabIndex = 5;
            this.btnSaveResult.Text = "Сохранить результат";
            this.btnSaveResult.UseVisualStyleBackColor = true;
            this.btnSaveResult.Click += new System.EventHandler(this.BtnSaveResult_Click);
            // 
            // lblForbiddenWords
            // 
            this.lblForbiddenWords.AutoSize = true;
            this.lblForbiddenWords.Location = new System.Drawing.Point(7, 33);
            this.lblForbiddenWords.Name = "lblForbiddenWords";
            this.lblForbiddenWords.Size = new System.Drawing.Size(201, 16);
            this.lblForbiddenWords.TabIndex = 5;
            this.lblForbiddenWords.Text = "Введите запрещенные слова:";
            // 
            // lblFolderPath
            // 
            this.lblFolderPath.AutoSize = true;
            this.lblFolderPath.Location = new System.Drawing.Point(6, 143);
            this.lblFolderPath.Name = "lblFolderPath";
            this.lblFolderPath.Size = new System.Drawing.Size(190, 16);
            this.lblFolderPath.TabIndex = 6;
            this.lblFolderPath.Text = "Выберите папку с файлами:";
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(10, 197);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(352, 30);
            this.progressBar.TabIndex = 8;
            // 
            // lstForbiddenWords
            // 
            this.lstForbiddenWords.FormattingEnabled = true;
            this.lstForbiddenWords.ItemHeight = 16;
            this.lstForbiddenWords.Location = new System.Drawing.Point(520, 30);
            this.lstForbiddenWords.Name = "lstForbiddenWords";
            this.lstForbiddenWords.Size = new System.Drawing.Size(153, 244);
            this.lstForbiddenWords.TabIndex = 9;
            // 
            // lstReport
            // 
            this.lstReport.Location = new System.Drawing.Point(0, 0);
            this.lstReport.Name = "lstReport";
            this.lstReport.Size = new System.Drawing.Size(120, 96);
            this.lstReport.TabIndex = 0;
            // 
            // lstFoundWords
            // 
            this.lstFoundWords.FormattingEnabled = true;
            this.lstFoundWords.ItemHeight = 16;
            this.lstFoundWords.Location = new System.Drawing.Point(10, 30);
            this.lstFoundWords.Name = "lstFoundWords";
            this.lstFoundWords.Size = new System.Drawing.Size(284, 244);
            this.lstFoundWords.TabIndex = 10;
            // 
            // grpReport
            // 
            this.grpReport.Controls.Add(this.lstFoundWords);
            this.grpReport.Location = new System.Drawing.Point(703, 12);
            this.grpReport.Name = "grpReport";
            this.grpReport.Size = new System.Drawing.Size(304, 294);
            this.grpReport.TabIndex = 11;
            this.grpReport.TabStop = false;
            this.grpReport.Text = "Результат";
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(1021, 317);
            this.Controls.Add(this.grpReport);
            this.Controls.Add(this.grpControls);
            this.Name = "Form1";
            this.Text = "Поиск запрещённых слов";
            this.grpControls.ResumeLayout(false);
            this.grpControls.PerformLayout();
            this.grpReport.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox grpControls;
        private System.Windows.Forms.TextBox txtForbiddenWords;
        private System.Windows.Forms.Button btnAddWord;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Button btnLoadForbiddenWords;
        private System.Windows.Forms.Button btnSelectFolder;
        private System.Windows.Forms.Button btnSaveResult;
        private System.Windows.Forms.Label lblForbiddenWords;
        private System.Windows.Forms.Label lblFolderPath;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.ListBox lstForbiddenWords;
        private System.Windows.Forms.ListBox lstFoundWords;
        private System.Windows.Forms.ListBox lstReport;
        private System.Windows.Forms.GroupBox grpReport;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.FolderBrowserDialog folderBrowserDialog;

        

    }
}
