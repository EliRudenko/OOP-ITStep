using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using CRUD_Students_Groups_ASP.Models;
using Microsoft.AspNetCore.Mvc.Rendering;
using System.Diagnostics;

namespace CRUD_Students_Groups_ASP.Controllers
{
    public class StudentsController : Controller
    {
        private readonly UniversityContext _context;

        public StudentsController(UniversityContext context)
        {
            _context = context;
        }

        public async Task<IActionResult> Index()
        {
            var students = await _context.Students.Include(s => s.Group).ToListAsync();
            return View(students);
        }
        public IActionResult Create()
        {
            ViewBag.GroupId = new SelectList(_context.Groups, "Id", "Name");
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create([Bind("Id","FirstName","LastName","Age","GroupId")]Student student)
        {
            if (ModelState.IsValid)
            {
                await _context.Students.AddAsync(student);
                await _context.SaveChangesAsync();

                return RedirectToAction("Index");
            }

            return View(student);
        }

        public async Task<IActionResult> Delete(int id)
        {
            var student = await _context.Students.Include(s=>s.Group).FirstOrDefaultAsync(s=>s.Id == id);
            if (student != null)
                return View(student);
            return RedirectToAction(nameof(Index));
        }
        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var student = await _context.Students.FindAsync(id);
            if (student == null)
            {
                return NotFound();
            }

            try
            {
                _context.Students.Remove(student);
                await _context.SaveChangesAsync();
                return RedirectToAction(nameof(Index)); 
            }
            catch (DbUpdateConcurrencyException)
            {
                return View("Error"); 
            }
        }



        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }

    }
}
