using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using GuestBook_MVC.Models;
using Microsoft.EntityFrameworkCore;
using Sodium;
using GuestBook_MVC.Repositories;

namespace GuestBook_MVC.Controllers;

public class HomeController : Controller
{
    private readonly IRepository _repo;
    public HomeController(IRepository repo)
    {
        _repo = repo;
    }

    public async Task<IActionResult> Index()
    {
        var messages = await _repo.GetMessages();

        var viewModel = new MessageViewModel
        {
            Messages = messages
        };

        return View(viewModel);
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Index(MessageViewModel model)
    {
        var sessionStr = HttpContext.Session.GetString("username");
        User? user = null;

        if (!string.IsNullOrEmpty(sessionStr))
            user = await _repo.GetUser(sessionStr); 

        if (user != null && !string.IsNullOrEmpty(model.MessageText))
        {
            var _message = new Message
            {
                User = user,
                MessageText = model.MessageText,
                SendDate = DateTime.Now
            };

            await _repo.AddMessage(_message);
            await _repo.Save();
        }

        return RedirectToAction("Index");
    }

    public IActionResult LogOut()
    {
        HttpContext.Session.Clear();
        return RedirectToAction("Index");
    }



    public IActionResult Login()
    {
        if (HttpContext.Session.GetString("username") != null)
            return RedirectToAction("Index");
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Login([Bind("Id", "Name", "Password")] User user)
    {
        var existingUser = await _repo.GetUser(user.Name); 

        if (existingUser == null || !PasswordHash.ArgonHashStringVerify(existingUser.Password, user.Password))
        {
            ModelState.AddModelError("Password", "Invalid username or password");
            return View(user);
        }

        HttpContext.Session.SetString("username", user.Name);
        return RedirectToAction("Index", "Home");
    }


    public IActionResult Registration()
    {
        if (HttpContext.Session.GetString("username") != null)
            return RedirectToAction("Index");
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Registration(User user)
    {
        if(user.Password != user.ConfirmPassword)
        {
            ModelState.AddModelError("Password", "Passwords have to be similar");
            return View(user);
        }

        user.Password = PasswordHash.ArgonHashString(user.Password, PasswordHash.StrengthArgon.Interactive);
        
        await _repo.AddUser(user);

        try
        {
            await _repo.Save();
        }
        catch (DbUpdateException)
        {
            ModelState.AddModelError("Name", "This username is already taken");
            return View(user);
        }

        return RedirectToAction("Login", "Home");
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}
