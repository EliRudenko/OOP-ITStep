using BLL.UIModels;

namespace BLL.Interfaces
{
    public interface IGenreService
    {
        Task Create(GenreGTO genre);
        Task Update(int id);
        Task Delete(int id);
        Task<GenreGTO?> Get(int id);
        Task<GenreGTO?> GetByName(string name);
        Task<IEnumerable<GenreGTO?>> GetAll();
    }
}
