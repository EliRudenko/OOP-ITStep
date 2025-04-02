using Microsoft.EntityFrameworkCore;
using MusicPortal_Layered_ASP.DLL.Context;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;

namespace MusicPortal_Layered_ASP.DLL.Repositories
{
    public class SongRepository : IRepository<Song>
    {
        private readonly MusicContext _context;
        public SongRepository(MusicContext context)
        {
            _context = context;
        }
        public async Task Add(Song obj)
        {
            await _context.Songs.AddAsync(obj);
        }
        public async Task Delete(int id)
        {
            var obj = await _context.Songs.FindAsync(id);
            if (obj != null)
                _context.Songs.Remove(obj);
        }
        public async Task<Song?> Get(int id)
        {
            return await _context.Songs.FindAsync(id);
        }

        public async Task<Song?> Get(string name)
        {
            return await _context.Songs.FirstOrDefaultAsync(s => s.Title == name);
        }

        public async Task<IEnumerable<Song>?> GetAll()
        {
            return await _context.Songs.Include(s=>s.Genre).ToListAsync();
        }
        public void Update(Song obj)
        {
            _context.Entry(obj).State = EntityState.Modified;
        }
    }
}
