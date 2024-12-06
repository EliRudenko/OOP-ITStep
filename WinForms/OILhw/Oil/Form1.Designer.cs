namespace Oil
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
            groupMiniCafe = new GroupBox();
            textBoxAmount4 = new TextBox();
            textBoxAmount3 = new TextBox();
            textBoxAmount2 = new TextBox();
            textBoxAmount1 = new TextBox();
            textBoxPrice4 = new TextBox();
            textBoxPrice3 = new TextBox();
            textBoxPrice2 = new TextBox();
            textBoxPrice1 = new TextBox();
            cafeAmountLabel = new Label();
            cafePriceLabel = new Label();
            coke = new CheckBox();
            frenchFries = new CheckBox();
            hamburger = new CheckBox();
            hotDog = new CheckBox();
            groupBoxToPayCafe = new GroupBox();
            cafeEndPrice = new Label();
            label1 = new Label();
            groupGasStation = new GroupBox();
            groupBoxToPay = new GroupBox();
            gasEndPrice = new Label();
            gasSumTextBox = new TextBox();
            gasAmountTextBox = new TextBox();
            groupSettersPrice = new GroupBox();
            radioButtonGasSum = new RadioButton();
            radioButtonGasCount = new RadioButton();
            gasPriceText = new TextBox();
            gasPriceLabel = new Label();
            comboBoxGas = new ComboBox();
            labelGas = new Label();
            groupBoxOverall = new GroupBox();
            overallEndPrice = new Label();
            button1 = new Button();
            groupMiniCafe.SuspendLayout();
            groupBoxToPayCafe.SuspendLayout();
            groupGasStation.SuspendLayout();
            groupBoxToPay.SuspendLayout();
            groupSettersPrice.SuspendLayout();
            groupBoxOverall.SuspendLayout();
            SuspendLayout();
            // 
            // groupMiniCafe
            // 
            groupMiniCafe.Controls.Add(textBoxAmount4);
            groupMiniCafe.Controls.Add(textBoxAmount3);
            groupMiniCafe.Controls.Add(textBoxAmount2);
            groupMiniCafe.Controls.Add(textBoxAmount1);
            groupMiniCafe.Controls.Add(textBoxPrice4);
            groupMiniCafe.Controls.Add(textBoxPrice3);
            groupMiniCafe.Controls.Add(textBoxPrice2);
            groupMiniCafe.Controls.Add(textBoxPrice1);
            groupMiniCafe.Controls.Add(cafeAmountLabel);
            groupMiniCafe.Controls.Add(cafePriceLabel);
            groupMiniCafe.Controls.Add(coke);
            groupMiniCafe.Controls.Add(frenchFries);
            groupMiniCafe.Controls.Add(hamburger);
            groupMiniCafe.Controls.Add(hotDog);
            groupMiniCafe.Controls.Add(groupBoxToPayCafe);
            groupMiniCafe.Location = new Point(278, 20);
            groupMiniCafe.Name = "groupMiniCafe";
            groupMiniCafe.Size = new Size(256, 339);
            groupMiniCafe.TabIndex = 1;
            groupMiniCafe.TabStop = false;
            groupMiniCafe.Text = "Міні-кафе";
            // 
            // textBoxAmount4
            // 
            textBoxAmount4.Location = new Point(183, 148);
            textBoxAmount4.Name = "textBoxAmount4";
            textBoxAmount4.Size = new Size(55, 23);
            textBoxAmount4.TabIndex = 17;
            textBoxAmount4.TextChanged += textBoxAmount4_TextChanged;
            // 
            // textBoxAmount3
            // 
            textBoxAmount3.Location = new Point(184, 113);
            textBoxAmount3.Name = "textBoxAmount3";
            textBoxAmount3.Size = new Size(55, 23);
            textBoxAmount3.TabIndex = 16;
            textBoxAmount3.TextChanged += textBoxAmount3_TextChanged;
            // 
            // textBoxAmount2
            // 
            textBoxAmount2.Location = new Point(183, 77);
            textBoxAmount2.Name = "textBoxAmount2";
            textBoxAmount2.Size = new Size(55, 23);
            textBoxAmount2.TabIndex = 15;
            textBoxAmount2.TextChanged += textBoxAmount2_TextChanged;
            // 
            // textBoxAmount1
            // 
            textBoxAmount1.Location = new Point(184, 41);
            textBoxAmount1.Name = "textBoxAmount1";
            textBoxAmount1.Size = new Size(55, 23);
            textBoxAmount1.TabIndex = 14;
            textBoxAmount1.TextChanged += textBoxAmount1_TextChanged;
            // 
            // textBoxPrice4
            // 
            textBoxPrice4.Location = new Point(115, 148);
            textBoxPrice4.Name = "textBoxPrice4";
            textBoxPrice4.ReadOnly = true;
            textBoxPrice4.Size = new Size(55, 23);
            textBoxPrice4.TabIndex = 13;
            // 
            // textBoxPrice3
            // 
            textBoxPrice3.Location = new Point(115, 113);
            textBoxPrice3.Name = "textBoxPrice3";
            textBoxPrice3.ReadOnly = true;
            textBoxPrice3.Size = new Size(55, 23);
            textBoxPrice3.TabIndex = 12;
            // 
            // textBoxPrice2
            // 
            textBoxPrice2.Location = new Point(115, 77);
            textBoxPrice2.Name = "textBoxPrice2";
            textBoxPrice2.ReadOnly = true;
            textBoxPrice2.Size = new Size(55, 23);
            textBoxPrice2.TabIndex = 11;
            // 
            // textBoxPrice1
            // 
            textBoxPrice1.Location = new Point(115, 41);
            textBoxPrice1.Name = "textBoxPrice1";
            textBoxPrice1.ReadOnly = true;
            textBoxPrice1.Size = new Size(55, 23);
            textBoxPrice1.TabIndex = 10;
            // 
            // cafeAmountLabel
            // 
            cafeAmountLabel.AutoSize = true;
            cafeAmountLabel.Location = new Point(183, 19);
            cafeAmountLabel.Name = "cafeAmountLabel";
            cafeAmountLabel.Size = new Size(56, 15);
            cafeAmountLabel.TabIndex = 9;
            cafeAmountLabel.Text = "Кількість";
            // 
            // cafePriceLabel
            // 
            cafePriceLabel.AutoSize = true;
            cafePriceLabel.Location = new Point(125, 19);
            cafePriceLabel.Name = "cafePriceLabel";
            cafePriceLabel.Size = new Size(32, 15);
            cafePriceLabel.TabIndex = 8;
            cafePriceLabel.Text = "Ціна";
            // 
            // coke
            // 
            coke.AutoSize = true;
            coke.Location = new Point(6, 152);
            coke.Name = "coke";
            coke.Size = new Size(15, 14);
            coke.TabIndex = 7;
            coke.UseVisualStyleBackColor = true;
            coke.CheckedChanged += coke_CheckedChanged;
            // 
            // frenchFries
            // 
            frenchFries.AutoSize = true;
            frenchFries.Location = new Point(6, 117);
            frenchFries.Name = "frenchFries";
            frenchFries.Size = new Size(15, 14);
            frenchFries.TabIndex = 6;
            frenchFries.UseVisualStyleBackColor = true;
            frenchFries.CheckedChanged += frenchFries_CheckedChanged;
            // 
            // hamburger
            // 
            hamburger.AutoSize = true;
            hamburger.Location = new Point(6, 81);
            hamburger.Name = "hamburger";
            hamburger.Size = new Size(15, 14);
            hamburger.TabIndex = 5;
            hamburger.UseVisualStyleBackColor = true;
            hamburger.CheckedChanged += hamburger_CheckedChanged;
            // 
            // hotDog
            // 
            hotDog.AutoSize = true;
            hotDog.Location = new Point(6, 45);
            hotDog.Name = "hotDog";
            hotDog.Size = new Size(15, 14);
            hotDog.TabIndex = 4;
            hotDog.UseVisualStyleBackColor = true;
            hotDog.CheckedChanged += hotDog_CheckedChanged;
            // 
            // groupBoxToPayCafe
            // 
            groupBoxToPayCafe.Controls.Add(cafeEndPrice);
            groupBoxToPayCafe.Controls.Add(label1);
            groupBoxToPayCafe.Location = new Point(6, 212);
            groupBoxToPayCafe.Name = "groupBoxToPayCafe";
            groupBoxToPayCafe.Size = new Size(200, 100);
            groupBoxToPayCafe.TabIndex = 3;
            groupBoxToPayCafe.TabStop = false;
            groupBoxToPayCafe.Text = "До сплати (грн.)";
            // 
            // cafeEndPrice
            // 
            cafeEndPrice.AutoSize = true;
            cafeEndPrice.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            cafeEndPrice.ImageAlign = ContentAlignment.TopRight;
            cafeEndPrice.Location = new Point(106, 35);
            cafeEndPrice.Name = "cafeEndPrice";
            cafeEndPrice.Size = new Size(58, 32);
            cafeEndPrice.TabIndex = 1;
            cafeEndPrice.Text = "0,00";
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(91, 35);
            label1.Name = "label1";
            label1.Size = new Size(0, 32);
            label1.TabIndex = 0;
            // 
            // groupGasStation
            // 
            groupGasStation.Controls.Add(groupBoxToPay);
            groupGasStation.Controls.Add(gasSumTextBox);
            groupGasStation.Controls.Add(gasAmountTextBox);
            groupGasStation.Controls.Add(groupSettersPrice);
            groupGasStation.Controls.Add(gasPriceText);
            groupGasStation.Controls.Add(gasPriceLabel);
            groupGasStation.Controls.Add(comboBoxGas);
            groupGasStation.Controls.Add(labelGas);
            groupGasStation.ForeColor = SystemColors.ActiveCaptionText;
            groupGasStation.Location = new Point(20, 20);
            groupGasStation.Name = "groupGasStation";
            groupGasStation.Size = new Size(235, 339);
            groupGasStation.TabIndex = 0;
            groupGasStation.TabStop = false;
            groupGasStation.Text = "Автозаправка";
            // 
            // groupBoxToPay
            // 
            groupBoxToPay.Controls.Add(gasEndPrice);
            groupBoxToPay.Location = new Point(10, 212);
            groupBoxToPay.Name = "groupBoxToPay";
            groupBoxToPay.Size = new Size(200, 100);
            groupBoxToPay.TabIndex = 2;
            groupBoxToPay.TabStop = false;
            groupBoxToPay.Text = "До сплати (грн.)";
            // 
            // gasEndPrice
            // 
            gasEndPrice.AutoSize = true;
            gasEndPrice.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            gasEndPrice.Location = new Point(91, 35);
            gasEndPrice.Name = "gasEndPrice";
            gasEndPrice.Size = new Size(58, 32);
            gasEndPrice.TabIndex = 0;
            gasEndPrice.Text = "0,00";
            // 
            // gasSumTextBox
            // 
            gasSumTextBox.Location = new Point(127, 166);
            gasSumTextBox.Name = "gasSumTextBox";
            gasSumTextBox.Size = new Size(100, 23);
            gasSumTextBox.TabIndex = 7;
            gasSumTextBox.TextChanged += gasSumTextBox_TextChanged;
            // 
            // gasAmountTextBox
            // 
            gasAmountTextBox.Location = new Point(127, 132);
            gasAmountTextBox.Name = "gasAmountTextBox";
            gasAmountTextBox.Size = new Size(100, 23);
            gasAmountTextBox.TabIndex = 6;
            gasAmountTextBox.TextChanged += gasAmountTextBox_TextChanged;
            // 
            // groupSettersPrice
            // 
            groupSettersPrice.Controls.Add(radioButtonGasSum);
            groupSettersPrice.Controls.Add(radioButtonGasCount);
            groupSettersPrice.Location = new Point(14, 117);
            groupSettersPrice.Name = "groupSettersPrice";
            groupSettersPrice.Size = new Size(103, 75);
            groupSettersPrice.TabIndex = 5;
            groupSettersPrice.TabStop = false;
            // 
            // radioButtonGasSum
            // 
            radioButtonGasSum.AutoSize = true;
            radioButtonGasSum.Location = new Point(5, 50);
            radioButtonGasSum.Name = "radioButtonGasSum";
            radioButtonGasSum.Size = new Size(87, 19);
            radioButtonGasSum.TabIndex = 1;
            radioButtonGasSum.TabStop = true;
            radioButtonGasSum.Text = "Сума (грн.)";
            radioButtonGasSum.UseVisualStyleBackColor = true;
            radioButtonGasSum.CheckedChanged += radioButtonGasSum_CheckedChanged;
            // 
            // radioButtonGasCount
            // 
            radioButtonGasCount.AutoSize = true;
            radioButtonGasCount.Location = new Point(5, 16);
            radioButtonGasCount.Name = "radioButtonGasCount";
            radioButtonGasCount.Size = new Size(95, 19);
            radioButtonGasCount.TabIndex = 0;
            radioButtonGasCount.TabStop = true;
            radioButtonGasCount.Text = "Кількість (л.)";
            radioButtonGasCount.UseVisualStyleBackColor = true;
            radioButtonGasCount.CheckedChanged += radioButtonGasCount_CheckedChanged;
            // 
            // gasPriceText
            // 
            gasPriceText.Location = new Point(79, 77);
            gasPriceText.Name = "gasPriceText";
            gasPriceText.ReadOnly = true;
            gasPriceText.Size = new Size(100, 23);
            gasPriceText.TabIndex = 4;
            // 
            // gasPriceLabel
            // 
            gasPriceLabel.AutoSize = true;
            gasPriceLabel.Location = new Point(10, 80);
            gasPriceLabel.Name = "gasPriceLabel";
            gasPriceLabel.Size = new Size(65, 15);
            gasPriceLabel.TabIndex = 3;
            gasPriceLabel.Text = "Ціна (грн.)";
            // 
            // comboBoxGas
            // 
            comboBoxGas.DropDownStyle = ComboBoxStyle.DropDownList;
            comboBoxGas.FormattingEnabled = true;
            comboBoxGas.Location = new Point(79, 30);
            comboBoxGas.Name = "comboBoxGas";
            comboBoxGas.Size = new Size(100, 23);
            comboBoxGas.Sorted = true;
            comboBoxGas.TabIndex = 2;
            comboBoxGas.SelectedIndexChanged += comboBoxGas_SelectedIndexChanged;
            // 
            // labelGas
            // 
            labelGas.AutoSize = true;
            labelGas.Location = new Point(10, 30);
            labelGas.Name = "labelGas";
            labelGas.Size = new Size(46, 15);
            labelGas.TabIndex = 0;
            labelGas.Text = "Бензин";
            // 
            // groupBoxOverall
            // 
            groupBoxOverall.Controls.Add(button1);
            groupBoxOverall.Controls.Add(overallEndPrice);
            groupBoxOverall.Location = new Point(26, 383);
            groupBoxOverall.Name = "groupBoxOverall";
            groupBoxOverall.Size = new Size(508, 100);
            groupBoxOverall.TabIndex = 2;
            groupBoxOverall.TabStop = false;
            groupBoxOverall.Text = "ВСЬОГО до сплати (грн.)";
            // 
            // overallEndPrice
            // 
            overallEndPrice.AutoSize = true;
            overallEndPrice.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point);
            overallEndPrice.Location = new Point(364, 43);
            overallEndPrice.Name = "overallEndPrice";
            overallEndPrice.Size = new Size(58, 32);
            overallEndPrice.TabIndex = 1;
            overallEndPrice.Text = "0,00";
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 12F, FontStyle.Regular, GraphicsUnit.Point);
            button1.Location = new Point(13, 43);
            button1.Name = "button1";
            button1.Size = new Size(143, 31);
            button1.TabIndex = 2;
            button1.Text = "Прорахувати";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(563, 504);
            Controls.Add(groupBoxOverall);
            Controls.Add(groupMiniCafe);
            Controls.Add(groupGasStation);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            MaximizeBox = false;
            Name = "Form1";
            Text = "BestOil";
            Load += Form1_Load;
            groupMiniCafe.ResumeLayout(false);
            groupMiniCafe.PerformLayout();
            groupBoxToPayCafe.ResumeLayout(false);
            groupBoxToPayCafe.PerformLayout();
            groupGasStation.ResumeLayout(false);
            groupGasStation.PerformLayout();
            groupBoxToPay.ResumeLayout(false);
            groupBoxToPay.PerformLayout();
            groupSettersPrice.ResumeLayout(false);
            groupSettersPrice.PerformLayout();
            groupBoxOverall.ResumeLayout(false);
            groupBoxOverall.PerformLayout();
            ResumeLayout(false);
        }

        #endregion
        private GroupBox groupMiniCafe;
        private GroupBox groupGasStation;
        private Label labelGas;
        private ComboBox comboBoxGas;
        private Label gasPriceLabel;
        private TextBox gasPriceText;
        private GroupBox groupSettersPrice;
        private RadioButton radioButtonGasCount;
        private RadioButton radioButtonGasSum;
        private TextBox gasSumTextBox;
        private TextBox gasAmountTextBox;
        private GroupBox groupBoxToPay;
        private Label gasEndPrice;
        private GroupBox groupBoxToPayCafe;
        private Label label1;
        private CheckBox coke;
        private CheckBox frenchFries;
        private CheckBox hamburger;
        private CheckBox hotDog;
        private Label cafePriceLabel;
        private Label cafeAmountLabel;
        private TextBox textBoxAmount4;
        private TextBox textBoxAmount3;
        private TextBox textBoxAmount2;
        private TextBox textBoxAmount1;
        private TextBox textBoxPrice4;
        private TextBox textBoxPrice3;
        private TextBox textBoxPrice2;
        private TextBox textBoxPrice1;
        private Label cafeEndPrice;
        private GroupBox groupBoxOverall;
        private Button button1;
        private Label overallEndPrice;
    }
}