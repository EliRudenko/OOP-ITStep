using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Department
    {
        public int Id { get; set; }
        public decimal Financing { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Name { get; set; } 
        public int FacultyId { get; set; }
        public Faculty Faculty { get; set; } = null!;
    }
}
