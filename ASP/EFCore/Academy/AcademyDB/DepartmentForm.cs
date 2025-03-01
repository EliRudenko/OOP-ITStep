using Microsoft.EntityFrameworkCore;
using Models;

namespace AcademyDB
{
    public partial class DepartmentForm : Form
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        public DepartmentForm()
        {
            InitializeComponent();
        }

        private async void DepartmentForm_Load(object sender, EventArgs e)
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Departments.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                {
                    dict[i] = list[i].Id;
                    listBox1.Items.Add(list[i].Name + '-' + list[i].Faculty.Name);
                }

                var faculties = await db.Faculties.ToListAsync();
                foreach (var item in faculties)
                    comboBox1.Items.Add(item.Name);
            }
        }

        private async void buttonAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBoxName.Text) || string.IsNullOrEmpty(textBoxFinancing.Text) || comboBox1.SelectedItem == null)
            {
                MessageBox.Show("Some fields are empty");
                return;
            }
            using (var db = new AcademyContext())
            {
                var faculty = await db.Faculties.FirstOrDefaultAsync(f => f.Name == comboBox1.SelectedItem.ToString());

                if (faculty == null)
                {
                    MessageBox.Show("Selected faculty does not exist in the database.");
                    return;
                }

                var isExisting = await db.Departments.FirstOrDefaultAsync(d => d.Name == textBoxName.Text);
                if (isExisting != null)
                {
                    MessageBox.Show("This department already exists");
                    return;
                }

                var department = new Department { Name = textBoxName.Text, Financing = decimal.Parse(textBoxFinancing.Text), Faculty = faculty };
                await db.Departments.AddAsync(department);
                await db.SaveChangesAsync();

                RegenerateDictionary();
                listBox1.Items.Add(department.Name + '-' + faculty.Name);
            }

            MessageBox.Show("Department has been added");
        }

        private async void RegenerateDictionary()
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Departments.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                    dict[i] = list[i].Id;
            }
        }

        private async void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem == null)
            {
                MessageBox.Show("You need to choose a department");
                return;
            }

            int index = listBox1.SelectedIndex;
            using (var db = new AcademyContext())
            {
                var query = await db.Departments.FirstOrDefaultAsync(t => t.Id == dict[index]);
                if (query == null)
                {
                    MessageBox.Show("Something went wrong..");
                    return;
                }
                db.Departments.Remove(query);
                await db.SaveChangesAsync();

            }
            RegenerateDictionary();
            listBox1.Items.Remove(listBox1.Items[index]);
            MessageBox.Show("Department has been deleted");
        }

        private void textBoxFinancing_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar))
                e.Handled = true;
        }
    }
}
