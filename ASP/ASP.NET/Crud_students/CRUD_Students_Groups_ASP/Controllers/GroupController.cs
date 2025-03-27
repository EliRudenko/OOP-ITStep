using System.Diagnostics;
using Microsoft.AspNetCore.Mvc;
using CRUD_Students_Groups_ASP.Models;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Storage;

namespace CRUD_Students_Groups_ASP.Controllers;

public class GroupController : Controller
{
    private readonly UniversityContext _context;
    public GroupController(UniversityContext universityContext )
    {
        _context = universityContext;
    }

    public async Task<IActionResult> Index()
    {
        var groups = await _context.Groups.ToListAsync();
        return View(groups);
    }

    public IActionResult Create()
    {
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Create(Group group)
    {
        if (ModelState.IsValid)
        {
            try
            {
                _context.Groups.Add(group);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index));
            }
            catch (DbUpdateException)
            {
                ModelState.AddModelError("Name", "The group name must be unique.");
                return View(group);
            }
        }

        return View(group);
    }


    public async Task<IActionResult> Delete(int id)
    {
        var group = await _context.Groups.FindAsync(id);

        if (group == null)
            return RedirectToAction("Index");
        return View(group);
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> DeleteConfirmed(int id)
    {
        var group = await _context.Groups.FindAsync(id);
        if (group != null)
        {
            try
            {
                _context.Groups.Remove(group);
                await _context.SaveChangesAsync();

            }
            catch(DbUpdateConcurrencyException) {
                return Error();
            }

        }

        return RedirectToAction("Index");
    }

    [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
    public IActionResult Error()
    {
        return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
    }
}
