using BLL.Interfaces;
using BLL.UIModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
namespace MusicPortal_Layered_ASP.Controllers;


public class SongController : Controller
{
    private readonly IUserService _userService;
    private readonly ISongService _songService;
    private readonly IGenreService _genreService;
    public SongController(IUserService userService,ISongService songService,IGenreService genreService)
    {
        _userService = userService;
        _songService = songService;
        _genreService = genreService;
    }

    public async Task<IActionResult> Index()
    {
        var songs = await _songService.GetAll();
        return View(songs);
    }

    public async Task<IActionResult> Edit(int id)
    {
        var song = await _songService.Get(id);
        var genres = await _genreService.GetAll();

        ViewBag.Genres = new SelectList(genres, "Id", "Name",song.GenreId);

        return View(song);
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Edit(SongGTO song)
    {
        if (!ModelState.IsValid)
            return View(song);
        await _songService.Update(song);
        return RedirectToAction("Index");
    }

    public async Task<IActionResult> Delete(int id)
    {
        return View(await _songService.Get(id));
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Delete(SongGTO song)
    {
        await _songService.Delete(song.Id);
        return RedirectToAction("Index");
    }
    public async Task<IActionResult> Create()
    {
        var genres = await _genreService.GetAll();
        ViewBag.Genres = new SelectList(genres, "Id", "Name");
        return View();
    }

    [HttpPost]
    [ValidateAntiForgeryToken]
    public async Task<IActionResult> Create(SongGTO song)
    {
        if (!ModelState.IsValid)
            return View(song);
        await _songService.Create(song);
        return RedirectToAction("Index");
    }

}
