using System.Runtime.Serialization;

namespace MVPBooksForm
{
    [Serializable]
    [DataContract]
    public class Book:IBook
    {
        static int bookCounter = 1;

        [DataMember]
        public string BookName { get; set; }

        [DataMember]
        public string Author { get; set; }

        [DataMember]
        public string Genre { get; set; }

        [DataMember]
        public int Year { get; set; }

        [DataMember]
        public int Id { get; set; }

        public void GiveId()
        {
            Id = bookCounter++;
        }

        public Book()
        {
            BookName = Genre = Author = string.Empty;
            Year = Id = 0;
        }
    }
}
