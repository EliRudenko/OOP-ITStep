namespace Models
{
    public class Olympiad
    {
        public int Id { get; set; }
        public int Year { get; set; }
        public string Season { get; set; }
        public int CityId { get; set; }
        public City City { get; set; }
        public ICollection <Participant> Participants { get; set; }
    }
}
