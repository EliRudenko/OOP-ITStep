using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using System.Threading.Tasks;

namespace CreatingMiddleware
{
    // You may need to install the Microsoft.AspNetCore.Http.Abstractions package into your project
    public class First
    {
        private readonly RequestDelegate _next;

        public First(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext httpContext)
        {
            string? digit = httpContext.Request.Query["digit"];

            if (!int.TryParse(digit, out int iDigit))
            {
                await httpContext.Response.WriteAsync("Incorrect format");
                return;
            }

            if (iDigit < 0)
            {
                await httpContext.Response.WriteAsync("Your digit is negative");
                return;
            }
            else if (iDigit == 0)
            {
                await httpContext.Response.WriteAsync("Your digit is zero");
                return;
            }

            await _next(httpContext); 
        }

    }

    public static class MiddlewareExtensions
    {
        public static IApplicationBuilder UseFirst(this IApplicationBuilder builder)
        {
            return builder.UseMiddleware<First>();
        }
    }
}
