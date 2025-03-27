using FileHandlerClass;
using System.Text.Json;
using UserClass;

namespace LoginMiddleware
{
    public class DefaultPage
    {
        private readonly RequestDelegate _next;

        public DefaultPage(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext context)
        {
            if (string.IsNullOrEmpty(context.Request.QueryString.ToString()))
            {
                UserList.Users = UserList.GetUsers();
                if (UserList.Users.Count == 0)
                    await context.Response.WriteAsync("No users in the file");
                string text = UserList.UsersToString(UserList.Users);
                await context.Response.WriteAsync(text);
            }
            else
                await _next(context);
        }


    }

    public static class DefaultPageExtensions
    {
        public static IApplicationBuilder UseDefaultPage(this IApplicationBuilder builder)
        {
            return builder.UseMiddleware<DefaultPage>();
        }
    }
}
