using Microsoft.EntityFrameworkCore;
using MusicPortal_Layered_ASP.DLL.Context;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;

namespace MusicPortal_Layered_ASP.DLL.Repositories
{
    public class GenreRepository : IRepository<Genre>
    {
        private readonly MusicContext _context;
        public GenreRepository(MusicContext context)
        {
            _context = context;
        }

        public async Task Add(Genre obj)
        {
            await _context.Genres.AddAsync(obj);
        }

        public async Task Delete(int id)
        {
            var obj = await _context.Genres.FindAsync(id);
            if (obj != null)
                _context.Genres.Remove(obj);
        }

        public async Task<Genre?> Get(int id)
        {
            return await _context.Genres.FindAsync(id);
        }

        public async Task<IEnumerable<Genre>?> GetAll()
        {
            return await _context.Genres.ToListAsync();
        }

        public void Update(Genre obj)
        {
            _context.Entry(obj).State = EntityState.Modified;
        }

        public Task<Genre?> Get(string name)
        {
            return _context.Genres.FirstOrDefaultAsync(g => g.Name == name);
        }
    }
}
