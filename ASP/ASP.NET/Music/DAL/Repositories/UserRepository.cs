using Microsoft.EntityFrameworkCore;
using MusicPortal_Layered_ASP.DLL.Context;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;

namespace MusicPortal_Layered_ASP.DLL.Repositories
{
    public class UserRepository : IRepository<User>
    {
        private readonly MusicContext _context;

        public UserRepository(MusicContext context)
        {
            _context = context;
        }
        public async Task Add(User user)
        {
            await _context.Users.AddAsync(user);
        }

        public async Task Delete(int id)
        {
            var user = await _context.Users.FindAsync(id);
            if(user != null)
                _context.Users.Remove(user);
        }


        public async Task<User?> Get(int id)
        {
            return await _context.Users.FindAsync(id);
        }

        public async Task<User?> Get(string name)
        {
            return await _context.Users.FirstOrDefaultAsync(u => u.Username == name);
        }

        public async Task<IEnumerable<User>?> GetAll()
        {
            return await _context.Users.ToListAsync();
        }

        public void Update(User user)
        {
            _context.Entry(user).State = EntityState.Modified;
        }

    }
}
