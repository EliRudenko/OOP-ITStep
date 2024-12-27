using SampleMVVM.ViewModels;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization.Json;

namespace SampleMVVM.Models
{
    public class ListBook
    {
        List<Book> books;
        private readonly string filePath = Path.Combine(Directory.GetCurrentDirectory(), "books.json");

        public ListBook() {
            books = new List<Book>();
            LoadFromFile();
        }

        public void AddBook(Book book)
        {
            books.Add(book);
            RefreshFile();
        }

        public void LoadFromFile()
        {
            using (FileStream fs = new FileStream(filePath, FileMode.Open))
            {
                if (fs.Length == 0)
                    return;
                DataContractJsonSerializer serializer = new DataContractJsonSerializer(typeof(List<Book>));
                books = (List<Book>)serializer.ReadObject(fs);
            }
        }

        public void RefreshFile()
        {

            using (FileStream fs = new FileStream("books.json", FileMode.Create))
            {
                DataContractJsonSerializer serializer = new DataContractJsonSerializer(typeof(List<Book>));
                serializer.WriteObject(fs, books);
            }
        }

        public List<Book> GetBooks()
        {
            return books;
        }

    }
}
