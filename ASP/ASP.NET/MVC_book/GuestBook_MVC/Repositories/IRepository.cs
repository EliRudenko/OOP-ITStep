using GuestBook_MVC.Models;

namespace GuestBook_MVC.Repositories
{
    public interface IRepository
    {
        Task <List<Message>?> GetMessages();
        Task<User?> GetUser(string name);
        Task AddUser(User user);
        Task AddMessage(Message message);
        Task Save();
    }
}
