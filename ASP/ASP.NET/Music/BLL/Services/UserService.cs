using BLL.Interfaces;
using BLL.UIModels;
using Microsoft.EntityFrameworkCore;
using MusicPortal_Layered_ASP.DLL.Entities;
using MusicPortal_Layered_ASP.DLL.Interfaces;
using Sodium;

namespace BLL.Services
{
    public class UserService : IUserService
    {
        IUnitOfWork Database { get; set; }

        public UserService(IUnitOfWork unitOfWork)
        {
            Database = unitOfWork;
        }
        public async Task<bool> CheckForAdmin(int id)
        {
            var user = await Database.Users.Get(id);
            if (user == null)
                return false;
            return user.IsAdmin;
        }

        public bool CheckPassword(User user,string password)
        {
            return PasswordHash.ArgonHashStringVerify(user.PasswordHash, password);
        }

        public async Task Create(UIRegistration user)
        {
            User newUser = new User
            {
                Username = user.Username,
                PasswordHash = PasswordHash.ArgonHashString(user.Password, PasswordHash.StrengthArgon.Interactive),
                IsAdmin = false
            };
            try
            {
                await Database.Users.Add(newUser);
            }
            catch (DbUpdateException) { throw; };
            await Database.Save();
        }

        public async Task Delete(int id)
        {
            await Database.Users.Delete(id);
            await Database.Save();
        }

        public async Task<UserGTO?> Get(string name)
        {
            var user = await Database.Users.Get(name);

            return new UserGTO
            {
                Id = user.Id,
                Username = user.Username,
                IsAdmin = user.IsAdmin
            };
        }



        public async Task<IEnumerable<UserGTO?>> GetAll()
        {
            var users = await Database.Users.GetAll();
            return users.Select(user => new UserGTO
            {
                Id = user.Id,
                Username = user.Username,
                IsAdmin = user.IsAdmin
            }).ToList();
        }


        public async Task Update(int id)
        {
            User? user = await Database.Users.Get(id);
            Database.Users.Update(user);
            await Database.Save();
        }

        public async Task<User?> Get(UILogin user)
        {
            return await Database.Users.Get(user.Username);
        }

        public async Task<UserGTO?> Get(int id)
        {
            var user = await Database.Users.Get(id);
            return new UserGTO
            {
                Id = user.Id,
                Username = user.Username,
                IsAdmin = user.IsAdmin
            };
        }

        public async Task<UserGTO?> Authenticate(UILogin user)
        {
            var db_user = await Database.Users.Get(user.Username);
            if (db_user == null)
                return null;
            if (!CheckPassword(db_user, user.Password))
                return null;
            return new UserGTO
            {
                Id = db_user.Id,
                Username = db_user.Username,
                IsAdmin = db_user.IsAdmin
            };
        }
    }
}
