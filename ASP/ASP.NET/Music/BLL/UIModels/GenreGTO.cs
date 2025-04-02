using System.ComponentModel.DataAnnotations;

namespace BLL.UIModels
{
    public class GenreGTO
    {
        public int Id { get; set; }
        [Required]
        [Length(7, 50, ErrorMessage = "Length is from 7 to 50")]
        public string? Name { get; set; }
    }
}
