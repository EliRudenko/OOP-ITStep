
namespace MVPBooksForm
{
    public partial class Form1 : Form, IView
    {

        public Book BookObj { get; set; }
        public Form1()
        {
            InitializeComponent();
            BookObj = new Book();

        }


        public event EventHandler<EventArgs> SaveToFileClicked;
        public event EventHandler<EventArgs> DeleteFromFileClicked;

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public void GetAllInfo()
        {
            BookObj.BookName = textBoxName.Text;
            BookObj.Author = textBoxAuthor.Text;
            BookObj.Genre = textBoxGenre.Text;
            BookObj.Year = int.Parse(textBoxYear.Text);
            BookObj.GiveId();
        }

        public string GetDelInputText()
        {
            return deleteInput.Text;
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            SaveToFileClicked?.Invoke(this, EventArgs.Empty);
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            DeleteFromFileClicked?.Invoke(this, EventArgs.Empty);
        }

        public void DisplaySaved()
        {
            MessageBox.Show("Book was saved");
        }

        public void DisplayDeleted()
        {
            MessageBox.Show("Book was deleted");
        }

        public void DisplayError(string message)
        {
            MessageBox.Show($"{message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private string FormattedBook(Book book)
        {
            return $"Title: {book.BookName}\t" +
                $"Author: {book.Author}\n";
        }

        public void ClearFields()
        {
            foreach (var control in this.Controls)
            {
                if (control is TextBox tb)
                    tb.Clear();
            }
        }

        public bool AreFieldsEmpty()
        {
            if (String.IsNullOrEmpty(textBoxName.Text))
                return true;
            if (String.IsNullOrEmpty(textBoxAuthor.Text))
                return true;
            if (String.IsNullOrEmpty(textBoxGenre.Text))
                return true;
            if (String.IsNullOrEmpty(textBoxYear.Text))
                return true;
            return false;
        }

        public bool IsDelInputEmpty()
        {
            return String.IsNullOrEmpty(deleteInput.Text);
        }

        public void ShowBooks(List<Book> books)
        {
            foreach (var book in books)
            {
                richTextBox1.AppendText(FormattedBook(book));
            }
        }

        public void ClearTextBox()
        {
            richTextBox1.Clear();
        }

        public DialogResult DisplayWarning(string message)
        {
            return MessageBox.Show($"{message}", "Warning", MessageBoxButtons.OKCancel, MessageBoxIcon.Warning);
        }

    }
}
