using System;
using System.Runtime.Serialization;

namespace SampleMVVM.Models
{
    [Serializable]
    [DataContract]
    public class Book
    {
        [DataMember]
        public string Title { get; set; }

        [DataMember]
        public string Author { get; set; }

        [DataMember]
        public int Count { get; set; }

        public Book(string title, string author, int count)
        {
            Title = title;
            Author = author;
            Count = count;
        }

    }
}
