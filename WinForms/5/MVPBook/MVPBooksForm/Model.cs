using System;
using System.Collections.Generic;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Windows.Forms;

namespace MVPBooksForm
{
    public class Model : IModel
    {
        public List<Book> Books { get; set; }
        private static string filePath = "books.json";

        public Model()
        {
            Books = new List<Book>();
            LoadBooksFromJSON();
        }

        public void AddBookToList(Book book)
        {
            Books.Add(book);
        }

        public void LoadBooksFromJSON()
        {
            if (!File.Exists(filePath))
            {
                MessageBox.Show("File does not exist.");
                return;
            }

            using (FileStream fs = new FileStream(filePath, FileMode.Open, FileAccess.Read))
            {
                DataContractJsonSerializer json = new DataContractJsonSerializer(typeof(List<Book>));

                if (fs.Length > 0)
                    Books = (List<Book>)json.ReadObject(fs);
                else
                    Books = new List<Book>();
            }
        }

        public void SaveToFile()
        {
            try
            {
                using (FileStream fs = new FileStream(filePath, FileMode.Create, FileAccess.Write))
                {
                    DataContractJsonSerializer json = new DataContractJsonSerializer(typeof(List<Book>));
                    json.WriteObject(fs, Books);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error saving to file: {ex.Message}");
            }
        }

        public void DeleteFromFile(string title)
        {
            Books.RemoveAll(item => item.BookName == title);
        }
    }
}
