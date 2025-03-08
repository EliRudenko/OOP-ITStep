using Microsoft.AspNetCore.Builder;
using Microsoft.AspNetCore.Http;
using System.Threading.Tasks;

namespace CreatingMiddleware
{
    public class Second
    {
        private readonly RequestDelegate _next;

        public Second(RequestDelegate next)
        {
            _next = next;
        }

        public async Task Invoke(HttpContext httpContext)
        {
            int digit;
            int.TryParse(httpContext.Request.Query["digit"].ToString(), out digit);
            if(digit<50000)
            {
                await httpContext.Response.WriteAsync("Your digit is smaller than 50000");
                return;
            }
            else
                await _next(httpContext);
        }
    }

    // Extension method used to add the middleware to the HTTP request pipeline.
    public static class SecondExtensions
    {
        public static IApplicationBuilder UseSecond(this IApplicationBuilder builder)
        {
            return builder.UseMiddleware<Second>();
        }
    }
}
