namespace AcademyDB
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void buttonSubjects_Click(object sender, EventArgs e)
        {
            var subjForm = new SubjectsForm();
            subjForm.ShowDialog();
        }

        private void buttonTeachers_Click(object sender, EventArgs e)
        {
            var teachersForm = new TeacherForm();
            teachersForm.ShowDialog();
        }

        private void buttonCurators_Click(object sender, EventArgs e)
        {
            var curatorForm = new CuratorForm();
            curatorForm.ShowDialog();
        }

        private void buttonFaculties_Click(object sender, EventArgs e)
        {
            var facultyForm = new FacultyForm();
            facultyForm.ShowDialog();
        }

        private void buttonDepartments_Click(object sender, EventArgs e)
        {
            var departmentForm = new DepartmentForm();
            departmentForm.ShowDialog();
        }

        private void buttonLectures_Click(object sender, EventArgs e)
        {
            var lectureForm = new LectureForm();
            lectureForm.ShowDialog();
        }
    }
}
