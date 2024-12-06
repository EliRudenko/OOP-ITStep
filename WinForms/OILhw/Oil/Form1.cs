namespace Oil
{
    public partial class Form1 : Form
    {
        Dictionary<string, double> gasesAndValues = new Dictionary<string, double>()
        {
            { "A-92", 52.84 },
            { "A-95", 55.23 },
            { "A-95 Premium", 58.38 },
            { "������", 51.95 }
        };

        Dictionary<string, double> productsAndValues = new Dictionary<string, double>()
        {
            {"���-���",4.00 },
            {"���������",5.40 },
            {"��������-��",7.20 },
            {"����-����",4.40 }
        };


        public Form1()
        {
            InitializeComponent();

            foreach (var item in gasesAndValues)
                comboBoxGas.Items.Add(item.Key);

            int productName_ind = 0;
            int productValue_ind = 0;
            int skippedTextBoxes = 0;

            foreach (Control control in groupMiniCafe.Controls)
            {
                if (control is CheckBox checkBox)
                {
                    if (productName_ind < productsAndValues.Count)
                        checkBox.Text = productsAndValues.Keys.ElementAt(productName_ind++);
                }

                if (control is TextBox textBox)
                {
                    if (skippedTextBoxes < 4)
                    {
                        control.Enabled = false;
                        skippedTextBoxes++;
                        continue;
                    }

                    if (productValue_ind < productsAndValues.Count)
                        textBox.Text = productsAndValues.Values.ElementAt(productValue_ind++).ToString("F2");
                }
            }
        }



        private void Form1_Load(object sender, EventArgs e)
        {
            gasAmountTextBox.Enabled = gasSumTextBox.Enabled = false;
            radioButtonGasCount.Enabled = radioButtonGasSum.Enabled = false;
        }

        private void comboBoxGas_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (!radioButtonGasSum.Enabled)
            {
                radioButtonGasSum.Enabled = radioButtonGasCount.Enabled = true;
            }

            string selectedGas = comboBoxGas.SelectedItem.ToString();

            if (gasesAndValues.ContainsKey(selectedGas))
                gasPriceText.Text = $"{gasesAndValues[selectedGas]:F2}";
        }

        private void radioButtonGasCount_CheckedChanged(object sender, EventArgs e)
        {
            gasSumTextBox.Enabled = false;
            gasAmountTextBox.Enabled = true;
            gasAmountTextBox.Text = string.Empty;
            gasEndPrice.Text = "0.00";
            gasSumTextBox.Text = "0.00";
        }

        private void radioButtonGasSum_CheckedChanged(object sender, EventArgs e)
        {
            gasAmountTextBox.Enabled = false;
            gasSumTextBox.Enabled = true;
            gasSumTextBox.Text = string.Empty;
            gasEndPrice.Text = "0.00";
            gasAmountTextBox.Text = "0.00";
        }

        private void gasAmountTextBox_TextChanged(object sender, EventArgs e)
        {
            if (radioButtonGasCount.Checked)
            {

                if (double.TryParse(gasAmountTextBox.Text, out double writtenPrice) &&
                    double.TryParse(gasPriceText.Text, out double priceForLiter))
                {
                    if (writtenPrice > 0 && priceForLiter > 0)
                    {
                        double totalPrice = writtenPrice * priceForLiter;
                        gasEndPrice.Text = totalPrice.ToString("F2");
                        gasSumTextBox.Text = gasEndPrice.Text;
                    }
                    else
                    {
                        gasEndPrice.Text = "0.00";
                        gasSumTextBox.Text = "0.00";
                    }
                }
                else
                {
                    gasEndPrice.Text = "0.00";
                    gasSumTextBox.Text = "0.00";
                }
            }
        }

        private void gasSumTextBox_TextChanged(object sender, EventArgs e)
        {
            if (radioButtonGasSum.Checked)
            {

                if (double.TryParse(gasSumTextBox.Text, out double writtenSum) &&
                    double.TryParse(gasPriceText.Text, out double priceForLiter))
                {
                    if (writtenSum > 0 && priceForLiter > 0)
                    {
                        double amount = writtenSum / priceForLiter;
                        gasAmountTextBox.Text = amount.ToString("F2");
                        gasEndPrice.Text = writtenSum.ToString("F2");
                    }
                    else
                    {
                        gasEndPrice.Text = "0.00";
                        gasAmountTextBox.Text = "0.00";
                    }
                }
                else
                {
                    gasEndPrice.Text = "0.00";
                    gasAmountTextBox.Text = "0.00";
                }
            }
        }

        private void hotDog_CheckedChanged(object sender, EventArgs e)
        {
            textBoxAmount1.Enabled = hotDog.Checked;

            if (!hotDog.Checked)
            {
                textBoxAmount1.Text = string.Empty;
            }
        }

        private void hamburger_CheckedChanged(object sender, EventArgs e)
        {
            textBoxAmount2.Enabled = hamburger.Checked;

            if (!hamburger.Checked)
            {
                textBoxAmount2.Text = string.Empty;
            }
        }

        private void frenchFries_CheckedChanged(object sender, EventArgs e)
        {
            textBoxAmount3.Enabled = frenchFries.Checked;

            if (!frenchFries.Checked)
            {
                textBoxAmount3.Text = string.Empty;
            }
        }

        private void coke_CheckedChanged(object sender, EventArgs e)
        {
            textBoxAmount4.Enabled = coke.Checked;

            if (!coke.Checked)
            {
                textBoxAmount4.Text = string.Empty;
            }
        }


        private void ProductAmount_TextChanged(object sender, TextBox textPrice, EventArgs e, string productName)
        {
            if (sender is TextBox textBox)
            {
                double price = double.Parse(textPrice.Text);

                if (double.TryParse(textBox.Text, out double quantity) && quantity >= 0)
                {
                    double totalPrice = quantity * price;
                }
                else
                    cafeEndPrice.Text = "0.00";
            }

            UpdateCafeEndPrice();

        }

        private void textBoxAmount1_TextChanged(object sender, EventArgs e)
        {
            ProductAmount_TextChanged(sender, textBoxPrice1, e, "���-���");
        }

        private void textBoxAmount2_TextChanged(object sender, EventArgs e)
        {
            ProductAmount_TextChanged(sender, textBoxPrice2, e, "���������");
        }

        private void textBoxAmount3_TextChanged(object sender, EventArgs e)
        {
            ProductAmount_TextChanged(sender, textBoxPrice3, e, "��������-��");
        }

        private void textBoxAmount4_TextChanged(object sender, EventArgs e)
        {
            ProductAmount_TextChanged(sender, textBoxPrice4, e, "����-����");
        }

        private void UpdateCafeEndPrice()
        {
            double totalCafePrice = 0;

            totalCafePrice += GetProductTotal(textBoxAmount1, textBoxPrice1, "���-���");
            totalCafePrice += GetProductTotal(textBoxAmount2, textBoxPrice2, "���������");
            totalCafePrice += GetProductTotal(textBoxAmount3, textBoxPrice3, "��������-��");
            totalCafePrice += GetProductTotal(textBoxAmount4, textBoxPrice4, "����-����");

            cafeEndPrice.Text = totalCafePrice.ToString("F2");
        }


        private double GetProductTotal(TextBox textBox, TextBox priceTextBox, string productName)
        {
            double productTotal = 0;
            double price = double.Parse(priceTextBox.Text);

            if (double.TryParse(textBox.Text, out double quantity) && quantity >= 0)
                productTotal = quantity * price;

            return productTotal;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double cafePrice = double.Parse(cafeEndPrice.Text);
            double gasPrice = double.Parse(gasEndPrice.Text);

            overallEndPrice.Text = (cafePrice + gasPrice).ToString("F2");
        }
    }


}
