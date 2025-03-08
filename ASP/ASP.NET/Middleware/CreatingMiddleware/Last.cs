using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using System.Threading.Tasks;

namespace CreatingMiddleware
{
    // You may need to install the Microsoft.AspNetCore.Http.Abstractions package into your project
    public class Last
    {
        private readonly RequestDelegate _next;

        public Last(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext httpContext)
        {
            int digit;
            int.TryParse(httpContext.Request.Query["digit"].ToString(),out digit);

            await httpContext.Response.WriteAsync($"Congratulations!! Your number {digit} is bigger than 50000");
        }
    }

    // Extension method used to add the middleware to the HTTP request pipeline.
    public static class LastExtensions
    {
        public static IApplicationBuilder UseLast(this IApplicationBuilder builder)
        {
            return builder.UseMiddleware<Last>();
        }
    }
}
