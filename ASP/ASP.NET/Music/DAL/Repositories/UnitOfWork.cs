using MusicPortal_Layered_ASP.DLL.Context;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;

namespace MusicPortal_Layered_ASP.DLL.Repositories
{
    public class UnitOfWork : IUnitOfWork
    {
        private MusicContext db;
        private UserRepository userRepository;
        private SongRepository songRepository;
        private GenreRepository genreRepository;

        public UnitOfWork(MusicContext context)
        {
            db = context;
        }
        public IRepository<Song> Songs
        {
            get
            {
                return songRepository ??= new SongRepository(db);
            }
        }

        public IRepository<User> Users
        {
            get
            {
                return userRepository ??= new UserRepository(db);
            }
        }
        public IRepository<Genre> Genres
        {
            get
            {
                return genreRepository ??= new GenreRepository(db);
            }
        }

        public async Task Save()
        {
            await db.SaveChangesAsync();
        }
    }
}
