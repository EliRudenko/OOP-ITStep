using BLL.Interfaces;
using BLL.UIModels;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;

namespace BLL.Services
{
    public class GenreService : IGenreService
    {
        IUnitOfWork Database { get; set; }

        public GenreService(IUnitOfWork uow)
        {
            Database = uow;
        }

        public async Task Create(GenreGTO genre)
        {
            Genre newGenre = new Genre
            {
                Id = genre.Id,
                Name = genre.Name
            };
            await Database.Genres.Add(newGenre);
            await Database.Save();
        }

        public async Task Delete(int id)
        {
            await Database.Genres.Delete(id);
            await Database.Save();
        }

        public async Task<GenreGTO> Get(int id)
        {
            var genre = await Database.Genres.Get(id);
            return new GenreGTO
            {
                Id = genre.Id,
                Name = genre.Name
            };
        }

        public async Task Update(int id)
        {
            Genre? genre = await Database.Genres.Get(id);
            Database.Genres.Update(genre);
            await Database.Save();
        }

        public async Task<IEnumerable<GenreGTO>> GetAll()
        {
            var genres = await Database.Genres.GetAll();
            return genres.Select(genre => new GenreGTO
            {
                Id = genre.Id,
                Name = genre.Name
            }).ToList();
        }

        public async Task<GenreGTO?> GetByName(string name)
        {
            var genre = await Database.Genres.Get(name);
            return new GenreGTO 
            {
                Id = genre.Id,
                Name = genre.Name 
            };
        }
    }
}
