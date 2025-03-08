using CreatingMiddleware;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.MapGet("/", () => "Hello World!");

app.UseFirst();
app.UseSecond();
app.UseLast();
app.Run();
