using BLL.Interfaces;
using BLL.UIModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
namespace MusicPortal_Layered_ASP.Controllers;

public class HomeController : Controller
{
    private readonly IUserService _userService;
    public HomeController(IUserService userService)
    {
        _userService = userService;
    }

    public IActionResult Index()
    {
        return View();
    }

    public IActionResult Login()
    {
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Login(UILogin user)
    {
        if (!ModelState.IsValid)
            return View(user);

        var userGTO = await _userService.Authenticate(user);
        if (userGTO == null)
        {
            ModelState.AddModelError("Password", "Incorrect username or password");
            return View(user);
        }
        HttpContext.Session.SetString("Username", user.Username);
        bool isAdmin = await _userService.CheckForAdmin(userGTO.Id);
        if (isAdmin)
            HttpContext.Session.SetString("IsAdmin", "true");
        else
            HttpContext.Session.SetString("IsAdmin", "false");
        return RedirectToAction("Index","Song");
    }

    public IActionResult Register()
    {
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Register(UIRegistration user)
    {
        if(!ModelState.IsValid)
            return View(user);
        try
        {
            await _userService.Create(user);
        }catch(DbUpdateException)
        {
            ModelState.AddModelError("Username", "Username already exists");
            return View(user);
        }
        return RedirectToAction(nameof(Index));
    }

    public IActionResult GuestLogin()
    {
        return RedirectToAction("Index", "Song");
    }
}

