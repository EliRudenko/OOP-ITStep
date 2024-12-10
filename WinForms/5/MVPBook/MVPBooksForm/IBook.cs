namespace MVPBooksForm
{
    public interface IBook
    {
        public string BookName { get; set; }
        public string Author { get; set; }
        public string Genre { get; set; }
        public int Year { get; set; }
        public int Id { get; set; }
    }
}
