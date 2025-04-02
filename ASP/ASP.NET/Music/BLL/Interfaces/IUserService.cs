using BLL.UIModels;
using MusicPortal_Layered_ASP.DLL.Entities;

namespace BLL.Interfaces
{
    public interface IUserService
    {
        Task Create(UIRegistration user);
        Task Update(int id);
        Task Delete(int id);
        Task<UserGTO?> Get(int id);
        Task<UserGTO?> Get(string name);
        Task<User?> Get(UILogin user);
        Task<UserGTO?> Authenticate(UILogin user);
        Task<IEnumerable<UserGTO?>> GetAll();
        Task<bool> CheckForAdmin(int id);
        bool CheckPassword(User user, string password);
    }
}
