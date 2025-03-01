using Microsoft.EntityFrameworkCore;
using Models;
using System.Text.RegularExpressions;

namespace IT_Employee_WinForms
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }

        private async void buttonLogin_Click(object sender, EventArgs e)
        {
            if (CheckForEmpty())
            {
                MessageBox.Show("Some fields are empty");
                Logger.Log($"Failed sign in due to empty fields");
                return;
            }

            string login = textBoxLogin.Text;
            string password = textBoxPassword.Text;
            var user = new User { Login = login, Password = password };

            using (var db = new EmployeeContext())
            {
                var query = await db.Users.FirstOrDefaultAsync(u => u.Password == password && u.Login == login);

                if (query == null)
                {
                    MessageBox.Show("There is no such user. Try again");
                    Logger.Log("Failed sign in. No such user");
                    return;
                }

                Logger.Log($"{login} logged in");

                DBForm dbForm = new DBForm();
                dbForm.ShowDialog();
            }
        }

        private bool CheckForEmpty()
        {
            return string.IsNullOrEmpty(textBoxLogin.Text) || string.IsNullOrEmpty(textBoxPassword.Text);
        }

        private bool CheckForRegex(string login,string password)
        {
            if(!Regex.IsMatch(login, @"^(?=.{3,20}$)(?![_.])(?!.*[_.]{2})[a-zA-Z0-9._]+(?<![_.])$"))
                return true;
            if(!Regex.IsMatch(password, @"^(?=.*[a-z])(?=.*\d)[A-Za-z\d_]{9,}$"))
                return true;

            return false;
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            if (CheckForEmpty())
            {
                MessageBox.Show("Some fields are empty");
                Logger.Log($"Failed sign in due to empty fields");
                return;
            }

            string login = textBoxLogin.Text;
            string password = textBoxPassword.Text;

            if (CheckForRegex(login,password))
            {
                MessageBox.Show("Incorrect format of some of the fields");
                Logger.Log("Failed sign up due to incorrect regex format");
                return;
            }

            var user = new User { Login = login, Password = password };

            using (var db = new EmployeeContext())
            {
                var query = await db.Users.FirstOrDefaultAsync(u => u.Login == login);
                if (query != null)
                {
                    MessageBox.Show("This login already exists");
                    Logger.Log("Failed sign up. Login already exists");
                    return;
                }

                await db.Users.AddAsync(user);
                await db.SaveChangesAsync();

                Logger.Log($"{user.Login} signed up successfully");

                DBForm dbForm = new DBForm();
                dbForm.ShowDialog();

            }
        }
    }
}
