using System.ComponentModel.DataAnnotations;

namespace CRUD_Students_Groups_ASP.Models
{
    public class Student
    {
        public int Id { get; set; }
        [Required]
        [RegularExpression(@"^[A-Z][a-z ,.'-]*$", ErrorMessage = "Only letters, spaces, and characters (' -) are allowed.")]
        public string FirstName { get; set; } = null!;
        [Required]
        [RegularExpression(@"^[A-Z][a-z ,.'-]*$", ErrorMessage = "Only letters, spaces, and characters (' -) are allowed.")]
        public string LastName { get; set; } = null!;
        [Required]
        [Range(17,25,ErrorMessage ="Age of a student has to be between 17 and 25")]
        public int Age { get; set; }
        public int GroupId { get; set; }
        public Group? Group { get; set; }

    }
}
