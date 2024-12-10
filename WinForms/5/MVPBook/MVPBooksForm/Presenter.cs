namespace MVPBooksForm
{
    public class Presenter
    {
        Model model;
        IView view;
        public Presenter(IModel _model, IView _view)
        {
            model = (Model?)_model;
            view = _view;
            model.LoadBooksFromJSON();
            view.ShowBooks(model.Books);
            view.SaveToFileClicked += new EventHandler<EventArgs>(SaveToFile);
            view.SaveToFileClicked += new EventHandler<EventArgs>(DisplayList);
            view.DeleteFromFileClicked += new EventHandler<EventArgs>(DeleteFromFile);
            view.DeleteFromFileClicked += new EventHandler<EventArgs>(DisplayList);
        }

        public void SaveToFile(object sender, EventArgs e)
        {
            view.GetAllInfo();
            if (view.BookObj.Year < 0 || view.BookObj.Year > DateTime.Now.Year)
            {
                view.DisplayError("Year is not correct");
                RefreshTextBox();
                return;
            }
            if (view.AreFieldsEmpty())
            {
                view.DisplayError("Some fields are empty.");
                return;
            }
            model.AddBookToList(view.BookObj);
            RefreshTextBox();
            view.DisplaySaved();
        }

        public void DisplayList(object sender,EventArgs e)
        {
            model.LoadBooksFromJSON();
            view.ShowBooks(model.Books);
        }

        public void DeleteFromFile(object sender, EventArgs e)
        {
            if (view.IsDelInputEmpty())
            {
                view.DisplayError("Delete input is empty");
                RefreshTextBox();
                return;
            }

            DialogResult res = view.DisplayWarning("Are you sure want to delete it?");
            if (res != DialogResult.OK) {
                RefreshTextBox();
                return;
            }
            model.DeleteFromFile(view.GetDelInputText());
            RefreshTextBox();
            view.DisplayDeleted();
        }

        private void RefreshTextBox()
        {
            view.ClearTextBox();
            model.SaveToFile();
        }


    }
}
