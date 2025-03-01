using Microsoft.EntityFrameworkCore;
using Models;

namespace IT_Employee_WinForms
{
    public partial class DBForm : Form
    {
        bool editClicked = false;
        Employee? tmpEmployee = null;
        public DBForm()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            string? fname = string.IsNullOrEmpty(textBoxFirstName.Text) ? null : textBoxFirstName.Text;
            string? lname = string.IsNullOrEmpty(textBoxLastName.Text) ? null : textBoxLastName.Text;
            string? positionText = comboBox1.Text;

            Position position;
            using (var db = new EmployeeContext())
            {
                position = await db.Positions
                    .FirstOrDefaultAsync(p => p.Name == positionText);

                var employee = new Employee { FirstName = fname, LastName = lname, Position = position };

                try
                {
                    await db.Employees.AddAsync(employee);
                    await db.SaveChangesAsync();
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"{ex.Message}");
                    Logger.Log(ex.Message);
                    return;
                }
            }

            string added = "Employee has been added";
            MessageBox.Show(added);
            Logger.Log(added);



        }

        private void Form1_Load(object sender, EventArgs e)
        {
            foreach (var item in EmployeeContext.pos_constraints)
                comboBox1.Items.Add(item);

            comboBox1.SelectedIndex = comboBox1.Items.IndexOf("Employee");
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            string? fname = string.IsNullOrEmpty(textBoxFirstName.Text) ? null : textBoxFirstName.Text;
            string? lname = string.IsNullOrEmpty(textBoxLastName.Text) ? null : textBoxLastName.Text;

            using (var db = new EmployeeContext())
            {

                try
                {
                    var employee = await db.Employees
                        .FirstOrDefaultAsync(p => p.FirstName == fname && p.LastName == lname);

                    if (employee != null)
                        db.Employees.Remove(employee);
                    await db.SaveChangesAsync();
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"{ex.Message}");
                    Logger.Log(ex.Message);
                    return;
                }
            }
            string deleted = "Employee has been deleted";
            Logger.Log(deleted);
            MessageBox.Show(deleted);
        }

        private async void button3_Click(object sender, EventArgs e)
        {
            string? fname, lname;

            if (!editClicked)
            {
                editClicked = true;
                fname = string.IsNullOrEmpty(textBoxFirstName.Text) ? null : textBoxFirstName.Text;
                lname = string.IsNullOrEmpty(textBoxLastName.Text) ? null : textBoxLastName.Text;

                using (var db = new EmployeeContext())
                {
                    tmpEmployee = await db.Employees
                        .FirstOrDefaultAsync(p => p.FirstName == fname && p.LastName == lname);

                    if (tmpEmployee == null)
                    {
                        string notFound = "Employee not found.";
                        MessageBox.Show(notFound);
                        Logger.Log(notFound);

                        editClicked = false;
                        return;
                    }
                }
                return;
            }

            fname = string.IsNullOrEmpty(textBoxFirstName.Text) ? null : textBoxFirstName.Text;
            lname = string.IsNullOrEmpty(textBoxLastName.Text) ? null : textBoxLastName.Text;
            Position position;

            using (var db = new EmployeeContext())
            {
                try
                {
                    position = await db.Positions
                        .FirstOrDefaultAsync(p => p.Name == comboBox1.Text);

                    if (tmpEmployee != null)
                    {
                        var newEmployee = await db.Employees.FirstOrDefaultAsync(p => p.FirstName == tmpEmployee.FirstName && p.LastName == tmpEmployee.LastName);
                        newEmployee.FirstName = fname;
                        newEmployee.LastName = lname;
                        newEmployee.Position = position;

                        await db.SaveChangesAsync();

                        string updated = "Employee has been updated";
                        MessageBox.Show(updated);
                        Logger.Log(updated);
                    }
                    else
                    {
                        MessageBox.Show("No employee to update.");
                        Logger.Log("No employee to update");
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Error: {ex.Message}");
                    Logger.Log(ex.Message);
                    return;
                }
            }

            tmpEmployee = null;
            editClicked = false;
        }

        private async void button5_Click(object sender, EventArgs e)
        {
            string? fname = string.IsNullOrEmpty(textBoxFirstName.Text) ? null : textBoxFirstName.Text;
            string? lname = string.IsNullOrEmpty(textBoxLastName.Text) ? null : textBoxLastName.Text;

            using (var db = new EmployeeContext())
            {
                Employee? employee = null;

                if (!string.IsNullOrEmpty(fname) && !string.IsNullOrEmpty(lname))
                {
                    employee = await db.Employees
                        .FirstOrDefaultAsync(p => p.FirstName == fname && p.LastName == lname);
                }
                else if (!string.IsNullOrEmpty(lname) && string.IsNullOrEmpty(fname))
                {
                    employee = await db.Employees
                        .FirstOrDefaultAsync(p => p.LastName == lname);
                }
                else if (string.IsNullOrEmpty(lname) && !string.IsNullOrEmpty(fname))
                {
                    employee = await db.Employees
                        .FirstOrDefaultAsync(p => p.FirstName == fname);
                }

                Position position = await db.Positions.FirstOrDefaultAsync(e => employee.PositionId == e.Id);

                if (employee != null)
                {
                    MessageBox.Show($"First name - {employee.FirstName}\n" +
                                     $"Last name - {employee.LastName}\n" +
                                     $"Position - {position.Name}");
                }
                else
                {
                    MessageBox.Show("Employee not found.");
                    Logger.Log("Employee not found");
                }
            }
        }
    }
}
