using Microsoft.EntityFrameworkCore;
using Models;

namespace AcademyDB
{
    public partial class CuratorForm : Form
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        public CuratorForm()
        {
            InitializeComponent();
        }

        private async void CuratorForm_Load(object sender, EventArgs e)
        {
            using (var db = new AcademyContext())
            {
                var query = await db.Curators.ToListAsync();
                if (query == null)
                    return;
                for (int i = 0; i < query.Count; i++)
                {
                    listBox1.Items.Add(query[i].Name + ' ' + query[i].Surname);
                    dict[i] = query[i].Id;
                }
            }
        }

        private async void buttonAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBoxName.Text) || string.IsNullOrEmpty(textBoxSurname.Text))
            {
                MessageBox.Show("Some fields are empty");
                return;
            }

            var curator = new Curator { Name = textBoxName.Text, Surname = textBoxSurname.Text };
            using (var db = new AcademyContext())
            {
                await db.Curators.AddAsync(curator);
                await db.SaveChangesAsync(); 


            }
            RegenerateDictionary();
            listBox1.Items.Add(curator.Name + " " + curator.Surname);
            MessageBox.Show("Curator has been added");
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
                var query = await db.Curators.FirstOrDefaultAsync(t => t.Id == dict[index]);
                if (query == null)
                {
                    MessageBox.Show("Something went wrong..");
                    return;
                }
                db.Curators.Remove(query);
                await db.SaveChangesAsync();

            }
            RegenerateDictionary();
            listBox1.Items.Remove(listBox1.Items[index]);
            MessageBox.Show("Curator has been deleted");
        }
        private async void RegenerateDictionary()
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Curators.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                    dict[i] = list[i].Id;
            }
        }
    }
}
