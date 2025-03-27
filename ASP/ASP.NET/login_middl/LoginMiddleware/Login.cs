using UserClass;

namespace LoginMiddleware
{
    public class Login
    {
        private readonly RequestDelegate _next;

        public Login(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext httpContext)
        {
            string? login = httpContext.Request.Query["login"];
            string? password = httpContext.Request.Query["password"];

            if (login == null || password == null)
            {
                await httpContext.Response.WriteAsync("Incorrect query");
                return;
            }

            var users = UserList.GetUsers();

            foreach(var user in users)
            {
                if (user.Login == login && user.Password == password)
                {
                    await httpContext.Response.WriteAsync($"{user.Name} has signed in");
                    return;
                }
            }
            await httpContext.Response.WriteAsync("No such user");

        }
    }

    public static class LoginExtensions
    {
        public static IApplicationBuilder UseLogin(this IApplicationBuilder builder)
        {
            return builder.UseMiddleware<Login>();
        }
    }
}
