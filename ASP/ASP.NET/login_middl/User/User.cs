using FileHandlerClass;
using System.Text.Json;

namespace UserClass
{
    public static class UserList
    {
        public static List<User> Users { get; set; }

        static UserList()
        {
            Users = new List<User>(); 
        }

        public static List<User> GetUsers()
        {
            string text = FileHandler.Read();
            if (string.IsNullOrWhiteSpace(text))
                return new List<User>();

            try
            {
                return JsonSerializer.Deserialize<List<User>>(text) ?? new List<User>();
            }
            catch (JsonException ex)
            {
                Console.WriteLine($"Ошибка при разборе JSON: {ex.Message}");
                return new List<User>();
            }
        }
        public static string UsersToString(List<User> users)
        {
            string res = string.Empty;
            foreach (var user in users)
            {
                res += $"Name = {user.Name}\n" +
                    $"Login = {user.Login}\n\n\n";
            }
            return res;
        }
    }


    public class User
    {
        public string Name { get; set; }
        public string Login {  get; set; }
        public string Password { get; set; }
        public User(string? name, string login, string password)
        {
            Name = name;
            Login = login;
            Password = password;
        }
    }
}
