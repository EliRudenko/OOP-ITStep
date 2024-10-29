using System;
using System.Collections;
using System.Collections.Generic;

public class Book : ICloneable, IComparable<Book>
{
    public string Title { get; set; }
    public string Author { get; set; }
    public int Year { get; set; }
    public int Pages { get; set; }
    public string Genre { get; set; }

    public Book(string title, string author, int year, int pages, string genre)
    {
        Title = title;
        Author = author;
        Year = year;
        Pages = pages;
        Genre = genre;
    }

    public object Clone()
    {
        return new Book(Title, Author, Year, Pages, Genre);
    }

    public int CompareTo(Book other)
    {
        return Title.CompareTo(other.Title);
    }

    public override string ToString()
    {
        return $"Title: {Title}, Author: {Author}, Year: {Year}, Pages: {Pages}, Genre: {Genre}";
    }
}

public class BookComparer : IComparer<Book>
{
    public enum SortCriteria
    {
        Author,
        Year,
        Pages
    }

    private SortCriteria _criteria;

    public BookComparer(SortCriteria criteria)
    {
        _criteria = criteria;
    }

    public int Compare(Book x, Book y)
    {
        switch (_criteria)
        {
            case SortCriteria.Author:
                return x.Author.CompareTo(y.Author);
            case SortCriteria.Year:
                return x.Year.CompareTo(y.Year);
            case SortCriteria.Pages:
                return x.Pages.CompareTo(y.Pages);
            default:
                return 0;
        }
    }
}

public class Library
{
    private List<Book> books;

    public Library()
    {
        books = new List<Book>();
    }

    public void AddBook(Book book)
    {
        books.Add(book);
    }

    public void ShowBooks()
    {
        foreach (var book in books)
        {
            Console.WriteLine(book);
        }
    }

    public void SortBooks()
    {
        books.Sort();
    }

    public void SortBooks(IComparer<Book> comparer)
    {
        books.Sort(comparer);
    }
}

class Program
{
    static void Main()
    {
        Library library = new Library();
        
        library.AddBook(new Book("1", "Author 1", 2020, 150, "Fiction"));
        library.AddBook(new Book("2", "Author 2", 2018, 300, "Non-Fiction"));
        library.AddBook(new Book("3", "Author 3", 2021, 200, "Science"));

        Console.WriteLine("Список книг:");
        library.ShowBooks();

        Console.WriteLine("\nСортировка по умолчанию (по заголовку):");
        library.SortBooks();
        library.ShowBooks();

        Console.WriteLine("\nСортировка по автору:");
        library.SortBooks(new BookComparer(BookComparer.SortCriteria.Author));
        library.ShowBooks();

        Console.WriteLine("\nСортировка по году выпуска:");
        library.SortBooks(new BookComparer(BookComparer.SortCriteria.Year));
        library.ShowBooks();
    }
}
