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
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace AcademyDB
{
    public partial class LectureForm : Form
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();
        public LectureForm()
        {
            InitializeComponent();
        }

        private async void LectureForm_Load(object sender, EventArgs e)
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Lectures.ToListAsync();
                for (int i = 0; i < list.Count; i++)
                {
                    dict[i] = list[i].Id;
                    listBox1.Items.Add(list[i].LectureRoom);
                }
                var teachers = await db.Teachers.ToListAsync();
                var subjects = await db.Subjects.ToListAsync();
                foreach (var item in teachers)
                    comboBoxTeacher.Items.Add(item.Name + ' ' + item.Surname);
                foreach (var item in subjects)
                    comboBoxSubject.Items.Add(item.Name);
            }
        }

        private async void buttonAdd_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(textBoxName.Text) || comboBoxSubject.SelectedItem == null || comboBoxTeacher.SelectedItem == null)
            {
                MessageBox.Show("Some fields are empty");
                return;
            }

            using (var db = new AcademyContext())
            {
                var subject = await db.Subjects.FirstOrDefaultAsync(s => s.Name == comboBoxSubject.SelectedItem.ToString());
                if (subject == null)
                {
                    MessageBox.Show("There is no such subject in the database");
                    return;
                }
                var teacher = await db.Teachers.FirstOrDefaultAsync(t =>
                    (t.Name + " " + t.Surname) == comboBoxTeacher.SelectedItem.ToString());

                if (teacher == null)
                {
                    MessageBox.Show("There is no such teacher in the database");
                    return;
                }

                var lecture = new Lecture { LectureRoom = textBoxName.Text, Subject = subject, Teacher = teacher };

                await db.Lectures.AddAsync(lecture);
                await db.SaveChangesAsync();

                RegenerateDictionary();
                listBox1.Items.Add(lecture.LectureRoom);
            }

            MessageBox.Show("Faculty has been added");
        }

        private async void RegenerateDictionary()
        {
            using (var db = new AcademyContext())
            {
                var list = await db.Lectures.ToListAsync();
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
                var query = await db.Lectures.FirstOrDefaultAsync(t => t.Id == dict[index]);
                if (query == null)
                {
                    MessageBox.Show("Something went wrong..");
                    return;
                }
                db.Lectures.Remove(query);
                await db.SaveChangesAsync();

            }
            RegenerateDictionary();
            listBox1.Items.Remove(listBox1.Items[index]);
            MessageBox.Show("Lecture has been deleted");
        }
    }
}
