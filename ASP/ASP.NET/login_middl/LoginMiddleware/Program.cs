using LoginMiddleware;

var builder = WebApplication.CreateBuilder(args);
var app = builder.Build();

app.UseDefaultPage();

app.UseRegistration();

app.UseLogin();

app.Run();

