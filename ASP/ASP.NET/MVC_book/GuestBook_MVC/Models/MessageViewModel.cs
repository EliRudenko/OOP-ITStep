using GuestBook_MVC.Models;

public class MessageViewModel
{
    public string? MessageText { get; set; }
    public List<Message> Messages { get; set; } = null!;
}
