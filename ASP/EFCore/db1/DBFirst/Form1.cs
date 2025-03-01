using Microsoft.EntityFrameworkCore;
using System.Data;
// Scaffold-DbContext "Data Source=C:\\Users\\morri\\OneDrive\\Рабочий стол\\Library.db" Microsoft.EntityFrameworkCore.Sqlite
namespace DBFirst
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private async void button1_Click(object sender, EventArgs e)
        {
            using (var db = new LibraryContext())
            {
                listBox1.Items.Clear();
                var query = await db.Authors.Select(x => x.Name).ToListAsync();
                foreach (var item in query)
                {
                    listBox1.Items.Add(item);
                }
            }
        }

        private async void button2_Click(object sender, EventArgs e)
        {
            using (var db = new LibraryContext())
            {
                listBox1.Items.Clear();

                var query = await db.Books.Select(x => x.Name).ToListAsync();
                foreach (var item in query)
                {
                    listBox1.Items.Add(item);
                }
            }
        }

        private async void button3_Click(object sender, EventArgs e)
        {
            using (var db = new LibraryContext())
            {
                listBox1.Items.Clear();

                var query = await db.Students.Select(x => x.Name).ToListAsync();
                foreach (var item in query)
                {
                    listBox1.Items.Add(item);
                }
            }
        }

        private async void button4_Click(object sender, EventArgs e)
        {
            using (var db = new LibraryContext())
            {
                listBox1.Items.Clear();

                var query = await db.Groups.Select(x => x.Name).ToListAsync();
                foreach (var item in query)
                {
                    listBox1.Items.Add(item);
                }
            }
        }
    }
}
