using BLL.UIModels;

namespace BLL.Interfaces
{
    public interface ISongService
    {
        Task Create(SongGTO song);
        Task Update(SongGTO song);
        Task Delete(int id);
        Task<SongGTO?> Get(int id);
        Task<IEnumerable<SongGTO?>> GetAll();
    }
}
