using System.Diagnostics;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using UniversityMVC.Models;

namespace UniversityMVC.Controllers;

public class HomeController : Controller
{
    private readonly ILogger<HomeController> _logger;
    private readonly UniversityContext _context;

    public HomeController(ILogger<HomeController> logger, UniversityContext context)
    {
        _logger = logger;
        _context = context;
    }

    public IActionResult Index()
    {
        return View();
    }

    public async Task<IActionResult> Students()
    {
        var students = await _context.Students.Include(s=>s.Group).ToListAsync();
        return View(students);
    }

    public async Task<IActionResult> Groups()
    {
        var groups = await _context.Groups.ToListAsync();
        return View(groups);
    }

    public async Task<IActionResult> Subjects()
    {
        var subjects = await _context.Subjects.ToListAsync();
        return View(subjects);
    }

    public async Task<IActionResult> Teachers()
    {
        var teachers = await _context.Teachers.ToListAsync();
        return View(teachers);
    }

    public async Task<IActionResult> Lectures()
    {
        var lectures = await _context.SubjectsGroups.Include(sg=>sg.Group).Include(sg=>sg.Subject).Include(sg=>sg.Teacher).ToListAsync();
        return View(lectures);
    }


    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}
