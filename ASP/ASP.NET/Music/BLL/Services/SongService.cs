using BLL.Interfaces;
using BLL.UIModels;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;

namespace BLL.Services
{
    public class SongService : ISongService
    {
        IUnitOfWork Database { get; set; }

        public SongService(IUnitOfWork uow)
        {
            Database = uow;
        }


        public async Task Delete(int id)
        {
            await Database.Songs.Delete(id);
            await Database.Save();
        }

        public async Task<SongGTO?> Get(int id)
        {
            var song = await Database.Songs.Get(id);
            if (song == null)
                return null;
            return new SongGTO
            {
                Id = song.Id,
                Title = song.Title,
                Artist = song.Artist,
                GenreId = song.GenreId,
                Genre = song.Genre?.Name
            };
        }

        public async Task Update(SongGTO updatedSong)
        {
            var song = await Database.Songs.Get(updatedSong.Id);

            var genreExists = await Database.Genres.Get(updatedSong.GenreId) != null;
            if (!genreExists)
                throw new InvalidOperationException("The selected genre does not exist.");

            song.Title = updatedSong.Title;
            song.Artist = updatedSong.Artist;
            song.GenreId = updatedSong.GenreId;

            Database.Songs.Update(song);
            await Database.Save();
        }


        public async Task<IEnumerable<SongGTO?>> GetAll()
        {
            var songs = await Database.Songs.GetAll();
            return songs.Select(song => new SongGTO
            {
                Id = song.Id,
                Title = song.Title,
                Artist = song.Artist,
                GenreId = song.GenreId,
                Genre = song.Genre?.Name
            }).ToList();
        }




        public async Task Create(SongGTO song)
        {
            Song newSong = new Song
            {
                Id = song.Id,
                Title = song.Title,
                Artist = song.Artist,
                GenreId = song.GenreId
            };
            await Database.Songs.Add(newSong);
            await Database.Save();
        }
    }
}
