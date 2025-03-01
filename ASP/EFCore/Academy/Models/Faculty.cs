using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Faculty
    {
        public int Id { get; set; }
        public decimal Financing { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Name { get; set; } 

    }
}
