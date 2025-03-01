using Microsoft.EntityFrameworkCore;
using Models;

namespace AcademyDB
{
    public partial class TeacherForm : Form
    {
        public TeacherForm()
        {
            InitializeComponent();
        }
        Dictionary<int, int> dict = new Dictionary<int, int>();

        private void textBoxSalary_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        private async void buttonAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBoxSalary.Text) || string.IsNullOrEmpty(textBoxName.Text) || string.IsNullOrEmpty(textBoxSurname.Text))
            {
                MessageBox.Show("Some fieds are empty");
                return;
            }

            var teacher = new Teacher { Name = textBoxName.Text, Surname = textBoxSurname.Text, Salary = decimal.Parse(textBoxSalary.Text) };
            using (var db = new AcademyContext())
            {
                var query = db.Teachers.FirstOrDefault(t => t == teacher);
                if (query != null)
                {
                    MessageBox.Show("There is this person in the database");
                    return;
                }
                await db.Teachers.AddAsync(teacher);
                await db.SaveChangesAsync();
            }

            RegenerateDictionary();
            listBox1.Items.Add(teacher.Name + ' ' + teacher.Surname);
            MessageBox.Show("Teacher has been added");
        }


        private void TeacherForm_Load(object sender, EventArgs e)
        {
            using (var db = new AcademyContext())
            {
                var query = db.Teachers.ToList();
                for (int i = 0; i < query.Count; i++)
                {
                    listBox1.Items.Add(query[i].Name + ' ' + query[i].Surname);
                    dict[i] = query[i].Id;
                }
            }
        }

        private async void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem == null)
            {
                MessageBox.Show("You need to choose a teacher");
                return;
            }

            int index = listBox1.SelectedIndex;
            using (var db = new AcademyContext())
            {
                var query = await db.Teachers.FirstOrDefaultAsync(t => t.Id == dict[index]);
                if (query == null)
                {
                    MessageBox.Show("Something went wrong..");
                    return;
                }
                db.Teachers.Remove(query);
                await db.SaveChangesAsync();

            }
            RegenerateDictionary();
            listBox1.Items.Remove(listBox1.Items[index]);
            MessageBox.Show("Teacher has been deleted");
        }

        private async void RegenerateDictionary()
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Teachers.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                    dict[i] = list[i].Id;
            }
        }

    }
}
