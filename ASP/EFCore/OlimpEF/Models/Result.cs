namespace Models
{
    public class Result
    {
        public int Id { get; set; }
        public int Place { get; set; }
        public int ParticipantId { get; set; }
        public Participant Participant { get; set; }
        public Olympiad Olympiad { get; set; }

    }
}
