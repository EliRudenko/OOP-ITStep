namespace MusicPortal_Layered_ASP.DLL.Entities
{
    public class User
    {
        public int Id { get; set; }
        public string? Username { get; set; }
        public string? PasswordHash { get; set; }
        public bool IsAdmin { get; set; }
    }
}
