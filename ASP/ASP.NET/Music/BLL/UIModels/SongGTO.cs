
using System.ComponentModel.DataAnnotations;

namespace BLL.UIModels
{
    public class SongGTO
    {
        public int Id { get; set; }
        [Required]
        [Length(2,50,ErrorMessage ="Length is from 2 to 50")]
        public string? Title { get; set; }

        [Required]
        [Length(2, 50, ErrorMessage = "Length is from 2 to 50")]
        public string? Artist { get; set; }
        public int GenreId { get; set; }
        public string? Genre { get; set; }
    }
}
