namespace GuestBook_MVC.Models
{
    public class Message
    {
        public int Id { get; set; }
        public int UserId { get; set; }
        public User User { get; set; } = null!;
        public string MessageText { get; set; } = null!;
        public DateTime SendDate { get; set; }
    }
}
