using Microsoft.EntityFrameworkCore;
using System.ComponentModel.DataAnnotations;

namespace CRUD_Students_Groups_ASP.Models
{
    public class Group
    {
        public int Id { get; set; }
        [Required]
        [Length(4, 15, ErrorMessage = "Length has to be between 4 and 15 symbols")]
        public string Name { get; set; } = null!;
    }


}
