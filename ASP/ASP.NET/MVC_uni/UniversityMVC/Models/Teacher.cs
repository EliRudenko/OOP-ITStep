using System.ComponentModel.DataAnnotations;

namespace UniversityMVC.Models
{
    public class Teacher
    {
        public int Id { get; set; }
        [RegularExpression("^[a-z ,.'-]+$", ErrorMessage = "Regex name error")]
        public string Name { get; set; }
        [RegularExpression("^[a-z ,.'-]+$", ErrorMessage = "Regex name error")]
        public string LastName { get; set; }

        public ICollection<SubjectsGroups> SubjectsGroups { get; set; } = null!;
    }
}
