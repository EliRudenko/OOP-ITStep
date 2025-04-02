using MusicPortal_Layered_ASP.DLL.Entities;

namespace MusicPortal_Layered_ASP.DLL.Interfaces
{
    public interface IUnitOfWork
    {
        IRepository<Song> Songs { get; }
        IRepository<User> Users { get; }
        IRepository<Genre> Genres { get; }
        Task Save();
    }
}
