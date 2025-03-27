using FileHandlerClass;
using System.Text.Json;
using UserClass;

namespace LoginMiddleware
{
    public class Registration
    {
        private readonly RequestDelegate _next;

        public Registration(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext httpContext)
        {
            string? name = httpContext.Request.Query["name"];
            if(string.IsNullOrEmpty(name))
                await _next(httpContext);
            else
            {
                string? login = httpContext.Request.Query["login"];
                string? password = httpContext.Request.Query["password"];
                if (string.IsNullOrEmpty(login) || string.IsNullOrEmpty(password))
                {
                    await httpContext.Response.WriteAsync("Incorrect");
                    return;
                }

                var user = new User(name, login,password);
                UserList.Users.Add(user);
                string usersString = JsonSerializer.Serialize(UserList.Users);
                FileHandler.Write(usersString);

                await httpContext.Response.WriteAsync($"{user.Name} has signed up");
                return;

            }
        }
    }

    public static class RegistrationExtensions
    {
        public static IApplicationBuilder UseRegistration(this IApplicationBuilder builder)
        {
            return builder.UseMiddleware<Registration>();
        }
    }
}
