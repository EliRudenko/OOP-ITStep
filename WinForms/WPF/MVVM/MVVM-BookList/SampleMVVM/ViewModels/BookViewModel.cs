using SampleMVVM.Models;
using SampleMVVM.Commands;
using System.Windows.Input;
using System.Windows;

namespace SampleMVVM.ViewModels
{
    class BookViewModel : DependencyObject
    {
        private static readonly DependencyProperty TitleProperty;
        private static readonly DependencyProperty AuthorProperty;
        private static readonly DependencyProperty CountProperty;
        private static readonly DependencyProperty NewTitleProperty;
        private static readonly DependencyProperty NewAuthorProperty;
        private MainViewModel mainViewModel;

        ListBook listBook;

        static BookViewModel()
        {
            TitleProperty = DependencyProperty.Register("Title", typeof(string), typeof(BookViewModel));
            AuthorProperty = DependencyProperty.Register("Author", typeof(string), typeof(BookViewModel));
            CountProperty = DependencyProperty.Register("Count", typeof(int), typeof(BookViewModel));
            NewTitleProperty = DependencyProperty.Register("NewTitle",typeof(string), typeof(BookViewModel));
            NewAuthorProperty = DependencyProperty.Register("NewAuthor", typeof(string), typeof(BookViewModel));
        }

        public BookViewModel(Book book,MainViewModel mainViewModel)
        {
            Title = book.Title;
            Author = book.Author;
            Count = book.Count;
            listBook = new ListBook();
            this.mainViewModel = mainViewModel;
        }

        public string Title
        {
            get { return (string)GetValue(TitleProperty); }
            set { SetValue(TitleProperty, value); }
        }

        public string Author
        {
            get { return (string)GetValue(AuthorProperty); }
            set { SetValue(AuthorProperty, value); }
        }

        public int Count
        {
            get { return (int)GetValue(CountProperty); }
            set { SetValue(CountProperty, value); }
        }

        private DelegateCommand getItemCommand;
        public ICommand GetItemCommand
        {
            get
            {
                if (getItemCommand == null)
                {
                    getItemCommand = new DelegateCommand(param => this.GetItem(), null);
                }
                return getItemCommand;
            }
        }

        private void GetItem()
        {
            Count++;
        }

        private DelegateCommand giveItemCommand;
        public ICommand GiveItemCommand
        {
            get
            {
                if (giveItemCommand == null)
                {
                    giveItemCommand = new DelegateCommand(param => GiveItem(), param => CanGiveItem());
                }
                return giveItemCommand;
            }
        }

        private void GiveItem()
        {
            Count--;
        }

        private bool CanGiveItem()
        {
            return Count > 0;
        }

        public string NewTitle
        {
            get { return (string)GetValue(NewTitleProperty); }
            set { SetValue(NewTitleProperty, value); }
        }
        public string NewAuthor
        {
            get { return (string)GetValue(NewAuthorProperty); }
            set { SetValue(NewAuthorProperty, value); }
        }
        private DelegateCommand addBookCommand;
        public ICommand AddBookCommand
        {
            get
            {
                if (addBookCommand == null)
                {
                    addBookCommand = new DelegateCommand(param => AddBook(), param => CanAddBook());
                }
                return addBookCommand;
            }
        }

        private bool CanAddBook()
        {
            return !string.IsNullOrEmpty(NewAuthor) && !string.IsNullOrEmpty(NewTitle);
        }

        private void AddBook()
        {
            Book newBook = new Book(NewTitle, NewAuthor, 1);
            listBook.AddBook(newBook);
            mainViewModel.BooksList.Add(new BookViewModel(newBook, mainViewModel));
            NewTitle = string.Empty;
            NewAuthor = string.Empty;
        }
    }
}
