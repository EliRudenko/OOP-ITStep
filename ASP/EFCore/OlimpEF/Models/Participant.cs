namespace Models
{
    public class Participant
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Surname { get; set; }
        public DateOnly Birthday { get; set; }
        public int CityId { get; set; }
        public City City { get; set; } = null!;
        public int SportId { get; set; }
        public Sport Sport { get; set; } = null!;
        public int OlympiadId { get; set; }
        public Olympiad Olympiad { get; set; } = null!;
    }

}
