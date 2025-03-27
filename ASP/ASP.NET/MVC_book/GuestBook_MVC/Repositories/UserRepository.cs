using GuestBook_MVC.Models;
using Microsoft.EntityFrameworkCore;

namespace GuestBook_MVC.Repositories
{
    public class UserRepository : IRepository
    {
        private readonly MessageContext _context;
        public UserRepository(MessageContext context)
        {
            _context = context;
        }

        public async Task AddMessage(Message message)
        {
            await _context.Messages.AddAsync(message);
        }

        public async Task AddUser(User user)
        {
            await _context.Users.AddAsync(user);
        }

        public async Task<List<Message>?> GetMessages()
        {
            return await _context.Messages.Include(m => m.User).ToListAsync();
        }

        public async Task<User?> GetUser(string name)
        {
            return await _context.Users.FirstOrDefaultAsync(u => u.Name == name);
        }

        public async Task Save()
        {
            await _context.SaveChangesAsync();
        }
    }
}
