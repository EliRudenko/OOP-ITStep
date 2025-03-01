using Microsoft.EntityFrameworkCore;
using Models;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AcademyDB
{
    public partial class FacultyForm : Form
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        public FacultyForm()
        {
            InitializeComponent();
        }

        private async void FacultyForm_Load(object sender, EventArgs e)
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Faculties.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                {
                    dict[i] = list[i].Id;
                    listBox1.Items.Add(list[i].Name);
                }
            }
        }

        private async void RegenerateDictionary()
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Faculties.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                    dict[i] = list[i].Id;
            }
        }

        private void textBoxFinancing_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsDigit(e.KeyChar))
                e.Handled = true;
        }

        private async void buttonAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBoxName.Text) || string.IsNullOrEmpty(textBoxFinancing.Text))
            {
                MessageBox.Show("Some fields are empty");
                return;
            }

            var faculty = new Faculty { Name = textBoxName.Text, Financing = decimal.Parse(textBoxFinancing.Text) };
            using (var db = new AcademyContext())
            {
                await db.Faculties.AddAsync(faculty);
                await db.SaveChangesAsync();
            }
            RegenerateDictionary();
            listBox1.Items.Add(faculty.Name);
            MessageBox.Show("Faculty has been added");
        }

        private async void buttonDelete_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedItem == null)
            {
                MessageBox.Show("You need to choose a faculty");
                return;
            }

            int index = listBox1.SelectedIndex;
            using (var db = new AcademyContext())
            {
                var query = await db.Faculties.FirstOrDefaultAsync(t => t.Id == dict[index]);
                if (query == null)
                {
                    MessageBox.Show("Something went wrong..");
                    return;
                }
                db.Faculties.Remove(query);
                await db.SaveChangesAsync();

            }
            RegenerateDictionary();
            listBox1.Items.Remove(listBox1.Items[index]);
            MessageBox.Show("Faculty has been deleted");
        }
    }
}
