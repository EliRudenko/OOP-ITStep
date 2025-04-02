
namespace MusicPortal_Layered_ASP.DLL.Interfaces
{
    public interface IRepository<T> where T : class
    {
        public Task<IEnumerable<T>?> GetAll();
        public Task<T?> Get(int id);
        public Task<T?> Get(string name);
        public Task Add(T obj);
        public void Update(T obj);
        public Task Delete(int id);
    }
}
