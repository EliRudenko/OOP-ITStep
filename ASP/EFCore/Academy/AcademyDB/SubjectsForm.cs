using Microsoft.EntityFrameworkCore;
using Models;

namespace AcademyDB
{
    public partial class SubjectsForm : Form
    {
        Dictionary<int,int> rowIdPairs = new Dictionary<int,int>();
        public SubjectsForm()
        {
            InitializeComponent();
        }

        private async void buttonAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBox1.Text))
            {
                MessageBox.Show("Name field is empty");
                return;
            }
            var subj = new Subject { Name = textBox1.Text };
            using (var db = new AcademyContext())
            {
                var query = db.Subjects.FirstOrDefault(s => s.Name == subj.Name);
                if (query != null)
                {
                    MessageBox.Show("This subject already exists");
                    return;
                }

                await db.Subjects.AddAsync(subj);
                await db.SaveChangesAsync();

            }
            RegenerateDictionary();
            listBoxSubjects.Items.Add(subj.Name);
            MessageBox.Show("Subject has been added");
        }

        private async void buttonDelete_Click(object sender, EventArgs e)
        {
            if(listBoxSubjects.SelectedItem == null)
            {
                MessageBox.Show("Pick a subject to delete");
                return;
            }

            int index = listBoxSubjects.SelectedIndex;

            using (var db = new AcademyContext())
            {
                var query = db.Subjects.FirstOrDefault(s => s.Id == rowIdPairs[index]);
                if (query == null)
                {
                    MessageBox.Show("Something went wrong..");
                    return;
                }
                db.Subjects.Remove(query);
                await db.SaveChangesAsync();

            }

            RegenerateDictionary();

            listBoxSubjects.Items.Remove(listBoxSubjects.Items[index]);
            MessageBox.Show("Subject has been deleted");
        }

        private void SubjectsForm_Load(object sender, EventArgs e)
        {
            using (var db = new AcademyContext())
            {
                var query = db.Subjects.ToList();
                for (int i = 0; i < query.Count; i++)
                {
                    listBoxSubjects.Items.Add(query[i].Name);
                    rowIdPairs[i] = query[i].Id;
                }
            }
        }

        private async void RegenerateDictionary()
        {
            using(var db = new AcademyContext())
            {
                var list = await db.Subjects.ToListAsync();
                for (int i = 0; i < list.Count; i++) 
                    rowIdPairs[i] = list[i].Id;
            }
        }
    }
}
