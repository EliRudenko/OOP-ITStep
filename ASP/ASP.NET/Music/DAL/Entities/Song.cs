namespace MusicPortal_Layered_ASP.DLL.Entities
{
    public class Song
    {
        public int Id { get; set; }
        public string? Title { get; set; }
        public string? Artist { get; set; }
        public int GenreId { get; set; }
        public Genre? Genre { get; set; }
    }
}
